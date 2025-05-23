#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "interfaz.h"

int main() {
    int opcion;
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                Circulo c;
                printf("Introduce el centro del circulo (x y): ");
                scanf("%f %f", &c.centro.x, &c.centro.y);
                printf("Introduce el radio del circulo: ");
                scanf("%f", &c.radio);

                if (c.radio <= 0) {
                    printf("El radio debe ser positivo.\n");
                    break;
                }

                float area, perimetro;
                calcularAreaPerimetroCirculo(c, &area, &perimetro);
                printf("Area: %.2f, Perimetro: %.2f\n", area, perimetro);
                break;
            }

            case 2: {
                Rectangulo r;
                printf("Introduce el vertice inferior izquierdo (x y): ");
                scanf("%f %f", &r.verticeInferiorIzquierdo.x, &r.verticeInferiorIzquierdo.y);
                printf("Introduce el ancho y el alto del rectángulo: ");
                scanf("%f %f", &r.ancho, &r.alto);

                if (r.ancho <= 0 || r.alto <= 0) {
                    printf("Ancho y alto deben ser positivos.\n");
                    break;
                }

                float area, perimetro;
                calcularAreaPerimetroRectangulo(r, &area, &perimetro);
                printf("Area: %.2f, Perímetro: %.2f\n", area, perimetro);
                break;
            }

            case 3: {
                Punto p1, p2;
                printf("Introduce el primer punto (x y): ");
                scanf("%f %f", &p1.x, &p1.y);
                printf("Introduce el segundo punto (x y): ");
                scanf("%f %f", &p2.x, &p2.y);

                float distancia = calcularDistanciaEntrePuntos(p1, p2);
                printf("Distancia: %.2f\n", distancia);
                break;
            }

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
