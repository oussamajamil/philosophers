# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:47:40 by ojamil            #+#    #+#              #
#    Updated: 2022/01/20 16:11:59 by ojamil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_m

CC = gcc

CFLAGES = -Wall -Wextra -Werror

INCLUDES = philo/philo.h

SRC += philo/philo.c
SRC += philo/utils1.c
SRC += philo/parsing.c

all : $(NAME)

$(NAME) : $(SRC) $(INCLUDES)
		$(CC)  $(SRC) -o $(NAME)
	