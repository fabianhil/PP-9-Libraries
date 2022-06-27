application: staticlib
	gcc *HAUPTPROGRAMM*.c -l*PROGRAMM1* -l*PROGRAMM2*

staticlib:
	gcc *PROGRAMM*.c -c
	ar -crs lib*LIBNAME.a *PROGRAMM*.o
	sudo cp *PROGRAMM*.h /usr/include
	sudo cp lib*LIBNAME.a /usr/include
