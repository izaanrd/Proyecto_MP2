/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "Inscripcion"
//
// Definiciones en: Inscripcion.cpp
//
// Fichero: Inscripcion.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef INSCRIPCION
#define INSCRIPCION

#include <string>

#include "Marca.h"
#include "utils.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

// Registro de Inscripciones

class Inscripcion {

private:

	string licencia_atleta;		// "MA143" - Licencia del atleta
	int    id_prueba;			// 1 - Identificador de la prueba
	Marca  marca;				// Marca conseguida por el atleta

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Necesario para crear arrays de objetos Inscripcion.

	Inscripcion (void);

	//--------------------------------------------------//
	// Constructor con parámetros.
	// Parámetros: trivial.

	Inscripcion (string la_licencia, int el_id_prueba, Marca la_marca);

	//--------------------------------------------------//
	// Constructor desde un string.
	// Parámetros: linea, string con los datos de la inscripción.
	//
	// Precondiciones: linea contiene los datos correctos en formato:
	//      licencia * id_prueba * tiempo * fecha *

	Inscripcion (string linea, char delimitador=DELIMITADOR);

	//--------------------------------------------------//
	// Métodos GET

	string GetLicenciaAtleta (void) const;
	int    GetIdPrueba       (void) const;
	Marca  GetMarca          (void) const;

	//--------------------------------------------------//
	// Métodos SET

	void SetLicenciaAtleta (string la_licencia);
	void SetIdPrueba       (int el_id_prueba);
	void SetMarca          (Marca la_marca);

	//--------------------------------------------------//
	// Serializa un dato "Inscripcion".
	// Devuelve: la representación textual de un dato "Inscripcion".

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif