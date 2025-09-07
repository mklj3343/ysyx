#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)


size_t strlen(const char *s) {
  size_t num = 0;
  while (*s++) {
    num++;
  }
  return num;
}


char *strcpy(char *dst, const char *src) {
  char *d = dst;
  while ((*d++ = *src++)) {
    ;
  }
  return dst;
}


char *strncpy(char *dst, const char *src, size_t n) {
  char *d = dst;
  size_t i;


  for (i = 0; i < n && src[i] != '\0'; i++) {
    d[i] = src[i];
  }


  for (; i < n; i++) {
    d[i] = '\0';
  }

  return dst;
}


char *strcat(char *dst, const char *src) {
  char *d = dst;
  while (*d) {
    d++;
  }
  while ((*d++ = *src++))
    ;
  return dst;
}


int strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}


int strncmp(const char *s1, const char *s2, size_t n) {
  while (n > 0 && *s1 && *s2 && *s1 == *s2) {
    n--;
    s1++;
    s2++;
  }
  if (n == 0) {
    return 0;
  }
  return *(unsigned char *)s1 - *(unsigned char *)s2;
}


void *memset(void *s, int c, size_t n) {
  unsigned char *d = s;
  while (n--) {
    *d++ = (unsigned char)c;
  }
  return s;
}


void *memmove(void *dst, const void *src, size_t n) {
  if (dst == src || n == 0)
    return dst;

  char *d = (char *)dst;
  const char *s = (const char *)src;


  if (d > s && d < s + n) {
    // 反向复制
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    }
  } else {

    while (n--) {
      *d++ = *s++;
    }
  }
  return dst;
}


void *memcpy(void *out, const void *in, size_t n) {

  char *d = out;
  const char *p = in;
  while (n--) {
    *d++ = *p++;
  }
  return out;
}


int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *d = s1;
  const unsigned char *p = s2;
  while (n--) {
    if (*d != *p) {
      return *d - *p;
    }
    d++;
    p++;
  }
  return 0;
}

#endif