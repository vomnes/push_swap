/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:49:37 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:36:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_shell_help_txt(void)
{
	ft_putstr("==============================[Help");
	ft_putendl("]==============================");
	ft_putendl("print : Print stack a and stack b\n");
	ft_putstr("sa    : Swap a - swap the first 2 elements at the top of");
	ft_putendl(" stack a.");
	ft_putendl("        Do nothing if there is only one or no elements).");
	ft_putstr("sb    : Swap b - swap the first 2 elements at the top of");
	ft_putendl(" stack b.");
	ft_putendl("        Do nothing if there is only one or no elements).");
	ft_putendl("ss    : sa and sb at the same time.\n");
	ft_putstr("pa    : Push a - take the first element at the top of b and");
	ft_putendl(" put it");
	ft_putendl("        at the top of a. Do nothing if b is empty.");
	ft_putstr("pb    : Push b - take the first element at the top of a and");
	ft_putendl(" put it");
	ft_putendl("        at the top of b. Do nothing if a is empty.\n");
}

void		ft_shell_help(char *command)
{
	if (ft_strcmp(command, "help") == 0)
	{
		ft_shell_help_txt();
		ft_putstr("ra    : Rotate a - shift up all elements of stack a by 1.");
		ft_putendl(" The first");
		ft_putendl("        element becomes the last one.");
		ft_putstr("rb    : Rotate b - shift up all elements of stack b by 1.");
		ft_putendl(" The first");
		ft_putendl("        element becomes the last one.");
		ft_putendl("rr    : Ra and rb at the same time.\n");
		ft_putstr("rra   : Reverse rotate a - shift down all elements of \
stack");
		ft_putendl("a by 1.");
		ft_putendl("        The last element becomes the first one.");
		ft_putstr("rrb   : Reverse rotate b - shift down all elements of \
stack");
		ft_putendl("b by 1.");
		ft_putendl("        The last element becomes the first one.");
		ft_putendl("rrr   : rra and rrb at the same time.\n");
		ft_putendl("exit  : exit ./checker");
		ft_putstr("==================================");
		ft_putendl("================================");
		ft_putstr(" >> ");
	}
}
