#include <stddef.h>

struct list_node //strutture nodo
{
    struct list_node *next; // punto il puntatore al prossimo nodo
};

struct list_node *list_get_tail(struct list_node **head) // prende l'elemento nella lista
{
    struct list_node *current_node = *head; // inizializza il nodo corrente con il primo elemento della lista
    struct list_node *last_node = NULL; // inizializza l'ultimo nodo con NULL
    while (current_node) // controlla se il nodo corrente
    {
        last_node = current_node; // assegna l'ultimo nodo con il nodo corrente
        current_node = current_node->next; // assegna il nodo corrente con il nodo successivo
    }
    return last_node; // ritornando il valore assegnato all'ultimo nodo
}

struct list_node *list_append(struct list_node **head, struct list_node *item) // aggiunge alla lista un nuovo elemento 
{
    struct list_node *tail = list_get_tail(head); // inizializza il nodo con l'elemento nella lista
    if (!tail) // se l'elemento non esiste 
    {
        *head = item; //assegna l'elemento alla lista iniziale
    }
    else
    {
        tail->next = item; // altrimento lo assengo al nodo successivo
    }
    item->next = NULL; // il nodo successivo è nullo
    return item; // ritorna il nodo
}

struct list_node *list_pop(struct list_node **head) // rimuove l'elemento iniziale dalla lista
{
    struct list_node *current_head = *head; // inizializza il nodo corrente con il primo elemento della lista
    if (!current_head) // se il nodo corrente non esiste
    {
        return NULL; //ritona nullo
    }
    *head = (*head)->next; // assegno il valore iniziale della lista con il nodo successivo
    current_head->next = NULL; // il nodo successivo è nullo
    return current_head; // ritorno il nodo corrente
}