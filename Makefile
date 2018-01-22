# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlux <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:01:04 by tlux              #+#    #+#              #
#    Updated: 2018/01/22 04:30:49 by tlux             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re all

NAME = libft.a
HEADER = libft/libft.h
LIBSRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strsplit.c ft_strtrim.c ft_strsub.c ft_toupper.c ft_tolower.c \
		ft_strstr.c ft_strnstr.c ft_strrchr.c ft_count_if.c ft_foreach.c \
		ft_print_params.c ft_sqrt.c ft_swap.c get_next_line.c ft_lstfadd.c
CHECKERSRC =   checker.c exec_master.c visualiser.c
PUSHSWAPSRC =	commands.c ft_issort.c get_infos.c rotate_push.c quick_sort.c \
				ft_int_tab_dup.c get_pivot.c quick_sort2.c

LIBOBJ = $(addprefix libft/, $(LIBSRC:.c=.o))
CHECKEROBJ = $(addprefix checker_dir/, $(CHECKERSRC:.c=.o))
PUSHSWAPOBJ = $(addprefix push_swap_dir/, $(PUSHSWAPSRC:.c=.o))

CHECKER_EXEC = checker
PUSH_SWAP_EXEC = push_swap
CC = gcc
FLAGS = -Wextra -Werror -Wall

all : $(NAME)

%.o : %.c
	@printf "\r\E[K\x1b[0m\x1b[32mCreated : \x1b[33m\x1b[1m[\x1b[37m\x1b[36m$@\x1b[33m]"
	@$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)
	
$(NAME) : $(CHECKEROBJ) $(PUSHSWAPOBJ) $(LIBOBJ) 
	@printf "\r\E[K\x1b[0m\x1b[32mCreated : \x1b[33m\x1b[1m[\x1b[37m\x1b[36m.o files\x1b[33m]"
	@ar rc $(NAME) $(CHECKEROBJ) $(PUSHSWAPOBJ) $(LIBOBJ)
	@ranlib $(NAME)
	@printf "\n\r\E[K\x1b[0m\x1b[32mCreated : \x1b[33m\x1b[1m[\x1b[37m\x1b[35mlibft.a\x1b[33m]"
	@$(CC) $(FLAGS) checker_dir/main.c $(NAME) -o $(CHECKER_EXEC)
	@printf "\n\x1b[0m\x1b[32mCreated : \x1b[33m\x1b[1m[\x1b[37mchecker executable\x1b[33m]"
	@$(CC) $(FLAGS) push_swap_dir/main.c $(NAME) -o $(PUSH_SWAP_EXEC)
	@printf "\n\r\E[K\x1b[0m\x1b[32mCreated : \x1b[33m\x1b[1m[\x1b[37mpush_swap executable\x1b[33m]\n"
clean :
	@rm -rf $(LIBOBJ) $(CHECKEROBJ) $(PUSHSWAPOBJ)
	@printf "\x1b[0m\x1b[31mDeleted : \x1b[33m\x1b[1m[\x1b[37m\x1b[36m.o files\x1b[33m]\n"

fclean : 	clean
	@rm -rf $(NAME)
	@printf "\x1b[0m\x1b[31mDeleted : \x1b[33m\x1b[1m[\x1b[37m\x1b[35mlibft.a\x1b[33m]"
	@rm -rf $(CHECKER_EXEC)
	@printf "\x1b[0m\n\x1b[31mDeleted : \x1b[33m\x1b[1m[\x1b[37mchecker executable\x1b[33m]\n"
	@rm -rf $(PUSH_SWAP_EXEC)
	@printf "\x1b[0m\x1b[31mDeleted : \x1b[33m\x1b[1m[\x1b[37mpush_swap executable\x1b[33m]\n"

re : fclean all
