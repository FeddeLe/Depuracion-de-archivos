# Depuracion-de-archivos

#include "Header.h"

void Crear_Archivo (char *Nombre_Archivo)
{
	FILE *archivo;

	archivo = fopen(Nombre_Archivo,"w+");

	fclose(archivo);
}


void Nueva_Persona (_pNodo Lista_Inicial,char *nombre,char *apellido,char *profesion,char *Nombre_Archivo)
{
	FILE *archivo;

    archivo = fopen(Nombre_Archivo,"a");
    fprintf(archivo, "%s\n%s\n%s\n\n",nombre,apellido,profesion);
    fclose(archivo);
}



void String_Copy (char* Str_Inicio,char *Str_Destino)
{
	int i = 0;

    while (Str_Inicio[i] != '\0')
    {
    	Str_Destino[i] = Str_Inicio[i];
    }
}



void Ranking (void)
{
    int enter = 1;

    _Nombrecito pointercito,auxiliar;

    FILE *out;

    out = fopen("Ranking","w+");

    pointercito = (_Nombrecito) malloc (sizeof(Nuevito));

    pointercito -> next = NULL;

    while(enter != 0)
    {
       Nombre_Archivo(pointercito);
       printf("Desea ingresar otro archivo?\n1. SI\n0. NO\n\n");
       scanf("%d",&enter);
    }

    auxiliar = pointercito;

    while(auxiliar -> next != NULL)
    {
       printf("%s\n",auxiliar -> nombre_archivo);
       auxiliar = auxiliar -> next;
    }
}


void Nombre_Archivo (_Nombrecito listita)
{
   _Nombrecito pointer,aux;

   aux = listita;

   pointer = (_Nombrecito) malloc (sizeof(Nuevito));

    if (pointer == NULL)
    {
        printf("No space available\n");
    }

    pointer -> next = NULL;

    if (listita -> next == NULL)
    {
        listita -> next = pointer;
    }

    else
    {
        while(aux -> next != NULL)
        {
            aux = aux -> next;
        }
        aux -> next = pointer;
    }

    printf("Ingresar nombre del archivo\n");
    scanf("%s",(pointer -> nombre_archivo));
}
