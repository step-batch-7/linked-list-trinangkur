#include <stdio.h>
#include "list.h"

void print_menu(void) {
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
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
    return insert_at(list,num,position);

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