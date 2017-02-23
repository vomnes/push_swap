/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_implementation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:07:03 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:07:28 by vomnes           ###   ########.fr       */
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

int ft_quicksort_insertion(t_env *env)
{
  int middle;
  int pos;
  int flag;
  int turn;
  int is_sorted;

  middle = 0;
  pos = -1;
  flag = 0;
  turn = 0;
  ft_lst_median(env->stack_a, &env->data_a);
  is_sorted = 0;
  while (is_sorted == 0)
  {
    while (turn == 0)
    {
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
      //  break ;
      }
      if ((pos = ft_lst_is_under(env->stack_a, env->data_a.median)) < 0)
      {
        ft_lst_median(env->stack_a, &env->data_a);
      }
      /* Check swap swap posibilities */
      if (env->stack_b != NULL && env->stack_b->next != NULL)
      {
        if (env->stack_a->data > env->stack_a->next->data &&
        env->stack_b->data < env->stack_b->next->data)
        {
        //  ft_swap_one_two(&env->stack_a);
        //  ft_swap_one_two(&env->stack_b);
        //  ft_putendl("ss");
        }
        else if (env->stack_a->data > env->stack_a->next->data)
        {
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        }
        if (env->stack_b->data < env->stack_b->next->data)
        {
          ft_swap_one_two(&env->stack_b);
          ft_putendl("sb");
        }
      }
      else
      {
        if (env->stack_a->data > env->stack_a->next->data)
        {
          {
            ft_swap_one_two(&env->stack_a);
            ft_putendl("sa");
          }
        }
      }
      pos = ft_lst_is_under(env->stack_a, env->data_a.median);
      middle = (int)(env->data_a.len / 2);
      ft_push_min(&env->stack_a, &env->stack_b, pos, middle);
      ft_print_stacks(env->stack_a, env->stack_b); usleep(250000);
    }
    while (turn == 1)
    {
      if (env->stack_b == NULL)
      {
        turn = 0;
        break ;
      }
      if ((pos = ft_lst_is_over(env->stack_b, env->data_b.median)) < 0)
      {
        ft_lst_median(env->stack_b, &env->data_b);
      }
      /* Check swap swap posibilities */
      if (env->stack_a != NULL && env->stack_a->next != NULL &&
      env->stack_b != NULL && env->stack_b->next != NULL)
      {
        if (env->stack_a->data > env->stack_a->next->data &&
        env->stack_b->data < env->stack_b->next->data)
        {
    //      ft_swap_one_two(&env->stack_a);
    //      ft_swap_one_two(&env->stack_b);
    //      ft_putendl("ss");
        }
        else if (env->stack_a->data > env->stack_a->next->data)
        {
          ft_swap_one_two(&env->stack_a);
          ft_putendl("sa");
        }
        else if (env->stack_b->data < env->stack_b->next->data)
        {
    //      ft_swap_one_two(&env->stack_b);
    //      ft_putendl("sb");
        }
      }
      ft_lst_values(env->stack_b, &env->data_b);
      pos = env->data_b.index_max;//ft_lst_is_over(env->stack_b, env->data_b.median);
      middle = (int)(ft_lst_len(env->stack_b) / 2);
      ft_push_max(&env->stack_a, &env->stack_b, pos, middle);
      ft_print_stacks(env->stack_a, env->stack_b); usleep(250000);
    }
    if (ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
    {
      is_sorted = 1;
      break ;
    }
  }
  return (0);
}
