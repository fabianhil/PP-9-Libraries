application: 
	gcc-10 test.c -o test -lm

staticlib:
	gcc *PROGRAMM*.c -c
	ar -crs lib*LIBNAME.a *PROGRAMM*.o
	sudo cp *PROGRAMM*.h /usr/include
	sudo cp lib*LIBNAME.a /usr/include
