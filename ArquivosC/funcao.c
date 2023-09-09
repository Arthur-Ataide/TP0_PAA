#include "../Include/funcao.h"


void escolha(int* continuar){
    pausar_tela();
    limpar_tela();
    
    printf("Deseja continuar? (1 - Sim / 0 - Nao): ");
    scanf("%d", continuar);

    pausar_tela();
    limpar_tela();
}


void menu(int* tipoFigura, int* quantFigura){  

    printf("\nPROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - Asterisco simples * \n");
    printf("2 - Simbolo de soma feita de asteriscos + \n");
    printf("3 - Letra X com asteriscos X \n");
    printf("4 - Figuras aleatorias \n");
    printf("5 - \033[0;35mT\033[0m\033[0;34me\033[0m\033[0;33mt\033[0m\033[0;31mr\033[0m\033[0;32mi\033[0m\033[0;36ms\033[0m\n\n");

    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", tipoFigura);

    limpar_tela();

    printf("Digite a quantidade de figuras desejada: ");
    scanf("%d", quantFigura);
    if (*quantFigura <= 0 ){
        *quantFigura = (rand()%100)+1;
    }

    else if (*quantFigura > 100){
        *quantFigura = 100;
    }

    if (*tipoFigura < 1 || *tipoFigura > 5){
        *tipoFigura = 5;
    }

}


void quadro(char matriz[][M]){
    int i, j;

    for (i = 0; i < M; i++){
        matriz[0][i] = '=';
        matriz[N-1][i] = '=';
    }

    for (i = 1; i < N-1; i++){
        matriz[i][0] = '|';
        matriz[i][M-1] = '|';
    }
    
    for (i = 1; i < N-1; i++)
        for (j = 1; j < M-1; j++)
            matriz[i][j] = ' ';

}

