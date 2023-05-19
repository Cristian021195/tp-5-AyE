#include <stdio.h>
#include <stdlib.h>
#define INDEF -9999;


typedef int PRIOR;
typedef char CARACTER;
typedef struct ELEMENTO{
    PRIOR prioridad;
    CARACTER caracter;
    struct ELEMENTO * siguiente;
}ELEMENTO;


typedef struct PILA{
    struct ELEMENTO * cabecera;
    int altura;
}PILA;



void PILAVACIA(PILA *P);
PILA PUSH(PILA P, PRIOR I, CARACTER c);
PILA PUSHF(PILA P, PRIOR I);
PRIOR FONDO(PILA P);
PRIOR TOP(PILA P);
PILA POP(PILA P);
PILA POPFONDO(PILA *P);
int ESSIMETRICA(PILA P);
PILA INVERTIRLISTA(PILA P); // como usuario
int INCLUIDA(PILA P, PILA P2); // como usuario
int ESPILAVACIA(PILA P);

int main(){ // + - * /  ~ () =
    PILA P; PILAVACIA(&P); PILA POSF; PILAVACIA(&POSF);
    
    P.altura = 0; P.cabecera = NULL;    
    POSF.altura = 0; POSF.cabecera = NULL;

    P = PUSH(P, 2, '/'); P = PUSH(P, 3, '~');
    //P = PUSH(P, 4); P = PUSH(P, 7);

    LISTAR(P);

    //POSF = PUSH(POSF, 2); POSF = PUSH(POSF, 7);
    //POSF = PUSH(POSF, 4); POSF = PUSH(POSF, 3);

    //
    //LISTAR(P);    
    //LISTAR(POSF);


    //printf("INCLUIDA: %d", INCLUIDA(P, POSF));
    //INCLUIDA(P, POSF);
    //PILA P2; PILAVACIA(&P2);
    //P2.altura = 0; P2.cabecera = NULL;

    //P = POP(P); P = POP(P); P = POP(P); P = POP(P);
    //printf("pv?: %d", ESPILAVACIA(P));

    //P2 = INVERTIRLISTA(P);
    //printf("P2?: %d", P2.cabecera->prioridad);
    //P = POP(P);
    //printf("top? %d", TOP(P));
    //printf("%d - %d", P.cabecera->prioridad, P.altura);
    //P = POPFONDO(&P);
    //printf("%d", POPFONDO(P));
    //printf("%d", FONDO(P));

}


int ESPILAVACIA(PILA P){
    return P.cabecera == NULL;// ? 1 : 0;
}

void LISTAR(PILA P){
    printf("\n");
    while (P.cabecera != NULL)
    {
        printf("\n[%c|%d]", P.cabecera->caracter, P.cabecera->prioridad);
        P.cabecera = P.cabecera->siguiente;
    }
    
}

int INCLUIDA(PILA P, PILA P2){
    int respuesta = 1;
    
    while (ESPILAVACIA(P2) != 1){
        if (TOP(P) == TOP(P2)){
            P = POP(P);
            P2 = POP(P2);
            respuesta = 0;
        }else{
            respuesta = 1;
            P2 = POP(P2);
        }
    }

    if(ESPILAVACIA(P) != 1){
        return 1;
    }
    

    return respuesta;
}

PILA INVERTIRLISTA(PILA P){ // recibe una lista enlazada y, con la ayuda de una pila auxiliar, retorna la lista construida en orden inverso. 
    PILA PAUX; PILAVACIA(&PAUX);

    while (ESPILAVACIA(P) != 1)
    {
        PAUX = PUSH(PAUX, TOP(P), 'n');
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

PRIOR TOP(PILA P){
    return P.cabecera->prioridad;
}

PRIOR FONDO(PILA P){

    while (P.cabecera->siguiente->siguiente != NULL){
        P.cabecera = P.cabecera->siguiente;
    }
    return P.cabecera->prioridad;

}

PILA PUSH(PILA P, PRIOR I, CARACTER c){
    ELEMENTO * nuevo = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    nuevo->prioridad = I; nuevo->caracter = c;
    nuevo->siguiente = P.cabecera;
    P.cabecera = nuevo;
    P.altura++;
    return P;
}
PILA PUSHF(PILA P, PRIOR I){
    ELEMENTO * AUX, *ANT;
    ELEMENTO * N = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    N->siguiente = NULL; N->prioridad = I;
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

// ELEMENTO * NUEVO = (ELEMENTO *) malloc(sizeof(ELEMENTO));