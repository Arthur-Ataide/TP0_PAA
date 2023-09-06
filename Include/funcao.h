#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define M 80
#define N 20

#if defined(__MINGW32__) || defined(_MSC_VER)
#define limpar_input() fflush(stdin)
#define limpar_tela() system("cls")
#define pausar_tela() system("pause")
#else
#include <stdio_ext.h>
#define limpar_input() __fpurge(stdin)
#define limpar_tela() system("clear")
#define pausar_tela() printf("\nPress any key to continue..."); limpar_input(); getchar();
#endif


void menu1(int* tipoFigura, int* quantFigura);
int tetris(char matriz[][M], int i, int j);
void quadro(char matriz[][M]);
void random(char matriz[][M], int quantFigura, int tipoFigura);
int figuras(char matriz[][M], int i, int j, int tipoFigura);
void print_matriz(char matriz[][M], int tipoFigura);
