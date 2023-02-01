# **************************************************************************** #
# NAME
# **************************************************************************** #

NAME =	serializer

# **************************************************************************** #
# FOLDERS
# **************************************************************************** #

SRC_DIR 	= src/
INCLUDE_DIR = include/
OBJ_DIR 	= obj/

# **************************************************************************** #
# FILES
# **************************************************************************** #

INC		= -I $(INCLUDE_DIR)

SRC 	=	main.cpp
			
OBJ		= $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))
DEP		= $(addsuffix .d, $(basename $(OBJ)))

# **************************************************************************** #
#COMPILATION
# **************************************************************************** #

COMPILE  = c++ -c
LINK	 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP $(INC)
DFLAGS	 = #-g #-fsanitize=address
RM_FILE	 = rm -f
RM_DIR	 = rm -rf
MKDIR	 = mkdir -p

# **************************************************************************** #
#RULES
# **************************************************************************** #

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp Makefile 
	@$(MKDIR) $(dir $@)
	@$(COMPILE) $(DFLAGS) $(CXXFLAGS) -o $@ $<
	@ECHO "Compiling... $<"

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@$(LINK) $(DFLAGS) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@ECHO "Created $(NAME)"

clean:
	@$(RM_FILE) $(OBJ) $(DEP) 
	@$(RM_DIR)  $(OBJ_DIR) 

fclean: clean
	@$(RM_FILE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
