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

int inicializarTrabajos(eTrabajo lista[], int tam)
{
	int todoOk = -1; //error

	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			lista[i].isEmpty = 1; //vacio la lista de trabajos
		}

		todoOk = 1; //todo OK
	}

	return todoOk;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{

	int indice = -1; //error

	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 1){  //busco un espacio vacio en mi lista
				indice = i; //indice del primer espacio vacio en la lista de trabajos
				break;
			}
		}
	}

	return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, int* pId)
{
	int todoOk = 0;
	int indice;
	eTrabajo auxTrabajo;

	if(lista != NULL && tam > 0 && pId != NULL)
	{
		system("cls");
		printf("=====        *** ALTA TRABAJO ***        =====\n");

		indice = buscarLibreTrabajo(lista, tam);
		if(indice == -1)
		{
			printf(" ==> NO HAY LUGAR EN EL SISTEMA!\n");
		}else
		{
			auxTrabajo.id = *pId;
			(*pId)++; //id autoincremental

			printf(" --> Ingrese el ID de su mascota: "); //VALIDAR QUE EXISTA
			fflush(stdin);
			scanf("%d", &auxTrabajo.idMascota);

			printf(" --> Ingrese el ID del servicio deseado: "); //VALIDAR QUE EXISTA
			scanf("%d", &auxTrabajo.idServicio);

			printf(" --> Ingrese la fecha: "); //VALIDAR QUE EXISTA
			scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

			auxTrabajo.isEmpty = 0;

			lista[indice] = auxTrabajo;

			todoOk = 1;
		}
	}

	return todoOk;
}

int mostrarTrabajos(eTrabajo lista[], int tam)
{
	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE MOTOS   ***        =====\n");
		printf("   ID  | ID MASCOTA  | ID SERVICIO  | FECHA  \n");
		printf("-------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarTrabajo(lista[i]); //muestro los trabajos de la lista que haya
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo)
{
	printf(" %5d %5d  %5d    %2d/%2d/%4d\n",
			unTrabajo.id,
			unTrabajo.idMascota,
			unTrabajo.idServicio,
			unTrabajo.fecha.dia,
			unTrabajo.fecha.mes,
			unTrabajo.fecha.anio);
}
