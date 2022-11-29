#include "AIV_pdf_Pag070_LinkedLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#define listAppend_Str(string) list_append((struct list_node **)&my_linked_list, (struct list_node *)string_item_new(string));

/*
● Implement removal of item
● Use preprocessor directives to reduce the verbose casting
● Higher Level Exercise: implement reversing of the list
*/

struct string_item // struttura della stringa 
{
    struct list_node node; // nodo della lista
    const char *string; // stringa
};

struct string_item *string_item_new(const char *string) // stringa nel nuovo elemento
{
    struct string_item *item = malloc(sizeof(struct string_item)); // alloca la memoria per il nuovo elemento sizeof(struct string_item)
    if (!item) // se il nuovo elemento non esiste 
    {
        return NULL; // ritorna nullo
    }
    item->string = string; // assegna la stringa al nuovo elemento
    return item; // ritorna il nuovo elemento
}

void deleteNode(struct list_node **head,int position) // funzione per eliminare un nodo
{
    struct  list_node *temp; // inizializza il nodo temporaneo
    temp = *head; // assegna il nodo temporaneo con il nodo iniziale
    struct list_node *prev; // inizializza il nodo precedente
    int i = 0; // inizializza i con 0
    while (i < position) // controllo finchè i è minore della posizione
    {
        prev = temp; // assegna il nodo precedente con il nodo temporaneo
        temp = temp->next; // assegna il nodo temporaneo con il nodo successivo
        i++; // incremento i
    }
    prev->next = temp->next; // assegna il nodo precedente con il nodo successivo
    free(temp); // libera la memoria del nodo temporaneo
}



struct list_node *list_reverse(struct list_node **head) //funzione per invertire la lista
{
    struct list_node *temp; // inizializza il nodo temporaneo
    temp = *head; // assegna il nodo temporaneo con il nodo iniziale
    struct list_node *prev; // inizializza il nodo precedente
    struct list_node *reversedList = NULL; // inizializza la lista invertita
    while (temp != NULL) // controllo finchè il nodo temporaneo è diverso da NULL
    {
        prev = temp; // assegna il nodo precedente con il nodo temporaneo
        temp = temp->next; // assegna il nodo temporaneo con il nodo successivo
        prev->next = reversedList; // assegna il nodo precedente con la lista invertita
        reversedList = prev; // assegna la lista invertita con il nodo precedente
    }
    *head = reversedList; // assegna il nodo iniziale con la lista invertita
    return *head; // ritorna il nodo iniziale
}

int main()
{
    struct string_item *my_linked_list = NULL;
    listAppend_Str("HelloWorld");
    listAppend_Str("Test001");
    listAppend_Str("Test002");
    listAppend_Str("Last Item of the Linked List");
    list_reverse((struct list_node **)&my_linked_list);
    //deleteNode((struct list_node **)&my_linked_list,2);
    struct string_item *string_item = my_linked_list;
    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (struct string_item *)string_item->node.next;
    }
    return 0;
}