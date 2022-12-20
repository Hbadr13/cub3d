/* ************************************************************************** */
/*									                                        */
/*                                                        :::      ::::::::   */
/*   ray_casting_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:22 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 11:32:24 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

double	fix_angle(double angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	search_for_first_step_vert(t_cub *cub, double *stepx, double *stepy)
{
	directions_playing(cub->player.ry_angle, cub);
	*stepx = (cub->player.beg_x - (int)(cub->player.beg_x / 64) * 64);
	if (cub->player.right == 1)
		*stepx = 64 - *stepx;
	if (cub->player.lefte == 1)
		*stepx *= -1;
	*stepy = *stepx * tan(cub->player.ry_angle);
}

void	search_for_first_step_hor(t_cub *cub, double *stepx, double *stepy)
{
	directions_playing(cub->player.ry_angle, cub);
	*stepy = (cub->player.beg_y - (int)(cub->player.beg_y / 64) * 64);
	if (cub->player.down == 1)
		*stepy = 64 - *stepy;
	if (cub->player.up == 1)
		*stepy *= -1;
	*stepx = *stepy / tan(cub->player.ry_angle);
}

void	search_for_delta_step_vert(t_cub *cub, double *verdltx, double *verdlty)
{
	directions_playing(cub->player.ry_angle, cub);
	(*verdltx) = 64;
	if (cub->player.lefte)
		(*verdltx) *= -1;
	(*verdlty) = (*verdltx) * tan(cub->player.ry_angle);
}

void	search_for_delta_step_hor(t_cub *cub, double *hrdeltx, double *hrdelty)
{
	directions_playing(cub->player.ry_angle, cub);
	(*hrdelty) = 64;
	if (cub->player.up)
		(*hrdelty) *= -1;
	(*hrdeltx) = (*hrdelty) / tan(cub->player.ry_angle);
}
