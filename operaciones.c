#include "operaciones.h"

float calcularDistanciaEntrePuntos(Punto p1, Punto p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void calcularAreaPerimetroCirculo(Circulo c, float* area, float* perimetro) {
    *area = M_PI * c.radio * c.radio;
    *perimetro = 2 * M_PI * c.radio;
}

void calcularAreaPerimetroRectangulo(Rectangulo r, float* area, float* perimetro) {
    *area = r.ancho * r.alto;
    *perimetro = 2 * (r.ancho + r.alto);
}

float calcularDistanciaEntreFormas(Punto p1, Punto p2) {
    return calcularDistanciaEntrePuntos(p1, p2);
}

int colisionCirculoCirculo(Circulo c1, Circulo c2) {
    float distancia = calcularDistanciaEntrePuntos(c1.centro, c2.centro);
    return distancia <= (c1.radio + c2.radio);
}

int colisionCirculoRectangulo(Circulo c, Rectangulo r) {
    float puntoCercanoX = fmax(r.verticeInferiorIzquierdo.x, fmin(c.centro.x, r.verticeInferiorIzquierdo.x + r.ancho));
    float puntoCercanoY = fmax(r.verticeInferiorIzquierdo.y, fmin(c.centro.y, r.verticeInferiorIzquierdo.y + r.alto));
    float distancia = sqrt(pow(c.centro.x - puntoCercanoX, 2) + pow(c.centro.y - puntoCercanoY, 2));
    return distancia <= c.radio;
}

int colisionRectanguloRectangulo(Rectangulo r1, Rectangulo r2) {
    int colisionX = r1.verticeInferiorIzquierdo.x < (r2.verticeInferiorIzquierdo.x + r2.ancho) &&
                    (r1.verticeInferiorIzquierdo.x + r1.ancho) > r2.verticeInferiorIzquierdo.x;
    int colisionY = r1.verticeInferiorIzquierdo.y < (r2.verticeInferiorIzquierdo.y + r2.alto) &&
                    (r1.verticeInferiorIzquierdo.y + r1.alto) > r2.verticeInferiorIzquierdo.y;
    return colisionX && colisionY;
}
