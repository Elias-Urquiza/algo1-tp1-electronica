#include "main.h"

#define REGISTRO_OPCION_NOMBRE "Apellido y Nombre"
#define REGISTRO_OPCION_PADRON "Padrón"
#define REGISTRO_OPCION_CARRERA "Carrera"

#define REGISTRO_ING_APELLIDO "Ingrese Apellido"
#define REGISTRO_ING_NOMBRE "Ingrese Nombre"
#define REGISTRO_ING_PADRON "Ingrese su padrón"
#define REGISTRO_ING_CARRERA "Ingrese el número correspondiente a su carrera"

#define REGISTRO_ING_AVISO "Queda registrado lo siguiente"
#define OPCION_VOLVER "Volver"

#define ERR_REG_NOMBRE "No se pudo leer el nombre ingresado."
#define ERR_REG_PADRON "El padrón ingresado no se pudo leer."
#define ERR_REG_CARRERA "El número de carrera ingresado no es válido."

#define ING_1 "Ingeniería Civil"
#define ING_2 "Ingeniería Industrial"
#define ING_3 "Ingeniería Naval y Mecánica"
#define ING_4 "Ingeniería en Agrimensura"
#define ING_5 "Ingeniería Mecánica"
#define ING_6 "Ingeniería Electricista"
#define ING_7 "Ingeniería Electrónica"
#define ING_8 "Ingeniería Química"
#define ING_9 "Lic. en Análisis de Sistemas"
#define ING_10 "Ingeniería en Informática"
#define ING_11 "Ingeniería en Alimentos"

/*La dejo como funcion definida aparte asi se utiliza en la opción finalizar*/
void imprimir_carrera(int fila, char carrera[11][30]);
/*Esto cuenta como hard-codeo? En todo caso 11 seria una constante de numero de carreras y 30 max_nombre de carrera*/

int main(void)
{
  int input_i;
  char apellido[50];
  char nombre[50];
  int padron;
  int sel_carrera;
  char carrera[11][30] = {{ING_1}, {ING_2}, {ING_3}, {ING_4}, {ING_5}, {ING_6}, {ING_7}, {ING_8}, {ING_9}, {ING_10}, {ING_11}}; /*use [30] pero podriamos buscar bien cual es el maximo numero de caracteres que puede usarse y cambiarlo*/
  /*Incluir estas variables en main() */

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
      if(scanf("%i", &padron) != 1)
      {
        fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_PADRON);
        return EXIT_FAILURE;
      }
      while(getchar() != '\n');

      printf("%s: %i\n", REGISTRO_ING_AVISO, padron);
    }
    else if(input_i == 3)
    {
      printf("%s: ", REGISTRO_ING_CARRERA);

      if(scanf("%i", &sel_carrera) != 1)
      {
        fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_REG_CARRERA);
        return EXIT_FAILURE;
      }
      while(getchar() != '\n');

      printf("%s: ", REGISTRO_ING_AVISO);

      imprimir_carrera(sel_carrera, carrera);
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

  return EXIT_SUCCESS;
}

void imprimir_carrera(int fila, char carrera[11][30])
{
  printf("%s\n", carrera[fila - 1]);
}
