# This makefile was generated by autochaos 0.2.1. Please do not
# tamper with it unless you are very certain about what you are doing.

ALL_ARGUMENTS = --install-prefix /var/lib/tftpboot/chaos 

PREFIX = /var/lib/tftpboot/chaos
PACKAGE = storm

# Compiler flags.

CFLAGS = -Wall -W -Wshadow -Wpointer-arith -Waggregate-return \
-Wstrict-prototypes -Wredundant-decls -Winline -Wmissing-prototypes \
-Werror -Wcast-align -Wbad-function-cast -Wsign-compare \
-Wmissing-declarations -Wmissing-noreturn -pipe \
-Wnested-externs -O3 -fno-builtin -funsigned-char -g -m32 -fomit-frame-pointer -ffreestanding $(EXTRA_CFLAGS) $(DEFINES)

INCLUDES = \
-I../include \
-I.. \
-I. -I$(PREFIX)/data/programming/c/headers

SUB_DIRECTORIES = \
generic \
ia32 \
include
ALL_OBJECTS = \
generic/arguments.o \
generic/avl.o \
generic/avl_debug.o \
generic/avl_rotate.o \
generic/avl_update.o \
generic/avl_delete.o \
generic/debug.o \
generic/idle.o \
generic/init.o \
generic/kernelfs.o \
generic/log.o \
generic/mailbox.o \
generic/memory.o \
generic/service.o \
generic/slab.o \
generic/system_call.o \
generic/tag.o \
generic/time.o \
ia32/cluster.o \
ia32/cpuid.o \
ia32/debug.o \
ia32/dispatch.o \
ia32/dma.o \
ia32/elf.o \
ia32/gdt.o \
ia32/idt.o \
ia32/init.o \
ia32/irq.o \
ia32/irq_handlers.o \
ia32/limits.o \
ia32/main.o \
ia32/memory.o \
ia32/memory_global.o \
ia32/memory_physical.o \
ia32/memory_virtual.o \
ia32/multiboot.o \
ia32/mutex.o \
ia32/port.o \
ia32/process.o \
ia32/schedule.o \
ia32/string.o \
ia32/system_calls-auto.o \
ia32/system_calls.o \
ia32/thread.o \
ia32/time.o \
ia32/timer.o \
ia32/trap.o \
ia32/wrapper.o

STATIC_LIBRARY_PATH = $(PREFIX)/data/programming/libraries/static

# Ideally, this would be -lwhatever, but we have not started patching
# the GNU tools yet...

LIBS = 
HEADER_PATH = $(PREFIX)/data/programming/c/headers/$(PACKAGE)/.

# TODO: Those should be overridable.

CC = gcc
NASM = nasm
AR = ar
RANLIB = ranlib
GZIP = gzip -f

%.o: %.c
	@echo Compiling $<...
	@$(CC) -o $(@) $(CFLAGS) $(INCLUDES) $(DEFS) -c $<
	@$(CC) -M $< $(CFLAGS) $(INCLUDES) $(DEFS) > $(*F).dep

%.o: %.S
	@echo Compiling $<...
	@$(CC) -o $(@) $(CFLAGS) $(INCLUDES) $(DEFS) -c $<
	@$(CC) -M $< $(CFLAGS) $(INCLUDES) $(DEFS) > $(*F).dep

%.o: %.asm
	$(NASM) -o $(@) $< -f elf

.PHONY: splash all clean install package-source package-check package

all: splash makefile 
	@for sub_directory in $(SUB_DIRECTORIES) ; do (cd $$sub_directory && echo -e "\n  Compiling directory: $$sub_directory\n" && $(MAKE)) || exit ; done
	@$(MAKE) storm

clean:
	@for sub_directory in $(SUB_DIRECTORIES) ; do (cd $$sub_directory && $(MAKE) clean) || exit ; done
	rm -f storm
	rm -f *.dep
	-$(MAKE) clean-local
makefile: configure
	@./configure

splash:
	@echo -e "\n  Compiling kernel: storm...\n"

configure: autochaos.rules
	@autochaos


LDFLAGS = -nostdlib -Wl,-T,current-arch/kernel.ld -lgcc -m32 $(EXTRA_LDFLAGS)

storm: $(OBJECTS) $(ALL_OBJECTS)
	@echo "Linking..."
	@$(CC) -o $(@) $(OBJECTS) $(ALL_OBJECTS) $(LIBS) $(LDFLAGS)

install: all
	@for sub_directory in $(SUB_DIRECTORIES) ; do (cd $$sub_directory && $(MAKE) install) || exit ; done
	mkdir -p $(PREFIX)/system/kernel
	cp storm $(PREFIX)/system/kernel
	strip -R .note -R .comment -R .eh_frame $(PREFIX)/system/kernel/storm
	$(GZIP) $(PREFIX)/system/kernel/storm # > $(PREFIX)/system/kernel/storm.gz

package-source:
	@for sub_directory in $(SUB_DIRECTORIES) ; do (cd $$sub_directory && $(MAKE) package-source) || exit ; done
	mkdir -p /home/per/Projects/chaos-old/storm/package-source/.
	-cp -f autochaos.rules changelog configure COPYING README AUTHORS TODO INSTALL /home/per/Projects/chaos-old/storm/package-source/.
	-cp -f makefile.template $(EXTRA_FILES) /home/per/Projects/chaos-old/storm/package-source/.
package-check: package-source
	     cd package-source && ./configure $(ALL_ARGUMENTS) && $(MAKE) && $(MAKE) clean
	     find package-source -name makefile -exec rm {} ';'
	     rm package-source/config.h
package: package-check
	rm -rf storm-0.5.1
	mv package-source storm-0.5.1
	tar cvIf storm-0.5.1.tar.bz2 storm-0.5.1
	     

# $Id$
# Local rules.

storm: current-arch

# FIXME: Make this detect the architecture in some way.

current-arch:
	ln -sf ia32 current-arch

clean-local:
	rm -f current-arch
