#***************************************************************************************
# Copyright (c) 2014-2024 Zihao Yu, Nanjing University
#
# NEMU is licensed under Mulan PSL v2.
# You can use this software according to the terms and conditions of the Mulan PSL v2.
# You may obtain a copy of Mulan PSL v2 at:
#          http://license.coscl.org.cn/MulanPSL2
#
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
# EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
# MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
#
# See the Mulan PSL v2 for more details.
#**************************************************************************************/

ifdef CONFIG_DIFFTEST

# 变量：定义差分测试引用路径，引用 NEMU_HOME 环境变量和 CONFIG_DIFFTEST_REF_PATH 配置
# $(call remove_quote,...) 是 Makefile 函数，用于去除 CONFIG_DIFFTEST_REF_PATH 中的引号
DIFF_REF_PATH = $(NEMU_HOME)/$(call remove_quote,$(CONFIG_DIFFTEST_REF_PATH))

# 变量：定义差分测试的共享对象文件路径
# 基于 DIFF_REF_PATH，构建出目标文件的路径，格式为 build/<GUEST_ISA>-<CONFIG_DIFFTEST_REF_NAME>-so
# GUEST_ISA 是目标指令集体系结构，CONFIG_DIFFTEST_REF_NAME 是差分测试引用的名称
DIFF_REF_SO = $(DIFF_REF_PATH)/build/$(GUEST_ISA)-$(call remove_quote,$(CONFIG_DIFFTEST_REF_NAME))-so

# 变量：定义 make 命令的标志参数
# GUEST_ISA 指定目标指令集体系结构
# SHARE=1 表示构建共享对象
# ENGINE=interpreter 指定使用解释器引擎

MKFLAGS = GUEST_ISA=$(GUEST_ISA) SHARE=1 ENGINE=interpreter

# 变量：定义差分测试的参数
# --diff=$(DIFF_REF_SO) 指定差分测试时使用的共享对象文件路径
ARGS_DIFF = --diff=$(DIFF_REF_SO)

# 条件编译：检查是否定义了 CONFIG_DIFFTEST_REF_NEMU
# 如果未定义 CONFIG_DIFFTEST_REF_NEMU，则执行以下规则
ifndef CONFIG_DIFFTEST_REF_NEMU
# 目标：生成差分测试的共享对象文件 $(DIFF_REF_SO)
# 依赖：无（规则会触发子 make 命令）
$(DIFF_REF_SO):
	$(MAKE) -s -C $(DIFF_REF_PATH) $(MKFLAGS) 
endif


# 声明 $(DIFF_REF_SO) 为伪目标
# 伪目标不会生成实际文件，防止 Makefile 将其视为文件目标
.PHONY: $(DIFF_REF_SO)

endif