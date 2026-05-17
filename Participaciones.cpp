#include <string>
#include "Participaciones.h"

using namespace std;

const int TAM_BLOQUE = 5;

/************************************************************/
// Pide memoria para poder guardar num elementos.
// Parámetros: num, número de casillas reservadas (capacidad).
// PRE: num_casillas >= 0

void Participaciones::ReservarMemoria(int num_casillas)
{
	vector_privado = new Inscripcion[num_casillas];

	capacidad = num_casillas;

	total_utilizados = 0;
}

/************************************************************/
// Libera memoria
// POST: El número de casillas usadas es 0
// El número de casillas reservadas es 0

void Participaciones::LiberarMemoria()
{
	if (vector_privado != nullptr)
		delete [] vector_privado;

	vector_privado = nullptr;

	total_utilizados = 0;

	capacidad = 0;
}

/************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo.
// PRE: Se ha reservado memoria para los datos

void Participaciones::CopiarDatos(const Participaciones &otro)
{
	total_utilizados = otro.total_utilizados;

	for (int i = 0; i < total_utilizados; i++)
		vector_privado[i] = otro.vector_privado[i];
}

//--------------------------------------------------//
// Constructor sin argumentos.
// POST: total_utilizados = 0

Participaciones::Participaciones(void)
{
	vector_privado = nullptr;

	total_utilizados = 0;

	capacidad = 0;
}

/************************************************************/
// Constructor de copia

Participaciones::Participaciones(const Participaciones &otro)
{
	ReservarMemoria(otro.capacidad);

	CopiarDatos(otro);
}

/************************************************************/
// Destructor

Participaciones::~Participaciones()
{
	LiberarMemoria();
}

/************************************************************/
// Método Clona

void Participaciones::Clona(const Participaciones &otro)
{
	if (this != &otro) {

		LiberarMemoria();

		ReservarMemoria(otro.capacidad);

		CopiarDatos(otro);
	}
}

//--------------------------------------------------//
// Devuelve el número de casillas ocupadas.

int Participaciones :: TotalUtilizados (void) const
{
	return total_utilizados;
}

//--------------------------------------------------//
// Devuelve el número de casillas reservadas.

int Participaciones :: Capacidad (void) const
{
	return capacidad;
}

//--------------------------------------------------//
// "Vacía" completamente la secuencia.
// POST: total_utilizados = 0

void Participaciones::EliminaTodos(void)
{
	LiberarMemoria();
}

//--------------------------------------------------//
// Devuelve el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

Inscripcion Participaciones :: Elemento (int pos) const
{
	return vector_privado[pos-1];
}

//--------------------------------------------------//
// Añade un elemento ("nuevo") a la secuencia.
// El nuevo elemento se coloca al final.

void Participaciones::Aniade(const Inscripcion &nuevo)
{
	if (total_utilizados == capacidad) {

		Inscripcion *temp = vector_privado;

		vector_privado = new Inscripcion[capacidad + TAM_BLOQUE];

		for (int i = 0; i < total_utilizados; i++){

			vector_privado[i] = temp[i];
		}

		delete [] temp;

		capacidad += TAM_BLOQUE;
	}

	vector_privado[total_utilizados] = nuevo;

	total_utilizados++;
}

//--------------------------------------------------//
// Inserta "nuevo" en la posición "pos".
// Los elementos por encima se desplazan una posición a la derecha.

void Participaciones::Inserta(int pos, const Inscripcion &nuevo)
{
	int indice = pos - 1;

	if ((indice >= 0) && (indice <= total_utilizados)) {

		if (total_utilizados == capacidad) {

			Inscripcion *temp = vector_privado;

			vector_privado = new Inscripcion[capacidad + TAM_BLOQUE];

			for (int i = 0; i < total_utilizados; i++)
				vector_privado[i] = temp[i];

			delete [] temp;

			capacidad += TAM_BLOQUE;
		}

		for (int i = total_utilizados; i > indice; i--){

			vector_privado[i] = vector_privado[i-1];
		}

		vector_privado[indice] = nuevo;

		total_utilizados++;
	}
}

//--------------------------------------------------//
// Elimina el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

void Participaciones::Elimina(int pos)
{
	int indice = pos - 1;

	if ((indice >= 0) && (indice < total_utilizados)) {

		for (int i = indice; i < total_utilizados - 1; i++){

			vector_privado[i] = vector_privado[i+1];
		}

		total_utilizados--;

		if (total_utilizados < capacidad) {

			if (total_utilizados == 0) {

				LiberarMemoria();
			}
			else {

				Inscripcion *temp = vector_privado;

				vector_privado = new Inscripcion[total_utilizados];

				for (int i = 0; i < total_utilizados; i++){

					vector_privado[i] = temp[i];
				}

				delete [] temp;

				capacidad = total_utilizados;
			}
		}
	}
}

//--------------------------------------------------//
// Serializa la secuencia.
//
// Devuelve: la representación textual de todas las
// inscripciones guardadas.

string Participaciones :: ToString (void) const
{
	string cad;

	for (int i = 0; i < total_utilizados; i++) {

		if (i > 0)
			cad = cad + "\n";

		cad = cad + vector_privado[i].ToString();
	}

	return cad;
}