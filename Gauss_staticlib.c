#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ZEILENLAENGE 30

void print_gaussian_stdDev_exp(int amount_of_values, FILE *input_stream) {

    char buffer[ZEILENLAENGE];
    char* end;
    double sum=0, exp_value=0, std_Dev=0;
    double temp=0, temp_var=0, var=0, value=0;
    int i=0;


    while(fgets(buffer, ZEILENLAENGE, input_stream)&&i<=amount_of_values-1) {
        temp=(strtod(buffer, &end))+temp;						//Summe aller Werte
        temp_var=(pow((strtod(buffer, &end)),2.0))+temp_var;	//n1^2 + n2^2 + ...
        i++;
    }

    sum=temp;
    printf("Summe aller Werte: %f\n",sum);

    exp_value=sum/amount_of_values;								//Berechnen des Erwartungswertes
    printf("Erwartungswert: %f\n",exp_value);

    var=(temp_var/amount_of_values)-(pow(exp_value,2.0));			//Berechnen der Varianz
    printf("Varianz: %f\n",var);

    std_Dev=sqrt(var);											//Berechnen der Standardabweichung
    printf("Standardabweichung; %f\n",std_Dev);

    return;
}