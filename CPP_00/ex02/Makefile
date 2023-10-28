# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 18:07:11 by ancolmen          #+#    #+#              #
#    Updated: 2023/10/28 22:30:31 by ancolmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######	VARIABLES #######

NAME		= my_account_log

SRC			= tests.cpp \
				Account.cpp \

BIN_PATH 	= ./bin/

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -std=c++98

OBJ			= $(addprefix $(BIN_PATH), $(SRC:.cpp=.o))

DEPS		= $(OBJ:.o=.d)

RM			= rm -rf

LEAKS		= valgrind

LF			= --leak-check=full \
        	--show-leak-kinds=all \
    		--track-origins=yes \
			--track-fds=yes \

#######	RULES #######

all: $(NAME)

$(BIN_PATH)%.o: %.cpp
	@ mkdir -p $(dir $@)
	@ echo "\n\033[97;4m🚧 compiling $@ file 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo "\033[32;1m★ bin OK ★\033[0m\n"

$(NAME): $(OBJ)
	@ echo "\033[97;4m🚧 account_log in progress 🚧\033[0m\n"
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@ echo "\033[32;1m✅ MY_ACCOUNT_LOG READY ✅\033[0m\n"

bonus: all

clean:
	@ echo "\n\033[97;4m🚧 cleaning object files 🚧\033[0m\n"
	@ $(RM) $(BIN_PATH)
	@ echo "\033[32;1m★ objects cleaned ★\033[0m\n"
	

fclean: clean
	@ $(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

leaks: all
	$(LEAKS) ./$(NAME)

leaksfull: all
	$(LEAKS) $(LF) ./$(NAME)

.PHONY: all clean fclean re bonus rebonus
