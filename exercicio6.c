#include <stdio.h>

int main()
{
    
    int nota;
    printf("Digite sua nota: \n");
    scanf("%d", &nota);
    
    switch (nota) {
        case 9 ... 10:
            printf("Você tirou um A.\n");
            break;
        case 7 ... 8:
            printf("Você tirou um B.\n");
            break;
        case 5 ... 6:
            printf("Você tirou um C.\n");
            break;
        case 3 ... 4:
            printf("Você tirou um D.\n");
            break;
       case 0 ... 2:
            printf("Você tirou um E.");
            break;
        
        default:
            printf("Nota inválida.\n");
            break;
    }
    
    return 0;

}


