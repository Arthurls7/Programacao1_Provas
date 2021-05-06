#include<stdio.h>

int ehPrimo(int n, int divisor){
    if(n == 0 || n == 1) return 0;
    
    if(divisor >= 2){
        if(n%divisor == 0) return 0;
        else return ehPrimo(n, divisor-1);
    } else{
        return 1;
    }
}

int primoAnterior(int n){
    if(n >= 2){
        if(ehPrimo(n, n-1) == 1) return n;
        else return primoAnterior(n-1);
    } else{
        return 0;
    }
}

int escanear(int maior, int menor, int contador, int tamRecursao){
    int numero;
    scanf("%d", &numero);

    if(numero>maior && numero%2 == 0) maior = numero;
    
    if(menor == 0 && numero%2 != 0) menor = numero;
    else if(numero<menor && numero%2 != 0) menor = numero;

    if(contador<tamRecursao) return escanear(maior, menor, contador+1, tamRecursao);
    else{
        if(maior == 0) printf("Sem numeros pares\n");
        else{
            printf("Maior par: %d\n", maior);
            printf("Primo anterior ao maior: %d\n", primoAnterior(maior-1));
        }

        if(menor == 0) printf("Sem numeros impares\n");
        else{
            printf("Menor impar: %d\n", menor);
            printf("Primo anterior ao menor: %d", primoAnterior(menor-1));
        }
    }
}

int main(){
    int tamRecursao;
    scanf("%d", &tamRecursao);
    escanear(0, 0, 1, tamRecursao);
}
