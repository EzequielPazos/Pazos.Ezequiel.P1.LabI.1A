#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "tipos.h"
#include "colores.h"
#include "mascotas.h"

int obtenerNombreMascota(eMascota lista[], int tam, int idMascota, char nombre[])
{
	int todoOk = 1;

	if(lista != NULL && tam>0 && nombre !=NULL)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == idMascota && lista[i].isEmpty == 0)
			{
				strcpy(nombre, lista[i].nombre);
				todoOk = 0;
				break;
			}
		}
	}
	return todoOk;
}

int mostrarMascotasUnColor(eMascota lista[], eColor listaColores[],  int tam, int tam_c)
{
	int todoOk = 1;
	int idColorElegido;
	int flag = 0;
	char nombre[20];

	if(lista !=NULL && tam>0 && listaColores !=NULL && tam_c>0) //validaciones de nulos y tamanios
	{
		system("cls");
		printf("==> Mascotas del color elegido\n\n");

		mostrarColores(listaColores, tam_c); //muestro la lista de colores

		printf("\n\n==> Ingrese el ID del color deseado: ");    //pido al usuario un ID del color que desea
		scanf("%d", &idColorElegido);
		while(validarIdColor(listaColores, tam_c, idColorElegido) == 0) //se valida
		{
			printf("\n\n==> La id ingresada no es valida! Intente nuevamente: \n");
			scanf("%d", &idColorElegido);
		}

		for(int i=0;i<tam;i++)
		{
			if(lista[i].idColor == idColorElegido)
			{
				obtenerNombreMascota(lista, tam, lista[i].id, nombre);
				printf("\n\n==> Mascotas del color elegido\n\n");
				printf("\n%s", nombre);
				flag = 1;
			}
		}

		if(flag ==0)
		{
			printf("\n\n==> No existe ninguna mascota de ese color\n\n");
		}

		todoOk = 0;
	}
	return todoOk;
}

int promedioMascotasVacunadas(eMascota lista[], int tam_m)
{
    int todoOk = 1; //error
    int cantidadMascotas = 0;
    int contadorVacunadas = 0;
    int promedioVacunadas;

    if(lista !=NULL && tam_m >0)
    {
        system("cls");

		for(int i=0;i<tam_m;i++)
		{
            if(lista[i].isEmpty == 1)
            {
                cantidadMascotas++;
                if(lista[i].vacunado == 's')
                {
                   contadorVacunadas++;
                }
            }
		}

		promedioVacunadas = (float)(contadorVacunadas*cantidadMascotas)/100;

		printf("==> Un %d porciento de las mascotas se encuentran vacunadas", promedioVacunadas);

		todoOk = 0;
    }

    return todoOk;
}

int mostrarMascotasMenores(eMascota lista[], int tam_m)
{
	int todoOk = 1;
	int primeraEdad = 81; //utilizo el maximo de la edad para poder comparar la primera edad y que asi la tome si o si
    int menorEdad;
    int flagPrimeraEdad = 0;

	if(lista !=NULL && tam_m>0)
	{
		system("cls");

		printf("==> Mascotas menores\n\n");

		for(int i=0;i<tam_m;i++)
		{
            if(!flagPrimeraEdad && lista[i].isEmpty == 0) //verifico si es la primera o edad y si existe la mascota
            {
                if(lista[i].edad < primeraEdad)
                {
                    menorEdad = lista[i].edad;
                    flagPrimeraEdad = 1;
                }
            }else
            {
                if(lista[i].edad < menorEdad && lista[i].isEmpty == 0) //si la edad de la siguiente mascota es menor a la menor edad y la mascota no ha sido dada de baja se reemplaza
                {
                    menorEdad = lista[i].edad;
                }
            }
		}

        printf("Lista de mascotas con la menor edad de %d", menorEdad);
		for(int i=0;i<tam_m;i++)
        {
            printf("4%d - 10%s", lista[i].id,lista[i].nombre);
        }

		todoOk = 0;
	}
	return todoOk;
}
