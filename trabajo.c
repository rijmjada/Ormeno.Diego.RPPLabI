#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"


#define ERROR -1
#define ALLOK 1

int inicializarlistaTrabajos(eTrabajo listaT[],int tam)
{
    int retorno = ERROR;
    if(listaT != NULL && tam >0)
    {
        for(int i=0; i< tam; i++)
        {
            listaT[i].isEmtpy = 1;
        }
        retorno = ALLOK;
    }
    return retorno;
}

int buscarEspacioLibreTrabajo(eTrabajo listaT[],int tam)
{
    int lugarLibreArray = ERROR;

    if (listaT != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(listaT[i].isEmtpy == 1)
            {
                lugarLibreArray = i; // RETORNA POSICION LIBRE !!
                break;
            }
        }
    }
    return lugarLibreArray;
}

int altaTrabajo(eTrabajo listTra[], int tamTra, int* idTrabajo,eNotebook listNote[],int tamNote,eServicio listServ[], int tamServ,eMarca list_M[],int tam_M,eTipo list_Tipo[],int tam_tipo,
                eCliente listCliente[], int tamCliente)
{
    int todoOk = 0;
    int indice;
    int idNoteAux;
    int idSerAux;
    int dia,mes,anio;


    system("cls");
    printf("***  Alta Trabajos  ***\n\n");
    indice = buscarEspacioLibreTrabajo(listTra,tamTra);

    if(indice != -1)
    {
        mostrarListaNotebook(listNote,tamNote,list_M,tam_M,list_Tipo,tam_tipo,listCliente,tamCliente);
        getInt(&idNoteAux,"\nIngrese ID notebook [1000/1100]: ","\nNo hay notebook con ese ID\n",1000,1100,3);
        if(validarIdNotebook(listNote,tamNote,idNoteAux)== 1)
        {
            listarServicios(listServ,tamServ);
            getInt(&idSerAux,"\nIngrese ID servicio [20000/20003]: ","\nNo hay servicio con ese ID\n",20000,20003,5);

            getInt(&dia,"\nIngrese dia [1/31]: ","\nError\n",1,31,5);
            getInt(&mes,"\nIngrese dia [1/12]: ","\nError\n",1,12,5);
            getInt(&anio,"\nIngrese anio [2020/2021]: ","\nError\n",2020,2021,5);

            if(valFecha(dia,mes,anio) == 1)
            {
                if(trabajo_setValores(&listTra[indice],idTrabajo,dia,mes,anio,idNoteAux,idSerAux))
                {
                    printf("\nAlta Exitosa!.\n");
                }
            }
        }
        else
        {
            printf("\nNo hay notebook con ese ID!. ");
        }
    }
    else
    {
        printf("No hay lugar en el sistema!!\n\n");
    }
    return todoOk;
}

int trabajo_setValores(eTrabajo* unTrabajo,int* idPtr,int dia,int mes, int anio,int idNote, int idServicio)
{
    int ret = ERROR;

    if(unTrabajo != NULL && idPtr != NULL )
    {
        unTrabajo->fecha.dia = dia;
        unTrabajo->fecha.mes = mes;
        unTrabajo->fecha.anio = anio;
        unTrabajo->id = *idPtr;
        unTrabajo->idNotebook = idNote;
        unTrabajo->idServicio = idServicio;
        unTrabajo->isEmtpy = 0;

        ret = ALLOK;
    }

    return ret;
}

int mostrarUnTrabajo(eTrabajo* unTrabajo,eNotebook listNote[],int tamNote,eServicio listServ[],int tamSer)
{
    int ret = ERROR;
    char modeloAux[24];
    char descServ[24];

    if(unTrabajo != NULL)
    {
        cargarDescripNotebook(listNote,tamNote,modeloAux,unTrabajo->idNotebook);
        cargarDescripServicio(listServ,tamSer,descServ,unTrabajo->idServicio);

        printf("%2d     %15s       %15s        %d/%d/%d"
               ,unTrabajo->id
               ,modeloAux
               ,descServ
               ,unTrabajo->fecha.dia
               ,unTrabajo->fecha.mes
               ,unTrabajo->fecha.anio
              );
        printf("\n");
    }

    return ret;
}

int listarTrabajos(eTrabajo list[],int len,eNotebook listNote[],int tamNote,eServicio listServ[],int tamSer)
{
    int ret = ERROR;

    if( list != NULL && len >0 && listNote != NULL && tamNote >0 && listServ != NULL && tamSer >0 )
    {
        system("cls");
        printf("\n                   ***Lista de Trabajos***\n\n");
        printf(" [ID]         [Modelo]      \t[Servicio]   \t[Fecha dd/mm/yyy]\n");
        printf("**************************************************************************\n\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmtpy == 0)
            {
                mostrarUnTrabajo(&list[i],listNote,tamNote,listServ,tamSer);
            }
        }
        printf("\n\n");
        ret = ALLOK;
    }
    return ret;
}

int valFecha(int dd,int mm, int yy)
{
    int retorno = ERROR;

    if(yy>=1986 && yy<=2050)
    {
//check month
        if(mm>=1 && mm<=12)
        {
//check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            {
                retorno = ALLOK;
            }

            else
            {
                if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                {
                    retorno = ALLOK;
                }

                else
                {
                    if((dd>=1 && dd<=28) && (mm==2))
                    {
                        retorno = ALLOK;
                    }

                    else
                    {
                        if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                        {
                            retorno = ALLOK;
                        }

                        else
                            printf("Dia no valido!.\n");
                    }
                }
            }
        }
        else
        {
            printf("Mes no valido!.\n");
        }
    }
    else
    {
        printf("Fecha no valida!.\n");
    }

    return retorno;
}
