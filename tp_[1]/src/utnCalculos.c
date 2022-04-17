/*
 * utnCalculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: LautaroCasco Div E
 */

#include <stdio.h>
#include <stdlib.h>


	//a) Tarjeta de débito
/// @brief // Toma un numero flotante y aplica un descuento.
///
/// @param numeroInicial // Toma variable con numero flotante.
/// @param porcentajeDescuento // Toma porcentaje a descontar.
/// @return
float aplicarDescuento(float numeroInicial, float porcentajeDescuento){

	float auxDescuento;
	float numeroFinal;

	auxDescuento=(numeroInicial*porcentajeDescuento)/100;
	numeroFinal=numeroInicial-auxDescuento;

	return numeroFinal;
	}
   //b) tarjeta de credito
/// @brief // Toma numero flotante y se le incrementa un interes.
///
/// @param numeroInicial // Toma numero flotante.
/// @param porcentajeInteres // Toma porcentaje a incrementar.
/// @return
float aplicarInteres(float numeroInicial, float porcentajeInteres){

	float auxInteres;
	float numeroFinal;

	auxInteres=(numeroInicial*porcentajeInteres)/100;
	numeroFinal=numeroInicial+auxInteres;

	return numeroFinal;
	}
	//c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
/// @brief // Toma numero flotante y devuelve numero en bitcoin.
///
/// @param numeroInicial // Toma variable con numero flotante.
/// @param valorBitcoin // Toma valor de Bitcoin.
/// @return
double numeroEnBitcoin(float numeroInicial, double valorBitcoin){

	double numeroEnBitcoin;

	numeroEnBitcoin = numeroInicial / valorBitcoin;

	return numeroEnBitcoin;

}


/// @brief // Toma numero flotante y muestra precio unitario.
///
/// @param precioTotal // Toma precio total.
/// @param cantidadTotal // Toma cantidad total.
/// @return
float precioPorUnidad(float precioTotal, float cantidadTotal){

	float precioUnitario;

	precioUnitario=(precioTotal/cantidadTotal);

	return precioUnitario;
}

/// @brief // Muestra diferencia entre dos numeros.
///
/// @param numero1 // Toma primer numero flotante.
/// @param numero2 // Toma segundo numero flotante.
/// @return
float diferenciaDeDosfloat(float numero1, float numero2){

	float diferencia;

	if (numero1>=numero2){
		diferencia=numero1-numero2;
	}else{
		diferencia=numero2-numero1;
	}
	return diferencia;
}

