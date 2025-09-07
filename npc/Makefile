# 基本源文件设置
VSRC = $(wildcard /home/zxj17/ysyx-workbench/npc/vsrc/*.v)
CSRC = $(shell find csrc -type f -name '*.c') $(shell find csrc -type f -name '*.cpp' -not -path 'csrc/llvm/*')
SRCS = $(VSRC) $(CSRC)
NXDC = constr/mux.nxdc
TOPNAME = ysyx_25040109_top
NAME = riscv32e-npc-interpreter
BUILD_DIR = $(NPC_HOME)/build
INC_PATH = $(shell find /home/zxj17/ysyx-workbench/npc/include -type d)  /home/zxj17/ysyx-workbench/npc/csrc/riscv32   /usr/include/llvm-14  /usr/include/llvm-c-14/ /home/zxj17/ysyx-workbench/npc/csrc/riscv32/local-include  /home/zxj17/ysyx-workbench/npc/csrc/llvm/ 

INCFLAGS = $(addprefix -I, $(INC_PATH))
IMG ?=
ARGS ?= 



#CFLAGS += -DSYNTHESIS

CONFIG_DIFFTEST = y

ifdef CONFIG_DIFFTEST

DIFF_REF_SO = $(NPC_HOME)/tools/build/riscv32-nemu-interpreter-so

ARGS_DIFF = --diff=$(DIFF_REF_SO)

endif



# 基本链接库
LDFLAGS = -lreadline -lhistory -lncurses -lSDL2

include $(NVBOARD_HOME)/scripts/nvboard.mk


ARGS_DIFF ?=

# ===== 动态库方案 =====
# 检查是否需要编译LLVM包装器动态库
LLVM_DIR = csrc/llvm
LLVM_WRAPPER_LIB = $(abspath $(LLVM_DIR)/libllvm_wrapper.so)
LLVM_WRAPPER_SRC = $(abspath $(LLVM_DIR)/llvm_wrapper.cpp)
DISASM_OBJ = $(abspath $(LLVM_DIR)/disasm.o)
DISASM_SRC = $(abspath $(LLVM_DIR)/disasm.cpp)

# 检查llvm-config是否可用
LLVM_CONFIG := $(shell which llvm-config-14 2>/dev/null || which llvm-config 2>/dev/null)

ifneq ($(LLVM_CONFIG),)
    # LLVM可用，启用动态库支持
    $(info Found LLVM config: $(LLVM_CONFIG))
    LLVM_AVAILABLE = 1
    
    # LLVM编译参数（仅用于编译包装器）
    LLVM_CXXFLAGS := $(shell $(LLVM_CONFIG) --cxxflags)
    LLVM_LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags)
    LLVM_LIBS := $(shell $(LLVM_CONFIG) --libs core mc mcdisassembler support)
    
    # 主程序只需要链接dl库（用于动态加载）
    LDFLAGS += -ldl
    
    # 将反汇编对象文件加入到源文件中
    CSRC += $(DISASM_OBJ)
else
    $(info LLVM not found, disassembly will use objdump fallback)
    LLVM_AVAILABLE = 0
    LDFLAGS += -ldl
    CSRC += $(DISASM_OBJ)
endif      

# 编译LLVM包装器动态库（如果LLVM可用）
$(LLVM_WRAPPER_LIB): $(LLVM_WRAPPER_SRC)
ifeq ($(LLVM_AVAILABLE),1)
	@echo "Building LLVM wrapper library..."
	g++ -shared -fPIC $(LLVM_CXXFLAGS) -o $@ $< $(LLVM_LDFLAGS) $(LLVM_LIBS)
	@echo "LLVM wrapper library built successfully"
else
	@echo "LLVM not available, creating dummy library..."
	@touch $@
endif

# 编译反汇编对象文件
$(DISASM_OBJ): $(DISASM_SRC)
	@echo "Building disassembler object..."
	@mkdir -p $(dir $@)
	g++ -O2 -Wall -fPIC -c -o $@ $< -ldl

# 强制编译规则：确保文件存在
.PHONY: ensure-llvm-deps
ensure-llvm-deps:
	@if [ ! -f $(DISASM_OBJ) ]; then \
		echo "Building missing disasm.o..."; \
		mkdir -p $(LLVM_DIR); \
		g++ -O2 -Wall -fPIC -c -o $(DISASM_OBJ) $(DISASM_SRC) -ldl; \
	fi
ifeq ($(LLVM_AVAILABLE),1)
	@if [ ! -f $(LLVM_WRAPPER_LIB) ]; then \
		echo "Building missing LLVM wrapper library..."; \
		g++ -shared -fPIC $(LLVM_CXXFLAGS) -o $(LLVM_WRAPPER_LIB) $(LLVM_WRAPPER_SRC) $(LLVM_LDFLAGS) $(LLVM_LIBS); \
	fi
endif

# 确保在编译主程序前先编译依赖库
COMPILE_DEPS = $(DISASM_OBJ)
ifeq ($(LLVM_AVAILABLE),1)
    COMPILE_DEPS += $(LLVM_WRAPPER_LIB)
endif

all:
	@echo "Write this Makefile by your self."

# 添加库路径到运行时环境
export LD_LIBRARY_PATH := $(shell pwd)/$(LLVM_DIR):$(LD_LIBRARY_PATH)

sim: $(COMPILE_DEPS) $(VSRC) $(CSRC_NVBOARD) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Building simulation with dynamic LLVM support..."
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $(NXDC) auto_bind.cpp
	verilator --cc --exe --build --noassert $(VSRC) $(CSRC) $(NVBOARD_ARCHIVE) auto_bind.cpp \
		--trace-fst --top-module top \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS))

waveform: ensure-llvm-deps $(COMPILE_DEPS)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Building waveform with dynamic LLVM support..."
	verilator -Wall --cc --exe --x-assign unique --x-initial unique --build $(SRCS) \
		--trace-fst --top-module $(TOPNAME) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		$(addprefix -CFLAGS , $(CXXFLAGS) $(INCFLAGS))
		mv obj_dir/V$(TOPNAME) $(BUILD_DIR)/$(NAME)

run: waveform
	@echo "Setting library path and running..."
	@echo "LD_LIBRARY_PATH=$(shell pwd)/$(LLVM_DIR):$LD_LIBRARY_PATH"
	@echo "./build/$(NAME) $(ARGS) $(IMG) $(ARGS_DIFF)"
	LD_LIBRARY_PATH=$(shell pwd)/$(LLVM_DIR):$LD_LIBRARY_PATH ./build/$(NAME) $(ARGS)  $(ARGS_DIFF) $(IMG) 

look:
	gtkwave sim.fst

# 安装LLVM库到系统路径
install-llvm-lib: $(LLVM_WRAPPER_LIB)
ifeq ($(LLVM_AVAILABLE),1)
	@echo "Installing LLVM wrapper library to system..."
	sudo cp $(LLVM_WRAPPER_LIB) /usr/local/lib/
	sudo ldconfig
	@echo "Library installed. You can now run without setting LD_LIBRARY_PATH"
else
	@echo "LLVM not available, nothing to install"
endif


info:
	@echo "=== Build Configuration ==="
	@echo "LLVM Available: $(LLVM_AVAILABLE)"
ifneq ($(LLVM_CONFIG),)
	@echo "LLVM Config: $(LLVM_CONFIG)"
	@echo "LLVM Version: $(shell $(LLVM_CONFIG) --version)"
endif
	@echo "Source files: $(words $(CSRC))  $(CSRC) C/C++ files, $(words $(VSRC)) Verilog files"
	@echo "Dependencies: $(COMPILE_DEPS)"
	@echo "LD_LIBRARY_PATH will include: $(shell pwd)/$(LLVM_DIR)"
	@echo "INC_PATH: $(INC_PATH)"

check:waveform
	@echo "Verilog : $(VSRC)"
	@echo "\n"
	@echo "C/CPP   : $(CSRC)"
	@echo "\n"
	@echo "INC_PATH: $(INC_PATH)"	
	@echo "111"
	@echo "$(ARGS_DIFF)"


clean:
	rm -rf obj_dir waveform.fst waveform.fst.hier auto_bind.cpp sim.fst
	rm -f $(LLVM_WRAPPER_LIB) $(DISASM_OBJ)


.PHONY: all sim waveform run look clean install-llvm-lib info clean-llvm rebuild-llvm

include ../Makefile