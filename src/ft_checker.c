/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:12:32 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/28 20:12:33 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

# define IS_IN(x) ft_strcmp(command, x) != 0

void ft_checker_print_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node *temp_a;
	t_node *temp_b;
	int len_a;
	int len_b;

	temp_a = stack_a;
	temp_b = stack_b;
	len_a = ft_lst_len(stack_a);
	len_b = ft_lst_len(stack_b);
	while (len_a > 0 || len_b > 0)
	{
		if (len_a == len_b)
		{
			ft_printf("%5d       %5d    \n", temp_a->data, temp_b->data);
			len_a--;
			len_b--;
			temp_a = temp_a->next;
			temp_b = temp_b->next;
		}
		else if (len_a > len_b)
		{
				ft_printf("%5d\n", temp_a->data);
				temp_a = temp_a->next;
				len_a--;
		}
		else if (len_a < len_b)
		{
				ft_printf("            %5d    \n", temp_b->data);
				temp_b = temp_b->next;
				len_b--;
		}
	}
	ft_putstr("===[");
	ft_putstr(GOLD"A"RESET);
	ft_putstr("]===   ===[");
	ft_putstr(GOLD"B"RESET);
	ft_putstr("]===\n");
	ft_putstr(" >> ");
}

void ft_checker_swap_pa(char *command, t_node **stack_a, t_node **stack_b,
int *shell_complexity)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		ft_swap_one_two(stack_a);
		(*shell_complexity)++;
	}
	if (ft_strcmp(command, "sb") == 0)
	{
		ft_swap_one_two(stack_b);
		(*shell_complexity)++;
	}
	if (ft_strcmp(command, "ss") == 0)
	{
		ft_swap_one_two(stack_a);
		ft_swap_one_two(stack_b);
		*shell_complexity += 2;
	}
	if (ft_strcmp(command, "pa") == 0)
	{
			ft_push_ab(stack_b, stack_a);
			(*shell_complexity)++;
	}
}

void ft_checker_reverse_pb(char *command, t_node **stack_a, t_node **stack_b,
	int *shell_complexity)
{
  if (ft_strcmp(command, "pb") == 0)
	{
			ft_push_ab(stack_a, stack_b);
			(*shell_complexity)++;
	}
  if (ft_strcmp(command, "ra") == 0)
	{
			ft_rotate(stack_a);
			(*shell_complexity)++;
	}
  if (ft_strcmp(command, "rb") == 0)
	{
			ft_rotate(stack_b);
			(*shell_complexity)++;
	}
  if (ft_strcmp(command, "rr") == 0)
  {
    ft_rotate(stack_a);
    ft_rotate(stack_b);
		*shell_complexity += 2;
  }
}

void ft_checker_reverse_rotate(char *command, t_node **stack_a,
	t_node **stack_b, int *shell_complexity)
{
  if (ft_strcmp(command, "rra") == 0)
	{
		ft_reverse_rotate(stack_a);
		(*shell_complexity)++;
	}
  else if (ft_strcmp(command, "rrb") == 0)
	{
		ft_reverse_rotate(stack_b);
		(*shell_complexity)++;
	}
  else if (ft_strcmp(command, "rrr") == 0)
  {
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
		*shell_complexity += 2;
  }
}

int ft_checker(t_env *env)
{
  char *command;
	int op;

	op = 0;
	if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 &&
	env->stack_b == NULL)
	{
		ft_putstr(LIGHT_GREEN"OK\n"RESET);
		return (1);
	}
  while (get_next_line(0, &command) > 0)
  {
			ft_checker_swap_pa(command, &env->stack_a, &env->stack_b, &op);
      ft_checker_reverse_pb(command, &env->stack_a, &env->stack_b, &op);
      ft_checker_reverse_rotate(command, &env->stack_a, &env->stack_b, &op);
			if (IS_IN("sa") && IS_IN("sb") && IS_IN("ss") && IS_IN("pa") &&
      IS_IN("pb") && IS_IN("ra") && IS_IN("rb") && IS_IN("rr") &&
      IS_IN("rra") && IS_IN("rrb") && IS_IN("rrr"))
			{
				ft_putendl(RED"Error"RESET);
        return (1);
			}
  }
	if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 &&
	env->stack_b == NULL)
	{
		ft_putstr(LIGHT_GREEN"OK - Sorted with "RESET);
		ft_putnbr(op);
		ft_putstr(LIGHT_GREEN" operation(s) !\n"RESET);
		return (1);
	}
	else
		ft_putstr(RED"KO - Not sorted\n"RESET);
	return (0);
}
