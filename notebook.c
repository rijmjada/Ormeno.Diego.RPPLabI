#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"

//---------------------------------------------------[A.B.M]---------------------------------------------------//

/** \brief Da de alta una posicion dentro del array "listaNotebook"
 * \param listaNotebook array de "notebooks"
 * \param tam tamaño del array "listaNotebook"
 * \param listaMarcas array de "Marcas"
 * \param tamM tamaño del array "listaMarcas"
 * \param listaTipos array de "Tipos"
 * \param tamTipos tamaño del array "listaTipos"
 * \param *idNotebooks direccion de la variable a incrementar
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int altaNotebook(eNotebook listaNotebook[],int tamNote,eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente list_Cliente[],int tamClientes,int* idPtr)
{
    int indexLibre, retorno = ERROR;
    char modeloAux[24];
    int idMarcaAux, idTipoAux,idClienteAux;
    float precioAux;

    if(listaNotebook != NULL && tamNote > 0)
    {
        indexLibre = buscarEspacioLibre(listaNotebook,tamNote);

        if(indexLibre != -1)
        {
            if( getString(modeloAux,"\nIngrese modelo: \n","ERROR",3,28,3) )
            {
                listarMarcas(listaMarca,tamMarca);

                if( getInt(&idMarcaAux,"\nIngrese id marca [1000/1003] : \n","\nERROR ID fuera de los rangos!.",1000,1003,10) )
                {
                    listarTipos(listaTipo,tamTipo);

                    if( getInt(&idTipoAux,"\nIngrese id tipo [5000/5003] : \n","\nERROR ID fuera de los rangos!.",5000,5003,10)
                            && getFloat(&precioAux,"\nIngrese precio [1000/50000] : \n","\nERROR fuera de los rangos!.",1000,50000,10) )
                    {
                        listarClientes(list_Cliente,tamClientes);
                        getInt(&idClienteAux,"\nIngrese Id cliente : ","\nError",1,10,3);

                        if(validarIdCliente(list_Cliente,tamClientes,idClienteAux)==1)
                        {
                            notebook_setValores(&listaNotebook[indexLibre],*idPtr,modeloAux,idMarcaAux,idTipoAux,idClienteAux,precioAux);
                            *idPtr = *idPtr+1;
                            retorno = ALLOK;
                        }
                        else
                        {
                            printf("\nNo ingreso un ID valido!.\n");
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo hay lugar en la lista!.");
        }
    }
    return retorno;
}

/** \brief Da de baja una posicion dentro del array "list"
 * \param list array de "notebooks"
 * \param tam tamaño del array "list"
 * \return 1 si cumplio la funcion, -1 caso contrario
 */
int bajaNotebook(eNotebook list[],int tam)
{
    int userId, i = ERROR, retorno = ERROR;

    if( list != NULL && tam > 0 )
    {
        getInt(&userId,"\nIngrese ID a dar de baja: ","\nNo ingreso un id valido!.\n",1000,2000,10);

        if(validarIdNotebook(list,tam,userId) == 1)
        {
            i = retornarIndicePorID(list,tam,userId);

            if( i != -1 )
            {
                list[i].isEmpty = 1;
                retorno = ALLOK;
                printf("\nBaja Exitosa!.\n\n");
            }
        }
        else
        {
            printf("\nNo se encontro notebook con ese ID!.\n\n");
        }
    }
    return retorno;
}

int modificarDatosNotebook(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaClientes[],int tamClientes)
{
    int retorno = ERROR;
    int index;   // Variable donde se guarda el retorno de la llamada a la funcion BuscarNotebookID
    int id;     // Variable donde se guarda el Id que ingresa el usuario

    if(listaNotebook != NULL && tam >0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos > 0)
    {
        system("cls");
        printf("\n  Modificar Datos Notebook\n\n");
        mostrarListaNotebook(listaNotebook,tam,listaMarcas,tamMarcas,listaTipos,tamTipos,listaClientes,tamClientes);
        getInt(&id,"\nIngrese la id que desea modificar:\n","\nDato Invalido\n",1000,1500,3);

        if(validarIdNotebook(listaNotebook,tam,id)==1)
        {
            index = retornarIndicePorID(listaNotebook,tam,id);

            switch(menuModifNotebook())
            {
            case 1:
                getFloat(&listaNotebook[index].precio,"\nIngrese NUEVO precio : \n","\nERROR",1,999999.9,5);
                break;
            case 2:
                listarTipos(listaTipos,tamTipos);
                getInt(&listaNotebook[index].idTipo,"\nIngrese id NUEVO tipo : \n","\nERROR",5000,5003,5);
                break;
            case 3:
                printf("\nOperacion cancelada por el usuario.\n\n");
                break;
            default:
                printf("No ingreso un dato valido!\n");
                break;
            }
            retorno = ALLOK;
        }
        else
        {
            printf("\nNo se encontro notebook con ese ID!.\n\n");
        }
    }
    return retorno;
}

