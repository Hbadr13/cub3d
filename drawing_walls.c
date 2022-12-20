/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:38:10 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:38:22 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	drawing_walls_util(t_cub *cub, int *color, int txtr_ofsx, int txtr_ofsy)
{
	if (cub->distanc_if_v_or_h)
	{
		if (cub->player.right)
			*color = cub->txts->data_txt_ea[(64 * txtr_ofsy) + txtr_ofsx];
		else
			*color = cub->txts->data_txt_we[(64 * txtr_ofsy) + txtr_ofsx];
	}
	else
	{
		if (cub->player.up)
			*color = cub->txts->data_txt_no[(64 * txtr_ofsy) + txtr_ofsx];
		else
			*color = cub->txts->data_txt_so[(64 * txtr_ofsy) + txtr_ofsx];
	}
}

void	drawing_walls(t_cub *cub, t_var *v)
{
	int	y;
	int	textur_ofs_x;
	int	textur_ofs_y;
	int	color;
	int	distancfromtop;

	if (cub->distanc_if_v_or_h)
		textur_ofs_x = (int)v->wally % 64;
	else
		textur_ofs_x = (int)v->wallx % 64;
	y = v->start_y;
	while (y < v->end_y)
	{
		distancfromtop = y + (v->walstrph / 2) - (WINDOW_HEIGHT / 2);
		textur_ofs_y = distancfromtop * ((double)64 / v->walstrph);
		if (cub->map[((int)(v->wally / 64))][(((int)(v->wallx / 64)))] == 'D')
			color = cub->txts->data_txt_dor[(64 * textur_ofs_y) + textur_ofs_x];
		else
			drawing_walls_util(cub, &color, textur_ofs_x, textur_ofs_y);
		cub->data_image[(WINDOW_WIDTH * y) + v->i] = color;
		y++;
	}
}
