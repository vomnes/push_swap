/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:47:27 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/17 12:47:28 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_lst_display(t_node *list)
{
	t_node *temp;

	temp = list;
	while (temp != NULL)
	{
		ft_putnbr((int)temp->data);
    ft_putchar('\n');
		temp = temp->next;
	}
}

int ft_push_front(t_node **lst_head, int number)
{
    t_node *new_node;
    if (!(new_node = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    new_node->data = number;
    new_node->next = *lst_head;
    *lst_head = new_node;
    return (1);
}

int ft_push_back(t_node **lst_head, int number)
{
  t_node *new_node;
  new_node = *lst_head;
  while (new_node->next != NULL)
    new_node = new_node->next;
  if (!(new_node->next = (t_node*)malloc(sizeof(t_node))))
    return (-1);
  new_node->next->data = number;
  new_node->next->next = NULL;
  return (1);
}

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

void ft_swap_one_two(t_node **lst_head)
{
  if ((*lst_head != NULL) && ((*lst_head)->next != NULL))
      ft_swap(&((*lst_head)->data), &((*lst_head)->next->data));
}

void ft_rotate(t_node **lst_head)
{
  t_node *lst;

  lst = *lst_head;
  while (lst->next != NULL)
  {
      ft_swap(&(lst->data), &(lst->next->data));
      lst = lst->next;
  }
}

int ft_reverse_rotate(t_node **lst_head)
{
  int first_to_last;

  first_to_last = -1;
  first_to_last = ft_delete_first(&(*lst_head));
  if (ft_push_back(&(*lst_head), first_to_last) == -1)
    return (-1);
  return (1);
}

int ft_push_ab(t_node **stack_one, t_node **stack_two)
{
    int val_to_move;

    val_to_move = -1;
    val_to_move = ft_delete_first(&(*stack_one));
    if (ft_push_front(&(*stack_two), val_to_move) == -1)
      return (-1);
    return (1);
}
