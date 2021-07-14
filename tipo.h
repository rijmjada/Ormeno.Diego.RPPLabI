#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

#define ERROR -1
#define ALLOK 1

typedef struct
{
    int id;
    char descripcion[24];
}eTipo;


void mostrarUnTipo(eTipo* tipo);
int listarTipos(eTipo listaTipos[],int tamTipos);
void cabeceraTipos();
int cargarDescripTipo(eTipo list[],int tam,char* cadena,int idTipo);
#endif // TIPO_H_INCLUDED
