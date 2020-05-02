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

int search_value(List *list, int value) {
  Node *p_walk = list->head;
  for(int i = 0; i < list->count; i++)
  {
    if (p_walk->value == value)
    {
      return i;
    }
    p_walk = p_walk->next;
  }
  return -1;
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

  if (position == list->count)
  {
    return add_to_end(list,value);
  }
  
  Node_ptr above_node = get_node(list,position - 1);
  Node_ptr new_node = create_node(value);
  Node_ptr temp = above_node->next;
  new_node->next = temp;
  above_node->next = new_node;
  list->count++;
  return Success;
}

Status add_unique(List_ptr list, int value) {
  if (search_value(list, value) != -1)
  {
    return Failure;
  }
  return add_to_end(list,value);
}

Status remove_from_start(List_ptr list) {
  if(list->count == 0) {
    return Failure;
  }

  Node_ptr temp = list->head;
  list->head = temp->next;
  list->count--;

  if(list->count == 0) {
    list->last = NULL;
  }
  free(temp);
  return Success;
}

Status remove_from_end(List_ptr list) {
  if(list->count == 0) {
    return Failure;
  }

  list->count--;
  free(list->last);
  if(list->count == 0) {
    list->head = NULL;
    list->last = NULL;
  } else {
    list->last = get_node(list, list->count - 1);
    list->last->next = NULL;
  }
  return Success;
}

Status remove_at(List_ptr list, int position) {
  if(position >= list->count || position < 0) {
    return Failure;
  }
  if(position == 0) {
    return remove_from_start(list);
  }

  if (position == list->count - 1) {
    return remove_from_end(list);
  }

  Node_ptr above_node = get_node(list,position - 1);
  Node_ptr temp = above_node->next;
  above_node->next = temp->next;
  list->count--;
  free(temp);
  return Success;
}

Status remove_first_occurrence(List_ptr list, int value) {
  if (list->count == 0) {
    return Failure;
  }
  if (list->head->value == value) {
    return remove_from_start(list);
  }

  Node_ptr p_walk = list->head;
  for (int i = 1; i < list->count - 1; i++) {
    if (p_walk->next->value == value) {
      Node_ptr temp = p_walk->next;
      p_walk->next = temp->next;
      free(temp);
      list->count--;
      return Success;
    }
    p_walk = p_walk->next;
  }

  if (list->last->value == value) {
    return remove_from_end(list);
  }
  return Failure;
}


Status remove_all_occurrences(List_ptr list, int value) {
  if (list->count == 0) {
    return Failure;
  }
  Status status = Failure;
  Node_ptr p_walk = list->head;
  int i = 1;
  while(i < list->count - 1) {
    if (p_walk->next->value == value) {
      Node_ptr temp = p_walk->next;
      p_walk->next = temp->next;
      free(temp);
      list->count--;
      status = Success;
    }else {
      p_walk = p_walk->next;
      i++;
    }
  }
  if (list->head->value == value) {
    status = remove_from_start(list);
  }
  if (list->count != 0 && list->last->value == value) {
    status = remove_from_end(list);
  }
  return status;
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
