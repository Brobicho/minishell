# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/08 19:44:04 by brobicho     #+#   ##    ##    #+#        #
#    Updated: 2018/08/11 21:29:18 by brobicho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell

CC = gcc

LIBFT = libft/libft.a

FLAG = -Werror -Wall -Wextra

OBJ = $(SRC_FILES:.c=.o)

SRC_FILES = main.c

HEADER = minishell.h libft/libft.h

all: lib $(NAME)

lib: 
	@make -C libft/

%.o: %.c $(HEADER)
	@$(CC) $(FLAG) -c $< -o $@ 
	@printf "ft_ls: "
	@printf %b "\033[1;93mCompiling "
	@printf "$@..."
	@printf "                                          "
	@printf "\r"

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAG) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[1;92mDone ! Project \033[1;91m$(NAME) \033[1;92mready !\033[0m\n"

clean:
	@rm -f $(OBJ)
	@make clean -C libft/
	@echo "\033[1;91m$(NAME)\033[1;94m: Project cleaned.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
