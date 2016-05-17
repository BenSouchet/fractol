# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 18:49:05 by bsouchet          #+#    #+#              #
#    Updated: 2016/05/17 19:14:15 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O3

LIBFT = libft

DIR_S = sources

DIR_O = temporary

DIR_MLX = libmlx

HEADERS = includes

SOURCES = main.c \
		  hook.c \
		  draw.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temporary $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(DIR_MLX)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $^ -framework OpenGL -framework AppKit -L $(DIR_MLX) -lmlx

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

norme:
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(HEADERS)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(DIR_MLX)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(DIR_MLX)

re: fclean all

.PHONY: all, temporary, norme, clean, fclean, re
