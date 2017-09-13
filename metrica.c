#include "main.h"


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
	int i, suma = 0;


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
