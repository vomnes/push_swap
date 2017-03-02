/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_selected_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:12:03 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:23:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_is_in(t_node *lst, int nb)
{
	t_node *temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->data == nb)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

static int	ft_get_true_index_value(t_node *stack, int nb)
{
	t_node	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	while (tmp != NULL && tmp->data != nb)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void		ft_push_selected_value(t_node **stack_a, t_node **stack_b, int nb, \
t_env *env)
{
	int	pos;
	int	middle;

	middle = (int)(ft_lst_len(*stack_b) / 2);
	while (ft_lst_is_in(*stack_b, nb) == -1)
	{
		pos = ft_get_true_index_value(*stack_b, nb);
		ft_push_max(&(*stack_a), &(*stack_b), pos, middle);
		ft_update_spe(env);
	}
}
