#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
//Grupo: Pedro Henrique de Holanda Lousada, Roger Daiki Hata Sakai, Luiz Henrique Nogueira dos Santos.
//https://drive.google.com/drive/folders/1bzQIhDI06tO37E4s9XpmIY9feluXLC_2?usp=sharing
bool win_condition(char v[3][3]){
	char u;
	int aux=0;
	int counter=0;
	u=v[0][0];
	while(1){
		for(int i=0;i<3;i++){                                   //Check de vitória na horizontal
			u=v[i][aux];
			for(int w=0;w<3;w++){
				if(u==v[i][w] && v[i][aux]!=' '){
					counter++;
				}
			}
			if(counter==3){
				printf("O %c venceu!\n", v[i][aux]);
				return true;
			}
			else{
				counter=0;
			}
		}
		aux=0;
		for(int i=0;i<3;i++){									//Check de vitória na vertical
			u=v[aux][i];
			for(int w=0;w<3;w++){
				if(u==v[w][i] && v[aux][i]!=' '){
					counter++;
				}
			}
			if(counter==3){
				printf("O %c venceu!\n", v[aux][i]);
				return true;
			}
			else{
				counter=0;
			}
		}
		aux=0;
		char matrixline[9];										//Matrixline é um truque que serve para transformar a matriz numa linha (O nome é bem sugestivo), decidimos fazer isso pois achamos mais fácil trabalhar com um vetor do que com uma matriz	
		for(int i=0;i<3;i++){									//Esse é o check de vitória na diagonal começando do primeiro elemento da primeiro linha.
			for(int w=0;w<3;w++){
				matrixline[aux]=v[i][w];
				aux++;
			}
		}
		aux=0;
		u=matrixline[aux];
		for(int i=0;i<9;i=i+4){											
			if(u==matrixline[i] && matrixline[i]!=' '){
				counter++;
			}
		}
		if(counter==3){
			printf("O %c venceu!\n", u);
			return true;
		}
		else{
			counter=0;
		}
		aux=2;
		u=matrixline[aux];
		counter=0;
		for(int i=4;i<9;i=i+2){								//Esse é o check de vitória na diagonal começando do terceiro elemento da primeira linha.
			if(u==matrixline[i] && matrixline[i]!=' '){
				counter++;
			}
		}
		if(counter==2){
			printf("O %c venceu!\n", u);
			return true;
		}
		break;
	}
	return false;
}

int main(){
	char matriz[3][3];
	int velhacounter=0;
	int comando1;											
	int turnoX=1;
	int linhaX, colunaX;
	int linhaO, colunaO;
	int turnoO=0;
	while(1){
	for(int i=0;i<3;i++){                                              // A matriz é inicializada no começo do programa (E após cada partida).
    			for(int n=0;n<3;n++){
    				matriz[i][n]=' ';
    			}
    		}
	printf(">>> JOGO DA VELHA DOS CAMPEOES <<<\n");
	printf("Menu:\n");
	printf("1 - Iniciar Partida\n");
	printf("2 - Ajuda\n");
	printf("3 - Encerrar o jogo\n");
	fflush(stdin);
    scanf("%d", &comando1);
    if(comando1==1){
    	while(1){
    	if(turnoX>0){
    		for(int i=0;i<3;i++){
    			printf("|");
    			for(int n=0;n<3;n++){
    				printf("| %c |", matriz[i][n]);
    			}
    			printf("|\n");
    		}
    		printf("Turno do X!\n");
    		printf("Escolha uma linha da matriz:\n");
    		fflush(stdin);											//Limpa o buffer do teclado para receber um comando.
    		scanf("%d", &linhaX);
    		printf("Escolha uma coluna da matriz:\n");
    		scanf("%d", &colunaX);
    		if((linhaX>3 || linhaX<1) || (colunaX>3 || colunaX<1)){
    			printf("ERRO: Valores invalidos! Tente novamente!\n");
    			continue;
    		}
    		if(matriz[linhaX-1][colunaX-1] == 'X' || matriz[linhaX-1][colunaX-1] == 'O' ){
    			printf("ERRO: O local selecionado ja foi ocupado!\n");
    			continue;
    		}
    		matriz[linhaX-1][colunaX-1]='X';
    		turnoX--;
    		turnoO++;
    	}
    	if(win_condition(matriz)){															// Checa se o jogador X venceu a partida.
    		for(int i=0;i<3;i++){
    			printf("|");
    			for(int n=0;n<3;n++){
    				printf("| %c |", matriz[i][n]);
    			}
    			printf("|\n");
    		}
    		break;
    	}
    	if(velhacounter==4){																//Check de Velha (Sugestivamente apelidado de velhacounter)
    		for(int i=0;i<3;i++){
    			printf("|");
    			for(int n=0;n<3;n++){
    				printf("| %c |", matriz[i][n]);
    			}
    			printf("|\n");
    		}
    		printf("Deu velha!\n");
    		break;
    	}
    	if(turnoO>0){
    		for(int i=0;i<3;i++){
    			printf("|");
    			for(int n=0;n<3;n++){
    				printf("| %c |", matriz[i][n]);
    			}
    			printf("|\n");
    		}
    		printf("Turno do O!\n");
    		printf("Escolha uma linha da matriz:\n");
    		fflush(stdin);
    		scanf("%d", &linhaO);
    		printf("Escolha uma coluna da matriz:\n");
    		scanf("%d", &colunaO);
    		if((linhaO>3 || linhaO<1) || (colunaO>3 || colunaO<1)){
    			printf("ERRO: Valores invalidos! Tente novamente!\n");
    			continue;
    		}
    		if(matriz[linhaO-1][colunaO-1] == 'X' || matriz[linhaO-1][colunaO-1] == 'O' ){
    			printf("ERRO: O local selecionado ja foi ocupado!\n");
    			continue;
    		}
    		matriz[linhaO-1][colunaO-1]='O';
    		turnoO--;
    		turnoX++;
    	}
    	if(win_condition(matriz)){ 																// Checa se o jogador O venceu a partida.
    		for(int i=0;i<3;i++){
    			printf("|");
    			for(int n=0;n<3;n++){
    				printf("| %c |", matriz[i][n]);
    			}
    			printf("|\n");
    		}
    		break;
    	}
    	velhacounter++;
    }
    }
    if(comando1==2){
    	printf("Noughts and Crosses eh um jogo antigo que tem sido jogado na Gra-Bretanha ha seculos. Este jogo enganosamente simples tambem eh chamado de Tic-Tac Toe (as vezes escrito Tick Tack Toe) na America e em outras partes do mundo. As origens precisas de Zeros e Cruzes são desconhecidas, mas ha evidencias de que o jogo de Zeros e Cruzes foi realmente jogado pelos antigos egipcios por volta de 1300 aC.\n");
    	printf("Cada jogador deve escolher uma posicao do tabuleiro. O jogador que alinhar uma sequencia de simbolos vence.\n");
    }

    if(comando1==3){
    	printf("Adeus!\n");
    	return 0;
    }
    velhacounter=0;
    turnoO=0;
    turnoX=1;
    continue;	
}
}
