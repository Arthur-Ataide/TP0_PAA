#include "./Include/funcao.h"

int main(){
    
    int tipoFigura;
    int quantFigura;
    char matriz[N][M];
    int continuar = 1;

    while (continuar)
    {
        menu1(&tipoFigura, &quantFigura);
        quadro(matriz);

        random(matriz, quantFigura, tipoFigura);

        print_matriz(matriz, tipoFigura);

        pausar_tela();
        limpar_tela();
    }
}