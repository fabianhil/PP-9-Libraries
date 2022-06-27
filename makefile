application: 
	gcc-10 test.c -o test -lm

staticlib:
	gcc *PROGRAMM*.c -c
	ar -crs lib*LIBNAME.a *LIBNAME*.o
	sudo cp *LIBNAME*.h /usr/include
	sudo cp lib*LIBNAME.a /usr/include
