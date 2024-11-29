#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num1, num2 = 0;
    printf("Digite um número inteiro: \n");
    scanf("%d", &num1);
    
    printf("Digite outro número inteiro:\n");
    scanf("%d", &num2);
    system("clear");
    
    int maior = num1 > num2;
    
    if(num1 > num2){
        printf("O maior número é: %d", num1);
    }else if(num2 > num1){
        printf("O maior número é: %d", num2);
    }else {
        printf("Os números são iguais.");
    }
    
    return 0;

}
