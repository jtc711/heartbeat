include Makefile.include

C_OBJS:=$(C_SOURCES:.c=.o)


CLEANALLOS:=$(addsuffix /build/*.o, $(addprefix $(PROJECT_ROOT)/lib/, $(LIBRARIES)))
CLEANALLAS:=$(addsuffix .a, $(basename $(CLEANALLOS)))

LDFLAGS=\
-T$(LDSCRIPT)\
-static\
-Xlinker -o$(APPLICATION_NAME).elf\
-Xlinker -M\
-Xlinker -Map=$(APPLICATION_NAME).map\
-Wa,-mimplicit-it=thumb\
-Wl,-gc-sections

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: _all

release: CFLAGS+=$(DEBUG_FLAGS)
release: _all

all: debug

_all: $(APPLICATION_NAME).elf
	@$(SIZE) -B $(APPLICATION_NAME).elf

$(APPLICATION_NAME).elf: $(C_OBJS) $(LIBRARIES)
	$(eval LIBOBJS := $(wildcard $(addprefix $(PROJECT_ROOT)/lib/, $(LIBRARIES))/build/*.o))
	@$(CC) $(CFLAGS) $(LIBOBJS) $(C_OBJS) $(LDFLAGS)

$(C_OBJS): %.o:%.c
	@echo "[$(APPLICATION_NAME)] compiling $<"
	@$(CC) $(CFLAGS) $(C_INCLUDES) -c $< -o $@

$(LIBRARIES):
	@$(MAKE) -s -C$(PROJECT_ROOT)/lib/$@/build

clean:
	@rm -f *.o *.bin *.elf *.out *.d *.map *.i *.s *.a *.hex

cleanall: clean
	@rm -f $(CLEANALLOS) $(CLEANALLAS)
