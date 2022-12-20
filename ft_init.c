/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:38:29 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:38:31 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

t_cub	*int_cub(void)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	cub->rgb_c = ft_calloc(sizeof(t_color), 1);
	cub->rgb_f = ft_calloc(sizeof(t_color), 1);
	cub->txts = ft_calloc(sizeof(t_textures), 1);
	cub->xx_d = ft_calloc(sizeof(int), cub->size_d + 1);
	cub->yy_d = ft_calloc(sizeof(int), cub->size_d + 1);
	return (cub);
}

void	ft_init_mlx(t_cub *cub)
{
	cub->index = 0;
	cub->flag_wpn = 0;
	cub->flag_over = 0;
	cub->index_g_ov = 0;
	cub->k = 0;
	width_and_height_window(cub);
	position_of_player(cub);
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
}
