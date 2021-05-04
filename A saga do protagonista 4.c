#include<stdio.h>

//Imprime matriz
void imprimir(int matriz[8][8]){
    printf("\n");
    for(int i=0; i<8; i++){
        printf("\n");
        for(int j=0; j<8; j++){
            printf("%d ", matriz[i][j]);
        }
    }
}

//Copia matriz 1 em matriz 2
void copiaMatriz(int matriz1[8][8], int matriz2[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matriz2[i][j] = matriz1[i][j];
        }
    }
}

//Verifica se a torre captura o rei
int movimentosTorre(int posX, int posY, int matriz[8][8]){
    int resultado = 0;
    for(int i=posY-1; i>=0; i--){
        if(matriz[posX][i] == 3) resultado = 1;
        if(matriz[posX][i] == 2) break;
    }

    for(int i=posY+1; i<8; i++){
        if(matriz[posX][i] == 3) resultado = 1;
        if(matriz[posX][i] == 2) break;
    }

    for(int j=posX-1; j>=0; j--){
        if(matriz[j][posY] == 3) resultado = 1;
        if(matriz[j][posY] == 2) break;
    }

    for(int j=posX+1; j<8; j++){
        if(matriz[j][posY] == 3) resultado = 1;
        if(matriz[j][posY] == 2) break;
    }

    return resultado;
}

//Verifica se o rei1 captura o rei2
int movimentosRei(int posX, int posY, int matriz[8][8]){
    int resultado = 0;
    if(posX-1>=0 && matriz[posX-1][posY] == 3) resultado = 1; //Cima
    if(posX+1<8 && matriz[posX+1][posY] == 3) resultado = 1; //Baixo
    if(posY-1>=0 && matriz[posX][posY-1] == 3) resultado = 1; //Esquerda
    if(posY+1<8 && matriz[posX][posY+1] == 3) resultado = 1; //Direita
        
    if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 3) resultado = 1; //Diagonal dir superior
    if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 3) resultado = 1; //Diagonal dir inferior
    if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 3) resultado = 1; //Diagonal esq superior
    if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 3) resultado = 1; //Diagonal esq inferior
    return resultado;
}

//Verifica se o rei2 captura o rei 1 e ganha o jogo
int reiCapturaRei(int posX, int posY, int matriz[8][8]){
    int eliminado = 0;
    //printf("\nMatrix x y: %d\n",matriz[posX][posY]);
    if(posX-1>=0 && matriz[posX-1][posY] == 2) eliminado = 1; //Cima
    if(posX+1<8 && matriz[posX+1][posY] == 2) eliminado = 1; //Baixo
    if(posY-1>=0 && matriz[posX][posY-1] == 2) eliminado = 1; //Esquerda
    if(posY+1<8 && matriz[posX][posY+1] == 2)  eliminado = 1; //Direita
        
    if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 2) eliminado = 1; //Diagonal dir superior
    if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 2) eliminado = 1; //Diagonal dir inferior
    if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 2) eliminado = 1; //Diagonal esq superior
    if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 2) eliminado = 1; //Diagonal esq inferior
    //printf("\n%d", eliminado);
    return eliminado;
}

//Marca as casas em que a torre pode chegar
void casasTorreOcupa(int posX, int posY, int matriz[8][8]){
    for(int i=posY-1; i>=0; i--){
        if(matriz[posX][i] == 4 || matriz[posX][i] == 3) continue;
        if(matriz[posX][i] != 0) break;
        else matriz[posX][i] = 4;
    }

    for(int i=posY+1; i<8; i++){
        if(matriz[posX][i] == 4 || matriz[posX][i] == 3) continue;
        if(matriz[posX][i] != 0) break;
        else matriz[posX][i] = 4;
    }

    for(int j=posX-1; j>=0; j--){
        if(matriz[j][posY] == 4 || matriz[j][posY] == 3) continue;
        if(matriz[j][posY] != 0) break;
        else matriz[j][posY] = 4;
    }

    for(int j=posX+1; j<8; j++){
        if(matriz[j][posY] == 4 || matriz[j][posY] == 3) continue;
        if(matriz[j][posY] != 0) break;
        else matriz[j][posY] = 4;
    }
}

//Marca as casas em que o rei1 pode chegar
void casasReiOcupa(int posX, int posY, int matriz[8][8]){
    //printf("\nMatrix x y: %d\n",matriz[posX][posY]);
    if(posX-1>=0 && matriz[posX-1][posY] == 0) matriz[posX-1][posY] = 5; //Cima
    if(posX+1<8 && matriz[posX+1][posY] == 0) matriz[posX+1][posY] = 5; //Baixo
    if(posY-1>=0 && matriz[posX][posY-1] == 0) matriz[posX][posY-1] = 5; //Esquerda
    if(posY+1<8 && matriz[posX][posY+1] == 0)  matriz[posX][posY+1] = 5; //Direita
        
    if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 0) matriz[posX-1][posY+1] = 5; //Diagonal dir superior
    if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 0) matriz[posX+1][posY+1] = 5; //Diagonal dir inferior
    if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 0) matriz[posX-1][posY-1] = 5; //Diagonal esq superior
    if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 0) matriz[posX+1][posY-1] = 5; //Diagonal esq inferior
}

//Verifica se o rei consegue capturar alguma torre
int reiCapturaTorre(int posX, int posY, int matriz[8][8]){
    int eliminado = 0;
    //printf("\nMatrix x y: %d\n",matriz[posX][posY]);
    if(posX-1>=0 && matriz[posX-1][posY] == 1) eliminado += 1; //Cima
    if(posX+1<8 && matriz[posX+1][posY] == 1) eliminado += 1; //Baixo
    if(posY-1>=0 && matriz[posX][posY-1] == 1) eliminado += 1; //Esquerda
    if(posY+1<8 && matriz[posX][posY+1] == 1)  eliminado += 1; //Direita
        
    if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 1) eliminado += 1; //Diagonal dir superior
    if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 1) eliminado += 1; //Diagonal dir inferior
    if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 1) eliminado += 1; //Diagonal esq superior
    if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 1) eliminado += 1; //Diagonal esq inferior
    //printf("\n%d", eliminado);
    return eliminado;
}

//Movimento em que o rei2 pode capturar as duas torres
int trocaReiTorre(int xRei, int yRei, int xTorre, int yTorre, int matriz[8][8]){
    matriz[xRei][yRei] = 0;
    matriz[xTorre][yTorre] = 3;
}

//Movimento em que o rei2 captura uma torre
void reiComeuTorre(int posX, int posY, int matriz[8][8]){
    //printf("\nMatrix x y: %d\n",matriz[posX][posY]);
    if(posX-1>=0 && matriz[posX-1][posY] == 1){
        matriz[posX][posY] = 0;
        matriz[posX-1][posY] = 3;
    } //Cima
    else if(posX+1<8 && matriz[posX+1][posY] == 1){
        matriz[posX][posY] = 0;
        matriz[posX+1][posY] = 3;
    } //Baixo
    else if(posY-1>=0 && matriz[posX][posY-1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX][posY-1] = 3;
    } //Esquerda
    else if(posY+1<8 && matriz[posX][posY+1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX][posY+1] = 3;
    } //Direita
        
    else if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX-1][posY+1] = 3;
    } //Diagonal dir superior
    else if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX+1][posY+1] = 3;
    } //Diagonal dir inferior
    else if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX-1][posY-1] = 3;
    } //Diagonal esq superior
    else if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 1){
        matriz[posX][posY] = 0;
        matriz[posX+1][posY-1] = 3;
    } //Diagonal esq inferior
}

//Casas que o rei2 pode ir sem morrer
int casasPossiveis(int posX, int posY, int matriz[8][8]){
    int casasPossiveis = 0;
    //printf("\nMatrix x y: %d\n",matriz[posX][posY]);
    if(posX-1>=0 && matriz[posX-1][posY] == 0) casasPossiveis += 1; //Cima
    if(posX+1<8 && matriz[posX+1][posY] == 0) casasPossiveis += 1; //Baixo
    if(posY-1>=0 && matriz[posX][posY-1] == 0) casasPossiveis += 1; //Esquerda
    if(posY+1<8 && matriz[posX][posY+1] == 0)  casasPossiveis += 1; //Direita
        
    if(posX-1>=0 && posY+1<8 && matriz[posX-1][posY+1] == 0) casasPossiveis += 1; //Diagonal dir superior
    if(posY+1<8 && posX+1<8 && matriz[posX+1][posY+1] == 0) casasPossiveis += 1; //Diagonal dir inferior
    if(posX-1>=0 && posY-1>=0 && matriz[posX-1][posY-1] == 0) casasPossiveis += 1; //Diagonal esq superior
    if(posX+1<8 && posY-1>=0 && matriz[posX+1][posY-1] == 0) casasPossiveis += 1; //Diagonal esq inferior
    //printf("\n%d", casasPossiveis);
    return casasPossiveis;
}

int main(){
    int quantidadeMatriz;
    scanf("%d", &quantidadeMatriz);
    int matriz[8][8], loop=0;
    int torre1X = -1, torre1Y = -1;
    int torre2X = -1, torre2Y = -1;
    int rei1X, rei1Y;
    int rei2X, rei2Y;
    int casasRei[8];
    
    while(loop < quantidadeMatriz){
        for(int i=0; i<8; i++){
            //printf("\n");
            for(int j=0; j<8; j++){
                scanf("%d", &matriz[i][j]);
                if(matriz[i][j] == 1 && torre1X == -1){
                    torre1X = i;
                    torre1Y = j;
                } else if(matriz[i][j] == 1 && torre1X != -1){
                    torre2X = i;
                    torre2Y = j;
                }

                if(matriz[i][j] == 2){
                    rei1X = i;
                    rei1Y = j;
                } else if(matriz[i][j] == 3){
                    rei2X = i;
                    rei2Y = j;
                }
                //printf("%d ", matriz[i][j]);
            }
        }

        if(reiCapturaRei(rei2X, rei2Y, matriz) == 1){
            printf("No\n");
            loop++;
            torre1X = -1; torre1Y = -1;
            torre2X = -1; torre2Y = -1;
            continue;
        }

        //printf("\nQtd torres capturaveis: %d", reiCapturaTorre(rei2X, rei2Y, matriz));
        //printf("\nCasas possiveis: %d", casasPossiveis(rei2X, rei2Y, matriz));
        
        if(reiCapturaTorre(rei2X, rei2Y, matriz) == 1){
            int matrizCopia[8][8];
            int qtdCasas = 0;
            copiaMatriz(matriz, matrizCopia);
            reiComeuTorre(rei2X, rei2Y, matrizCopia);
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(matrizCopia[i][j] == 3){
                        rei2X = i;
                        rei2Y = j;
                    } else if(matrizCopia[i][j] == 1){
                        torre1X = i;
                        torre1Y = j;
                    }
                }
            }
            
            if(movimentosTorre(torre1X, torre1Y, matrizCopia) == 0 && movimentosRei(rei1X, rei1Y, matrizCopia) == 0){
                printf("No\n");
                loop++;
                torre1X = -1; torre1Y = -1;
                torre2X = -1; torre2Y = -1;
                continue;
            }
        } 

        else if(reiCapturaTorre(rei2X, rei2Y, matriz) == 2){
            int matriz1[8][8];
            int matriz2[8][8];
            copiaMatriz(matriz, matriz1);
            copiaMatriz(matriz, matriz2);
            trocaReiTorre(rei2X, rei2Y, torre1X, torre1Y, matriz1);
            trocaReiTorre(rei2X, rei2Y, torre2X, torre2Y, matriz2);
            if(movimentosTorre(torre2X, torre2Y, matriz1) == 0 && movimentosRei(rei1X, rei1Y, matriz1) == 0){
                printf("No\n");
                loop++;
                torre1X = -1; torre1Y = -1;
                torre2X = -1; torre2Y = -1;
                continue;
            } else if(movimentosTorre(torre1X, torre1Y, matriz2) == 0 && movimentosRei(rei1X, rei1Y, matriz2) == 0){
                printf("No\n");
                loop++;
                torre1X = -1; torre1Y = -1;
                torre2X = -1; torre2Y = -1;
                continue;
            }
        } 
     
        casasTorreOcupa(torre1X, torre1Y, matriz);
        casasTorreOcupa(torre2X, torre2Y, matriz);
        casasReiOcupa(rei1X, rei1Y, matriz);
        //printf("\nCasas possiveis: %d", casasPossiveis(rei2X, rei2Y, matriz));
        if(casasPossiveis(rei2X, rei2Y, matriz) == 0){
            printf("Yes\n");
        } else{
            printf("No\n");
        }
        loop++;
        torre1X = -1; torre1Y = -1;
        torre2X = -1; torre2Y = -1;
    }
}