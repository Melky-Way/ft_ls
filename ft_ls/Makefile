#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 18:21:40 by msoudan           #+#    #+#              #
#    Updated: 2014/03/19 14:12:07 by msoudan          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CPATH = src
HPATH = includes
LIBPATH = libft

NAME = ft_ls 
LIB = $(LIBPATH)/libft.a

CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_ls.c
SRC += ft_lsblkcnt.c
SRC += ft_lsclearlist.c
SRC += ft_lsgetdata.c
SRC += ft_lserror.c
SRC += ft_lsgetuidgroup.c
SRC += ft_lsprintdata.c
SRC += ft_lsrecursive.c
SRC += ft_lssortdata.c
SRC += ft_printspaces.c
SRC += ft_lsgetname.c
SRC += main.c

CFILES = $(patsubst %,$(CPATH)/%,$(SRC))
OFILES = $(patsubst %.c,%.o,$(CFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	@make -C $(LIBPATH)
	@$(CC) -L $(LIBPATH) -lft $^ -o $@
	@clear
	@echo "\033[36m\\o/ Finished ! \\o/\033[0m"

%.o: %.c
	@$(CC) -I $(HPATH) -I $(LIBPATH)/$(HPATH) $(CFLAGS) -c $^ -o $@

clean:
	@make -C $(LIBPATH) clean
	@$(RM) -f $(OFILES)

fclean: clean
	@make -C $(LIBPATH) fclean
	@$(RM) -f $(NAME)

re: fclean all
