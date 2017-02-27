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
    int len_arg;

    len_arg = argc - 1;
    i = len_arg;
    if (argc == 0)
      return (0);
    if (ft_parsing_input(argc, argv) == -1)
      return (-1);
    env.stack_a = NULL;
    env.stack_b = NULL;
    while (i)
    {
      if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i]))))
        return (-1);
      i--;
    }
    /* Test */
  /*  ft_print_stacks(env.stack_a, env.stack_b);
    ft_lst_values(env.stack_a, &env.data_a);
    if (index_val > ft_lst_len(stack) / 2)
        index_val = ft_lst_len(stack) - index_val;
    ft_printf("max >> %d\n", env.data_a.max);
    ft_printf("max index >> %d\n", env.data_a.index_max);
    ft_printf("max_less >> %d\n", ft_max_under_max(env.stack_a, env.data_a.max));
    ft_printf("max_less index >> %d\n", ft_max_under_max_index(env.stack_a, env.data_a.max));
    ft_printf("max_less_less >> %d\n", ft_max_under_max(env.stack_a, ft_max_under_max(env.stack_a, env.data_a.max)));
    ft_printf("max_less_less index >> %d\n", ft_max_under_max_index(env.stack_a, ft_max_under_max(env.stack_a, env.data_a.max)));*/
    /* Test */
    if (ft_lst_len(env.stack_a) <= 6)
    {
      if (ft_big_bubble_sort(&env.stack_a, &env.stack_b, &env) == -1)
        return (-1);
    }
    else
        ft_algorithm_sort(&env);
    return (0);
}
