/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:59:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/23 13:59:41 by vomnes           ###   ########.fr       */
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

int ft_lst_is_under_median(t_node *list, int limit)
{
  t_node *temp;
  int index;

  temp = list;
  index = 0;
  while (temp != NULL)
  {
    if (temp->data < limit)
      return (index);
    index++;
    temp = temp->next;
  }
  return(-1);
}

int ft_big_bubble_sort(t_node **stack_a, t_node **stack_b, t_env *env)
{
  int len;
  int pos;
  int middle;

  len = ft_lst_len(*stack_a);
  if (len <= 3)
      ft_lst_bubble_sort(&(*stack_a));
  else if (len <= 6)
  {
      ft_lst_median(*stack_a, &env->data_a, 2);
      while (ft_lst_min(*stack_a) < env->data_a.median)
      {
          if ((*stack_a)->data > (*stack_a)->next->data &&
          (*stack_a)->next->data < env->data_a.median)
          {
            ft_swap_one_two(&(*stack_a));
            ft_putendl("sa");
          }
          pos = ft_lst_is_under_median(*stack_a, env->data_a.median);
          middle = (int)(env->data_a.len / 2);
          ft_push_min(&(*stack_a), &(*stack_b), pos, middle);
      }
      ft_lst_bubble_sort(&(*stack_a));
      ft_lst_bubble_reverse_sort(&(*stack_b));
      while ((*stack_b) != NULL)
      {
        ft_push_ab(&(*stack_b), &(*stack_a));
        ft_putendl("pa");
      }
  }
  return (0);
}
