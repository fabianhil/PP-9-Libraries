#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ZEILENLAENGE 30

void print_gaussian_stdDev_exp(int amount_of_values, FILE *input_stream){
	
	char buffer[ZEILENLAENGE], rnd_number[20];
	
	  
		for(int i = 0; amount_of_values-1 >= i; i++){
		  
			while(fgets(buffer, ZEILENLAENGE, input_stream))
			fputs(buffer, stdout);
		}
return;
}