/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "Atleta"
//
// Definiciones en: Atleta.cpp
//
// Fichero: Atleta.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef ATLETA
#define ATLETA

#include <string>
#include "Fecha.h"
#include "utils.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

// Registro de Atletas //

class Atleta {

private:

	string licencia;			// "MA143" - Número de licencia del atleta
	string apellidos;			// "FERNANDEZ ARRIBA" - Apellidos del atleta
	string nombre;				// "JUAN" - Nombre del atleta
	Fecha  fecha_nacimiento;	// Fecha de nacimiento del atleta
	string id_club;				// "NERMA" - Código del club al que pertenece
	char sexo;					// "H" o "M" - Sexo del atleta

public:

    //--------------------------------------------------//
	// Constructor sin argumentos.
	// Necesario para crear arrays de objetos Atleta. S inicializarán todas las posiciones.

	Atleta (void);

	//--------------------------------------------------//
	// Constructor con parámetros.
	// Parámetros: trivial.

	Atleta (string la_licencia, string los_apellidos, string el_nombre,
        	Fecha la_fecha, string el_id_club, char el_sexo);
	
    //--------------------------------------------------//
	// Constructor desde un string.
	// Parámetros: linea (string con los datos del atleta).
	//
	// Precondiciones: linea contiene los datos correctos en formato:
	//      licencia * apellidos * nombre * fecha_nacimiento * id_club * sexo *

	Atleta (string linea, char delimitador=DELIMITADOR);

    //--------------------------------------------------//
    // Métodos GET

	string GetLicencia         (void) const;
	string GetApellidos        (void) const;
	string GetNombre           (void) const;
	Fecha  GetFechaNacimiento  (void) const;
	string GetIdClub           (void) const;
	char GetSexo               (void) const;

	//--------------------------------------------------//
    // Métodos SET

	void SetLicencia        (string la_licencia);
	void SetApellidos       (string los_apellidos);
	void SetNombre          (string el_nombre);
	void SetFechaNacimiento (Fecha la_fecha);
	void SetIdClub          (string el_id_club);
	void SetSexo            (char el_sexo);

    //--------------------------------------------------//
	// Serializa un dato "Atleta".
	// Devuelve: la representación en texto de un dato "Atleta".

	string ToString (void) const;

};
 
/////////////////////////////////////////////////////////////////////////////
 
#endif