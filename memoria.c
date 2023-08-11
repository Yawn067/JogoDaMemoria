#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(int argc, char * argv[]){
    bool fimjogo = false;
    int i=0, j=0, l1=0, c1=0, l2=0, c2=0, aux=0, jogador1=0, jogador2=0;
    char gabarito[6][6] ={
    {'a', 'a', 'b', 'b', 'c', 'c'},
    {'d', 'd', 'e', 'e', 'f', 'f'},
    {'g', 'g', 'h', 'h', 'i', 'i'},
    {'j', 'j', 'k', 'k', 'l', 'l'},
    {'m', 'm', 'n', 'n', 'o', 'o'},
    {'p', 'p', 'q', 'q', 'r', 'r'}};
    char visual[6][6] ={
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' '}};
    srand(time(NULL));

    //embaralhar
    for(i=0;i<70;i++){
        l1 = rand() % 6;
        c2 = rand() % 6;
        l2 = rand() % 6;
        c2 = rand() % 6;
        aux = gabarito[l2][c2];
        gabarito[l2][c2] = gabarito[l1][c1];
        gabarito[l1][c1] = aux;
    }

    while(fimjogo==false){
    //jogador 1
        //impressao
        printf("   0  1  2  3  4  5   \n");
        for(i=0;i<6;i++){
            printf("%d ", i);
            for(j=0;j<6;j++){
                printf("[%c]", visual[i][j]);
            }
            printf("\n");
        }
        printf("Jogador 1 = %d  /  Jogador 2 = %d\n", jogador1, jogador2);
        printf("(Jogador 1)[linha1 coluna1 linha2 coluna2]: ");
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);

        //verificação se ha coordenada invalida ou repitida
        if((l1<0)||(c1<0)||(l2<0)||(c2<0)||(l1>6)||(c1>6)||(l2>6)||(c2>6)||((l1==l2)&&(c1==c2))){
            printf("Coordenadas invalidas!\n");
            //verificação se a coordenada ja foi aberta
        }
            else{
                if((visual[l1][c1]!=' ')||(visual[l2][c2]!=' ')){
                printf("Essa coordenada ja foi aberta!\n");
            }
                else{
                //mostrar na tela as letras das coordenadas digitadas
                    printf("   0  1  2  3  4  5   \n");
                    for(i=0;i<6;i++){
                        printf("%d ", i);
                        for(j=0;j<6;j++){
                            if(((i==l1)&&(j==c1))||((i==l2)&&(j==c2))){
                                printf("[%c]", gabarito[i][j]);
                            }
                            else{
                                printf("[%c]", visual[i][j]);
                            }
                        }
                        printf("\n");
                    }
                 //verificar se as letras são iguais ou não
                    if(gabarito[l1][c1]==gabarito[l2][c2]){
                        visual[l1][c1] = gabarito[l1][c1];
                        visual[l2][c2] = gabarito[l2][c2];
                        printf("IGUAIS\n");
                        jogador1 = jogador1 + 2;
                    }
                    else{printf("DIFERENTES\n");}
                }
            }

    //jogador 2
        //impressao
        printf("   0  1  2  3  4  5   \n");
        for(i=0;i<6;i++){
            printf("%d ", i);
            for(j=0;j<6;j++){
                printf("[%c]", visual[i][j]);
            }
            printf("\n");
        }
        printf("Jogador 1 = %d  /  Jogador 2 = %d\n", jogador1, jogador2);
        printf("(Jogador 2)[linha1 coluna1 linha2 coluna2]: ");
        scanf("%d %d %d %d", &l1, &c1, &l2, &c2);

        //verificação se ha coordenada invalida ou repitida
        if((l1<0)||(c1<0)||(l2<0)||(c2<0)||(l1>6)||(c1>6)||(l2>6)||(c2>6)||((l1==l2)&&(c1==c2))){
            printf("Coordenadas invalidas!\n");
            //verificação se a coordenada ja foi aberta
        }
            else{
                if((visual[l1][c1]!=' ')||(visual[l2][c2]!=' ')){
                printf("Essa coordenada ja foi aberta!\n");
            }
                else{
                //mostrar na tela as letras das coordenadas digitadas
                    printf("   0  1  2  3  4  5   \n");
                    for(i=0;i<6;i++){
                        printf("%d ", i);
                        for(j=0;j<6;j++){
                            if(((i==l1)&&(j==c1))||((i==l2)&&(j==c2))){
                                printf("[%c]", gabarito[i][j]);
                            }
                            else{
                                printf("[%c]", visual[i][j]);
                            }
                        }
                        printf("\n");
                    }
                 //verificar se as letras são iguais ou não
                    if(gabarito[l1][c1]==gabarito[l2][c2]){
                        visual[l1][c1] = gabarito[l1][c1];
                        visual[l2][c2] = gabarito[l2][c2];
                        printf("IGUAIS\n");
                        jogador2 = jogador2 + 2;
                        if((jogador1 + jogador2)==36){
                            printf("\n");
                            printf("Fim de jogo\n");
                           if(jogador1 > jogador2){
                                printf("JOGADOR 1 VENCEU!!!");
                           }
                           else{
                               printf("JOGADOR 2 VENCEU!!!");
                           }
                           fimjogo = true;
                         }
                    }
                    else{printf("DIFERENTES\n");}
                }
            }
    //Fim do jogo
        if((jogador1 + jogador2)==36){
            printf("\n");
            printf("Fim de jogo\n");
            if(jogador1 > jogador2){
                printf("JOGADOR 1 VENCEU!!!");
            }
            else{
                printf("JOGADOR 2 VENCEU!!!");
            }
            fimjogo = true;
        }
    }
    return 0;
}









