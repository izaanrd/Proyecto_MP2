/***************************************************************************/
/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Fichero: utils.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef UTILS
#define UTILS

#include <string>

using namespace std;


/***************************************************************************/
/***************************************************************************/

enum class TipoAlineacion {Izquierda, Centro, Derecha}; 

// Terminador para cada campo.
const char DELIMITADOR = '*';

/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas 
// que contiene el valor textual de "entero".
// 
// Recibe: 	entero, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
//			relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual.  

string FormatInt (int entero, int num_casillas, char relleno=' '); 

//--------------------------------------------------//
// Función auxiliar "Trim" para eliminar (o no contar) los espacios al principio y final de cada campo.
//
// Parámetros: cad (el string que se va a "limpiar")
// Devuelve: el string sin espacios al principio ni al final.
//--------------------------------------------------//

string Trim (string cad);

/***************************************************************************/
/***************************************************************************/
// Convierte el dato double "real" a un string que contiene el valor 
// textual de "real" de acuerdo con el formato indicado según los 
// valores de "num_casillas" y "num_dec". Si hiciera falta, rellena 
// los huecos con "relleno".
//
// Parámetros: 
//		real, el valor double a transformar. 
//		num_casillas, número total de casillas que tendrá el resultado.
//		num_dec, número de casillas para la parte decimal del resultado.
//		relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.    
// 
// NOTAS: 
// 1) Si el número de casillas solicitado es mayor que el que se necesita, 
//	  se completa el inicio de la parte entera con relleno.
// 2) Si el número de decimales requerido es cero, NO se muestra el punto. 
//	  Si es mayor que el que se necesita se completa con ceros. 

string FormatDouble (double real, int num_casillas, int num_dec, 
                     char relleno=' ');

/***************************************************************************/
/***************************************************************************/
// Convierte el dato string "la_cadena" a un string con "num_casillas" 
// casillas rellenando con el caracter "relleno" por la izquierda.
// 
// Recibe: 	la_cadena, el valor a transformar.
//			num_casillas, número total de casillas que tendrá el resultado.
// 			alineacion, ajuste de "la_cadena" en el hueco disponible de 
//                "num_casillas".
//			relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual.  

string FormatString (string la_cadena, int num_casillas, 
	                 TipoAlineacion alineacion=TipoAlineacion::Izquierda, 
	                 char relleno=' '); 

/***************************************************************************/
/***************************************************************************/

#endif