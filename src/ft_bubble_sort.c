/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:33:43 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:33:43 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void		ft_bubble_sort(int *tab, int len)
{
	int		i;
	int		is_sort;

	is_sort = 0;
	while (is_sort == 0)
	{
		is_sort = 1;
		i = 0;
		while (i < len - 1)
		{
			if (tab[i] > tab[i + 1])
      {
        ft_swap(&tab[i], &tab[i + 1]);
        is_sort = 0;
      }
			i++;
		}
	}
}
