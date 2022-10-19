#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct{
    int id; //(autoincremental)
    int idMascota; //(debe existir) Validar
    int idServicio; //(debe existir) Validar
    eFecha fecha; //(Validar d�a, mes y a�o)
    int isEmpty; //1 si vacio, 0 si lleno
}eTrabajo;

#endif // TRABAJOS_H_INCLUDED

void mostrarTrabajo(eTrabajo unTrabajo);
int mostrarTrabajos(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo lista[], int tam, int* pId);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int inicializarTrabajos(eTrabajo lista[], int tam);

