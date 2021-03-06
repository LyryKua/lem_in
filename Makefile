# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/03/08 17:45:36 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=				\033[

NORMAL :=				$(SWITCH)0m
BOLD :=					$(SWITCH)1m
RED :=					$(SWITCH)31m
GREEN :=				$(SWITCH)32m
YELLOW :=				$(SWITCH)33m
CYAN :=					$(SWITCH)36m
LIGHT_RED :=			$(SWITCH)91m
LIGHT_YELLOW :=			$(SWITCH)93m
LIGHT_GREEN :=			$(SWITCH)92m
LIGHT_CYAN :=			$(SWITCH)96m

NAME :=					lem_in

INC_DIR :=				includes/

LIBFTPRINTF_DIR :=		libftprintf/

SRCS_DIR :=				sources/

OBJS_DIR :=				objects/

SRCS :=					main.c			\
						error_exit.c

OBJS :=					$(SRCS:.c=.o)

SRCS_PATHS :=			$(addprefix $(SRCS_DIR), $(SRCS))

OBJS_PATHS :=			$(addprefix $(OBJS_DIR), $(OBJS))

LIBFTPRINTF :=			$(LIBFTPRINTF_DIR)libftprintf.a

CC :=					gcc

INC :=					-I$(LIBFTPRINTF_DIR)includes/		\
						-I$(LIBFTPRINTF_DIR)libft/includes	\
						-I$(INC_DIR)
#CFLAGS :=				-Wall -Werror -Wextra
LIBFTPRINTF_FLAGS :=	-L$(LIBFTPRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJS_PATHS) 	
	$(CC) $(LIBFTPRINTF_FLAGS) $(OBJS_PATHS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(NORMAL)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@echo "$(GREEN)Compile $<$(NORMAL)"
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(LIBFTPRINTF):
	@echo "$(YELLOW)Compiling libft... $<$(NORMAL)"
	make -C $(LIBFTPRINTF_DIR)

clean:
	make clean -C $(LIBFTPRINTF_DIR)
	rm -rf $(OBJS_PATHS)
	@echo "$(RED)$(NAME) objects cleared$(NORMAL)"

fclean: clean
	make fclean -C $(LIBFTPRINTF_DIR)
	rm -rf $(NAME)
	@echo "$(RED)$(NAME) deleted$(NORMAL)"
	
re: fclean all

pu: fclean 

.PHONY: clean fclean re
