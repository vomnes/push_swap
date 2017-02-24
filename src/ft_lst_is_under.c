/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_under.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:33:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:33:52 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_lst_is_under(t_node *list, int limit)
{
  t_node *temp;
  int index;

  temp = list;
  index = 0;
  while (temp != NULL)
  {
    if (temp->data <= limit)
      return (index);
    index++;
    temp = temp->next;
  }
  return(-1);
}
/*
int ft_lst_is_under(t_node *list, int limit)
{
  t_node *temp;
  int index;
  int index_one;
  int index_one_ok;
  int index_two;
  int one;
  int two;
  int len;

  temp = list;
  index = 0;
  index_one = 0;
  one = 0;
  index_two = 0;
  two = 0;
  index_one_ok = 0;
  len = ft_lst_len(temp);
  while (temp != NULL)
  {
    if (temp->data <= limit && index_one_ok == 0)
    {
      index_one = index;
      one = temp->data;
      index_two = index;
      two = temp->data;
      index_one_ok = 1;
    }
    else if (temp->data <= limit)
    {
      index_two = index;
      two = temp->data;
    }
    index++;
    temp = temp->next;
  }
  ft_printf("limit     : %d\n", limit);
  ft_printf("index_one : %d - value : %d -> index_one : %d\n", index_one, one, index_one);
  ft_printf("index_two : %d - value : %d -> len - index_two : %d\n", index_two, two, len - index_two);
  ft_printf("len       : %d\n", len);
  if (index_one == len - index_two)
  {
    if (one < two)
      return (index_one);
    else
      return (index_two);
  }
  else if (index_one < len - index_two)
    return (index_one);
  else
    return (index_two);
  return(-1);
}
*/
