/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_over.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:11:40 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/28 20:11:41 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_is_over(t_node *list, int limit)
{
  t_node *temp;
  int index;

  temp = list;
  index = 0;
  while (temp != NULL)
  {
    if (temp->data >= limit)
      return (index);
    index++;
    temp = temp->next;
  }
  return(-1);
}
