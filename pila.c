#include <stdio.h>
#include <stdlib.h>
#include "headers/pila.h"
#define INDEF -9999;

int main(){
    PILA P1; PILAVACIA(&P1);
    P1.altura = 0; P1.cabecera = NULL;
    PILA P3; PILAVACIA(&P3);
    P3.altura = 0; P3.cabecera = NULL;

    P1 = PUSH(P1, 2); P1 = PUSH(P1, 3);
    //P1 = PUSH(P1, 4); P1 = PUSH(P1, 7);

    P3 = PUSH(P3, 2); P3 = PUSH(P3, 7);
    P3 = PUSH(P3, 4); P3 = PUSH(P3, 3);

    //
    LISTAR(P1);    
    //LISTAR(P3);


    //printf("INCLUIDA: %d", INCLUIDA(P1, P3));
    //INCLUIDA(P1, P3);
    //PILA P2; PILAVACIA(&P2);
    //P2.altura = 0; P2.cabecera = NULL;

    //P1 = POP(P1); P1 = POP(P1); P1 = POP(P1); P1 = POP(P1);
    //printf("pv?: %d", ESPILAVACIA(P1));

    //P2 = INVERTIRLISTA(P1);
    //printf("P2?: %d", P2.cabecera->dato);
    //P1 = POP(P1);
    //printf("top? %d", TOP(P1));
    //printf("%d - %d", P1.cabecera->dato, P1.altura);
    //P1 = POPFONDO(&P1);
    //printf("%d", POPFONDO(P1));
    //printf("%d", FONDO(P1));

}