int tetris(char matriz[][M], int i, int j){
    int rotacao;
    int Erro = 0;
    int bloco = (rand() % 5) + 1;

    switch (bloco){
        case 1:
            rotacao = (rand() % 2 + 1);
            switch (rotacao){
                case 1:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+2][j] != ' ' || matriz[i+3][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i+3][j+1] != ' ')
                    return 0;

                    matriz[i][j] = 'A'; matriz[i+1][j] = 'A'; matriz[i+2][j] = 'A'; matriz[i+3][j] = 'A'; matriz[i][j+1] = 'A'; matriz[i+1][j+1] = 'A'; matriz[i+2][j+1] = 'A'; matriz[i+3][j+1] = 'A';
                    break;
                case 2:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i][j+2] != ' ' || matriz[i][j+3] != ' ' || matriz[i][j+4] != ' ' || matriz[i][j+5] != ' ' || matriz[i][j+6] != ' ' || matriz[i][j+7] != ' ')
                    return 0;

                    matriz[i][j] = 'A'; matriz[i][j+1] = 'A'; matriz[i][j+2] = 'A'; matriz[i][j+3] = 'A'; matriz[i][j+4] = 'A'; matriz[i][j+5] = 'A'; matriz[i][j+6] = 'A'; matriz[i][j+7] = 'A';
                    break;
                
                default:
                    break;
            }
            break;
        
        case 2:
            if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i][j+2] != ' ' || matriz[i][j+3] != ' ' || matriz[i+1][j+2] != ' ' || matriz[i+1][j+3] != ' ')
                return 0;

            matriz[i][j] = 'M'; matriz[i][j+1] = 'M'; matriz[i+1][j] = 'M'; matriz[i+1][j+1] = 'M'; matriz[i][j+2] = 'M'; matriz[i][j+3] = 'M'; matriz[i+1][j+2] = 'M'; matriz[i+1][j+3] = 'M';
            break;

        case 3:
            rotacao = (rand() % 4 + 1);
            switch (rotacao){
                case 1:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+2][j] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j+2] != ' ' || matriz[i+2][j+3] != ' ')
                        return 0;

                    matriz[i][j] = 'L'; matriz[i+1][j] = 'L'; matriz[i+2][j] = 'L'; matriz[i+2][j+1] = 'L'; matriz[i][j+1] = 'L'; matriz[i+1][j+1] = 'L'; matriz[i+2][j+2] = 'L'; matriz[i+2][j+3] = 'L';
                    break;

                case 2:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i][j+2] != ' ' || matriz[i][j+3] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i][j+4] != ' ' || matriz[i][j+5] != ' ')
                        return 0;

                    matriz[i][j] = 'L'; matriz[i+1][j] = 'L'; matriz[i][j+1] = 'L'; matriz[i][j+2] = 'L'; matriz[i][j+3] = 'L'; matriz[i+1][j+1] = 'L'; matriz[i][j+4] = 'L'; matriz[i][j+5] = 'L';
                    break;
                
                case 3:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j-1] != ' ' || matriz[i+1][j-2] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j-4] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j-3] != ' ')
                        return 0;

                    matriz[i][j] = 'L'; matriz[i+1][j] = 'L'; matriz[i+1][j-1] = 'L'; matriz[i+1][j-2] = 'L'; matriz[i][j+1] = 'L'; matriz[i+1][j-4] = 'L'; matriz[i+1][j] = 'L'; matriz[i+1][j-3] = 'L';
                    break;
                
                case 4:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+2][j] != ' ' || matriz[i][j-1] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i][j-2] != ' ')
                        return 0;

                    matriz[i][j] = 'L'; matriz[i+1][j] = 'L'; matriz[i+2][j] = 'L'; matriz[i][j-1] = 'L'; matriz[i][j+1] = 'L'; matriz[i+1][j+1] = 'L'; matriz[i+2][j+1] = 'L'; matriz[i][j-2] = 'L';
                    break;
                
                default:
                    break;
            }
            break;
        
        case 4:
            rotacao = (rand() % 2 + 1);
            switch (rotacao){
                case 1:
                    if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j+2] != ' ' || matriz[i+1][j+3] != ' ' || matriz[i+2][j+2] != ' ')
                        return 0;

                    matriz[i][j] = 'V'; matriz[i+1][j] = 'V'; matriz[i+1][j+1] = 'V'; matriz[i+2][j+2] = 'V'; matriz[i][j+1] = 'V'; matriz[i+1][j+2] = 'V'; matriz[i+1][j+3] = 'V'; matriz[i+2][j+3] = 'V';
                    break;

                case 2:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j-1] != ' ' || matriz[i][j+2] != ' ' || matriz[i][j+3] != ' ' || matriz[i+1][j-2] != ' ' || matriz[i+1][j] != ' ')
                        return 0;

                    matriz[i][j] = 'V'; matriz[i][j+1] = 'V'; matriz[i+1][j] = 'V'; matriz[i+1][j-1] = 'V'; matriz[i][j+2] = 'V'; matriz[i][j+3] = 'V'; matriz[i+1][j-2] = 'V'; matriz[i+1][j] = 'V';
                    break;

                default:
                    break;
            }
            break;
        
        case 5:
            rotacao = (rand() % 4 + 1);
            switch (rotacao){
                case 1:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i][j+2] != ' ' || matriz[i][j+3] != ' ' || matriz[i][j-2] != ' ' || matriz[i][j-1] != ' ')
                        return 0;

                    matriz[i][j] = 'R'; matriz[i][j+1] = 'R'; matriz[i+1][j] = 'R'; matriz[i][j+1] = 'R'; matriz[i][j+2] = 'R'; matriz[i][j+3] = 'R'; matriz[i][j-2] = 'R'; matriz[i][j-1] = 'R';                
                    break;
                
                case 2:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i+1][j+2] != ' ' || matriz[i+1][j+3] != ' ')
                        return 0;

                    matriz[i][j] = 'R'; matriz[i][j+1] = 'R'; matriz[i+1][j] = 'R'; matriz[i+1][j+1] = 'R'; matriz[i+2][j] = 'R'; matriz[i+2][j+1] = 'R'; matriz[i+1][j+2] = 'R'; matriz[i+1][j+3] = 'R';
                    break;

                case 3:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+1][j+2] != ' ' || matriz[i+1][j+3] != ' ' || matriz[i+1][j-1] != ' ' || matriz[i+1][j-2] != ' ')
                        return 0;
                    
                    matriz[i][j] = 'R'; matriz[i][j+1] = 'R'; matriz[i+1][j] = 'R'; matriz[i+1][j+1] = 'R'; matriz[i+1][j+2] = 'R'; matriz[i+1][j+3] = 'R'; matriz[i+1][j-1] = 'R'; matriz[i+1][j-2] = 'R';
                
                case 4:
                    if (matriz[i][j] != ' ' || matriz[i][j+1] != ' ' || matriz[i+1][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j] != ' ' || matriz[i+2][j+1] != ' ' || matriz[i+1][j-1] != ' ' || matriz[i+1][j-2] != ' ')
                        return 0;
                    
                    matriz[i][j] = 'R'; matriz[i][j+1] = 'R'; matriz[i+1][j] = 'R'; matriz[i+1][j+1] = 'R'; matriz[i+2][j] = 'R'; matriz[i+2][j+1] = 'R'; matriz[i+1][j-1] = 'R'; matriz[i+1][j-2] = 'R';
                
                default:
                    break;
            }
            break;

        default:
            break;

    
            return 1;

    }
}


