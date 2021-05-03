#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

int main() {

    int d, r, l, p, g, dReal, gNecessaria, lNecessarios;
    scanf("%d %d %d %d %d", &d, &r, &l, &p, &g);
    dReal = d - (10*l);
    gNecessaria = g*dReal/10;
    lNecessarios = dReal/10;
    
    if(d<=(10*l)){
        printf("Pode viajar.");
        printf("\nR$: %d", r);
    } else if((dReal/p)>(l*10)){
        printf("Nao pode viajar.");
    } else if(r>=gNecessaria && d>(10*l)){
        printf("Pode viajar."); 
        printf("\nR$: %d", r-gNecessaria);
    } else{
       printf("Nao pode viajar.");
    }
    
	return 0;
}