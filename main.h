#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*define lenguaje*/
#define FRANCAIS

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
#define LENGTH_MAX_ASIGNATURA 30
#define NUMERO_MAX_ASIGNATURAS 10

/* Otros parametros */
#define MAX_TRY 3
#define LENGTH_MAX_CARRERAS 12
#define LENGTH_MAX_NOMBRE_CARRERAS 35

#define OUT 0
#define IN 1

#define MAX_CALIF 10
#define MIN_CANLIF 0
#define CANTIDAD_INTENTOS 3
#define ASCII_CERO 48
#define UNO 1

/*Tipos de clasificacion de variables personales*/

typedef enum
{
  MAIN_MENU, MENU_REGISTRO = MAIN_OPCION_1_CHAR, MENU_ASIGNATURAS = MAIN_OPCION_2_CHAR, MENU_METRICA = MAIN_OPCION_3_CHAR, MENU_FINALIZAR = MAIN_OPCION_FINALIZAR_CHAR, MAIN_SALIR = MAIN_OPCION_SALIR_CHAR
} estado_main;


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
usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);
usuario_t asignaturas(usuario_t usuario);
usuario_t metrica(usuario_t);
usuario_t finalizar(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);


/*funcionnes de registro*/
void imprimir_carrera(int fila, char carrera[][LENGTH_MAX_NOMBRE_CARRERAS]);

/*funcionnes de asignaturas*/
void print_opciones(char materia[][LENGTH_MAX_ASIGNATURA],int nota[], int COLUMNA_IMP, int CANT);
void clear_notas(int nota[], int FILA_NOT);
void clear_materias(char materia[][LENGTH_MAX_ASIGNATURA], int FILA_MAT, int COLUM_MAT);
void clear_regrab(char m[][LENGTH_MAX_ASIGNATURA], int COLUMNA_BORR, int FILA_BORR);

/*funcionnes y tipos de metrica*/
typedef enum
{
	MAIN_METRICA, PROMEDIO = METRICA_OPCION_PROMEDIO_CHAR, MAXIMO = METRICA_OPCION_MAXIMO_CHAR, MINIMO = METRICA_OPCION_MINIMO_CHAR, CANTIDAD = METRICA_OPCION_CANTIDAD_CHAR, APLAZOS = METRICA_OPCION_APLAZOS_CHAR, VOLVER = METRICA_OPCION_VOLVER_CHAR
}estado_metrica;

float promedio(usuario_t, int);
int cantidad(usuario_t);
int maximo(usuario_t, int);
int minimo(usuario_t, int);
int aplazos(usuario_t, int);

#endif
