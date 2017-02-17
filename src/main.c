/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:05:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/16 10:05:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    t_node *stack_a;
    t_node *stack_b;
    int len_arg;

    len_arg = argc - 1;
    i = len_arg;
    if (argc == 0)
      return (0);
    if (!(stack_a = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    stack_a = NULL;
    if (!(stack_b = (t_node*)malloc(sizeof(t_node))))
      return (-1);
    stack_b = NULL;
    while (i)
    {
      if (!(ft_push_front(&stack_a, ft_atoi(argv[i]))))
        return (-1);
      i--;
    }
//    ft_push_back(&lst_tab, 42);
//    ft_delete_first(&lst_tab);
  //  ft_rotate(&lst_tab);
  //  ft_lst_display(lst_tab);
  //  ft_reverse_rotate(&lst_tab);
    ft_push_ab(&stack_a, &stack_b);
    ft_push_ab(&stack_a, &stack_b);
    ft_push_ab(&stack_a, &stack_b);
    ft_push_ab(&stack_a, &stack_b);
    ft_putendl("===[A]===");
    ft_lst_display(stack_a);
    ft_putendl("===[B]===");
    ft_lst_display(stack_b);
    return (0);
}

/*
int *new_stack_a;
int *new_stack_b;
if (!((int*)malloc(sizeof(new_stack_b) * (size_oldstack_b + 1))))
  return (old_stack_b);
new_stack[0] = old_stack_a[size_tab - 1];
i = 0;
while (i < size_oldstack_b)
{
  new_stack_b[i + 1] = old_stack_b[i];
  i++;
}
return (new_stack_b);
if (!((int*)malloc(sizeof(new_stack_a) * (size_oldstack_a - 1))))
  return (old_stack_a);
i = 0;
while (i < size_oldstack_a - 2)
{
  new_stack_a[i] = old_stack_a[i];
  i++;
}
return (new_stack_a);
*/
