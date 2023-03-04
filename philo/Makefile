# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruangde <pruangde@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 12:37:19 by pruangde          #+#    #+#              #
#    Updated: 2023/03/04 15:44:05 by pruangde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = uname -s

ifeq ($(UNAME), Linux)
	CC = clang
else
	CC = gcc
endif

CFLAGS = -Wall -Wextra -Werror
ADDITIONAL = -g -pthread
RM = rm -rf
NAME = philo

SRCS = philo.c cx_input.c init_data.c routine_1.c routine_2.c time.c utils_1.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(ADDITIONAL) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

test:
	$(CC) maintest.c $(NAME)
	#valgrind --vgdb=no --leak-check=full --show-leak-kinds=all ./a.out

leak:
	leaks --atExit -- ./a.out

san:
	$(CC) -fsanitize=address -fno-omit-frame-pointer maintest.c

norm:
	@echo "------------------------------------"
	@echo " !!!!!!!!   NORMINETTE   !!!!!!!!"
	@echo ""
	@norminette -R CheckForbiddenSourceHeader *.c
	@echo ""
	@echo ""
	@norminette -R CheckDefine *.h
	@echo ""
	@echo "------------------------------------"
