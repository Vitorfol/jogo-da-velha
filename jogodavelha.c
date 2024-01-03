#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char mat[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
char vetor[3];
int i, j;

void jogo();
int parada();
int vencedor();

int main(){
	setlocale(LC_ALL, "Portuguese");
    int jogador = 1, linha, coluna, auxiliar;
    jogo();
    printf("O jogo da velha vai comecar!\n");
    
    int jogada = 0;
    while (1) {
                if (jogador%2 == 1) {
        jogador = 1;
    }
    else {
        jogador = 2;
    }
        printf("É a vez do jogador %d\n", jogador);
        printf("Onde você vai jogar?\n");
        printf("OBS: se tentar enrolar vai perder a vez\n");
        scanf("%d",&linha);
        scanf("%d", &coluna);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (jogador == 1) {
                	if (mat[linha-1][coluna-1] == '-') {
                    mat[linha-1][coluna-1] = 'O';
                    jogada++;
                    }
                }
                else {
                	if (mat[linha-1][coluna-1] == '-') {	
                    mat[linha-1][coluna-1] = 'X';
                    jogada++;
                    }
                }
            }
        }
    jogo();
    auxiliar = parada();
    if (auxiliar == 1) {
    	printf("\n\tO jogador %d venceu", jogador);
    	break;
	}
    jogador++;
    if (jogada > 8) {
    	printf("\tV E L H A !\n");
    	break;
	}
    }
    return 0;
}

void jogo(){
	system("cls");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
           printf("\t%c", mat[i][j]);
        }
        printf("\t\n");
    }
}

int vencedor() {
	if (vetor[0] == vetor[1] && vetor [1] == vetor[2] && vetor[0] != '-') {
		return 1;
	}
	return 0;
}


int parada() {
	int ajuda[8];
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			vetor[j] = mat[i][j];
		}
		ajuda[i] = vencedor();
	}
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			vetor[j] = mat[j][i];
		}
		ajuda[i+3] = vencedor();
	}
	
	for (i = 0; i < 3; i++) {
		vetor[i] = mat[i][i];
	}
	ajuda[6] = vencedor();

    for (i = 0; i < 3; i++) {
        vetor[i] = mat[i][2 - i];
    }
    ajuda[7] = vencedor();

	int p; 
	for (p = 0; p < 8; p++) {
		if (ajuda[p] != 0) {
			return 1;
			break;
		}
	}
	return 0;
}