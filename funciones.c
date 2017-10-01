#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/* MAIN */

/*-------------------------------------------------------*/
char menu_principal(int *tentativa)
{
	char letter = '\0';

	imprimir_menu_principal();

	while ((scanf("%c", &letter) != 1) && (*tentativa < MAX_TRY))
	{
		fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
		*tentativa++;
		clear_buffer();
	}

	clear_buffer();
	letter = toupper(letter);
	return letter;
}


void imprimir_menu_principal(void)
{
	puts(MSJ_MAIN);
	printf("\t%c) %s\n", MAIN_OPCION_1_CHAR, MAIN_OPCION_1);
	printf("\t%c) %s\n", MAIN_OPCION_2_CHAR, MAIN_OPCION_2);
	printf("\t%c) %s\n", MAIN_OPCION_3_CHAR, MAIN_OPCION_3);
	printf("\t%c) %s\n", MAIN_OPCION_FINALIZAR_CHAR, MAIN_OPCION_FINALIZAR);
	printf("\t%c) %s\n?", MAIN_OPCION_SALIR_CHAR, MAIN_OPCION_SALIR);
}



/*-------------------------------------------------------*/


/* REGISTRO */

/*-------------------------------------------------------*/

usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS])
{
	/*inicializo variables*/

	char input_i = '\0'; /*variable para switch*/
	int i = 0; /*contador para reintentos*/

	puts(MSJ_REGISTRO);

	/*Inicia un loop en el que se encontrará el sub-menú: */
	while(1)
	{
		imprimir_menu_registro();

		switch(input_i)
		{
		case REGISTRO_OPCION_NOMBRE_CHAR:
		{
			input_i = '\0';
			i = 0;           /*reinicio variables*/

			printf("%s: ", REGISTRO_ING_APELLIDO);
			if(scanf("%s", usuario.apellido) != 1)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
			}
			clear_buffer();

			printf("%s: ", REGISTRO_ING_NOMBRE);

			if(scanf("%s", usuario.nombre) != 1)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
			}
			clear_buffer();

			printf("%s: %s, %s\n", REGISTRO_ING_AVISO, usuario.apellido, usuario.nombre);

			break;
		}

		case REGISTRO_OPCION_PADRON_CHAR:
		{
			input_i = '\0';
			i = 0;           /*reinicio variables*/

			printf("%s: ", REGISTRO_ING_PADRON);

			while ((scanf("%i", &usuario.padron) != 1) && i < MAX_TRY)
			{
				fprintf(stdout, "%s: %s\n%s", ERR_PREFIJO, ERR_REG_PADRON, ERR_OPCIONES);
				i++;
				clear_buffer();
			}
			clear_buffer();

			printf("%s: %i\n", REGISTRO_ING_AVISO, usuario.padron);

			break;
		}

		case REGISTRO_OPCION_CARRERA_CHAR:
		{
			input_i = '\0';
			i = 0;           /*reinicio variables*/

			printf("%s: ", REGISTRO_ING_CARRERA);
			if(scanf("%i", &usuario.num_carrera) != 1)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_REG_CARRERA);
			}
			while(getchar() != '\n') ;

			printf("%s: ", REGISTRO_ING_AVISO);
			imprimir_carrera_aviso(usuario.num_carrera, carreras);

			printf("\n");

			break;
		}

		case REGISTRO_OPCION_VOLVER_CHAR:
		{
			return usuario;
			break;
		}

		default:
		{
			if(scanf("%c", &input_i) != 1)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				i++;
				if(i >= 3)
					input_i = MAIN_OPCION_SALIR_CHAR;
			}
			clear_buffer();         /*verifica que el input sea válido y le da al usuario 3 oportunidades antes de devolverlo al menu principal*/
		}
		}
	}
}


