#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


#include "notebook.h"
#include "servicio.h"
#include "marcas.h"
#include "fecha.h"

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmtpy;

}eTrabajo;


int inicializarlistaTrabajos(eTrabajo listaT[],int tam);
int buscarEspacioLibreTrabajo(eTrabajo listaT[],int tam);

int altaTrabajo(eTrabajo listTra[], int tamTra, int* idTrabajo,eNotebook listNote[],int tamNote,
                eServicio listServ[], int tamServ,eMarca list_M[],int tam_M,eTipo list_Tipo[],int tam_tipo,
                eCliente listCliente[], int tamCliente);
int trabajo_setValores(eTrabajo* unTrabajo,int* idPtr,int dia,int mes, int anio,int idNote, int idServicio);
int mostrarUnTrabajo(eTrabajo* unTrabajo,eNotebook listNote[],int tamNote,eServicio listServ[],int tamSer);
int listarTrabajos(eTrabajo list[],int len,eNotebook listNote[],int tamNote,eServicio listServ[],int tamSer);
int valFecha(int dd,int mm, int yy);

#endif // TRABAJO_H_INCLUDED
