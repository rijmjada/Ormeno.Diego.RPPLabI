#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "marcas.h"

int listarMarcas(eMarca list_M[],int len)
{
    int retorno = -1;

    system("cls");
    printf("\n  ** Lista De Marcas **\n\n");
    printf("id    Descripcion\n");
    printf("-----------------------------\n");

    if( list_M != NULL )
    {
        for(int i=0; i<len; i++)
        {
            mostrarUnaMarca(&list_M[i]);
        }
        retorno = 1;
        printf("\n\n");
    }
    return retorno;
}

void mostrarUnaMarca(eMarca* unaMarca)
{

    printf("%d     %s\n"
           ,unaMarca->id
           ,unaMarca->descripcion
          );
    printf("-----------------------------");
    printf("\n");
}

int cargarDescripMarca(eMarca list[],int tam,char* cadena,int idMarca)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].id == idMarca)
            {
                strcpy(cadena,list[i].descripcion);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}
