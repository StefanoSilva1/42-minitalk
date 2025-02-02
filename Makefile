# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 21:48:34 by sdavi-al          #+#    #+#              #
#    Updated: 2025/02/01 13:11:56 by sdavi-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT	= client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
LIBFT		= libft/libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Ilibft
RM			= rm -f

SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all:		libft $(NAME_SERVER) $(NAME_CLIENT)

bonus:		libft $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

libft:
			$(MAKE) -C libft

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT_BONUS)

clean:
			$(MAKE) -C libft clean
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean:		clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re:			fclean all

.PHONY:		all clean fclean re libft bonus

