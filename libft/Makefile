# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 10:43:38 by ycontre           #+#    #+#              #
#    Updated: 2023/11/30 17:08:40 by ycontre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT #
NAME	= libft.a
CC		= @clang
CFLAGS	= -Wall -Wextra -Werror
RM		= @rm -f
FILE	= $(shell ls -lR src/ | grep -F .c | wc -l)
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

# PRINT
# Libft is ready to use
RNBW	= @printf "                                                                     \r$(RED)Lib$(ORANGE)ft$(LBLUE) is$(INDI) re$(PURPLE)ady$(RESET)\n"

# SOURCES #
SRC	= ./src/check/ft_isalnum.c\
	  ./src/check/ft_isalpha.c\
	  ./src/check/ft_isascii.c\
	  ./src/check/ft_isdigit.c\
	  ./src/check/ft_isprint.c\
	  ./src/list/ft_lstadd_back.c\
	  ./src/list/ft_lstadd_front.c\
	  ./src/list/ft_lstclear.c\
	  ./src/list/ft_lstdelone.c\
	  ./src/list/ft_lstiter.c\
	  ./src/list/ft_lstlast.c\
	  ./src/list/ft_lstmap.c\
	  ./src/list/ft_lstnew.c\
	  ./src/list/ft_lstsize.c\
	  ./src/memory/ft_bzero.c\
	  ./src/memory/ft_calloc.c\
	  ./src/memory/ft_memchr.c\
	  ./src/memory/ft_memcmp.c\
	  ./src/memory/ft_memcpy.c\
	  ./src/memory/ft_memmove.c\
	  ./src/memory/ft_memset.c\
	  ./src/print/ft_putchar_fd.c\
	  ./src/print/ft_putendl_fd.c\
	  ./src/print/ft_putnbr_fd.c\
	  ./src/print/ft_putstr_fd.c\
	  ./src/string/ft_atoi.c\
	  ./src/string/ft_itoa.c\
	  ./src/string/ft_split.c\
	  ./src/string/ft_strchr.c\
	  ./src/string/ft_strncmp.c\
	  ./src/string/ft_strdup.c\
	  ./src/string/ft_striteri.c\
	  ./src/string/ft_strjoin.c\
	  ./src/string/ft_strlcat.c\
	  ./src/string/ft_strlcpy.c\
	  ./src/string/ft_strlen.c\
	  ./src/string/ft_strmapi.c\
	  ./src/string/ft_strncmp.c\
	  ./src/string/ft_strnstr.c\
	  ./src/string/ft_strrchr.c\
	  ./src/string/ft_strtrim.c\
	  ./src/string/ft_substr.c\
	  ./src/string/ft_tolower.c\
	  ./src/string/ft_toupper.c\
	  ./src/string/ft_split_mult.c\
	  ./src/gnl/get_next_line.c\
	  ./src/gnl/get_next_line_utils.c\
	  ./src/utils/ft_max.c\
	  ./src/utils/ft_min.c\
	  ./src/utils/ft_abs.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)
	$(RNBW)	

%.o: %.c
	@printf "$(ORANGE)[$(RESET)$(CMP)$(ORANGE)] $(RESET)Compilating the libft... $(RED)$<$(ORANGE) [$(RESET)$(CMP)$(ORANGE)/$(RESET)$(FILE)$(ORANGE)]$(RESET)           \r"
	$(CC) $(CFLAGS) -c $< -o  $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
	all
.PHONY: 
	all clean fclean re
