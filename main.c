#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int contenuto; // lista di "int"
    struct Nodo* successivo; // nodo successivo
/*
liste doppiamente collegate (nodo precedente oltre quello successivo), per scorrimento inverso e operazioni di rimozione e non solo
*/
    struct Nodo* precedente;
};
typedef struct Nodo* nodo;

nodo primo=NULL; // collegato al primo nodo

nodo ultimo=NULL;

void rimuovi(nodo quale){
    if(!quale) return; // puntatore valido

    // primo
    if(quale==primo) primo=quale->successivo;

    // ultimo (può essere sia primo che ultimo simultaneamente)
    if(quale==ultimo) ultimo=quale->precedente;

    // precedente
    if(quale->precedente)
    quale->precedente->successivo=quale->successivo;

    // successivo
    if(quale->successivo)
    quale->successivo->precedente=quale->precedente;

    free(quale); // de-alloca (quel che è stato allocato con malloc)
}

nodo prendi(int indice){
    //printf("Scorri dal primo all'ultimo\n");
    struct Nodo* scorre=primo;
    int i=0;
    while(scorre != NULL){

        if(i==indice)
        return scorre;

        //printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->successivo;

        i++;
    }
    return NULL;
}

int main(){

    for(int n=1; n<=3; n++){ // aggiungi: quanti?

        printf("aggiungi n=%d\n",n);

        struct Nodo* corrente=(struct Nodo*)malloc(sizeof (struct Nodo)); // alloca
        corrente->contenuto=n;
        corrente->successivo=NULL;

        corrente->precedente=ultimo;

        if(ultimo==NULL) primo=corrente;
        else ultimo->successivo=corrente;

        ultimo=corrente;
    }

    nodo scorre;

    printf("Scorri dal primo all'ultimo\n");
    scorre=primo;
    while(scorre != NULL){
        printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->successivo;
    }

    printf("Ordine inverso\n");
    scorre=ultimo;
    while(scorre != NULL){
        printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->precedente;
    }

    rimuovi(prendi(2)); // parte da indice=0 come primo

    printf("Scorri dal primo all'ultimo\n");
    scorre=primo;
    while(scorre != NULL){
        printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->successivo;
    }

    return 0;
}
