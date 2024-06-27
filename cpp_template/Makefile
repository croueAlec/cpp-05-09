# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroue <acroue@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/05/30 11:12:54 by acroue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#	Program name
NAME = CHANGE_ME

#	Colors
DEFAULT    = \033[0m
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
BWHITE    = \033[1;37m

# Utils
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
DEP_FLAGS = -MMD -MP
RM = rm -rf

#	Directories
SRCS_DIR = srcs
INCS_DIR = includes
OBJS_DIR = objs

#	Files

INCLUDES := $(INCS_DIR) \

INCLUDES_FLAGS := $(addprefix -I , $(INCLUDES))

SRC := \
	main.cpp

OBJ := $(patsubst %.cpp,$(OBJS_DIR)/%.o,$(SRC))
DEPS := $(patsubst %.cpp,$(OBJS_DIR)/%.d,$(SRC))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)* Assembling $(BWHITE)$@$(DEFAULT)"
	@$(CPP) $(CPPFLAGS) $(OBJ) $(INCLUDES_FLAGS) -o $@

-include %(DEPS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@echo "$(CYAN)- Compiling$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CPP) $(DEP_FLAGS) $(CPPFLAGS) $(INCLUDES_FLAGS) -c $< -o $@

clean:
	@echo "$(RED)! Removing$(DEFAULT) ${OBJS_DIR} files"
	@${RM} ${OBJS_DIR}

fclean: clean
	@echo "$(RED)! Removing$(DEFAULT) $(NAME)"
	@$(RM) $(NAME)

re: fclean all

cre:
	@clear
	@make re --no-print-directory
