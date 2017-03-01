/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:42:17 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:29:59 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_basic_bubble_sort(t_node **stack, t_env *env)
{
	t_node *tmp;

	if ((*stack)->next == NULL)
		return (1);
	tmp = *stack;
	while (ft_lst_is_sorted(*stack) == -1)
	{
		if (tmp->data < tmp->next->data)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sa");
		}
		else
		{
			ft_rotate(&(*stack));
			ft_putendl("ra");
		}
		if (env->flg_print == 1)
		{
			ft_print_stacks(env->stack_a, env->stack_b, 0);
			usleep(env->frame_rate);
		}
	}
	return (1);
}

static int	ft_lst_rev_bubble_sort(t_node **stack, t_env *env)
{
	t_node *tmp;

	if ((*stack)->next == NULL)
		return (1);
	tmp = *stack;
	while (ft_lst_is_sorted(*stack) == -1)
	{
		if (tmp->data > tmp->next->data)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sa");
		}
		else
		{
			ft_reverse_rotate(&(*stack));
			ft_putendl("rra");
		}
		if (env->flg_print == 1)
		{
			ft_print_stacks(env->stack_a, env->stack_b, 0);
			usleep(env->frame_rate);
		}
	}
	return (1);
}

void		ft_lst_bubble_sort(t_node **stack, t_env *env)
{
	int min;
	int max;

	min = 0;
	max = 0;
	if (ft_lst_len(*stack) <= 2)
		ft_lst_basic_bubble_sort(&(*stack), env);
	if (ft_lst_len(*stack) == 3)
	{
		min = ft_lst_min(*stack);
		max = ft_lst_max(*stack);
		if ((*stack)->next->next->data == min)
			ft_lst_rev_bubble_sort(&(*stack), env);
		else if ((*stack)->next->data == min &&
		(*stack)->next->next->data == max)
		{
			ft_swap_one_two(&(*stack));
			ft_putendl("sa");
			if (env->flg_print == 1)
			{
				ft_print_stacks(env->stack_a, env->stack_b, 0);
				usleep(env->frame_rate);
			}
		}
		else
			ft_lst_basic_bubble_sort(&(*stack), env);
	}
}
