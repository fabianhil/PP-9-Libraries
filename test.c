#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<unistd.h>
//#include"help.h"

 int expected_value=1;
 int std_deviation=1;
 int amount_of_values = 100;
 int i;
 double dist_out;
 double res=0.1;
 double start_calc;
 double x; 
 const double PI = 3.141592654;

 int options;


void help(void){

	printf("Version 0.1 Apha \n");
	printf("Autor: Fabian Hilbich, Camil Cieslok\n");
	printf("Dieses Programm, stellt anhand der beim Programmstart, mitgegebenen Variablen die Normalverteilung nach Gauss Dar.\n");
	printf("Optionen: \n");
	printf("-e	Erwartungswert \n");
	printf("-s	Standard-Abweeichung (default =1) \n");
	printf("-a	Anzahl der zu berechneden Werte(default = min 100) \n");
}	





int main (int argc,char *argv[]){

	help();

        FILE *output_stream;
        output_stream = fopen("output_stream.txt", "rw"); //Read/Write

        if (output_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Could not open file\n");
              		exit(-1); // must include stdlib.h
                    }


	start_calc=expected_value-((amount_of_values/2.0)*res);
	
        x=start_calc;
	for(i=0;i<=amount_of_values;i++){
		
                //dist_out=amount_of_values;
                dist_out = (1.0/(std_deviation*sqrt(2.0*PI)))*(exp(-1.0*((pow((x - expected_value), 2.0))/(2.0*(pow(std_deviation, 2.0))))));


                // write to file
		fprintf(output_stream, "%1.12f \n",dist_out); // write to file

                printf("%1.12f \n",dist_out);
                x=x+res;
	}
		
	fclose(output_stream);
        
	return 0;
}
