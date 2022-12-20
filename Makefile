NAME	=	cub3d
SRC		=	main.c \
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c \
			parsing/parsing_map.c parsing/parsing_utils_1.c\
			parsing/parsing_utils_2.c\
			parsing/handling_texture.c\
			parsing/parsing_map_1.c \
			size_and_postion.c \
			init_textures.c \
			press_start.c ft_init.c \
			handling_keys.c ray_casting.c \
			drawing_floors_and_ceilings.c \
			mini_map.c doors.c \
			game_over.c drawing_walls.c ray_casting_util_1.c \
			doors_util.c ray_casting_util_2.c haswallat.c
OBJ = ${SRC:.c=.o}
CC = gcc 
CFLAGS = -Wall -Werror -Wextra
HEADERS = include/cub3d.h
LIBFT = libft/libft.a
GREEN  = \033[1;32m
YELLOW = \033[1;33m

all : $(NAME)

%.o:%.c  $(HEADERS)
	gcc $(CFLAGS) -g -c $< -o $@

$(NAME) : $(OBJ) $(HEADERS)
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) -lmlx -framework openGL -framework AppKit  $(OBJ) $(LIBFT) -g -o $(NAME)
	@echo "$(GREEN)---> success!"
clean :
	@${MAKE} -C libft clean
	@rm -f $(OBJ)
	@echo "${YELLOW}---> object files deleted!"

fclean : clean
	@${MAKE} -C libft fclean
	@rm -f $(NAME)
	@echo "${YELLOW}---> all deleted!"
re : fclean all
