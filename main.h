#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*define lenguaje*/
#define ESPANOL

#ifdef ESPANOL
#include "espanol.h"
#endif

#ifdef ENGLISH
#include "english.h"
#endif

#ifdef FRANCAIS
#include "francais.h"
#endif



/*Parametros de usuario_t*/
#define LENGTH_MAX_NOMBRE 50
#define LENGTH_MAX_CARRERAS 12
#define LENGTH_MAX_NOMBRE_CARRERAS 30
#define LENGTH_MAX_ASIGNATURA 30
#define NUMERO_MAX_ASIGNATURAS 10

/*Tipos de clasificacion de variables personales*/

typedef enum
{
  MAIN_MENU, MENU_REGISTRO = MAIN_OPCION_1_CHAR, MENU_ASIGNATURAS = MAIN_OPCION_2_CHAR, MENU_METRICA = MAIN_OPCION_3_CHAR, MENU_FINALIZAR = MAIN_OPCION_FINALIZAR_CHAR, MAIN_SALIR = MAIN_OPCION_SALIR_CHAR
} estado_main;


/* Estructura de datos */

typedef struct
{
  char nombre[LENGTH_MAX_NOMBRE];
	char apellido[LENGTH_MAX_NOMBRE];
	int padron;
  int num_carrera;
  char asignaturas[NUMERO_MAX_ASIGNATURAS][LENGTH_MAX_ASIGNATURA];
  int notas[NUMERO_MAX_ASIGNATURAS];
}usuario_t;


/*funcionnes del main*/
usuario_t reinit(usuario_t);
void clear_buffer(void);
void imprimir_carrera(int fila, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);

usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);
usuario_t asignaturas(usuario_t);
usuario_t metrica(usuario_t);
usuario_t finalizar(usuario_t);


/*funcionnes de registro*/


/*funcionnes de asignaturas*/


/*funcionnes de metrica*/


#endif