/*imprime sub-menú*/
void imprimir_menu_registro(void)
{
	printf("\t%c) %s\n",REGISTRO_OPCION_NOMBRE_CHAR, REGISTRO_OPCION_NOMBRE);
	printf("\t%c) %s\n", REGISTRO_OPCION_PADRON_CHAR, REGISTRO_OPCION_PADRON);
	printf("\t%c) %s\n", REGISTRO_OPCION_CARRERA_CHAR, REGISTRO_OPCION_CARRERA);
	printf("\t%c) %s\n?", REGISTRO_OPCION_VOLVER_CHAR, REGISTRO_OPCION_VOLVER);
}

/*-------------------------------------------------------*/







/* ASIGNATURAS */

/*-------------------------------------------------------*/


void submenu_asignaturas (char* option,estado_main estado, int *intentos, usuario_t usuario)
{
	imprimir_menu_asignaturas(usuario);
	while ((scanf("%s", option) != 1) && (*intentos < MAX_TRY))
	{
			fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			(*intentos)++;
			clear_buffer();
	}
	clear_buffer();
}

void imprimir_menu_asignaturas(usuario_t usuario)
{
	int cantidadAsignaturas = cantidad(usuario);
	int i = 0;

	puts(MSJ_MAIN);
	if(cantidadAsignaturas > 0)
	{
		while(i < cantidadAsignaturas)
		{
			print_opciones(usuario, LENGTH_MAX_ASIGNATURA, i);
			i++;
		}

		printf("\t%c) %s\n", ASIGNATURA_OPCION_BORRAR_CHAR, ASIGNATURA_OPCION_BORRAR);
	}

	printf("\t%c) %s\n",ASIGNATURA_OPCION_INGRESO_CHAR, ASIGNATURA_OPCION_INGRESO);
	printf("\t%c) %s\n", ASIGNATURA_OPCION_VOLVER_CHAR, ASIGNATURA_OPCION_VOLVER);
	printf("%s", ASIGNATURA_OPCION_PREGUNTA);
}

/*imprime toda la columna seleccionada*/
void print_opciones(usuario_t usuario, int columna_IMP, int CANT)
{
	int columna;

	printf("\t%i) ", CANT);
	for(columna=0; columna < columna_IMP - 2 && usuario.asignaturas[CANT][columna] != '\n'; columna++)
	{
		printf("%c", usuario.asignaturas[CANT][columna]);
	}

	printf(" (%i)\n", usuario.notas[CANT]);
}


usuario_t asignaturas(usuario_t usuario)
{
/*Defino un rango de las matrices junto a un par de valores auxiliares*/
	estado_asignatura estado = MAIN_ASIGNATURA;
	char opcion[2];
	int cantidadAsignaturas;
	int intentos = 0, numero = -1;


	while(estado != VOLVER_A)
	{
		cantidadAsignaturas = cantidad(usuario);

		switch (estado)
		{

		case MAIN_ASIGNATURA:
		{
			submenu_asignaturas(opcion, MENU_ASIGNATURAS, &intentos, usuario);
			estado = opcion[0];
			break;
		}

		case AGRAGAR:
		{
			usuario = agregar(usuario, cantidadAsignaturas);
			intentos = 0;
			estado = MAIN_ASIGNATURA;
			break;
		}

		case ELIMINAR:
		{
			usuario = eliminar(usuario, cantidadAsignaturas);
			if (intentos > MAX_TRY)
			{
				fprintf(stdout, "%s\n", ERR_PREFIJO);
				estado = VOLVER_A;
			}
			estado = MAIN_ASIGNATURA;
			break;
		}

		case VOLVER_A:
		{
			estado = VOLVER_A;
			break;
		}

		default:
		{
			numero = atoi(opcion);  /*Modificacion para que se guarde el numero ingresado en vez de su equivalente en ASCII*/
			if(numero >= cantidadAsignaturas || cantidadAsignaturas == 0 || (numero == 0 && opcion != ASCII_CERO))
			{
				intentos++;
				if (intentos > MAX_TRY)
				{
					fprintf(stdout, "%s\n", ERR_PREFIJO);
					estado = VOLVER_A;
				}
				else
				{
					fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
					estado = MAIN_ASIGNATURA;
				}
			}
			else
			{
				usuario = modificar(usuario, numero);
			}
			estado=MAIN_ASIGNATURA;
			break;
		}

		} /*end of switch*/

	} /*end of while*/

	return usuario;
}



