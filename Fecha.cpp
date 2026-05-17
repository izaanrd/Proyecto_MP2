/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Definición de la clase "Fecha"
//
// Versión básica -mínima-
//
// Declaraciones en: Fecha.h
//
// Fichero: Fecha.cpp
//
// FASE 0
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Fecha.h"
#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor sin argumentos. 
// Necesario para crear arrays o matrices u objetos que contengan "Fecha".
// Compone un dato "Fecha" a partir de la fecha del sistema. 

Fecha :: Fecha (void) 
{
	time_t momento;  

	time (&momento); // Num. segundos desde 00:00, 1 Ene 1970 UTC

	// Puntero a un "struct tm" con fecha/hora local 
	tm * ahora = localtime(&momento);

	// Escribir en los campos desde los valores del struct "ahora"
	anio = 1900 + ahora->tm_year;
	mes = ahora->tm_mon+1;
	dia = ahora->tm_mday;
}

/***************************************************************************/
/***************************************************************************/
// Constructor directo. 
// Parámetros: trivial. 
// PRE: 1 <= el_dia <= 31 
// PRE: 1 <= el_mes <= 12
// PRE: 1900 <= el_anio	

Fecha :: Fecha (int el_dia, int el_mes, int el_anio) : 
         dia (el_dia), mes (el_mes), anio (el_anio)
{ }

/***************************************************************************/
/***************************************************************************/

// Constructor desde un string.
// Parámetros: cad, string con la fecha. 
//
// PRE: cad contiene una fecha CORRECTA en formato dd/mm/aaaa 
// PRE: cad.length() == 10	

Fecha :: Fecha (string cad)
{
	dia  = stoi(cad.substr(0,2));	 
	mes  = stoi(cad.substr(3,2));	  	
	anio = stoi(cad.substr(6,4));	 
}

/***************************************************************************/
/***************************************************************************/
// Métodos Get/Set

int Fecha :: GetDia  (void) const {	return dia;  }
int Fecha :: GetMes  (void) const {	return mes;  }
int Fecha :: GetAnio (void) const {	return anio; }

// PRE: 1 <= el_dia <= 31 
// PRE: 1 <= el_mes <= 12
// PRE: 1900 <= el_anio	
void Fecha :: SetDia  (int el_dia)  { dia = el_dia; }
void Fecha :: SetMes  (int el_mes)  { mes = el_mes; }
void Fecha :: SetAnio (int el_anio) { anio = el_anio; }

/***************************************************************************/
/***************************************************************************/
// Serializa un dato "Fecha".
//
// Parámetros: corto, si es "true" el mes se presenta con 3 caracteres. 

string Fecha :: ToString (bool corto) const
{
	const string MESES[] = {"Enero     ", "Febrero   ", "Marzo     ", 
							"Abril     ", "Mayo      ", "Junio     ", 
							"Julio     ", "Agosto    ", "Septiembre", 
							"Octubre   ", "Noviembre ", "Diciembre "};

	string str_mes = MESES[mes-1];
	if (corto) str_mes = str_mes.substr(0,3);

	string cad; 
	
	cad = cad + FormatInt(dia,  2, ' ') + " " + str_mes + " " + 
		        FormatInt(anio, 4, ' ');
		        
	return cad; 
}

/***************************************************************************/
/***************************************************************************/