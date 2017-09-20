#include "main.h"


/* REGISTRO */

/*-------------------------------------------------------*/

usuario_t registro(usuario_t usuario, char carreras[][LENGTH_MAX_NOMBRE_CARRERAS])
{
	char input_i = '\0';
	int i = 0;

	puts(MSJ_REGISTRO);
	
	/*Inicia un loop en el que se encontrará el sub-menú: */
	while(1)
	{
		printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n? ",REGISTRO_OPCION_NOMBRE_CHAR, REGISTRO_OPCION_NOMBRE, REGISTRO_OPCION_PADRON_CHAR, REGISTRO_OPCION_PADRON, REGISTRO_OPCION_CARRERA_CHAR, REGISTRO_OPCION_CARRERA, REGISTRO_OPCION_VOLVER_CHAR, REGISTRO_OPCION_VOLVER);


		input_i = '\0';
		i = 0;
		while((input_i != REGISTRO_OPCION_NOMBRE_CHAR) && (input_i != REGISTRO_OPCION_PADRON_CHAR) && (input_i != REGISTRO_OPCION_CARRERA_CHAR) && (input_i != REGISTRO_OPCION_VOLVER_CHAR))
		{
			scanf("%c", &input_i);
			if((input_i != REGISTRO_OPCION_NOMBRE_CHAR) && (input_i != REGISTRO_OPCION_PADRON_CHAR) && (input_i != REGISTRO_OPCION_CARRERA_CHAR) && (input_i != REGISTRO_OPCION_VOLVER_CHAR))
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				i++;
				if(i >= 3)
					input_i = MAIN_OPCION_SALIR_CHAR;
			}
			clear_buffer();
			/*verifica que el input sea válido y le da al usuario 3 oportunidades antes de devolverlo al menu principal*/
		}

/*Ingresa apellido y nombre*/
		if(input_i == REGISTRO_OPCION_NOMBRE_CHAR)
		{
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
		}

/*Ingresa padron*/
		else if(input_i == REGISTRO_OPCION_PADRON_CHAR)
		{
			printf("%s: ", REGISTRO_ING_PADRON);
			i = 0;
			while ((scanf("%i", &usuario.padron) != 1) && i < MAX_TRY)
			{
				fprintf(stdout, "%s: %s\n%s", ERR_PREFIJO, ERR_REG_PADRON, ERR_OPCIONES);
				i++;
				clear_buffer();
			}
			clear_buffer();
			printf("%s: %i\n", REGISTRO_ING_AVISO, usuario.padron);
		}

/*Pide numero de carrera para identificar que nombre de la matriz carreras usar*/
		else if(input_i == REGISTRO_OPCION_CARRERA_CHAR)
		{
			printf("%s: ", REGISTRO_ING_CARRERA);
			if(scanf("%i", &usuario.num_carrera) != 1)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_REG_CARRERA);
			}
			while(getchar() != '\n');

			printf("%s: ", REGISTRO_ING_AVISO);
			imprimir_carrera_aviso(usuario.num_carrera, carreras);

			printf("\n");
		}

/*Sale del loop y permite terminar la funcion registro*/
		else if(input_i == REGISTRO_OPCION_VOLVER_CHAR)
		{
			break;
		}

		else
		{
			fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
		}
	}

	return usuario;         /* Solo se sale exitosamente si se activa el break; */
}



/*-------------------------------------------------------*/







/* ASIGNATURAS */

/*-------------------------------------------------------*/




