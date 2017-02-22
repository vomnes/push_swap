# include "push_swap.h"

int ft_lst_min(t_node *lst)
{
  t_node *temp;
  int index;
  int min;

  temp = lst;
  index = 0;
  min = 2147483647;
  while (temp != NULL)
  {
    min = temp->data < min ? temp->data : min;
    temp = temp->next;
    index++;
  }
  return (min);
}
