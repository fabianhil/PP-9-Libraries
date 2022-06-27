application: 
	gcc-10 header_only_Gauss.c -o header_only_Gauss -lm

staticlib:
	gcc *PROGRAMM*.c -c
	ar -crs lib*LIBNAME.a *LIBNAME*.o
	sudo cp *LIBNAME*.h /usr/include
	sudo cp lib*LIBNAME.a /usr/include