int figuras(char matriz[][M],int i,int j, int tipoFigura){
    int Erro = 0;
    int c;

    if(tipoFigura == 4)
        tipoFigura = (rand() % 3 + 1);

    switch (tipoFigura){
        case 1:
            if (matriz[i][j] == ' '){
                    matriz[i][j] = '*';
                    
                }
            else return 0;

            break;

        case 2:

            if (matriz[i][j] != ' ' || matriz[i+1][j] != ' ' || matriz[i+2][j] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+1][j-1] != ' ')
                    return 0;
                
            matriz[i][j] = '*'; matriz[i+1][j] = '*'; matriz[i+2][j] = '*'; matriz[i+1][j+1] = '*'; matriz[i+1][j-1] = '*';
            
            break;

        case 3:
            if (matriz[i][j] != ' ' || matriz[i+2][j] != ' ' || matriz[i][j+2] != ' ' || matriz[i+1][j+1] != ' ' || matriz[i+2][j+2] != ' '){
                return 0;
            }

            matriz[i][j] = '*';  matriz[i+2][j] = '*';  matriz[i][j+2] = '*';  matriz[i+1][j+1] = '*';  matriz[i+2][j+2] = '*';
            break;
                    
        case 5:
            if (j % 2 != 0)
                return tetris(matriz, i, j);
            else
                return 0;
            break;
        
        default:
            break;
    }
    return 1;
}

void randomizar(char matriz[][M], int quantFigura, int tipoFigura){
    int i, j, cont, linha, coluna;
    
    cont = 0;
        
        while (cont < quantFigura){
            linha = (rand() % N-2) + 1;
            coluna = (rand() % M-2) + 1;
            if (figuras(matriz, linha, coluna, tipoFigura)){
                cont++;

            }
        } 
    printf("\nA quantidade de figuras a ser gerada foi %d\n", quantFigura);
}

void print_matriz(char matriz[][M], int tipoFigura){
    int i, j;

    printf("\nA figura gerada foi: \n\n");

    switch (tipoFigura){
    case 1:
        printf("Asterisco simples * \n");
        break;
    
    case 2:
        printf("Simbolo de soma feita de asteriscos + \n");
        break;

    case 3:
        printf("Letra X com asteriscos X \n");
        break;

    case 4:
        printf("Figuras aleatorias \n");

    case 5:
        printf("\033[0;35mT\033[0m\033[0;34me\033[0m\033[0;33mt\033[0m\033[0;31mr\033[0m\033[0;32mi\033[0m\033[0;36ms\033[0m\n\n");
        break;

    default:
        break;
    }

    printf("\n");
    
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            if (matriz[i][j] == 'A'){
                printf("\033[0;34m[\033[0m"); // Azul
                printf("\033[0;34m]\033[0m"); // Azul
                j++;
            }

            else if (matriz[i][j] == 'M'){
                printf("\033[0;33m[\033[0m"); // Amarelo
                printf("\033[0;33m]\033[0m"); // Amarelo
                j++;
            }
            
            else if (matriz[i][j] == 'L'){
                printf("\033[0;31m[\033[0m"); // Laranja
                printf("\033[0;31m]\033[0m"); // Laranja
                j++;
            }
            
            else if (matriz[i][j] == 'V'){
                printf("\033[0;32m[\033[0m"); // Verde
                printf("\033[0;32m]\033[0m"); // Verde
                j++;
            }
            
            else if (matriz[i][j] == 'R'){
                printf("\033[0;35m[\033[0m"); // Rosa
                printf("\033[0;35m]\033[0m"); // Rosa
                j++;
            }

            else
                printf("%c", matriz[i][j]);
        }

        printf("\n");
    }
    
    printf("\n");
}