/*Ingresa las materias*/
usuario_t agregar(usuario_t usuario, int cantidadAsignaturas)
{

	int problema, intentos = 0, salida = 0;


	if(cantidadAsignaturas >= NUMERO_MAX_ASIGNATURAS)         /*Preveo que no se pase*/
	{
		fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_MAX_NOTA);
	}

	else
	{
		printf("\n%s", TEXT_MATERIA);

		fgets(usuario.asignaturas[cantidadAsignaturas], LENGTH_MAX_ASIGNATURA, stdin);

		printf("%s", TEXT_NOTA);

		if(scanf("%i", &usuario.notas[cantidadAsignaturas]) != 1 || usuario.notas[cantidadAsignaturas] > MAX_CALIF || usuario.notas[cantidadAsignaturas] < MIN_CANLIF)
		{
			problema=1;

			while(problema == 1 && salida != 1)
			{
				if(intentos == MAX_TRY)
				{
					fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_INGRESO_MATERIA);
					clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, cantidadAsignaturas);
					usuario.notas[cantidadAsignaturas] = 0;
					salida = 1;
				}

				else
				{
					clear_buffer();

					fprintf(stdout, "%s: %s", ERR_PREFIJO, ERR_INGRESO_CONT_NOTA);
					if(scanf("%i", &usuario.notas[cantidadAsignaturas]) == 1 && usuario.notas[cantidadAsignaturas] <= MAX_CALIF && usuario.notas[cantidadAsignaturas] >= MIN_CANLIF)
					{
						problema = 0;
					}
				}
				intentos++;
			}
		}

		clear_buffer();
		printf("\n");
	}
	return usuario;
}



/*Funcion donde se elimina la materia elegida*/
usuario_t eliminar(usuario_t usuario, int cantidadAsignaturas)
{
	int columna, numBorrar;
	if(cantidadAsignaturas == 0)
	{
		fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
	}
	else
	{
		printf("\n%s", TEXT_ELEC_BORRAR);

		if(scanf("%i", &numBorrar) != 1 || numBorrar > cantidadAsignaturas - 1 || numBorrar < 0)
		{
			clear_buffer();

			fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
		}
		else
		{
			clear_buffer();

			while(numBorrar < NUMERO_MAX_ASIGNATURAS - 1)
			{
				for(columna = 0; columna < LENGTH_MAX_ASIGNATURA; columna++)
				{
					usuario.asignaturas[numBorrar][columna] = usuario.asignaturas[numBorrar + 1][columna];
				}
				columna=0;
				usuario.notas[numBorrar] = usuario.notas[numBorrar + 1];
				numBorrar++;
			}

			clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, numBorrar); /*Eliminacion de la ultima variable para preveer datos basura*/
			usuario.notas[numBorrar] = 0;
		}
	}
	return usuario;
}



/*Funcion donde se modifica la materia elegida*/
usuario_t modificar(usuario_t usuario, int numero)
{

	int columna, intentos = 0, salida = 0, problema;

	clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, numero);

	printf("%s", TEXT_MATERIA);

	fgets(usuario.asignaturas[numero], LENGTH_MAX_ASIGNATURA, stdin);

	printf("%s", TEXT_NOTA);

	if(scanf("%i", &usuario.notas[numero]) != 1 || usuario.notas[numero] > MAX_CALIF || usuario.notas[numero] < MIN_CANLIF)
	{
		problema = 1;
		while(problema == 1 && salida != 1)
		{
			if(intentos == MAX_TRY)
			{
				fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_REINGRESO_CONT_NOTA);

				clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, numero);

				while(numero < NUMERO_MAX_ASIGNATURAS - 1)
				{
					for(columna = 0; columna < LENGTH_MAX_ASIGNATURA; columna++)
					{
						usuario.asignaturas[numero][columna] = usuario.asignaturas[numero + 1][columna];
					}
					columna = 0;
					usuario.notas[numero] = usuario.notas[numero + 1];
					numero++;
				}
				salida = 1;
			}
			else
			{
				clear_buffer();

				fprintf(stdout, "%s: %s", ERR_PREFIJO, ERR_INGRESO_CONT_NOTA);

				if(scanf("%i", &usuario.notas[numero]) == 1 && usuario.notas[numero] <= MAX_CALIF && usuario.notas[numero] >= MIN_CANLIF)
				{
					problema = 0;
				}

			}
			intentos++;
		}
	}
	clear_buffer();

	printf("\n");
	return usuario;
}

