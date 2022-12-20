/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_util_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:06:02 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 14:06:03 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	distance_ver_hor(t_cub *cub, t_var *v)
{
	if (cub->if_ver)
		v->a = sqrt(pow((cub->player.beg_x - v->wall_ver_x), 2)
				+ pow((cub->player.beg_y - v->wall_ver_y), 2));
	else
		v->a = MAX_INT;
	if (cub->if_hor)
		v->b = sqrt(pow(cub->player.beg_x - v->wall_hor_x, 2)
				+ pow(cub->player.beg_y - v->wall_hor_y, 2));
	else
		v->b = MAX_INT;
}

void	wall_ver_util(t_cub *cub, double *stepx)
{
	cub->if_ver = 0;
	if (cub->player.lefte)
		(*stepx)--;
}

void	wall_hor_util(t_cub *cub, double *j)
{
	cub->if_hor = 0;
	if (cub->player.up == 1)
		(*j)--;
}
