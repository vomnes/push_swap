/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:34:17 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:34:18 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_values(t_node *lst, t_data *val)
{
  t_node *temp;
  int index;

  temp = lst;
  index = 0;
  val->min = 2147483647;
  val->max = -2147483648;
  val->index_min = 1;
  val->index_max = 1;
  while (temp != NULL)
  {
    val->index_min = (int)temp->data < val->min ?
    index : val->index_min;
    val->min = (int)temp->data < val->min
    ? (int)temp->data : val->min;
    val->index_max = (int)temp->data > val->max ?
    index : val->index_max;
    val->max = (int)temp->data > val->max
    ? (int)temp->data : val->max;
    temp = temp->next;
    index++;
  }
  return (index);
}
