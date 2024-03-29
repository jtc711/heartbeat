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
debug: $(APPLICATION_NAME).elf
	@$(SIZE) -A $(APPLICATION_NAME).elf

release: CFLAGS+=$(RELEASE_FLAGS)
release: $(APPLICATION_NAME).elf
	@$(STRIP) --strip-debug $(APPLICATION_NAME).elf
	@$(SIZE) -A $(APPLICATION_NAME).elf

all: debug

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
