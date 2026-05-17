/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "Inscripcion"
//
// Declaraciones en: Inscripcion.h
//
// Fichero: Inscripcion.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Inscripcion.h"
#include "utils.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// Crea un objeto Inscripcion vacío.

Inscripcion :: Inscripcion (void) :
             licencia_atleta(""), id_prueba(0), marca()
{ }

//--------------------------------------------------//
// Constructor con parámetros.
// Parámetros: trivial.

Inscripcion :: Inscripcion (string la_licencia, int el_id_prueba, Marca la_marca) :
             licencia_atleta(la_licencia), id_prueba(el_id_prueba), marca(la_marca)
{ }

//--------------------------------------------------//
// Constructor desde un string.
// Parámetros: linea, string con los datos de la inscripción.
//
// Precondiciones: linea contiene los datos correctos en formato:
//      licencia * id_prueba * tiempo * fecha *

Inscripcion :: Inscripcion (string linea, char delimitador)
{
	int pos = linea.find(delimitador);

	licencia_atleta = Trim(linea.substr(0, pos));
	linea = linea.substr(pos + 1);

	pos = linea.find(delimitador);

	id_prueba = stoi(Trim(linea.substr(0, pos)));
	linea = linea.substr(pos + 1);

	marca = Marca(linea, delimitador);
}

//--------------------------------------------------//
// Métodos GET

string Inscripcion :: GetLicenciaAtleta (void) const { return licencia_atleta; }
int    Inscripcion :: GetIdPrueba       (void) const { return id_prueba;       }
Marca  Inscripcion :: GetMarca          (void) const { return marca;           }

//--------------------------------------------------//
// Métodos SET

void Inscripcion :: SetLicenciaAtleta (string la_licencia)
{
	licencia_atleta = la_licencia;
}

void Inscripcion :: SetIdPrueba (int el_id_prueba)
{
	id_prueba = el_id_prueba;
}

void Inscripcion :: SetMarca (Marca la_marca)
{
	marca = la_marca;
}

//--------------------------------------------------//
// Serializa un dato "Inscripcion".
//
// Devuelve: la representación textual de un dato "Inscripcion".

string Inscripcion :: ToString (void) const
{
	string cad;

	cad = FormatString(licencia_atleta, 8, TipoAlineacion::Izquierda) + " " +
	      FormatInt(id_prueba, 3, ' ') + " " +
	      marca.ToString();

	return cad;
}