usuario_t asignaturas(usuario_t usuario)
{
/*Defino un rango de las matrices junto a un par de valores auxiliares*/

	char ELEC[2]; /*variable modificada para aceptar numero de dos cifras*/
	int ENTRADA = IN, CANT_MAT = 0, NUMB, ELEC_BORR,COLUMNA, NUMERO, INTENTOS, SALIDA, PROBLEMA;

/*Limpio las matrices de cualquier valor al azar definido por el programa*/

	clear_materias(usuario.asignaturas, NUMERO_MAX_ASIGNATURAS, LENGTH_MAX_ASIGNATURA);
	clear_notas(usuario.notas, MAX_CALIF);

/*Ingreso del programa*/

	while(ENTRADA==IN)
	{
		SALIDA=0;
		INTENTOS=1;
		NUMB=0;

/*Menu inicial*/

		puts(MSJ_MAIN);
		if(CANT_MAT > 0)
		{
			while(NUMB < CANT_MAT)
			{
				print_opciones(usuario.asignaturas, usuario.notas, LENGTH_MAX_ASIGNATURA, NUMB);
				NUMB++;
			}

			printf("\t%s\n", ASIGNATURA_OPCION_BORRAR);
		}

		printf("\t%s\n", ASIGNATURA_OPCION_INGRESO);
		printf("\t%s\n", ASIGNATURA_OPCION_SALIDA);
		printf("%s", ASIGNATURA_OPCION_PREGUNTA);

		scanf("%s", ELEC); /*scanf modificado para aceptar una cadena de caracteres y no solo un char*/
		while(getchar() != '\n') ;

/*Eleccion de ingreso de asignatura*/

		if(ELEC[0] == AGREGAR)
		{
			if(CANT_MAT == NUMERO_MAX_ASIGNATURAS)
			{
				fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_MAX_NOTA);
			}

			else
			{
				printf("\n%s", TEXT_MATERIA);
				fgets(usuario.asignaturas[CANT_MAT], LENGTH_MAX_ASIGNATURA, stdin);
				printf("%s", TEXT_NOTA);
				if(scanf("%i", &usuario.notas[CANT_MAT]) != 1 || usuario.notas[CANT_MAT] > MAX_CALIF || usuario.notas[CANT_MAT] < MIN_CANLIF)
				{
					PROBLEMA=1;

					while(PROBLEMA == 1 && SALIDA != 1)
					{
						if(INTENTOS == CANTIDAD_INTENTOS)
						{
							fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_INGRESO_MATERIA);
							clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, CANT_MAT);
							usuario.notas[CANT_MAT] = 0;
							CANT_MAT--;
							SALIDA = 1;
						}

						else
						{
							while(getchar()!='\n') ;

							fprintf(stdout, "%s: %s", ERR_PREFIJO, ERR_INGRESO_CONT_NOTA);
							if(scanf("%i", &usuario.notas[CANT_MAT]) == 1 && usuario.notas[CANT_MAT] <= MAX_CALIF && usuario.notas[CANT_MAT] >= MIN_CANLIF)
							{
								PROBLEMA = 0;
							}
						}

						INTENTOS++;
					}
				}
				while(getchar()!='\n') ;

				CANT_MAT++;
				printf("\n");
			}
		}

/*Salida del programa*/

		else if(ELEC[0] == SALIR)
		{
			ENTRADA = OUT;
		}

