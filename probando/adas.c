#include <stdio.h>
#include <stdlib.h>

int sumarDosEnteros (int primerNumero, int segundoNumero);

int main (void) {
    int numeroA = 8;
    int numeroB = 10;
    printf("El resultado es %d", sumarDosEnteros(numeroA, numeroB));
    return 0;   
}

int sumarDosEnteros (int primerNumero, int segundoNumero) {
    int resultado = primerNumero + segundoNumero;
    return resultado;
}