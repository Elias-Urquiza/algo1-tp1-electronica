#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* hacer un idioma.h para cada lenguaje */
#define MSJ_BIENVENIDA "¡Bienvenido!"
#define MSJ_MAIN "Elija una opcion pulsando el número indicado al lado."
#define MSJ_DESPEDIDA "¡Hasta Luego!"

#define MAIN_OPCION_1 "Registro Personal"
#define MAIN_OPCION_2 "Asignaturas"
#define MAIN_OPCION_3 "Métricas"
#define MAIN_OPCION_4 "Finalizar"
#define MAIN_OPCION_SALIR "Salir"

#define ERR_PREFIJO "ERROR"
#define ERR_OPCIONES "Opción ingresada no válida."

/*Tipos de clasificacion de variables personales*/

typedef enum {MAIN_MENU, MENU_REGISTRO, MENU_ASIGNATURAS, MENU_METRICAS, MENU_FINALIZAR, MAIN_SALIR} estado_main;

#endif
