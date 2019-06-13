include Makefile.include

C_OBJS:=$(C_SOURCES:.c=.o)

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: _all

release: CFLAGS+=$(RELEASE_FLAGS)
release: _all

all: debug

_all: $(C_OBJS)

$(C_OBJS): %.o:%.c
	@echo "[lib/$(LIBRARY_NAME)] compiling $<"
	@$(CC) $(CFLAGS) $(C_INCLUDES) -c $< -o $@

clean:
	-rm -f *.o *.bin *.elf *.out *.d *.map *.i *.s *.a *.hex
