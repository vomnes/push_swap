# include "push_swap.h"

int ft_lst_min(t_node *lst, t_env *env)
{
  t_node *temp;
  int index;

  temp = lst;
  index = 0;
  env->data_a.min = 2147483647;
  env->data_a.index_min = 1;
  while (temp != NULL)
  {
    env->data_a.index_min = (int)temp->data < env->data_a.min ?
    index : env->data_a.index_min;
    env->data_a.min = (int)temp->data < env->data_a.min
    ? (int)temp->data : env->data_a.min;
    temp = temp->next;
    index++;
  }
  return (index);
}

int ft_sort(t_env *env)
{
  int middle;
  int complexity;

  middle = 0;
  complexity = 0;
  while (env->stack_a != NULL)
  {
      env->data_a.len = ft_lst_min(env->stack_a, env);
      middle = (int)(env->data_a.len / 2);
      ft_printf("middle = %d | len = %d | MIN = %d | index = %d\n",
      middle, env->data_a.len, env->data_a.min, env->data_a.index_min);
      if (env->data_a.index_min == 0)
      {
        ft_push_ab(&env->stack_a, &env->stack_b);
        complexity++;
        ft_putendl("pb");
      }
      else if (env->data_a.index_min == 1)
      {
        ft_swap_one_two(&env->stack_a);
        complexity++;
        ft_putendl("sa");
      }
      else if (env->data_a.index_min < middle)
      {
        ft_rotate(&env->stack_a);
        complexity++;
        ft_putendl("ra");
      }
      else
      {
        ft_reverse_rotate(&env->stack_a);
        complexity++;
        ft_putendl("rra");
      }
  }
  while (env->stack_b != NULL)
  {
      ft_push_ab(&env->stack_b, &env->stack_a);
      complexity++;
      ft_putendl("pa");
  }
//  ft_printf("len = %d | MIN = %d | index = %d\n",
//  env->data_a.len, env->data_a.min, env->data_a.index_min);
  ft_printf("complexity >> %d\n", complexity);
//  ft_lst_display(env->stack_a);
  return (0);
}
