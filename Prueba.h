/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "Prueba"
//
// Definiciones en: Prueba.cpp
//
// Fichero: Prueba.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef PRUEBA
#define PRUEBA

#include <string>

#include "Tiempo.h"
#include "utils.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

// Registro de Pruebas

class Prueba {

private:

	int    id_prueba;		// 1 - Identificador único de la prueba
	int distancia;			// 60 - Distancia en metros
	Tiempo tiempo_corte;	// 00:00:07:30 - Tiempo máximo para ser admitido
	int    cupo;			// 12 - Número máximo de atletas admitidos
	string descripcion;		// "60 ML Hombres" - Título de la prueba

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Necesario para crear arrays de objetos Prueba. Se inicializarán todas las posiciones.

	Prueba (void);

	//--------------------------------------------------//
	// Constructor con parámetros.
	// Parámetros: trivial.

	Prueba (int el_id, int la_distancia, Tiempo el_tiempo_corte,
	        int el_cupo, string la_descripcion);

	//--------------------------------------------------//
	// Constructor desde un string.
	// Parámetros: linea, string con los datos de la prueba.
	//
	// Precondiciones: linea contiene los datos correctos en formato:
	//      id_prueba * distancia * tiempo_corte * cupo * descripcion *

	Prueba (string linea, char delimitador=DELIMITADOR);

	//--------------------------------------------------//
	// Métodos GET

	int    	GetIdPrueba     (void) const;
	int 	GetDistancia    (void) const;
	Tiempo 	GetTiempoCorte  (void) const;
	int    	GetCupo         (void) const;
	string 	GetDescripcion  (void) const;

	//--------------------------------------------------//
	// Métodos SET

	void SetIdPrueba     (int el_id);
	void SetDistancia    (int la_distancia);
	void SetTiempoCorte  (Tiempo el_tiempo);
	void SetCupo         (int el_cupo);
	void SetDescripcion  (string la_descripcion);

	//--------------------------------------------------//
	// Serializa un dato "Prueba".
	// Devuelve: la representación textual de un dato "Prueba".

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif
