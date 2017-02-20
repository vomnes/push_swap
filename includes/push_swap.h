/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:07:48 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 10:07:49 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct  s_data
{
  int           min;
  int           index_min;
  int           len;
}               t_data;

typedef struct    s_node
{
    int           data;
    struct s_node *next;
}                 t_node;

typedef struct    s_env
{
  t_node          *stack_a;
  t_data          data_a;
  t_node          *stack_b;
}                 t_env;

int ft_parsing_input(int argc, char **argv);
int *ft_counting_sort(int *tab, int size_tab, int max);
int			get_next_line(const int fd, char **line);
void ft_shell(t_env *env);
int ft_delete_last(t_node **lst_head);

int ft_push_front(t_node **lst_head, int number);
void	ft_lst_display(t_node *list);
void ft_swap_one_two(t_node **lst_head);
void ft_rotate(t_node **lst_head);
int ft_reverse_rotate(t_node **lst_head);
int ft_push_ab(t_node **stack_one, t_node **stack_two);
int ft_sort(t_env *env);

#endif
