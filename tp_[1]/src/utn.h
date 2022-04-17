/*
 * utn.h
 *
 *  Created on: 12 abr. 2022
 *      Author: LautaroCasco Div E
 */

#ifndef UTN_H_
#define UTN_H_

int getInt(int *pNumeroIngresado, char *mensaje, char *mensajeError, int maximo,
		int minimo, int maximoDeReintentos);

int getFloat(float *pNumeroIngresado, char *mensaje, char *mensajeError,
		float maximo, float minimo, int maximoDeReintentos);

int getDosFloat(float *pNumero1, float *pNumero2, char *primerMensajePidePrimerFloat,
		char *segundoMensajePideSegundoFloat, char *mensajeError1, char *mensajeError2,
		int maximo, int minimo, int maximoDeReintentos1, int maximoDeReintentos2);

#endif /* UTN_H_ */
