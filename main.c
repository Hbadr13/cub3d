/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:39:17 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 09:39:19 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	move_t(int key, t_cub *cub)
{
	if (key == UP_W)
		cub->player.walkdirection = 0;
	if (key == DOWN_S)
		cub->player.walkdirection = 0;
	if (key == UP_A)
		cub->player.walk_side_direction = 0;
	if (key == UP_D)
		cub->player.walk_side_direction = 0;
	if (key == RIGHT)
		cub->player.rotation_angle = 0;
	if (key == LEFT)
		cub->player.rotation_angle = 0;
	return (0);
}

int	ft_exit(t_cub *cub)
{
	ft_putstr_fd("you are out of the game\n", 2);
	mlx_destroy_image(cub->mlx, cub->window);
	exit(0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	static int	view;

	(void)y;
	if (x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		if (view > x)
			cub->player.angle_of_player += ROTAIONA_SPEED;
		else
			cub->player.angle_of_player -= ROTAIONA_SPEED;
	}
	view = x;
	return (0);
}

int	main(int agrc, char **argv)
{
	t_cub	*cub;

	if (agrc != 2)
		return (1);
	cub = int_cub();
	check_map_valid(cub, argv[1]);
	ft_init_mlx(cub);
	init_textures(cub);
	mlx_hook(cub->window, 17, 1L << 2, ft_exit, cub);
	mlx_hook(cub->window, 6, 1L << 0, mouse_move, cub);
	mlx_hook(cub->window, 2, 0, handling_keys, cub);
	mlx_loop_hook(cub->mlx, press_start, cub);
	mlx_hook(cub->window, 3, 1L << 1, move_t, cub);
	mlx_loop(cub->mlx);
	free_tab(cub->lines);
	return (0);
}
