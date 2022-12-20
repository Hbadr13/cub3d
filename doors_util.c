/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:37:56 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:37:58 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	check_arry(int *b, int x, t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->k)
	{
		if (b[i] == x)
			return (0);
		i++;
	}
	return (1);
}

void	up_to_fault(t_cub *cub, int x, int y, int i)
{
	if (cub->map[y][x] == 'D')
	{
		cub->map[y][x] = '0';
		if (check_arry(cub->xx_d, x, cub) || check_arry(cub->yy_d, y, cub))
		{
			cub->xx_d[cub->k] = x;
			cub->yy_d[cub->k] = y;
			cub->k++;
		}
	}
	else if (cub->map[y][x] == '0')
	{
		i = -1;
		while (++i < cub->k)
		{
			if (cub->map[cub->yy_d[i]][cub->xx_d[i]] == '0')
			{
				if (x == cub->xx_d[i] && y == cub->yy_d[i])
				{
					cub->map[cub->yy_d[i]][cub->xx_d[i]] = 'D';
					break ;
				}
			}
		}
	}
}

void	incri(t_cub *cub, int x, int y)
{
	int	i;

	i = 0;
	while (i <= cub->k)
	{
		if (cub->yy_d[i] == y && cub->xx_d[i] == x)
			cub->player.x_d = 1;
		i++;
	}
}
