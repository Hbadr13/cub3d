/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:39:24 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:39:31 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	draw_space(t_cub *cub, char c, int y, int x)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		mlx_put_image_to_window(cub->mlx, cub->window,
			cub->txts->yellow, y, x);
}

void	draw_mini_map(t_cub *cub, int a, int b)
{
	int	i;
	int	j;

	i = (cub->player.beg_y / 64) - 2;
	if (i < 0)
		i = 0;
	while (cub->map[i] && i < (cub->player.beg_y / 64) + 2)
	{
		j = (cub->player.beg_x / 64) - 2;
		if (j < 0)
			j = 0;
		while (cub->map[i][j] && j < (cub->player.beg_x / 64) + 2)
		{
			if (cub->map[i][j] == '1')
				mlx_put_image_to_window(cub->mlx, cub->window,
					cub->txts->red, (j * 64 - a), (i * 64 - b));
			if (cub->map[i][j] == 'D')
				mlx_put_image_to_window(cub->mlx, cub->window,
					cub->txts->teal, (j * 64 - a), (i * 64 - b));
			draw_space(cub, cub->map[i][j], (j * 64 - a), (i * 64 - b));
			j++;
		}
		i++;
	}
}

void	mini_map(t_cub *cub)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (cub->player.beg_x > 100)
		a = cub->player.beg_x - 100;
	else if (cub->player.beg_x <= 100)
		a = 100 - cub->player.beg_x;
	if (cub->player.beg_y > 100)
		b = cub->player.beg_y - 100;
	else if (cub->player.beg_y <= 100)
		b = 100 - cub->player.beg_y;
	draw_mini_map(cub, a, b);
	mlx_put_image_to_window(cub->mlx, cub->window,
		cub->txts->blue, (cub->player.beg_x - 10) - a,
		(cub->player.beg_y - 10) - b);
}
