#ifndef GENERICAS_H_INCLUDED
#define GENERICAS_H_INCLUDED

#define EXIT_ERROR -1
#define ALLOK 1

int getInt(int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);

float getFloat(float *pResultado,
          char *pMensaje,
          char *pMensajeError,
          float minimo,
          float maximo,
          int reintentos);

char getChar(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          char minimo,
          char maximo,
          int reintentos);

int getString(char *pResultado,
          char *pMensaje,
          char *pMensajeError,
          int minimo,
          int maximo,
          int reintentos);

int getNombreOApellido(char *pResultado,
                       char *pMensaje,
                       char *pMensajeError,
                       int minimo,
                       int maximo,
                       int reintentos);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfanumerico(char str[]);
int esSoloLetras(char str[]);



#endif // GENERICAS_H_INCLUDED
