# include "push_swap.h"

int ft_lst_min(t_node *lst, t_data *val)
{
  t_node *temp;
  int index;

  temp = lst;
  index = 0;
  val->min = 2147483647;
  val->max = -2147483648;
  val->index_min = 1;
  val->index_max = 1;
  while (temp != NULL)
  {
    val->index_min = (int)temp->data < val->min ?
    index : val->index_min;
    val->min = (int)temp->data < val->min
    ? (int)temp->data : val->min;
    val->index_max = (int)temp->data > val->max ?
    index : val->index_max;
    val->max = (int)temp->data > val->max
    ? (int)temp->data : val->max;
    temp = temp->next;
    index++;
  }
  return (index);
}

int ft_sort(t_env *env)
{
  int middle;
  int complexity;
  t_node *lst;

  middle = 0;
  complexity = 0;
  while (env->stack_a != NULL)
  {
      env->data_a.len = ft_lst_min(env->stack_a, &env->data_a);
      middle = (int)(env->data_a.len / 2);
  //    ft_printf("middle = %d | len = %d | MIN = %d | index = %d\n",
  //    middle, env->data_a.len, env->data_a.min, env->data_a.index_min);
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
  ft_lst_display(env->stack_a);
  ft_printf("complexity >> %d\n", complexity);
  return (0);
}