#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num = 0;
    printf("Digite um número inteiro: \n");
    scanf("%d", &num);
    system("clear");
    
    if(num % 2 == 0){
        printf("Número par");
    }else{
        printf("Número impar");
    }
    
    return 0;

}
