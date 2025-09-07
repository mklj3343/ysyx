ifdef CONFIG_DIFFTEST

DIFF_REF_SO = $(NPC_HOME)/tools/build/riscv32-nemu-interpreter-so

ARGS_DIFF = --diff=$(DIFF_REF_SO)

endif
