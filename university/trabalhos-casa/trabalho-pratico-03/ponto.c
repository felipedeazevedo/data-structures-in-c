#include <stdio.h>
#include "ponto.h"

float calcularAreaPoligono(Ponto pontos[], int qtdVertices) {
    float area = 0.0;

    for (int i = 1; i < qtdVertices - 1; i++) {
        area += calcularAreaTriangulo(pontos[0], pontos[i], pontos[i + 1]);
    }

    return area;
}

float calcularAreaTriangulo(Ponto a, Ponto b, Ponto c) {
    // formula usada -> ((x0 * y1) + (y0 * x2) + (x1 * y2)) - ((y0 * x1) + (x0 * y2) + (y1 * x2));
    float determinante;

    determinante = ((a.X * b.Y) + (a.Y * c.X) + (b.X * c.Y)) - ((a.Y * b.X) + (a.X * c.Y) + (b.Y * c.X));

    if (determinante < 0) {
        determinante *= -1;
    }

    return 0.5 * determinante;
}