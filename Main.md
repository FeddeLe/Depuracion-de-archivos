#include "Header.h"

int main (void)
{
	int usuario = 1;
	int input = 1;
	char Nombre_Archivo[30];
	char nombre[20];
	char apellido[20];
	char Profesion[20];
	char *N,*A,*P,*N_A;

	N = nombre;
	A = apellido;
	P = Profesion;
	N_A = Nombre_Archivo;
	_pNodo Lista_Inicial;

    Lista_Inicial = (_pNodo) malloc (sizeof(Node));
	Lista_Inicial -> next = NULL;

	while (usuario != 0)
	{
		printf("1. Crear nuevo archivo\n2. Modificar Archivo\n3. Generar Ranking\n0. Cerrar\n\n\n");
		scanf("%d",&usuario);

		switch (usuario)
		{
			case 1:
			   printf("Ingrese nombre del archivo a crear\n");
			   scanf("%s",N_A);
			   Crear_Archivo(N_A);
			   break;

			case 2:
			   printf("Ingrese nombre del archivo que desea abrir\n");
			   scanf("%s",N_A);
			   while(input != 0)
			   {	
			     printf("Ingrese apellido\n");
			     scanf("%s",A);
			     printf("Ingrese nombre\n");
                 scanf("%s",N);
			     printf("Ingrese profesion\n");
			     scanf("%s",P);
			     Nueva_Persona(Lista_Inicial,N,A,P,N_A);
			     printf("Ingresar nuevo registro?\n1. SI\n0. NO\n");
			     scanf("%d",&input);
			   }
			   break;

			   case 3:
			      Ranking();
			      break;
		}
	}
	return 0;
}
