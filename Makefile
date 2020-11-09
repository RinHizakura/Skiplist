GIT_HOOKS := .git/hooks/applied
FLAGS=-O0 -Wall -Wextra 
BUILD_DIR = build

SRCS=$(wildcard *.c)
OUT=$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(GIT_HOOKS) main
clean: 
	rm -rf build main

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	gcc $(FLAGS) -g -c $< -o $@

main: $(OUT)
	gcc -o main $(OUT)
