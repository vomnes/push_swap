/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:59:07 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/02 11:51:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_opt_parsing(t_env *env, int argc, char **argv)
{
	env->spe.flg_print = 0;
	env->spe.frame_rate = 250000;
	if (ft_strcmp(argv[1], "-p") == 0 || ft_strcmp(argv[1], "-print") == 0)
		env->spe.flg_print = 1;
	if (ft_parsing_input(argc, argv, env->spe.flg_print) == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	t_env	env;
	int		len_arg;

	len_arg = argc - 1;
	i = len_arg;
	if (argc == 1)
		return (0);
	if (ft_opt_parsing(&env, argc, argv) == -1)
		return (-1);
	env.stack_a = NULL;
	env.stack_b = NULL;
	while (i > env.spe.flg_print)
		if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i--]))))
			return (-1);
	if (env.spe.flg_print == 1)
		ft_putendl("Print push_swap : [on]");
	if (ft_lst_len(env.stack_a) <= 6)
	{
		if (ft_big_bubble_sort(&env.stack_a, &env.stack_b, &env) == -1)
			return (-1);
	}
	else
		ft_algorithm_sort(&env);
	return (0);
}
