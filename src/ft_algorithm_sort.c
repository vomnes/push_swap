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

  middle = 0;
  pos = -1;
  flag = 0;
  turn = 0;
  len = ft_lst_len(env->stack_a);
  original_len = ft_lst_len(env->stack_a);
  level = ((1.0 / 75.0) * len + 5.0 / 2.9) + 0.5;
  level = (level < 2) ? 2 : level;
  ft_lst_median(env->stack_a, &env->data_a, level); /* Median */
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
          ft_lst_median(env->stack_a, &env->data_a, level); /* Median */
        }
      /*  if (env->stack_a->data == env->stack_a->next->data + 1)
        {
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        } */
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
        ft_lst_values(env->stack_b, &env->data_b);
        pos = env->data_b.index_max;
    /*    if (env->stack_b != NULL && env->stack_b->next != NULL && ft_lst_len(env->stack_b) > 2)
        {
        //  ft_print_stacks(env->stack_a, env->stack_b); //usleep(250000);
          if (env->stack_b->data == env->data_b.max - 1)
          {
            ft_push_ab(&env->stack_b, &env->stack_a);
            ft_putendl("pa");
          }
        }
        if (env->stack_a->data > env->stack_a->next->data)
        {
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        }*/
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
