#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#define TAM_Servicios 4

typedef struct
{
    int id;
    char descripcion[24];
    float precio;

}eServicio;

int mostrarUnServicio(eServicio* list);
int listarServicios(eServicio list[],int tam);
int cargarDescripServicio(eServicio list[],int tam,char* cadena,int idSer);
int get_MontoServicio(eServicio list[],int tam,int* monto,int idSer);

#endif // SERVICIO_H_INCLUDED


