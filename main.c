#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(void)
{
	/*Arreglo que contiene el nombre de las carreras correspondiente al numero de la misma*/
	char carreras[LENGTH_MAX_CARRERAS][LENGTH_MAX_NOMBRE_CARRERAS] = {{ING_0}, {ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}};

	estado_main estado = default;
	char letter = '\0'; /*variable para lo que ingrese el usuario*/
	int i = 0; /*variable para reintentos*/
	usuario_t alumno;

	alumno = reinit(alumno); /*inicializa las variables de la struct*/

	puts(MSJ_BIENVENIDA);

	while(1)
	{
		imprimir_menu_principal();

		switch(estado)
		{
			case MENU_REGISTRO:
			{
				char letter = '\0';
				int i = 0; /*reinicio variables*/

				alumno = registro(alumno, carreras);
				estado = default;
				break;
			}

			case MENU_ASIGNATURAS:
			{
				char letter = '\0';
				int i = 0; /*reinicio variables*/

				alumno = asignaturas(alumno);
				estado = default;
				break;
			}

			case MENU_METRICA:
			{
				char letter = '\0';
				int i = 0; /*reinicio variables*/

				alumno = metrica(alumno);
				estado = default;
				break;
			}

			case MENU_FINALIZAR:
			{
				char letter = '\0';
				int i = 0; /*reinicio variables*/

				alumno = finalizar(alumno, carreras);
				estado = default;
				break;
			}

			case MAIN_SALIR:
			{
				return EXIT_SUCCESS;
			}

			case default:
			{
				i++;
				if((scanf("%c", &letter) != 1) || !isalpha(letter)) /*verifica que ingrese un solo caracter alfabético. En caso de que no pueda ser reconocido, el case se repite e igualmente se aumenta el nivel de intentos que ha tenido el usuario.*/
				{
					fprintf(stdout, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
					i++;
				}
				clear_buffer();

				if(i >= 4)
				{
					letter = MAIN_OPCION_SALIR_CHAR;
				}

				estado = letter;
			}
		}
	}
}
