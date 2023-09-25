#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float X;
    float Y;
} Ponto;

float calcularAreaPoligono(Ponto pontos[], int qtdVertices);
float calcularAreaTriangulo(Ponto a, Ponto b, Ponto c);

#endif
