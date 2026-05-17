/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// IZAN RODRÍGUEZ TERRÓN
// GRUPO B1
//
// Definición de la clase "SecuenciaClubes"
//
// Declaraciones en: SecuenciaClubes.h
//
// Fichero: SecuenciaClubes.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <string>
#include <cstring>
#include <iostream>

#include "Clubes.h"

using namespace std;

//--------------------------------------------------//
// Constructor sin argumentos.
// POST: total_utilizados = 0

Clubes :: Clubes (void) : total_utilizados(0)
{ }

//--------------------------------------------------//
// Devuelve el número de casillas ocupadas.

int Clubes :: TotalUtilizados (void) const
{
	return total_utilizados;
}

//--------------------------------------------------//
// Devuelve el número de casillas disponibles.

int Clubes :: Capacidad (void) const
{
	return TAMANIO;
}

//--------------------------------------------------//
// "Vacía" completamente la secuencia.
// POST: total_utilizados = 0

void Clubes :: EliminaTodos (void)
{
	total_utilizados = 0;
}

//--------------------------------------------------//
// Devuelve el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

Club Clubes :: Elemento (int pos) const
{
	return vector_privado[pos-1];
}

//--------------------------------------------------//
// Añade un elemento ("nuevo") a la secuencia.
// El nuevo elemento se coloca al final.
// Si no hay espacio, no se hace nada.
//
// Precondiciones: TotalUtilizados() < Capacidad()

void Clubes :: Aniade (const Club & nuevo)
{
	if (total_utilizados < TAMANIO) {
		vector_privado[total_utilizados] = nuevo;
		total_utilizados++;
	}
}

//--------------------------------------------------//
// Inserta "nuevo" en la posición "pos".
// Los elementos por encima se mueven una posición a la derecha.
//
// Precondiciones: TotalUtilizados() < Capacidad()
// Precondiciones: 1 <= pos <= TotalUtilizados()+1

void Clubes :: Inserta (int pos, const Club & nuevo)
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
// Los elementos por encima se desplazan una posición a la izquierda.
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

void Clubes :: Elimina (int pos)
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
// Devuelve: la representación textual de todos los clubes guardados.

string Clubes :: ToString (void) const
{
	string cad;

	for (int i = 0; i < total_utilizados; i++){
		if (i > 0)
    		cad = cad + "\n";

		cad = cad + vector_privado[i].ToString();
	}
	
	return cad;
}