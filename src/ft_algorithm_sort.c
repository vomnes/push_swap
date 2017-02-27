/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:32:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/27 11:32:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int ft_push_max(t_node **stack_a, t_node **stack_b, int pos, int middle)
{
  if (pos == 0)
  {
    ft_push_ab(&(*stack_b), &(*stack_a));
    ft_putendl("pa");
  }
  else if (pos < middle)
  {
    ft_rotate(&(*stack_b));
    ft_putendl("rb");
  }
  else if (pos >= middle)
  {
    ft_reverse_rotate(&(*stack_b));
    ft_putendl("rrb");
  }
  return (0);
}

int ft_max_under_max_index(t_node *stack, int max_less)
{
  t_node *tmp;
  int index;
  int index_val;
  int tmp_nb;

  tmp = stack;
  index = 0;
  index_val = 0;
  tmp_nb = -2147483648;
  while (tmp != NULL)
  {
    if (tmp->data < max_less && tmp->data > tmp_nb)
    {
      index_val = index;
      tmp_nb = tmp->data;
    }
    tmp = tmp->next;
    index++;
  }
  return (index_val);
}

int ft_get_pos_value(t_node *stack, int nb)
{
  t_node *tmp;
  int index;

  tmp = stack;
  index = 0;
  if (tmp->data == nb)
      return (0);
  while (tmp != NULL && tmp->data != nb)
  {
    tmp = tmp->next;
    index++;
  }
  if (index > ft_lst_len(stack) / 2)
      index = ft_lst_len(stack) - index;
  return (index);
}

int ft_get_index_value(t_node *stack, int nb)
{
  t_node *tmp;
  int index;

  tmp = stack;
  index = 0;
  if (tmp->data == nb)
      return (0);
  while (tmp != NULL && tmp->data != nb)
  {
    tmp = tmp->next;
    index++;
  }
  if (index > ft_lst_len(stack) / 2)
      index = ft_lst_len(stack) - index;
  return (index);
}

void ft_push_selected_value(t_node **stack_a, t_node **stack_b, int nb)
{
    int pos;
    int middle;

    pos = ft_get_index_value(*stack_b, nb);
    middle = (int)(ft_lst_len(*stack_b) / 2);
    while (ft_lst_min(*stack_b) == nb)
      ft_push_max(&(*stack_a), &(*stack_b), pos, middle);
}
/*
int			take_pos_opti(t_swap **pa, int number)
{
	int		count1;
	int		count2;
	t_swap	*pile;

	count1 = 1;
	count2 = 1;
	if (number == (*pa)->nb)
		return (count1);
	pile = (*pa)->next;
	while (!pile->first && pile->nb != number)
	{
		count1 += 1;
		pile = pile->next;
	}
	pile = (*pa)->previous;
	while (!pile->first && pile->nb != number)
	{
		count2 += 1;
		pile = pile->previous;
	}
	return ((count1 > count2) ? count2 : count1);
}
*/
int ft_algorithm_sort(t_env *env)
{
  int middle;
  int pos;
  int flag;
  int turn;
  int is_sorted;
  int level;
  int len;
  int original_len;

  int max_2;
  int max_3;

  middle = 0;
  pos = -1;
  flag = 0;
  turn = 0;
  len = ft_lst_len(env->stack_a);
  original_len = ft_lst_len(env->stack_a);
  level = ((1.0 / 75.0) * len + 5.0 / 2.9) + 0.5;
  level = (level < 2) ? 2 : level;
  ft_lst_median(env->stack_a, &env->data_a, level);
  is_sorted = 0;
  while (is_sorted == 0)
  {
    while (turn == 0)
    {
        if (ft_lst_len(env->stack_a) == 3 &&
        ft_lst_min(env->stack_a) > ft_lst_max(env->stack_b))
        {
          ft_big_bubble_sort(&env->stack_a, &env->stack_b, env);
          turn = 1;
          break ;
        }
        if (ft_lst_len(env->stack_a) == 2)
        {
          ft_big_bubble_sort(&env->stack_a, &env->stack_b, env);
          turn = 1;
          break ;
        }
        if (ft_lst_is_sorted(env->stack_a) == 1 &&
        (env->stack_a->data > ft_lst_max(env->stack_b)))
        {
          turn = 1;
          break ;
        }
        if ((pos = ft_lst_is_under(env->stack_a, env->data_a.median)) < 0)
        {
          len = ft_lst_len(env->stack_a);
          if (original_len >= 1000)
              level = ((1.0 / 75.0) * len + 5.0 / 2.9) + 0.5;
          else
              level = ((1.0 / 60.0) * len + 5.0 / 2.3) + 0.5;
          level = (level < 2) ? 2 : level;
          ft_lst_median(env->stack_a, &env->data_a, level);
        }
        pos = ft_lst_is_under(env->stack_a, env->data_a.median);
        middle = (int)(env->data_a.len / 2);
        ft_push_min(&env->stack_a, &env->stack_b, pos, middle);
    //    ft_print_stacks(env->stack_a, env->stack_b); usleep(250000);
    }
    while (turn == 1)
    {
        if (env->stack_b == NULL)
        {
          turn = 0;
          break ;
        }
      /*  ft_lst_values(env->stack_b, &env->data_b);
        max_2 = ft_max_under_max_index(env->stack_b, env->data_b.max);
        max_2 = ft_max_under_max_index(env->stack_b, max_2);
        if ((env->data_b.max > max_2) && ft_get_pos_value(env->stack_b, max_2) <
        ft_get_pos_value(env->stack_b, env->data_b.max) &&
        ft_get_pos_value(env->stack_b, max_2) < ft_get_pos_value(env->stack_b, max_2))
        {
          ft_push_selected_value(&env->stack_a, &env->stack_a, max_2);
          ft_push_selected_value(&env->stack_a, &env->stack_a, env->data_b.max);
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        }
        else if ((max_3 < env->data_b.max) && ft_get_pos_value(env->stack_b, max_3) < ft_get_pos_value(env->stack_b, env->data_b.max)
        && ft_get_pos_value(env->stack_b, max_2) > ft_get_pos_value(env->stack_b, max_3))
        {
          ft_push_selected_value(&env->stack_a, &env->stack_a, max_3);
          ft_push_selected_value(&env->stack_a, &env->stack_a, env->data_b.index_max);
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
          ft_lst_values(env->stack_b, &env->data_b);
          ft_push_selected_value(&env->stack_a, &env->stack_a, env->data_b.max);
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        }
        else
        {
          ft_push_selected_value(&env->stack_a, &env->stack_a, env->data_b.max);
        }*/ /* Work in progress */
        ft_lst_values(env->stack_b, &env->data_b);
        pos = env->data_b.index_max;
        middle = (int)(ft_lst_len(env->stack_b) / 2);
        ft_push_max(&env->stack_a, &env->stack_b, pos, middle);
    //    ft_print_stacks(env->stack_a, env->stack_b); usleep(250000);
    }
    if (ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
    {
      is_sorted = 1;
      break ;
    }
  }
  return (0);
}
