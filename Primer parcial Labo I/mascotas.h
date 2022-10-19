#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int idTipo; //Validar
    int idColor; //Validar
    int edad;
    char vacunado; //s o n
    int isEmpty; //1 si vacio, 0 si lleno
}eMascota;

#endif // MASCOTAS_H_INCLUDED

int inicializarMascotas(eMascota lista[], int tam);
int buscarLibre(eMascota lista[], int tam);
int altaMascota(eMascota lista[], int tam, int* pId, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c);
int modificarMascota(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c);
int mostrarMascotas(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c);
void mostrarMascota(eMascota unaMascota, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c);
int bajaMascota(eMascota lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c);
int buscarMascotaPorId(eMascota lista[], int tam, int id);
int ordenarMascotasPorTipoNombre(eMascota lista[], int tam);
