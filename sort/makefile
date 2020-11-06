# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

.PHONY: all test clean

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=..

CFLAGS=-std=c99
#CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -fsanitize=address
CFLAGS += -ftest-coverage
CFLAGS += -fprofile-arcs

TARGET_BASE1=test_identifier
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=$(UNITY_ROOT)/unity/unity.c src/sort.c  test/TestSort.c  test/test_runners/TestSort_Runner.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/unity
SYMBOLS=

all: clean default #test

default: $(SRC_FILES1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)

test:
	./test.sh

test/test_runners/TestSort_Runner.c: test/TestSort.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb test/TestSort.c  test/test_runners/TestSort_Runner.c

clean:
	$(CLEANUP) $(TARGET1) *.o cov* *.dSYM *.gcda *.gcno *.gcov

ci: CFLAGS += -Werror
ci: default
