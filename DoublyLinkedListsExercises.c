#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <stddef.h>
#define listAppend_Str(string) list_append((struct list_node **)&my_linked_list, (struct list_node *)string_item_new(string));

/*
● Implement removal
● Implement insert after an item
● Implement insert before an item
● Higher Level Exercise: implement shuffling
*/

struct list_node
{
    struct list_node *prev;
    struct list_node *next;
};

struct list_node *list_get_tail(struct list_node **head)
{
    struct list_node *current_node = *head;
    struct list_node *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }

    return last_node;
};

struct list_node *list_append(struct list_node **head, struct list_node *item)
{
    struct list_node *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

struct list_node *list_remove(struct list_node **head, const int index_to_remove) // funzione per rimuovere un elemento dalla lista
{
    struct list_node *current_node = *head; // puntatore al primo elemento della lista
    struct list_node *previous_node = NULL; // puntatore al nodo precedente

    for(int i = 0; i < index_to_remove; i++) // scorro la lista fino all'elemento da rimuovere
    {
        previous_node = current_node; // salvo il nodo precedente
        current_node = current_node->next; // scorro la lista
    }

    if (previous_node) // se il nodo precedente esiste
    {
        previous_node->next = current_node->next; // il nodo precedente punta al nodo successivo
    }
    else // se il nodo precedente non esiste
    {
        *head = current_node->next; // il primo elemento della lista punta al nodo successivo
    }

    if (current_node->next) // se il nodo successivo esiste
    {
        current_node->next->prev = previous_node; // il nodo successivo punta al nodo precedente
    }

    return current_node; // ritorno il nodo rimosso
}

void list_insert_after(struct list_node **head, struct list_node *item, const int position) // funzione per inserire un elemento dopo un altro
{
    struct list_node *temp = *head; // puntatore al primo elemento della lista
    for (int i = 0; i < position; i++) // scorro la lista fino all'elemento dopo il quale inserire
    {
        temp = temp->next; // scorro la lista
    }

    item->next = temp->next; // il nuovo nodo punta al nodo successivo
    temp->next = item; // il nodo precedente punta al nuovo nodo
    item->prev = temp; // il nuovo nodo punta al nodo precedente
};

void list_insert_before(struct list_node **head, struct list_node *item, const int position) // funzione per inserire un elemento prima di un altro
{
    struct list_node *temp = *head; // puntatore al primo elemento della lista
    for (int i = 0; i < position; i++) // scorro la lista fino all'elemento prima del quale inserire
    {
        temp = temp->next; // scorro la lista
    }

    temp->prev->next = item; // il nodo precedente punta al nuovo nodo
    temp->prev = item; // il nodo successivo punta al nuovo nodo 
    item->next = temp; // il nuovo nodo punta al nodo successivo
};

struct string_item
{
    struct list_node node;
    const char *string;
};

struct string_item *string_item_new(const char *string) // prendo una stringa in sola lettura in input
{
    struct string_item *item = malloc(sizeof(struct string_item)); // in item creo la memoria necessaria per contenere uno string_item
    if (!item)                                                     // se è NULL o 0... (non sono riuscito ad allocare memoria)
    {
        return NULL; // ... ritorno NULL
    }
    item->string = string; // assegno al contenuto di item il contenuto passato in entrata alla funzione.
    return item;           // ritorno item
}

int main()
{
    struct string_item *my_linked_list = NULL;
    listAppend_Str("Hello World");
    listAppend_Str("Test001");
    listAppend_Str("Test002");
    listAppend_Str("Last Item of the Linked List");
    struct string_item *string_item = my_linked_list;

    list_remove((struct list_node **)&my_linked_list, 1);

    //list_insert_after((struct list_node **)&my_linked_list, (struct list_node *)string_item_new("New element"), 3);
    //list_insert_before((struct list_node **)&my_linked_list, (struct list_node *)string_item_new("New element"), 1);

    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }

    return 0;
}