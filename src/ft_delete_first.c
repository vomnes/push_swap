/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:45:31 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/27 11:45:31 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_delete_first(t_node **lst_head)
{
  t_node *old_head;
  int deleted_value;

  old_head = NULL;
  deleted_value = -1;
  if (*lst_head == NULL)
    return (-1);
  old_head = *lst_head;
  deleted_value = (*lst_head)->data;
  *lst_head = (*lst_head)->next;
  free(old_head);
  return (deleted_value);
}
