application_header_only: 
	gcc-10 header_only_Gauss.c -o header_only_Gauss -lm

application_static: staticlib 
	gcc-10 calc_Gauss_stdDev_expected.c -o calc_Gauss_stdDev_expected -lGauss_staticlib -lm
	
staticlib:
	gcc Gauss_staticlib.c -c
	ar -crs libGauss_staticlib.a Gauss_staticlib.o
	sudo cp Gauss_staticlib.h /usr/include
	sudo cp libGauss_staticlib.a /usr/include
