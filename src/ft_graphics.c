/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:36:09 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/02 12:36:21 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	ft_mem_pixel_img(char *mlx_data, int size_line, unsigned int x, \
unsigned int y, int color)
{
	unsigned int *index;
	unsigned int y_line;

	index = (unsigned int*)mlx_data;
	y_line = y * size_line / 4;
	*(index + y_line + x) = color;
}

int ft_draw_rectangle(int x1, int y1, int x2, int y2, char *mlx_data, \
int size_line, int color)
{
    int x;
    int y;

    x = x1;
    y = y1;
    while (y < y2)
    {
      x = x1;
      while (x < x2)
      {
				if (y == y1 || y == y2 || x == x1 || x == x2)
					   ft_mem_pixel_img(mlx_data, size_line, x, y, 0x001A535C);
				else
        	   ft_mem_pixel_img(mlx_data, size_line, x, y, color);
        x++;
      }
      y++;
    }
    return (0);
}

int ft_graphics(t_node *stack_a, t_node *stack_b, t_env *env)
{
  int color;
	int y;
  int x;
  t_node *tmp_a;
  t_node *tmp_b;
  int len;
  int width;
  int length;
  int x0;
  int x1;

	env->img.img = mlx_new_image(env->img.mlx, 2010, 1020);
	env->img.mlx_data = mlx_get_data_addr(env->img.img,
	&env->img.bits_per_pixel, &env->img.size_line, &env->img.endian);
	y = 0;
	x = 0;
	color = 0;
  tmp_a = stack_a;
  tmp_b = stack_b;
  len = env->spe.len;
  x0 = 0;
  x1 = 0;
  while (tmp_a != NULL)
  {
    width = 2000 / len;
    length = 1000 - (1000 / tmp_a->data) + (1000 / 10);
    ft_printf(">> data :: %d | width :: %d || length :: %D\n", tmp_a->data, width, length);
    ft_draw_rectangle(x0, 1000 - length, x1, 1000, env->img.mlx_data, \
    env->img.size_line, COLOR_GOLD);
    x0 += width;
    x1 += width;
    tmp_a = tmp_a->next;
  }
	mlx_clear_window(env->img.mlx, env->img.win); // Expose hook ??
	mlx_put_image_to_window(env->img.mlx, env->img.win, env->img.img, 0, 0);
	mlx_destroy_image(env->img.mlx, env->img.img);
  return (0);
}
