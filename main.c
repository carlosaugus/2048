#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

// Linha | Coluna
int jogo2048[4][4], inicio = 0;
int score;

int main(){
	char tecla;
	do{
		limpaArray();
		telaInicial();
		score = 0;
		tecla = getch();
		if(tecla == 13){
			jogada(1);
			do{
				tecla = getch();
				
				switch (tecla) {
				case 75: //Seta para esquerda
					jogada(esquerdaNumeros());
					break;
				case 72: //Seta para cima
					jogada(sobeNumeros());
					break;
				case 77: //Seta para direita
					jogada(direitaNumeros());
					break;
				case 80: //Seta para baixo
					jogada(desceNumeros());
					break;
				}	
			}while(tecla != 114); // Sai se apertar a tecla R ou se resultado for Game Over	
		}
	}while(tecla != 27); // Sai se apertar a tecla ESC
	
	return 0;
	//system("pause");
}

void telaInicial() {
	system("cls");
	printf("\t_________________________________________________________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t_______________________                    ______________________\n");
	printf("\t_______________________        2048        ______________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t_________________________________________________________________\n");
	printf("\t______________________<ESC> PARA SAIR DO JOGO____________________\n");
	printf("\t____________________<ENTER> PARA INICIAR O JOGO__________________\n");
}

int desceNumeros(){
	int c, l, jogada = 0;
	for(c = 0; c < 4; c++){ // Coluna
		for(l = 3; l >= 1; l--){ // Linha
			if(jogo2048[l][c] == 0 && jogo2048[l-1][c] > 0){
				jogo2048[l][c] = jogo2048[l-1][c];
				jogo2048[l-1][c] = 0;
				l = 4;
				jogada = 1;
			}
		}
		
		for(l = 3; l >= 1; l--){
			if(jogo2048[l][c] == jogo2048[l-1][c]){
				jogo2048[l][c] += jogo2048[l-1][c];
				jogo2048[l-1][c] = 0;
				score += jogo2048[l][c];
			}
		}
		
		for(l = 3; l >= 1; l--){
			if(jogo2048[l][c] == 0 && jogo2048[l-1][c] > 0){
				jogo2048[l][c] = jogo2048[l-1][c];
				jogo2048[l-1][c] = 0;
				l = 4;
				jogada = 1;
			}
		}
	}
	return jogada;
}

int sobeNumeros(){
	int c, l, jogada = 0;
	for(c = 0; c < 4; c++){ // Coluna
		for(l = 0; l < 3; l++){ // Linha
			if(jogo2048[l][c] == 0 && jogo2048[l+1][c] > 0){
				jogo2048[l][c] = jogo2048[l+1][c];
				jogo2048[l+1][c] = 0;
				l = -1;
				jogada = 1;
			}
		}
		
		for(l = 0; l < 3; l++){
			if(jogo2048[l][c] == jogo2048[l+1][c]){
				jogo2048[l][c] += jogo2048[l+1][c];
				jogo2048[l+1][c] = 0;
				score += jogo2048[l][c];
			}
		}
		
		for(l = 0; l < 3; l++){
			if(jogo2048[l][c] == 0 && jogo2048[l+1][c] > 0){
				jogo2048[l][c] = jogo2048[l+1][c];
				jogo2048[l+1][c] = 0;
				l = -1;
				jogada = 1;
			}
		}
	}
	return jogada;
}

int esquerdaNumeros(){
	int c, l, jogada = 0;
	for(l = 0; l < 4; l++){ // Coluna
		for(c = 0; c < 3; c++){ // Linha
			if(jogo2048[l][c] == 0 && jogo2048[l][c+1] > 0){
				jogo2048[l][c] = jogo2048[l][c+1];
				jogo2048[l][c+1] = 0;
				c = -1;
				jogada = 1;
			}
		}
		
		for(c = 0; c < 3; c++){
			if(jogo2048[l][c] == jogo2048[l][c+1]){
				jogo2048[l][c] += jogo2048[l][c+1];
				jogo2048[l][c+1] = 0;
				score += jogo2048[l][c];
			}
		}
		
		for(c = 0; c < 3; c++){
			if(jogo2048[l][c] == 0 && jogo2048[l][c+1] > 0){
				jogo2048[l][c] = jogo2048[l][c+1];
				jogo2048[l][c+1] = 0;
				c = -1;
				jogada = 1;
			}
		}
	}
	return jogada;
}

