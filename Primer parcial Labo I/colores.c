#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "colores.h"


int mostrarColores(eColor lista[], int tam){

	int todoOk = 0; //error

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE COLORES   ***        =====\n");
		printf("   ID  | DESCRIPCION\n");
		printf("-------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf(" %d     %10s\n", lista[i].id, lista[i].descripcion);
		}
		todoOk = 1; //todo OK
	}

	return todoOk;
}

int validarIdColor(eColor lista[], int tam, int id){

	int existe = 0; //no existe

	if(lista !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == id)
			{
				existe = 1; //si existe
				break;
			}
		}
	}
	return existe;
}

int cargarDescripcionColor(eColor lista[], int tam, int idColor, char descripcion[]){

	int todoOk = 0;

	if(lista !=NULL && tam>0 && descripcion !=NULL){
		for(int i=0; i<tam;i++)
		{
			if(lista[i].id == idColor){
				strcpy(descripcion, lista[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
