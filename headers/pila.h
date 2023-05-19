#include <stdio.h>
#include <stdlib.h>
#define INDEF -9999;


typedef int ITEM;
typedef struct ELEMENTO{
    ITEM dato;
    struct ELEMENTO * siguiente;
}ELEMENTO;


typedef struct PILA{
    struct ELEMENTO * cabecera;
    int altura;
}PILA;



void PILAVACIA(PILA *P);
PILA PUSH(PILA P, ITEM I);
PILA PUSHF(PILA P, ITEM I);
ITEM FONDO(PILA P);
ITEM TOP(PILA P);
PILA POP(PILA P);
PILA POPFONDO(PILA *P);
int ESSIMETRICA(PILA P);
PILA INVERTIRLISTA(PILA P); // como usuario
int INCLUIDA(PILA P1, PILA P2); // como usuario
int ESPILAVACIA(PILA P);


int ESPILAVACIA(PILA P){
    return P.cabecera == NULL;// ? 1 : 0;
}

void LISTAR(PILA P){
    printf("\n");
    while (P.cabecera != NULL)
    {
        printf("[%d]", P.cabecera->dato);
        P.cabecera = P.cabecera->siguiente;
    }
    
}

int INCLUIDA(PILA P1, PILA P2){
    int respuesta = 1;
    
    while (ESPILAVACIA(P2) != 1){
        if (TOP(P1) == TOP(P2)){
            P1 = POP(P1);
            P2 = POP(P2);
            respuesta = 0;
        }else{
            respuesta = 1;
            P2 = POP(P2);
        }
    }

    if(ESPILAVACIA(P1) != 1){
        return 1;
    }
    

    return respuesta;
}

PILA INVERTIRLISTA(PILA P){ // recibe una lista enlazada y, con la ayuda de una pila auxiliar, retorna la lista construida en orden inverso. 
    PILA PAUX; PILAVACIA(&PAUX);

    while (ESPILAVACIA(P) != 1)
    {
        PAUX = PUSH(PAUX, TOP(P));
        P = POP(P);
    }   

    return PAUX;

}

PILA POP(PILA P){
    ELEMENTO *AUX;
    
    AUX = P.cabecera;
    P.cabecera = P.cabecera->siguiente;
    free(AUX);
    return P;
}

int ESSIMETRICA(PILA P){
    return 1;
}

PILA POPFONDO(PILA *P){
    ELEMENTO * AUX, *ANT;
    AUX = P->cabecera;
    while (AUX->siguiente != NULL){
        ANT = AUX;
        AUX = ANT->siguiente;
    }
    ANT->siguiente = NULL;
    free(AUX);
    return *P;
}

ITEM TOP(PILA P){
    return P.cabecera->dato;
}

ITEM FONDO(PILA P){

    while (P.cabecera->siguiente->siguiente != NULL){
        P.cabecera = P.cabecera->siguiente;
    }
    return P.cabecera->dato;

}

PILA PUSH(PILA P, ITEM I){
    ELEMENTO * nuevo = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    nuevo->dato = I;
    nuevo->siguiente = P.cabecera;
    P.cabecera = nuevo;
    P.altura++;
    return P;
}
PILA PUSHF(PILA P, ITEM I){
    ELEMENTO * AUX, *ANT;
    ELEMENTO * N = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    N->siguiente = NULL; N->dato = I;
    AUX = P.cabecera;
    while (AUX->siguiente != NULL){
        ANT = AUX;
        AUX = ANT->siguiente;
    }
    //ANT->siguiente = NULL;
    AUX->siguiente = N;
    return P;
}

void PILAVACIA(PILA *P){
    P = NULL;
}



