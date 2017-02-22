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

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define LIGHT_GREEN "\x1b[92m"
#define YELLOW_GREEN "\x1b[38;5;190m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define GOLD    "\x1b[38;5;214m"
#define BOLD    "\x1b[1;m"
#define ITALIC    "\x1b[3;m"
#define UNDERLINE  "\x1b[4;m"
#define RESET   "\x1b[0m"
#define CLEAN ft_putstr("\033[H\033[2J");

typedef struct  s_data
{
  int           min;
  int           index_min;
  int           max;
  int           index_max;
  int           len;
  int           median;
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
  t_data          data_b;
}                 t_env;

int ft_parsing_input(int argc, char **argv);
int *ft_counting_sort(int *tab, int size_tab, int max);
int			get_next_line(const int fd, char **line);
int ft_shell(t_env *env);
int ft_delete_last(t_node **lst_head);

int ft_push_front(t_node **lst_head, int number);
void	ft_lst_display(t_node *list);
void ft_swap_one_two(t_node **lst_head);
void ft_rotate(t_node **lst_head);
int ft_reverse_rotate(t_node **lst_head);
int ft_push_ab(t_node **stack_one, t_node **stack_two);
int ft_sort(t_env *env);
int	ft_lst_int(t_node *list, t_data *data);
int ft_quicksort_insertion(t_env *env);
int ft_lst_is_sorted(t_node *list);
int ft_lst_values(t_node *lst, t_data *val);
void		ft_bubble_sort(int *tab, int len);
int	ft_lst_median(t_node *list, t_data *data);
int ft_lst_is_under(t_node *list, int limit);
int ft_lst_is_over(t_node *list, int limit);
int	ft_lst_len(t_node *list);
void ft_print_stacks(t_node *stack_a, t_node *stack_b);
int ft_lst_min(t_node *lst);
int ft_lst_bubble_sort(t_node *stack_a, t_node *stack_b);

#endif
