#include<stdio.h>
#include<stdlib.h>

typedef int ITEM;

typedef struct NODO {
    ITEM dato;
    struct NODO * siguiente;
}NODO;

typedef NODO * LISTA;

LISTA AGREGAR(LISTA L, ITEM x);
int ESSIMETRICA(LISTA L);
void LISTAR(LISTA L);
LISTA LISTAVACIA();

int main(){
    LISTA L1 = LISTAVACIA();

    L1 = AGREGAR(L1, 1);
    L1 = AGREGAR(L1, 2);
    L1 = AGREGAR(L1, 3);

    L1 = AGREGAR(L1, 3);
    L1 = AGREGAR(L1, 2);
    L1 = AGREGAR(L1, 1);

    //printf("%d", L1->dato);

    //LISTAR(L1);


    ESSIMETRICA(L1);

    //printf("\n\nES SIMETRICA? %d", ESSIMETRICA(L1));
    


    return 0;
}

int ESSIMETRICA(LISTA L){
    int CANT = 6;

    return 1;
}

LISTA AGREGAR(LISTA L, ITEM x){
    NODO *N = (NODO *) malloc(sizeof(NODO));
    N->dato = x;
    N->siguiente = L;
    L = N;
    return L;
}

LISTA LISTAVACIA(){
    LISTA L = NULL;
    return L;
}

void LISTAR(LISTA L){
    while (L != NULL)
    {
        printf("\n[%d]", L->dato);
        L = L->siguiente;
    }    
}