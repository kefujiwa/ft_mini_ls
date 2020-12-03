# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 18:41:00 by kefujiwa          #+#    #+#              #
#    Updated: 2020/12/03 22:39:11 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_mini_ls
CC		= gcc
CCFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_mini_ls.c\
		flstadd.c\
		flstclear.c\
		flstnew.c\
		flstprint.c\

OBJS		= $(SRCS:.c=.o)

BONUSDIR	= ./bonus/
SRCSb		= $(BONUSDIR)ft_mini_ls_bonus.c\
		$(BONUSDIR)flstadd_bonus.c\
		$(BONUSDIR)flstclear_bonus.c\
		$(BONUSDIR)flstnew_bonus.c\
		$(BONUSDIR)flstprint_bonus.c\

OBJSb		= $(SRCSb:.c=.o)

LIBFTDIR	= ./libft/
LIBFTSRCNAME	= $(SRCS)ft_memset.c\
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
		$(SRCS)ft_lstnew.c\
		$(SRCS)ft_lstadd_front.c\
		$(SRCS)ft_lstsize.c\
		$(SRCS)ft_lstlast.c\
		$(SRCS)ft_lstadd_back.c\
		$(SRCS)ft_lstdelone.c\
		$(SRCS)ft_lstclear.c\
		$(SRCS)ft_lstiter.c\
		$(SRCS)ft_lstmap.c\
LIBFTOBJNAME	= $(LIBFTSRCS:.c=.o)
LIBFTSRCS	= $(LIBFTDIR$(LIBFTSRCNAME))
LIBFTOBJS	= $(LIBFTDIR$(LIBFTOBJNAME))
LIBFTNAME	= $(LIBFTDIR)libft.a

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFTNAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTNAME)

bonus:		$(OBJSb) $(LIBFTNAME)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJSb) $(LIBFTNAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFTNAME):	FORCE
		$(MAKE) -C ./libft

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS) $(OBJSb)

fclean:		clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:		fclean all

FORCE:
.PHONY: all clean fclean re FORCE
