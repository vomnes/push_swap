# include "push_swap.h"

int ft_lst_min(t_node *lst, t_env *env)
{
  t_node *temp;
  int index;

  temp = lst;
  index = 0;
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

  env->data_a.min = 2147483647;
  env->data_a.index_min = 1;
  middle = 0;
  while (env->stack_a != NULL)
  {
      env->data_a.len = ft_lst_min(env->stack_a, env);
      middle = env->data_a.len / env->data_a.index_min;
      if (env->data_a.index_min == 0)
          ft_push_ab(&env->stack_b, &env->stack_a);
      else if (env->data_a.index_min < middle)
          ft_rotate(&env->stack_a);
      else
          ft_reverse_rotate(&env->stack_a);
      ft_lst_display(env->stack_a);
      ft_putendl("========[OK]========");
  }
  ft_printf("len = %d | MIN = %d | index = %d\n",
  env->data_a.len, env->data_a.min, env->data_a.index_min);
  return (0);
}
