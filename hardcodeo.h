#ifndef HARDCODEO_H_INCLUDED
#define HARDCODEO_H_INCLUDED


#include "notebook.h"
#include "cliente.h"
#include "trabajo.h"

int cargarNotebooks(eNotebook lista[],int tam,int cant,int* id);
int cargarClientes(eCliente lista[],int tam,int cant,int* id);
int cargarTrabajos(eTrabajo list[],int tam,int cant,int* id);

#endif // HARDCODEO_H_INCLUDED
