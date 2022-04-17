/*
 * utn.c
 *
 *  Created on: 12 abr. 2022
 *      Author: LautaroCasco Div E
 */
#include <stdio.h>
#include <stdlib.h>

/// @brief 	Valida un numero entero y lo retorna.
///
/// @param pNumeroIngresado // Ingresa numero entero.
/// @param mensaje // Muestra mensaje solicitando numero entero.
/// @param mensajeError // Muestra mensaje de error si el ingreso falla.
/// @param maximo // Maximo valor posible del numero entero.
/// @param minimo // Minimo valor posible del numero entero.
/// @param maximoDeReintentos // Total de reintentos
/// @return
int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError,
		int maximo, int minimo, int maximoDeReintentos) {

	int auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			maximoDeReintentos--;

			if (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
		} while (maximoDeReintentos > 0);
	}
	return retorno;
}

/// @brief //Valida un numero entero y lo retorna.
///
/// @param pNumeroIngresado // Ingresa numero flotante.
/// @param mensaje // Muestra mensaje solicitando numero entero.
/// @param mensajeError // Muestra mensaje de error si el ingreso falla.
/// @param maximo // Maximo valor posible del numero entero.
/// @param minimo // Minimo valor posible del numero entero.
/// @param maximoDeReintentos // Total de reintentos/*/
/// @return
int getFloat(float *pNumeroIngresado, char *mensaje, char *mensajeError,
	float maximo, float minimo, int maximoDeReintentos) {

	float auxNumeroIngresado;
	int retorno;
	retorno = -1;

	if (pNumeroIngresado != NULL && maximo >= minimo && maximoDeReintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			maximoDeReintentos--;

			if (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) {
				*pNumeroIngresado = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
			}
		} while (maximoDeReintentos > 0);
	}
	return retorno;
}
