/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "Atleta"
//
// Declaraciones en: Atleta.h
//
// Fichero: Atleta.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Atleta.h"
#include "utils.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// Crea un objeto Atleta vacío.

Atleta :: Atleta (void) :
    licencia(""), apellidos(""), nombre(""), fecha_nacimiento(), id_club(""), sexo(' ')
{ }

//--------------------------------------------------//
// Constructor con parámetros.
// Parámetros: trivial.

Atleta :: Atleta (string la_licencia, string los_apellidos, string el_nombre,
                Fecha la_fecha, string el_id_club, char el_sexo) :
          		licencia(la_licencia), apellidos(los_apellidos), nombre(el_nombre),
          		fecha_nacimiento(la_fecha), id_club(el_id_club), sexo(el_sexo)
{ }

//--------------------------------------------------//
// Constructor desde un string.
// Parámetros: linea, string con los datos del atleta.
//
// PRE: linea contiene los datos correctos en formato:
//      licencia * apellidos * nombre * fecha_nacimiento * id_club * sexo *

Atleta :: Atleta (string linea, char delimitador)
{
	// Extraer el campo "licencia"
	int pos   = linea.find(delimitador);
	licencia  = Trim(linea.substr(0, pos));
	linea     = linea.substr(pos + 1);

	// Extraer el campo "apellidos"
	pos       = linea.find(delimitador);
	apellidos = Trim(linea.substr(0, pos));
	linea     = linea.substr(pos + 1);

	// Extraer el campo "nombre"
	pos       = linea.find(delimitador);
	nombre    = Trim(linea.substr(0, pos));
	linea     = linea.substr(pos + 1);

	// Extraer el campo "fecha_nacimiento"
	// Se extrae como string y se construye un objeto Fecha con él
	pos                = linea.find(delimitador);
	string str_fecha   = Trim(linea.substr(0, pos));
	fecha_nacimiento   = Fecha(str_fecha);
	linea              = linea.substr(pos + 1);

	// Extraer el campo "id_club"
	pos     = linea.find(delimitador);
	id_club = Trim(linea.substr(0, pos));
	linea   = linea.substr(pos + 1);

	// Extraer el campo "sexo"
	pos  = linea.find(delimitador);
	string str_sexo = Trim(linea.substr(0, pos));
	sexo = str_sexo[0];
}

//--------------------------------------------------//
// Métodos GET

string Atleta :: GetLicencia        (void) const { return licencia;         }
string Atleta :: GetApellidos       (void) const { return apellidos;        }
string Atleta :: GetNombre          (void) const { return nombre;           }
Fecha  Atleta :: GetFechaNacimiento (void) const { return fecha_nacimiento; }
string Atleta :: GetIdClub          (void) const { return id_club;          }
char   Atleta :: GetSexo            (void) const { return sexo;             }

//--------------------------------------------------//
// Métodos SET

void Atleta :: SetLicencia (string la_licencia)
{
    licencia = la_licencia;
}

void Atleta :: SetApellidos (string los_apellidos)
{
    apellidos = los_apellidos;
}

void Atleta :: SetNombre (string el_nombre)
{
    nombre = el_nombre;
}

void Atleta :: SetFechaNacimiento (Fecha la_fecha)
{
    fecha_nacimiento = la_fecha;
}

void Atleta :: SetIdClub (string el_id_club)
{
    id_club = el_id_club;
}

void Atleta :: SetSexo (char el_sexo)
{
    sexo = el_sexo;
}

//--------------------------------------------------//
// Serializa un dato "Atleta".
//
// Devuelve: la representación textual de un dato "Atleta".

string Atleta :: ToString (void) const
{
	string cad;

	cad = FormatString(licencia, 10, TipoAlineacion::Izquierda) + " " +
	      FormatString(apellidos, 25, TipoAlineacion::Izquierda) + " " +
	      FormatString(nombre, 15, TipoAlineacion::Izquierda) + " " +
	      fecha_nacimiento.ToString(true)                        + " " +
	      FormatString(id_club, 8, TipoAlineacion::Izquierda) + " " +
	      FormatString(string(1, sexo), 1, TipoAlineacion::Izquierda);

	return cad;
}