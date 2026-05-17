/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase "Tiempo"
//
// Versión básica -mínima-
//
// Definiciones en: Tiempo.cpp
//
// Fichero: Tiempo.h
//
// FASE 0
//
/***************************************************************************/
/***************************************************************************/

#ifndef TIEMPO
#define TIEMPO

#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Clase Tiempo (¡¡sin filtros rigurosos!!)

class Tiempo {

private: 
	
	static const int SEGS_MIN  = 60; 
	static const int MINS_HORA = 60; 
	static const int SEGS_HORA = SEGS_MIN*MINS_HORA; 
	static const int CENTESIMAS_SEG = 100; 

			
	int horas;			// 0 <= horas 
	int minutos; 		// 0 <= minutos  < MINS_HORA
	int segundos; 		// 0 <= segundos < SEGS_MIN	
	int centesimas; 	// 0 <= centesimas < CENTESIMAS_SEG 
	
	/************************************************************************/
	/************************************************************************/
	// Calcula el número de centésimas de segundo de un dato "Tiempo". 
	// Devuelve: el número de centesimas de segundo del objeto implícito.
	
	long TiempoEnCentesimasSegundo (void);
	
	/***********************************************************************/
	/************************************************************************/

public: 

	/***********************************************************************/
	/***********************************************************************/
	// Constructor sin argumentos.
	// Compone un dato "Tiempo" con valor 00:00:00:00. 	
	
	Tiempo (void);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumento.
	// Compone un dato "Tiempo" a partir de un string. 
	// Parámetros: 	cad, la cadena de la que se extraen los campos.
	//
	// PRE: "cad" es correcta (el formato es hh:mm:ss:cc).
		
	Tiempo (string cad);
	
	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumentos.
	// Compone un dato "Tiempo" a partir de los valores recibidos. 	
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
			
	Tiempo (int las_horas, int los_minutos, int los_segundos, 
			int las_centesimas);
	  
	/***********************************************************************/
	// Métodos Get/Set

	int GetHoras      (void) const;
	int GetMinutos    (void) const;
	int GetSegundos   (void) const;
	int GetCentesimas (void) const;

	// PRE: 0 <= las_horas 
	// PRE: 0 <= los_minutos  < MINS_HORA
	// PRE: 0 <= los_segundos < SEGS_MIN
	// PRE: 0 <= las_centesimas < CENTESIMAS_SEG 	

	void SetHoras      (int las_horas);
	void SetMinutos    (int los_minutos); 
	void SetSegundos   (int los_segundos);
	void SetCentesimas (int las_centesimas);

	/***********************************************************************/
	/***********************************************************************/
	// Serializa un dato "Tiempo". 
	// 
	// Devuelve: la representación textual de un dato "Tiempo".  
	
	string ToString (void) const;

	/***********************************************************************/
 	/***********************************************************************/
                     
};

////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
