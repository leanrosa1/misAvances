/*
 ============================================================================
 Name        : Clase.c
 Author      : Leandro Rosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pedirNumero (float valorMinimo, float valorMaximo, int intentos, char mensaje[], float* prNumero);
int dividir (float dividendo, float divisor, float* pResultado);

int main(void) {
	setbuf(stdout, NULL);
	float dividendo;
	float divisor;
	float resultado;

	char mensaje[] = "Ingrese el número dividendo";
	if(pedirNumero(0.0, 1000.0, 3, mensaje, &dividendo) == 1) {
		printf("\nIngresaste: %f\n", dividendo);
		char mensaje[] = "Ingrese el número divisor";
		if (pedirNumero(0.0, 1000.0, 3, mensaje, &divisor) == 1) {
				printf("\nIngresaste %f", divisor);
				if (dividir (dividendo, divisor, &resultado) == 0) {
						printf("\nNo es posible realizar la operación porque el divisor es 0");
					} else {
						printf("\nEl resultado es %f", resultado);
					}
		}
	}
	printf("\nGracias por usar nuestro programa");
	return EXIT_SUCCESS;
}

int pedirNumero (float valorMinimo, float valorMaximo, int intentos, char mensaje[], float* prNumero) {
	int contador;
	float numero;
	int estado;
	int intentosRestantes;
	if (valorMinimo < valorMaximo) {
		for (contador = 0; contador <= intentos; contador++) {
			printf("%s \n", mensaje);
			scanf("%f", &numero);
			if (numero >= valorMinimo && numero <= valorMaximo) {
				*prNumero = numero;
				estado = 1;
				break;
			} else {
				estado = 0;
				intentosRestantes = intentos - contador;
				printf("Numero fuera de rango. Quedan %d intentos\n", intentosRestantes);
			}
		}
	} else {
		printf("Error. Valor mínimo mayor a valor máximo");
		estado = 0;
	}
	return estado;
}

int dividir (float dividendo, float divisor, float* pResultado) {
	int estado = 1;
	if (divisor != 0) {
		*pResultado = dividendo / divisor;
	} else {
		estado = 0;
	}
	return estado;
}
