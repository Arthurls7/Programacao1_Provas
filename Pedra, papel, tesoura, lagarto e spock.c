#include <stdio.h>
#include <stdlib.h>

int batalha(int jogada1, int jogada2){
    int vencedor = 0;
    //1 para Rodrigo vencedor
    //2 para Willy vencedor
    if(jogada1 == jogada2) return vencedor;

    if(jogada1 == 1){
        if(jogada2 == 2) vencedor = 2;
        else if(jogada2 == 3) vencedor = 1;
        else if(jogada2 == 4) vencedor = 1;
        else if(jogada2 == 5) vencedor = 2;
    } else if(jogada1 == 2){
        if(jogada2 == 1) vencedor = 1;
        else if(jogada2 == 3) vencedor = 2;
        else if(jogada2 == 4) vencedor = 1;
        else if(jogada2 == 5) vencedor = 2;
    } else if(jogada1 == 3){
        if(jogada2 == 1) vencedor = 2;
        else if(jogada2 == 2) vencedor = 1;
        else if(jogada2 == 4) vencedor = 2;
        else if(jogada2 == 5) vencedor = 1;
    } else if(jogada1 == 4){
        if(jogada2 == 1) vencedor = 2;
        else if(jogada2 == 2) vencedor = 2;
        else if(jogada2 == 3) vencedor = 1;
        else if(jogada2 == 5) vencedor = 1;
    } else if(jogada1 == 5){
        if(jogada2 == 1) vencedor = 1;
        else if(jogada2 == 2) vencedor = 1;
        else if(jogada2 == 3) vencedor = 2;
        else if(jogada2 == 4) vencedor = 2;
    }

    return vencedor;
}

int main() {
    
    int jog1Rodrigo, jog2Rodrigo, jog1Willy, jog2Willy;
    double apostaRodrigo, apostaWilly;
    int pntRodrigo = 0, pntWilly = 0;
    double bonusAposta = 0;

    scanf("%lf %lf", &apostaRodrigo, &apostaWilly);
    scanf("%d %d", &jog1Rodrigo, &jog1Willy);
    scanf("%d %d", &jog2Rodrigo, &jog2Willy);

    //Batalha 1
    if(batalha(jog1Rodrigo, jog1Willy) == 1){
        printf("Rodrigo venceu a partida 1\n");
        pntRodrigo += 1;
        bonusAposta += 5;
    } else if(batalha(jog1Rodrigo, jog1Willy) == 2){
        printf("Willy venceu a partida 1\n");
        pntWilly += 1;
        bonusAposta += 5;
    } else if(batalha(jog1Rodrigo, jog1Willy) == 0){
        printf("Empate\n");
    }

    //Batalha 2
    if(batalha(jog2Rodrigo, jog2Willy) == 1){
        printf("Rodrigo venceu a partida 2\n");
        pntRodrigo += 1;
        bonusAposta += 5;
    } else if(batalha(jog2Rodrigo, jog2Willy) == 2){
        printf("Willy venceu a partida 2\n");
        pntWilly += 1;
        bonusAposta += 5;
    } else if(batalha(jog2Rodrigo, jog2Willy) == 0){
        printf("Empate\n");
    }

    //Vencedor geral
    if(pntRodrigo > pntWilly){
        printf("Rodrigo foi o vencedor da aposta");
    } else if(pntWilly > pntRodrigo){
        printf("Willy foi o vencedor da aposta");
    } else{
        printf("Empate na aposta");
        return 0;
    }

    //Valor aposta
    double resultado = apostaRodrigo+apostaWilly;
    
    if(bonusAposta != 0){
        resultado = resultado + (bonusAposta/100 * resultado);
        printf("\nValor ganho: R$%.2lf", resultado);
    }

	return 0;
}
