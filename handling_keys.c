/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   handling_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:38:49 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:38:51 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	handling_keys(int key, t_cub *cub)
{
	cub->flag_over = 1;
	if (key == ESC)
		exit(ESC);
	if (key == 125)
		cub->index++;
	if (key == 126)
		cub->index--;
	if (key == 49)
		open_and_close_doors(cub);
	if (key == UP_W)
		cub->player.walkdirection = MOVE;
	if (key == DOWN_S)
		cub->player.walkdirection = -MOVE;
	if (key == UP_A)
		cub->player.walk_side_direction = MOVE;
	if (key == UP_D)
		cub->player.walk_side_direction = -MOVE;
	if (key == RIGHT)
		cub->player.rotation_angle = ROTAIONA_SPEED;
	if (key == LEFT)
		cub->player.rotation_angle = -ROTAIONA_SPEED;
	return (0);
}
