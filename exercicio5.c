#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int numero = 0;
    printf("Digite um número inteiro para saber se é múltiplo de 3 ou 5: \n");
    scanf("%d", &numero);
    system("clear");
    
    if(numero % 3 == 0 && numero % 5 == 0){
        printf("O número %d é múltiplo de 3 e 5", numero);
    }else if(numero % 5 == 0){
        printf("O número %d é múltiplo de 5", numero);
    }else if (numero % 3 == 0){
        printf("O número %d é múltiplo de 3", numero);
    }else {
        printf("O número %d não é múltiplo de 3 nem de 5", numero);
    }
    
    return 0;

}
