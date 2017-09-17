#ifndef ESPANOL__H
#define ESPANOL__H


/* MSJ global */
#define MSJ_BIENVENIDA "¡Bienvenido!"
#define MSJ_MAIN "Elija que desea hacer:"

/*Errores*/
#define ERR_PREFIJO "ERROR"
#define ERR_OPCIONES "Opción ingresada no válida, intenta de nuevo: "

#define ERR_INGRESO_MATERIA "La asignatura fue mal ingresada."
#define ERR_INGRESO_NOTA "La nota fue mal ingresada."
#define ERR_INGRESO_CONT_NOTA "La nota fue mal ingresada, por favor vuelva a intentar: "
#define ERR_REINGRESO_CONT_NOTA "La rescritura de la materia fue de manera incorrecta"
#define ERR_ELEC "La eleccion realizada no esta permitida."
#define ERR_MAX_NOTA "Se a llegado a la maxima cantidad de asignaturas ingresada."

#define ERR_REG_NOMBRE "No se pudo leer el nombre ingresado."
#define ERR_REG_PADRON "El padrón ingresado no se pudo leer."
#define ERR_REG_CARRERA "Número de Carrera Inválido."

/* MSJ main */
#define MAIN_OPCION_1 "Registro Personal"
#define MAIN_OPCION_1_CHAR 'R'
#define MAIN_OPCION_2 "Asignaturas"
#define MAIN_OPCION_2_CHAR 'A'
#define MAIN_OPCION_3 "Calcular métrica individual"
#define MAIN_OPCION_3_CHAR 'M'
#define MAIN_OPCION_FINALIZAR "Finalizar"
#define MAIN_OPCION_FINALIZAR_CHAR '!'
#define MAIN_OPCION_SALIR "Salir"
#define MAIN_OPCION_SALIR_CHAR '0'

/*Carreras*/
#define ING_0 "Ninguna Carrera Seleccionada"
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


/* MSJ asignatura */
#define ASIGNATURA_OPCION_INGRESO "+) Ingreso de asignatura."
#define ASIGNATURA_OPCION_SALIDA "!) Salir."
#define ASIGNATURA_OPCION_BORRAR "-) Eliminar una asignatura."
#define ASIGNATURA_OPCION_PREGUNTA "? "
#define TEXT_NOTA "Ingrese la nota: "
#define TEXT_MATERIA "Ingrese la asignatura: "
#define TEXT_ELEC_BORRAR "Ingrese el numero de asignatura que desea borrar: "

#define AGREGAR '+'
#define ELIMINAR '-'
#define SALIR '!'


/* MSJ registro */
#define MSJ_REGISTRO "Menu Registro. Elija una opción para modificar los datos ingresados."
#define REGISTRO_OPCION_NOMBRE "Apellido y Nombre"
#define REGISTRO_OPCION_NOMBRE_CHAR 'A'
#define REGISTRO_OPCION_PADRON "Padrón"
#define REGISTRO_OPCION_PADRON_CHAR '#'
#define REGISTRO_OPCION_CARRERA "Carrera"
#define REGISTRO_OPCION_CARRERA_CHAR 'C'
#define REGISTRO_OPCION_VOLVER "Volver"
#define REGISTRO_OPCION_VOLVER_CHAR '0'

#define REGISTRO_ING_APELLIDO "Ingrese Apellido"
#define REGISTRO_ING_NOMBRE "Ingrese Nombre"
#define REGISTRO_ING_PADRON "Ingrese su padrón"
#define REGISTRO_ING_CARRERA "Ingrese el número correspondiente a su carrera"

#define REGISTRO_ING_AVISO "Queda registrado lo siguiente"

/* MSJ de metricas */
#define MSJ_METRICA "\nMetrica:"
#define METRICA_OPCION_PROMEDIO "Promedio"
#define METRICA_OPCION_PROMEDIO_CHAR 'P'
#define METRICA_OPCION_MAXIMO "Maximo"
#define METRICA_OPCION_MAXIMO_CHAR 'M'
#define METRICA_OPCION_MINIMO "Minimo"
#define METRICA_OPCION_MINIMO_CHAR 'm'
#define METRICA_OPCION_CANTIDAD "Cantidad de materias"
#define METRICA_OPCION_CANTIDAD_CHAR '#'
#define METRICA_OPCION_APLAZOS "Aplazos"
#define METRICA_OPCION_APLAZOS_CHAR 'A'
#define METRICA_OPCION_VOLVER "Volver"
#define METRICA_OPCION_VOLVER_CHAR '0'

#define MSJ_PROMEDIO "El promedio es de: "
#define MSJ_MAXIMO "La asignatura con la mejor nota es: "
#define MSJ_MINIMO "La asignatura con la peor nota es: "
#define MSJ_CANTIDAD "La cantidad de materias cursadas es: "
#define MSJ_APLAZOS "La cantidad de aplazos es: "

#endif
