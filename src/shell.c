/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:09:25 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 14:43:24 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_command(char *command, int op)
{
	if (ft_strcmp(command, "exit") == 0)
		return (1);
	if (ft_strcmp(command, "clear") == 0)
	{
		CLEAN
		ft_putstr(" >> ");
	}
	if (ft_strcmp(command, "op") == 0)
		ft_printf("%sNumber of operations : %s%d\n>> ", LIGHT_GREEN, RESET, op);
	if (IS_IN("help") && IS_IN("print") && IS_IN("sa") && IS_IN("sb") &&
	IS_IN("ss") && IS_IN("pa") && IS_IN("pb") && IS_IN("ra") && IS_IN("rb") &&
	IS_IN("rr") && IS_IN("rra") && IS_IN("rrb") && IS_IN("rrr") &&
	IS_IN("exit") && IS_IN("op") && IS_IN("clear"))
	{
		ft_putstr(RED"Unknown Command "RESET);
		ft_putendl(": Try help");
		ft_putstr(" >> ");
	}
	return (0);
}

static int	ft_put_command(char *command, t_node **stack_a, t_node **stack_b, \
	int op)
{
	if (ft_strcmp(command, "print") == 0)
		ft_print_stacks(*stack_a, *stack_b, 1);
	ft_shell_help(command);
	if (*stack_a != NULL && ft_lst_is_sorted(*stack_a) == 1 && *stack_b == NULL)
	{
		ft_printf("%sSorted with %s%d%s operation(s) !%s\n", LIGHT_GREEN, \
		RESET, op, LIGHT_GREEN, RESET);
		return (1);
	}
	return (0);
}

int			ft_shell(t_env *env)
{
	char *command;

	CLEAN
	ft_printf("Push_Swap Shell\nCommand : help - print - sa sb ss pa pb ra rb\
	rr rra rrb rrr - exit\n-> Stack a and stack b :\n");
	ft_print_stacks(env->stack_a, env->stack_b, 1);
	env->op = 0;
	if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
	{
		ft_putstr(LIGHT_GREEN"Already sorted\n"RESET);
		return (1);
	}
	while (get_next_line(0, &command) > 0)
	{
		ft_operations_print(command, &env->stack_a, &env->stack_b, env);
		if (ft_put_command(command, &env->stack_a, &env->stack_b, env->op) == 1)
			return (1);
		if (ft_check_command(command, env->op) == 1)
			return (1);
	}
	return (0);
}
