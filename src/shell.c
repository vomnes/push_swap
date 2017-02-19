# include "push_swap.h"

void ft_shell_print(char *command, t_node *stack_a, t_node *stack_b)
{
  if (ft_strcmp(command, "print") == 0)
  {
    ft_putendl("===[A]===");
    ft_lst_display(stack_a);
    ft_putendl("===[B]===");
    ft_lst_display(stack_b);
    ft_putstr(" >> ");
  }
}

void ft_shell_help_one(char *command)
{
  if (ft_strcmp(command, "help") == 0)
  {
    ft_putstr("============================[Help");
    ft_putendl("]============================");
    ft_putstr("sa  : Swap a - swap the first 2 elements at the top of");
    ft_putendl(" stack a.");
    ft_putendl("      Do nothing if there is only one or no elements).");
    ft_putstr("sb  : Swap b - swap the first 2 elements at the top of");
    ft_putendl(" stack b.");
    ft_putendl("      Do nothing if there is only one or no elements).");
    ft_putendl("ss  : sa and sb at the same time.\n");
    ft_putstr("pa  : Push a - take the first element at the top of b and");
    ft_putendl(" put it");
    ft_putendl("      at the top of a. Do nothing if b is empty.");
    ft_putstr("pb  : Push b - take the first element at the top of a and");
    ft_putendl(" put it");
    ft_putendl("      at the top of b. Do nothing if a is empty.\n");
  }
}

void ft_shell_help_two(char *command)
{
  if (ft_strcmp(command, "help") == 0)
  {
    ft_putstr("ra  : Rotate a - shift up all elements of stack a by 1.");
    ft_putendl(" The first");
    ft_putendl("      element becomes the last one.");
    ft_putstr("rb  : Rotate b - shift up all elements of stack b by 1.");
    ft_putendl("The first");
    ft_putendl("      element becomes the last one.");
    ft_putendl("rr  : Ra and rb at the same time.\n");
    ft_putstr("rra : Reverse rotate a - shift down all elements of stack");
    ft_putendl("a by 1.");
    ft_putendl("     The last element becomes the first one.");
    ft_putstr("rrb : Reverse rotate b - shift down all elements of stack");
    ft_putendl("b by 1.");
    ft_putendl("     The last element becomes the first one.");
    ft_putendl("rrr : rra and rrb at the same time.");
    ft_putstr("=================================");
    ft_putendl("=============================");
    ft_putstr(" >> ");
  }
}

void ft_shell_command(char *command, t_node **stack_a, t_node **stack_b)
{
  if (ft_strcmp(command, "sa") == 0 || ft_strcmp(command, "swap a") == 0)
    ft_swap_one_two(stack_a);
  if (ft_strcmp(command, "sb") == 0 || ft_strcmp(command, "swap b") == 0)
    ft_swap_one_two(stack_a);
  if (ft_strcmp(command, "ss") == 0)
  {
    ft_swap_one_two(stack_a);
    ft_swap_one_two(stack_b);
  }
  if (ft_strcmp(command, "pa") == 0 || ft_strcmp(command, "push a") == 0)
    ft_push_ab(stack_b, stack_a);
  if (ft_strcmp(command, "pb") == 0 || ft_strcmp(command, "push b") == 0)
    ft_push_ab(stack_a, stack_b);
  if (ft_strcmp(command, "ra") == 0 || ft_strcmp(command, "rotate a") == 0)
    ft_rotate(stack_a);
  if (ft_strcmp(command, "rb") == 0 || ft_strcmp(command, "rotate b") == 0)
    ft_rotate(stack_b);
  if (ft_strcmp(command, "rr") == 0)
  {
    ft_rotate(stack_a);
    ft_rotate(stack_b);
  }
}

void ft_shell_command_two(char *command, t_node **stack_a, t_node **stack_b)
{
  if (ft_strcmp(command, "rra") == 0 ||
  ft_strcmp(command, "reverse rotate a") == 0)
    ft_reverse_rotate(stack_a);
  else if (ft_strcmp(command, "rrb") == 0 ||
  ft_strcmp(command, "reverse rotate b") == 0)
    ft_reverse_rotate(stack_b);
  else if (ft_strcmp(command, "rrr") == 0)
  {
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
  }
}

void ft_shell(t_node *stack_a, t_node *stack_b)
{
  char *command;

  ft_putendl("Push_Swap Shell");
  ft_putstr("Command : help - print - sa sb ss pa ");
  ft_putendl("pb ra rb rr rra rrb rrr - exit");
  ft_putstr(" >> ");
  while (get_next_line(0, &command) > 0)
  {
      ft_shell_print(command, stack_a, stack_b);
      ft_shell_help_one(command);
      ft_shell_help_two(command);
      ft_shell_command(command, &stack_a, &stack_b);
      ft_shell_command_two(command, &stack_a, &stack_b);
      if (ft_strcmp(command, "exit") == 0)
        break ;
  }
}
