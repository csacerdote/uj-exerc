#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota1, nota2, nota3 = 0;
    printf("Digite sua primeira nota: \n");
    scanf("%d", &nota1);
    
    printf("Digite sua segunda nota: \n");
    scanf("%d", &nota2);
    
    printf("Digite sua terceira nota: \n");
    scanf("%d", &nota3);
    system("clear");
    
    int media = 0;
    media = (nota1 + nota2 + nota3) / 3;
    
    printf("Sua media é: %d. ", media);
    printf("Logo, ");
    
    if(media >=6){
        printf("você esta aprovado!");
    }else if(media >=4 && media <6){
        printf("você tem direito a recuperação!");
    }else {
        printf("você esta reprovado");
    }

    return 0;
}
