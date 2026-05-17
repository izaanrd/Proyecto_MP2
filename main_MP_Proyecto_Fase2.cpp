/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase1.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 1. 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "utils.h"

#include "Fecha.h"
#include "Tiempo.h"

#include "Atleta.h"
#include "Club.h"
#include "Prueba.h"
#include "Marca.h"
#include "Inscripcion.h"

#include "Atletas.h"
#include "Clubes.h"
#include "Pruebas.h"
#include "Participaciones.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";


	// Cada linea del fichero se lee en un dato string. 
	string linea;

	// Contadores
	int cont_atletas = 0;
	int cont_clubes = 0;
	int cont_pruebas = 0;
	int cont_inscripciones = 0;

	cout << Cabecera ("LECTURA DE DATOS");

	cout << endl; 
	cout << "Hoy es " << Fecha().ToString(true) << endl; 
	cout << endl; 



	// ATLETAS

	Atletas los_atletas; 

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_atletas++; // Un atleta más (no se leyó TERMINADOR)	
			
		Atleta un_atleta (linea);

		cout << un_atleta.ToString() << endl; 

		// Añadir a la secuencia "los_atletas"
		los_atletas.Aniade (un_atleta);

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl; 
	cout << "Total atletas leidos = "<< setw(3) << cont_atletas << endl; 
	cout << endl; 



	// CLUBES

	Clubes los_clubes; 

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_clubes++; // Un Club más (no se leyó TERMINADOR)	
			
		Club un_club (linea);

		cout << un_club.ToString() << endl; 

		// Añadir a la secuencia "los_clubes"
		los_clubes.Aniade (un_club);

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl; 
	cout << "Total clubes leidos = "<< setw(3) << cont_clubes << endl; 
	cout << endl; 



	// PRUEBAS

	Pruebas las_pruebas; 

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_pruebas++; // Una prueba más (no se leyó TERMINADOR)	
			
		Prueba una_prueba (linea);

		cout << una_prueba.ToString() << endl; 

		// Añadir a la secuencia "las_pruebas"
		las_pruebas.Aniade (una_prueba);

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl; 
	cout << "Total pruebas leidas = "<< setw(3) << cont_pruebas << endl; 
	cout << endl; 



	// INSCRIPCIONES

	Participaciones las_inscripciones; 

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_inscripciones++; // Una inscripción más (no se leyó TERMINADOR)	
			
		Inscripcion una_inscripcion (linea);

		cout << una_inscripcion.ToString() << endl; 

		// Añadir a la secuencia "las_inscripciones"
		las_inscripciones.Aniade (una_inscripcion);

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)

	cout << endl; 
	cout << "Total inscripciones leidas = "
	     << setw(3) << cont_inscripciones << endl; 
	cout << endl; 

	/************************************************************************/

	// los_atletas.Ordena(); 

	cout << Cabecera ("ATLETAS:");
	cout << los_atletas.ToString() << endl; 
	cout << "Total atletas guardados = "<< setw(3) 
	     << los_atletas.TotalUtilizados() << endl; 
	cout << endl; 

	cout << Cabecera ("CLUBES:");
	cout << los_clubes.ToString() << endl; 
	cout << "Total clubes guardados = "<< setw(3) 
	     << los_clubes.TotalUtilizados() << endl; 
	cout << endl; 

	cout << Cabecera ("PRUEBAS:");
	cout << las_pruebas.ToString() << endl; 
	cout << "Total pruebas guardadas = "<< setw(3) 
	     << las_pruebas.TotalUtilizados() << endl; 
	cout << endl; 

	cout << Cabecera ("INSCRIPCIONES:");
	cout << las_inscripciones.ToString() << endl; 
	cout << "Total inscripciones guardadas = "<< setw(3) 
	     << las_inscripciones.TotalUtilizados() << endl; 
	cout << endl; 

	/************************************************************************/

	return 0;
}

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 81; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}

/***************************************************************************/
/***************************************************************************/
