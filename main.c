#include "./Include/funcao.h"

int main(){
    
    int tipoFigura;
    int quantFigura;
    char matriz[N][M];
    int continuar = 1;

    while (continuar)
    {
        menu(&tipoFigura, &quantFigura);
        quadro(matriz);

        randomizar(matriz, quantFigura, tipoFigura);

        print_matriz(matriz, tipoFigura);

        pausar_tela();
        limpar_tela();
    }
}