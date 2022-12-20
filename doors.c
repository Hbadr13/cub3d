/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:37:47 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:41:08 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	open_and_close_doors_1(t_cub *cub, int *x, int *y)
{
	*x = cub->player.beg_x / 64;
	*y = cub->player.beg_y / 64 + 1;
	incri(cub, *x, *y);
	if (cub->map[*y][*x] == 'D')
		;
	else if (cub->player.x_d == 1)
		;
	else
	{
		(*y) -= 1;
		(*x) -= 1;
	}
	cub->player.x_d = 0;
}

void	open_and_close_doors_2(t_cub *cub, int *x, int *y)
{
	*x = cub->player.beg_x / 64;
	*y = cub->player.beg_y / 64 - 1;
	incri(cub, *x, *y);
	if (cub->map[*y][*x] == 'D')
		;
	else if (cub->player.x_d == 1)
		;
	else
	{
		(*x) -= 1;
		(*y) += 1;
	}
	cub->player.x_d = 0;
}

void	open_and_close_doors_3(t_cub *cub, int *x, int *y)
{
	*x = cub->player.beg_x / 64 + 1;
	*y = cub->player.beg_y / 64;
	incri(cub, *x, *y);
	if (cub->map[*y][*x] == 'D')
		;
	else if (cub->player.x_d == 1)
		;
	else
	{
		(*y) -= 1;
		(*x) -= 1;
	}
	cub->player.x_d = 0;
}

void	open_and_close_doors_4(t_cub *cub, int *x, int *y)
{
	*x = cub->player.beg_x / 64;
	*y = cub->player.beg_y / 64 + 1;
	incri(cub, *x, *y);
	if (cub->map[*y][*x] == 'D')
		;
	else if (cub->player.x_d == 1)
		;
	else
	{
		(*y) -= 1;
		(*x) += 1;
	}
	cub->player.x_d = 0;
}

void	open_and_close_doors(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	cub->player.x_d = 0;
	cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
	if (cub->player.angle_of_player < M_PI
		&& cub->player.angle_of_player > M_PI_2)
		open_and_close_doors_1(cub, &x, &y);
	if (cub->player.angle_of_player > M_PI
		&& cub->player.angle_of_player < 1.5 * M_PI)
		open_and_close_doors_2(cub, &x, &y);
	if (cub->player.angle_of_player > 1.5 * M_PI)
		open_and_close_doors_3(cub, &x, &y);
	if (cub->player.angle_of_player > 0 && cub->player.angle_of_player < M_PI_2)
		open_and_close_doors_4(cub, &x, &y);
	up_to_fault(cub, x, y, i);
}
