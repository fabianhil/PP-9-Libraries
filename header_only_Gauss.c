#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<unistd.h>
#include"headerlib.h"

 int expected_value=10;
 int std_deviation=1;
 int amount_of_values = 100;
 int i;
 const double PI = 3.141592654;

 int option;


void help(void){

	printf("Version 0.1 Apha \n");
	printf("Autor: Fabian Hilbich, Camil Cieslok\n");
	printf("Dieses Programm, generiert mit Hilfe der beim Programmstart, übergebenen Variablen eine definierte Anzahl von Normalverteilten Zufallswerten nach Gauß.\n");
	printf("Sollten Beim Progammstart keine Variablen übergeben worden sein, findet eine automatische Generierung der Zahlen mit den Default Werten statt. \n");
	printf("Die Ausgabe erfolgt in die Konsole sowie in die Datei (output_stream.txt) im Programmverzeichnis. \n");
	printf("Optionen: \n");
	printf("-e	Erwartungswert (default = 10 \n");
	printf("-s	Standardabweichung (default = 1) \n");
	printf("-a	Anzahl der zu berechnenden Werte(default = min 100) \n");
}	





int main (int argc,char *argv[]){
	
       	while((option = getopt(argc, argv, "h e: s: a: ")) != -1) 
    	{
    	    switch(option) 
        	{ 
			case 'h':
				help();
			break;	
			case 'e': 
						expected_value=atoi(optarg);
				printf("Erwartungswert: %i\n", expected_value); 
			break; 
			case 's': 
						std_deviation=atoi(optarg); 
				printf("Standardabweichung: %i \n", std_deviation); 
			break; 
			case 'a': 
						amount_of_values=atoi(optarg);
				printf("Anzahl Werte: %i\n", amount_of_values);
			break; 
			}
		}
        FILE *output_stream;
        output_stream = fopen("output_stream.txt", "w+"); 

        if (output_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Datei nicht gefunden\n");
              		exit(-1); 
                    }


			for(i=0;i<=amount_of_values;i++){
		
                print_gaussian_dist(expected_value,std_deviation,amount_of_values, output_stream);
				
	}
		
	fclose(output_stream);
        
	return 0;
}
