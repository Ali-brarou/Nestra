CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Iinclude 

SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := build

DIS 	:= $(BIN_DIR)/nesdisasm
DIS_SRC	:= $(wildcard $(SRC_DIR)/disasm/*.c)

all: $(DIS)

$(DIS): $(DIS_SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(BIN_DIR)
.PHONY: all clean
