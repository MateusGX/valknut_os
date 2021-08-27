CC=gcc
TARGET=valknut
C_FILES=./kernel/screen/screen.c  \
		./kernel/libs/string.c \
		./kernel/io/io.c \
		./kernel/graphics/footer.c \
		./kernel/sys/sys.c \
		./kernel.c

OBJS=$(C_FILES:.c=.o)

all compile:$(TARGET)
all: finale

.PHONY: all compile clean finale

%.o:
	$(CC) -c $(@:.o=.c) -o $@ -ffreestanding -fno-exceptions -m32 -Wall

$(TARGET):$(OBJS)
	$(shell nasm -f elf start.asm -o start.o)
				
	$(CC) -m32 -nostdlib -nodefaultlibs -lgcc start.o $? -T linker.ld -o $(TARGET)

finale:
	$(shell cp $(TARGET) ./iso/boot/$(TARGET))
	$(shell grub-mkrescue ./iso --output=$(TARGET).iso)

clean: 
	rm -f *.o $(TARGET) $(TARGET).iso
	rm -f ./kernel/io/*.o
	rm -f ./kernel/libs/*.o
	rm -f ./kernel/screen/*.o
	rm -f ./kernel/graphics/*.o
	rm -f ./kernel/sys/*.o
	rm -f ./iso/boot/$(TARGET)
