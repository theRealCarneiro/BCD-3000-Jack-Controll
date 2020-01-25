BCD:	BCD_3000_Midi.o	jack.o
	gcc BCD_3000_Midi.o jack.o -o BCD -lasound
BCD_3000_Midi.o:	BCD_3000_Midi.c
	gcc -c BCD_3000_Midi.c
jack.o:	jack.c
	gcc -c jack.c
clean:
	rm -rf *.o
install:
	install BCD /usr/local/bin
uninstall:
	rm /usr/local/bin/BCD
