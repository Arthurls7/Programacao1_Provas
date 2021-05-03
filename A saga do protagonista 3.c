#include <stdio.h>
#include <stdlib.h>

int array[100], subArray[100];
int tamanhoArray, tamanhoSubArray;
int posicaoFim = 0, contSeq = 0, contSeqTotal = 0;

void escanear(int array[], int tamanho, int contador){
    scanf("%d", &array[contador]);
    if(contador<tamanho-1) escanear(array, tamanho, contador+1);
    else return;
}

void comparar(int posAtual, int contador){
    if(array[posAtual] == subArray[contador]) contSeq++;
    if(contador<tamanhoSubArray-1) comparar(posAtual+1, contador+1);
}

void calcular(int contador){
    comparar(contador, 0);
    
    if(contSeq > contSeqTotal){
        contSeqTotal = contSeq;
        posicaoFim = contador;
    }
    
    if(contador<(tamanhoArray-tamanhoSubArray)+1){
        contSeq = 0;
        calcular(contador+1);
    }
}

void imprimir(int contador){
    if(contador == posicaoFim+tamanhoSubArray-1){
        printf("%d\n", array[contador]);
        printf("%d", tamanhoSubArray-contSeqTotal);
        return;
    } 
    
    printf("%d ", array[contador]);
    if(contador<posicaoFim+tamanhoSubArray-1) imprimir(contador+1);
}

void main() {
    scanf("%d", &tamanhoArray);
    escanear(array, tamanhoArray, 0);
    scanf("%d", &tamanhoSubArray);
    escanear(subArray, tamanhoSubArray, 0);
    
    calcular(0);
    imprimir(posicaoFim);
}