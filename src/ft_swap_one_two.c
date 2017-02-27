/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_one_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:46:30 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/27 11:46:30 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_swap_one_two(t_node **lst_head)
{
  if ((*lst_head != NULL) && ((*lst_head)->next != NULL))
      ft_swap(&((*lst_head)->data), &((*lst_head)->next->data));
}
