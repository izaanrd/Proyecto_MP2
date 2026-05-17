#ifndef ATLETAS
#define ATLETAS

#include <string>
#include "Atleta.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class Atletas {

private:

	Atleta *vector_privado;		// Vector de objetos "Atleta"
	int total_utilizados;		// Número de casillas ocupadas
	int capacidad;				// Número de casillas disponibles
	
	// Funciones para optimizar la gestión de memoria dinámica

	/************************************************************/
	// Pide memoria para poder guardar num elementos.
	// Parámetros: num, número de casillas reservadas (capacidad).
	// PRE: num_casillas >= 0

	void ReservarMemoria(int num_casillas);

	/************************************************************/
	// Libera memoria
	// POST: El número de casillas usadas es 0
	// El número de casillas reservadas es 0

	void LiberarMemoria();

	/************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo.
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos(const Atletas &otro);

public:

	//--------------------------------------------------//
	// Constructor sin argumentos.
	// Post: total_utilizados = 0 (la secuencia estará vacía)

	Atletas (void);

	Atletas(const Atletas &otro);		// Constructor de copia

	~Atletas();							// Destructor

	void Clona(const Atletas &otro);		// Método clona para realizar copia profunda

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

	Atleta Elemento (int pos) const;

	//--------------------------------------------------//
	// Añade un elemento ("nuevo") a la secuencia.
	// El nuevo elemento se coloca al final.

	void Aniade (const Atleta & nuevo);

	//--------------------------------------------------//
	// Inserta "nuevo" en la posición "pos".
	// Los elementos por encima se desplazan una posición a la derecha.

	void Inserta (int pos, const Atleta & nuevo);

	//--------------------------------------------------//
	// Elimina el elemento de la posición "pos".
	//
	// Precondiciones: 1 <= pos <= TotalUtilizados()

	void Elimina (int pos);

	// Serializa la secuencia.
	//
	// Devuelve: la representación textual de todos los atletas guardados.

	string ToString (void) const;

};

/////////////////////////////////////////////////////////////////////////////

#endif