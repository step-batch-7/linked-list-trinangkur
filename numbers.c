#include <stdio.h>
#include "list.h"

void print_menu(void) {
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
}

Status perform_list_operation(List_ptr list, char menu) {
  int num,position;
  switch (menu) {
    case 'a':
    printf("enter a value\n");
    scanf("%d",&num);
    return add_to_end(list,num);

    case 'b':
    printf("enter a value\n");
    scanf("%d",&num);
    return add_to_start(list,num);

    case 'c':
    printf("enter a value\n");
    scanf("%d",&num);
    printf("enter a position\n");
    scanf("%d",&position);
    return insert_at(list, num, position);

    case 'd':
    printf("enter a value\n");
    scanf("%d",&num);
    return add_unique(list, num);

    case 'e':
    return remove_from_start(list);

    case 'f':
    return remove_from_end(list);

    case 'g':
    printf("enter a position\n");
    scanf("%d", &position);
    return remove_at(list, position);

    case 'h':
    printf("enter a value\n");
    scanf("%d", &num);
    return remove_first_occurrence(list, num);

    case 'i':
    printf("enter a value\n");
    scanf("%d", &num);
    return remove_all_occurrences(list, num);

    case 'j':
    return clear_list(list);

    case 'k':
    printf("enter a value\n");
    scanf("%d", &num);
    if(search_value(list, num) == -1){
      printf("value is not present in the list\n");
      return Success;
    }
    printf("value present in the list\n");
    return Success;

    case 'l':
    display(list);
    return Success;

    default:
    return Failure;
  }
}

int main(void)
{
  char menu;
  Status status;
  List_ptr list = create_list();

  print_menu();
  scanf("%c",&menu);

  while (menu != 'm') {
    status = perform_list_operation(list, menu);
    if (status == Failure) {
      printf("operation failed\n");
    }
    print_menu();
    fflush(stdin);
    scanf("%c",&menu);
  }
  
  return 0;
}