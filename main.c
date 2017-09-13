#include "main.h"

int main(void)
{
	/*Arreglo que contiene el nombre de las carreras correspondiente al numero de la misma*/
	char carreras[LENGTH_MAX_CARRERAS][LENGTH_MAX_NOMBRE_CARRERAS] = {{ING_0}, {ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}};

	estado_main estado = MAIN_MENU;
	char letter = '\0';
	usuario_t alumno;
	int i = 0;

	alumno = reinit(alumno);

	puts(MSJ_BIENVENIDA);

	while(1)
	{
		switch(estado)
		{
		case MAIN_MENU:
		{
			puts(MSJ_MAIN);
			printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n? ", MAIN_OPCION_1_CHAR, MAIN_OPCION_1, MAIN_OPCION_2_CHAR, MAIN_OPCION_2, MAIN_OPCION_3_CHAR, MAIN_OPCION_3, MAIN_OPCION_FINALIZAR_CHAR, MAIN_OPCION_FINALIZAR, MAIN_OPCION_SALIR_CHAR, MAIN_OPCION_SALIR);

			letter = '\0';
			i = 0;
			while((i < MAX_TRY) && (letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) && (letter != MAIN_OPCION_FINALIZAR_CHAR) && (letter != MAIN_OPCION_SALIR_CHAR))
			{
				scanf("%c", &letter);
				if((letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) && (letter != MAIN_OPCION_FINALIZAR_CHAR) && (letter != MAIN_OPCION_SALIR_CHAR))
				{
					fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				}
				clear_buffer();
				i++;
			}

			estado = letter;
			break;
		}

		case MENU_REGISTRO:
		{
			alumno = registro(alumno, carreras); /*function de elias*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_ASIGNATURAS:
		{
			/*
			   alumno = asignaturas(alumno); */ /*function de mauri*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_METRICA:
		{
			alumno = metrica(alumno); /*function de aurelien*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_FINALIZAR:
		{
			alumno = finalizar(alumno);
			estado = MAIN_MENU;
			break;
		}

		case MAIN_SALIR:
		{
			puts(MSJ_DESPEDIDA);
			return EXIT_SUCCESS;
		}

		}
	}

	return 0;
}
