CC			=	cc

LIBS		=	libs
INCS		=	-I incs -I $(LIBS)/libft -I $(LIBS)/mlx


SRCDIR		=	src
SRC			=	$(SRCDIR)/draw.c \
				$(SRCDIR)/game.c \
				$(SRCDIR)/input.c \
				$(SRCDIR)/main.c \
				$(SRCDIR)/map_construction.c \
				$(SRCDIR)/map_validation.c \
				$(SRCDIR)/path_finding.c \
				$(SRCDIR)/utils.c
B_SRCDIR	=	src_bonus
BONUS_SRC	=	$(B_SRCDIR)/draw_bonus.c \
				$(B_SRCDIR)/game_bonus.c \
				$(B_SRCDIR)/map_construction_bonus.c \
				$(B_SRCDIR)/map_validation_bonus.c \
				$(B_SRCDIR)/utils_bonus.c \
				$(B_SRCDIR)/input_bonus.c \
				$(B_SRCDIR)/utils2_bonus.c \
				$(B_SRCDIR)/path_finding_bonus.c

NAME		=	so_long
bonus		=	so_long_bonus
CFLAGS		=	-Wall -Wextra -Werror $(INCS)
OBJ			= 	$(SRC:.o=.c)
B_OBJ		= 	$(BONUS_SRC:.o=.c)

all: $(NAME) #$(BONUS_NAME)

$(NAME):
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(LIBS)/libft -l ft -L $(LIBS)/mlx -l mlx

bonus:
	$(CC) $(CFLAGS) $(B_OBJ) -o $(bonus) -L $(LIBS)/libft -l ft -L $(LIBS)/mlx -l mlx

clean:
	rm -f $(OBJ) #$(B_OBJ)

fclean: clean
	make -C $(LIBS)/mlx clean
	#rm -f $(NAME) $(BONUS_NAME)

re: fclean all

norminette:
	norminette

.PHONY: clean fclean re all norminette