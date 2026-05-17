#ifndef PARTICIPACIONES
#define PARTICIPACIONES

#include <string>
#include "Inscripcion.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Participaciones {

private:

	Inscripcion *vector_privado;

	int total_utilizados;

	int capacidad;

	// Funciones para optimizar la gestión de memoria dinámica

	/************************************************************/
	// Pide memoria para poder guardar num elementos.
	// Parámetros: num, número de casillas reservadas (capacidad).
	// PRE: num_casillas >= 0

	void ReservarMemoria(int num_casillas);

	/************************************************************/
	// Libera memoria
	// POST: El número de casillas usadas es 0
	// POST: El número de casillas reservadas es 0

	void LiberarMemoria();

	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos(const Participaciones &otro);

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Post: total_utilizados = 0 (la secuencia estará vacía)

	Participaciones (void);

	//--------------------------------------------------//
	// Constructor de copia

	Participaciones(const Participaciones &otro);

	//--------------------------------------------------//
	// Destructor

	~Participaciones();

	//--------------------------------------------------//
	// Método Clona para realizar copia profunda

	void Clona(const Participaciones &otro);

	//--------------------------------------------------//
	// Devuelve el número de casillas ocupadas.

	int TotalUtilizados (void) const;

	//--------------------------------------------------//
	// Devuelve el número de casillas reservadas.

	int Capacidad (void) const;

	//--------------------------------------------------//
	// "Vacía" completamente la secuencia.
	// POST: total_utilizados = 0

	void EliminaTodos (void);

	//--------------------------------------------------//
	// Devuelve el elemento de la posición "pos".
	//
	// Precondiciones: 1 <= pos <= TotalUtilizados()

	Inscripcion Elemento (int pos) const;

	//--------------------------------------------------//
	// Añade un elemento ("nuevo") a la secuencia.
	// El nuevo elemento se coloca al final.

	void Aniade (const Inscripcion & nuevo);

	//--------------------------------------------------//
	// Inserta "nuevo" en la posición "pos".
	// Los elementos por encima se desplazan una posición a la derecha.

	void Inserta (int pos, const Inscripcion & nuevo);

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