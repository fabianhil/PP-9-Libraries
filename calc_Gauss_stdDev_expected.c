#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<unistd.h>
#include<Gauss_staticlib.h>

 int expected_value;
 int std_deviation;
 int amount_of_values =100;
 int i;
 const double PI = 3.141592654;

int option;


void help(void){

	printf("Version 0.1 Alpha \n");
	printf("Autor: Fabian Hilbich, Camil Cieslok\n");
	printf("Dieses Programm, berechnet die Standardabweichung und denn Erwartungswert nach Gauß.\n");
	printf("Zur Berechung werden Zeilenweise die ersten 100 Werte in der Datei output_stream.txt im Programmverzeichnis benutzt.\n");
	printf("Optionen: \n");
	printf("-h	Hilfe");
}	





int main (int argc,char *argv[]){
	
       	while((option = getopt(argc, argv, "h")) != -1) 
    	{
    	    switch(option) 
        	{ 
	case 'h':
		help();
	break;	
        }
	}
	
        FILE *input_stream;
        input_stream = fopen("output_stream.txt", "r"); 

        if (input_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Datei nicht gefunden\n");
              		exit(-1); 
                    }


			            print_gaussian_stdDev_exp(amount_of_values,input_stream);
				
	
		
	fclose(input_stream);
        
	return 0;
}