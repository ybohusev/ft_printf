# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:25:37 by ybohusev          #+#    #+#              #
#    Updated: 2018/01/15 15:25:38 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftprintf.a

C = clang

FLAGS += -Wall -Wextra -Werror

LIBFT = ./libft

DIR_S = srcs

DIR_O = temporary

HEADER = includes

SOURCES = 

SOURCES += call_int.c
SOURCES += call_char.c
SOURCES += call_uint.c
SOURCES += char_width.c
SOURCES += ft_printf.c
SOURCES += hash_uint.c
SOURCES += precision_int.c
SOURCES += call_str.c
SOURCES += sep_spec.c
SOURCES += sign_int.c
SOURCES += width_int.c
SOURCES += work_with.c
SOURCES += handle_btwper.c
SOURCES += print_ptr.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all