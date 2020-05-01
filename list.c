#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List_ptr create_list(void) {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;

  return list;
}

Node_ptr create_node(int value) {
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}


Node_ptr get_node(List_ptr list, int position) {
  Node_ptr p_walk = list->head;
  for(int i = 0; i < position; i++)
  {
    p_walk = p_walk->next;
  }
  return p_walk;
}

Status add_to_end(List_ptr list, int value) { 
  Node_ptr new_node = create_node(value);
  if (new_node == NULL) {
    return Failure;
  }
  if (list->head == NULL) {
    list->head = new_node;
  }else {
    list->last->next = new_node;
  }
  list->count += 1;
  list->last = new_node;
  return Success;
}

Status add_to_start(List_ptr list, int value) { 
  Node_ptr new_node = create_node(value);
  if (new_node == NULL) {
    return Failure;
  }
  Node_ptr temp = list->head;
  list->head = new_node;
  if (temp == NULL) {
    list->last = new_node;
  }else{
    list->head->next = temp;
  }
  list->count += 1;
  return Success;
}

Status insert_at(List_ptr list, int value, int position) {
  if(position > list->count || position < 0) {
    return Failure;
  }
  if(position == 0) {
    return add_to_start(list, value);
  }
  Node_ptr above_node = get_node(list,position - 1);
  Node_ptr new_node = create_node(value);
  Node_ptr temp = above_node->next;
  new_node->next = temp;
  above_node->next = new_node;
  list->count++;
  return Success;
}

void display(List_ptr list) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("\n");
}
