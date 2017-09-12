#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	char Nombre[20];
	char Apellido[20];
	char Profesion[20];
	int Intervencion;
	struct Nodo *next;
}Node;

typedef struct New_Archive
{
	char nombre_archivo[20];
	struct New_Archive *next;
}Nuevito;

typedef Node *_pNodo;
typedef Nuevito *_Nombrecito;

void Crear_Archivo (char*);
void Nueva_Persona (_pNodo,char*,char*,char*,char*);
void Ranking (void);
void String_Copy (char*,char*);
void Nombre_Archivo (_Nombrecito);
