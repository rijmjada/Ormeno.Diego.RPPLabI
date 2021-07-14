#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericas.h"

#define ERROR -1
#define ALLOK 1

typedef struct{

    int id;
    char nombre[20];
    char localidad[24];
    char sexo;
    int isEmpty;

}eCliente;


void mostrarUnCliente(eCliente list);
int listarClientes(eCliente list[],int tam);
int inicializarCliente(eCliente listaCliente[],int tam);
int validarIdCliente(eCliente list[],int tam, int id);
int cargarNombreCliente(eCliente list[],int tam,char* cadena,int idCliente);
int cargarLocalidadCliente(eCliente list[],int tam,char* cadena,int idCliente);
int buscarEspacioLibreCliente(eCliente list[],int tam);
int listarLocalidades(eCliente list[],int tam);
int agregarCliente(eCliente list[],int tam,int* idPtr);
int cliente_setValores(eCliente* unCliente, char nombre[],char localidad[],char sexo,int id);
int darBajaCliente(eCliente list[],int len);


#endif // CLIENTE_H_INCLUDED
