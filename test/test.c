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

void test_add_unique(void) {
  printf("\ntesting add_unique\n");
  List_ptr list = create_list();
  printf("\t should have one element while list is empty and value is inserted\n");
  assert(add_unique(list,5));
  assert(list->count == 1);
  assert(list->head->value == 5);
  printf("passed...\n");

  printf("\t should not add the same value which has been inserted\n");
  assert(add_unique(list,5) == 0);
  assert(list->count == 1);
  printf("passed...\n");
}

void test_remove_from_start(void) {
  printf("\ntesting remove_from_start\n");
  List_ptr list = create_list();
  printf("\t should not be able to remove anything while list is empty\n");
  assert(remove_from_start(list) == 0);
  printf("passed...\n");

  add_to_start(list,5);
  add_to_start(list,3);

  printf("\t should be able to remove one value from start while list is not empty\n");
  assert(remove_from_start(list));
  assert(list->count == 1);
  assert(list->head->value == 5);
  printf("passed...\n");
}

void test_remove_from_end(void) {
  printf("\ntesting remove_from_end\n");
  List_ptr list = create_list();
  printf("\t should not be able to remove anything while list is empty\n");
  assert(remove_from_end(list) == 0);
  printf("passed...\n");

  add_to_start(list,5);
  add_to_start(list,3);

  printf("\t should be able to remove one value from end while list is not empty\n");
  assert(remove_from_end(list));
  assert(list->count == 1);
  assert(list->head->value == 3);
  printf("passed...\n");
}

void test_remove_at(void) {
  printf("\ntesting remove_at\n");
  List_ptr list = create_list();
  printf("\t should not be able to remove anything while list is empty\n");
  assert(remove_at(list,0) == 0);
  printf("passed...\n");

  add_to_start(list,5);
  add_to_start(list,3);

  printf("\t should be able to remove one value from a given valid position\n");
  assert(remove_at(list,1));
  assert(list->count == 1);
  assert(list->head->value == 3);
  printf("passed...\n");

  printf("\t should not be able to remove elment for a invalid position\n");
  assert(remove_at(list,1) == 0);
  printf("passed...\n");
}

void test_remove_first_occurrence(void) {
  printf("\ntesting remove_first_occurrence\n");
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 5);
  printf("\tShould remove first match only\n");
  assert(remove_first_occurrence(list, 5));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);
  printf("passed...\n");

  printf("\tShould not able to remove if no matches exist\n");
  assert(remove_first_occurrence(list, 1) == 0);
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);
  printf("passed...\n");

  printf("\tShould remove all elements while matching with only element in list\n");
  assert(remove_first_occurrence(list, 5));
  assert(list->count == 0);
  assert(list->head == NULL);
  assert(list->last == NULL);
  printf("passed...\n");
}

void test_remove_all_occurrence(void) {
  printf("\ntesting remove_all_occurrences\n");
  List_ptr list = create_list();
  add_to_end(list, 5);
  add_to_end(list, 3);
  add_to_end(list, 3);

  printf("\tShould fail if no matches found\n");
  assert(remove_all_occurrences(list, 0) == 0);
  assert(list->count == 3);
  assert(list->head->value == 5);
  assert(list->last->value == 3);
  printf("passed...\n");

  printf("\tShould remove all mathces\n");
  assert(remove_all_occurrences(list, 3));
  assert(list->count == 1);
  assert(list->head->value == 5);
  assert(list->last->value == 5);
  printf("passed...\n");
}

int main(void)
{
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrence();
  return 0;
}