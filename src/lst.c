# include "push_swap.h"

void	ft_lst_display(t_node *list)
{
	t_node *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_putnbr((int)temp->data);
    ft_putchar('\n');
		temp = temp->next;
	}
}

int ft_push_front(t_node **lst_head, int number)
{
    t_node *new_node;
    if (!(new_node = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    new_node->data = number;
    new_node->next = *lst_head;
    *lst_head = new_node;
    return (1);
}

int ft_push_back(t_node **lst_head, int number)
{
  t_node *new_node;
  new_node = *lst_head;
  while (new_node->next != NULL)
    new_node = new_node->next;
  if (!(new_node->next = (t_node*)malloc(sizeof(t_node))))
    return (-1);
  new_node->next->data = number;
  new_node->next->next = NULL;
  return (1);
}

int ft_delete_first(t_node **lst_head)
{
  t_node *old_head;
  int deleted_value;

  old_head = NULL;
  deleted_value = -1;
  if (*lst_head == NULL)
    return (-1);
  old_head = *lst_head;
  deleted_value = (*lst_head)->data;
  *lst_head = (*lst_head)->next;
  free(old_head);
  return (deleted_value);
}

int main(int argc, char **argv)
{
    int i;
    t_node *lst_tab;
    int len_arg;

    len_arg = argc - 1;
    i = len_arg;
    if (argc == 0)
      return (0);
    if (!(lst_tab = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    lst_tab = NULL;
    while (i)
    {
      if (!(ft_push_front(&lst_tab, ft_atoi(argv[i]))))
        return (-1);
      i--;
    }
    ft_push_back(&lst_tab, 42);
    ft_printf("Deleted value = %d\n", ft_delete_first(&lst_tab));
    ft_printf("Deleted value = %d\n", ft_delete_first(&lst_tab));
    ft_printf("Deleted value = %d\n", ft_delete_first(&lst_tab));
    ft_printf("Deleted value = %d\n", ft_delete_first(&lst_tab));
    ft_printf("Deleted value = %d\n", ft_delete_first(&lst_tab));
    ft_lst_display(lst_tab);
    return (0);
}

/*
if (!(elem = ft_lstnew(ft_strsub(s, size_words[k], size_words[k + 1]),
size_words[k + 1] + 1)))
  return (NULL);
ft_lstadd_end(&list, elem);
*/
