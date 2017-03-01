/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:12:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:19:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker(t_env *env)
{
	char *command;

	env->op = 0;
	while (get_next_line(0, &command) > 0)
	{
		ft_operations(command, &env->stack_a, &env->stack_b, env);
		if (IS_IN("sa") && IS_IN("sb") && IS_IN("ss") && IS_IN("pa") &&
		IS_IN("pb") && IS_IN("ra") && IS_IN("rb") && IS_IN("rr") &&
		IS_IN("rra") && IS_IN("rrb") && IS_IN("rrr"))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}
	if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 &&
	env->stack_b == NULL)
	{
		ft_putendl("OK");
		return (1);
	}
	else
		ft_putendl("KO");
	return (0);
}
