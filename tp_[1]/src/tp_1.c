/*
 ============================================================================
 Name        : tp_1.c
 Author      : LautaroCasco Div E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "utnCalculos.h"

#define VALORBITCOIN 4606954.55

int main(void) {

	setbuf(stdout, NULL);

	int opcionMenu;
	int validacionDeRetorno;
	float kilometrosIngresados = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int flagKilometros = 0;
	int flagPrecios = 0;
	int flagOpcion3 = 0;
	int opcionSubMenu2;
	float precioAerolineasConDebito;
	float precioLatamConDebito;
	float precioAerolineasConCredito;
	float precioLatamConCredito;
	float precioAerolineasEnBitcoin;
	double precioLatamEnBitcoin;
	float precioKilometroAerolineas;
	float precioKilometroLatam;
	float diferenciaDePrecios;
	float cargaForzadaKilometrosIngresados = 7090;
	float cargaForzadaPrecioAerolineas = 162965;
	float cargaForzadaPrecioLatam = 159339;
	float cargaForzadaPrecioAerolineasConDebito;
	float cargaForzadaPrecioLatamConDebito;
	float cargaForzadaPrecioAerolineasConCredito;
	float cargaForzadaPrecioLatamConCredito;
	double cargaForzadaPrecioAerolineasEnBitcoin;
	float cargaForzadaPrecioLatamEnBitcoin;
	float cargaForzadaPrecioKilometroAerolineas;
	float cargaForzadaPrecioKilometroLatam;
	float cargaForzadaDiferenciaDePrecios;
	do {
		printf("\nMenu Principal\n1. Ingresar Kilómetros: (km=%.2f)",kilometrosIngresados);
		printf("\n2. Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)", precioAerolineas, precioLatam);
		validacionDeRetorno =getInt(&opcionMenu,"\n3. Calcular todos los costos:\n4. Informar Resultados\n"
		"5. Carga forzada de datos\n6. Salir\n\nIngrese opcion deseada:\n","\n\nOpcion incorrecta. ", 6, 1, 3);

		if (validacionDeRetorno == 0) {
			if (opcionMenu == 1 || opcionMenu == 5 || opcionMenu == 6 || flagKilometros == 1) {
				switch (opcionMenu) {
				case 1:
					validacionDeRetorno = getFloat(&kilometrosIngresados,"\nIngrese kilometros : ",
					"\nError, ingrese kilometros nuevamente (minimo 100): \n", 1000000, 100, 3);
					if (validacionDeRetorno == 0) {
						flagKilometros = 1;
					} else {
						kilometrosIngresados = 0;
					}
					break;
				case 2: //
					validacionDeRetorno =getInt(&opcionSubMenu2,"\n1. Ingresar precio de Aerolinas y precio de Latam:"
					"\n2. Volver al menu principal.\n","\nError,Ingrese opcion valida:\n", 2, 1,2);
					if (validacionDeRetorno == 0) {
						switch (opcionSubMenu2) {
						case 1:
							validacionDeRetorno = getFloat(&precioAerolineas,"\nIngrese precio de Aerolineas "
							"Argentinas: ","\nError, ingrese precio valido de Aerolineas: ",100000000, 100, 3);
							if (validacionDeRetorno == 0) {
								validacionDeRetorno =getFloat(&precioLatam,"\nIngrese precio de Latam: ",
								"\nError, ingrese precio valido de Latam: ",100000000, 100, 3);
								if (validacionDeRetorno == 0) {
									flagPrecios = 1;
								} else {
									precioAerolineas = 0;
								}
							}
							break;
						case 2:
							break;
						}
					}
					break;
				case 3:
					if (flagPrecios == 1 && flagKilometros == 1) {
						flagOpcion3 = 1;
						precioAerolineasConDebito = aplicarDescuento(precioAerolineas, 10);
						precioLatamConDebito = aplicarDescuento(precioLatam,10);
						precioAerolineasConCredito = aplicarInteres(precioAerolineas, 25);
						precioLatamConCredito = aplicarInteres(precioLatam, 25);
						precioAerolineasEnBitcoin = numeroEnBitcoin(precioAerolineas, 4606954.55);
						precioLatamEnBitcoin = numeroEnBitcoin(precioLatam,VALORBITCOIN);
						precioKilometroAerolineas = precioPorUnidad(precioAerolineas, kilometrosIngresados);
						precioKilometroLatam = precioPorUnidad(precioLatam,kilometrosIngresados);
						diferenciaDePrecios = diferenciaDeDosfloat(precioAerolineas, precioLatam);
					} else if (flagKilometros == 1 && flagPrecios == 0) {
						printf("Error, ingrese previamente opcion 2.");
					} else {
						printf("Error, Ingrese previamente opcion 1.");
					}
					break;
				case 4:
					if (flagPrecios == 1 && flagOpcion3 == 1) {
						printf("\nLatam: \na) Precio con tarjeta de débito: $%.2f\nb) Precio con tarjeta de crédito: $%.2f\n"
								"c) Precio pagando con bitcoin: $%lf\nd) Precio unitario: $%.2f\n",precioLatamConDebito,
								precioLatamConCredito, precioLatamEnBitcoin, precioKilometroLatam);
						printf("\nAerolíneas: \na) Precio con tarjeta de débito: $%.2f\nb) Precio con tarjeta de crédito: $%.2f\n"
								"c) Precio pagando con bitcoin: $%lf\nd) Precio unitario: $%.2f\n", precioAerolineasConDebito,
								precioAerolineasConCredito, precioAerolineasEnBitcoin, precioKilometroAerolineas);
						printf("\nLa diferencia de precio es: $%.2f", diferenciaDePrecios);
					} else if (flagPrecios == 1 && flagOpcion3 == 0) {
						printf("Error, Ingrese previamente opcion 3.");
					} else if (flagPrecios == 0 && flagOpcion3 == 1) {
						printf("Error, Ingrese previamente opcion 2.");
					} else {
						printf("Error, Ingrese previamente opcion 2 y luego opcion 3");
					}
					flagKilometros = 0;
					flagPrecios = 0;
					break;
				case 5:
					cargaForzadaPrecioAerolineasConDebito = aplicarDescuento(cargaForzadaPrecioAerolineas, 10);
					cargaForzadaPrecioLatamConDebito = aplicarDescuento(cargaForzadaPrecioLatam, 10);
					cargaForzadaPrecioAerolineasConCredito = aplicarInteres(cargaForzadaPrecioAerolineas, 25);
					cargaForzadaPrecioLatamConCredito = aplicarInteres(cargaForzadaPrecioLatam, 25);
					cargaForzadaPrecioAerolineasEnBitcoin = numeroEnBitcoin(cargaForzadaPrecioAerolineas, VALORBITCOIN);
					cargaForzadaPrecioLatamEnBitcoin = numeroEnBitcoin(cargaForzadaPrecioLatam, 4606954.55);
					cargaForzadaPrecioKilometroAerolineas = precioPorUnidad(cargaForzadaPrecioAerolineas,
					cargaForzadaKilometrosIngresados);
					cargaForzadaPrecioKilometroLatam = precioPorUnidad(cargaForzadaPrecioLatam, cargaForzadaKilometrosIngresados);
					cargaForzadaDiferenciaDePrecios = diferenciaDeDosfloat(cargaForzadaPrecioAerolineas,cargaForzadaPrecioLatam);
					printf("\nKilometros Ingresados: %f\n\nPrecio de Aerolineas : $%.2f\nLatam: \n"
					"a) Precio con tarjeta de débito: $%.2f\nb) Precio con tarjeta de crédito: $%.2f\n"
					"c) Precio pagando con bitcoin: $%lf\nd) Precio unitario: $%.2f\n",	cargaForzadaKilometrosIngresados,
					cargaForzadaPrecioAerolineas, cargaForzadaPrecioLatamConDebito, cargaForzadaPrecioLatamConCredito,
					cargaForzadaPrecioLatamEnBitcoin, cargaForzadaPrecioKilometroLatam);
					printf("\nPrecio de Latam: $%.2f\nAerolíneas: \na) Precio con tarjeta de débito: $%.2f\n"
					"b) Precio con tarjeta de crédito: $%.2f\nc) Precio pagando con bitcoin: $%lf\n"
					"d) Precio unitario: $%.2f\n", cargaForzadaPrecioAerolineas, cargaForzadaPrecioAerolineasConDebito,
					cargaForzadaPrecioAerolineasConCredito, cargaForzadaPrecioAerolineasEnBitcoin, cargaForzadaPrecioKilometroAerolineas);
					printf("\nLa diferencia de precio es: $%.2f", cargaForzadaDiferenciaDePrecios);
					break;
				case 6:
					printf("\nPrograma finalizado.");
					break;
				}
			} else if (opcionMenu == 2) {
				printf("Error, Ingresar previamente opcion 1.");
			} else if (opcionMenu == 3) {
				printf("Error, Ingresar previamente opcion 1 y luego opcion 2.");
			} else if (opcionMenu == 4) {
				printf("Error, Ingresar previamente opcion 1, opcion 2 y luego opcion 3.");
			}
		} else {
			printf("Te quedaste sin intentos.");
		}
	} while (opcionMenu != 6);
	return 0;
}

