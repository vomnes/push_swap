# include "push_swap.h"

int ft_max_under_max(t_node *stack, int max_less)
{
  t_node *tmp;
  int tmp_nb;

  tmp = stack;
  tmp_nb = 0;
  while (tmp != NULL)
  {
    if (tmp->data < max_less && tmp->data > tmp_nb)
        tmp_nb = tmp->data;
    tmp = tmp->next;
  }
  return (tmp_nb);
}
