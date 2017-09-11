#include "main.h"


int main(void)
{
	estado_main estado = MAIN_MENU;
	int input_i = 0;

	puts(MSJ_BIENVENIDA);

	while(1)
	{
		switch(estado)
		{
		case MAIN_MENU:
		{
			puts(MSJ_MAIN);
			printf("1) %s\n2) %s\n3) %s\n0) %s\n", MAIN_OPCION_1, MAIN_OPCION_2, MAIN_OPCION_3, MAIN_OPCION_SALIR);

			if(scanf("%i", &input_i) != 1)
			{
				fprintf(stderr,"%s: %s\n", ERR_PREFIJO, ERR_OPCIONES_MAIN);                 /*Hacer funcion error*/
				return EXIT_FAILURE;
			}
			while(getchar() != '\n') ;

			if(input_i == 1)
				estado = MENU_REGISTRO;
			else if(input_i == 2)
				estado = MENU_ASIGNATURAS;
			else if(input_i == 3)
				estado = MENU_OTROS;
			else if(input_i == 0)
				estado = MAIN_SALIR;
			else
			{                 /*hacer funcion error opciones_main() */
				fprintf(stderr,"%s: %s\n", ERR_PREFIJO, ERR_OPCIONES_MAIN);
				return EXIT_FAILURE;
			}
			break;
		}

		case MENU_REGISTRO:
		{
			/* hacer funcion type registro( variables a discutir ) */
			puts("Menu Registro! Pulse 0 para volver y cualquier otra cosa para un error fatal!");

			scanf("%i", &input_i);

			if(input_i == 0)
				estado = MAIN_MENU;
			else
			{
				puts(ERR_PREFIJO);
				return EXIT_FAILURE;
			}

			break;
		}

		case MENU_ASIGNATURAS:
		{
			/* hacer funcion type asignaturas( variables a discutir ) */
			puts("Menu Asignaturas! Pulse 0 para volver o cualquier otra cosa para un error fatal!");

			scanf("%i", &input_i);

			if(input_i == 0)
				estado = MAIN_MENU;
			else
			{
				puts(ERR_PREFIJO);
				return EXIT_FAILURE;
			}

			break;
		}




		case MENU_OTROS:
		{
			/* hacer funcion type a_discutir( variables a discutir ) */
			puts("Menu [FILE_NOT_FOUND]! Pulse 0 para volver y cualquier otra cosa para un error fatal!");

			scanf("%i", &input_i);

			if(input_i == 0)
				estado = MAIN_MENU;
			else
			{
				puts(ERR_PREFIJO);
				return EXIT_FAILURE;
			}

			break;
		}

		case MAIN_SALIR:
		{
			puts(MSJ_DESPEDIDA);
			/* Funcion p' imprimir datos ingresados? */
			return EXIT_SUCCESS;
		}

		}
	}
}