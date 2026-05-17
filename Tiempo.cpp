/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Definición de la clase "Tiempo"
//
// Versión básica -mínima-
//
// Declaraciones en: Tiempo.h
//
// Fichero: Tiempo.cpp
//
// FASE 0
//
/***************************************************************************/
/***************************************************************************/

#include <string>

#include "Tiempo.h"
#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor sin argumentos.
// Compone un dato "Tiempo" con valor 00:00:00:00. 	

Tiempo :: Tiempo (void) : horas(0), minutos(0), segundos(0), centesimas(0)
{ }

/***************************************************************************/
/***************************************************************************/
// Constructor con argumento.
// Compone un dato "Tiempo" a partir de un string. 
// Parámetros: 	cad, la cadena de la que se extraen los campos.
//
// PRE: "cad" es correcta (el formato es hh:mm:ss:cc).
	
Tiempo :: Tiempo (string cad)
{			
	horas      = stoi(cad.substr(0,2));	 
	minutos    = stoi(cad.substr(3,2));	 
	segundos   = stoi(cad.substr(6,2));	
	centesimas = stoi(cad.substr(9,2));	
}

/***************************************************************************/
/***************************************************************************/
// Constructor con argumentos.
// Compone un dato "Tiempo" a partir de los valorfes recibidos. 	
//
// Parámetros: 	las_horas, la hora a asignar.
//              los_minutos, los minutos a asignar.
//              los_segundos, los segundos a asignar.
//              las_centesimas, las centésimas a asignar.
//
// PRE: 0 <= las_horas, 
// PRE: 0 <= los_minutos < MINS_HORA, 
// PRE: 0 <= los_segundos < SEGS_MIN	
// PRE: 0 <= las_centesimas < CENTESIMAS_SEG 	

Tiempo :: Tiempo (int las_horas, int los_minutos, int los_segundos, 
				  int las_centesimas) : 
		  horas (las_horas), minutos(los_minutos), segundos(los_segundos),
		  centesimas(las_centesimas) 
{ }
  
/***************************************************************************/
/***************************************************************************/
// Métodos Get/Set

int Tiempo :: GetHoras    (void)   const { return horas;  }
int Tiempo :: GetMinutos  (void)   const { return minutos; }
int Tiempo :: GetSegundos (void)   const { return segundos; }
int Tiempo :: GetCentesimas (void) const { return centesimas; }

// PRE: 0 <= las_horas 
// PRE: 0 <= los_minutos  < MINS_HORA
// PRE: 0 <= los_segundos < SEGS_MIN
// PRE: 0 <= las_centesimas < CENTESIMAS_SEG 	

void Tiempo :: SetHoras      (int las_horas)     { horas = las_horas; }
void Tiempo :: SetMinutos    (int los_minutos)   { minutos = los_minutos; }
void Tiempo :: SetSegundos   (int los_segundos)  { segundos = los_segundos; }
void Tiempo :: SetCentesimas (int las_centesimas){ centesimas=las_centesimas; }

/***************************************************************************/
/***************************************************************************/
// Serializa un dato "Tiempo". 
// 
// Devuelve: la representación textual de un dato "Tiempo".  

string Tiempo :: ToString (void) const
{
	return (FormatInt(horas, 2, '0') + ":"+ 
	        FormatInt(minutos, 2, '0') + ":" + 
	        FormatInt(segundos, 2, '0') + ":" + 
	        FormatInt(centesimas, 2, '0'));
}

/***************************************************************************/
/***************************************************************************/
                 

/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/
// Calcula el número de centésimas de segundo de un dato "Tiempo". 
// Devuelve:  el número de centesimas de segundo del objeto implícito.

long Tiempo :: TiempoEnCentesimasSegundo (void)
{
	return ((horas*SEGS_HORA + minutos*SEGS_MIN + segundos) * CENTESIMAS_SEG);	
}

/***************************************************************************/
/***************************************************************************/
