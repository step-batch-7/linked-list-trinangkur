#include <stdio.h>
#include "list.h"

void print_menu(void) {
  printf("(a) add a number to the end of the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
}

Status perform_list_operation(List_ptr list, char menu) {
  int num;
  if (menu == 'a')
  {
    printf("enter a value\n");
    scanf("%d",&num);
    return add_to_end(list,num);
  }
  if (menu == 'l') {
    display(list);
    return Success;
  }
  return Failure;
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
    // printf("%u\n",status);
    if (status == Failure) {
      printf("operation failed\n");
    }
    print_menu();
    scanf("%c",&menu);
  }
  
  return 0;
}