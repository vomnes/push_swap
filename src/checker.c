/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:20:52 by vomnes            #+#    #+#             */
/*   Updated: 2017/03/01 11:53:57 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_env	env;
	int		len_arg;
  short flag;
  char *input;

	len_arg = argc - 1;
	i = len_arg;
  flag = 0;
	if (argc == 1)
		return (0);
  if (ft_strcmp(argv[1], "-s") == 0 || ft_strcmp(argv[1], "-shell") == 0)
      flag = 1;
	if (ft_parsing_input(argc, argv, flag) == -1)
		return (-1);
	env.stack_a = NULL;
	env.stack_b = NULL;
	(void)input;
  /*if (get_next_line(0, &input) > 0)
	{
		if (ft_strcmp(input, "Print push_swap : [on]") == 0)
			return (0);
	}*/
	while (i > flag)
	{
		if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i]))))
			return (-1);
		i--;
	}
  if (flag == 1)
      ft_shell(&env);
  else
      ft_checker(&env);
	return (0);
}
