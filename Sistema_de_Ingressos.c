#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int dia, estudante, socio;
    double ingresso;
    scanf("%d %d %d", &dia, &estudante, &socio);
    
    if(dia == 1 || dia == 2 || dia == 3 || dia == 4){
        if(estudante == 1){
            ingresso = 15.0 - (15*0.3);
            printf("ESTUDANTE: R$ %.2lf", ingresso);
            return 0;
        } else if(socio == 1){
            printf("SOCIO: R$ %.2lf", 15.00);
            return 0;
        }
        
        printf("COMUM: R$ %.2lf", 15.00);
    } else if(dia == 5 || dia == 6 || dia == 7){
        if(estudante == 1){
            ingresso = 30.0 - (30*0.3);
            printf("ESTUDANTE: R$ %.2lf", ingresso);
            return 0;
        } else if(socio == 1){
            ingresso = 30.0 - (30*0.2);
            printf("SOCIO: R$ %.2lf", ingresso);
            return 0;
        }
        
        printf("COMUM: R$ %.2lf", 30.00);    
    } else{
        printf("Dia invalido");
    }
    
	return 0;
}
