/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase "Fecha"
//
// Versión básica -mínima-
//
// Definiciones en: Fecha.cpp
//
// Fichero: Fecha.h
//
// FASE 0
//
/***************************************************************************/
/***************************************************************************/

#ifndef FECHA
#define FECHA

#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Registro de fecha (¡¡sin filtros rigurosos!!)

class Fecha {

private: 

	int dia;	// 1 <= dia <= 31 
	int mes; 	// 1 <= mes <= 12
	int anio; 	// 1900 <= anio	

public : 

	/***********************************************************************/
	/***********************************************************************/
	// Constructor sin argumentos. 
	// Necesario para crear arrays o matrices u objetos que contengan "Fecha".
	// Compone un dato "Fecha" a partir de la fecha del sistema. 

	Fecha (void);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor directo. 
	// Parámetros: trivial. 
	// PRE: 1 <= el_dia <= 31 
	// PRE: 1 <= el_mes <= 12
	// PRE: 1900 <= el_anio	

	Fecha (int el_dia, int el_mes, int el_anio);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor desde un string.
	// Parámetros: cad, string con la fecha. 
	//
	// PRE: cad contiene una fecha CORRECTA en formato dd/mm/aaaa 
	// PRE: cad.length() == 10	

	Fecha (string cad);

	/***********************************************************************/
	// Métodos Get/Set

	int GetDia  (void) const;
	int GetMes  (void) const;
	int GetAnio (void) const;

	// PRE: 1 <= el_dia <= 31 
	// PRE: 1 <= el_mes <= 12
	// PRE: 1900 <= el_anio	
	void SetDia  (int el_dia);
	void SetMes  (int el_mes); 
	void SetAnio (int el_anio);
	
	/***********************************************************************/
	/***********************************************************************/
	// Serializa un dato "Fecha".
	//
	// Parámetros: corto, si es "true" el mes se presenta con 3 caracteres. 

	string ToString (bool corto=false) const; 

	/***********************************************************************/
	/***********************************************************************/
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
