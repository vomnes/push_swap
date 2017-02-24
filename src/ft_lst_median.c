/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 11:34:08 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/22 11:34:09 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_lst_median(t_node *list, t_data *data, int level)
{
	t_node *temp;
  int *tab;
  int len;
  int i;

  len = ft_lst_len(list);
  if (!(tab = (int*)malloc(sizeof(tab) * len)))
      return (-1);
	temp = list;
  i = 0;
	while (temp != NULL)
	{
		tab[i] = (int)temp->data;
		temp = temp->next;
    i++;
	}
  ft_bubble_sort(tab, len);
	if (ft_lst_len(list) == 4)
			data->median = tab[1];
	else
  		data->median = tab[(int)(len / level)]; //2 -> 25 //3 -> 100 //5 -> 500
  return (0);
}
