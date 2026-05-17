/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Declaración de la clase "SecuenciaClubes"
//
// Definiciones en: SecuenciaClubes.cpp
//
// Fichero: SecuenciaClubes.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CLUBES
#define CLUBES

#include <string>

#include "Club.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Clubes {

private:

	static const int TAMANIO = 50; // Núm. de casillas disponibles
	Club vector_privado[TAMANIO];

	// Precondiciones: 0 <= total_utilizados <= TAMANIO
	int total_utilizados; // Núm. de casillas ocupadas

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Post: total_utilizados = 0 (la secuencia estará vacía)

	Clubes (void);

	//--------------------------------------------------//
	// Devuelve el número de casillas ocupadas.

	int TotalUtilizados (void) const;

	//--------------------------------------------------//
	// Devuelve el número de casillas disponibles.

	int Capacidad (void) const;

	//--------------------------------------------------//
	// "Vacía" completamente la secuencia.
	// POST: total_utilizados = 0

	void EliminaTodos (void);

	//--------------------------------------------------//
	// Devuelve el elemento de la posición "pos".
	//
	// Precondiciones: 1 <= pos <= TotalUtilizados()

	Club Elemento (int pos) const;

	//--------------------------------------------------//
	// Añade un elemento ("nuevo") a la secuencia.
	// El nuevo elemento se coloca al final.
	//
	// Precondiciones: TotalUtilizados() < Capacidad()

	void Aniade (const Club & nuevo);

	//--------------------------------------------------//
	// Inserta "nuevo" en la posición "pos".
	// Los elementos por encima se desplazan una posición a la derecha.
	//
	// Precondiciones: TotalUtilizados() < Capacidad()
	// Precondiciones: 1 <= pos <= TotalUtilizados()+1

	void Inserta (int pos, const Club & nuevo);

	//--------------------------------------------------//
	// Elimina el elemento de la posición "pos".
	// Los elementos de después se desplazan a la izquierda (una posición).
	//
	// Precondiciones: 1 <= pos <= TotalUtilizados()

	void Elimina (int pos);

	//--------------------------------------------------//
	// Serializa la secuencia.
	//
	// Devuelve: la representación textual de todos los clubes guardados.

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif