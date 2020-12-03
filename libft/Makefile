# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 23:54:56 by kefujiwa          #+#    #+#              #
#    Updated: 2020/07/05 19:00:30 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./

SRC	= $(SRCS)ft_memset.c\
		$(SRCS)ft_memset.c\
		$(SRCS)ft_bzero.c\
		$(SRCS)ft_memcpy.c\
		$(SRCS)ft_memccpy.c\
		$(SRCS)ft_memmove.c\
		$(SRCS)ft_memchr.c\
		$(SRCS)ft_memcmp.c\
		$(SRCS)ft_strlen.c\
		$(SRCS)ft_strlcpy.c\
		$(SRCS)ft_strlcat.c\
		$(SRCS)ft_strchr.c\
		$(SRCS)ft_strrchr.c\
		$(SRCS)ft_strnstr.c\
		$(SRCS)ft_strncmp.c\
		$(SRCS)ft_atoi.c\
		$(SRCS)ft_isalpha.c\
		$(SRCS)ft_isdigit.c\
		$(SRCS)ft_isalnum.c\
		$(SRCS)ft_isascii.c\
		$(SRCS)ft_isprint.c\
		$(SRCS)ft_toupper.c\
		$(SRCS)ft_tolower.c\
		$(SRCS)ft_calloc.c\
		$(SRCS)ft_strdup.c\
		$(SRCS)ft_substr.c\
		$(SRCS)ft_strjoin.c\
		$(SRCS)ft_strtrim.c\
		$(SRCS)ft_split.c\
		$(SRCS)ft_itoa.c\
		$(SRCS)ft_strmapi.c\
		$(SRCS)ft_putchar_fd.c\
		$(SRCS)ft_putstr_fd.c\
		$(SRCS)ft_putendl_fd.c\
		$(SRCS)ft_putnbr_fd.c\

SRCb	= $(SRCS)ft_lstnew.c\
		$(SRCS)ft_lstadd_front.c\
		$(SRCS)ft_lstsize.c\
		$(SRCS)ft_lstlast.c\
		$(SRCS)ft_lstadd_back.c\
		$(SRCS)ft_lstdelone.c\
		$(SRCS)ft_lstclear.c\
		$(SRCS)ft_lstiter.c\
		$(SRCS)ft_lstmap.c\

OBJ	= $(SRC:.c=.o)

OBJb	= $(SRCb:.c=.o)


all:	$(NAME)

$(NAME)	: $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:	all $(OBJb)
	ar rcs $(NAME) $(OBJb)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ) $(OBJb)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
