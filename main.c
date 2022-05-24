#include <stdio.h>
#include <stdlib.h>

int main(){

    struct Nodo{
        int contenuto; // lista di "int"
        struct Nodo* collegato; // nodo successivo
/*
liste doppiamente collegate (nodo precedente oltre quello successivo), per scorrimento inverso e operazioni di rimozione e non solo
*/
        struct Nodo* precedente;
    };
    struct Nodo* lista=NULL; // collegato al primo nodo

    struct Nodo* ultimo=NULL;
    for(int n=1; n<=3; n++){ // aggiungi: quanti?

        printf("aggiungi n=%d\n",n);
        
        struct Nodo* corrente=(struct Nodo*)malloc(sizeof (struct Nodo));
        corrente->contenuto=n;
        corrente->collegato=NULL;

        corrente->precedente=ultimo;
        
        if(ultimo==NULL) lista=corrente;
        else ultimo->collegato=corrente;

        ultimo=corrente;
    }

    printf("Scorri dal primo all'ultimo\n");
    struct Nodo* scorre=lista;
    while(scorre != NULL){
        printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->collegato;
    }

    printf("Ordine inverso\n");
    scorre=ultimo;
    while(scorre != NULL){
        printf("scorrendo n=%d\n",scorre->contenuto);
        scorre=scorre->precedente;
    }

    return 0;
}