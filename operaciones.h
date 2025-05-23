#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <math.h>

typedef struct {
    float x, y;
} Punto;

typedef struct {
    Punto centro;
    float radio;
} Circulo;

typedef struct {
    Punto verticeInferiorIzquierdo;
    float ancho, alto;
} Rectangulo;

float calcularDistanciaEntrePuntos(Punto p1, Punto p2);
void calcularAreaPerimetroCirculo(Circulo c, float* area, float* perimetro);
void calcularAreaPerimetroRectangulo(Rectangulo r, float* area, float* perimetro);
float calcularDistanciaEntreFormas(Punto p1, Punto p2);
int colisionCirculoCirculo(Circulo c1, Circulo c2);
int colisionCirculoRectangulo(Circulo c, Rectangulo r);
int colisionRectanguloRectangulo(Rectangulo r1, Rectangulo r2);

#endif
