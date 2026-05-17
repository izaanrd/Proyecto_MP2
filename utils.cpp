/***************************************************************************/
/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Fichero: utils.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Funciones "privadas" 

double Redondea (double real, int num_decimales);

/***************************************************************************/
/***************************************************************************/
// Convierte el dato int "entero" a un string con "num_casillas" casillas 
// que contiene el valor textual de "entero".
// 
// Parámetros: entero, el valor a transformar.
//			   num_casillas, número total de casillas que tendrá el resultado.
//			   relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual.  

string FormatInt (int entero, int num_casillas, char relleno)
{
	// Inicialmente nos quedamos con el resultado de to_string
	string cadena = to_string(entero);

	int long_cadena = (int) cadena.length(); 
	
	// Si es preciso se completa (por la izquierda) con "relleno"
	
	if (long_cadena < num_casillas) {
		
		int num_casillas_faltan = num_casillas-long_cadena; 
		
		for (int i=0; i<num_casillas_faltan; i++) 
			cadena = relleno + cadena; 
	}

	return cadena;
}

//--------------------------------------------------//
// Función auxiliar "Trim" para eliminar (o no contar) los espacios al principio y final de cada campo.
//
// Parámetros: cad (el string que se va a "limpiar")
// Devuelve: el string sin espacios al principio ni al final.
//--------------------------------------------------//

string Trim (string cad){

    int longitud = cad.length();

    // Eliminar los espacios del principio
    while (longitud > 0 && cad[0] == ' '){
        cad = cad.substr(1);
        longitud--;
    }

    // Eliminar espacios al final
    while (longitud > 0 && cad[longitud-1] == ' '){
        cad = cad.substr(0, longitud-1);
        longitud--;
    }

    return cad;
}
	
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

string FormatDouble (double real, int num_casillas, int num_dec, char relleno)
{
	double real_redondeado = Redondea (real, num_dec);
	
	// Actualizar el campo "cadena" para trabajar sobre él.
	string cadena = to_string(real_redondeado);
	
	// Eliminar los '0' finales (si los hubiera)
	while (cadena.length()>0 && cadena.back() == '0')
		cadena.pop_back();

	// Si no queremos decimales
	
	if (num_dec==0) {
		
		cadena.pop_back();	// Borrar el punto
		
		int long_cadena = (int) cadena.length(); 
	   	
		// Rellenar parte entera
		int digitos_enteros_faltan = num_casillas-long_cadena;
		for (int i=0; i<digitos_enteros_faltan; i++) 
			cadena = relleno + cadena; 	 	
	}
	else { // Queremos decimales 

		int long_cadena = (int) cadena.length(); 
			
		if (long_cadena < num_casillas) {
			
			// Se calcula la longitud de las partes entera y decimal
			// La referencia es el punto (¡¡SIEMPRE ESTÁ!!)
			
			int pos_punto = cadena.find ('.');  
			int long_parte_entera = pos_punto; 
			int long_parte_decimal = long_cadena-pos_punto-1;
			
			// Rellenar parte decimal con ceros
			int digitos_decimales_faltan = num_dec - long_parte_decimal;
			for (int i=0; i<digitos_decimales_faltan; i++) 
				cadena += '0';
	
			// Rellenar parte entera con relleno
			int digitos_enteros = num_casillas-num_dec-1;
			int digitos_enteros_faltan = digitos_enteros-long_parte_entera;
			
			for (int i=0; i<digitos_enteros_faltan; i++) 
				cadena = relleno + cadena; 	 
		}		
	}
	return cadena;
}

/***************************************************************************/
/***************************************************************************/
// Convierte el dato string "la_cadena" a un string con "num_casillas" 
// casillas rellenando con el caracter "relleno".
// 
// Parámetros: la_cadena, el valor a transformar.
//			      num_casillas, número total de casillas que tendrá el resultado.
// 			   alineacion, ajuste de "la_cadena" en el hueco disponible de 
//                "num_casillas".
//			   relleno, el carácter que se emplea para rellenar los huecos. 
// Devuelve: el string compuesto.  
//
// NOTAS: Si el número de casillas solicitado es mayor que el que se necesita, 
//	  	se completa al principio con "relleno" hasta alcanzar un tamaño de 
//	  	"num_casillas". Si el valor tuviera "per se" más de "num_casillas" 
//		se devuelve tal cual. 

string FormatString (string la_cadena, int num_casillas,  
	                 TipoAlineacion alineacion, char relleno)
{
	string cadena = la_cadena;

	string cad_relleno; 
	cad_relleno.push_back(relleno); 

	int long_cadena = (int) la_cadena.length(); 
	
	// Si es preciso se completa (por la izquierda) con "relleno"
	
	if (long_cadena < num_casillas) {
		
		int num_casillas_faltan = num_casillas-long_cadena; 
		
        switch (alineacion) {

        	case (TipoAlineacion::Izquierda) : 
        	{
				for (int i=0; i<num_casillas_faltan; i++) 
					cadena = cadena + cad_relleno; 

        		break; 
        	}
        	case (TipoAlineacion::Centro) : 
        	{
        	    int num_casillas_izda = num_casillas_faltan/2;
				int num_casillas_dcha = num_casillas - num_casillas_izda 
				                                     - long_cadena;

				for (int i=0; i<num_casillas_izda; i++) 
					cadena = cad_relleno + cadena; 

				for (int i=0; i<num_casillas_dcha; i++) 
					cadena = cadena + cad_relleno; 

        		break; 
        	}
        	case (TipoAlineacion::Derecha) : 
        	{
				for (int i=0; i<num_casillas_faltan; i++) 
					cadena = cad_relleno + cadena; 

        		break; 
        	}
        }
	}

	return cadena;
}

/***************************************************************************/
/***************************************************************************/
// Función que calcula la potencia x^n
// 		x^n = x * x * ... * x si n > 0
// 		x^n = 1 / (x * x * ... * x) si n < 0
//		x^0 = 1
// Parámetros: 
//		x: base
//		n: exponente
// Devuelve: x^n (potencia n-ésima de x)
//
// PRE: Si x==0, entonces n!=0
	
double Potencia (double base, int exponente)
{
	double potencia;	// El dato local "potencia" no debe confundirse 
						// con la función "Potencia"	
	double abs_exponente = fabs(exponente);

	potencia = 1.0;
	for (int i = 1; i <= abs_exponente; i++) potencia = potencia * base;
	if (exponente < 0) potencia = 1 / potencia;
	
	return potencia;	
}

/***************************************************************************/
/***************************************************************************/
// Redondea el número "real" a "num_decimales" decimales.
//
// Parámetros: 
//		real, el valor que se va a redondear.
//		num_decimales, el númerode decimales que se desea.
// Devuelve: 
//		El número "real" redondeado a la "num_decimales" cifra.

double Redondea (double real, int num_decimales)
{
   long long potencia_10 = Potencia(10, num_decimales);
   double nuevo_num = ((int) (round (real * potencia_10)));
   double real_redondeado = nuevo_num / potencia_10;

   return (real_redondeado);
}	
	
/***************************************************************************/
/***************************************************************************/

