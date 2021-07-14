#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED

#define ERROR -1
#define ALLOK 1

#include "fecha.h"
#include "genericas.h"
#include "marcas.h"
#include "tipo.h"
#include "cliente.h"

typedef struct
{
    int id;
    int idCliente;
    char modelo[24];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;

int inicializarListaNotebook(eNotebook listaNotebook[],int tam);
int buscarEspacioLibre(eNotebook listaNotebook[],int tam);

int altaNotebook(eNotebook listaNotebook[],int tamNote,eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente list_Cliente[],int tamClientes,int* idPtr);
int bajaNotebook(eNotebook list[],int tam);
int modificarDatosNotebook(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaClientes[],int tamClientes);
int notebook_setValores(eNotebook* unaNotebook, int id, char modelo[], int idMarca, int idTipo,int idCliente, float precio);
int retornarIndicePorID(eNotebook list[],int tam, int userId);


//--------------------------------------[Imprimir por pantalla]--------------------------------------//

int mostrarUnaNotebook(eNotebook* unaNote,eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente listaCliente[],int tamClient);
int mostrarListaNotebook(eNotebook listaNote[],int tamNote, eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente listaCliente[],int tamClient);


int cargarDescripNotebook(eNotebook list[],int tam,char* cadena,int id);
int menuModifNotebook();

int ordenarNotebooks(eNotebook list[],int len);
int ordenarNotebooksPorPrecio(eNotebook list[],int len);

//--------------------------------------[Validar]--------------------------------------//

int validarIdNotebook(eNotebook list[],int tam, int id);

#endif // NOTEBOOK_H_INCLUDED
