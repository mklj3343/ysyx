VSRC = vsrc/top.v vsrc/light.v
CSRC_NVBOARD = csrc/light_nvboard.cpp
CSRC_WAVE=csrc/light_wave.cpp
TOPNAME = top
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
INC_PATH ?=

include $(NVBOARD_HOME)/scripts/nvboard.mk

all:
	@echo "Write this Makefile by your self."

sim:$(VSRCS) $(CSRC_NVBOARD) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py constr/light.nxdc auto_bind.cpp
	verilator -Wall --cc --exe --build $(VSRC) $(CSRC_NVBOARD) $(NVBOARD_ARCHIVE) auto_bind.cpp --trace-fst --top-module top $(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS))


waveform:$(VSRCS) $(CSRC_WAVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --exe --x-assign unique --x-initial unique --build $(VSRC) $(CSRC_WAVE) --trace-fst --top-module top 

run:
	./obj_dir/V$(TOPNAME)  +verilator+rand+reset+2

look:
	gtkwave waveform.fst	


clean:
	rm -rf obj_dir waveform.fst  auto_bind.cpp

include ../Makefile
