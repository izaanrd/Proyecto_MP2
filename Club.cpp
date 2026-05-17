/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "Club"
//
// Declaraciones en: Club.h
//
// Fichero: Club.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Club.h"
#include "utils.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// Es necesario para cuando creemos un array de objetos Club. Se inicializarán todas las posiciones.

Club :: Club (void) : codigo(""), nombre(""), provincia("")
{ }

//--------------------------------------------------//
// Constructor con parámetros.
// Parámetros: trivial.

Club :: Club (string el_codigo, string el_nombre, string la_provincia) :
       codigo(el_codigo), nombre(el_nombre), provincia(la_provincia)
{ }

//--------------------------------------------------//
// Constructor desde un string.
// Parámetros: línea (string con los datos del club).
// Precondiciones: linea contiene los datos correctos en formato:
//      código * nombre * provincia *

Club :: Club (string linea, char delimitador){

    // Extraemos el campo "código"
	int pos = linea.find(delimitador);      // En pos se encuentra el asterisco
	codigo = Trim(linea.substr(0, pos));    // Se "corta" la línea desde que empieza hasta que acaba el campo (de 0 a pos)
	linea  = linea.substr(pos + 1);         // Se avanza la línea (se descarta lo procesado)

	// Extraemos el campo "nombre"
	pos    = linea.find(delimitador);
	nombre = Trim(linea.substr(0, pos));
	linea  = linea.substr(pos + 1);

	// Extraemos el campo "provincia"
	pos       = linea.find(delimitador);
	provincia = Trim(linea.substr(0, pos));
}

//--------------------------------------------------//
// Métodos GET

string Club :: GetCodigo    (void) const { return codigo;    }
string Club :: GetNombre    (void) const { return nombre;    }
string Club :: GetProvincia (void) const { return provincia; }

//--------------------------------------------------//
// Métodos SET

void Club :: SetCodigo (string el_codigo)
{
    codigo = el_codigo;
}

void Club :: SetNombre (string el_nombre)
{
    nombre = el_nombre;
}

void Club :: SetProvincia (string la_provincia)
{
    provincia = la_provincia;
}

//--------------------------------------------------//
// Serializa un dato "Club".
// Devuelve la representación en texto del dato "Club".

string Club :: ToString (void) const
{

	string cad;

	cad = 	FormatString(codigo, 8, TipoAlineacion::Izquierda) + " " +
      		FormatString(nombre, 35, TipoAlineacion::Izquierda) + " (" +
      		provincia + ")";

	return cad;
}