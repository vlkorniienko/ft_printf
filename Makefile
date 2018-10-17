# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 19:57:56 by vkorniie          #+#    #+#              #
#    Updated: 2018/08/02 19:57:58 by vkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = ft_printf.out
SRCS = first.c write_sbigc.c write_sss.c write_char.c write_string.c \
		write_oux.c write_oux_c.c print_out.c print_cont.c \
		print_non_stop.c find_qualifier.c find_qualifier_cont.c \
		write_unicd.c write_unicd_con.c printf_begin.c final_file.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c -g -Wall -Wextra -Werror libft/*.c -I libft/libft.h
	@gcc -c $(SRCS)
	@ar rc $(NAME) *.o

test:
	@gcc -g -L. -lftprintf $(SRCS) ../printf1/main.c -o $(TEST)

clean:
	@rm -rf *.o libft/*.o

fclean: clean
	@rm -rf $(NAME) libft/*.a

re: fclean all
