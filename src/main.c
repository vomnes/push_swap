/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:05:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 10:05:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_print_int_tab(int *tab, int size_tab)
{
  int i;

  i = 0;
  while (i < size_tab)
  {
    ft_printf("%d\n", tab[i]);
    i++;
  }
}

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

int main(int argc, char **argv)
{
    int i;
    int *tab_int;
    int max;

    i = 0;
    max = -2147483648;
    if (argc == 0)
      return (0);
    if (ft_parsing_input(argc, argv) == -1)
      return (-1);
    if (!(tab_int = (int*)malloc(sizeof(tab_int) * (argc - 1))))
      return (-1);
    while (i < argc - 1)
    {
      tab_int[i] = ft_atoi(argv[i + 1]);
      max = tab_int[i] > max ? tab_int[i] : max;
      i++;
    }
    tab_int = ft_counting_sort(tab_int, argc - 1, max);
    ft_print_int_tab(tab_int, argc - 1);
    return (0);
}
