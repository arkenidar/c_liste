#include <stdio.h>
#include <stdlib.h>

/*
liste doppiamente collegate con implementazione personalizzata
per scorrimento inverso e operazioni di rimozione e non solo
*/

// Struttura del nodo della lista doppiamente collegata
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Funzione per creare un nuovo nodo
Node *crea_nodo(int data)
{
    Node *nuovo = (Node *)malloc(sizeof(Node));
    nuovo->data = data;
    nuovo->next = NULL;
    nuovo->prev = NULL;
    return nuovo;
}

// Funzione per aggiungere un nodo alla fine
Node *aggiungi_fine(Node *head, int data)
{
    Node *nuovo = crea_nodo(data);

    if (head == NULL)
    {
        return nuovo;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = nuovo;
    nuovo->prev = temp;

    return head;
}

// Funzione per trovare l'ultimo nodo
Node *trova_ultimo(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

// Funzione per rimuovere un nodo all'indice specificato
Node *rimuovi_indice(Node *head, int indice)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    int i = 0;

    while (temp != NULL && i < indice)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
        return head;

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

// Funzione per liberare tutta la lista
void libera_lista(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *lista = NULL;

    // Aggiungi elementi alla lista
    for (int n = 1; n <= 3; n++)
    {
        printf("aggiungi n=%d\n", n);
        lista = aggiungi_fine(lista, n);
    }

    // Scorri dal primo all'ultimo
    printf("Scorri dal primo all'ultimo\n");
    for (Node *l = lista; l != NULL; l = l->next)
    {
        printf("scorrendo n=%d\n", l->data);
    }

    // Ordine inverso
    printf("Ordine inverso\n");
    for (Node *l = trova_ultimo(lista); l != NULL; l = l->prev)
    {
        printf("scorrendo n=%d\n", l->data);
    }

    // Rimuovi elemento all'indice 2 (parte da indice=0 come primo)
    lista = rimuovi_indice(lista, 2);

    // Scorri dal primo all'ultimo dopo rimozione
    printf("Scorri dal primo all'ultimo\n");
    for (Node *l = lista; l != NULL; l = l->next)
    {
        printf("scorrendo n=%d\n", l->data);
    }

    // Libera la memoria della lista
    libera_lista(lista);

    return 0;
}
