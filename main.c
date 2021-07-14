#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "trabajo.h"
#include "notebook.h"
#include "servicio.h"
#include "marcas.h"
#include "tipo.h"
#include "fecha.h"
#include "hardcodeo.h"
#include "cliente.h"
#include "informes.h"


#define TAM_NOTE 100
#define TAM_JOBS 100
#define TAM_Marcas 4
#define TAM_Tipos 4
#define TAM_Clientes 100

/*MENU DE OPCIONES:

1.	ALTA NOTEBOOK
2.	MODIFICAR NOTEBOOK: Se ingresará el id de la notebook, permitiendo en un submenú modificar:
•	precio
•	tipo
3.	BAJA NOTEBOOK: Se ingresará el id de la notebook y se realizará una baja lógica.
4.	LISTAR NOTEBOOKS: Hacer un único listado de todas las notebooks ordenadas por marca y precio.
5.	LISTAR  MARCAS
6.	LISTAR TIPOS
7.	LISTAR SERVICIOS
8.	ALTA TRABAJO: Se dará de alta cada ocurrencia de trabajo pidiéndole al usuario que elija una notebook y un Servicio
9.	LISTAR TRABAJOS

*/


int main()
{
    eNotebook listaNote[TAM_NOTE];
    eTrabajo listTrabajos[TAM_JOBS];
    eCliente listClientes[TAM_Clientes];

    inicializarListaNotebook(listaNote,TAM_NOTE);
    inicializarlistaTrabajos(listTrabajos,TAM_JOBS);
    inicializarCliente(listClientes,TAM_Clientes);


    eMarca listaMarcas[TAM_Marcas]=
    {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };

    eTipo listaTipos[TAM_Tipos]=
    {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };

    eServicio listaServicios[TAM_Servicios]=
    {
        {20000,"Bateria",250},
        {20001,"Antivirus",300},
        {20002,"Actualizacion",400},
        {20003,"Fuente",600}
    };

    int id = 1000;
    int id_jobs = 1;
    int id_Clientes = 1;
    int flagAltaNote = 1;
    char usuario = 's';

    cargarNotebooks(listaNote,TAM_NOTE,10,&id);
    cargarClientes(listClientes,TAM_Clientes,10,&id_Clientes);
    cargarTrabajos(listTrabajos,TAM_JOBS,10,&id_jobs);

    //int bufferIdModif = -1;

    do
    {
        switch(menu())
        {
        case 1:
            if(altaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes,&id) == 1)
            {
                printf("\nAlta Exitosa!\n");
                flagAltaNote = 1;
            }
            else
            {
                printf("\nERROR en el alta!\n");
            }
            break;

        case 2:
            if(flagAltaNote)
            {
                if(modificarDatosNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes)== 1)
                {
                    printf("\nModificacion Exitosa!.\n");
                }
                else
                {
                    printf("\nHubo un error en la modificacion.\n");
                }
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }

            break;

        case 3:
            if(flagAltaNote)
            {
                mostrarListaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                bajaNotebook(listaNote,TAM_NOTE);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }
            break;

        case 4:
            if(flagAltaNote)
            {
                ordenarNotebooks(listaNote,TAM_NOTE);
                mostrarListaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
            }
            else
            {
                printf("\nAntes debe dar de alta una notebook!\n");
            }
            break;

        case 5:
            listarMarcas(listaMarcas,TAM_Marcas);
            break;

        case 6:
            listarTipos(listaTipos,TAM_Tipos);
            break;

        case 7:
            listarServicios(listaServicios,TAM_Servicios);
            break;

        case 8:
            altaTrabajo(listTrabajos,TAM_JOBS,&id_jobs,listaNote,TAM_NOTE,listaServicios,TAM_Servicios,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
            break;

        case 9:
            listarTrabajos(listTrabajos,TAM_JOBS,listaNote,TAM_NOTE,listaServicios,TAM_Servicios);
            break;
//-----------------------------------------------[PARTE 2]-----------------------------------------------------//
        case 10:

            switch(menu2())
            {
            case 1:
                mostrarListaSeleccionTipo(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                break;

            case 2:
                mostrarListaSeleccionMarca(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                break;

            case 3:
                mostrarNotebooksMasBaratas(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                break;

            case 4:
                ordenarNotebooksPorMarca(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas);
                mostrarListaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                break;

            case 5:
                contarNoteMarcayTipo(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos);
                break;

            case 6:
                marcaMasElegidaClientes(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas);
                break;

            case 7:
                mostrarListaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                mostrarTrabajosUnaNotebook(listTrabajos,TAM_JOBS,listaNote,TAM_NOTE,listaServicios,TAM_Servicios);
                break;

            case 8:
                mostrarListaNotebook(listaNote,TAM_NOTE,listaMarcas,TAM_Marcas,listaTipos,TAM_Tipos,listClientes,TAM_Clientes);
                mostrarSumaImporteServicios(listTrabajos,TAM_JOBS,listaNote,TAM_NOTE,listaServicios,TAM_Servicios);
                break;

            case 9:
                listarNotebooksTipoServicio(listTrabajos,TAM_JOBS,listaNote,TAM_NOTE,listaServicios,TAM_Servicios);
                break;

            case 10:
                mostrarServiciosPorFecha(listaServicios,listTrabajos,TAM_JOBS);
                break;

            case 11:
                ordenarPorLocalidadDes(listClientes,TAM_Clientes);
                listarClientes(listClientes,TAM_Clientes);
                break;

            case 12:
                ordenarPorLocalidadAsc(listClientes,TAM_Clientes);
                listarClientes(listClientes,TAM_Clientes);
                break;

            case 13:
                listarLocalidades(listClientes,TAM_Clientes);
                break;

            case 14:
                mostrarNotebookPorCliente(listaNote,TAM_NOTE,listaTipos,TAM_Tipos,listaMarcas,TAM_Marcas,listClientes,TAM_Clientes);
                break;

            case 15:
               if(agregarCliente(listClientes,TAM_Clientes,&id_Clientes) == 1)
               {
                   printf("\nAlta Exitosa\n\n");
               }
                break;

            case 16:
                darBajaCliente(listClientes,TAM_Clientes);
                break;

            case 17:
               listarClientes(listClientes,TAM_Clientes);
                break;

            case 18:
               inputLocalidad(listClientes,TAM_Clientes);
                break;

            }
            break;

        case 11:
            exit(1);
            break;

        }

        system("pause");
    }
    while(usuario == 's');

    return 0;
}


