#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "servicio.h"


int mostrarUnServicio(eServicio* list)
{
    int ret = ERROR;

    if( list != NULL )
    {
        printf("%d    $%.2f      %s\n"
               ,list->id
               ,list->precio
               ,list->descripcion);
               printf("-------------------------------\n");
        ret = ALLOK;
    }
    return ret;
}

int listarServicios(eServicio list[],int tam)
{
    int retorno = ERROR;
    system("cls");
    printf("\n   ** Lista De Servicios **\n\n");
    printf(" Id   Precio    Descripcion\n");
    printf("-------------------------------\n");
    for(int i=0; i<tam; i++)
    {
        mostrarUnServicio(&list[i]);
    }
    printf("\n\n");
    return retorno;
}

int cargarDescripServicio(eServicio list[],int tam,char* cadena,int idSer)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
          for(int i=0; i<tam; i++)
        {
            if(list[i].id == idSer)
            {
                strcpy(cadena,list[i].descripcion);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}

int get_MontoServicio(eServicio list[],int tam,int* monto,int idSer)
{
    int retorno = ERROR;

    if( list != NULL && monto != NULL )
    {
          for(int i=0; i<tam; i++)
        {
            if(list[i].id == idSer)
            {
               *monto = list[i].precio;
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}

