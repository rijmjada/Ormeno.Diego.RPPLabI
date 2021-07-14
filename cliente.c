
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "genericas.h"

int inicializarCliente(eCliente listaCliente[],int tam)
{

    int retorno = ERROR;
    if(listaCliente != NULL)
    {
        for(int i=0; i< tam; i++)
        {
            listaCliente[i].isEmpty = 1;
        }
        retorno = ALLOK;
    }
    return retorno;
}

int validarIdCliente(eCliente list[],int tam, int id)
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

int cargarNombreCliente(eCliente list[],int tam,char* cadena,int idCliente)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == idCliente)
            {
                strcpy(cadena,list[i].nombre);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}

int cargarLocalidadCliente(eCliente list[],int tam,char* cadena,int idCliente)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == idCliente)
            {
                strcpy(cadena,list[i].localidad);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}





//-----------------------------------------------------[Imprimir]-----------------------------------------------------//


int listarLocalidades(eCliente list[],int tam)
{
    int ret = ERROR;
    system("cls");
    printf("  ** Lista De Localidades Mis Clientes **\n\n");
    printf("-----------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%s\n",list[i].localidad);
            ret = ALLOK;
        }
    }
     printf("\n\n");
    if (ret == ERROR)
    {
        printf("No hay Clientes cargados!\n");
    }
    return 0;
}

void mostrarUnCliente(eCliente list)
{

    printf("%4d     %12s   %c   %12s\n"
           ,list.id
           ,list.nombre
           ,list.sexo
           ,list.localidad
          );
    printf("-----------------------------------------------\n");
}

int agregarCliente(eCliente list[],int tam,int* idPtr)
{
    int ret = ERROR;
    int index;
    char nombreAux[28];
    char localidadAux[28];
    char sexAux;
    int idAux;

    if(list != NULL && tam >0)
    {
        index = buscarEspacioLibreCliente(list,tam);

        if(index != -1)
        {
            getNombreOApellido(nombreAux,"\nIngrese nombre [max24c.]: ","\nError",1,24,3);
            getNombreOApellido(localidadAux,"\nIngrese localidad [max24c.]: ","\nError",1,24,3);
            printf("\nIngrese sexo: \n");
            fflush(stdin);
            scanf("%c",&sexAux);
            idAux = *idPtr;

            if(cliente_setValores(&list[index],nombreAux,localidadAux,sexAux,idAux)==1)
            {
            *(idPtr) = idAux++;
            }
        }
        else
        {
            printf("\nNo hay lugar para mas clientes!.\n");
        }
    }

    return ret;
}

int buscarEspacioLibreCliente(eCliente list[],int tam)
{
    int lugarLibreArray = ERROR;

    if (list != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                lugarLibreArray = i; // RETORNA POSICION LIBRE !!
                break;
            }
        }
    }
    return lugarLibreArray;
}

int cliente_setValores(eCliente* unCliente, char nombre[],char localidad[],char sexo,int id)
{
    int retorno = -1;


        unCliente->id = id;
        strcpy(unCliente->nombre,nombre);
        strcpy(unCliente->localidad,localidad);
        unCliente->sexo = sexo;
        unCliente->isEmpty = 0;

    return retorno;
}

int darBajaCliente(eCliente list[],int len)
{
    int idAux, ret = ERROR;

    if(list != NULL && len >0)
    {
        listarClientes(list,len);

        getInt(&idAux,"\nIngrese ID : ","\nError\n",1,100,3);

        if(validarIdCliente(list,len,idAux)== 1)
        {
            for(int i=0; i<len; i++)
            {
                if(list[i].id == idAux)
                {
                    list[i].isEmpty = 1;
                    printf("\nBaja Exitosa!.");
                    break;
                }
            }
            ret = ALLOK;
        }
        else
        {
            printf("\nNo ingreso un ID valido!.");
        }
    }
    return ret;
}
