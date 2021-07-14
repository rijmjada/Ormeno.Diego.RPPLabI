
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "informes.h"


int menu()
{
    int opcionMenu;

    system("cls");
    printf("\n    *** MENU OPCIONES ***\n");
    printf("---------------------------\n\n");
    printf("1- Alta Notebook\n");
    printf("2- Modificar Notebook\n");
    printf("3- Baja Notebook\n");
    printf("4- Listar Notebook\n");
    printf("5- Listar Marcas\n");
    printf("6- Listar Tipos\n");
    printf("7- Listar Servicios\n");
    printf("8- Alta Trabajo\n");
    printf("9- Listar Trabajos\n");
    printf("10- Menu Extra(Parte 2)\n");
    printf("11- SALIR\n");
    printf("\n\n");

    printf("\nDesde el main puede eliminarse el hardcodeo!.");
    getInt(&opcionMenu,"\nIngrese una opcion [1/11]: ","\nNo ingreso una opcion valida!.\n",1,11,3);

    return opcionMenu;

}

int menu2()
{
    int opcionMenu;

    system("cls");
    printf("\n    *** MENU OPCIONES ***\n");
    printf("---------------------------\n\n");
    printf("1- Mostrar las notebooks del tipo seleccionado por el usuario.\n");
    printf("2- Mostrar notebooks de una marca seleccionada.\n");
    printf("3- Informar la o las notebooks mas baratas\n");
    printf("4- Mostrar un listado de las notebooks separadas por marca\n");
    printf("5- Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.\n");
    printf("6- Mostrar la o las marcas mas elegidas por los clientes.\n");
    printf("7- Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.\n");
    printf("8- Pedir un notebook e informar la suma de los importes de los services se le hicieron a la misma\n");
    printf("9- Pedir un servicio y mostrar las notebooks a las que se realizo ese servicio y la fecha.\n");
    printf("10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("\n\nAgregados Recuperatorio\n\n");
    printf("11- Ordenar x Localidad Descendente\n");
    printf("12- Ordenar x Localidad AScendente\n");
    printf("13- Listar Localidades Mis Clientes\n");
    printf("14- Mostrar Notebook por ID cliente\n");
    printf("15- Agregar Cliente\n");
    printf("16- Dar Baja Cliente\n");
    printf("17- Listar Clientes\n");
    printf("18- Ingresar Localidad y buscar Si hay un cliente de la misma\n");

    printf("\n\n");

    getInt(&opcionMenu,"\nIngrese una opcion [1/18]: ","\nNo ingreso una opcion valida!.\n",1,18,3);
    printf("\n\n");

    return opcionMenu;
}

int mostrarListaSeleccionTipo(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaCliente[],int tamCliente)
{
    int retorno = ERROR;
    int bufferTipo;
    listarTipos(listaTipos,tamTipos);
    getInt(&bufferTipo,"\nIngrese id tipo <5000/5003> :\n","\nId Invalido\n",5000,5003,3);


    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos >0)
    {
        system("cls");
        printf("\n                   ***Lista de Notebooks***\n\n");
        printf("[ID]           [Modelo]           [Marca]           [Tipo]    [Precio]       [Cliente]  [Localidad] \n");
        printf("********************************************************************************************************\n\n");
        retorno = ALLOK;

        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].idTipo == bufferTipo && listaNotebook[i].isEmpty == 0)
            {
                mostrarUnaNotebook(&listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos,listaCliente,tamCliente);
            }
        }

        printf("\n\n");
    }

    return retorno;
}

int mostrarListaSeleccionMarca(eNotebook listaNotebook[],int tam,eMarca listaMarcas[],int tamMarcas,eTipo listaTipos[],int tamTipos,eCliente listaCliente[],int tamCliente)
{
    int retorno = ERROR;
    int bufferTipo;
    listarMarcas(listaMarcas,tamMarcas);
    getInt(&bufferTipo,"\nIngrese id marca <1000/1003> :\n","\nId Invalido\n",1000,1003,3);


    if(listaNotebook != NULL && tam > 0 && listaMarcas != NULL && tamMarcas > 0 && listaTipos != NULL && tamTipos >0)
    {

        system("cls");
        printf("\n                   ***Lista de Notebooks***\n\n");
        printf("[ID]           [Modelo]           [Marca]           [Tipo]    [Precio]       [Cliente]  [Localidad] \n");
        printf("********************************************************************************************************\n\n");
        retorno = ALLOK;

        for(int i=0; i<tam; i++)
        {
            if(listaNotebook[i].idMarca == bufferTipo && listaNotebook[i].isEmpty == 0)
            {
                mostrarUnaNotebook(&listaNotebook[i],listaMarcas,tamMarcas,listaTipos,tamTipos,listaCliente,tamCliente);
            }
        }

        printf("\n\n");
    }

    return retorno;
}

int informarNotebookMasBarata(eNotebook listaNotebook[],int tam,eMarca listaMarca[], int tamMarca, eTipo listaTipo[],int tamTipo,eCliente listaCliente[], int tamCliente)
{
    int retorno = ERROR;
    //int bufferId;
    float bufferPrecio;
    eNotebook aux;

    if(listaNotebook != NULL && tam >0 && listaTipo != NULL && tamTipo >0 && listaCliente != NULL && tamCliente >0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(listaNotebook[i].precio < listaNotebook[j].precio)
                {
                    aux = listaNotebook[i];
                    listaNotebook[i] = listaNotebook[j];
                    listaNotebook[j] = aux;
                }
            }
        }

        for(int i=0; i<tam; i++)
        {
            bufferPrecio = listaNotebook[0].precio;
            if(listaNotebook[i].precio == bufferPrecio)
            {
                mostrarUnaNotebook(&listaNotebook[i],listaMarca,tamMarca,listaTipo,tamTipo,listaCliente,tamCliente);
            }
        }
        /*
                system("cls");
                printf("\n                   ***Lista de Notebooks***\n\n");
                printf("[ID]           [Modelo]           [Marca]           [Tipo]    [Precio]       [Cliente] \n");
                printf("****************************************************************************************\n\n");

                mostrarUnaNotebook(&listaNotebook[bufferId],listaMarca,tamMarca,listaTipo,tamTipo,listaCliente,tamCliente);*/
    }
    return retorno;
}

int ordenarNotebooksPorMarca(eNotebook listaNotebook[],int tam,eMarca listaMarca[],int tamMarca)
{
    int retorno = ERROR;
    eNotebook noteAux;

    if(listaNotebook != NULL && tam > 0 && listaMarca != NULL && tamMarca >0 )
    {
        for(int i=0; i<tam -1 ; i ++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(listaNotebook[i].idMarca >= listaNotebook[j].idMarca)
                {
                    noteAux = listaNotebook[i];
                    listaNotebook[i]=listaNotebook[j];
                    listaNotebook[j]= noteAux;
                    retorno = ALLOK;
                }
            }
        }
    }

    return retorno;
}

int contarNoteMarcayTipo(eNotebook listaNotebook[],int tam,eMarca listaMarca[],int tamMarca,eTipo listTipo[],int tamTipo)
{
    int retorno = ERROR;
    int contador = 0;
    int bufferIdMarca;
    int bufferIdTipo;

    if(listaNotebook != NULL && tam > 0 && listaMarca != NULL && tamMarca >0 && listTipo != NULL && tamTipo >0 )
    {
        listarMarcas(listaMarca,tamMarca);
        getInt(&bufferIdMarca,"\nIngrese id Marca <1000/1003>: \n","\nID ingresado no es valido!.\n",1000,1003,5);
        listarTipos(listTipo,tamTipo);
        getInt(&bufferIdTipo,"\nIngrese id Tipo <1000/1003>: \n","\nID ingresado no es valido!.\n",5000,5003,5);

        for(int i=0; i<tam ; i ++)
        {
            if(listaNotebook[i].idMarca == bufferIdMarca && listaNotebook[i].idTipo == bufferIdTipo)
            {
                contador++;
                retorno = ALLOK;
            }
        }
        system("cls");
        printf("\n\nLa cantidad registrada con esos parametros son : [%d]\n\n",contador);
    }
    return retorno;
}

