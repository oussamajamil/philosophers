# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 14:47:40 by ojamil            #+#    #+#              #
#    Updated: 2022/01/21 14:33:21 by ojamil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_m

CC = gcc

CFLAGES = -Wall -Wextra -Werror

INCLUDES = philo/philo.h

SRC += philo/philo.c
SRC += philo/utils1.c
SRC += philo/parsing.c
SRC += philo/Circular_list.c 
SRC += philo/exec.c 

all : $(NAME)

$(NAME) : $(SRC) $(INCLUDES)
		$(CC)  $(SRC) -o ./philo/$(NAME)

clean :
	rm -rf ./philo/$(NAME)

fclean : clean
	