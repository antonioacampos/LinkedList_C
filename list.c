#include<stdio.h>
#include<stdlib.h>
#include "list.h"

t_list* create_list() { // versao com tail
    t_list *list;
    list = (t_list*) malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}
t_node* create_node(int elem){
  t_node *node = (t_node*) malloc(sizeof(t_node));
  node->item = elem;
  node->next = NULL;
  return node;
}

int is_empty(t_list* list){
  if(list->size==0||list->head==NULL)
    return 1;
  return 0;
}

int is_full(t_list* list){
  return 0;
}
int size(t_list* list){
  return list->size;
}
int destroy_list(t_list *list) {
    t_node *current = list->head;
    t_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    // Após liberar todos os nós, ajustamos a lista para um estado vazio
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  return 1;
}
t_node* get_node_by_item(t_list *list, int item){
  t_node* aux = list->head;
  while (aux->item != item) {
      aux = aux->next; // 3
  }
  return aux;
}
t_node* get_node_by_index(t_list *list, int index){
  int indexStore = 0;
  t_node* aux = list->head;

  while (indexStore != index) {
      aux = aux->next;
      indexStore++; 
  }
  return aux;
}
int clear(t_list *list){
  if(is_empty(list))
    return 0;
  int indexStore = 0;
  t_node* aux = list->head;

  while (indexStore < list->size) {
      free(aux);
      aux = aux->next;
      indexStore++; 
  }
  return 1;
}
void print_node(t_node* node){
  printf("%d", node->item);
}
int remove_at(t_list *list, int index){
  int currentIndex = 0;
  t_node* aux = list->head;
  t_node* prev = NULL;

  if (index == 0) {
      list->head = aux->next;
      free(aux);
      return 1;
  }

  while (aux != NULL && currentIndex < index) {
      prev = aux;
      aux = aux->next;
      currentIndex++;
  }
  if (aux == NULL) {
      return 0;
  }
  prev->next = aux->next;
  free(aux);
  return 1;
}
t_node* peek_front(t_list *list){
  return list->head;
}
t_node* peek_back(t_list *list){
  return list->tail;
}
t_node* pop_front(t_list *list){
  t_node* node = list->head;
  list->head = node->next;
  return node;
}

t_node* pop_back(t_list *list){
  t_node* node = list->head;
  int index=0;
  while(index<(list->size-1)){
    node = node->next;
    index++;
  }
  t_node* next_node = node->next;
  t_node* aux = node;
  free(node);
  list->tail = next_node;
  return aux;
}
int reverse(t_list *list) {
    t_node *prev = NULL;
    t_node *current = list->head;
    t_node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
  return 1;
}


int print_list(t_list* list){
  t_node* current = list->head;
  if(is_empty(list))
    return 0;
  while(current->next!=NULL){
    printf("%d", current->item);
    current = current->next;
  }
  return 1;
}
int remove_item(t_list *list, int value) {
    t_node *current = list->head;
    t_node *previous = NULL;

    while (current != NULL) {
        if (current->item == value) {
            if (previous != NULL) {
                previous->next = current->next;
                if (current == list->tail) {
                    list->tail = previous;
                }
            } else {
                list->head = current->next;
                if (list->head == NULL) {
                    list->tail = NULL;
                }
            }
            free(current);
            list->size--;
            return 1; // Se encontramos e removemos o item, podemos sair da função
        }
        previous = current;
        current = current->next;
    }
  return 0;
}

int insert(t_list *list, int index, int elem){
    t_node *aux=list->head;
    t_node*auxPrev=list->head;
    t_node *new=create_node(elem);
    int cont=0;
    while(aux!=NULL){
        aux=aux->next;
        if(cont==index){
            auxPrev->next=new;
            new->next=aux;
            break;
        }
        auxPrev=aux;
      
        cont++;
    }
    return 1;
}	

int append(t_list *list, int elem) { // versao com tail
    t_node *node = create_node(elem);
    if (list->size == 0) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
    return 1;
}











/*int append(t_list *list, int elem) {
    t_node *node;

    node = (t_node*) malloc(sizeof(t_node));
    node->item = elem;
    node->next = NULL;
    if (list->size == 0) {
        list->head = node;
    } else {
        t_node* aux = list->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }
    list->size++;
}*/
