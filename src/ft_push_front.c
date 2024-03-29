/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:46:02 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:17:32 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_front(t_node **lst_head, int number)
{
	t_node	*new_node;

	if (lst_head == NULL)
	{
		if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
			exit(-1);
		new_node->data = number;
		new_node->next = NULL;
	}
	else
	{
		if (!(new_node = (t_node*)ft_memalloc(sizeof(t_node))))
			exit(-1);
		new_node->data = number;
		new_node->next = *lst_head;
		*lst_head = new_node;
	}
	return (1);
}
