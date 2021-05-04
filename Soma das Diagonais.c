#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int tamanho;
    scanf("%d", &tamanho);
    int matriz[tamanho][tamanho];
    int i = 0, j = 0;
    int dPrincipal = 0, dSecundaria = 0;
    for(i=0; i<tamanho; i++){
        for(j=0; j<tamanho; j++){
            scanf("%d", &matriz[i][j]);
            if(i == j) dPrincipal += matriz[i][j];
            if(i == tamanho-1-j) dSecundaria += matriz[i][j];
        }
    }
    
    if(dPrincipal > dSecundaria) printf("Principal");
    else if(dPrincipal == dSecundaria) printf("Empate");
    else printf("Secundaria");
    
	return 0;
}