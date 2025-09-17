CC      := gcc
CFLAGS  := -Wall -Wextra -Iinclude

SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := build

TARGETS := nes-disasm nes-asm nes-emul

CORE_SRC := $(wildcard $(SRC_DIR)/core/*.c)
DIS_SRC  := $(CORE_SRC) $(wildcard $(SRC_DIR)/disasm/*.c)
ASM_SRC  := $(CORE_SRC) $(wildcard $(SRC_DIR)/asm/*.c)
EMU_SRC  := $(CORE_SRC) $(wildcard $(SRC_DIR)/emul/*.c)

all: $(addprefix $(BIN_DIR)/, $(TARGETS))

$(BIN_DIR)/nes-disasm: $(DIS_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DNES_DISASSEMBLER $^ -o $@

$(BIN_DIR)/nes-asm: $(ASM_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DNES_ASSEMBLER $^ -o $@

$(BIN_DIR)/nes-emul: $(EMU_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DNES_EMULATOR $^ -o $@

# Clean up
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
