/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:11:29 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:23:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index_value(t_node *stack, int nb)
{
	t_node	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	if (tmp->data == nb)
		return (0);
	while (tmp != NULL && tmp->data != nb)
	{
		tmp = tmp->next;
		index++;
	}
	if (index > ft_lst_len(stack) / 2)
		index = ft_lst_len(stack) - index;
	return (index);
}
