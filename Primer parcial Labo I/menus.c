#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "menus.h"

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
    printf("J. INFORMES\n");
    printf("K. SALIR\n\n");
    printf("==> INGRESE LA OPCION DESEADA: ");

    opcionDeseada = getche(); //me permite deshacerme de un posible error por escribir mas de un caracter antes de presionar el enter

    opcionDeseada = toupper(opcionDeseada);

    if(!isalpha(opcionDeseada)){ //informe de que no se permiten numeros
        printf("\n\n==> NO SE ADMITEN NUMEROS!");
    }

    return opcionDeseada;
}

char menuInformes(){

    char opcionDeseada;

    system("cls");

    printf("*** --- INFORMES MASCOTAS --- ***\n\n");
    printf("a. MASCOTAS DE UN COLOR\n");
    printf("b. PROMEDIO DE MASCOTAS VACUNADAS\n");
    printf("c. MASCOTAS DE MENOR EDAD\n");
    printf("d. MASCOTAS SEGUN TIPO\n");
    printf("e. CANTIDAD DE MASCOTAS SEGUN UN COLOR Y UN TIPO\n");
    printf("f. COLORES CON MAS MASCOTAS\n");
    printf("g. TRABAJOS DE UNA MASCOTA\n");
    printf("h. SUMA DE IMPORTES DE LOS SERVICIOS DE UNA MASCOTA\n");
    printf("i. MASCOTAS Y FECHAS A LAS QUE SE LES REALIZO UN SERVICIO\n");
    printf("j. SERVICIOS EN UNA FECHA\n");
    printf("k. SALIR\n\n");
    printf("==> INGRESE LA OPCION DESEADA: ");

    opcionDeseada = getche(); //me permite deshacerme de un posible error por escribir mas de un caracter antes de presionar el enter

    opcionDeseada = tolower(opcionDeseada);

    if(!isalpha(opcionDeseada)){ //informe de que no se permiten numeros
        printf("\n\n==> NO SE ADMITEN NUMEROS!");
    }

    return opcionDeseada;
}
