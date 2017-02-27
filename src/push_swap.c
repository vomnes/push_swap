/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:59:07 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/27 11:59:08 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_env env;
    char *command;
    int len_arg;

    len_arg = argc - 1;
    i = len_arg;
    if (argc == 0)
      return (0);
    if (ft_parsing_input(argc, argv) == -1)
      return (-1);
    if (!(env.stack_a = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    env.stack_a = NULL;
    if (!(env.stack_b = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    env.stack_b = NULL;
    while (i)
    {
      if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i]))))
        return (-1);
      i--;
    }
    if (ft_lst_len(env.stack_a) <= 6)
        ft_big_bubble_sort(&env.stack_a, &env.stack_b, &env);
    else
        ft_algorithm_sort(&env);
    while (42) {}
    return (0);
}
