# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2016/05/02 17:48:09 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O3

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_abs.c \
		  ft_itoa.c \
		  ft_atoi.c \
		  ft_bzero.c \
		  ft_strcat.c \
		  ft_strcpy.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_strlen.c \
		  ft_strnew.c \
		  ft_strjoin.c \
		  ft_strcmp.c \
		  ft_memalloc.c \
		  ft_rand.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temporary $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette $(HEADER)
	@echo
	norminette $(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
