/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:13:39 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 12:50:47 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Check doubles */
static int	ft_isdigitstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && str[i] != '-')
			return (-1);
		i++;
	}
	return (1);
}

static int ft_check_double(int len, char **argv)
{
	int		*tab;
	int		i;

	if (!(tab = (int*)malloc(sizeof(tab) * len)))
		return (-1);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_lltoi(argv[i + 1]);
		i++;
	}
	ft_bubble_sort(tab, len);
	i = 0;
	while (i < len)
	{
		if (tab[i] == tab[i - 1])
					return (-1);
		i++;
	}
	free(tab);
	return (0);
}

int			ft_parsing_input(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_isdigitstr(argv[i + 1]) == -1
		|| ft_lltoi(argv[i + 1]) >= 2147483648
		|| ft_lltoi(argv[i + 1]) < -2147483648)
		{
			ft_putendl_fd("Error", 2);
			return (-1);
		}
		i++;
	}
	if (ft_check_double(argc - 1, argv) == -1)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	return (0);
}
