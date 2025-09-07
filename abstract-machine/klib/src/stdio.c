#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

typedef void (*OutputFunc)(char c, void *data);

static void reverse_str(char *start, int len) {
  char *end = start + len - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

// 有符号整数转换函数
static int itoa_signed(int num, char *buf, int base) {
  char *p = buf;
  unsigned int unum;

  if (num == 0) {
    *p++ = '0';
    *p = '\0';
    return 1;
  }

  if (num < 0 && base == 10) {
    *p++ = '-';

    unum = (unsigned int)num;
    unum = ~unum + 1; // 等价于 -num 但避免溢出
  } else {
    unum = (unsigned int)num;
  }

  char *start_of_digits = p;
  while (unum > 0) {
    int digit = unum % base;
    *p++ = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    unum /= base;
  }
  *p = '\0';

  reverse_str(start_of_digits, p - start_of_digits);
  return p - buf;
}

// 无符号整数转换函数
static int utoa(unsigned int num, char *buf, int base) {
  char *p = buf;

  if (num == 0) {
    *p++ = '0';
    *p = '\0';
    return 1;
  }

  char *start_of_digits = p;
  while (num > 0) {
    int digit = num % base;
    *p++ = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    num /= base;
  }
  *p = '\0';

  reverse_str(start_of_digits, p - start_of_digits);
  return p - buf;
}

// 无符号长整型转换函数
static int ulltoa(unsigned long long num, char *buf, int base) {
  char *p = buf;

  if (num == 0) {
    *p++ = '0';
    *p = '\0';
    return 1;
  }

  char *start_of_digits = p;
  while (num > 0) {
    int digit = num % base;
    *p++ = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    num /= base;
  }
  *p = '\0';

  reverse_str(start_of_digits, p - start_of_digits);
  return p - buf;
}

// 修复后的格式化数字输出函数
static void output_formatted_number(const char *buf, int width, bool zero_pad,
                                    OutputFunc out, void *data) {
  int len = 0;
  const char *p = buf;
  while (*p) {
    len++;
    p++;
  }

  // 处理负号和零填充
  bool has_negative = (buf[0] == '-');
  const char *number_start = has_negative ? buf + 1 : buf;

  // 如果需要填充
  if (width > len) {
    if (zero_pad && has_negative) {
      // 零填充时先输出负号
      out('-', data);
      // 填充零
      for (int i = 0; i < width - len; i++) {
        out('0', data);
      }
      // 输出数字部分
      while (*number_start) {
        out(*number_start++, data);
      }
    } else {
      // 空格填充或正数的零填充
      char pad_char = zero_pad ? '0' : ' ';
      for (int i = 0; i < width - len; i++) {
        out(pad_char, data);
      }
      // 输出完整数字（包括负号）
      while (*buf) {
        out(*buf++, data);
      }
    }
  } else {
    // 不需要填充，直接输出
    while (*buf) {
      out(*buf++, data);
    }
  }
}

// 修复后的长整型转换函数
static int lltoa_signed(long long num, char *buf, int base) {
  char *p = buf;
  unsigned long long unum;

  if (num == 0) {
    *p++ = '0';
    *p = '\0';
    return 1;
  }

  if (num < 0 && base == 10) {
    *p++ = '-';
    // 修复：使用无符号运算避免溢出
    unum = (unsigned long long)num;
    unum = ~unum + 1; // 等价于 -num 但避免溢出
  } else {
    unum = (unsigned long long)num;
  }

  char *start_of_digits = p;
  while (unum > 0) {
    int digit = unum % base;
    *p++ = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    unum /= base;
  }
  *p = '\0';

  reverse_str(start_of_digits, p - start_of_digits);
  return p - buf;
}

// 带长度限制的输出函数数据结构
struct snprintf_data {
  char *buf;
  size_t remaining;
  size_t total_written;
};

// snprintf 输出函数
static void snprintf_out(char c, void *data) {
  struct snprintf_data *ctx = (struct snprintf_data *)data;
  ctx->total_written++;
  if (ctx->remaining > 1) { // 保留空间给 '\0'
    *(ctx->buf)++ = c;
    ctx->remaining--;
  }
}

static void format_core(const char *fmt, va_list args, OutputFunc out,
                        void *data) {
  for (const char *p = fmt; *p != '\0'; p++) {
    if (*p != '%') {
      out(*p, data);
      continue;
    }

    p++;
    if (*p == '\0')
      break; // 防止格式字符串以 % 结尾

    // 解析格式说明符
    bool zero_pad = false;
    int width = 0;
    int long_count = 0; // 计算 'l' 的数量

    // 检查零填充标志
    if (*p == '0') {
      zero_pad = true;
      p++;
    }

    // 解析宽度
    while (*p >= '0' && *p <= '9') {
      width = width * 10 + (*p - '0');
      p++;
    }

    // 检查长度修饰符 - 支持 l 和 ll
    while (*p == 'l' && long_count < 2) {
      long_count++;
      p++;
    }

    switch (*p) {
    case 's': {
      const char *s = va_arg(args, const char *);
      if (s == NULL)
        s = "(null)";
      while (*s) {
        out(*s++, data);
      }
      break;
    }
    case 'd': {
      if (long_count >= 2) { // ll 或 更多 l
        long long num = va_arg(args, long long);
        char buf[64];
        lltoa_signed(num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else if (long_count == 1) { // l
        long num = va_arg(args, long);
        char buf[64];
        lltoa_signed((long long)num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else { // 无修饰符
        int num = va_arg(args, int);
        char buf[32];
        itoa_signed(num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      }
      break;
    }
    case 'x': {
      if (long_count >= 2) { 
        unsigned long long num = va_arg(args, unsigned long long);
        char buf[64];
        ulltoa(num, buf, 16);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else if (long_count == 1) { 
        unsigned long num = va_arg(args, unsigned long);
        char buf[64];
        ulltoa((unsigned long long)num, buf, 16);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else { 
        unsigned int num = va_arg(args, unsigned int);
        char buf[32];
        utoa(num, buf, 16);
        output_formatted_number(buf, width, zero_pad, out, data);
      }
      break;
    }
    case 'p': {

      void *ptr = va_arg(args, void *);
      char buf[32];

      unsigned long long addr = (unsigned long long)(unsigned long)ptr;
      ulltoa(addr, buf, 16);
      out('0', data);
      out('x', data);
      output_formatted_number(buf, 0, false, out, data);
      break;
    }
    case 'u': {
      if (long_count >= 2) { 
        unsigned long long num = va_arg(args, unsigned long long);
        char buf[64];
        ulltoa(num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else if (long_count == 1) { // l
        unsigned long num = va_arg(args, unsigned long);
        char buf[64];
        ulltoa((unsigned long long)num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      } else { // 无修饰符
        unsigned int num = va_arg(args, unsigned int);
        char buf[32];
        utoa(num, buf, 10);
        output_formatted_number(buf, width, zero_pad, out, data);
      }
      break;
    }
    case 'c': {
      int c = va_arg(args, int);
      out((char)c, data);
      break;
    }
    case '%':
      out('%', data);
      break;
    default:
      // 处理未知格式说明符
      out('%', data);
      for (int i = 0; i < long_count; i++) {
        out('l', data);
      }
      out(*p, data);
      break;
    }
  }
}

void sprintf_out(char c, void *data) {
  char **buf = (char **)data;
  *(*buf)++ = c;
}

void printf_out(char c, void *data) { putch(c); }

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  format_core(fmt, args, printf_out, NULL);
  va_end(args);
  return 0;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *str_start = out;
  format_core(fmt, ap, sprintf_out, &out);
  *out = '\0';
  return out - str_start;
}

int sprintf(char *str, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  char *str_start = str;
  format_core(fmt, args, sprintf_out, &str);
  *str = '\0';
  va_end(args);
  return str - str_start;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  if (n == 0)
    return 0;

  va_list args;
  va_start(args, fmt);

  struct snprintf_data ctx = {out, n, 0};
  format_core(fmt, args, snprintf_out, &ctx);


  if (ctx.remaining > 0) {
    *ctx.buf = '\0';
  } else if (n > 0) {
    out[n - 1] = '\0';
  }

  va_end(args);
  return ctx.total_written;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  if (n == 0)
    return 0;

  struct snprintf_data ctx = {out, n, 0};
  format_core(fmt, ap, snprintf_out, &ctx);

  if (ctx.remaining > 0) {
    *ctx.buf = '\0';
  } else if (n > 0) {
    out[n - 1] = '\0';
  }

  return ctx.total_written;
}

#endif