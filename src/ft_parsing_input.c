/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:13:39 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 11:13:40 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int ft_isdigitstr(char *str)
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

int ft_parsing_input(int argc, char **argv)
{
  int i;

  i = 0;
  while (i < argc - 1)
  {
    if (ft_isdigitstr(argv[i + 1]) == -1)
    {
      ft_putstr("Error\n");
      return (-1);
    }
    i++;
  }
  return (0);
}
