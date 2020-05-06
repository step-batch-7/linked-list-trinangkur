#include <stdio.h>
#include <assert.h>
#include "../list.h"

void test_add_to_end(void) {
  printf("\ntesting add_to_end\n");
  List_ptr list = create_list();
  printf("\t should have one element while list is empty and have the value inserted\n");
  assert(add_to_end(list,5));
  assert(list->count == 1);
  assert(list->head->value == 5);
  printf("passed...\n");

  printf("\t next of head element should be NULL while having one element\n");
  assert(list->head->next == NULL);
  printf("passed...\n");

  printf("\t last element of list and head should be same while having one element\n");
  assert(list->last == list->head);
  printf("passed...\n");

  printf("\t should have two element after inserting another element to the same list\n");
  assert(add_to_end(list,3));
  assert(list->count == 2);
  assert(list->head->next->value == 3);
  assert(list->last->value == 3);
  printf("passed...\n");
}

void test_add_to_start(void) {
  printf("\ntesting add_to_start\n");
  List_ptr list = create_list();
  printf("\t should have one element while list is empty and have the value inserted\n");
  assert(add_to_start(list,5));
  assert(list->count == 1);
  assert(list->head->value == 5);
  printf("passed...\n");

  printf("\t next of head element should be NULL while having one element\n");
  assert(list->head->next == NULL);
  printf("passed...\n");

  printf("\t last element of list and head should be same while having one element\n");
  assert(list->last == list->head);
  printf("passed...\n");

  printf("\t should have two element after inserting another element to the same list\n");
  assert(add_to_start(list,3));
  assert(list->count == 2);
  printf("\t head should pointing to the new value\n");
  assert(list->head->value == 3);
  assert(list->last->value == 5);
  printf("passed...\n");
}

void test_insert_at(void){
  printf("\ntesting insert_at\n");
  List_ptr list = create_list();
  printf("\t should have one element while list is empty and the value is inserted in 0th position\n");
  assert(insert_at(list,5,0));
  assert(list->count == 1);
  assert(list->head->value == 5);
  printf("passed...\n");

  printf("\t should not be able to insert value in a invalid position\n");
  assert(insert_at(list,3,11) == 0);
  printf("passed...\n");
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  return 0;
}