/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:39:08 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:39:09 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	init_textures_util(t_cub *cub)
{
	int	t[3];

	cub->txts->sprite = malloc(sizeof(char *) * 6);
	if (!cub->txts->sprite)
		msg_error(8);
	cub->txts->game_over = mlx_xpm_file_to_image(cub->mlx,
			"game_over.xmp", &t[0], &t[1]);
	cub->txts->sprite[0] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_1.xpm", &t[0], &t[1]);
	cub->txts->sprite[1] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_2.xpm", &t[0], &t[1]);
	cub->txts->sprite[2] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_3.xpm", &t[0], &t[1]);
	cub->txts->sprite[3] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_4.xpm", &t[0], &t[1]);
	cub->txts->sprite[4] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_5.xpm", &t[0], &t[1]);
	cub->txts->sprite[5] = mlx_xpm_file_to_image(cub->mlx,
			"sprite/sprite_6.xpm", &t[0], &t[1]);
	if (!cub->txts->game_over || !cub->txts->sprite[1]
		|| !cub->txts->sprite[2] || !cub->txts->sprite[3]
		|| !cub->txts->sprite[4] || !cub->txts->sprite[5])
		msg_error(8);
}

void	get_data_textures(t_cub *cub, char *str)
{
	int	t[3];

	cub->txts->data_txt_ea = (int *)mlx_get_data_addr(cub->txts->txt_ea,
			&(t[0]), &(t[1]), &(t[2]));
	cub->txts->data_txt_no = (int *)mlx_get_data_addr(cub->txts->txt_no,
			&(t[0]), &(t[1]), &(t[2]));
	cub->txts->data_txt_so = (int *)mlx_get_data_addr(cub->txts->txt_so,
			&(t[0]), &(t[1]), &(t[2]));
	cub->txts->data_txt_we = (int *)mlx_get_data_addr(cub->txts->txt_we,
			&(t[0]), &(t[1]), &(t[2]));
	cub->txts->data_txt_dor = (int *)mlx_get_data_addr(str,
			&(t[0]), &(t[1]), &(t[2]));
	if (!cub->txts->data_txt_ea || !cub->txts->data_txt_no
		|| !cub->txts->data_txt_so || !cub->txts->data_txt_we
		|| !cub->txts->data_txt_dor)
		msg_error(8);
}

void	mini_map_textures(t_cub *cub)
{
	int	t[3];

	cub->txts->blue = mlx_xpm_file_to_image(cub->mlx,
			"minimap_textuers/blue.xpm", &(t[0]), &(t[1]));
	cub->txts->red = mlx_xpm_file_to_image(cub->mlx,
			"minimap_textuers/red.xpm", &(t[0]), &(t[1]));
	cub->txts->teal = mlx_xpm_file_to_image(cub->mlx,
			"minimap_textuers/teal.xpm", &(t[0]), &(t[1]));
	cub->txts->yellow = mlx_xpm_file_to_image(cub->mlx,
			"minimap_textuers/yellow.xpm", &(t[0]), &(t[1]));
	if (!cub->txts->blue || !cub->txts->red
		|| !cub->txts->teal || !cub->txts->yellow)
		msg_error(8);
}

void	init_textures(t_cub *cub)
{
	int		t[3];
	char	*str;

	cub->txts->txt_ea = mlx_xpm_file_to_image(cub->mlx, cub->file_ea, &(t[0]),
			&(t[1]));
	cub->txts->txt_no = mlx_xpm_file_to_image(cub->mlx, cub->file_no, &(t[0]),
			&(t[1]));
	cub->txts->txt_so = mlx_xpm_file_to_image(cub->mlx, cub->file_so, &(t[0]),
			&(t[1]));
	cub->txts->txt_we = mlx_xpm_file_to_image(cub->mlx, cub->file_we, &(t[0]),
			&(t[1]));
	str = mlx_xpm_file_to_image(cub->mlx, "textures/DOOR_1A.xpm",
			&(t[0]), &(t[1]));
	if (!cub->txts->txt_ea || !cub->txts->txt_no
		|| !cub->txts->txt_so || !cub->txts->txt_we || !str)
		msg_error(8);
	get_data_textures(cub, str);
	init_textures_util(cub);
	mini_map_textures(cub);
}