int marcaMasElegidaClientes(eNotebook list[],int len,eMarca listaMarca[],int tamMarca)
{
    int ret = ERROR;
    int compaq=0,asus=0,acer=0,hp=0;
    int marca=0;
    char nombre[24];
    if( list != NULL && listaMarca != NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].idMarca==1000 && list[i].isEmpty==0)
            {
                compaq++;
            }
            else if(list[i].idMarca==1001 && list[i].isEmpty==0)
            {
                asus++;
            }
            else if(list[i].idMarca==1002 && list[i].isEmpty==0)
            {
                acer++;
            }
            else if(list[i].idMarca==1003 && list[i].isEmpty==0)
            {
                hp++;
            }

        }
        if(marca<acer)
        {
            strcpy(nombre,"Acer-");
            marca=acer;
        }
        if(marca<asus)
        {
            strcpy(nombre,"Asus-");
            marca=asus;
        }
        else if(marca==asus)
        {
            strcat(nombre," Asus-");
        }
        if(marca<compaq)
        {
            strcpy(nombre,"Compaq-");
            marca=compaq;
        }
        else if(marca==compaq)
        {
            strcat(nombre," Compaq-");
        }
        if(marca<hp)
        {
            strcpy(nombre,"Hp-");
            marca=hp;
        }
        else if(marca==hp)
        {
            strcat(nombre," Hp-");
        }

        system("cls");
        printf("\nLa/s marca mas elegida por los clientes es/son :\n\n %s\n\n",nombre);
    }

    return ret;
}

int mostrarTrabajosUnaNotebook(eTrabajo listJob[],int tamJob,eNotebook listaNote[],int tamNote,eServicio listaServ[],int tamServ)
{
    int bufferIdNote,ret = ERROR;

    if( listJob != NULL && listaNote != NULL && listaServ != NULL)
    {
        getInt(&bufferIdNote,"\nIngrese ID de una notebook : ","\nError\n",1000,1015,3);
        if(validarIdNotebook(listaNote,tamNote,bufferIdNote))
        {
            system("cls");
            printf("\n***** Servicios echos*****\n\n ");
            printf(" [ID_Job]     \t[Modelo]       \t    [Servicio]     \t[Fecha] ");
            printf("\n*****************************************************************\n");
            for(int i=0; i<tamJob; i++)
            {
                if(listJob[i].idNotebook == bufferIdNote)
                {
                    mostrarUnTrabajo(&listJob[i],listaNote,tamNote,listaServ,tamServ);
                    printf("\n\n");
                }
            }
        }
        else
        {
            printf("\nNo ingreso un ID valido!.\n");
        }
    }

    return ret;
}

int mostrarSumaImporteServicios(eTrabajo listJob[],int tamJob,eNotebook listaNote[],int tamNote,eServicio listaServ[],int tamServ)
{
    int bufferIdNote,monto,acumulador = 0,ret = ERROR;

    if( listJob != NULL && listaNote != NULL && listaServ != NULL)
    {
        getInt(&bufferIdNote,"\nIngrese ID de una notebook : ","\nError\n",1000,1015,3);
        if(validarIdNotebook(listaNote,tamNote,bufferIdNote))
        {
            system("cls");
            for(int i=0; i<tamJob; i++)
            {
                if(listJob[i].idNotebook == bufferIdNote)
                {
                    get_MontoServicio(listaServ,tamServ,&monto,listJob[i].idServicio);
                    acumulador = acumulador + monto;
                }
            }
            printf("\nLa suma de los importes es: $%d\n\n",acumulador);
        }
        else
        {
            printf("\nNo ingreso un ID valido!.\n");
        }
    }

    return ret;
}

int listarNotebooksTipoServicio(eTrabajo listJob[],int tamJob,eNotebook listNote[],int tamNote,eServicio listServ[],int tamServ)
{
    int ret = ERROR;
    int idAuxServ;
    int idNoteaux;
    char NoteAux[24];

    if(listNote != NULL && listServ != NULL && listServ != NULL)
    {
        listarServicios(listServ,tamServ);
        getInt(&idAuxServ,"\nIngrese un Id de servicio: [20000/20003]\n","\nID invalido!.\n",20000,20003,5);
        //validar con funcion tambien
        for(int i=0; i<tamJob; i++)
        {
            if(listJob[i].idServicio == idAuxServ)
            {
                idNoteaux = listJob[i].idNotebook;
                cargarDescripNotebook(listNote,tamNote,NoteAux,idNoteaux);

                printf("\nNotebook : %s",NoteAux);
                printf("\nFecha servicio: %d/%d/%d",listJob[i].fecha.dia,listJob[i].fecha.mes,listJob[i].fecha.anio);
                printf("\n\n");
            }
        }
    }
    return ret;
}

