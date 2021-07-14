#define INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


#include "trabajo.h"
#include "notebook.h"
#include "servicio.h"
#include "marcas.h"
#include "tipo.h"
#include "fecha.h"
#include "hardcodeo.h"
#include "cliente.h"

int menu();
int menu2();
int mostrarListaSeleccionTipo(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaCliente[],int tamCliente);
int mostrarListaSeleccionMarca(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaCliente[],int tamCliente);
int informarNotebookMasBarata(eNotebook listaNotebook[],int tam,eMarca listaMarca[], int tamMarca, eTipo listaTipo[],int tamTipo,eCliente listaCliente[], int tamCliente);
int ordenarNotebooksPorMarca(eNotebook listaNotebook[],int tam,eMarca listaMarca[],int tamMarca);
int contarNoteMarcayTipo(eNotebook listaNotebook[],int tam,eMarca listaMarca[],int tamMarca,eTipo listTipo[],int tamTipo);

//--------------//

int marcaMasElegidaClientes(eNotebook list[],int len,eMarca listaMarca[],int tamMarca);
int mostrarTrabajosUnaNotebook(eTrabajo listJob[],int tamJob,eNotebook listaNote[],int tamNote,eServicio listaServ[],int tamServ);
int mostrarSumaImporteServicios(eTrabajo listJob[],int tamJob,eNotebook listaNote[],int tamNote,eServicio listaServ[],int tamServ);
int listarNotebooksTipoServicio(eTrabajo listJob[],int tamJob,eNotebook listNote[],int tamNote,eServicio listServ[],int tamServ);
int mostrarServiciosPorFecha(eServicio listServ[],eTrabajo listJobs[], int tamJobs);
int mostrarNotebooksMasBaratas(eNotebook list[],int tam,eMarca listMarc[],int tamM,eTipo listTipo[],int tamTip,eCliente listCliente[],int tamCliente);
int mostrarNotebookPorCliente(eNotebook listaNote[],int tamNote,eTipo listTipo[], int tamTipo,eMarca listaMarca[],int tamMarca,eCliente listaCliente[],int tamCliente);
int listarClientes(eCliente list[],int tam);
int ordenarPorLocalidadAsc(eCliente list[],int len);
int ordenarPorLocalidadDes(eCliente list[],int len);
int inputLocalidad(eCliente list[],int len);
