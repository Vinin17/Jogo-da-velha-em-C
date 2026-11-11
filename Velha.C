#include <stdio.h>
#include <stdlib.h>
int tabuleiro[3][3];
int jogadorAtual;
void iniciartabuleiro(){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tabuleiro[i][j] = 0;
        }
    }
}
void exibirtabuleiro(){
    int i,j;
    printf("   |  1  |  2  |  3  |\n");
    printf("----------------------\n");
    for(i=0; i<3; i++){
        printf(" %d |", i+1);
        for(j=0; j<3; j++){
            if(tabuleiro[i][j]==0){
                printf("     |");
            }
            if(tabuleiro[i][j]==2){
                printf("  0  |");
            }
            if(tabuleiro[i][j]==1){
                printf("  x  |");
            }
           // printf(" %d |", tabuleiro[i][j]);            
        }        
        printf("\n----------------------\n");
    }
}
int validarJogada(int x, int y){
    if((x>=0 && x<3) && (y>=0 && y<3) && tabuleiro[x][y]==0){
        return 1;
    }
    return 0;
}
void recebejogada(){
    int x, y, valido;
    valido = 0;
    while (valido == 0){
        printf("jogador %d\n", jogadorAtual);
        printf("digite x: ");
        scanf("%d", &x);
        x--;
        printf("digite y: ");
        scanf("%d", &y);
        y--;
        valido = validarJogada(x, y);
        if(valido){
            tabuleiro[x][y] = jogadorAtual;
        }else{
            printf("jogada invalida! \n");
        }
    }
   
   
}
void trocaJogador(){
    if(jogadorAtual == 1){
        jogadorAtual = 2;
    }else{
        jogadorAtual = 1;
    }
}
void vitoria(){
    printf("###################");
    printf("\n jogador %d ganhou! \n", jogadorAtual);
    printf("###################");
}
int verificaVitoria(){
    int i,j,pontos;
    for(i=0; i<3;i++){
        pontos=0;
        for(j=0; j<3;j++){
            if(tabuleiro[i][j]==jogadorAtual){
                pontos++;
            }
        }
        if(pontos==3){
            vitoria();
            return 0;
        }
    }
    // Verificando colunas
    for(j = 0; j < 3; j++){
        pontos = 0;

    for(i = 0; i < 3; i++){
        if(tabuleiro[i][j] == jogadorAtual){
            pontos++;
        }
    }

    if(pontos == 3){
        vitoria();
        return 0;
    }
}
    //diagonal principal
    pontos =0;
    for(i=0;i<3;i++){
        if(tabuleiro[i][i] == jogadorAtual){
            pontos++;
        }
    }
    if(pontos == 3){
        vitoria();
        return 0;
    }
    //diagonal secundaria
    pontos = 0;
    i = 0;
    j = 2;
    while(i<3 && j>=0){
        if(tabuleiro[i][j] == jogadorAtual){
            pontos++;
        }
        i++;
        j--;
    }
    if(pontos == 3){
        vitoria();
        return 0;
    }
    return 1;
}
void empate(){
    printf("#######");
    printf("Empatou");
    printf("#######");
}
int main() {
    system("cls");
    //iniciando jogo
    iniciartabuleiro();
    jogadorAtual = 1;
   
    //jogando
    int jogadas = 1, jogando = 1;
    while(jogando){
        system("cls");
        exibirtabuleiro();
        recebejogada();
        system("cls");
        exibirtabuleiro();
        if(jogadas >= 5){
            printf("Verificando...\n");
            jogando = verificaVitoria();
            if(jogando==0){
                break;
            }   
        }
        if (jogadas == 9){
            empate();
            jogando = 0;
            break;
        }
        trocaJogador();
        jogadas++;
    }
   
    return 0;
}

