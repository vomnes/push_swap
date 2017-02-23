/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:00:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/23 14:00:53 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_min(t_node *lst)
{
  t_node *temp;
  int min;

  temp = lst;
  min = 2147483647;
  while (temp != NULL)
  {
    min = temp->data < min ? temp->data : min;
    temp = temp->next;
  }
  return (min);
}
