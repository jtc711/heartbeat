include Makefile.include

BINDIR:=$(LIBRARY_ROOT)/bin

C_OBJS:=$(C_SOURCES:.c=.o)

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: _all

release: CFLAGS+=$(DEBUG_FLAGS)
release: _all

all: debug

_all: $(C_OBJS)

$(C_OBJS): %.o:%.c
	@echo "compiling $<"
	@$(CC) $(CFLAGS) $(C_INCLUDES) -c $< -o $@

clean:
	-rm -f *.o *.bin *.elf *.out *.d *.map *.i *.s *.hex
