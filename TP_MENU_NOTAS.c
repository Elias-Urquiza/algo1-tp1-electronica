#include <stdio.h>
#include <stdlib.h>
#define TEXT_INGRESO "+)Ingreso de materia."
#define TEXT_SALIDA "!)Salir."
#define TEXT_BORRAR "-)Eliminar una asignatura."
#define TEXT_PREGUNTA "? "
#define TEXT_NOTA "Ingrese la nota: "
#define TEXT_MATERIA "Ingrese la materia: "
#define TEXT_ELEC_BORRAR "Ingrese el numero de la materia que desea borrar: "
#define ERR_PREFIJO "Error"
#define ERR_INGRESO_MATERIA "La materia fue mal ingresada."
#define ERR_INGRESO_NOTA "La nota fue mal ingresada."
#define ERR_ELEC "La eleccion realizada no esta permitida."
#define OUT 0
#define IN 1

/*procesos definidos (proximamente movidos)*/

void printm(char mat[][16],int not[][1], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c-2;j++)
            printf("%c", mat[i][j]);
            printf("%c %i\n", mat[i][j],not[i][1] );
    }
}
void print_opciones(char mat[][16],int not[][1], int c, int CANT)
{
    int j;
    {
        printf("%i)",CANT);
        for(j=0;j<c-2;j++)
        {

            printf("%c", mat[CANT][j]);
        }
            printf("%c(%i)\n", mat[CANT][j],not[CANT][0] );
    }
}
void pasada(int m[][10],int fila)
{

}

void clrnot(int m[][1], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<=c;j++)
            m[i][j]='\0';
}
void clrmat(char m[][16], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            m[i][j]='\0';
}
void clr_regrab(char m[][16], int r, int c)
{
    int i;
    for(i=0;i<r;i++)
        m[c][i]='\0';
}

    /*Programa principal*/

int main(void)
{
    /*Defino un rango de las matrices junto a un par de valores auxiliares*/

    char  MATERIA[10][16], ELEC;
    int NOTA[10][1], ENTRADA=IN, CANT_MAT=0, NUMB, ELEC_BORR,COLUMNA, NUMERO;

    /*Limpio las matrices de cualquier valor al azar definido por el programa*/

    clrmat(MATERIA, 10, 16);
    clrnot(NOTA, 10, 1);

    /*Ingreso del programa*/

    while(ENTRADA==IN)
    {
        NUMB=0;
    /*Menu inicial*/

        if(CANT_MAT>0)
        {
            while(NUMB<CANT_MAT)
            {
                print_opciones( MATERIA, NOTA, 16, NUMB);
                NUMB++;

            }
            printf("%s\n", TEXT_BORRAR);
        }
		printf("%s\n",TEXT_INGRESO);
        printf("%s\n", TEXT_SALIDA);
        printf("%s", TEXT_PREGUNTA);

    /*Ingreso de la opcion*/

        if(scanf("%c",&ELEC)!=1)
            {
            fprintf(stderr,"%s: %s\n", ERR_PREFIJO, ERR_ELEC);
            return EXIT_FAILURE;
            }
        while(getchar()!='\n')
        ;

    /*Eleccion de ingreso de asignatura*/

        if(ELEC=='+')
        {
            printf("%s", TEXT_MATERIA);
            if((scanf("%s",MATERIA[CANT_MAT]))!=1)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_INGRESO_MATERIA);
                return EXIT_FAILURE;
            }
            while(getchar()!='\n')
            ;
            printf("%s", TEXT_NOTA);

            if(scanf("%i",NOTA[CANT_MAT])!=1||NOTA[CANT_MAT][0]>10||NOTA[CANT_MAT][0]<0)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_INGRESO_NOTA);
                return EXIT_FAILURE;
            }
            while(getchar()!='\n')
            ;
            CANT_MAT++;
            printf("\n");
        }

    /*Salida del programa*/

        else if(ELEC=='!')
        {
        ENTRADA=OUT;
        }

    /*Eliminación de asignatura*/

        else if(ELEC=='-')
        {
           if(CANT_MAT==0)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
                return EXIT_FAILURE;
            }
            printf("%s",TEXT_ELEC_BORRAR);
            if(scanf("%i", &ELEC_BORR)!=1)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
                return EXIT_FAILURE;
            }
            while(getchar()!='\n')
                ;
            if(ELEC_BORR+1>CANT_MAT||ELEC_BORR<0)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
                return EXIT_FAILURE;
            }
            while(ELEC_BORR<9)
            {
                for(COLUMNA=0;COLUMNA<16;COLUMNA++)
				{
                	MATERIA[ELEC_BORR][COLUMNA]=MATERIA[ELEC_BORR+1][COLUMNA];

				}
                COLUMNA=0;
				NOTA[ELEC_BORR][0]=NOTA[ELEC_BORR+1][0];
                ELEC_BORR++;
            }
            CANT_MAT--;
        }

    /*Sobre escritura de asignaturas*/

        else
        {
             ELEC=ELEC-48;
             NUMERO=ELEC;
             if(NUMERO>=CANT_MAT||CANT_MAT==0)
             {
                 fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_ELEC);
                 return EXIT_FAILURE;
             }
             clr_regrab(MATERIA, 16, NUMERO);
             printf("%s", TEXT_MATERIA);
             if(scanf("%s",MATERIA[NUMERO])!=1)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_INGRESO_MATERIA);
                return EXIT_FAILURE;
            }
             while(getchar()!='\n')
             ;
             printf("%s", TEXT_NOTA);
             if(scanf("%i",NOTA[NUMERO])!=1||NOTA[NUMERO][0]>10||NOTA[CANT_MAT][0]<0)
            {
                fprintf(stderr, "%s: %s\n", ERR_PREFIJO, ERR_INGRESO_NOTA);
                return EXIT_FAILURE;
            }
            while(getchar()!='\n')
			
                ;
            printf("\n");
        }
    }
    return EXIT_SUCCESS;
}
