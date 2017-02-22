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
  ft_putnbr(data->median);
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

int ft_lst_issort(t_node *list)
{
  t_node *temp;

  temp = list;
  while (temp->next != NULL)
  {
    if (temp->data > temp->next->data)
      return (-1);
    temp = temp->next;
  }
  return(1);
}

int ft_quicksort_insertion(t_env *env)
{
  int middle;
  int complexity;
  int pos;
  int flag;

  middle = 0;
  complexity = 0;
  pos = -1;
  flag = 0;
  ft_lst_int(env->stack_a, &env->data_a);
  ft_printf(">> *%d*\n", env->data_a.median);
  ft_lst_is_under(env->stack_a, 1);
  while (flag == 0)
  {
    while (env->stack_a != NULL)
    {
        ft_printf(">> *%d*\n", env->data_a.median);
        if (ft_lst_is_under(env->stack_a, env->data_a.median) == -1)
        {
          ft_lst_int(env->stack_a, &env->data_a);
          ft_putchar('>');
          ft_putnbr(env->data_a.median);
          ft_putchar('<');
          ft_lst_display(env->stack_a);
          if (env->stack_b != NULL)
              ft_reverse_rotate(&env->stack_b);
          ft_putendl("rrb");
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
            ft_putendl("pb");
            ft_rotate(&env->stack_b);
            ft_putendl("rx");
            complexity += 2;
          }
          else if (pos == 0)
          {
            ft_putendl("pb");
            ft_push_ab(&env->stack_a, &env->stack_b);
            complexity++;
          }
          else if (pos < middle)
          {
            ft_putendl("ra");
            ft_rotate(&env->stack_a);
            complexity++;
          }
          else if (pos >= middle)
          {
            ft_putendl("rra");
            ft_reverse_rotate(&env->stack_a);
            complexity++;
          }
        }
        flag = 0;
    }
    ft_lst_display(env->stack_b);
    ft_lst_int(env->stack_b, &env->data_b);
    while (env->stack_b != NULL)
    {
        if (ft_lst_is_under(env->stack_b, env->data_b.median) == -1)
        {
          ft_lst_int(env->stack_b, &env->data_b);
          ft_putchar('|');
          ft_putnbr(env->data_b.median);
          ft_putchar('|');
      //    ft_reverse_rotate(&env->stack_a);
          ft_putendl("ra");
          complexity++;
        //      ft_lst_display(env->stack_b);
        }
        while ((pos = ft_lst_is_under(env->stack_b, env->data_b.median)) >= 0)
        {
          ft_putnbr(pos);
          ft_putchar('-');
          ft_putnbr(env->stack_b->data);
          middle = (int)(env->data_b.len / 2);
          if (pos == 0 && env->stack_b->data == env->data_b.median)
          {
            ft_push_ab(&env->stack_b, &env->stack_a);
            ft_rotate(&env->stack_a);
            ft_putendl("pa");
            ft_putendl("ra");
            complexity += 2;
          }
          else if (pos == 0)
          {
            ft_push_ab(&env->stack_b, &env->stack_a);
            complexity++;
            ft_putendl("pa");
          }
          else if (pos < middle)
          {
            ft_rotate(&env->stack_b);
            complexity++;
            ft_putendl("rb");
          }
          else if (pos >= middle)
          {
            ft_reverse_rotate(&env->stack_b);
            complexity++;
            ft_putendl("rrb");
          }
        }
        flag = 0;
    }
    if (env->stack_a != NULL && env->stack_b == NULL && ft_lst_issort(env->stack_a) == -1)
        flag = 1;
    else
        flag = 0;
  }
  ft_lst_display(env->stack_a);
//  ft_printf("len = %d | MIN = %d | index = %d\n",
//  env->data_a.len, env->data_a.min, env->data_a.index_min);

  ft_printf("complexity >> %d\n", complexity);
  return (0);
}
