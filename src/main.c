/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:05:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/20 19:25:10 by vomnes           ###   ########.fr       */
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
//    ft_sort(&env);
//    ft_quicksort_insertion(&env);
    ft_lst_bubble_sort(env.stack_a, env.stack_b);
//    ft_shell(&env);
    return (0);
}
