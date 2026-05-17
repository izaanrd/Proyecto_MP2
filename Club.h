/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "Club"
//
// Definiciones en: Club.cpp
//
// Fichero: Club.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLUB
#define CLUB

#include <string>
#include "utils.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////

// Registro de Clubes //

class Club {

private:

    string codigo;  // "ALBGR" El código del club.
    string nombre;  // "Atletismo Albolote"
    string provincia;   // "Granada"

public:

    //--------------------------------------------------//
    // Constructor sin argumentos.
    // Es necesario para cuando creemos un array de objetos Club. Se inicializarán todas las posiciones.

    Club (void);

    //--------------------------------------------------//
    // Constructor con parámetros.
    // Parámetros: trivial.

    Club (string el_codigo, string el_nombre, string la_provincia);

    //--------------------------------------------------//
    // Constructor desde un string.
    // Parámetros: linea (string con los datos del club).
    // Precondiciones: linea contiene los datos correctos en formato:
    //      código * nombre * provincia *

    Club (string linea, char delimitador=DELIMITADOR);
    
    //--------------------------------------------------//
    // Métodos GET

    string GetCodigo    (void) const;
    string GetNombre    (void) const;
    string GetProvincia (void) const;

    //--------------------------------------------------//
    // Métodos SET

    void SetCodigo    (string el_codigo);
    void SetNombre    (string el_nombre);
    void SetProvincia (string la_provincia);

    //--------------------------------------------------//
    // Serializa un dato "Club".
    // Devuelve la representación en texto del dato "Club".

    string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif