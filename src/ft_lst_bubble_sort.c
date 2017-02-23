/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:42:17 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 15:42:27 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_basic_bubble_sort(t_node **stack_a, t_node **stack_b)
{
  t_node *tmp;

  if ((*stack_a)->next == NULL)
      return (1);
  tmp = *stack_a;
  while (ft_lst_is_sorted(*stack_a) == -1)
  {
    if (tmp->data < tmp->next->data)
    {
      ft_swap_one_two(&(*stack_a));
      ft_putendl("sa");
      ft_rotate(&(*stack_a));
      ft_putendl("ra");
    }
    else
    {
      ft_rotate(&(*stack_a));
      ft_putendl("ra");
    }
  }
  return (1);
}

int ft_lst_rev_bubble_sort(t_node **stack_a, t_node **stack_b)
{
  t_node *tmp;

  if ((*stack_a)->next == NULL)
      return (1);
  tmp = *stack_a;
  while (ft_lst_is_sorted(*stack_a) == -1)
  {
    if (tmp->data > tmp->next->data)
    {
      ft_swap_one_two(&(*stack_a));
      ft_putendl("sa");
      ft_reverse_rotate(&(*stack_a));
      ft_putendl("rra");
    }
    else
    {
      ft_reverse_rotate(&(*stack_a));
      ft_putendl("rra");
    }
  }
  return (1);
}

void ft_lst_bubble_sort(t_node *stack_a, t_node *stack_b)
{
  int min;
  int max;

  min = 0;
  max = 0;
  if (ft_lst_len(stack_a) <= 2)
      ft_lst_basic_bubble_sort(&stack_a, &stack_b);
  if (ft_lst_len(stack_a) == 3)
  {
      min = ft_lst_min(stack_a);
      max = ft_lst_max(stack_a);
      if (stack_a->next->next->data == min)
        ft_lst_rev_bubble_sort(&stack_a, &stack_b);
      else if (stack_a->next->data == min &&
      stack_a->next->next->data == max)
      {
        ft_swap_one_two(&stack_a);
        ft_putendl("sa");
      }
      else
        ft_lst_basic_bubble_sort(&stack_a, &stack_b);
  }
  ft_print_stacks(stack_a, stack_b);
}
