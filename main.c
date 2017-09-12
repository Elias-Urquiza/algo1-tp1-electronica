#include "main.h"


int main(void)
{
	estado_main estado = MAIN_MENU;
	char letter = 'W';
	usuario_t alumno;

	alumno = reinit(alumno);

	puts(MSJ_BIENVENIDA);

	while(1)
	{
		switch(estado)
		{
		case MAIN_MENU:
		{
			puts(MSJ_MAIN);
			printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n", MAIN_OPCION_1_CHAR, MAIN_OPCION_1, MAIN_OPCION_2_CHAR, MAIN_OPCION_2, MAIN_OPCION_3_CHAR, MAIN_OPCION_3, MAIN_OPCION_SALIR_CHAR, MAIN_OPCION_SALIR);

			while((letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) & (letter != MAIN_OPCION_SALIR_CHAR))
			{
				scanf("%c", &letter);
				if((letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) & (letter != MAIN_OPCION_SALIR_CHAR))
					printf("%s: %s\n", ERR_PREFIJO, ERR_OPCIONES_MAIN);
				clear_buffer();
			}

			estado = letter;
			letter = 'W';
			break;
		}

		case MENU_REGISTRO:
		{
			alumno = registro(alumno); /*function de elias*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_ASIGNATURAS:
		{
			alumno = asignaturas(alumno); /*function de mauri*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_OTROS:
		{
			alumno = otros(alumno); /*function de aurelien*/
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


usuario_t reinit(usuario_t usuario)
{
	int i, j;

	for(i = 0; i < LENGTH_MAX_NOMBRE; i++)
	{
		usuario.nombre[i] = '\0';
	}

	usuario.padron = 0;

	usuario.carrera = 0;

	for(i = 0; i < NUMERO_MAX_ASIGNATURAS; i++)
	{
		for(j = 0; j < LENGTH_MAX_ASIGNATURA; j++)
		{
			usuario.asignaturas[i][j] = '\0';
		}

		usuario.notas[i] = 0;
	}

	return usuario;
}


void clear_buffer(void)
{
	while(getchar() != '\n')
		NULL;
}
