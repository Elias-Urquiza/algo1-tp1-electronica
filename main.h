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
#define LENGTH_MAX_ASIGNATURA 30
#define NUMERO_MAX_ASIGNATURAS 10


/*Tipos de clasificacion de variables personales*/

typedef enum
{
  MAIN_MENU, MENU_REGISTRO = MAIN_OPCION_1_CHAR, MENU_ASIGNATURAS = MAIN_OPCION_2_CHAR, MENU_OTROS = MAIN_OPCION_3_CHAR, MAIN_SALIR = MAIN_OPCION_SALIR_CHAR
} estado_main;


typedef enum {
  VOLVER, REG_NOMBRE, REG_PADRON, REG_CARRERA, ASIGN_ING, ASIGN_MODIF
} estado_opciones; /*a desarrollar*/



typedef struct
{
  char nombre[LENGTH_MAX_NOMBRE];
  int padron;
  int carrera;
  char asignaturas[NUMERO_MAX_ASIGNATURAS][LENGTH_MAX_ASIGNATURA];
  int notas[NUMERO_MAX_ASIGNATURAS];
}usuario_t;


usuario_t reinit(usuario_t);
void clear_buffer(void);

usuario_t registro(usuario_t);
usuario_t asignaturas(usuario_t);
usuario_t otros(usuario_t);



#endif
