#ifndef FUNCIONES__H
#define FUNCIONES__H

/*define lenguaje*/
#define ENGLISH

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


#define MAX_CALIF 10
#define MIN_CANLIF 0
#define ASCII_CERO 48

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
char menu_principal(int *tentativa);
void imprimir_menu_principal(void);
usuario_t reinit(usuario_t);
void clear_buffer(void);
usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);
usuario_t asignaturas(usuario_t usuario);
usuario_t metrica(usuario_t);
usuario_t finalizar(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]);

/*funciones de menu*/
char menu(estado_main, int *tentativa, usuario_t usuario);
void imprimir_menu_principal(void);
void imprimir_menu_registro(void);
void imprimir_menu_asignaturas(usuario_t usuario);
void imprimir_menu_metrica(void);

/*funcionnes y tipos de registro*/
typedef enum
{
	MAIN_REGISTRO, NOMBRE = REGISTRO_OPCION_NOMBRE_CHAR, PADRON = REGISTRO_OPCION_PADRON_CHAR, CARRERA = REGISTRO_OPCION_CARRERA_CHAR, VOLVER_R = REGISTRO_OPCION_VOLVER_CHAR
}estado_registro;

void imprimir_carrera_aviso(int fila, char carrera[][LENGTH_MAX_NOMBRE_CARRERAS]);
void imprimir_carrera_fin(int fila, char carrera[][LENGTH_MAX_NOMBRE_CARRERAS]);

/*funcionnes y tipos de asignaturas*/
typedef enum
{
	MAIN_ASIGNATURA, AGRAGAR = ASIGNATURA_OPCION_INGRESO_CHAR, ELIMINAR = ASIGNATURA_OPCION_BORRAR_CHAR, VOLVER_A = ASIGNATURA_OPCION_SALIDA_CHAR
}estado_asignatura;

usuario_t agregar(usuario_t usuario, int cantidadAsignaturas);
usuario_t eliminar(usuario_t usuario, int cantidadAsignaturas);
usuario_t modificar(usuario_t usuario, int numero);
void print_opciones(usuario_t usuario, int columna_IMP, int CANT);
void clear_materias(char materia[][LENGTH_MAX_ASIGNATURA], int FILA_MAT, int COLUM_MAT);
void clear_regrab(char m[][LENGTH_MAX_ASIGNATURA], int COLUMNA_BORR, int FILA_BORR);

/*funcionnes y tipos de metrica*/
typedef enum
{
	MAIN_METRICA, PROMEDIO = METRICA_OPCION_PROMEDIO_CHAR, MAXIMO = METRICA_OPCION_MAXIMO_CHAR, MINIMO = METRICA_OPCION_MINIMO_CHAR, CANTIDAD = METRICA_OPCION_CANTIDAD_CHAR, APLAZOS = METRICA_OPCION_APLAZOS_CHAR, VOLVER_M = METRICA_OPCION_VOLVER_CHAR
}estado_metrica;

float promedio(usuario_t, int);
int cantidad(usuario_t);
int maximo(usuario_t, int);
int minimo(usuario_t, int);
int aplazos(usuario_t, int);

#endif
