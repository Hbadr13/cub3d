/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:39:37 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:39:39 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	haswallat(double x, double y, t_cub *cub)
{
	if (x < 0 || x > cub->win_width || y < 0 || y > cub->win_height)
		return (1);
	if (cub->map[(int)y / 64][(int)x / 64] != '1')
	{
		if (check_all(x, y, cub))
			return (1);
		return (0);
	}
	return (1);
}

void	move_player(t_cub *cub,	double stepx, double stepy)
{
	cub->player.angle_of_player += cub->player.rotation_angle;
	if (cub->player.walkdirection)
	{
		stepx = round(cos(cub->player.angle_of_player)
				* cub->player.walkdirection);
		stepy = round(sin(cub->player.angle_of_player)
				* cub->player.walkdirection);
	}
	if (cub->player.walk_side_direction)
	{
		stepx = round(cos(cub->player.angle_of_player - M_PI_2)
				* cub->player.walk_side_direction);
		stepy = round(sin(cub->player.angle_of_player - M_PI_2)
				* cub->player.walk_side_direction);
	}
	stepx += cub->player.beg_x;
	stepy += cub->player.beg_y;
	cub->player.angle_of_player = fix_angle(cub->player.angle_of_player);
	if (!haswallat(stepx, stepy, cub))
	{
		cub->player.beg_x = stepx;
		cub->player.beg_y = stepy;
	}
}

int	press_start(t_cub *cub)
{
	int	arr[3];

	if (cub->flag_over == 0)
	{
		game_over(cub);
		return (0);
	}
	move_player(cub, 0, 0);
	mlx_clear_window(cub->mlx, cub->window);
	cub->player.ry_angle = cub->player.angle_of_player - 30 * (M_PI / 180);
	cub->image = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->data_image = (int *)mlx_get_data_addr(cub->image,
			&arr[0], &arr[1], &arr[2]);
	drawing_floors_and_ceilings(cub);
	ray_casting(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	mini_map(cub);
	mlx_destroy_image(cub->mlx, cub->image);
	return (0);
}
