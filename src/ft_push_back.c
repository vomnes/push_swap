/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:45:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:16:00 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_back(t_node **lst_head, int number)
{
	t_node	*new_node;

	new_node = *lst_head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	if (!(new_node->next = (t_node*)malloc(sizeof(t_node))))
		return (-1);
	new_node->next->data = number;
	new_node->next->next = NULL;
	return (1);
}
