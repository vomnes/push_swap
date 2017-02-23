/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:34:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:34:27 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int ft_push_min(t_node **stack_a, t_node **stack_b, int pos, int middle)
{
  if (pos == 0)
  {
    ft_push_ab(&(*stack_a), &(*stack_b));
    ft_putendl("pb");
  }
  else if (pos < middle)
  {
    ft_rotate(&(*stack_a));
    ft_putendl("ra");
  }
  else if (pos >= middle)
  {
    ft_reverse_rotate(&(*stack_a));
    ft_putendl("rra");
  }
  return (0);
}

int ft_quicksort_insertion__(t_env *env)
{
  int middle;
  int pos;
  int flag;
	int turn;

  middle = 0;
  pos = -1;
  flag = 0;
	turn = 0;
  ft_lst_median(env->stack_a, &env->data_a);
  ft_lst_is_under(env->stack_a, 1);
  while (flag == 0)
  {
    while (turn == 0)
    {
        if (ft_lst_is_under(env->stack_a, env->data_a.median) == -1)
        {
          ft_lst_median(env->stack_a, &env->data_a);
          ft_reverse_rotate(&env->stack_b);
          ft_putendl("rrb");
        }
				if (ft_lst_len(env->stack_a) <= 3)
				{
          ft_big_bubble_sort(&env->stack_a, &env->stack_b, env);
					turn = 1;
				}
        while ((pos = ft_lst_is_under(env->stack_a, env->data_a.median)) >= 0
				&& ft_lst_len(env->stack_a) > 3)
        {
          middle = (int)(env->data_a.len / 2);
					if (env->stack_b != NULL && env->stack_b->next != NULL)
							if (env->stack_b->data < env->stack_b->next->data)
							{
								ft_swap_one_two(&env->stack_b);
								ft_putendl("sb");
							}
					if (env->stack_a != NULL && env->stack_a->next != NULL)
							if (env->stack_a->data > env->stack_a->next->data)
							{
								ft_swap_one_two(&env->stack_a);
								ft_putendl("sa");
							}
					if (ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b != NULL &&
					ft_lst_min(env->stack_a) > ft_lst_min(env->stack_b))
					{
						turn = 1;
						break ;
					}
          ft_push_min(&env->stack_a, &env->stack_b, pos, middle);
					ft_print_stacks(env->stack_a, env->stack_b);
        }
        flag = 0;
    }
    ft_lst_median(env->stack_b, &env->data_b);
    while (turn == 1)
    {
				if (env->stack_b == NULL)
						turn = 0;
        if (ft_lst_is_over(env->stack_b, env->data_b.median) == -1)
        {
          ft_lst_median(env->stack_b, &env->data_b);
          ft_reverse_rotate(&env->stack_a);
          ft_putendl("ra");
        }
        while ((pos = ft_lst_is_over(env->stack_b, env->data_b.median)) >= 0)
        {
          middle = (int)(env->data_b.len / 2);
          if (pos == 0 && env->stack_b->data == env->data_b.median)
          {
            ft_push_ab(&env->stack_b, &env->stack_a);
            ft_rotate(&env->stack_a);
            ft_putendl("pa");
            ft_putendl("ra");
          }
          else if (pos == 0)
          {
            ft_push_ab(&env->stack_b, &env->stack_a);
            ft_putendl("pa");
          }
          else if (pos < middle)
          {
            ft_rotate(&env->stack_b);
            ft_putendl("rb");
          }
          else if (pos >= middle)
          {
            ft_reverse_rotate(&env->stack_b);
            ft_putendl("rrb");
          }
        }
        flag = 0;
    }
    if (env->stack_a != NULL && env->stack_b == NULL && ft_lst_is_sorted(env->stack_a) == 1)
        flag = 1;
    else
        flag = 0;
  }
	ft_putendl("<Final stack>");
  ft_lst_display(env->stack_a);
  return (0);
}
