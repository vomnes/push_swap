/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:45:46 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:53:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_ab(t_node **stack_one, t_node **stack_two)
{
	int val_to_move;

	val_to_move = -1;
	val_to_move = ft_delete_first(&(*stack_one));
	if (ft_push_front(&(*stack_two), val_to_move) == -1)
		return (-1);
	return (1);
}
