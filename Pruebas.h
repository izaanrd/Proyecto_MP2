#ifndef PRUEBAS
#define PRUEBAS

#include <string>

#include "Prueba.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Pruebas {

private:

	static const int TAMANIO = 50; // Núm. de casillas disponibles
	Prueba vector_privado[TAMANIO];

	// Precondiciones: 0 <= total_utilizados <= TAMANIO
	int total_utilizados; // Núm. de casillas ocupadas

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Post: total_utilizados = 0 (la secuencia estará vacía)

	Pruebas (void);

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

	Prueba Elemento (int pos) const;

	//--------------------------------------------------//
	// Añade un elemento ("nuevo") a la secuencia.
	// El nuevo elemento se coloca al final.
	//
	// Precondiciones: TotalUtilizados() < Capacidad()

	void Aniade (const Prueba & nuevo);

	//--------------------------------------------------//
	// Inserta "nuevo" en la posición "pos".
	// Los elementos por encima se desplazan una posición a la derecha.
	//
	// Precondiciones: TotalUtilizados() < Capacidad()
	// Precondiciones: 1 <= pos <= TotalUtilizados()+1

	void Inserta (int pos, const Prueba & nuevo);

	//--------------------------------------------------//
	// Elimina el elemento de la posición "pos".
	//
	// Precondiciones: 1 <= pos <= TotalUtilizados()

	void Elimina (int pos);

	//--------------------------------------------------//
	// Serializa la secuencia.

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif