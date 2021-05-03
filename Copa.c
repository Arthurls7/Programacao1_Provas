#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

float aplicarDesconto(float desconto, float ingresso){
    ingresso = ingresso - (ingresso*desconto);
    return ingresso;
}

int main() {
    char nacionalidade, sexo;
    int idade, maiorIdade;
    float valorIngresso;
    float descontoF = 0.1;
    float descontoM = 0.0;
    scanf("%c %d %c %f", &nacionalidade, &idade, &sexo, &valorIngresso);

    if(idade<0 || idade>120){
        printf("idade invalida!");
        exit(1);
    }
    
    if(nacionalidade == 'B' || nacionalidade == 'A'){
        maiorIdade = 18;
    }
    
    if(nacionalidade == 'B'){
        descontoM = 0.5;
        descontoF = 0.5;
    } else if(nacionalidade == 'A' && idade >= maiorIdade && sexo == 'M'){
        descontoM = 0.0;
    } else if(nacionalidade == 'A' && idade >= maiorIdade && sexo == 'F'){
        descontoF = 0.2;
    } else if(nacionalidade == 'A' && idade < maiorIdade){
        descontoM = 0.2;
        descontoF = 0.2;
    }
    
    if(nacionalidade == 'F' || nacionalidade == 'C'){
        maiorIdade = 21;
    } 
    
    if((nacionalidade == 'F' || nacionalidade == 'C') && idade<maiorIdade){
        printf("nao pode comprar");
        exit(1);
    }
    
    if(nacionalidade == 'F' || nacionalidade == 'C' && idade>=maiorIdade){
        descontoM = 0.3;
        descontoF = 0.3;
    }

    if(nacionalidade == 'I' || nacionalidade == 'R'){
        maiorIdade = 16;
    } 
    
    if((nacionalidade == 'I' || nacionalidade == 'R') && idade >= maiorIdade){
        descontoM = 0.3;
        descontoF = 0.3;
    } else if((nacionalidade == 'I' || nacionalidade == 'R') && idade < maiorIdade){
        descontoM = 0.4;
        descontoF = 0.4;
    }
    
    if(sexo == 'M'){
        printf("R$ %.2f", aplicarDesconto(descontoM, valorIngresso));
    } else if(sexo == 'F'){
        printf("R$ %.2f", aplicarDesconto(descontoF, valorIngresso));
    }
        
	return 0;
}