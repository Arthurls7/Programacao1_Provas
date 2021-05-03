#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int primo(int n, int divisor){
    if(n<0) return 0;
    if(n == divisor) return 1;
    if(n == 1 || n == 0) return 1;
    else{
        if(n%divisor == 0) return 0;
        else n = primo(n, divisor+1);
    }
}

int proxPrimo(int n){
    int proxN = n+1;
    if(primo(proxN, 2) == 1){
        return proxN;
    }
    else{
        proxPrimo(n+1);
    }
}

int divisorPrimo(int n, int contador){
    if(contador < n){
        if(n%contador == 0 && primo(contador, 2) == 1) return contador;
        else divisorPrimo(n, contador+1);
    } else{
        return 0;
    }
}

int divisor(int n, int contador){
    if(contador < n){
        if(n%contador == 0 && n%2 == 0) return contador;
        else divisor(n, contador+1);
    } else{
        return 0;
    }
}

void jogo(int n, int acaba, int rodadas, int x){
    
    if(divisorPrimo(n, 2) != 0){
        rodadas++;
        x = divisorPrimo(n, 2);
        if(n%x == 0) n = n/x;
        else n = (n/x)+1;
    } else{
        acaba = 1;
        printf("Protagonista\n");
        printf("%d\n", rodadas);
        return;
    }
    
    if(divisor(n, 2) != 0){
        rodadas++;
        x = divisor(n, 2);
        if(n%x == 0) n = n/x;
        else n = (n/x)+1;
    } else{
        acaba = 1;
        printf("Z\n");
        printf("%d\n", rodadas);
        return;
    }
    
    if(acaba != 1){
        jogo(n, acaba, rodadas, x);
    }
}

void escanear(){
    int n;
    scanf("%d", &n);
    if(n != -1){
        jogo(n, 0, 0, 2);
        escanear();
    } else{
        return;
    }
}

int main() {
    escanear();
    return 0;
}