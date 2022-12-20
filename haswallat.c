/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haswallat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:09:37 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/10/26 13:10:08 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	check_wall_1(double x, double y, t_cub *cub)
{
	int	index_x;
	int	index_y;

	index_x = x / 64;
	if (cub->player.walkdirection < 0)
		index_y = (y - 10) / 64;
	else
		index_y = (y + 10) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	if (cub->player.walkdirection < 0)
		index_x = (x + 10) / 64;
	else
		index_x = (x - 10) / 64;
	index_y = (y) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	return (0);
}

int	check_wall_2(double x, double y, t_cub *cub)
{
	int	index_x;
	int	index_y;

	index_x = x / 64;
	if (cub->player.walkdirection < 0)
		index_y = (y + 10) / 64;
	else
		index_y = (y - 10) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	if (cub->player.walkdirection < 0)
		index_x = (x + 10) / 64;
	else
		index_x = (x - 10) / 64;
	index_y = (y) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	return (0);
}

int	check_wall_3(double x, double y, t_cub *cub)
{
	int	index_x;
	int	index_y;

	if (cub->player.walkdirection < 0)
		index_x = (x - 10) / 64;
	else
		index_x = (x + 10) / 64;
	index_y = (y) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	index_x = (x) / 64;
	if (cub->player.walkdirection < 0)
		index_y = (y + 10) / 64;
	else
		index_y = (y - 10) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	return (0);
}

int	check_wall_4(double x, double y, t_cub *cub)
{
	int	index_x;
	int	index_y;

	index_x = (x) / 64;
	if (cub->player.walkdirection < 0)
		index_y = (y - 10) / 64;
	else
		index_y = (y + 10) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	if (cub->player.walkdirection < 0)
		index_x = (x - 10) / 64;
	else
		index_x = (x + 10) / 64;
	index_y = (y) / 64;
	if (cub->map[index_y][index_x] == '1')
		return (1);
	return (0);
}

int	check_all(double x, double y, t_cub *cub)
{
	if (cub->map[(int)y / 64][(int)x / 64] == 'D')
		return (1);
	if (cub->player.angle_of_player < M_PI
		&& cub->player.angle_of_player >= M_PI_2)
	{
		if (check_wall_1(x, y, cub))
			return (1);
	}
	else if (cub->player.angle_of_player > M_PI
		&& cub->player.angle_of_player <= 1.5 * M_PI)
	{
		if (check_wall_2(x, y, cub))
			return (1);
	}
	else if (cub->player.angle_of_player > 1.5 * M_PI)
	{
		if (check_wall_3(x, y, cub))
			return (1);
	}
	else if (cub->player.angle_of_player >= 0
		&& cub->player.angle_of_player < M_PI_2)
		if (check_wall_4(x, y, cub))
			return (1);
	return (0);
}
