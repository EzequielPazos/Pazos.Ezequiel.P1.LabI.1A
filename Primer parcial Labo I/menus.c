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

char menuOpciones(){

    char opcionDeseada;

    system("cls");

    printf("*** --- VETERINARIA PATITAS --- ***\n\n");
    printf("A. ALTA MASCOTA\n");
    printf("B. MODIFICAR MASCOTA\n");
    printf("C. BAJA MASCOTA\n");
    printf("D. LISTAR MASCOTAS\n");
    printf("E. LISTAR TIPOS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. SALIR\n\n");
    printf("==> INGRESE LA OPCION DESEADA: ");

    opcionDeseada = getche(); //me permite deshacerme de un posible error por escribir mas de un caracter antes de presionar el enter

    opcionDeseada = toupper(opcionDeseada);

    if(!isalpha(opcionDeseada)){ //informe de que no se permiten numeros
        printf("\n\n==> NO SE ADMITEN NUMEROS!");
    }

    return opcionDeseada;
}
