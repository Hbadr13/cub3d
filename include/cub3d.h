/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:25:31 by hbadr             #+#    #+#             */
/*   Updated: 2022/11/24 17:25:32 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <limits.h>

# define FOV 1.0472
# define UP_W 13
# define DOWN_S 1
# define UP_A 0
# define UP_D 2
# define LEFT 123
# define RIGHT 124
# define MOVE 6
# define ESC 53
# define MAX_INT 2147483647
# define ROTAIONA_SPEED 0.0698132
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600

typedef struct t_var
{
	double	wall_ver_x;
	double	wall_ver_y;
	double	wall_hor_x;
	double	wall_hor_y;
	double	a;
	double	b;
	int		i;
	int		j;
	int		k;
	int		len;
	int		x;
	int		y;
	char	*str;
	char	*dst;
	char	**tab;
	double	distprojplan;
	double	teta;
	double	corr_dst;
	double	raydst;
	int		walstrph;
	int		start_y;
	int		end_y;
	double	wallx;
	double	wally;
}	t_var;

typedef struct s_color
{
	int		_r;
	int		_g;
	int		_b;
}	t_color;

typedef struct s_player
{
	int		lefte;
	int		right;
	int		up;
	int		down;
	int		beg_x;
	int		beg_y;
	int		end_x;
	int		end_y;
	double	angle_of_player;
	int		walkdirection;
	int		walk_side_direction;
	double	ry_angle;
	int		x_d;
	double	rotation_angle;
}	t_player;

typedef struct s_textures
{
	void	*txt_so;
	void	*txt_no;
	void	*txt_we;
	void	*txt_ea;
	void	**sprite;
	void	*game_over;
	void	*blue;
	void	*red;
	void	*teal;
	void	*yellow;
	int		*data_txt_so;
	int		*data_txt_no;
	int		*data_txt_we;
	int		*data_txt_dor;
	int		*data_txt_ea;
}	t_textures;

typedef struct s_cub3d
{
	char		**map;
	int			*xx_d;
	int			*yy_d;
	int			k;
	int			size_d;
	char		**lines;
	char		*file_so;
	char		*file_no;
	char		*file_we;
	char		*file_ea;
	char		*before_map;
	int			size1;
	int			size2;
	t_color		*rgb_f;
	t_color		*rgb_c;
	t_player	player;
	char		*mlx;
	int			win_height;
	int			win_width;
	char		*window;
	double		move_hor;
	double		move_vert;
	int			if_hor;
	int			if_ver;
	int			distanc_if_v_or_h;
	void		*image;
	int			*data_image;
	t_textures	*txts;
	int			flag_wpn;
	int			flag_over;
	int			index;
	int			index_g_ov;
}	t_cub;

int		main(int argc, char **argv);
void	check_map_valid(t_cub *cub, char *path);
int		ft_strcmp(char *s1, char *s2);
void	msg_error(int status);
int		size_map(char *path);
void	free_tab(char **tab);
int		handling_texture(t_cub *cub, int i, int j);
void	search_color(t_cub *cub, char *str, int *j, int index);
void	handling_color(t_cub *cub, char *des, int index, int i);
void	check_color(t_var var);
int		len_tab(char **tab, int index);
int		handling_texture(t_cub *cub, int i, int j);
void	handling_texture_2(char **str, int *j, t_cub *cub, int i);
void	check_may_map(char **map, int i, int j, int k);
int		if_player(char c);
void	position_of_player(t_cub *cub);
int		haswallat(double x, double y, t_cub *cub);
void	width_and_height_window(t_cub *cub);
void	up_to_fault(t_cub *cub, int x, int y, int i);
void	init_textures(t_cub *cub);
int		press_start(t_cub *cub);
void	ft_init_mlx(t_cub *cub);
t_cub	*int_cub(void);
int		handling_keys(int key, t_cub *cub);
int		ray_casting(t_cub *cub);
double	fix_angle(double angle);
void	mini_map(t_cub *cub);
void	drawing_floors_and_ceilings(t_cub *cub);
void	open_and_close_doors(t_cub *cub);
int		game_over(t_cub *cont);
void	drawing_walls(t_cub *cub, t_var *v);
void	search_for_first_step_vert(t_cub *cub, double *stepx, double *stepy);
void	search_for_first_step_hor(t_cub *cub, double *stepx, double *stepy);
void	search_for_delta_step_hor(t_cub *cub,
			double *hor_deltx, double *hor_delty);
void	search_for_delta_step_vert(t_cub *cub,
			double *ver_deltx, double *ver_delty);
void	directions_playing(double angle, t_cub *cub);
void	incri(t_cub *cub, int x, int y);
void	up_to_fault(t_cub *cub, int x, int y, int i);
int		check_arry(int *b, int x, t_cub *cub);
void	wall_hor_util(t_cub *cub, double *j);
void	wall_ver_util(t_cub *cub, double *stepx);
void	distance_ver_hor(t_cub *cub, t_var *v);
int		check_all(double x, double y, t_cub *cub);
#endif