/*limpia la fila fila y columna*/
void clear_regrab(char m[][LENGTH_MAX_ASIGNATURA], int columna_BORR, int FILA_BORR)
{
	int columna;

	for(columna=0; columna<columna_BORR-1; columna++)
	{
		m[FILA_BORR][columna]='\0';
	}
}


/*-------------------------------------------------------*/









/* METRICAS */

/*-------------------------------------------------------*/

usuario_t metrica (usuario_t usuario)
{
	estado_metrica estado = MAIN_METRICA;
	float promedioAsignaturas;
	int cantidadAsignaturas = cantidad(usuario);
	int index, i;

	while(estado != VOLVER) /*inicializa el sub-menú y lo mantiene dentro del mismo hasta que el usuario elija salir*/
	{
		switch(estado)
		{
		/*menu principal*/
		case MAIN_METRICA:
		{
			estado = menu_metrica();
			break;
		}

/*calcula promedio usando su funcion respectiva*/
		case PROMEDIO:
		{
			printf(MSJ_PROMEDIO);
			promedioAsignaturas = promedio(usuario, cantidadAsignaturas);
			printf("%.1f\n", promedioAsignaturas);
			estado = MAIN_METRICA;
			break;
		}

/*calcula nota maxima y expresa en cual materia es usando la funcion maximo();*/
		case MAXIMO:
		{
			printf(MSJ_MAXIMO);
			index = maximo(usuario, cantidadAsignaturas);

			for( i = 0; usuario.asignaturas[index][i + 1] != '\0'; i++)
			{
				printf("%c", usuario.asignaturas[index][i]);
			}
			printf(" (%i)\n", usuario.notas[index]);

			estado = MAIN_METRICA;
			break;
		}

/*calcula nota minima y expresa en cual materia es usando la funcion minimo();*/
		case MINIMO:
		{
			printf(MSJ_MINIMO);
			index = minimo(usuario, cantidadAsignaturas);

			for( i = 0; usuario.asignaturas[index][i + 1] != '\0'; i++)
			{
				printf("%c", usuario.asignaturas[index][i]);
			}
			printf(" (%i)\n", usuario.notas[index]);

			estado = MAIN_METRICA;
			break;
		}

/*calcula la cantidad de materias cursadas con su funcion correspondiente*/
		case CANTIDAD:
		{
			printf(MSJ_CANTIDAD);
			printf("%i\n", cantidadAsignaturas);
			estado = MAIN_METRICA;
			break;
		}

/*calcula la cantidad de aplazos con su funcion correspondiente*/
		case APLAZOS:
		{
			printf(MSJ_APLAZOS);
			printf("%i\n", aplazos(usuario, cantidadAsignaturas));
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


char menu_metrica()
{

	char letter = '\0';
	int i = 0;

	imprimir_menu_metrica();

	while((i < MAX_TRY) && (letter != METRICA_OPCION_PROMEDIO_CHAR) && (letter != METRICA_OPCION_MAXIMO_CHAR) && (letter != METRICA_OPCION_MINIMO_CHAR) && (letter != METRICA_OPCION_CANTIDAD_CHAR) && (letter != METRICA_OPCION_APLAZOS_CHAR) && (letter != METRICA_OPCION_VOLVER_CHAR))
	{
		scanf("%c", &letter);
		if((letter != METRICA_OPCION_PROMEDIO_CHAR) && (letter != METRICA_OPCION_MAXIMO_CHAR) && (letter != METRICA_OPCION_MINIMO_CHAR) && (letter != METRICA_OPCION_CANTIDAD_CHAR) && (letter != METRICA_OPCION_APLAZOS_CHAR) && (letter != METRICA_OPCION_VOLVER_CHAR))
		{
			printf("%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			i++;
			if (i >= 3)
				letter = '0';
		}
		clear_buffer();
	}

	return letter;
}


void imprimir_menu_metrica(void)
{
	puts(MSJ_METRICA);
	printf("\t%c) %s\n", METRICA_OPCION_PROMEDIO_CHAR, METRICA_OPCION_PROMEDIO);
	printf("\t%c) %s\n", METRICA_OPCION_MAXIMO_CHAR, METRICA_OPCION_MAXIMO);
	printf("\t%c) %s\n", METRICA_OPCION_MINIMO_CHAR, METRICA_OPCION_MINIMO);
	printf("\t%c) %s\n", METRICA_OPCION_CANTIDAD_CHAR, METRICA_OPCION_CANTIDAD);
	printf("\t%c) %s\n", METRICA_OPCION_APLAZOS_CHAR, METRICA_OPCION_APLAZOS);
	printf("\t%c) %s\n?", METRICA_OPCION_VOLVER_CHAR, METRICA_OPCION_VOLVER);
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
		{
			indexmax = i;
			max = usuario.notas[i];
		}
	}
	return indexmax;
}


int minimo(usuario_t usuario, int cantidadAsignaturas)
{
	int min = 11, i, indexmin;

	for(i = 0; i < cantidadAsignaturas; i++)
	{
		if (usuario.notas[i] < min)
		{
			indexmin = i;
			min = usuario.notas[i];
		}
	}
	return indexmin;
}


int aplazos(usuario_t usuario, int cantidadAsignaturas)
{
	int i, numero = 0;

	for(i = 0; i < cantidadAsignaturas; i++)
	{
		if (usuario.notas[i] < 4)
			numero++;
	}

	return numero;
}

/*-------------------------------------------------------*/








/* FINALIZAR */

/*-------------------------------------------------------*/

usuario_t finalizar(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS])
{
	int cantidadAsignaturas = cantidad(usuario);
	fprintf(stderr, "%s %s, %i, ",  usuario.nombre, usuario.apellido, usuario.padron); /*imprime nombre, apellido y padrón por stderr*/
	imprimir_carrera_fin(usuario.num_carrera, carreras); /*imprime la carrera elegida por stderr*/
	fprintf(stderr, "%i, %.2f, %i\n",cantidadAsignaturas, promedio(usuario, cantidadAsignaturas), aplazos(usuario, cantidadAsignaturas)); /*imprime los datos restantes por stderr*/
	return reinit(usuario);
	clear_buffer();
}

/*-------------------------------------------------------*/






/* OTROS */

/*-------------------------------------------------------*/


usuario_t reinit(usuario_t usuario) /*reinicializa los datos del usuario*/
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

void imprimir_carrera_aviso(int fila, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]) /*imprime por stdout el nombre de carrera segun num*/
{
	if(fila < 0 || fila > 12)
	{
		puts(ERR_REG_CARRERA);
	}
	else
	{
		printf("%s\n", carreras[fila]); /*Imprime la carrera correspondiente a lo ingresado*/
	}
}

void imprimir_carrera_fin(int fila, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS]) /*imprime por stderr el nombre de carrera segun num*/
{
	if(fila < 0 || fila > 12)
	{
		fprintf(stderr, "%s, ", ERR_REG_CARRERA);
	}
	else
	{
		fprintf(stderr, "%s, ", carreras[fila]);
	}
}

void clear_buffer(void) /*limpia el buffer. No siempre utilizado*/
{
	while(getchar() != '\n')
		NULL;
}

/*-------------------------------------------------------*/
