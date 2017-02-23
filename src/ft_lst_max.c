/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:00:41 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/23 14:00:42 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_max(t_node *lst)
{
  t_node *temp;
  int max;

  temp = lst;
  max = -2147483648;
  while (temp != NULL)
  {
    max = temp->data > max ? temp->data : max;
    temp = temp->next;
  }
  return (max);
}
