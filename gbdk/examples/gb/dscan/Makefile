CC	= ../../../bin/lcc -Wa-l -Wl-m

BINS	= dscan.gb

all:	$(BINS)

%.o:	%.c
	$(CC) -c -o $@ $<

%.s:	%.c
	$(CC) -S -o $@ $<

%.o:	%.s
	$(CC) -c -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym

# Link file, and write 0x80 at position 0x143 in header
dscan.gb:	dscan.o
	$(CC) -Wl-yc -o dscan.gb dscan.o
