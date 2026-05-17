/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "Marca"
//
// Declaraciones en: Marca.h
//
// Fichero: Marca.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Marca.h"
#include "utils.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// Crea un objeto Marca vacío.

Marca :: Marca (void) :
         tiempo_marca(), fecha_marca()
{ }

//--------------------------------------------------//
// Constructor con parámetros.
// Parámetros: trivial.

Marca :: Marca (Tiempo el_tiempo, Fecha la_fecha) :
         tiempo_marca(el_tiempo), fecha_marca(la_fecha)
{ }

//--------------------------------------------------//
// Constructor desde un string.
// Parámetros: linea, string con los datos de la marca.
//
// PRE: linea contiene los datos correctos en formato:
//      tiempo * fecha *

Marca :: Marca (string linea, char delimitador)
{
	int pos = linea.find(delimitador);

	string str_tiempo = Trim(linea.substr(0, pos));
	tiempo_marca = Tiempo(str_tiempo);

	linea = linea.substr(pos + 1);

	pos = linea.find(delimitador);

	string str_fecha = Trim(linea.substr(0, pos));
	fecha_marca = Fecha(str_fecha);
}

//--------------------------------------------------//
// Métodos GET

Tiempo Marca :: GetTiempoMarca (void) const { return tiempo_marca; }
Fecha  Marca :: GetFechaMarca  (void) const { return fecha_marca;  }

//--------------------------------------------------//
// Métodos SET

void Marca :: SetTiempoMarca (Tiempo el_tiempo)
{
	tiempo_marca = el_tiempo;
}

void Marca :: SetFechaMarca (Fecha la_fecha)
{
	fecha_marca = la_fecha;
}

//--------------------------------------------------//
// Serializa un dato "Marca".
//
// Devuelve: la representación textual de un dato "Marca".

string Marca :: ToString (void) const
{
	string cad;

	cad = tiempo_marca.ToString() + " " + fecha_marca.ToString(true);

	return cad;
}