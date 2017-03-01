/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:34:00 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:36:56 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_len(t_node *list)
{
	t_node	*temp;
	int		count;

	temp = list;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
