/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_revsorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:00:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/23 14:00:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_is_revsorted(t_node *list)
{
  t_node *temp;

  temp = list;
  while (temp->next != NULL)
  {
    if (temp->data < temp->next->data)
      return (-1);
    temp = temp->next;
  }
  return(1);
}
