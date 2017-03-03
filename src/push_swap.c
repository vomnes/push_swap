/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:59:07 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/03 16:32:29 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define TAB env->spe.tab_visual

static int	ft_opt_parsing(t_env *env, int argc, char **argv)
{
	env->spe.flg_print = 0;
	env->spe.flg_visual = 0;
	env->spe.frame_rate = 250000;
	env->spe.max = 0;
	env->spe.min = 0;
	if (ft_strcmp(argv[1], "-p") == 0 || ft_strcmp(argv[1], "-print") == 0)
		env->spe.flg_print = 1;
	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-visual") == 0)
		env->spe.flg_visual = 1;
	if (ft_parsing_input(argc, argv, env->spe.flg_print +\
	env->spe.flg_visual) == -1)
		return (-1);
	env->spe.len = argc - env->spe.flg_print - env->spe.flg_visual;
	if (env->spe.flg_print == 1 || env->spe.flg_visual == 1)
		ft_putendl("Option -print/-visual [on]");
	return (0);
}

static char	**ft_malloc_tab(char **tab, int max, int len)
{
	int i;

	i = 0;
	if (!(tab = (char**)ft_memalloc(sizeof(*tab) * (max + 1))))
		return (NULL);
	while (i < max)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(tab) * (len + 1 + 1))))
			return (NULL);
		ft_memset((char*)tab[i], ' ', len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static int	ft_init_spe(t_env *env)
{
	env->spe.max = ft_lst_max(env->stack_a);
	env->spe.min = ft_lst_min(env->stack_a);
	env->spe.len = ft_lst_len(env->stack_a);
	if (env->spe.min <= 0 || env->spe.max <= 0 || env->spe.max > 100)
		env->spe.flg_visual = 0;
	else
	{
		if (!(env->spe.tab_visual = ft_malloc_tab(env->spe.tab_visual, \
		env->spe.max, env->spe.len)))
			return (-1);
	}
	return (0);
}

static int	ft_run_sort(t_env *env)
{
	if (ft_lst_is_sorted(env->stack_a) == 1)
	{
		ft_update_spe(env);
	}
	else if (env->spe.len <= 6)
	{
		if (ft_big_bubble_sort(&env->stack_a, &env->stack_b, env) == -1)
			return (-1);
	}
	else
	{
		if (ft_algorithm_sort(env) == -1)
			return (-1);
	}
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
	while (i > (env.spe.flg_print + env.spe.flg_visual))
		if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i--]))))
			return (-1);
	if (ft_init_spe(&env) == -1)
		return (-1);
	if (ft_run_sort(&env) == -1)
		return (-1);
	if (env.spe.flg_visual == 1)
		ft_free_tab(env.spe.tab_visual);
	return (0);
}
