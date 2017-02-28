/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:32:19 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/27 11:32:19 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

# define MAX val.max
# define MAX_2 val.max_2
# define MAX_3 val.max_3

static void ft_swap_this(t_node **stack_a)
{
  ft_swap_one_two(&(*stack_a));
  ft_putendl("sa");
}

static void ft_algo_opti_max(t_node **stack_a, t_node **stack_b, t_env *env)
{
  t_max val;

  MAX = env->data_b.max;
  MAX_2 = ft_max_under_max(*stack_b, MAX);
  MAX_3 = ft_max_under_max(*stack_b, MAX_2);
  if (ft_get_index_value(*stack_b, MAX_2) < ft_get_index_value(*stack_b, MAX) &&
  ft_get_index_value(*stack_b, MAX_2) < ft_get_index_value(*stack_b, MAX_3))
  {
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX_2);
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX);
    ft_swap_this(&(*stack_a));
  }
  else if (
  ft_get_index_value(*stack_b, MAX_3) < ft_get_index_value(*stack_b, MAX) &&
  ft_get_index_value(*stack_b, MAX_2) > ft_get_index_value(*stack_b, MAX_3))
  {
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX_3);
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX);
    ft_swap_this(&(*stack_a));
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX_2);
    ft_swap_this(&(*stack_a));
  }
  else
    ft_push_selected_value(&(*stack_a), &(*stack_b), MAX);
}

static void ft_push_on_b(t_node **stack_a, t_node **stack_b,
t_data *data_a, int o_len)
{
  int len;
  int level;
  int pos;
  int middle;

  len = 0;
  level = 2;
  pos = 0;
  middle = 0;
  if ((pos = ft_lst_is_under(*stack_a, data_a->median)) < 0)
  {
    len = ft_lst_len(*stack_a);
    if (o_len >= 1000)
        level = ((1.0 / 75.0) * len + 5.0 / 2.9) + 0.5;
    else
        level = ((1.0 / 62.0) * len + 4.8 / 2.3) + 0.5;
    level = (level < 2) ? 2 : level;
    ft_lst_median(*stack_a, &(*data_a), level);
  }
  pos = ft_lst_is_under(*stack_a, data_a->median);
  middle = (int)(data_a->len / 2);
  ft_push_min(&(*stack_a), &(*stack_b), pos, middle);
}

static void ft_push_on_b_while(t_node **stack_a, t_node **stack_b, t_env *env,
int o_len)
{
  while (2)
  {
      if ((ft_lst_len(*stack_a) == 3 &&
      ft_lst_min(*stack_a) > ft_lst_max(*stack_b)) ||
      (ft_lst_len(*stack_a) == 2))
      {
        ft_big_bubble_sort(&(*stack_a), &(*stack_b), env);
        break ;
      }
      ft_push_on_b(&(*stack_a), &(*stack_b), &env->data_a, o_len);
  //    ft_print_stacks(env->stack_a, env->stack_b); usleep(250000);
  }
}

void ft_algorithm_sort(t_env *env)
{
  int level;
  int original_len;

  original_len = ft_lst_len(env->stack_a);
  level = ((1.0 / 75.0) * original_len + 5.0 / 2.9) + 0.5;
  level = (level < 2) ? 2 : level;
  ft_lst_median(env->stack_a, &env->data_a, level);
  while (1)
  {
    ft_push_on_b_while(&env->stack_a, &env->stack_b, env, original_len);
    while (3)
    {
        if (env->stack_b == NULL)
            break ;
        ft_lst_values(env->stack_b, &env->data_b);
        ft_algo_opti_max(&env->stack_a, &env->stack_b, env);
        //ft_print_stacks(env->stack_a, env->stack_b); //usleep(250000);
    }
    if (ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
      break ;
  }
}
