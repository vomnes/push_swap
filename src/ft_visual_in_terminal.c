/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_in_terminal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:55:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/03 15:21:17 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX env->spe.max
#define POS_TXT (18 / 2 + (max_x + 1) / 2)

static int	ft_stack_a_in_tab(char **tab, int value, int pos, int max)
{
	int i;

	i = 0;
	max--;
	while (i < value)
	{
		tab[max - i][pos] = '#';
		i++;
	}
	return (0);
}

static int	ft_stack_b_in_tab(char **tab, int value, int pos, int max)
{
	int i;

	i = 0;
	max--;
	while (i < value)
	{
		tab[max - i][pos] = '@';
		i++;
	}
	return (0);
}

static void	ft_print_tab(char **tab, int max_x, int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (max_x >= 18)
		ft_printf("%4c%s%*s%*c\n"RESET, ' ', UNDERLINE, \
		POS_TXT, "Push_swap - Visual", (max_x + 1) - POS_TXT, ' ');
	while (y < max_y)
	{
		x = 0;
		ft_printf("%3d|", max_y - y);
		while (x < max_x + 1)
		{
			if (tab[y][x] == '#')
				ft_putstr(GOLD"#"RESET);
			else if (tab[y][x] == '@')
				ft_putstr(WHITE_BLUE"#"RESET);
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int			ft_visual_in_terminal(t_node *stack_a, t_node *stack_b, t_env *env)
{
	t_node	*tmp_a;
	t_node	*tmp_b;
	int		index;

	tmp_a = stack_a;
	tmp_b = stack_b;
	index = 0;
	ft_putstr(CLEAR);
	while (tmp_a != NULL)
	{
		ft_stack_a_in_tab(env->spe.tab_visual, tmp_a->data, index++, MAX);
		tmp_a = tmp_a->next;
	}
	index++;
	while (tmp_b != NULL)
	{
		ft_stack_b_in_tab(env->spe.tab_visual, tmp_b->data, index++, MAX);
		tmp_b = tmp_b->next;
	}
	ft_print_tab(env->spe.tab_visual, env->spe.len, MAX);
	index = 0;
	while (env->spe.tab_visual[index])
		ft_memset((char*)env->spe.tab_visual[index++], ' ', env->spe.len + 1);
	return (0);
}
