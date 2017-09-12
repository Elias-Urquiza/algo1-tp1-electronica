#include "main.h"

int menu_registro(int *ptr_padron, int *ptr_num_carrera, char carrera[][30], char apellido[], char nombre[]);

void imprimir_carrera(int fila, char carrera[][30]);

int main(void)
{
	/*Cambiar constantes a constantes en serio.*/
	estado_main estado = MAIN_MENU;
	int input_i = 0;
	char apellido[50];
	char nombre[50];
	int padron, num_carrera;
	char carrera[11][30] = {{ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}};


	puts(MSJ_BIENVENIDA);

	while(1)
	{
		switch(estado)
		{
			case MAIN_MENU:
			{
				puts(MSJ_MAIN);
				printf("1) %s\n2) %s\n3) %s\n4) %s\n0) %s\n", MAIN_OPCION_1, MAIN_OPCION_2, MAIN_OPCION_3, MAIN_OPCION_4, MAIN_OPCION_SALIR);

				if(scanf("%i", &input_i) != 1)
				{
					fprintf(stderr,"%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);                 /*Hacer funcion error*/
					return EXIT_FAILURE;
				}
				while(getchar() != '\n');

				if(input_i == 1)
					estado = MENU_REGISTRO;
				else if(input_i == 2)
					estado = MENU_ASIGNATURAS;
				else if(input_i == 3)
					estado = MENU_METRICAS;
				else if(input_i == 4)
					estado = MENU_FINALIZAR;
				else if(input_i == 0)
					estado = MAIN_SALIR;
				else
				{                 /*hacer funcion error opciones_main() */
					fprintf(stderr,"%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
					return EXIT_FAILURE;
				}

				break;
			}

			case MENU_REGISTRO:
			{
				input_i = menu_registro(&padron, &num_carrera, carrera, apellido, nombre);

				if(input_i == EXIT_SUCCESS)
					estado = MAIN_MENU;
				else
				{
					return EXIT_FAILURE;
				}

				printf("PRUEBA: PADRON: %i CARRERA: %i\n", padron, num_carrera);

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

			case MENU_METRICAS:
			{
				/* hacer funcion type a_discutir( variables a discutir ) */
				puts("Menu Métricas! Pulse 0 para volver y cualquier otra cosa para un error fatal!");

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

			case MENU_FINALIZAR:
			{
				puts("Menu Finalizar! Aquí se imprimiran los datos calculados y se volverá a cero los valores. Pulse 0 para volver.");

				scanf("%i", &input_i);

				if(input_i == 0)
					estado = MAIN_MENU;
				else
				{
					puts(ERR_PREFIJO);
					return EXIT_FAILURE;
				}
			}
			case MAIN_SALIR:
			{
				puts(MSJ_DESPEDIDA);
				return EXIT_SUCCESS;
			}

		}
	}
}

void imprimir_carrera(int fila, char carrera[][30])
{
       	printf("%s\n", carrera[fila - 1]);
}

int menu_registro(int *ptr_padron, int *ptr_num_carrera, char carrera[][30], char apellido[], char nombre[])
{
	int input_i = 0;

	puts(MSJ_REGISTRO);

	while(1)
	{
		printf("1) %s\n2) %s\n3) %s\n0) %s\n", REGISTRO_OPCION_NOMBRE, REGISTRO_OPCION_PADRON, REGISTRO_OPCION_CARRERA, OPCION_VOLVER);

		if(scanf("%i", &input_i) != 1)
		{
			fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			return EXIT_FAILURE;
		}
		while(getchar() != '\n');

		if(input_i == 1)
		{
			printf("%s: ", REGISTRO_ING_APELLIDO);
			if(scanf("%s", apellido) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				return EXIT_FAILURE;
			}
			while(getchar() != '\n');

			printf("%s: ", REGISTRO_ING_NOMBRE);

			if(scanf("%s", nombre) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_NOMBRE);
				return EXIT_FAILURE;
			}
			while(getchar() != '\n');

			printf("%s: %s, %s\n", REGISTRO_ING_AVISO, apellido, nombre);
		}
		else if(input_i == 2)
		{
			printf("%s: ", REGISTRO_ING_PADRON);
			if(scanf("%i", ptr_padron) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_PADRON);
				return EXIT_FAILURE;
			}
			while(getchar() != '\n');
			printf("%s: %i\n", REGISTRO_ING_AVISO, *ptr_padron);
		}
		else if(input_i == 3)
		{
			printf("%s: ", REGISTRO_ING_CARRERA);
			if(scanf("%i", ptr_num_carrera) != 1)
			{
				fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_CARRERA);
				return EXIT_FAILURE;
			}
			while(getchar() != '\n');

			printf("%s: ", REGISTRO_ING_AVISO);
			imprimir_carrera(*ptr_num_carrera, carrera);
		}
		else if(input_i == 0)
		{
			break;
		}
		else
		{
			fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_OPCIONES);
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS; /* Solo se sale exitosamente si se activa el break; */
}
