#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 double expected_value=1.0;
 double std_deviation=1.0;
 double amount_of_values = 100;
 int i;
 double dist_out;
 double res=0.1;
 double start;
 double x; 
 const double PI = 3.1415;



 int main (void){
	
        FILE *output_stream;
        output_stream = fopen("output_stream.txt", "rw"); //Read/Write

        if (output_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Could not open file\n");
              		exit(-1); // must include stdlib.h
                    }

	start=expected_value-((amount_of_values/2.0)*res);
	
        x=start;
	for(i=0;i<=amount_of_values;i++){
		
                //dist_out=amount_of_values;
                dist_out = (1.0/(std_deviation*sqrt(2.0*PI)))*(exp(-1.0*((pow((x - expected_value), 2.0))/(2.0*(pow(std_deviation, 2.0))))));


                // write to file
		fprintf(output_stream, "Wert: %f \n",dist_out); // write to file

                printf("%f \n",dist_out);
                x=x+res;
                }
		fclose(output_stream);
        return 0;
}
