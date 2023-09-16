LIBSRC		=	libs/libft/ft_lstadd_back.c \
				libs/libft/ft_memcmp.c \
				libs/libft/ft_strcmp.c \
				libs/libft/ft_strrchr.c \
				libs/libft/ft_atoi.c \
				libs/libft/ft_lstadd_front.c \
				libs/libft/ft_memcpy.c \
				libs/libft/ft_strdup.c \
				libs/libft/ft_strtrim.c \
				libs/libft/ft_bzero.c \
				libs/libft/ft_lstclear.c \
				libs/libft/ft_memmove.c \
				libs/libft/ft_striteri.c \
				libs/libft/ft_substr.c \
				libs/libft/ft_calloc.c \
				libs/libft/ft_lstdelone.c \
				libs/libft/ft_memset.c \
				libs/libft/ft_strjoin.c \
				libs/libft/ft_tolower.c \
				libs/libft/ft_isalnum.c \
				libs/libft/ft_lstiter.c \
				libs/libft/ft_putchar_fd.c \
				libs/libft/ft_strlcat.c \
				libs/libft/ft_toupper.c \
				libs/libft/ft_isalpha.c \
				libs/libft/ft_lstlast.c \
				libs/libft/ft_putendl_fd.c \
				libs/libft/ft_strlcpy.c \
				libs/libft/get_next_line.c \
				libs/libft/ft_isascii.c \
				libs/libft/ft_lstmap.c \
				libs/libft/ft_putnbr_fd.c \
				libs/libft/ft_strlen.c \
				libs/libft/get_next_line_utils.c \
				libs/libft/ft_isdigit.c \
				libs/libft/ft_lstnew.c \
				libs/libft/ft_putstr_fd.c \
				libs/libft/ft_strmapi.c \
				libs/libft/ft_isprint.c \
				libs/libft/ft_lstsize.c \
				libs/libft/ft_split.c \
				libs/libft/ft_strncmp.c \
				libs/libft/ft_itoa.c \
				libs/libft/ft_memchr.c \
				libs/libft/ft_strchr.c \
				libs/libft/ft_strnstr.c

SRC			=	src/game.c \
				src/map_construction.c \
				src/map_validation.c \
				src/draw.c \
				src/input.c \
				src/utils.c \
				src/path_finding.c
SRC			+=	$(LIBSRC)
	
BONUS_SRC	=	src_bonus/draw_bonus.c \
				src_bonus/game_bonus.c \
				src_bonus/map_construction_bonus.c \
				src_bonus/map_validation_bonus.c \
				src_bonus/utils_bonus.c \
				src_bonus/input_bonus.c \
				src_bonus/utils2_bonus.c \
				src_bonus/path_finding_bonus.c
BONUS_SRC	+=	$(LIBSRC)

NAME		=	so_long
BONUS_NAME	=	so_long_bonus
MLX			=	./libs/mlx/libmlx.a
FLAGS		=	-Wall -Wextra -Werror -Imlx
CFLAGS		=	-Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit -L./libs/mlx
CC			=	cc
OBJ			=	$(eval OBJ := $$(SRC:.c=.o))$(OBJ)
BONUS_OBJ	=	$(eval BONUS_OBJ := $$(BONUS_SRC:.c=.o))$(BONUS_OBJ)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): mlx_lib $(OBJ)
	@$(CC) ./src/main.c $(OBJ) $(MLX) $(CFLAGS) -o $(NAME)

mlx_lib:
	@make -C libs/mlx

b: bonus
bonus: $(BONUS_OBJ) $(OBJ)
	@$(CC) ./src_bonus/main_bonus.c $(BONUS_OBJ) $(MLX) $(CFLAGS) -o $(BONUS_NAME)

c: clean
clean:
	@rm $(OBJ)
	@rm $(BONUS_OBJ)

fc: fclean
fclean: clean
	@make -C libs/mlx clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

n: norminette
norminette:
	norminette

.PHONY: clean c fclean fc re all norminette n bonus b
