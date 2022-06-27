#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 double expected_value=50.0;
 double std_deviation=2.0;
 double amount_of_values = 0;
 int i;
 double dist_out;

 #define PI (3.1415)



 int main (void){

        FILE *output_stream;
        output_stream = fopen("output_stream", "rw"); //Read/Write

        if (output_stream == NULL) // test for files not existing.
            		{
              		printf("Error! Could not open file\n");
              		exit(-1); // must include stdlib.h
                    }

        for(i=0;i<=100;i++){

                //dist_out=amount_of_values;
                dist_out = (1.0/(std_deviation*sqrt(2.0*PI)))*(exp(-1.0*((pow((amount_of_values - expected_value), 2.0))/(2.0*(pow(std_deviation, 2.0))))));


                // write to file
                fprintf(output_stream, "%f \n",dist_out); // write to file

                printf("%f \n",dist_out);
                amount_of_values=amount_of_values+1.0;
                }
        return 0;
}
