/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "Marca"
//
// Definiciones en: Marca.cpp
//
// Fichero: Marca.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef MARCA
#define MARCA

#include <string>

#include "Tiempo.h"
#include "Fecha.h"
#include "utils.h"

using namespace std;

// Registro de Marcas

class Marca {

private:

	Tiempo tiempo_marca;	// 00:00:06:94 - Tiempo de la marca
	Fecha  fecha_marca;		// 05/05/2025  - Fecha en que se consiguió

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Necesario para crear arrays de objetos Marca.

	Marca (void);

	//--------------------------------------------------//
	// Constructor con parámetros.
	// Parámetros: trivial.

	Marca (Tiempo el_tiempo, Fecha la_fecha);

	//--------------------------------------------------//
	// Constructor desde un string.
	// Parámetros: linea, string con los datos de la marca.
	//
	// Precondiciones: linea contiene los datos correctos en formato:
	//      tiempo * fecha *

	Marca (string linea, char delimitador=DELIMITADOR);

	//--------------------------------------------------//
	// Métodos GET

	Tiempo GetTiempoMarca (void) const;
	Fecha  GetFechaMarca  (void) const;

	//--------------------------------------------------//
	// Métodos SET

	void SetTiempoMarca (Tiempo el_tiempo);
	void SetFechaMarca  (Fecha la_fecha);

	//--------------------------------------------------//
	// Serializa un dato "Marca".
	// Devuelve: la representación textual de un dato "Marca".

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif