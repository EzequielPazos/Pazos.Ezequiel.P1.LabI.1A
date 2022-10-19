#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{
    int id; //(comienza en 1000)
    char descripcion[20];
}eTipo;

#endif // TIPOS_H_INCLUDED

int mostrarTipos(eTipo lista[], int tam);
int validarIdTipo(eTipo lista[], int tam, int id);
int cargarDescripcionTipo(eTipo lista[], int tam, int idTipo, char descripcion[]);
