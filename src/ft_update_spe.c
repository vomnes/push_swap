/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:19:21 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/02 11:28:58 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_spe(t_env *env)
{
	if (env->spe.flg_print == 1)
	{
		ft_print_stacks(env->stack_a, env->stack_b, 0);
		usleep(env->spe.frame_rate);
	}
	if (env->spe.flg_visual == 1)
	{
		ft_visual_in_terminal(env->stack_a, env->stack_b, env);
		usleep(env->spe.frame_rate);
	}
}
