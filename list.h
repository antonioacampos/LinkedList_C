#ifndef LIST_H
#define LIST_H

typedef struct _node {
    int item;
    struct _node *next;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;

// Cria uma nova lista encadeada
t_list* create_list();
// Libera a memória alocada para a lista
int destroy_list(t_list *list);
// Retorna o tamanho atual da lista
int size(t_list *list);
// Verifica se a lista está cheia
int is_full(t_list *list);
// Verifica se a lista está vazia
int is_empty(t_list *list);
// Adiciona um elemento ao final da lista
int append(t_list *list, int elem);
// Insere um elemento em uma posição específica da lista
int insert(t_list *list, int index, int elem);
// Remove a primeira ocorrência do elemento especificado da lista
int remove_item(t_list *list, int item);
// Retorna o nó que contém o item especificado, se encontrado na lista
t_node* get_node_item(t_list *list, int item);
// Retorna o nó na posição especificada na lista
t_node* get_item_by_index(t_list *list, int index);
// Imprime os elementos da lista
int print_list(t_list *list);
// Remove todos os elementos da lista
int clear(t_list *list);
// Remove o elemento na posição especificada da lista
int remove_at(t_list *list, int index);
// Retorna o nó no início da lista
t_node* peek_front(t_list *list);
// Retorna o nó no final da lista
t_node* peek_back(t_list *list);
// Remove e retorna o nó no início da lista
t_node* pop_front(t_list *list);
// Remove e retorna o nó no final da lista
t_node* pop_back(t_list *list);
// Inverte a ordem dos elementos na lista
int reverse(t_list *list);
// Ordena os elementos na lista
int sort(t_list *list);
// Funde duas listas ordenadas em uma única lista ordenada
int merge(t_list *list1, t_list *list2);
// Clona os elementos de uma lista para outra lista
int clone(t_list *src, t_list *dest);



#endif /* LIST_H */