/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:46:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:29:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **lst_head)
{
	t_node *lst;

	lst = *lst_head;
	if (*lst_head != NULL)
	{
		while (lst->next != NULL)
		{
			ft_swap(&(lst->data), &(lst->next->data));
			lst = lst->next;
		}
	}
}
