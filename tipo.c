#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"


void mostrarUnTipo(eTipo* tipo)
{

    printf("% d     %s\n"
           ,tipo->id
           ,tipo->descripcion
          );

    printf("----------------------------\n");

}

int listarTipos(eTipo listaTipos[],int tamTipos)
{
    int retorno = ERROR;

    cabeceraTipos(); //printf
    if( listaTipos != NULL && tamTipos > 0 )
    {
        for(int i=0; i<tamTipos; i++)
        {
           // if(listaTipos[i].isEmtpy == 0)
            //{
                mostrarUnTipo(&listaTipos[i]);
                retorno = ALLOK;
           // }
        }
        printf("\n\n");
    }
    return retorno;
}

void cabeceraTipos()
{
    system("cls");
    printf(" \n   ** Lista Tipos **\n\n");
    printf("ID    Descripcion\n");
    printf("----------------------------\n");
}

int cargarDescripTipo(eTipo list[],int tam,char* cadena,int idTipo)
{
    int retorno = ERROR;

    if( list != NULL && cadena != NULL )
    {
         for(int i=0; i<tam; i++)
        {
            if(list[i].id == idTipo)
            {
                strcpy(cadena,list[i].descripcion);
                retorno = ALLOK;
                break;
            }
        }
    }
    return retorno;
}
