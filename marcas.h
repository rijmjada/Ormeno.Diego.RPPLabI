#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[24];
}eMarca;

int listarMarcas(eMarca list_M[],int len);
void mostrarUnaMarca(eMarca* unaMarca);
int cargarDescripMarca(eMarca list[],int tam,char* cadena,int idMarca);
#endif // MARCAS_H_INCLUDED

