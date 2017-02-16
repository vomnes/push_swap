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

void ft_print_int_tab(int *tab, int size_tab)
{
  int i;

  i = 0;
  while (i < size_tab)
  {
    ft_printf("%d\n", tab[i]);
    i++;
  }
}

void ft_swap_ab(int *stack)
{
  ft_swap(&stack[0], &stack[1]);
}

void ft_rotate_ab(int *stack, int size_tab)
{
  int i;

  i = 0;
  while (i < size_tab - 1)
  {
      ft_swap(&stack[i], &stack[i + 1]);
      i++;
  }
}

void ft_reverse_rotate_ab(int *stack, int size_tab)
{
  int i;

  i = size_tab - 1;
  while (i)
  {
      ft_swap(&stack[i - 1], &stack[i]);
      i--;
  }
}

void ft_push_ab()
{
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
}

//sa ft_swap(&stack_a[0], &stack_a[1]);
//sb ft_swap(&stack_b[0], &stack_b[1]);

int ft_stack(int *tab_int, int size_tab)
{
  int *stack_a;
  int *stack_b;
  ft_putendl("===[A]===");
  ft_print_int_tab(tab_int, size_tab);
  ft_putendl("===[B]===");
//  ft_swap_ab(tab_int);
//  ft_rotate_ab(tab_int, size_tab);
  ft_reverse_rotate_ab(tab_int, size_tab);
  ft_print_int_tab(tab_int, size_tab);
  ft_putchar('\n');
  return (0);
}

int main(int argc, char **argv)
{
    int i;
    int *tab_int;
    int max;
    int len_arg;

    i = 0;
    max = -2147483648;
    len_arg = argc - 1;
    if (argc == 0)
      return (0);
    if (ft_parsing_input(argc, argv) == -1)
      return (-1);
    if (!(tab_int = (int*)malloc(sizeof(tab_int) * (argc - 1))))
      return (-1);
    while (i < len_arg)
    {
      tab_int[i] = ft_atoi(argv[i + 1]);
      max = tab_int[i] > max ? tab_int[i] : max;
      i++;
    }
    ft_printf("sizeof(tab_int) = %d - sizeof(int) = %d --> len = %d - len_arg = %d\n", sizeof(tab_int), sizeof(int), sizeof(tab_int)/sizeof(int), len_arg);
    ft_stack(tab_int, len_arg);
//    tab_int = ft_counting_sort(tab_int, argc - 1, max);
    return (0);
}
