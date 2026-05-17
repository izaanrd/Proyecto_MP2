#include <string>

#include "Pruebas.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// POST: total_utilizados = 0

Pruebas :: Pruebas (void) : total_utilizados(0)
{ }

//--------------------------------------------------//
// Devuelve el número de casillas ocupadas.

int Pruebas :: TotalUtilizados (void) const
{
	return total_utilizados;
}

//--------------------------------------------------//
// Devuelve el número de casillas disponibles.

int Pruebas :: Capacidad (void) const
{
	return TAMANIO;
}

//--------------------------------------------------//
// "Vacía" completamente la secuencia.
// POST: total_utilizados = 0

void Pruebas :: EliminaTodos (void)
{
	total_utilizados = 0;
}

//--------------------------------------------------//
// Devuelve el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

Prueba Pruebas :: Elemento (int pos) const
{
	return vector_privado[pos-1];
}

//--------------------------------------------------//
// Añade un elemento ("nuevo") a la secuencia.
// El nuevo elemento se coloca al final.
//
// Precondiciones: TotalUtilizados() < Capacidad()

void Pruebas :: Aniade (const Prueba & nuevo)
{
	if (total_utilizados < TAMANIO) {
		vector_privado[total_utilizados] = nuevo;
		total_utilizados++;
	}
}

//--------------------------------------------------//
// Inserta "nuevo" en la posición "pos".
// Los elementos por encima se desplazan una posición a la derecha.
//
// Precondiciones: TotalUtilizados() < Capacidad()
// Precondiciones: 1 <= pos <= TotalUtilizados()+1

void Pruebas :: Inserta (int pos, const Prueba & nuevo)
{
	int indice = pos - 1;

	if ((total_utilizados < TAMANIO) &&
	    (indice >= 0) && (indice <= total_utilizados)) {

		for (int i = total_utilizados; i > indice; i--)
			vector_privado[i] = vector_privado[i-1];

		vector_privado[indice] = nuevo;
		total_utilizados++;
	}
}

//--------------------------------------------------//
// Elimina el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

void Pruebas :: Elimina (int pos)
{
	int indice = pos - 1;

	if ((indice >= 0) && (indice < total_utilizados)) {

		for (int i = indice; i < total_utilizados - 1; i++)
			vector_privado[i] = vector_privado[i+1];

		total_utilizados--;
	}
}

//--------------------------------------------------//
// Serializa la secuencia.
//
// Devuelve: la representación textual de todas las pruebas guardadas.

string Pruebas :: ToString (void) const
{
	string cad;

	for (int i = 0; i < total_utilizados; i++) {
		if (i > 0)
			cad = cad + "\n";

		cad = cad + vector_privado[i].ToString();
	}

	return cad;
}