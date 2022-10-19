#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{
    int id; //(comienza en 5000)
    char descripcion[20];
}eColor;

#endif // COLORES_H_INCLUDED

int mostrarColores(eColor lista[], int tam);
int validarIdColor(eColor lista[], int tam, int id);
int cargarDescripcionColor(eColor lista[], int tam, int idColor, char descripcion[]);
