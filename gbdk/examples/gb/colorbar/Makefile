CC	= ../../../bin/lcc -Wa-l -Wl-m

CFLAGS	= -DGBDK_2_COMPAT

BINS	= colorbar.gb

all:	$(BINS)

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym

# Link file, and write 0x80 at position 0x143 in header
colorbar.gb:	colorbar.o
	$(CC) $(CFLAGS) -Wl-yC -o colorbar.gb colorbar.o
