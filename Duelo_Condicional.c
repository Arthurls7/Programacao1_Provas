#include<stdio.h>

int main(){
    double nivel1, nivel2, dano, vida;

    scanf("%lf %lf", &nivel1, &dano);
    scanf("%lf %lf", &nivel2, &vida);

    if(nivel1>=1 && nivel1<=5) dano = dano * 1.20;
    else if(nivel1>=6 && nivel1<=10) dano = dano * 1.50;
    else if(nivel1>=11 && nivel1<=15) dano = dano * 1.80;
    else if(nivel1>=16 && nivel1<=20) dano = dano * 2.00;
    else if(nivel1 < 1){
        printf("Nivel abaixo");
        return 0;
    } else if(nivel1 > 20){
        printf("Nivel acima");
        return 0;
    }

    if(nivel2>=1 && nivel2<=5) vida = vida * 1.20;
    else if(nivel2>=6 && nivel2<=10) vida = vida * 1.50;
    else if(nivel2>=11 && nivel2<=15) vida = vida * 1.80;
    else if(nivel2>=16 && nivel2<=20) vida = vida * 2.00;
    else if(nivel2 < 1){
        printf("Nivel abaixo");
        return 0;
    } else if(nivel2 > 20){
        printf("Nivel acima");
        return 0;
    }

    double calculo = vida - dano;

    if(calculo>0.00){
        printf("Personagem 2 venceu\n");
        printf("Vida restante: %.2lf", calculo);
    } else{
        printf("Personagem 1 venceu\n");
        printf("Dano causado: %.2lf", dano);
    }

    return 0;
}
