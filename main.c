#include "main.h"


int main(void)
{
	/*Arreglo que contiene el nombre de las carreras correspondiente al numero de la misma*/
	char carreras[LENGTH_MAX_CARRERAS][LENGTH_MAX_NOMBRE_CARRERAS] = {{ING_0}, {ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}};

	estado_main estado = MAIN_MENU;
	char letter = '\0';
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
			printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n", MAIN_OPCION_1_CHAR, MAIN_OPCION_1, MAIN_OPCION_2_CHAR, MAIN_OPCION_2, MAIN_OPCION_3_CHAR, MAIN_OPCION_3, MAIN_OPCION_FINALIZAR_CHAR, MAIN_OPCION_FINALIZAR, MAIN_OPCION_SALIR_CHAR, MAIN_OPCION_SALIR);

			while((letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) && (letter != MAIN_OPCION_FINALIZAR_CHAR) && (letter != MAIN_OPCION_SALIR_CHAR))
			{
				scanf("%c", &letter);
				if((letter != MAIN_OPCION_1_CHAR) && (letter != MAIN_OPCION_2_CHAR) && (letter != MAIN_OPCION_3_CHAR) && (letter != MAIN_OPCION_FINALIZAR_CHAR) && (letter != MAIN_OPCION_SALIR_CHAR))
				{
					fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				}
				clear_buffer();
			}

			estado = letter;
			letter = '\0';
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
			/*
			alumno = metrica(alumno); */ /*function de aurelien*/
			estado = MAIN_MENU;
			break;
		}

		case MENU_FINALIZAR:
		{
			/*
			alumno = finalizar(alumno); */
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

usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS])
{
	int input_i = 0;

	puts(MSJ_REGISTRO);

	while(1)
	{
		printf("%s\n%s\n%s\n%s\n", REGISTRO_OPCION_NOMBRE, REGISTRO_OPCION_PADRON, REGISTRO_OPCION_CARRERA, REGISTRO_OPCION_VOLVER);

		if(scanf("%i", &input_i) != 1)
		{
			fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
		}
		while(getchar() != '\n');

		if(input_i == 1)
		{
			printf("%s: ", REGISTRO_ING_APELLIDO);
			if(scanf("%s", usuario.apellido) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n');

			printf("%s: ", REGISTRO_ING_NOMBRE);

			if(scanf("%s", usuario.nombre) != 1)/*Ingresa apellido y nombre*/
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n');

			printf("%s: %s, %s\n", REGISTRO_ING_AVISO, usuario.apellido, usuario.nombre);
		}
		else if(input_i == 2) /*Ingresa padron*/
		{
			printf("%s: ", REGISTRO_ING_PADRON);
			if(scanf("%i", &usuario.padron) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_PADRON);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n');
			printf("%s: %i\n", REGISTRO_ING_AVISO, usuario.padron);
		}
		else if(input_i == 3) /*Pide numero de carrera para identificar que nombre de la matriz carreras usar*/
		{
			printf("%s: ", REGISTRO_ING_CARRERA);
			if(scanf("%i", &usuario.num_carrera) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_CARRERA);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n');

			printf("%s: ", REGISTRO_ING_AVISO);
			imprimir_carrera(usuario.num_carrera, carreras);
		}
		else if(input_i == 0) /*Sale del loop y permite terminar la funcion registro*/
		{
			break;
		}
		else
		{
			fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
		}
	}

	return usuario; /* Solo se sale exitosamente si se activa el break; */
}



usuario_t reinit(usuario_t usuario)
{
	int i, j;

	for(i = 0; i < LENGTH_MAX_NOMBRE; i++)
	{
		usuario.nombre[i] = '\0';
		usuario.apellido[i] = '\0';
	}

	usuario.padron = 0;

	usuario.num_carrera = 0;

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

void imprimir_carrera(int fila, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS])
{
       	printf("%s\n", carreras[fila]); /*Imprime la carrera correspondiente a lo ingresado*/
}

void clear_buffer(void)
{
	while(getchar() != '\n')
		NULL;
}
