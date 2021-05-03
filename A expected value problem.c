#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int somaAteN(int n, int soma, int contador){
    if(contador<=n) somaAteN(n, soma+contador, contador+1);
    else return soma;
}

int somarArray(int array[], int tamanho, int contador, int soma){
    soma+= array[contador];
    if(contador<tamanho-1) somarArray(array, tamanho, contador+1, soma);
    else return soma;
}

int formula(int n, int arraySoma[], int contador){
    if(contador<n){
        arraySoma[contador] = somaAteN(contador+1, 0, 1);
        formula(n, arraySoma, contador+1);
    } else{
        int soma;
        soma = somarArray(arraySoma, n, 0, 0);
        return soma;
    }
}

void valorFinal(int arraySoma[], int soma, int contador, int n, double resultado){
    if(contador<n){
        resultado += (double)((double)arraySoma[contador]/(double)soma) * (double)(contador+1);
        valorFinal(arraySoma, soma, contador+1, n, resultado);
    } else{
        printf("%.2lf", resultado);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arraySoma[n];
    int soma;
    soma = formula(n, arraySoma, 0);
    valorFinal(arraySoma, soma, 0, n, 0);
    
    return 0;
}