int direitaNumeros(){
	int c, l, jogada = 0;
	for(l = 0; l < 4; l++){ // Coluna
		for(c = 3; c >= 1; c--){ // Linha
			if(jogo2048[l][c] == 0 && jogo2048[l][c-1] > 0){
				jogo2048[l][c] = jogo2048[l][c-1];
				jogo2048[l][c-1] = 0;
				c = 4;
				jogada = 1;
			}
		}
		
		for(c = 3; c >= 1; c--){
			if(jogo2048[l][c] == jogo2048[l][c-1]){
				jogo2048[l][c] += jogo2048[l][c-1];
				jogo2048[l][c-1] = 0;
				score += jogo2048[l][c];
			}
		}
		
		for(c = 3; c >= 1; c--){
			if(jogo2048[l][c] == 0 && jogo2048[l][c-1] > 0){
				jogo2048[l][c] = jogo2048[l][c-1];
				jogo2048[l][c-1] = 0;
				c = 4;
				jogada = 1;
			}
		}
	}
	return jogada;
}

int verificarJogadas(){
	int c, l;

	for(c = 0; c < 4; c++){
		for(l = 0; l < 4; l++){
			if (jogo2048[l][c] == 0) {
				return 1;
			}
		}
		for(l = 3; l >= 1; l--){
			if(jogo2048[l][c] == jogo2048[l-1][c] || jogo2048[l][c] == jogo2048[l][c-1]){
				return 1;
			}
		}
		for(l = 0; l < 3; l++){
			if(jogo2048[l][c] == jogo2048[l+1][c] || jogo2048[l][c] == jogo2048[l][c+1]){
				return 1;
			}
		}
	}
	return 0;
}

void desenha(int status){	
	int i, y, z;

	system("cls");
	if(status == 0 && verificarJogadas() == 0){
		printf("\tGAME OVER - SCORE: %d\n", score);
	} else {
		printf("\tSCORE: %d\n", score);
	}
	for(i = 0; i < 4; i++){
	  printf("\t-----------------------------------------------------------------\n");
	  printf("\t|");
		for(y = 0; y < 4; y++){
			if(jogo2048[i][y] == 0)
				printf("\t \t|");
			else
				printf("\t%d\t|", jogo2048[i][y]);
		}
		printf("\n\t-----------------------------------------------------------------\n");
	}
	printf("\tUSE AS SETAS DO TECLADO                 <R> PARA REINICIAR O JOGO\n");
}

void jogada(int status) {
	int i = 0, y = 0, cont = 0;

	for (i = 0; i < 4; i++) {
		for (y = 0; y < 4; y++) {
			if (jogo2048[i][y] == 0) {
				cont++;
			}
		}
	}

	if(status != 0){
		preencheCampoComDois(cont);
		desenha(1);
	} else {
		if(verificarJogadas() == 1){
			desenha(1);
		} else {
			desenha(0);
		}
	}
}

void preencheCampoComDois(int cont){
	int i, y, auxCont;
	
	srand(time(NULL));
		auxCont = rand() % cont;
		cont = 0;
	
		for (i = 0; i < 4; i++) {
			for (y = 0; y < 4; y++) {
				if (jogo2048[i][y] == 0) {
					if (cont == auxCont) {
						jogo2048[i][y] = 2;
					}
					cont++;
				}
			}
		}
}

void limpaArray(){
	int i, y, cont = 2;
	for (i = 0; i < 4; i++) {
		for (y = 0; y < 4; y++) {
			jogo2048[i][y] = 0;
		}
	}
}
