#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(void)
{
	/*Arreglo que contiene el nombre de las carreras correspondiente al numero de la misma*/
	char carreras[LENGTH_MAX_CARRERAS][LENGTH_MAX_NOMBRE_CARRERAS] = {{ING_0}, {ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}};
	estado_main estado = MAIN_MENU;
	usuario_t alumno;
	int tentativa = 0;

	alumno = reinit(alumno); /*inicializa las variables de la struct*/

	puts(MSJ_BIENVENIDA);


	while(estado != MAIN_SALIR)
	{

		switch(estado)
		{

		case MAIN_MENU:
		{
			estado = menu_principal(&tentativa);
			break;
		}

		case MENU_REGISTRO:
		{
			int tentativa = 0;
			alumno = registro(alumno, carreras);
			estado = MAIN_MENU;
			break;
		}

		case MENU_ASIGNATURAS:
		{
			int tentativa = 0;
			alumno = asignaturas(alumno);
			estado = MAIN_MENU;
			break;
		}

		case MENU_METRICA:
		{
			int tentativa = 0;
			alumno = metrica(alumno);
			estado = MAIN_MENU;
			break;
		}

		case MENU_FINALIZAR:
		{
			int tentativa = 0;
			alumno = finalizar(alumno, carreras);
			estado = MAIN_MENU;
			break;
		}

		case MAIN_SALIR:
		{
			estado = MAIN_SALIR;
		}

		default:
		{
			tentativa++;

			if (tentativa > MAX_TRY)
			{
				fprintf(stdout, "%s\n", ERR_PREFIJO);
				estado = MAIN_SALIR;
			}
			else
			{
				fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
				estado = MAIN_MENU;
			}
			break;
		}

		} /* end of switch */

	} /* end of while */

	return EXIT_SUCCESS;
}
