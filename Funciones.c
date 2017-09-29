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
    fprintf(archivo,"%s\n%s\n%s\n\n",nombre,apellido,profesion);
    fclose(archivo);
}



void String_Copy (char* Str_Inicio,char *Str_Destino)
{
	int i = 0;

    while (Str_Inicio[i] != '\0')
    {
    	Str_Destino[i] = Str_Inicio[i];
        i++;
    }
}


int String_Compare (char *s1,char *s2)
{
    int count = 0;
    int cont = 0;

    while(s1[count] != '\0')
    {
        count++;
    }

    while(s2[cont] != '\0')
    {
        cont++;
    }

    if (count != cont)
    {
        return 0;
    }

    count = 0;

    while(count < cont)
    {
        if (s1[count] != s2[count])
        {
            return 0;
        }
        count++;
    }

    return 1;
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

    pointer -> next = NULL;

    printf("Ingresar nombre del archivo\n");
    scanf("%s",(pointer -> nombre_archivo));
}


void Lista_Ranking (_pNodo listita,char *_p1,char *_p2,char *_p3)
{
   _pNodo pointer,aux;

   aux = listita;

   pointer = (_pNodo) malloc (sizeof(Node));

    if (pointer == NULL)
    {
        printf("No space available\n");
    }

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

    pointer -> next = NULL;

    String_Copy(_p1,pointer -> Nombre);
    String_Copy(_p2,pointer -> Apellido);
    String_Copy(_p3,pointer -> Profesion);
}



void Ranking (void)
{
    int enter = 1;
    int intervencion = 0;
    int repe;
    char nombrecito[20] = "xxx";
    char apellidito[20] = "xxx";
    char profesion[20] = "xxx";
    char *n,*a,*p;

    _Nombrecito pointercito,auxiliar;
    _pNodo lista_rank,aux,auxilio,repetidos,aux_repe;

    FILE *out,*archivo_1;

    n = nombrecito;
    a = apellidito;
    p = profesion; 

    out = fopen("Ranking","w+");

    lista_rank = (_pNodo) malloc (sizeof(Node));

    lista_rank -> next = NULL;

    pointercito = (_Nombrecito) malloc (sizeof(Nuevito));

    pointercito -> next = NULL;

    repetidos = (_pNodo) malloc (sizeof(Node));

    String_Copy(nombrecito,repetidos -> Nombre);  
    String_Copy(apellidito,repetidos -> Apellido);   
    String_Copy(profesion,repetidos -> Profesion);  
    repetidos -> next = NULL;

    while(enter != 0)
    {
       Nombre_Archivo(pointercito);
       printf("Desea ingresar otro archivo?\n1. SI\n0. NO\n\n");
       scanf("%d",&enter);
    }

    auxiliar = pointercito -> next;
    archivo_1 = fopen(auxiliar -> nombre_archivo,"r");

    while(auxiliar != NULL)
    {
        while(fscanf(archivo_1,"%s %s %s",nombrecito,apellidito,profesion) != EOF)
        {
           Lista_Ranking(lista_rank,n,a,p);
        }
        auxiliar = auxiliar -> next;
        archivo_1 = fopen(auxiliar -> nombre_archivo,"r");
    }

    aux = lista_rank -> next;
    auxilio = lista_rank -> next;
    aux_repe = repetidos;

    while(aux != NULL)
    {
       while(aux_repe != NULL)
       {
          if (String_Compare(aux -> Nombre,aux_repe -> Nombre) == 1  && String_Compare(aux -> Apellido,aux_repe -> Apellido) == 1  && String_Compare(aux -> Profesion,aux_repe -> Profesion) == 1)
          {
            repe = SI;
            break; 
          }

          else
          {
            repe = NO;
          }
          aux_repe = aux_repe -> next;
        }
        
        aux_repe = repetidos;

          if(repe == NO)
          {
            while(auxilio != NULL)
            {
                if (String_Compare(aux -> Nombre,auxilio -> Nombre) == 1  && String_Compare(aux -> Apellido,auxilio -> Apellido) == 1  && String_Compare(aux -> Profesion,auxilio -> Profesion) == 1)
                {
                    intervencion++;
                }
                auxilio = auxilio -> next;
            }
            fprintf(out,"Nombre: %s\nApellido: %s\nProfesion: %s\nIntervenciones: %d\n\n",aux -> Nombre,aux -> Apellido,aux -> Profesion,intervencion);
            Lista_Ranking(repetidos,aux -> Nombre,aux -> Apellido,aux -> Profesion);
            intervencion = 0;
            auxilio = lista_rank -> next;
          }
       aux = aux -> next;
    }
}


