# =========================================================
# SGDK MAKEFILE - SIMPLE PROJECT
# =========================================================

# Caminho do SGDK (ajuste se necessário)
GDK := $(SGDK)

# Nome do projeto
NAME := rom

# Pastas
SRC_DIR := src
RES_DIR := res
OUT_DIR := out

# Compilador SGDK
CC := $(GDK)/bin/gcc
RESCOMP := java -jar $(GDK)/bin/rescomp.jar

# Flags
CFLAGS := -m68000 -Wall -O2

# Arquivos
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

# =========================================================
# DEFAULT TARGET
# =========================================================

all: $(NAME).bin

# =========================================================
# BUILD ROM
# =========================================================

$(NAME).bin: resources $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# =========================================================
# RESOURCES (SPRITES / MUSIC)
# =========================================================

resources:
	$(RESCOMP) $(RES_DIR)/resources.res

# =========================================================
# CLEAN
# =========================================================

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f *.bin
	rm -f $(RES_DIR)/*.h
	rm -f $(RES_DIR)/*.o