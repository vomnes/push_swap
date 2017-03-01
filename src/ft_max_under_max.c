/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_under_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:54:22 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 08:54:23 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_max_under_max(t_node *stack, int max_less)
{
  t_node *tmp;
  int tmp_nb;

  tmp = stack;
  tmp_nb = -2147483648;
  while (tmp != NULL)
  {
    if (tmp->data < max_less && tmp->data > tmp_nb)
        tmp_nb = tmp->data;
    tmp = tmp->next;
  }
  return (tmp_nb);
}
