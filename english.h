#ifndef ENGLISH__H
#define ENGLISH__H


/* Global Messages */
#define MSJ_BIENVENIDA "Welcome!"
#define MSJ_MAIN "Please, pick an option:"

/*Errors*/
#define ERR_PREFIJO "ERROR"
#define ERR_OPCIONES "Invalid option. Please, try again: "

#define ERR_INGRESO_MATERIA "La asignatura fue mal ingresada."
#define ERR_INGRESO_NOTA "La nota fue mal ingresada."
#define ERR_INGRESO_CONT_NOTA "La nota fue mal ingresada, por favor vuelva a intentar: "
#define ERR_REINGRESO_CONT_NOTA "La rescritura de la materia fue de manera incorrecta"
#define ERR_ELEC "La eleccion realizada no esta permitida."
#define ERR_MAX_NOTA "Se a llegado a la maxima cantidad de asignaturas ingresada."

#define ERR_REG_NOMBRE "The name you typed couldn't be read."
#define ERR_REG_PADRON "The college ID you typed couldn't be read."
#define ERR_REG_CARRERA "Invalid Career Number."

/* Main Options */
#define MAIN_OPCION_1 "Personal Registry"
#define MAIN_OPCION_1_CHAR 'R'
#define MAIN_OPCION_2 "Courses"
#define MAIN_OPCION_2_CHAR 'C'
#define MAIN_OPCION_3 "Calculate Individual Metrics"
#define MAIN_OPCION_3_CHAR 'M'
#define MAIN_OPCION_FINALIZAR "End Session"
#define MAIN_OPCION_FINALIZAR_CHAR '!'
#define MAIN_OPCION_SALIR "Exit"
#define MAIN_OPCION_SALIR_CHAR '0'

/*Careers*/
#define ING_0 "No career selected"
#define ING_1 "Civil Engineering"
#define ING_2 "Industrial Engineering"
#define ING_3 "Marine & Mechanical Engineering"
#define ING_4 "Surveying Engineering"
#define ING_5 "Mechanical Engineering"
#define ING_6 "Electrical Engineering"
#define ING_7 "Electronics Engineering"
#define ING_8 "Chemical Engineering"
#define ING_9 "Computer Systems Bachelor"
#define ING_10 "Informatics' Engineering"
#define ING_11 "Food Engineering"

/* Courses */
#define ASIGNATURA_OPCION_INGRESO "+) Add a Course"
#define ASIGNATURA_OPCION_SALIDA "!) Exit"
#define ASIGNATURA_OPCION_BORRAR "-) Delete Course"
#define ASIGNATURA_OPCION_PREGUNTA "? "
#define TEXT_NOTA "Insert your course grade: "
#define TEXT_MATERIA "Insert your course: "
#define TEXT_ELEC_BORRAR "Insert the number of the course you wish to delete: "

#define AGREGAR '+'
#define ELIMINAR '-'
#define SALIR '!'

/* Registry */
#define MSJ_REGISTRO "Registry Menu. Pick an option to modify the logged data."
#define REGISTRO_OPCION_NOMBRE "Full Name"
#define REGISTRO_OPCION_NOMBRE_CHAR 'N'
#define REGISTRO_OPCION_PADRON "College ID"
#define REGISTRO_OPCION_PADRON_CHAR '#'
#define REGISTRO_OPCION_CARRERA "Career"
#define REGISTRO_OPCION_CARRERA_CHAR 'C'
#define REGISTRO_OPCION_VOLVER "Go Back"
#define REGISTRO_OPCION_VOLVER_CHAR '0'

#define REGISTRO_ING_APELLIDO "Insert Surname"
#define REGISTRO_ING_NOMBRE "Insert Name"
#define REGISTRO_ING_PADRON "Insert College ID"
#define REGISTRO_ING_CARRERA "Insert your career's corresponding number"

#define REGISTRO_ING_AVISO "Registered:"

/* Metrics */
#define MSJ_METRICA "\nPick which metric to measure:"
#define METRICA_OPCION_PROMEDIO "Average"
#define METRICA_OPCION_PROMEDIO_CHAR 'A'
#define METRICA_OPCION_MAXIMO "Maximum"
#define METRICA_OPCION_MAXIMO_CHAR 'M'
#define METRICA_OPCION_MINIMO "Minimum"
#define METRICA_OPCION_MINIMO_CHAR 'm'
#define METRICA_OPCION_CANTIDAD "Amount of Courses"
#define METRICA_OPCION_CANTIDAD_CHAR '#'
#define METRICA_OPCION_APLAZOS "Failed Courses"
#define METRICA_OPCION_APLAZOS_CHAR 'A'
#define METRICA_OPCION_VOLVER "Go Back"
#define METRICA_OPCION_VOLVER_CHAR '0'

#define MSJ_PROMEDIO "Your average is: "
#define MSJ_MAXIMO "The course with the highest note is: "
#define MSJ_MINIMO "The course with the lowest note is: "
#define MSJ_CANTIDAD "The amount of courses you've taken is: "
#define MSJ_APLAZOS "Amount of failed courses: "

#endif
