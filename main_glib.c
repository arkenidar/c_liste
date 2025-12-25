#include <stdio.h>
#include <glib.h>

/*
liste doppiamente collegate usando GLib
GList è una lista doppiamente collegata di GLib
 per scorrimento inverso e operazioni di rimozione e non solo
*/

int main()
{
    GList *lista = NULL; // inizializza lista vuota

    // Aggiungi elementi alla lista
    for (int n = 1; n <= 3; n++)
    { 
        printf("aggiungi n=%d\n", n);
        lista = g_list_append(lista, GINT_TO_POINTER(n));
    }

    // Scorri dal primo all'ultimo
    printf("Scorri dal primo all'ultimo\n");
    for (GList *l = lista; l != NULL; l = l->next)
    {
        int n = GPOINTER_TO_INT(l->data);
        printf("scorrendo n=%d\n", n);
    }

    // Ordine inverso
    printf("Ordine inverso\n");
    for (GList *l = g_list_last(lista); l != NULL; l = l->prev)
    {
        int n = GPOINTER_TO_INT(l->data);
        printf("scorrendo n=%d\n", n);
    }

    // Rimuovi elemento all'indice 2 (parte da indice=0 come primo)
    GList *elemento = g_list_nth(lista, 2);
    if (elemento != NULL)
    {
        lista = g_list_delete_link(lista, elemento);
    }

    // Scorri dal primo all'ultimo dopo rimozione
    printf("Scorri dal primo all'ultimo\n");
    for (GList *l = lista; l != NULL; l = l->next)
    {
        int n = GPOINTER_TO_INT(l->data);
        printf("scorrendo n=%d\n", n);
    }

    // Libera la memoria della lista
    g_list_free(lista);

    return 0;
}
