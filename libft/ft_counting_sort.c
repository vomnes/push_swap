/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counting_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:41:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 13:41:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int *ft_counting_sort(int *tab, int size_tab, int max)
{
    int *tab_count;
    int x;
    int i;
    int j;

    x = 0;
    i = 0;
    j = 0;
    if (max <= 0)
      return (tab);
    if (!(tab_count = (int*)malloc(sizeof(tab_count) * (max - 1))))
      return (tab);
    while (i < max + 1)
      tab_count[i++] = 0;
    i = 0;
    while (i < size_tab)
      tab_count[tab[i++]]++;
    i = 0;
    while (i < max + 1)
    {
      j = 0;
      while (j < tab_count[i])
      {
        tab[x++] = i;
        j++;
      }
      i++;
    }
    free(tab_count);
    return (tab);
}
