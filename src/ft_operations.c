/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:48:54 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:46:38 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_shell_swap_pa(char *command, t_node **stack_a, \
t_node **stack_b, int *op)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		ft_swap_one_two(stack_a);
		(*op)++;
	}
	if (ft_strcmp(command, "sb") == 0)
	{
		ft_swap_one_two(stack_b);
		(*op)++;
	}
	if (ft_strcmp(command, "ss") == 0)
	{
		ft_swap_one_two(stack_a);
		ft_swap_one_two(stack_b);
		(*op) += 2;
	}
	if (ft_strcmp(command, "pa") == 0)
	{
		ft_push_ab(stack_b, stack_a);
		(*op)++;
	}
}

static void		ft_shell_reverse_pb(char *command, t_node **stack_a, \
t_node **stack_b, int *op)
{
	if (ft_strcmp(command, "pb") == 0)
	{
		ft_push_ab(stack_a, stack_b);
		(*op)++;
	}
	if (ft_strcmp(command, "ra") == 0)
	{
		ft_rotate(stack_a);
		(*op)++;
	}
	if (ft_strcmp(command, "rb") == 0)
	{
		ft_rotate(stack_b);
		(*op)++;
	}
	if (ft_strcmp(command, "rr") == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		(*op) += 2;
	}
}

static void		ft_shell_reverse_rotate(char *command, t_node **stack_a, \
t_node **stack_b, int *op)
{
	if (ft_strcmp(command, "rra") == 0)
	{
		ft_reverse_rotate(stack_a);
		(*op)++;
	}
	else if (ft_strcmp(command, "rrb") == 0)
	{
		ft_reverse_rotate(stack_b);
		(*op)++;
	}
	else if (ft_strcmp(command, "rrr") == 0)
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
		(*op) += 2;
	}
}

void			ft_operations(char *command, t_node **stack_a, \
t_node **stack_b, t_env *env)
{
	ft_shell_swap_pa(command, &(*stack_a), &(*stack_b), &env->op);
	ft_shell_reverse_pb(command, &(*stack_a), &(*stack_b), &env->op);
	ft_shell_reverse_rotate(command, &(*stack_a), &(*stack_b), &env->op);
}
