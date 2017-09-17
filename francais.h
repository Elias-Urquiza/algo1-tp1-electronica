#ifndef FRANCAIS_H
#define FRANCAIS_H


/* MSJ global */
#define MSJ_BIENVENIDA "Bienvenue !"
#define MSJ_MAIN "Choississez ce que vous voulez faire :"

/*Errores*/
#define ERR_PREFIJO "ERREUR"
#define ERR_OPCIONES "Option invalide. Merci de réessayer : "

#define ERR_INGRESO_MATERIA "La matière ne peut pas être lue"
#define ERR_INGRESO_NOTA "La note n'est pas valide"
#define ERR_INGRESO_CONT_NOTA "La note n'est pas valide. Merci de réessayer"
#define ERR_REINGRESO_CONT_NOTA "La note n'est toujours pas valide "
#define ERR_ELEC "Ce choix n'est pas disponible."
#define ERR_MAX_NOTA "Désolé vous ne pouvez plus rentrer de matières car vous avez atteint le maximum."

#define ERR_REG_NOMBRE "Le nom ne peut pas être lu."
#define ERR_REG_PADRON "Le padron ne peut pas être lu."
#define ERR_REG_CARRERA "Numéro de departement invalide."

/* MSJ main */
#define MAIN_OPCION_1 "Registre personnel"
#define MAIN_OPCION_1_CHAR 'R'
#define MAIN_OPCION_2 "Matières"
#define MAIN_OPCION_2_CHAR 'M'
#define MAIN_OPCION_3 "Calcul de données personnelles"
#define MAIN_OPCION_3_CHAR 'C'
#define MAIN_OPCION_FINALIZAR "Finaliser"
#define MAIN_OPCION_FINALIZAR_CHAR '!'
#define MAIN_OPCION_SALIR "Sortir"
#define MAIN_OPCION_SALIR_CHAR '0'

/*Carreras*/
#define ING_0 "Aucun département sélectionné"
#define ING_1 "Ingenieur Civil"
#define ING_2 "Ingenieur Industriel"
#define ING_3 "Ingenieur Mécanique et Naval"
#define ING_4 "Ingenieur en mesure agricole"
#define ING_5 "Ingenieur Mécanique"
#define ING_6 "Ingenieur Electrique"
#define ING_7 "Ingenieur Electronique"
#define ING_8 "Ingenieur Chimique"
#define ING_9 "License en Analyse des Systèmes"
#define ING_10 "Ingenieur Informatique"
#define ING_11 "Ingenieur en Alimentation"


/* MSJ asignatura */
#define ASIGNATURA_OPCION_INGRESO "+) Ajouter une matière"
#define ASIGNATURA_OPCION_SALIDA "!) Sortir."
#define ASIGNATURA_OPCION_BORRAR "-) Supprimer une matière."
#define ASIGNATURA_OPCION_PREGUNTA "? "
#define TEXT_NOTA "Entrer le note: "
#define TEXT_MATERIA "Entrer le matière: "
#define TEXT_ELEC_BORRAR "Rentrer le numéro de la matière que vous souhaitez effacer: "

#define AGREGAR '+'
#define ELIMINAR '-'
#define SALIR '!'


/* MSJ registro */
#define MSJ_REGISTRO "Menu register, Choississez une option pour modifier les données rentrées."
#define REGISTRO_OPCION_NOMBRE "Nom et prénom"
#define REGISTRO_OPCION_NOMBRE_CHAR 'N'
#define REGISTRO_OPCION_PADRON "Padron"
#define REGISTRO_OPCION_PADRON_CHAR '#'
#define REGISTRO_OPCION_CARRERA "Département"
#define REGISTRO_OPCION_CARRERA_CHAR 'D'
#define REGISTRO_OPCION_VOLVER "Sortir"
#define REGISTRO_OPCION_VOLVER_CHAR '0'

#define REGISTRO_ING_APELLIDO "Rentrer votre nom"
#define REGISTRO_ING_NOMBRE "Rentrer votre prénom"
#define REGISTRO_ING_PADRON "Rentrer votre padron"
#define REGISTRO_ING_CARRERA "Rentrer le numéro correspodant à votre département."

#define REGISTRO_ING_AVISO "Donnée enregistrée"

/* MSJ de metricas */
#define MSJ_METRICA "\nDonnées : "
#define METRICA_OPCION_PROMEDIO "Moyenne"
#define METRICA_OPCION_PROMEDIO_CHAR '%'
#define METRICA_OPCION_MAXIMO "Maximum"
#define METRICA_OPCION_MAXIMO_CHAR 'M'
#define METRICA_OPCION_MINIMO "Minimum"
#define METRICA_OPCION_MINIMO_CHAR 'm'
#define METRICA_OPCION_CANTIDAD "Nombre de matières"
#define METRICA_OPCION_CANTIDAD_CHAR '#'
#define METRICA_OPCION_APLAZOS "Echec"
#define METRICA_OPCION_APLAZOS_CHAR 'E'
#define METRICA_OPCION_VOLVER "Sortir"
#define METRICA_OPCION_VOLVER_CHAR '0'

#define MSJ_PROMEDIO "La moyenne est de : "
#define MSJ_MAXIMO "La matière ou vous avez la meilleure bonne note est : "
#define MSJ_MINIMO "La matière ou vous avez la moins bonne note est : "
#define MSJ_CANTIDAD "Le nombre de matière est : "
#define MSJ_APLAZOS "La nombre de matière(s) échouée(s) : "

#endif