/*Eliminación de asignatura*/

		else if(ELEC[0] == ELIMINAR)
		{
			if(CANT_MAT == 0)
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
			}
			else
			{
				printf("\n%s", TEXT_ELEC_BORRAR);

				if(scanf("%i", &ELEC_BORR) != 1 ||ELEC_BORR > CANT_MAT - 1 || ELEC_BORR < 0)
				{
					while(getchar()!='\n') ;

					fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
				}
				else
				{
					while(getchar() != '\n') ;  /*limpieza de buffer*/

					while(ELEC_BORR < NUMERO_MAX_ASIGNATURAS - UNO)
					{
						for(COLUMNA = 0; COLUMNA < LENGTH_MAX_ASIGNATURA; COLUMNA++)
						{
							usuario.asignaturas[ELEC_BORR][COLUMNA] = usuario.asignaturas[ELEC_BORR + 1][COLUMNA];
						}
						COLUMNA=0;
						usuario.notas[ELEC_BORR] = usuario.notas[ELEC_BORR + 1];
						ELEC_BORR++;
					}
					CANT_MAT--;
				}
			}
		}


		/*Sobre escritura de asignaturas*/
		else /*para los casos de ELEC*/

		{
			NUMERO = atoi(ELEC);  /*Modificacion para que se guarde el numero ingresado en vez de su equivalente en ASCII*/
			if(NUMERO >= CANT_MAT || CANT_MAT == 0 || (NUMERO == 0 && ELEC[0] != ASCII_CERO))
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
			}
			else
			{
				clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, NUMERO);
				printf("%s", TEXT_MATERIA);
				fgets(usuario.asignaturas[NUMERO], LENGTH_MAX_ASIGNATURA, stdin);

				printf("%s", TEXT_NOTA);
				if(scanf("%i", &usuario.notas[NUMERO]) != 1 || usuario.notas[NUMERO] > MAX_CALIF || usuario.notas[NUMERO] < MIN_CANLIF)
				{
					PROBLEMA = 1;
					while(PROBLEMA == 1 && SALIDA != 1)
					{
						if(INTENTOS == CANTIDAD_INTENTOS)
						{
							fprintf(stdout,"%s: %s", ERR_PREFIJO, ERR_REINGRESO_CONT_NOTA);

							clear_regrab(usuario.asignaturas, LENGTH_MAX_ASIGNATURA, NUMERO);

							while(NUMERO < NUMERO_MAX_ASIGNATURAS - 1)
							{
								for(COLUMNA = 0; COLUMNA < LENGTH_MAX_ASIGNATURA; COLUMNA++)
								{
									usuario.asignaturas[NUMERO][COLUMNA] = usuario.asignaturas[NUMERO + 1][COLUMNA];
								}
								COLUMNA = 0;
								usuario.notas[NUMERO] = usuario.notas[NUMERO + 1];
								NUMERO++;
							}
							CANT_MAT--;
							SALIDA = 1;
						}
						else
						{
							while(getchar() != '\n') ;

							fprintf(stdout, "%s: %s", ERR_PREFIJO, ERR_INGRESO_CONT_NOTA);

							if(scanf("%i", &usuario.notas[NUMERO]) == 1 && usuario.notas[NUMERO] <= MAX_CALIF && usuario.notas[NUMERO] >= MIN_CANLIF)
							{
								PROBLEMA = 0;
							}

						}
						INTENTOS++;
					}
				}
				while(getchar()!='\n') ;

				printf("\n");
			}
		}
	}
	return usuario;
}



void print_opciones(char materia[][LENGTH_MAX_ASIGNATURA], int nota[], int COLUMNA_IMP, int CANT)
{
	int COLUMNA;

	printf("\t%i) ", CANT);
	for(COLUMNA=0; COLUMNA < COLUMNA_IMP - 2 && materia[CANT][COLUMNA] != '\n'; COLUMNA++)
	{
		printf("%c", materia[CANT][COLUMNA]);
	}

	printf(" (%i)\n", nota[CANT]);
}


void clear_notas(int nota[], int FILA_NOT)
{
	int FILA;

	for(FILA=0; FILA<FILA_NOT; FILA++)
	{
		nota[FILA]='\0';
	}
}


void clear_materias(char materia[][LENGTH_MAX_ASIGNATURA], int FILA_MAT, int COLUM_MAT)
{
	int FILA, COLUMNA;

	for(FILA=0; FILA < FILA_MAT; FILA++)
	{
		for(COLUMNA=0; COLUMNA < COLUM_MAT; COLUMNA++)
		{
			materia[FILA][COLUMNA]='\0';
		}
	}
}


void clear_regrab(char m[][LENGTH_MAX_ASIGNATURA], int COLUMNA_BORR, int FILA_BORR)
{
	int COLUMNA;

	for(COLUMNA=0; COLUMNA<COLUMNA_BORR-1; COLUMNA++)
	{
		m[FILA_BORR][COLUMNA]='\0';
	}
}


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

	while(estado != VOLVER) /*inicializa el sub-menú y lo mantiene dentro del mismo hasta que el usuario elija salir*/
	{
		switch(estado)
		{
			/*menu principal*/
			case MAIN_METRICA:
			{

				puts(MSJ_METRICA);
				printf("\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n\t%c) %s\n? ", METRICA_OPCION_PROMEDIO_CHAR, METRICA_OPCION_PROMEDIO, METRICA_OPCION_MAXIMO_CHAR, METRICA_OPCION_MAXIMO, METRICA_OPCION_MINIMO_CHAR, METRICA_OPCION_MINIMO, METRICA_OPCION_CANTIDAD_CHAR, METRICA_OPCION_CANTIDAD, METRICA_OPCION_APLAZOS_CHAR, METRICA_OPCION_APLAZOS, METRICA_OPCION_VOLVER_CHAR, METRICA_OPCION_VOLVER);

				letter = '\0';
				i = 0;

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

				estado = letter;
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
