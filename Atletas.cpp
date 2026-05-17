#include <string>
#include "Atletas.h"

using namespace std;

const int TAM_BLOQUE = 5;

/************************************************************/
// Pide memoria para poder guardar num elementos.
// Parámetros: num, número de casillas reservadas (capacidad).
// PRE: num_casillas >= 0

void Atletas::ReservarMemoria(int num_casillas)
{
	vector_privado = new Atleta[num_casillas];

	capacidad = num_casillas;

	total_utilizados = 0;
}

/************************************************************/
// Libera memoria
// POST: El número de casillas usadas es 0
// El número de casillas reservadas es 0

void Atletas::LiberarMemoria()
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

void Atletas::CopiarDatos(const Atletas &otro)
{
	total_utilizados = otro.total_utilizados;

	for (int i = 0; i < total_utilizados; i++)
		vector_privado[i] = otro.vector_privado[i];
}

//--------------------------------------------------//
// Constructor sin argumentos.
// POST: total_utilizados = 0

Atletas::Atletas(void)
{
	vector_privado = nullptr;

	total_utilizados = 0;

	capacidad = 0;
}

/************************************************************/
// Constructor de copia

Atletas::Atletas(const Atletas &otro)
{
	ReservarMemoria(otro.capacidad);

	CopiarDatos(otro);
}

/************************************************************/
// Destructor

Atletas::~Atletas()
{
	LiberarMemoria();
}

/************************************************************/
// Método Clona

void Atletas::Clona(const Atletas &otro)
{
	if (this != &otro) {

		LiberarMemoria();

		ReservarMemoria(otro.capacidad);

		CopiarDatos(otro);
	}
}

//--------------------------------------------------//
// Devuelve el número de casillas ocupadas.

int Atletas :: TotalUtilizados (void) const
{
	return total_utilizados;
}

//--------------------------------------------------//
// Devuelve el número de casillas reservadas.

int Atletas :: Capacidad (void) const
{
	return capacidad;
}

//--------------------------------------------------//
// "Vacía" completamente la secuencia.
// POST: total_utilizados = 0

void Atletas::EliminaTodos(void)
{
	LiberarMemoria();
}

//--------------------------------------------------//
// Devuelve el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

Atleta Atletas :: Elemento (int pos) const
{
	return vector_privado[pos-1];
}

//--------------------------------------------------//
// Añade un elemento ("nuevo") a la secuencia.
// El nuevo elemento se coloca al final.

void Atletas::Aniade(const Atleta &nuevo)
{
	if (total_utilizados == capacidad) {

		Atleta *temp = vector_privado;							// Guardamos el vector actual en un temporal

		vector_privado = new Atleta[capacidad + TAM_BLOQUE];	// Creamos un nuevo vector con más capacidad

		for (int i = 0; i < total_utilizados; i++){				// Copiamos los datos del vector antiguo al nuevo
	
			vector_privado[i] = temp[i];
		}
		delete [] temp;											// Liberamos la memoria del vector antiguo	

		capacidad += TAM_BLOQUE;								// Actualizamos la capacidad
	}

	vector_privado[total_utilizados] = nuevo;					// Añadimos el nuevo elemento al final del vector

	total_utilizados++;											// Actualizamos el número de elementos utilizados
}

//--------------------------------------------------//
// Inserta "nuevo" en la posición "pos".
// Los elementos por encima se desplazan una posición a la derecha.

void Atletas::Inserta(int pos, const Atleta &nuevo)
{
	int indice = pos - 1;									// Convertimos la posición a índice

	if ((indice >= 0) && (indice <= total_utilizados)) {	// Si el índice es válido...

		if (total_utilizados == capacidad) {				// Si el vector está lleno, necesitamos aumentar su capacidad

			Atleta *temp = vector_privado;

			vector_privado = new Atleta[capacidad + TAM_BLOQUE];

			for (int i = 0; i < total_utilizados; i++)
				vector_privado[i] = temp[i];

			delete [] temp;

			capacidad += TAM_BLOQUE;
		}

		for (int i = total_utilizados; i > indice; i--){		// Desplazamos los elementos una posición a la derecha
			vector_privado[i] = vector_privado[i-1];

		}
		vector_privado[indice] = nuevo;							// Insertamos el nuevo elemento en la posición indicada

		total_utilizados++;
	}
}

//--------------------------------------------------//
// Elimina el elemento de la posición "pos".
//
// Precondiciones: 1 <= pos <= TotalUtilizados()

void Atletas::Elimina(int pos)
{
	int indice = pos - 1;

	if ((indice >= 0) && (indice < total_utilizados)) {

		for (int i = indice; i < total_utilizados - 1; i++){		// Desplazamos los elementos una posición a la izquierda
			vector_privado[i] = vector_privado[i+1];

		}

		total_utilizados--;

		if (total_utilizados < capacidad) {				// Si el número de elementos utilizados es menor que la capacidad, reducimos el tamaño

			if (total_utilizados == 0) {

				LiberarMemoria();
			}
			else {										

				Atleta *temp = vector_privado;

				vector_privado = new Atleta[total_utilizados];

				for (int i = 0; i < total_utilizados; i++){
					vector_privado[i] = temp[i];
				}

				delete [] temp;

				capacidad = total_utilizados;
			}
		}
	}
}

// Serializa la secuencia.
//
// Devuelve: la representación textual de todos los atletas guardados.


string Atletas :: ToString (void) const
{
	string cad;

	for (int i = 0; i < total_utilizados; i++) {
		if (i > 0)
			cad = cad + "\n";

		cad = cad + vector_privado[i].ToString();
	}

	return cad;
}