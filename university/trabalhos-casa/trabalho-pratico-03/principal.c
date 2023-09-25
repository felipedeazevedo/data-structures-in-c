#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int qtdVertices;
    fscanf(arquivo, "%d", &qtdVertices);

    Ponto pontos[qtdVertices];

    for (int i = 0; i < qtdVertices; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    float area = calcularAreaPoligono(pontos, qtdVertices);
    printf("A área do polígono é %.2f", area);

    return 0;
}