int mostrarServiciosPorFecha(eServicio listServ[],eTrabajo listJobs[], int tamJobs)
{
    int ret = ERROR;
    eFecha fecha;

    if(listServ != NULL && listJobs != NULL)
    {
        getInt(&fecha.dia,"\nIngrese dia [1/31]:","\nDato invalido.\n",1,31,5);
        getInt(&fecha.mes,"\nIngrese mes [1/12]:","\nDato invalido.\n",1,12,5);
        getInt(&fecha.anio,"\nIngrese anio [2020/2021]:","\nDato invalido.\n",2000,2021,5);

        for(int i=0; i<tamJobs; i++)
        {
            if(fecha.dia == listJobs[i].fecha.dia && fecha.mes == listJobs[i].fecha.mes && fecha.anio == listJobs[i].fecha.anio)
            {
                printf("%d  %13s  $%.2f\n",listServ[i].id,listServ[i].descripcion,listServ[i].precio);
            }
        }
        ret = ALLOK;
    }
    return ret;
}

int mostrarNotebooksMasBaratas(eNotebook listaNote[],int tam,eMarca listMarc[],int tamM,eTipo listTipo[],int tamTip,eCliente listCliente[],int tamCliente)
{
    int ret = ERROR;
    float precioBajo;

    if(listaNote != NULL && listMarc != NULL && listTipo != NULL && listCliente != NULL)
    {
        ordenarNotebooksPorPrecio(listaNote,tam);
        precioBajo = listaNote[0].precio;

        for(int i=0; i<tam; i++)
        {
            if(listaNote[i].precio == precioBajo)
            {
                if(listaNote[i].isEmpty == 0)
                {
                    mostrarUnaNotebook(&listaNote[i],listMarc,tamM,listTipo,tamTip,listCliente,tamCliente);
                }
            }
        }
        ret = ALLOK;
    }

    return ret;
}

int mostrarNotebookPorCliente(eNotebook listaNote[],int tamNote,eTipo listTipo[], int tamTipo,eMarca listaMarca[],int tamMarca,eCliente listaCliente[],int tamCliente)
{
    int ret = ERROR;
    int idaux;

    if(listaNote != NULL)
    {
        listarClientes(listaCliente,tamCliente);
        getInt(&idaux,"\nIngrese ID cliente:  ","ERROR",1,10,3);

        if(validarIdCliente(listaCliente,tamCliente,idaux)== 1)
        {
            system("cls");
            printf("\n                   ***Lista de Notebooks***\n\n");
            printf("[ID]           [Modelo]           [Marca]           [Tipo]    [Precio]       [Cliente]    [Localidad]\n");
            printf("********************************************************************************************************\n\n");

            ret = ALLOK;
            for(int i=0; i<tamNote; i++)
            {
                if(listaNote[i].idCliente == idaux && listaNote[i].isEmpty == 0)
                {
                    mostrarUnaNotebook(&listaNote[i],listaMarca,tamMarca,listTipo,tamTipo,listaCliente,tamCliente);
                }
            }
        }
    }

    return ret;
}


int listarClientes(eCliente list[],int tam)
{
    int ret = ERROR;
    system("cls");
    printf("  ** Lista De Clientes **\n\n");
    printf("  ID            Nombre  Sexo   Localidad\n");
    printf("-----------------------------------------------\n");

    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 0)
        {
            mostrarUnCliente(list[i]);
            ret = ALLOK;
        }
    }
    if (ret == ERROR)
    {
        printf("No hay Clientes cargados!\n");
    }
    return 0;
}

int ordenarPorLocalidadAsc(eCliente list[],int len)
{
    int ret = ERROR;
    eCliente aux;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].localidad,list[j].localidad)>0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
        ret = ALLOK;
    }
    return ret;
}

int ordenarPorLocalidadDes(eCliente list[],int len)
{
    int ret = ERROR;
    eCliente aux;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].localidad,list[j].localidad)<0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
        ret = ALLOK;
    }
    return ret;
}

int inputLocalidad(eCliente list[],int len)
{
    int ret = ERROR;
    int flag = 0;
    char aux[24];

    if(list != NULL && len >0)
    {
        system("cls");
        getNombreOApellido(aux,"\nIngrese Localidad: ","\nError",1,24,3);
        for(int i=0; i<len; i++)
        {
            if(strcmp(list[i].localidad,aux)==0)
            {
                printf("\nContamos con clientes que viven en la localidad de %s!!\n\n",aux);
                break;
            }
            else
            {
                flag=1;
            }
        }
        if(flag ==1)
        {
            printf("\nNO econtramos clientes que vivan en la localidad de %s!!\n\n",aux);
        }
        ret = ALLOK;
    }
    return ret;
}

