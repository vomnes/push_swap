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

#define MIN env->spe.min
#define MAX env->spe.max

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
	width = 2000 / len;
	x1 = width;
  while (tmp_a != NULL)
  {
		length = tmp_a->data * (1000 / MAX) - MIN;
    ft_printf(">> data :: %d | width :: %d || length :: %D\n", tmp_a->data, width, length);
		ft_printf("x0 >> %d | y0 >> %d | x1 >> %d | y1 >> %d\n", x0, 1010 - length, x1, 1000);
		ft_draw_rectangle(0, 600, 166, 1000, env->img.mlx_data, env->img.size_line, COLOR_GOLD);
    ft_draw_rectangle(x0, 1010 - length, x1, 1010, env->img.mlx_data, \
    env->img.size_line, COLOR_GOLD);
		sleep(1);
    x0 = x0 + width;
    x1 = x1 + width;
    tmp_a = tmp_a->next;
  }
	mlx_clear_window(env->img.mlx, env->img.win);
	mlx_put_image_to_window(env->img.mlx, env->img.win, env->img.img, 0, 0);
	mlx_destroy_image(env->img.mlx, env->img.img);
  return (0);
}
