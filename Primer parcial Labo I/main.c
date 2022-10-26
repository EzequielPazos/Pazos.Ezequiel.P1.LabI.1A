#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "mascotas.h"
#include "trabajos.h"
#include "menus.h"
#include "Informes.h"

#define TAM_T 5
#define TAM_C 5
#define TAM_S 3
#define TAM_M 100
#define TAM_TRA 100

int main()
{
   	eTipo listaTipos[TAM_T] = {			//hardcodeo del array de la estructura tipos
		{1000, "Ave"},
		{1001, "Perro"},
		{1002, "Roedor"},
		{1003, "Gato"},
		{1004, "Pez"}
	};

	eColor listaColores[TAM_C] = {			//hardcodeo del array de la estructura colores
		{5000, "Negro"},
		{5001, "Blanco"},
		{5002, "Rojo"},
		{5003, "Gris"},
		{5004, "Azul"}
	};

	eServicio listaServicios[TAM_S] = {			//hardcodeo del array de la estructura servicios
		{20000, "Corte", 450},
		{20001, "Desparacitado", 800},
		{20002, "Castrado", 600}
	};

    char seguir = 's';
    char seguirInformes = 's';
    int siguienteIdMascota = 1;
    int siguienteIdTrabajo = 50000;
    int flagPrimerAlta = 0;
    int flagPrimerAltaTrabajo = 0;
    eMascota listaMascotas[TAM_M];
    eTrabajo listaTrabajos[TAM_TRA];

    if( !inicializarMascotas(listaMascotas, TAM_M)){                    //inicializo las mascotas --> las vacio
		printf("Ocurrio un problema al inicializar las mascotas");
	}

    if( !inicializarTrabajos(listaTrabajos, TAM_TRA)){
		printf("Ocurrio un problema al inicializar trabajos");
	}

	do{

		switch(menuOpciones())
		{
			case 'A':
                if(altaMascota(listaMascotas, TAM_M, &siguienteIdMascota, listaTipos, TAM_T, listaColores, TAM_C)){
					printf("\n --> EL ALTA FUE REALIZADA CON EXITO! \n\n");
					flagPrimerAlta = 1;
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON EL ALTA! \n\n");
				}
				break;
			case 'B':
				if(flagPrimerAlta){
					if(modificarMascota(listaMascotas, TAM_M, listaTipos, TAM_T, listaColores, TAM_C)){
						printf("\n --> LA MODIFICACION FUE REALIZADA CON EXITO! \n\n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA CON LA MODIFICACION! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MASCOTA DE ALTA!  \n\n");
				}
				break;
			case 'C':
				if(flagPrimerAlta){
					if(bajaMascota(listaMascotas, TAM_M, listaTipos, TAM_T, listaColores, TAM_C)){
						printf("\n --> LA BAJA FUE REALIZADA CON EXITO! \n\n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA CON LA BAJA! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MASCOTA DE ALTA!  \n\n");
				}
				break;
			case 'D':
				if(flagPrimerAlta){
					if(ordenarMascotasPorTipoNombre(listaMascotas, TAM_M)){
						printf("\n --> LA LISTA FUE ORDENADA CON EXITO! \n\n");
						mostrarMascotas(listaMascotas, TAM_M, listaTipos, TAM_T, listaColores, TAM_C);
					}else
					{
						printf("\n --> HUBO UN PROBLEMA AL ORDENAR LA LISTA! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MASCOTA DE ALTA!  \n\n");
				}
				break;
			case 'E':
				if(mostrarTipos(listaTipos, TAM_T)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 'F':
				if(mostrarColores(listaColores, TAM_C)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 'G':
				if(mostrarServicios(listaServicios, TAM_S)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 'H':
				if(altaTrabajo(listaTrabajos, TAM_TRA, &siguienteIdTrabajo)){
					printf("\n --> EL ALTA FUE REALIZADA CON EXITO! \n\n");
					flagPrimerAltaTrabajo = 1;
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON EL ALTA! \n\n");
				}
				break;
			case 'I':
				if(flagPrimerAltaTrabajo){
					if(mostrarTrabajos(listaTrabajos, TAM_TRA)){
						printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n");
					}
				}
				else{
						printf("\n --> TODAVIA NO SE HA DADO NINGUN TRABAJO DE ALTA!  \n");
				}
				break;
            case 'J':

                do{
                    switch(menuInformes())
                    {
                    case 'a':
                        if(flagPrimerAlta)
                        {
                            if(mostrarMascotasUnColor(listaMascotas,listaColores,TAM_M,TAM_C)){
                                printf("\n --> EL INFORME FUE MOSTRADO CON EXITO! \n\n");
                            }else
                            {
                                printf("\n --> HUBO UN PROBLEMA AL MOSTRAR EL INFORME \n\n");
                            }
                        }else
                        {
                            printf("\n --> TODAVIA NO SE HA DADO NINGUNA MASCOTA DE ALTA!  \n\n");
                        }
                        break;
                    case 'b':
                        if(flagPrimerAlta)
                        {
                            if(promedioMascotasVacunadas(listaMascotas,TAM_M)){
                                printf("\n --> EL INFORME FUE MOSTRADO CON EXITO! \n\n");
                            }else
                            {
                                printf("\n --> HUBO UN PROBLEMA AL MOSTRAR EL INFORME \n\n");
                            }
                        }else
                        {
                            printf("\n --> TODAVIA NO SE HA DADO NINGUNA MASCOTA DE ALTA!  \n\n");
                        }
                        break;
                    case 'c':

                        break;
                    case 'd':
                        break;
                    case 'e':
                        break;
                    case 'f':
                        break;
                    case 'g':
                        break;
                    case 'h':
                        break;
                    case 'i':
                        break;
                    case 'j':
                        break;
                    case 'k':
                        seguirInformes = 'n';
                        break;
                    default:
                        printf("\n\n==> LA OPCION INGRESADA ES INVALIDA\n\n"); //validacion de cualquier error de ingreso
                    }

                printf("\n\n");
                system("pause");

                }while(seguirInformes == 's');

                break;
			case 'K':
				seguir = 'n';
				break;
			default:
				printf("\n\n==> LA OPCION INGRESADA ES INVALIDA\n\n"); //validacion de cualquier error de ingreso
		}

    printf("\n\n");
    system("pause");

	}while(seguir == 's');

}
