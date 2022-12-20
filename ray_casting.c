/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:39:43 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 11:32:06 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	directions_playing(double angle, t_cub *cub)
{
	cub->player.lefte = 0;
	cub->player.right = 0;
	cub->player.down = 0;
	cub->player.up = 0;
	if (angle <= 3 * M_PI_2 && angle >= M_PI_2)
		cub->player.lefte = 1;
	else
		cub->player.right = 1;
	if (angle > 0 && angle < M_PI)
		cub->player.down = 1;
	else
		cub->player.up = 1;
}

void	search_for_wall_ver(t_cub *cub, double *stepx, double *stepy)
{
	double	ver_deltx;
	double	ver_delty;
	double	i;
	double	j;

	search_for_first_step_vert(cub, stepx, stepy);
	search_for_delta_step_vert(cub, &ver_deltx, &ver_delty);
	(*stepx) += cub->player.beg_x;
	(*stepy) += cub->player.beg_y;
	wall_ver_util(cub, stepx);
	i = (*stepx);
	j = (*stepy);
	while ((i) > 0 && (i) < cub->win_width && (j) > 0 && (j) < cub->win_height)
	{
		if (cub->map[(int)(j / 64)][(int)(i / 64)] == '1'
			|| (cub->map[((int)(j / 64))][(((int)(i / 64)))] == 'D'))
		{
			cub->if_ver = 1;
			(*stepx) = i;
			(*stepy) = j--;
			break ;
		}
		i += ver_deltx;
		j += ver_delty;
	}
}

void	search_for_wall_hor(t_cub *cub, double *stepx, double *stepy)
{
	double	ver_deltx;
	double	ver_delty;
	double	i;
	double	j;

	search_for_first_step_hor(cub, stepx, stepy);
	search_for_delta_step_hor(cub, &ver_deltx, &ver_delty);
	(*stepx) += cub->player.beg_x;
	(*stepy) += cub->player.beg_y;
	wall_hor_util(cub, stepy);
	i = (*stepx);
	j = (*stepy);
	while (i > 0 && i < cub->win_width && j > 0 && j < cub->win_height)
	{
		if (cub->map[((int)(j / 64))][(((int)(i / 64)))] == '1'
			|| (cub->map[((int)(j / 64))][(((int)(i / 64)))] == 'D'))
		{
			cub->if_hor = 1;
			*stepx = i--;
			*stepy = j;
			break ;
		}
		i += ver_deltx;
		j += ver_delty;
	}
}

void	intersection_ver_or_hor_wall(t_cub *cub, double *wallx, double *wally)
{
	t_var	v;

	cub->player.ry_angle = fix_angle(cub->player.ry_angle);
	search_for_wall_ver(cub, &v.wall_ver_x, &v.wall_ver_y);
	search_for_wall_hor(cub, &v.wall_hor_x, &v.wall_hor_y);
	distance_ver_hor(cub, &v);
	if (v.a < v.b)
	{
		cub->distanc_if_v_or_h = 1;
		*wallx = v.wall_ver_x;
		*wally = v.wall_ver_y;
	}
	else
	{
		cub->distanc_if_v_or_h = 0;
		*wallx = v.wall_hor_x;
		*wally = v.wall_hor_y;
	}
}

int	ray_casting(t_cub *cub)
{
	t_var	v;

	v.i = -1;
	while (++v.i < WINDOW_WIDTH)
	{
		intersection_ver_or_hor_wall(cub, &v.wallx, &v.wally);
		v.raydst = sqrt(pow((cub->player.beg_x - v.wallx), 2)
				+ pow((cub->player.beg_y - v.wally), 2));
		v.distprojplan = (WINDOW_WIDTH / 2) / tan(FOV / 2);
		v.teta = cub->player.ry_angle - cub->player.angle_of_player;
		v.corr_dst = v.raydst * cos(v.teta);
		v.walstrph = (64 / v.corr_dst) * v.distprojplan;
		v.start_y = (WINDOW_HEIGHT / 2) - (v.walstrph / 2);
		if (v.start_y < 0)
			v.start_y = 0;
		v.end_y = (WINDOW_HEIGHT / 2) + (v.walstrph / 2);
		if (v.end_y > WINDOW_HEIGHT)
			v.end_y = WINDOW_HEIGHT;
		drawing_walls(cub, &v);
		cub->player.ry_angle += (60 * (M_PI / 180)) / WINDOW_WIDTH;
	}
	return (0);
}
