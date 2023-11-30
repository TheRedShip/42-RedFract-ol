FILE	= $(shell ls -lR mandatory/src | grep -F .c | wc -l)
CMP		= 1
CLEAR	= @clear

# COLOR #
GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;213m
LBLUE	= \033[38;5;51m
BLUE	= \033[38;5;117m
INDI	= \033[38;5;99m
RESET	= \033[00m

RNBW	= @printf "                                                                     \r$(RED)Fract'$(ORANGE)ol$(LBLUE) is$(INDI) re$(PURPLE)ady$(RESET)\n"

NAME		=	fractol

CC			=	cc

CFLAGS		=	-g -Wall -Wextra -Werror

INCLUDE		=	-I.

LIBFT			=	-L./libft -lft

SRCS		=	mandatory/src/fractol.c						\

OBJS		= 	${SRCS:.c=.o}

# OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

LIBPATH		= 	libft/

MINILIBXPATH		= 	minilibx-linux/

all:			${NAME}
	$(RNBW)

%.o: %.c
	@printf "$(ORANGE)[$(RESET)$(CMP)$(ORANGE)] $(RESET)Compilating Fract'ol... $(RED)$<$(ORANGE) [$(RESET)$(CMP)$(ORANGE)/$(RESET)$(FILE)$(ORANGE)]$(RESET)           \r"
	$(CC) $(CFLAGS) -c $< -o  $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

${NAME}:		${OBJS}
			make --quiet -C ${LIBPATH}
			make --quiet -C ${MINILIBXPATH}
			${CC} ${CFLAGS} $^ ${INCLUDE} ${LIBFT} -Lminilibx-linux -lmlx_Linux -I./minilibx-linux -lXext -lX11 -lm -lz -o $@



clean:
			make --quiet clean -C ${LIBPATH}
			make --quiet clean -C ${MINILIBXPATH}
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
			make --quiet fclean -C ${LIBPATH}
			make --quiet clean -C ${MINILIBXPATH}
			rm -f ${NAME} ${NAME_BONUS} ${NAME_TEST}

re:				fclean all

.SILENT:
	all

.PHONY:			all clean fclean re