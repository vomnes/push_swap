/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:11:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:19:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_max(t_node **stack_a, t_node **stack_b, int pos, int middle)
{
	if (pos == 0)
	{
		ft_push_ab(&(*stack_b), &(*stack_a));
		ft_putendl("pa");
	}
	else if (pos < middle)
	{
		ft_rotate(&(*stack_b));
		ft_putendl("rb");
	}
	else if (pos >= middle)
	{
		ft_reverse_rotate(&(*stack_b));
		ft_putendl("rrb");
	}
	return (0);
}