int retornarIndicePorID(eNotebook list[],int tam, int userId)
{
    int retorno = ERROR;

    if( list != NULL && tam > 0 && userId > 0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == userId)
            {
// Si encuentro una Notebook con el ID pasado por el usuario Retorno el indice
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



//------------------------------------------------[Imprimir por Pantalla]------------------------------------------------------------//


int mostrarUnaNotebook(eNotebook* unaNote,eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente listaCliente[],int tamClient)
{
    int ret = ERROR;
    char descMarca[24];
    char descTipo[24];
    char nombreCliente[24];
    char localidad[24];

    cargarDescripMarca(listaMarca,tamMarca,descMarca,unaNote->idMarca);
    cargarDescripTipo(listaTipo,tamTipo,descTipo,unaNote->idTipo);
    cargarNombreCliente(listaCliente,tamClient,nombreCliente,unaNote->idCliente);
    cargarLocalidadCliente(listaCliente,tamClient,localidad,unaNote->idCliente);

    if(unaNote != NULL)
    {
        printf("%4d      %12s       %12s      %12s    %.2f   %12s   %12s \n"
               ,unaNote->id
               ,unaNote->modelo
               ,descMarca
               ,descTipo
               ,unaNote->precio
               ,nombreCliente
               ,localidad);

    }

    return ret;
}

int mostrarListaNotebook(eNotebook listaNote[],int tamNote,eMarca listaMarca[],int tamMarca,eTipo listaTipo[],int tamTipo,eCliente listaCliente[],int tamClient)
{
    int ret = ERROR;

    if( listaNote != NULL  )
    {
        system("cls");
        printf("\n                   ***Lista de Notebooks***\n\n");
        printf("[ID]           [Modelo]           [Marca]           [Tipo]    [Precio]       [Cliente]    [Localidad]\n");
        printf("********************************************************************************************************\n\n");

        for(int i=0; i<tamNote; i++)
        {
            if(listaNote[i].isEmpty == 0)
            {
                mostrarUnaNotebook(&listaNote[i],listaMarca,tamMarca,listaTipo,tamTipo,listaCliente,tamClient);
            }
        }
        printf("\n\n");
        ret = ALLOK;
    }

    return ret;
}

int menuModifNotebook()
{
    int option;
    system("cls");
    printf("\n ** Elija una opcion ** \n");
    printf("1-Modificar Precio\n");
    printf("2-Modificar Tipo\n");
    printf("3- Salir\n");

    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida.",1,3,5);
    return option;
}

//---------------------------------------------------[carga]---------------------------------------------------//


int notebook_setValores(eNotebook* unaNotebook, int id, char modelo[], int idMarca, int idTipo,int idCliente, float precio)
{
    int retorno = -1;

    if(unaNotebook != NULL)
    {
        unaNotebook->idCliente = idCliente;
        unaNotebook->id = id;
        strcpy(unaNotebook->modelo,modelo);
        unaNotebook->idMarca = idMarca;
        unaNotebook->idTipo = idTipo;
        unaNotebook->precio = precio;
        unaNotebook->isEmpty = 0;
    }
    return retorno;
}


int cargarDescripNotebook(eNotebook list[],int tam,char* cadena,int id)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == id)
            {
                strcpy(cadena,list[i].modelo);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}

//------------------------------------------------------------------[]------------------------------------------------------------------//

int inicializarListaNotebook(eNotebook listaNotebook[],int tam)
{
    int retorno = ERROR;

    if(listaNotebook != NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {
            listaNotebook[i].isEmpty = 1;
        }
        retorno = ALLOK;
    }
    return retorno;
}

int buscarEspacioLibre(eNotebook listaNotebook[],int tam)
{
    int lugarLibreArray = ERROR; // retorna -1 si la lista es NULL

    if (listaNotebook != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].isEmpty==1)
            {
                lugarLibreArray = i; // RETORNA POSICION LIBRE !!
                break;
            }
        }
    }
    return lugarLibreArray;
}


//------------------------------------------------------------------[Sort]------------------------------------------------------------------//

int ordenarNotebooks(eNotebook list[],int len)
{
    int retorno = ERROR;
    eNotebook noteAux;

    if( list != NULL && len > 0 )
    {
        for(int i=0; i<len -1 ; i ++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i].idMarca > list[j].idMarca   ||
                        (list[i].idMarca == list[j].idMarca  &&
                         list[i].precio > list[j].precio))
                {
                    if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                    {
                        noteAux = list[i];
                        list[i] = list[j];
                        list[j] = noteAux;
                        retorno = ALLOK;
                    }
                }
            }
        }
    }

    return retorno;
}

int validarIdNotebook(eNotebook list[],int tam, int id)
{
    int retorno = ERROR;

    if(list != NULL && tam > 0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}

int ordenarNotebooksPorPrecio(eNotebook list[],int len)
{
    int retorno = ERROR;
    eNotebook noteAux;

    if( list != NULL && len > 0 )
    {
        for(int i=0; i<len-1 ; i ++)
        {
            for(int j=i+1; j<len; j++)
            {
                if((list[i].precio  > list[j].precio) && list[i].isEmpty == 0 && list[j].isEmpty  == 0)
                {
                    noteAux = list[i];
                    list[i] = list[j];
                    list[j] = noteAux;
                    retorno = ALLOK;
                }
            }
        }
    }

    return retorno;
}


