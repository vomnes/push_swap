# include "push_swap.h"

#define MIN env->spe.min
#define MAX env->spe.max

static int ft_put_elem_tab_hash(char **tab, int value, int pos, int max)
{
  int i;

  i = 0;
  max--;
  while (i < value)
  {
    tab[max - i][pos] = '#';
    i++;
  }
  return (0);
}

static int ft_put_elem_tab_a(char **tab, int value, int pos, int max)
{
  int i;

  i = 0;
  max--;
  while (i < value)
  {
    tab[max - i][pos] = '@';
    i++;
  }
  return (0);
}

static void ft_print_tab(char **tab, int max_x, int max_y)
{
  int x;
  int y;

  x = 0;
  y = 0;
  if (max_x >= 18)
    ft_printf("%4c%s%*s%*c\n"RESET, ' ', UNDERLINE, 18 / 2 + (max_x + 1) / 2, "Push_swap - Visual", (max_x + 1) - (18 /2 + (max_x + 1) / 2), ' ');
  while (y < max_y)
  {
      x = 0;
      ft_printf("%3d|", max_y - y);
      while(x < max_x)
      {
      /*    ft_putnbr(y);
          ft_putchar('-');
          ft_putnbr(x);*/
          if (tab[y][x] == '#')
            ft_putstr(RED"#"RESET);
          else if (tab[y][x] == '@')
            ft_putstr(BLUE"#"RESET);
          else
            ft_putchar(' ');
          x++;
      }
      ft_putchar('\n');
      y++;
  }
  ft_putstr (GOLD" >> "RESET);
}

int ft_visual_in_terminal(t_node *stack_a, t_node *stack_b, t_env *env)
{
  t_node *tmp_a;
  t_node *tmp_b;
  int index;

  tmp_a = stack_a;
  tmp_b = stack_b;
  index = 0;
  ft_putstr(CLEAR);
  while (tmp_a != NULL)
  {
      ft_put_elem_tab_hash(env->spe.tab_visual, tmp_a->data, index, env->spe.max);
      index++;
      tmp_a = tmp_a->next;
  }
  index++;
  while (tmp_b != NULL)
  {
      ft_put_elem_tab_a(env->spe.tab_visual, tmp_b->data, index, env->spe.max);
      index++;
      tmp_b = tmp_b->next;
  }
  ft_print_tab(env->spe.tab_visual, env->spe.len, env->spe.max);
  index = 0;
  while(env->spe.tab_visual[index])
    ft_memset((char*)env->spe.tab_visual[index++], ' ', env->spe.len);
  return (0);
}
