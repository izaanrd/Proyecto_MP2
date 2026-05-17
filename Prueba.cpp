/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "Prueba"
//
// Declaraciones en: Prueba.h
//
// Fichero: Prueba.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>

#include "Prueba.h"
#include "utils.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// Crea un objeto Prueba vacío.

Prueba :: Prueba (void) :
    id_prueba(0),
    distancia(0),
    tiempo_corte(),
    cupo(0),
    descripcion("")
{ }

//--------------------------------------------------//
// Constructor con parámetros.
// Parámetros: trivial.

Prueba :: Prueba (int el_id, int la_distancia, Tiempo el_tiempo_corte,
                  int el_cupo, string la_descripcion) :
          		  id_prueba(el_id), distancia(la_distancia), 
          		  tiempo_corte(el_tiempo_corte), cupo(el_cupo), 
          		  descripcion(la_descripcion)
{ }

//--------------------------------------------------//
// Constructor desde un string.
// Parámetros: linea, string con los datos de la prueba.
//
// Precondiciones: linea contiene los datos correctos en formato:
//      id_prueba * distancia * tiempo_corte * cupo * descripcion *

Prueba :: Prueba (string linea, char delimitador)
{
	// Extraer el campo "id_prueba"
	int pos      = linea.find(delimitador);
	id_prueba    = stoi(Trim(linea.substr(0, pos)));
	linea        = linea.substr(pos + 1);

	// Extraer el campo "distancia"
	pos          = linea.find(delimitador);
	distancia    = stoi(Trim(linea.substr(0, pos)));
	linea        = linea.substr(pos + 1);

	// Extraer el campo "tiempo_corte"
	// Se extrae como string y se construye un objeto Tiempo con él
	pos                  = linea.find(delimitador);
	string str_tiempo    = Trim(linea.substr(0, pos));
	tiempo_corte         = Tiempo(str_tiempo);
	linea                = linea.substr(pos + 1);

	// Extraer el campo "cupo"
	pos      = linea.find(delimitador);
	cupo     = stoi(Trim(linea.substr(0, pos)));
	linea    = linea.substr(pos + 1);

	// Extraer el campo "descripcion"
	pos          = linea.find(delimitador);
	descripcion  = Trim(linea.substr(0, pos));
}

//--------------------------------------------------//
// Métodos GET

int    Prueba :: GetIdPrueba    (void) const { return id_prueba;    }
int    Prueba :: GetDistancia   (void) const { return distancia;    }
Tiempo Prueba :: GetTiempoCorte (void) const { return tiempo_corte; }
int    Prueba :: GetCupo        (void) const { return cupo;         }
string Prueba :: GetDescripcion (void) const { return descripcion;  }

//--------------------------------------------------//
// Métodos SET

void Prueba :: SetIdPrueba (int el_id)
{
    id_prueba = el_id;
}

void Prueba :: SetDistancia (int la_distancia)
{
    distancia = la_distancia;
}

void Prueba :: SetTiempoCorte (Tiempo el_tiempo)
{
    tiempo_corte = el_tiempo;
}

void Prueba :: SetCupo (int el_cupo)
{
    cupo = el_cupo;
}

void Prueba :: SetDescripcion (string la_descripcion)
{
    descripcion = la_descripcion;
}

//--------------------------------------------------//
// Serializa un dato "Prueba".
//
// Devuelve: la representación textual de un dato "Prueba".

string Prueba :: ToString (void) const
{
	string cad;

	cad = FormatInt   (id_prueba,  3, ' ')          + " " +
	      FormatInt(distancia, 5, ' ')      		+ " m. " +
	      tiempo_corte.ToString()                   + " " +
	      FormatInt   (cupo,       2, ' ')          + " " +
	      FormatString(descripcion, 25, TipoAlineacion::Izquierda);

	return cad;
}

/***************************************************************************/
/***************************************************************************/
