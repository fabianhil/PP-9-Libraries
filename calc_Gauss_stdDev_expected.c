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
 char *file_name;


int option;


void help(void){

	printf("Version 1.0 \n");
	printf("Autor: Fabian Hilbich, Camil Cieslok\n");
	printf("Dieses Programm, berechnet die Standardabweichung und denn Erwartungswert nach Gauß.\n");
	printf("Zur Berechung werden Zeilenweise die ersten 100 Werte in der Datei output_stream.txt im Programmverzeichnis benutzt.\n");
	printf("Optionen: \n");
	printf("-h	Hilfe \n");
	printf("-d	'DATEIPFAD' mit diesem Befehl muss der Dateipfad angegeben werden. \n");
}	





int main (int argc,char *argv[]){
	
       	while((option = getopt(argc, argv, "h d: ")) != -1) 
    	{
    	    switch(option) 
        	{ 
			case 'h':
			help();
			case 'd':
			file_name = optarg;
			break;	
			}
		}
	
        FILE *input_stream;
        input_stream = fopen(file_name, "r"); 

        if (input_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Datei nicht gefunden\n");
              		exit(-1); 
                    }

						printf("Statistik der Werte aus der Datei %s : \n",file_name);
			            print_gaussian_stdDev_exp(amount_of_values,input_stream);
				
	
		
	fclose(input_stream);
	
	printf("Für Hilfe Programm mit -h ausführen. \n");
        
	return 0;
}