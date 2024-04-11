#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main() {
    t_list *list;

    list = create_list();

    printf("%d\n", is_empty(list));


    append(list, 4);
    append(list, 2);
    append(list, 1);
    append(list, 10);
    print_list(list);

    t_node *node;
    node = get_node_item(list, 4);
    print_node(node);
    node = get_node_item(list, 2);
    print_node(node);
    node = get_node_item(list, 1);
    print_node(node);
    node = get_node_item(list, 100);
    print_node(node);
    node = get_node_item(list, 10);
    print_node(node);

    remove_item(list, 4);
    print_list(list);
    remove_item(list, 1);
    print_list(list);
    remove_item(list, 10);
    print_list(list);
    remove_item(list, 2);
    print_list(list);

    free(list);

    return 1;
}