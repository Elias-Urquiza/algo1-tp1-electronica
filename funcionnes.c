#include "main.h"

/* REGISTRO */

/*-------------------------------------------------------*/

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
		while(getchar() != '\n') ;

		if(input_i == 1)
		{
			printf("%s: ", REGISTRO_ING_APELLIDO);
			if(scanf("%s", usuario.apellido) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n') ;

			printf("%s: ", REGISTRO_ING_NOMBRE);

			if(scanf("%s", usuario.nombre) != 1) /*Ingresa apellido y nombre*/
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				/*ERROR REVISAR QUE HACER AQUI AURELIEN!*/
			}
			while(getchar() != '\n') ;

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
			while(getchar() != '\n') ;
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
			while(getchar() != '\n') ;

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

/*-------------------------------------------------------*/






/* ASIGNATURAS */

/*-------------------------------------------------------*/



/*-------------------------------------------------------*/








/* METRICAS */

/*-------------------------------------------------------*/

usuario_t metrica (usuario_t usuario)
{
	estado_metrica estado = MAIN_METRICA;
	char letter = '\0';
	int i = 0;
	float promedioAsignaturas;
	int cantidadAsignaturas = cantidad(usuario);
	int index;

	while(estado != VOLVER)
	{
		switch(estado)
		{
		case MAIN_METRICA:
		{

			puts(MSJ_METRICA);
			printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n", METRICA_OPCION_PROMEDIO_CHAR, METRICA_OPCION_PROMEDIO, METRICA_OPCION_MAXIMO_CHAR, METRICA_OPCION_MAXIMO, METRICA_OPCION_MINIMO_CHAR, METRICA_OPCION_MINIMO, METRICA_OPCION_CANTIDAD_CHAR, METRICA_OPCION_CANTIDAD, METRICA_OPCION_VOLVER_CHAR, METRICA_OPCION_VOLVER);

			letter = '\0';
			i = 0;

			while((i < MAX_TRY) && (letter != METRICA_OPCION_PROMEDIO_CHAR) && (letter != METRICA_OPCION_MAXIMO_CHAR) && (letter != METRICA_OPCION_MINIMO_CHAR) && (letter != METRICA_OPCION_CANTIDAD_CHAR) && (letter != METRICA_OPCION_VOLVER_CHAR))
			{
				scanf("%c", &letter);
				if((letter != METRICA_OPCION_PROMEDIO_CHAR) && (letter != METRICA_OPCION_MAXIMO_CHAR) && (letter != METRICA_OPCION_MINIMO_CHAR) && (letter != METRICA_OPCION_CANTIDAD_CHAR) && (letter != METRICA_OPCION_VOLVER_CHAR))
					printf("%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				clear_buffer();
				i++;
			}

			estado = letter;
			break;
		}

		case PROMEDIO:
		{
			printf(MSJ_PROMEDIO);
			promedioAsignaturas = promedio(usuario, cantidadAsignaturas);
			printf("%f \n", promedioAsignaturas);
			estado = MAIN_METRICA;
			break;
		}

		case MAXIMO:
		{
			printf(MSJ_MAXIMO);
			index = maximo(usuario, cantidadAsignaturas);
			printf("%s (%i)\n", usuario.asignaturas[index], usuario.notas[index]);
			estado = MAIN_METRICA;
			break;
		}

		case MINIMO:
		{
			printf(MSJ_MINIMO);
			index = minimo(usuario, cantidadAsignaturas);
			printf("%s (%i)\n", usuario.asignaturas[index], usuario.notas[index]);
			estado = MAIN_METRICA;
			break;
		}

		case CANTIDAD:
		{
			printf(MSJ_CANTIDAD);
			printf("%i\n", cantidadAsignaturas);
			estado = MAIN_METRICA;
			break;
		}

		case VOLVER:
		{
			NULL;
			break;
		}

		}
	}

	return usuario;
}


int cantidad (usuario_t usuario)
{
	int i, j = 0;

	for(i = 0; usuario.asignaturas[i][1]; i++, j++) ;

	return j;
}


float promedio(usuario_t usuario, int cantidadAsignaturas)
{
	int i;
	float suma = 0;


	for(i = 0; i < cantidadAsignaturas; i++)
	{
		suma += usuario.notas[i];
	}

	return suma/cantidadAsignaturas;
}


int maximo(usuario_t usuario, int cantidadAsignaturas)
{
	int indexmax = 0, i, max = 0;

	for(i = 0; i < cantidadAsignaturas; i++)
	{
		if (usuario.notas[i] > max)
			indexmax = i;
	}
	return indexmax;
}


int minimo(usuario_t usuario, int cantidadAsignaturas)
{
	int min = 10, i, indexmin;

	for(i = 0; i < cantidadAsignaturas; i++)
	{
		if (usuario.notas[i] < min)
			indexmin = i;
	}
	return indexmin;
}


/*-------------------------------------------------------*/







/* OTROS */

/*-------------------------------------------------------*/


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

/*-------------------------------------------------------*/
