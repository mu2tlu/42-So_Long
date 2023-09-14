SRC = src/main.c src/game.c src/map_constraction.c src/map_validation.c src/draw.c src/input.c src/utils2.c src/path_finding.c

BSRC = src_bonus/draw_bonus.c src_bonus/main_bonus.c src_bonus/game_bonus.c src_bonus/map_constraction_bonus.c src_bonus/map_validation_bonus.c src_bonus/utils_bonus.c src_bonus/input_bonus.c src_bonus/utils2_bonus.c src_bonus/path_finding_bonus.c

INC = inc
NAME = so_long
BNAME = so_long_bonus
CFLAGS = -Wall -Werror -Wextra
FRAMEWORKS = -framework OpenGL -framework AppKit
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(SRC)
	@make -C mlx
	@gcc -g -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

bonus: $(BNAME)

$(BNAME): $(BSRC)
	@make -C mlx
	@gcc -o $@ $^ $(CFLAGS) $(FRAMEWORKS) $(MLX) -I $(INC)

clean:
	@rm -rf $(NAME)
	@rm -rf $(BNAME)

fclean: clean
	@make -C mlx clean

re: fclean all

.PHONY: clean fclean re all 