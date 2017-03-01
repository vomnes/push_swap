/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_issorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:35:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:36:01 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_is_sorted(t_node *list)
{
	t_node	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (-1);
		temp = temp->next;
	}
	return (1);
}
