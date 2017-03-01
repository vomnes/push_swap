/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:28:28 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 10:28:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void ft_manage_print(t_node **temp_a, t_node **temp_b, int *len_a, \
  int *len_b)
{
  while (*len_a > 0 || *len_b > 0)
  {
    if (*len_a == *len_b)
    {
      ft_printf("%5d       %5d    \n", (*temp_a)->data, (*temp_b)->data);
      (*len_a)--;
      (*len_b)--;
      *temp_a = (*temp_a)->next;
      *temp_b = (*temp_b)->next;
    }
    else if (*len_a > *len_b)
    {
        ft_printf("%5d\n", (*temp_a)->data);
        *temp_a = (*temp_a)->next;
        (*len_a)--;
    }
    else if (*len_a < *len_b)
    {
        ft_printf("            %5d    \n", (*temp_b)->data);
        *temp_b = (*temp_b)->next;
        (*len_b)--;
    }
  }
}

void ft_print_stacks(t_node *stack_a, t_node *stack_b, short flag)
{
	t_node *temp_a;
	t_node *temp_b;
	int len_a;
	int len_b;

	temp_a = stack_a;
	temp_b = stack_b;
	len_a = ft_lst_len(stack_a);
	len_b = ft_lst_len(stack_b);
	while (len_a > 0 || len_b > 0)
    ft_manage_print(&temp_a, &temp_b, &len_a, &len_b);
	ft_printf("===[%sA%s]===   ===[%sB%s]===\n", GOLD, RESET, GOLD, RESET);
	if (flag == 1)
		ft_putstr(" >> ");
}
