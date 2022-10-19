#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "mascotas.h"
#include "tipos.h"
#include "colores.h"
#include "trabajos.h"
#include "servicios.h"
#include "menus.h"
#include "fecha.h"

int mostrarServicios(eServicio lista[], int tam){

	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE SERVICIOS   ***        =====\n");
		printf("   ID  |   DESCRIPCION   | PRECIO\n");
		printf("-------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf(" %d     %13s     %.2f\n", lista[i].id, lista[i].descripcion, lista[i].precio);
		}
		todoOk = 1;
	}

	return todoOk;
}
