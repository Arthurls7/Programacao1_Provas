#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void escanear(int array[], int tamanho, int contador){
    scanf("%d", &array[contador]);
    if(contador<tamanho-1) escanear(array, tamanho, contador+1);
    else return;
}

int percorre1(int tam, int contador, int valor, int posAtual){
    posAtual += 1;
    if(posAtual == tam) posAtual = 0;
    if(contador<valor) percorre1(tam, contador+1, valor, posAtual);
    else return posAtual;
}

int percorre2(int tam, int contador, int valor, int posAtual){
    posAtual -= 1;
    if(posAtual < 0) posAtual = tam-1;
    if(contador<valor) percorre2(tam, contador+1, valor, posAtual);
    else return posAtual;
}

void movimentos(int array[], int tam, int contador, int index){
    
    if(contador%2 == 0){
        if(array[contador] != 0) index = percorre1(tam, 1, array[contador], index);
    } else{
        if(array[contador] != 0) index = percorre2(tam, 1, array[contador], index);
    }
    
    if(contador<tam-1) movimentos(array, tam, contador+1, index);
    else printf("\n%d", index);
}


int main() {
    int tamanhoArray;
    scanf("%d", &tamanhoArray);
    int array[tamanhoArray];
    escanear(array, tamanhoArray, 0);
    movimentos(array, tamanhoArray, 0, 0);
    
    return 0;
}