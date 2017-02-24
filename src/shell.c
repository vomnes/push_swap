/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:09:25 by vomnes            #+#    #+#             */
/*   Updated: 2017/02/19 18:09:26 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

# define IS_IN(x) ft_strcmp(command, x) != 0

int	ft_lst_length(t_node *list)
{
	t_node *temp;
  int count;

	temp = list;
  count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
    count++;
	}
  return (count);
}

void ft_print_stacks(t_node *stack_a, t_node *stack_b)
{
	t_node *temp_a;
	t_node *temp_b;
	int len_a;
	int len_b;

	temp_a = stack_a;
	temp_b = stack_b;
	len_a = ft_lst_length(stack_a);
	len_b = ft_lst_length(stack_b);
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

void ft_shell_print(char *command, t_node *stack_a, t_node *stack_b)
{
  if (ft_strcmp(command, "print") == 0)
  {
		ft_print_stacks(stack_a, stack_b);
  }
}

void ft_shell_help_one(char *command)
{
  if (ft_strcmp(command, "help") == 0)
  {
    ft_putstr("==============================[Help");
    ft_putendl("]==============================");
		ft_putendl("print : Print stack a and stack b\n");
    ft_putstr("sa    : Swap a - swap the first 2 elements at the top of");
    ft_putendl(" stack a.");
    ft_putendl("        Do nothing if there is only one or no elements).");
    ft_putstr("sb    : Swap b - swap the first 2 elements at the top of");
    ft_putendl(" stack b.");
    ft_putendl("        Do nothing if there is only one or no elements).");
    ft_putendl("ss    : sa and sb at the same time.\n");
    ft_putstr("pa    : Push a - take the first element at the top of b and");
    ft_putendl(" put it");
    ft_putendl("        at the top of a. Do nothing if b is empty.");
    ft_putstr("pb    : Push b - take the first element at the top of a and");
    ft_putendl(" put it");
    ft_putendl("        at the top of b. Do nothing if a is empty.\n");
  }
}

void ft_shell_help_two(char *command)
{
  if (ft_strcmp(command, "help") == 0)
  {
    ft_putstr("ra    : Rotate a - shift up all elements of stack a by 1.");
    ft_putendl(" The first");
    ft_putendl("        element becomes the last one.");
    ft_putstr("rb    : Rotate b - shift up all elements of stack b by 1.");
    ft_putendl("The first");
    ft_putendl("        element becomes the last one.");
    ft_putendl("rr    : Ra and rb at the same time.\n");
    ft_putstr("rra   : Reverse rotate a - shift down all elements of stack");
    ft_putendl("a by 1.");
    ft_putendl("        The last element becomes the first one.");
    ft_putstr("rrb   : Reverse rotate b - shift down all elements of stack");
    ft_putendl("b by 1.");
    ft_putendl("        The last element becomes the first one.");
    ft_putendl("rrr   : rra and rrb at the same time.\n");
		ft_putendl("exit  : exit ./checker");
    ft_putstr("==================================");
    ft_putendl("================================");
    ft_putstr(" >> ");
  }
}

void ft_shell_swap_pa(char *command, t_node **stack_a, t_node **stack_b, int *shell_complexity)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		ft_swap_one_two(stack_a);
		(*shell_complexity)++;
		ft_print_stacks(*stack_a, *stack_b);
	}
	if (ft_strcmp(command, "sb") == 0)
	{
		ft_swap_one_two(stack_b);
		(*shell_complexity)++;
		ft_print_stacks(*stack_a, *stack_b);
	}
	if (ft_strcmp(command, "ss") == 0)
	{
		ft_swap_one_two(stack_a);
		ft_swap_one_two(stack_b);
		*shell_complexity += 2;
		ft_print_stacks(*stack_a, *stack_b);
	}
	if (ft_strcmp(command, "pa") == 0)
	{
			ft_push_ab(stack_b, stack_a);
			(*shell_complexity)++;
			ft_print_stacks(*stack_a, *stack_b);
	}
}

void ft_shell_reverse_pb(char *command, t_node **stack_a, t_node **stack_b, int *shell_complexity)
{
  if (ft_strcmp(command, "pb") == 0)
	{
			ft_push_ab(stack_a, stack_b);
			(*shell_complexity)++;
			ft_print_stacks(*stack_a, *stack_b);
	}
  if (ft_strcmp(command, "ra") == 0)
	{
			ft_rotate(stack_a);
			(*shell_complexity)++;
			ft_print_stacks(*stack_a, *stack_b);
	}
  if (ft_strcmp(command, "rb") == 0)
	{
			ft_rotate(stack_b);
			(*shell_complexity)++;
			ft_print_stacks(*stack_a, *stack_b);
	}
  if (ft_strcmp(command, "rr") == 0)
  {
    ft_rotate(stack_a);
    ft_rotate(stack_b);
		*shell_complexity += 2;
		ft_print_stacks(*stack_a, *stack_b);
  }
}

void ft_shell_reverse_rotate(char *command, t_node **stack_a, t_node **stack_b, int *shell_complexity)
{
  if (ft_strcmp(command, "rra") == 0)
	{
		ft_reverse_rotate(stack_a);
		(*shell_complexity)++;
		ft_print_stacks(*stack_a, *stack_b);
	}
  else if (ft_strcmp(command, "rrb") == 0)
	{
		ft_reverse_rotate(stack_b);
		(*shell_complexity)++;
		ft_print_stacks(*stack_a, *stack_b);
	}
  else if (ft_strcmp(command, "rrr") == 0)
  {
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
		*shell_complexity += 2;
		ft_print_stacks(*stack_a, *stack_b);
  }
}

int ft_shell(t_env *env)
{
  char *command;
	int op;

	CLEAN
  ft_putendl("Push_Swap Shell");
  ft_putstr("Command : help - print - sa sb ss pa ");
  ft_putendl("pb ra rb rr rra rrb rrr - exit");
	ft_putendl("-> Stack a and stack b :");
	ft_print_stacks(env->stack_a, env->stack_b);
	op = 0;
	if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
	{
		ft_putstr(LIGHT_GREEN"Already sorted\n"RESET);
		return (1);
	}
  while (get_next_line(0, &command) > 0)
  {
      ft_shell_print(command, env->stack_a, env->stack_b);
      ft_shell_help_one(command);
      ft_shell_help_two(command);
			ft_shell_swap_pa(command, &env->stack_a, &env->stack_b, &op);
      ft_shell_reverse_pb(command, &env->stack_a, &env->stack_b, &op);
      ft_shell_reverse_rotate(command, &env->stack_a, &env->stack_b, &op);
			if (env->stack_a != NULL && ft_lst_is_sorted(env->stack_a) == 1 && env->stack_b == NULL)
			{
				ft_putstr(LIGHT_GREEN"Sorted with "RESET);
				ft_putnbr(op);
				ft_putstr(LIGHT_GREEN" operation(s) !\n"RESET);
				return (1);
			}
      if (ft_strcmp(command, "exit") == 0)
        return (1);
			if (ft_strcmp(command, "clear") == 0)
			{
				CLEAN
				ft_putstr(" >> ");
			}
			if (ft_strcmp(command, "op") == 0)
			{
				ft_putstr(LIGHT_GREEN"Number of operations : "RESET);
				ft_putnbr(op);
				ft_putchar('\n');
				ft_putstr(" >> ");
			}
			if (IS_IN("help") && IS_IN("print") && IS_IN("sa") && IS_IN("sb") &&
			IS_IN("ss") && IS_IN("pa") && IS_IN("pb") && IS_IN("ra") && IS_IN("rb") &&
			IS_IN("rr") && IS_IN("rra") && IS_IN("rrb") && IS_IN("rrr") &&
			IS_IN("exit") && IS_IN("op") && IS_IN("clear"))
			{
				ft_putstr(RED"Unknown Command "RESET);
				ft_putendl(": Try help");
				ft_putstr(" >> ");
			}
  }
	return (0);
}
