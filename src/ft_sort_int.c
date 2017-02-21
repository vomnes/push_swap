# include "push_swap.h"

int	ft_lst_len(t_node *list)
{
	t_node *temp;
  int count;

	temp = list;
  count = 0;
	while (temp != NULL)
	{
    count++;
		temp = temp->next;
	}
  return(count);
}

void		ft_sort_int(int *tab, int len)
{
	int		i;
	int		is_sort;

	is_sort = 0;
	while (is_sort == 0)
	{
		is_sort = 1;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
      {
        ft_swap(&tab[i], &tab[i + 1]);
        is_sort = 0;
      }
			i++;
		}
	}
}

int	ft_lst_int(t_node *list, t_data *data)
{
	t_node *temp;
  int *tab;
  int len;
  int i;

  len = ft_lst_len(list);
  if (!(tab = (int*)malloc(sizeof(tab) * len)))
      return (-1);
	temp = list;
  i = 0;
	while (temp != NULL)
	{
		tab[i] = (int)temp->data;
		temp = temp->next;
    i++;
	}
  ft_sort_int(tab, len);
  i = 0;
//  while (i < len)
//    ft_printf(">> %d\n", tab[i++]);
  data->median = tab[len / 2];
  return (0);
}

int ft_lst_is_under(t_node *list, int limit)
{
  t_node *temp;
  int index;

  temp = list;
  index = 0;
  while (temp != NULL)
  {
    if (temp->data <= limit)
      return (index);
    index++;
    temp = temp->next;
  }
  return(-1);
}

int ft_quicksort_insertion(t_env *env)
{
  int middle;
  int complexity;
  int pos;

  middle = 0;
  complexity = 0;
  pos = -1;
  ft_lst_int(env->stack_a, &env->data_a);
  ft_lst_is_under(env->stack_a, 1);
  ft_printf("|%d|", env->data_a.median);
  while (env->stack_a != NULL)
  {
      if (ft_lst_is_under(env->stack_a, env->data_a.median) == -1)
      {
        ft_lst_int(env->stack_a, &env->data_a);
        ft_putchar('|');
        ft_putnbr(env->data_a.median);
        ft_putchar('|');
        ft_reverse_rotate(&env->stack_b);
        ft_putendl("rb");
        complexity++;
  //      ft_lst_display(env->stack_b);
      }
      while ((pos = ft_lst_is_under(env->stack_a, env->data_a.median)) >= 0)
      {
        ft_putnbr(pos);
        ft_putchar('-');
        ft_putnbr(env->stack_a->data);
        middle = (int)(env->data_a.len / 2);
        if (pos == 0 && env->stack_a->data == env->data_a.median)
        {
          ft_push_ab(&env->stack_a, &env->stack_b);
          ft_rotate(&env->stack_b);
          ft_putendl("pb");
          ft_putendl("rb");
          complexity += 2;
        }
        else if (pos == 0)
        {
          ft_push_ab(&env->stack_a, &env->stack_b);
          complexity++;
          ft_putendl("pb");
        }
        else if (pos < middle)
        {
          ft_rotate(&env->stack_a);
          complexity++;
          ft_putendl("ra");
        }
        else if (pos >= middle)
        {
          ft_reverse_rotate(&env->stack_a);
          complexity++;
          ft_putendl("rra");
        }
      }
  }
  ft_lst_display(env->stack_b);
  while (env->stack_b != NULL)
  {
        env->data_b.len = ft_lst_min(env->stack_b, &env->data_b);
        middle = (int)(env->data_b.len / 2);
        ft_printf("middle = %d | len = %d | MAX = %d | index = %d\n",
        middle, env->data_b.len, env->data_b.max, env->data_b.index_max);
        if (env->data_b.index_max == 0)
        {
          ft_push_ab(&env->stack_b, &env->stack_a);
          complexity++;
          ft_putendl("pa");
        }
        else if (env->data_b.index_max == 1)
        {
          ft_swap_one_two(&env->stack_b);
          complexity++;
          ft_putendl("sa");
        }
        else if (env->data_a.index_max < middle)
        {
          ft_rotate(&env->stack_b);
          complexity++;
          ft_putendl("ra");
        }
        else if (env->data_a.index_max >= middle)
        {
          ft_reverse_rotate(&env->stack_b);
          complexity++;
          ft_putendl("rra");
        }
        ft_putendl("<<>>");
        ft_lst_display(env->stack_b);
        break ;
  }
  ft_lst_display(env->stack_a);
//  ft_printf("len = %d | MIN = %d | index = %d\n",
//  env->data_a.len, env->data_a.min, env->data_a.index_min);

  ft_printf("complexity >> %d\n", complexity);
  return (0);
}
