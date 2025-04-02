#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char caminho[9][4];
char j[3][3];
char jogador1[20], jogador2[20];
char simb = 'O';
int nj = 0, j1 = 0, j2 = 0, emp = 0, op = 0, lin = 0, col = 0;
_Bool enc = false;

void inicializar() {
  for (int id = 0; id < 9; id++) {
    caminho[id][0] = '\0';
  }
  for (int lin = 0; lin < 3; lin++) {
    for (int col = 0; col < 3; col++) {
      j[lin][col] = ' ';
    }
  }
  nj = 0;
  enc = false;
}

char simbolo() {
  if (simb == 'O') {
    simb = 'X';
  } else {
    simb = 'O';
  }
  nj++;
  return simb;
}

void menu() {
  system("clear");
  printf("***************************\n");
  printf("*       GAME VELHA        *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   1 - INICIAR           *\n");
  printf("*   2 - ESTATISTICA       *\n");
  printf("*   3 - SAIR              *\n");
  printf("*                         *\n");
  printf("***************************\n\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void game() {
  system("clear");
  printf("    0        1       2   \n");
  printf("         *       *       \n");
  printf("0    %c   *   %c   *   %c   \n", j[0][0], j[0][1], j[0][2]);
  printf("         *       *       \n");
  printf(" * * * * * * * * * * * * * \n");
  printf("         *       *       \n");
  printf("1    %c   *   %c   *   %c   \n", j[1][0], j[1][1], j[1][2]);
  printf("         *       *       \n");
  printf(" * * * * * * * * * * * * *\n");
  printf("         *       *       \n");
  printf("2    %c   *   %c   *   %c   \n", j[2][0], j[2][1], j[2][2]);
  printf("         *       *       \n\n");
}

void estatistica() {
  system("clear");
  printf("***************************\n");
  printf("*       ESTATISTICA       *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   %s = %i                 *\n", jogador1, j1);
  printf("*   %s = %i                 *\n", jogador2, j2);
  printf("*   Empate = %i            *\n", emp);
  printf("*                         *\n");
  printf("***************************\n");
  sleep(5);
}

_Bool verificarjogada(int l, int c) { 
  return j[l][c] == ' '; 
}

void armazenar(int l, int c) {
  char temp[2] = {j[l][c], '\0'};
  if (l == 0 && c == 0) {
    strcat(caminho[1], temp);
    strcat(caminho[6], temp);
    strcat(caminho[8], temp);
  } else if (l == 0 && c == 1) {
    strcat(caminho[1], temp);
    strcat(caminho[5], temp);
  } else if (l == 0 && c == 2) {
    strcat(caminho[1], temp);
    strcat(caminho[4], temp);
    strcat(caminho[7], temp);
  } else if (l == 1 && c == 0) {
    strcat(caminho[2], temp);
    strcat(caminho[6], temp);
  } else if (l == 1 && c == 1) {
    strcat(caminho[2], temp);
    strcat(caminho[5], temp);
    strcat(caminho[7], temp);
    strcat(caminho[8], temp);
  } else if (l == 1 && c == 2) {
    strcat(caminho[2], temp);
    strcat(caminho[4], temp);
  } else if (l == 2 && c == 0) {
    strcat(caminho[3], temp);
    strcat(caminho[6], temp);
    strcat(caminho[7], temp);
  } else if (l == 2 && c == 1) {
    strcat(caminho[3], temp);
    strcat(caminho[5], temp);
  } else if (l == 2 && c == 2) {
    strcat(caminho[3], temp);
    strcat(caminho[4], temp);
    strcat(caminho[8], temp);
  }
}

_Bool verificarvitoria() {
  _Bool ver = false;
  if (nj >= 5) {
    for (int x = 1; x < 9; x++) {
      if (strlen(caminho[x]) == 3) {
        if (strcmp(caminho[x], "XXX") == 0) {
          ver = true;
          j1++;
          system("clear");
          printf("Parabéns %s, você venceu!\n", jogador1);
          estatistica();
        } else if (strcmp(caminho[x], "OOO") == 0) {
          ver = true;
          j2++;
          system("clear");
          printf("Parabéns %s, você venceu!\n", jogador2);
          estatistica();
        }
      }
    }
    if (!ver && nj == 9) {
      emp++;
      printf("Deu velha!!!\n");
      sleep(2);
      system("clear");
      estatistica();
    }
  }
  return ver;
}

int main() {

  do {
    menu();
    scanf("%d", &op);
    switch (op) {
    case 1: {
      inicializar();
      system("clear");

      printf("Nome do Jogador 1 (X): ");
      scanf("%s", jogador1);
      printf("Nome do Jogador 2 (O): ");
      scanf("%s", jogador2);

      do {
        game();
        do {
          printf("Digite a linha entre 0-2: ");
          scanf("%d", &lin);
        } while (lin < 0 || lin > 2);

        do {
          printf("Digite a coluna entre 0-2: ");
          scanf("%d", &col);
        } while (col < 0 || col > 2);

        if (verificarjogada(lin, col)) {
          j[lin][col] = simbolo();
          armazenar(lin, col);
          enc = verificarvitoria();
        } else {
          printf("Jogada invalida\n");
          sleep(2);
        }
      } while (!enc && nj < 9);
      break;
    }
    case 2: {
      estatistica();
      break;
    }
    default: {
      if (op > 3 || op < 1) {
        printf("Opcao invalida!\n");
        sleep(2);
      }
      break;
    }
    }
  } while (op != 3);

  system("clear");
  printf("Sistema finalizado com sucesso!\n");
  return 0;
}
