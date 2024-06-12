CFLAGS ?= -O2 -g
CFLAGS += -std=gnu99
CFLAGS += -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self \
	-Wswitch-default -Wpointer-arith -Wtype-limits -Wempty-body \
	-Wstrict-prototypes -Wold-style-declaration -Wold-style-definition \
	-Wmissing-parameter-type -Wmissing-field-initializers -Wnested-externs \
	-Wstack-usage=4096 -Wfloat-equal -Wabsolute-value -g
CFLAGS += -fsanitize=undefined -fsanitize-undefined-trap-on-error
CC += gcc -m32 -no-pie -fno-pie
LDLIBS = -lm

OBJS = BuildDir/main.o BuildDir/function.o
TARGET = integral


all: make_dir $(OBJS)
	gcc -m32 -o $(TARGET) $(OBJS) $(LDLIBS)

OBJS_TEST = BuildDir/test.o BuildDir/test_functions.o
test: make_dir $(OBJS_TEST)
	gcc -m32 -o $(TARGET) $(OBJS_TEST) $(LDLIBS)

make_dir:
	mkdir -p BuildDir

# Object files from .asm
BuildDir/%.o: src/%.asm
	nasm -g -f elf32 -o $@ $<
#Link all object files with gcc
BuildDir/%.o: src/%.c
	gcc -m32 -c $(CFLAGS) -o $@ $<

BuildDir:
	mkdir -p BuildDir

.PHONY: clean
clean:
	rm -rf BuildDir
	rm -f $(TARGET)