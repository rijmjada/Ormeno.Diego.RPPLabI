#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardcodeo.h"
#include "cliente.h"

int idMarcass[10] = {1000,1003,1002,1003,1001,1000,1001,1002,1002,1000};
int idTiposs[10] = {5003,5001,5002,5003,5000,5001,5002,5003,5002,5001};
float precio[10] = {1000,2000,3000,3500,1500,2000,2000,5550,1000,2500};
int idCliente[10] = {1,2,3,4,5,6,7,8,9,10};

char modelo[10][24] =
{
    {"ThinkPad"},
    {"Alienware"},
    {"Zenbook"},
    {"Ultrabook"},
    {"Saraza"},
    {"Falcon"},
    {"MegaXL"},
    {"SteveJobs"},
    {"AllinOne"},
    {"Pegasus"}
};

int cargarNotebooks(eNotebook lista[],int tam,int cant,int* id)
{
    int cantidad = 0;

    for(int i=0; i<cant; i++)
    {
        lista[i].id = *id;
        *id = *id + 1;
        lista[i].idCliente = idCliente[i];
        strcpy(lista[i].modelo,modelo[i]);
        lista[i].idMarca = idMarcass[i];
        lista[i].idTipo = idTiposs[i];
        lista[i].precio = precio[i];
        lista[i].isEmpty = 0;
        cantidad++;
    }
    return cant;
}


//--------------------------------------------------[Clientes]--------------------------------------------------//

int idPer[10] = {1,2,3,4,5,6,7,8,9,10};
char sexo[10] = {'f','m','f','m','f','m','f','m','f','m'};
char nombre[10][24] =
{
    {"Pepe"},
    {"Juan"},
    {"Jose"},
    {"Carlos"},
    {"Maria"},
    {"Julieta"},
    {"Luna"},
    {"Cristina"},
    {"Lucia"},
    {"Andres"}
};
char localidad [10][24] =
{
    {"Olivos"},
    {"Munro"},
    {"Martinez"},
    {"Boulogne"},
    {"Beccar"},
    {"Victoria"},
    {"Olivos"},
    {"El Talar"},
    {"Don Torcuato"},
    {"Boulogne"}
};

int cargarClientes(eCliente lista[],int tam,int cant,int* id)
{
    int cantidad = 0;

    for(int i=0; i<cant; i++)
    {
        lista[i].id = *id;
        *id = *id + 1;
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].localidad,localidad[i]);
        lista[i].sexo = sexo[i];
        lista[i].isEmpty = 0;
        cantidad++;
    }
    return cant;
}

//--------------------------------------------------[Trabajos]--------------------------------------------------//

int idNote[10]= {1000,1002,1003,1005,1005,1000,1002,1003,1005,1006};
int idServ[10]= {20002,20000,20001,20001,20000,20003,20002,20002,20003,20002};
eFecha auxF[10] =
{
    {15,5,2020},
    {16,6,2021},
    {17,7,2021},
    {18,5,2021},
    {19,2,2020},
    {18,2,2021},
    {16,2,2021},
    {15,3,2020},
    {15,1,2021},
    {15,2,2021}
};

int cargarTrabajos(eTrabajo list[],int tam,int cant,int* id)
{
    int cantidad = 0;

    for(int i=0; i<cant; i++)
    {
        list[i].id = *id;
        *id = *id + 1;
        list[i].idNotebook = idNote[i];
        list[i].idServicio = idServ[i];
        list[i].fecha = auxF[i];
        list[i].isEmtpy = 0;
        cantidad++;
    }
    return cant;
}
