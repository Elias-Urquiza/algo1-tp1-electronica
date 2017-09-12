#ifndef MAIN__H
#define MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* hacer un idioma.h para cada lenguaje */
/*Menu Principal y Mensajes comunes*/

#define MSJ_BIENVENIDA "¡Bienvenido!"
#define MSJ_MAIN "Elija una opcion pulsando el número indicado al lado."
#define MSJ_DESPEDIDA "¡Hasta Luego!"

#define MAIN_OPCION_1 "Registro Personal"
#define MAIN_OPCION_2 "Asignaturas"
#define MAIN_OPCION_3 "Métricas"
#define MAIN_OPCION_4 "Finalizar"
#define MAIN_OPCION_SALIR "Salir"

#define OPCION_VOLVER "Volver"

/*Registro*/
#define MSJ_REGISTRO "Menu Registro. Elija una opción para modificar los datos ingresados."
#define REGISTRO_OPCION_NOMBRE "Apellido y Nombre"
#define REGISTRO_OPCION_PADRON "Padrón"
#define REGISTRO_OPCION_CARRERA "Carrera"

#define REGISTRO_ING_APELLIDO "Ingrese Apellido"
#define REGISTRO_ING_NOMBRE "Ingrese Nombre"
#define REGISTRO_ING_PADRON "Ingrese su padrón"
#define REGISTRO_ING_CARRERA "Ingrese el número correspondiente a su carrera"

#define REGISTRO_ING_AVISO "Queda registrado lo siguiente"

/*Ingenierias*/

#define ING_1 "Ingeniería Civil"
#define ING_2 "Ingeniería Industrial"
#define ING_3 "Ingeniería Naval y Mecánica"
#define ING_4 "Ingeniería en Agrimensura"
#define ING_5 "Ingeniería Mecánica"
#define ING_6 "Ingeniería Electricista"
#define ING_7 "Ingeniería Electrónica"
#define ING_8 "Ingeniería Química"
#define ING_9 "Lic. en Análisis de Sistemas"
#define ING_10 "Ingeniería en Informática"
#define ING_11 "Ingeniería en Alimentos"

/*Errores*/

#define ERR_PREFIJO "ERROR"
#define ERR_OPCIONES "Opción ingresada no válida."

#define ERR_REG_NOMBRE "No se pudo leer el nombre ingresado."
#define ERR_REG_PADRON "El padrón ingresado no se pudo leer."
#define ERR_REG_CARRERA "El número de carrera ingresado no es válido."


/*Tipos de clasificacion de variables personales*/

typedef enum {MAIN_MENU, MENU_REGISTRO, MENU_ASIGNATURAS, MENU_METRICAS, MENU_FINALIZAR, MAIN_SALIR} estado_main;

#endif
