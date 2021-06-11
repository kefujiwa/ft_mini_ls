# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 18:41:00 by kefujiwa          #+#    #+#              #
#    Updated: 2021/06/11 18:00:27 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAKEFILE ###

## COLORS ##

# Formats #
_RESET				= \x1b[0m
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
HEADER_DIR			= includes/
SRCS_DIR			= srcs/
SRCS_DIRb			= bonus/
OBJS_DIR			= objs/srcs/
OBJS_DIRb			= objs/bonus/
LIBFT_DIR			= libft/

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
OBJS				= $(SRCS:%.c=$(OBJS_DIR)%.o)
OBJSb				= $(SRCSb:%.c=$(OBJS_DIRb)%.o)
LIBFT_NAME			= $(LIBFT_DIR)libft.a

# Executable #
NAME				= ft_mini_ls


# **************************************************************************** #

## RULES ##

# Main Rules #
all:				$(NAME)

clean:
					@$(MAKE) clean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning ft_mini_ls objects...\n$(_RESET)"
					@$(RM) objs/

fclean:
					@$(MAKE) fclean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning ft_mini_ls objects...\n$(_RESET)"
					@$(RM) objs/
					@echo "$(_RED)Deleting executable '$(NAME)'...\n$(_RESET)"
					@$(RM) $(NAME)

re:					fclean all

# Bonus Rules #
bonus:				fclean $(LIBFT_NAME) $(OBJS_DIRb) $(OBJSb)
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJSb) $(LIBFT_NAME) -o $(NAME)
						@echo "\n\n$(_GREEN)Executable '$(NAME)' created.\n$(_RESET)"
						@echo "$(_BLUE)Try \"./ft_mini_ls\".$(END)"

# Variable Rules #
$(NAME):			$(LIBFT_NAME) $(OBJS_DIR) $(OBJS)
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(OBJS) $(LIBFT_NAME) -o $(NAME)
						@echo "\n\n$(_GREEN)Executable '$(NAME)' created.\n$(_RESET)"
						@echo "$(_BLUE)Try \"./ft_mini_ls\".$(END)"

$(LIBFT_NAME):
					@$(MAKE) -C $(LIBFT_DIR)

# Compiled Source Files #
$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
						@printf "$(_YELLOW)Generating ft_mini_ls objects... %-33.33s\r$(_RESET)" $@
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@
$(OBJS_DIRb)%.o: 	$(SRCS_DIRb)%.c
						@printf "$(_YELLOW)Generating ft_mini_ls objects... %-33.33s\r$(_RESET)" $@
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $(OBJS_DIR)
$(OBJS_DIRb):
					@mkdir -p $(OBJS_DIRb)

# Phony #
.PHONY:				all clean fclean re bonus re_bonus FORCE
