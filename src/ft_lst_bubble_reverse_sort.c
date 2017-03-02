/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubble_reverse_sort.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:00:10 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:26:10 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_basic_bubble_sort(t_node **stack, t_env *env)
{
	t_node *tmp;

	if ((*stack)->next == NULL)
		return (1);
	tmp = *stack;
	while (ft_lst_is_revsorted(*stack) == -1)
	{
		if (tmp->data > tmp->next->data)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sb");
		}
		else
		{
			ft_rotate(&(*stack));
			ft_putendl("rb");
		}
		ft_update_spe(env);
	}
	return (1);
}

static int	ft_lst_rev_bubble_sort(t_node **stack, t_env *env)
{
	t_node *tmp;

	if ((*stack)->next == NULL)
		return (1);
	tmp = *stack;
	while (ft_lst_is_revsorted(*stack) == -1)
	{
		if (tmp->data < tmp->next->data)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sb");
		}
		else
		{
			ft_reverse_rotate(&(*stack));
			ft_putendl("rrb");
		}
		ft_update_spe(env);
	}
	return (1);
}

void		ft_lst_bubble_reverse_sort(t_node **stack, t_env *env)
{
	int min;
	int max;

	min = 0;
	max = 0;
	if (ft_lst_len(*stack) == 2)
	{
		if ((*stack)->data < (*stack)->next->data)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sb");
			ft_update_spe(env);
		}
	}
	if (ft_lst_len(*stack) == 3)
	{
		min = ft_lst_min(*stack);
		max = ft_lst_max(*stack);
		if (((*stack)->next->data == min && (*stack)->next->next->data == max)
		|| ((*stack)->next->data == max && (*stack)->next->next->data == min)
		|| ((*stack)->next->next->data == max && (*stack)->data == min))
			ft_lst_rev_bubble_sort(&(*stack), env);
		else
			ft_lst_basic_bubble_sort(&(*stack), env);
	}
}
