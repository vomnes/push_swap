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

int ft_lst_bubble_sort(t_node *stack_a, t_node *stack_b)
{
  t_node *tmp;
  int complexity;

  if (stack_a->next == NULL)
      return (1);
  tmp = stack_a;
  complexity = 0;
  ft_print_stacks(stack_a, stack_b);
  while (ft_lst_is_sorted(stack_a) == -1)
  {
    if (tmp->data < tmp->next->data)
    {
      ft_swap_one_two(&stack_a);
      ft_putendl("sa");
      ft_print_stacks(stack_a, stack_b);

      ft_rotate(&stack_a);
      ft_putendl("ra");
      complexity += 2;
      ft_print_stacks(stack_a, stack_b);
    }
    else
    {
      ft_rotate(&stack_a);
      ft_putendl("ra");
      complexity += 1;
      ft_print_stacks(stack_a, stack_b);
    }
  }
  ft_print_stacks(stack_a, stack_b);
  ft_printf(BLUE">> %d\n"RESET, complexity);
  return (1);
}
