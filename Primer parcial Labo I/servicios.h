#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
    int id; //(comienza en 20000)
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIOS_H_INCLUDED

int mostrarServicios(eServicio lista[], int tam);
