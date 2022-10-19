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

int inicializarMascotas(eMascota lista[], int tam)
{
	int todoOk = -1; //error

	if(lista !=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			lista[i].isEmpty = 1; //inicializo la lista de mascotas vaciandola
		}

		todoOk = 1; //todo OK
	}

	return todoOk;
}

int buscarLibre(eMascota lista[], int tam)
{

	int indice = -1; //error

	if(lista !=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 1){  //si esta vacio entonces utilizo ese indice de la lista --> AKA encontre uno libre
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int altaMascota(eMascota lista[], int tam, int* pId, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	int todoOk = 0; //error
	int indice;
	eMascota auxMascota;

	if(lista !=NULL && tam > 0 && pId != NULL) //validaciones
	{
		system("cls");
		printf("=====        *** ALTA MASCOTA ***        =====\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1)
		{
			printf(" ==> NO HAY LUGAR EN EL SISTEMA!\n");
		}else
		{
			auxMascota.id = *pId;
			(*pId)++; //id autoincremental

			printf("\n --> Ingrese el nombre de la mascota: ");
			fflush(stdin);
			gets(auxMascota.nombre);

			mostrarTipos(listaTipos, tam_t);	//muestro tipos
			printf("\n --> Ingrese el ID segun su tipo: ");  //ingreso tipos
			scanf("%d", &auxMascota.idTipo);

			while(!validarIdTipo(listaTipos, tam_t, auxMascota.idTipo)){		//validacion tipo existente
				mostrarTipos(listaTipos, tam_t);
				printf("\n --> El ID ingresado es invalido. Ingrese nuevamente: ");
				scanf("%d", &auxMascota.idTipo);
			}

			mostrarColores(listaColores, tam_c); //muestro colores
			printf("\n --> Ingrese el ID segun su color: "); //ingreso color
			scanf("%d", &auxMascota.idColor);

			while(!validarIdColor(listaColores, tam_c, auxMascota.idColor)){		//validacion color existente
				mostrarColores(listaColores, tam_c);
				printf("\n --> El ID ingresado es invalido. Ingrese nuevamente: ");
				scanf("%d", &auxMascota.idColor);
			}

            system("cls");

			printf("\n --> Ingrese la edad (1 a 80): ");
			scanf("%d", &auxMascota.edad);

			while(auxMascota.edad <1 || auxMascota.edad >80){ //validacion edad maxima --> perros 20//gatos 20//roedores 25//peces 20//aves 80
				printf("\n --> La edad ingresada es invalida. Ingrese nuevamente (1 a 80): ");
				scanf("%d", &auxMascota.edad);
			}

			printf("\n --> Esta vacunado? ('s' o 'n'): ");
			fflush(stdin);
			scanf("%c", &auxMascota.vacunado);
			auxMascota.vacunado = tolower(auxMascota.vacunado);

			while(auxMascota.vacunado !='s' && auxMascota.vacunado !='n'){
				printf("\n --> La respuesta ingresada es invalida. Ingrese nuevamente ('s' o 'n'): "); //validacion caracter correcto
				fflush(stdin);
				scanf("%c", &auxMascota.vacunado);
				auxMascota.vacunado = tolower(auxMascota.vacunado);
			}

			auxMascota.isEmpty = 0; //se lleno el espacio de la estructura

			lista[indice] = auxMascota;

			todoOk = 1;
		}
	}

	return todoOk;
}

int modificarMascota(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	int todoOk = 0; //error
	int id;
	int indice;
	int opcion;
	char seguir;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("=====        *** MODIFICAR MASCOTA ***        =====\n\n");
		mostrarMascotas(lista, tam, listaTipos, tam_t, listaColores, tam_c); //muestro las mascotas que hay actualmente
		printf(" --> INGRESE EL ID DE LA MASCOTA A MODIFICAR: ");
		scanf("%d", &id); //pido id

		indice = buscarMascotaPorId(lista, tam, id); //busco mascota por id

		if(indice == -1)
		{
			printf(" --> NO EXISTE UNA MASCOTA CON ESA ID!\n\n");
		}else
		{
			mostrarMascota(lista[indice], listaTipos, tam_t, listaColores, tam_c); //muestro la mascota indicada

			do{
				printf("QUE DESEA MODIFICAR?\n\n");
				printf("1 ---> TIPO\n");
				printf("2 ---> VACUNADO\n");
				printf("3 ---> VOLVER ATRAS\n");
				scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:

						mostrarTipos(listaTipos, tam_t);

						printf(" --> Ingrese el ID segun su tipo: ");
						scanf("%d", &lista[indice].idTipo);

						while(!validarIdTipo(listaTipos, tam_t, lista[indice].idTipo)){		//validacion tipo existente
							mostrarTipos(listaTipos, tam_t);
							printf(" --> El ID ingresado es invalido. Ingrese nuevamente: ");
							scanf("%d", &lista[indice].idTipo);
						}

						printf("\n\nEl cambio de tipo ha sido realizado con exito!");
						system("pause");
						break;
					case 2:
                        if(lista[id].vacunado == 's')   //ya que son dos opciones cambio de una a la otra para evitar errores por parte del usuario
                        {
                            lista[id].vacunado = 'n';
                        }else
                        {
                            lista[id].vacunado = 's';
                        }
						printf("\n\nEl cambio en la vacunacion ha sido realizado con exito!");
						system("pause");
						break;
					case 3:
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				todoOk = 1;
			}while(seguir == 's');
		}
	}
	return todoOk;
}

int mostrarMascotas(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE MASCOTAS   ***        =====\n");
		printf("   ID  | NOMBRE  | TIPO  | COLOR  | EDAD | VACUNADO\n");
		printf("--------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarMascota(lista[i], listaTipos, tam_t, listaColores, tam_c);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

void mostrarMascota(eMascota unaMascota, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	char descripcionTipo[20];
	char descripcionColor[20];

	cargarDescripcionTipo(listaTipos, tam_t, unaMascota.idTipo, descripcionTipo);
	cargarDescripcionColor(listaColores, tam_c, unaMascota.idColor, descripcionColor);

	printf(" %5d %10s %20s %20s %2d %c\n", //muestro una sola mascota
			unaMascota.id,
			unaMascota.nombre,
			descripcionTipo,
			descripcionColor,
			unaMascota.edad,
			unaMascota.vacunado);
}

int buscarMascotaPorId(eMascota lista[], int tam, int id)
{
	int indice = -1; //no existe

	for(int i=0;i<tam;i++)
	{
		if(lista[i].id == id)
		{
			indice = i; //mascota encontrada
			break;
		}
	}

	return indice;
}

int bajaMascota(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	int todoOk = 0; //error
	int indice;
	int id;
	char confirmar;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("=====        *** BAJA DE MASCOTAS ***        =====\n\n");
		mostrarMascotas(lista, tam, listaTipos, tam_t, listaColores, tam_c);
		printf(" --> Ingrese el ID de la mascota que desea dar de baja: ");
		scanf("%d", &id);

		indice = buscarMascotaPorId(lista, tam, id);

		if(indice == -1)
		{
			printf(" --> No existe ninguna mascota con esa ID!\n\n");
		}else
		{
			mostrarMascota(lista[indice], listaTipos, tam_t, listaColores, tam_c); //muestro la mascota en la interfaz
			printf(" --> Confirma el borrado? Ingrese s/n\n");
			fflush(stdin);
			scanf("%c", &confirmar);
			while(confirmar !='s' && confirmar !='n')
			{
				printf(" --> La respuesta ingresada no es valida. Ingrese s/n\n");
				fflush(stdin);
				scanf("%c", &confirmar);
			}

			if(confirmar =='s')
			{
				lista[indice].isEmpty = 1; //baja logica --> 1 significa vacio en el campo isEmpty
				todoOk = 1; //todo OK
			}
		}
	}
	return todoOk;
}

int ordenarMascotasPorTipoNombre(eMascota lista[], int tam){

	int todoOk = 0; //error
	eMascota aux;

	if(lista !=NULL && tam > 0){

		for(int i=0; i<tam-1; i++)
		{
			for(int j= i+1; j<tam; j++)
			{
				if(lista[i].idTipo < lista[j].idTipo || (lista[i].idTipo == lista[j].idTipo && lista[i].nombre < lista[j].nombre)) //ordenamiento por tipo y nombre decreciente
				{
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}

		todoOk = 1; //todo OK
	}
	return todoOk;
}
