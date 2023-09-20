CC			=	cc

LIBS		=	libs
INCS		=	-I incs -I $(LIBS)/libft -I $(LIBS)/mlx 
LIBR		=	-L $(LIBS)/libft -l ft \
				-L $(LIBS)/mlx -l mlx -framework OpenGL -framework AppKit

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
				$(B_SRCDIR)/input_bonus.c \
				$(B_SRCDIR)/main_bonus.c \
				$(B_SRCDIR)/map_construction_bonus.c \
				$(B_SRCDIR)/map_validation_bonus.c \
				$(B_SRCDIR)/path_finding_bonus.c \
				$(B_SRCDIR)/utils_bonus.c

NAME		=	so_long
BONUS_NAME	=	so_long_bonus
CFLAGS		=	-Wall -Wextra -Werror $(INCS)
OBJ			= 	$(SRC:.c=.o)
B_OBJ		= 	$(BONUS_SRC:.c=.o)



all: depend $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBR)

bonus : $(B_OBJ) depend
	$(CC) $(CFLAGS) $(B_OBJ) -o $(BONUS_NAME) $(LIBR)

#bonus: depend $(BONUN_NAME)

depend:		
	make -C $(LIBS)/libft	&> /dev/null
	make -C $(LIBS)/mlx		&> /dev/null

clean:
	make -C $(LIBS)/mlx clean
	make -C $(LIBS)/libft clean
	rm -f $(OBJ) 
	rm -f $(B_OBJ)

fclean: clean
	rm -f $(NAME) 
	rm -f $(bonus)

re: fclean
	
norminette:
	norminette

.PHONY: clean fclean re all norminette bonus