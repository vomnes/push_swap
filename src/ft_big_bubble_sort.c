/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:59:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:17:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_is_under_median(t_node *list, int limit)
{
	t_node	*temp;
	int		index;

	temp = list;
	index = 0;
	while (temp != NULL)
	{
		if (temp->data < limit)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}

static void	ft_push_under_median(t_node **stack_a, t_node **stack_b, t_env *env)
{
	if ((*stack_a)->data > (*stack_a)->next->data &&
	(*stack_a)->next->data < env->data_a.median)
	{
		ft_swap_one_two(&(*stack_a));
		ft_putendl("sa");
	}
}

static void	ft_back_on_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_b) != NULL)
	{
		ft_push_ab(&(*stack_b), &(*stack_a));
		ft_putendl("pa");
	}
}

int			ft_big_bubble_sort(t_node **stack_a, t_node **stack_b, t_env *env)
{
	int len;
	int pos;
	int middle;

	len = ft_lst_len(*stack_a);
	if (len <= 3)
		ft_lst_bubble_sort(&(*stack_a));
	else if (len <= 6)
	{
		if (ft_lst_median(*stack_a, &env->data_a, 2) == -1)
			return (-1);
		while (ft_lst_min(*stack_a) < env->data_a.median)
		{
			ft_push_under_median(&(*stack_a), &(*stack_b), env);
			pos = ft_lst_is_under_median(*stack_a, env->data_a.median);
			middle = (int)(env->data_a.len / 2);
			ft_push_min(&(*stack_a), &(*stack_b), pos, middle);
		}
		ft_lst_bubble_sort(&(*stack_a));
		ft_lst_bubble_reverse_sort(&(*stack_b));
		ft_back_on_a(&(*stack_a), &(*stack_b));
	}
	return (0);
}
