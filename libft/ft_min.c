/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vomnes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:24:29 by vomnes            #+#    #+#             */
/*   Updated: 2016/11/08 18:29:20 by vomnes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int x, int y, int z)
{
	if (x < y && x < z)
		return (x);
	else if (y <= x && y < z)
		return (y);
	else
		return (z);
}
