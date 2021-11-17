# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 20:26:16 by ycornamu          #+#    #+#              #
#    Updated: 2021/11/17 16:41:40 by ycornamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c \
	   sort.c \
	   utils.c \
	   bubble.c \
	   insertion.c \
	   separate.c \
	   stack/stack.c \
	   stack/swap.c \
	   stack/push.c \
	   stack/rotate.c \
	   stack/rotate_rev.c

SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj obj/stack

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = includes
LIBFT = libft.a
LIBFT_DIR = libft

CC = clang
CFLAGS = -g -Wall -Werror -Wextra  -I $(LIBFT_DIR) -I $(HEADERS)

all: $(NAME)

$(NAME): $(_OBJS)
	$(CC) $(_OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(_OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(DIRS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) -c $(CFLAGS) $< -o $@

$(DIRS):
	mkdir -p $(DIRS)

clean:
	rm -rf $(DIRS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -rf $(DIRS) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(LIBFT_DIR) bonus

re: fclean all

.PHONY: all clean fclean re
