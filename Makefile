# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 18:41:00 by kefujiwa          #+#    #+#              #
#    Updated: 2021/01/20 04:26:33 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAKEFILE ###

## COLORS ##

# Formats #
_END				= \x1b[0m
_BOLD				= \x1b[1m
_DIM				= \x1b[2m
_UNDER				= \x1b[4m
_BLINK				= \x1b[5m
_REV				= \x1b[7m
_HIDDEN				= \x1b[8m

# Foreground Colors #
_GREY				= \x1b[30m
_RED				= \x1b[31m
_GREEN				= \x1b[32m
_YELLOW				= \x1b[33m
_BLUE				= \x1b[34m
_PURPLE				= \x1b[35m
_CYAN				= \x1b[36m
_WHITE				= \x1b[37m

# Background Colors #
_BGREY				= \x1b[40m
_BRED				= \x1b[41m
_BGREEN				= \x1b[42m
_BYELLOW			= \x1b[43m
_BBLUE				= \x1b[44m
_BPURPLE			= \x1b[45m
_BCYAN				= \x1b[46m
_BWHITE				= \x1b[47m


# **************************************************************************** #

## VARIABLES ##

# Compilation #
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
AR					= ar rcs

# Delete #
RM					= rm -rf

# Directories #
DIR_HEADERS			= ./includes/
DIR_SRCS			= ./srcs/
DIR_OBJS			= ./compiled_srcs/
DIR_SRCSb			= ./bonus/
DIR_OBJSb			= ./compiled_bonus/
DIR_LIBFT			= ./libft/
DIR_LIBFT_HEADERS	= $(DIR_LIBFT)includes/

# Files #
SRCS				= ft_mini_ls.c \
						flstadd.c \
						flstclear.c \
						flstnew.c \
						flstprint.c

SRCSb				= ft_mini_ls_bonus.c \
						flstadd_bonus.c \
						flstclear_bonus.c \
						flstnew_bonus.c \
						flstprint_bonus.c

# Compiled Files #
OBJS				= $(SRCS:%.c=$(DIR_OBJS)%.o)
OBJSb				= $(SRCSb:%.c=$(DIR_OBJSb)%.o)
LIBFT_NAME			= $(DIR_LIBFT)libft.a

# Executable #
NAME				= ft_mini_ls


# **************************************************************************** #

## RULES ##

# Variables Rules #
$(NAME):			$(OBJS) $(LIBFT_NAME)
						@echo "$(_GREEN) All files compiled. $(_END)"
						$(CC) $(CFLAGS) -I $(DIR_HEADERS) -I $(DIR_LIBFT_HEADERS) $(OBJS) $(LIBFT_NAME) -o $(NAME)
						@echo "$(_GREEN) Executable '$(NAME)' created. $(_END)"

$(LIBFT_NAME):		FORCE
						@$(MAKE) -C $(DIR_LIBFT)

FORCE:

# Compiled Source Files #
$(OBJS):			$(DIR_OBJS)
$(OBJSb):			$(DIR_OBJSb)

$(DIR_OBJS)%.o: 	$(DIR_SRCS)%.c
						$(CC) $(CFLAGS) -I $(DIR_HEADERS) -I $(DIR_LIBFT_HEADERS) -c $< -o $@
$(DIR_OBJSb)%.o: 	$(DIR_SRCSb)%.c
						$(CC) $(CFLAGS) -I $(DIR_HEADERS) -I $(DIR_LIBFT_HEADERS) -c $< -o $@

$(DIR_OBJS):
						@mkdir $(DIR_OBJS)
$(DIR_OBJSb):
						@mkdir $(DIR_OBJSb)

# Mandatory Part #
all:				$(NAME)

clean:
						@$(MAKE) clean -C $(DIR_LIBFT)
						@$(RM) $(DIR_OBJS) $(DIR_OBJSb)
						@$(RM) $(EXEC)
						@echo "$(_YELLOW) '$(DIR_OBJS)' '$(DIR_OBJSb)' has been deleted. $(_END)"

fclean:				clean
						@$(MAKE) fclean -C $(DIR_LIBFT)
						@$(RM) $(NAME)
						@echo "$(_YELLOW) '$(NAME)' has been deleted. $(_END)"

re:					fclean all

# Bonus Part #
bonus:				$(OBJSb) $(LIBFT_NAME)
						@echo "$(_GREEN) All files compiled. $(_END)"
						$(CC) $(CFLAGS) -I $(DIR_HEADERS) -I $(DIR_LIBFT_HEADERS) $(OBJSb) $(LIBFT_NAME) -o $(NAME)
						@echo "$(_GREEN) Executable '$(NAME)' created. $(_END)"

re_bonus:			fclean bonus

# Phony #
.PHONY:				all clean fclean re bonus re_bonus FORCE
