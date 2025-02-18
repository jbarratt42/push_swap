# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 09:15:50 by jbarratt          #+#    #+#              #
#    Updated: 2025/02/18 14:24:20 by jbarratt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEAD = $(addsuffix .h, $(NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	push_swap \
	cheapest_first_sort \
	operate \
	read_stack \
	queue \
	queue_collapse \
	stack \
	short_sort \
	utils


SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS) main.c
	$(CC) $(OBJS) main.c -o $(NAME)

# $(HEAD): $(NAME).stub.h $(SRCS)
# 	cp $< $(HEAD)
# 	cproto -E 0 $(SRCS) >> $(HEAD)
# 	echo "#endif" >> $(HEAD)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	make $(HEAD)
	$(CC) $(CFLAGS) -I. -c $< -o $@

debug: $(SRCS) $(HEAD) main.c
	$(CC) -g $(CFLAGS) $(SRCS) $(HEAD) main.c -o $(NAME)

gen_stack: $(SRCS) $(HEAD) gen_stack.c
	$(CC) $(SRCS) gen_stack.c -o gen_stack

test: test.sh gen_stack $(NAME)
	./test.sh 100 3 3
	./test.sh 500 5 12
	./test.sh 1000 100 700
	./test.sh 1000 500 5500

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

list:
	@echo $(SRCS)

.PHONY: all clean fclean re debug list
