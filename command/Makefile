# commands/Makefile

#ENTRYPOINT	= 0x1000
HD		= ../80m.img

ASM		= nasm
DASM		= objdump
CC		= gcc
LD		= ld
ASMFLAGS	= -I ../include/ -f elf
CFLAGS		= -m32 -I ../include/ -c -fno-builtin -fno-stack-protector -Wall
LDFLAGS		= -m elf_i386 -Ttext 0x1000
DASMFLAGS	= -D
LIB		= ../lib/orangescrt.a
BIN		= echo help calendar calculator jsb

# All Phony Targets
.PHONY : everything final clean realclean disasm all install

# Default starting position
everything : $(BIN)

install : all clean
	cp ../boot/hd*.bin ./ -v
	cp ../kernel.bin ./ -v
	tar vcf inst.tar kernel.bin $(BIN)
	dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc
all : realclean everything

final : all clean

clean :
	rm -f *.o
realclean :
	rm -f $(BIN) *.o

kernel.bin :
	cp ../kernel.bin ./

start.o : start.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

echo.o: echo.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

echo : echo.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

help.o: help.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

help : help.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

calendar.o: calendar.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

calendar : calendar.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

calculator.o: calculator.c ../include/type.h ../include/stdio.h ../include/string.h
	$(CC) $(CFLAGS) -o $@ $<

calculator : calculator.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

jsb.o: jsb.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<

jsb : jsb.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?
