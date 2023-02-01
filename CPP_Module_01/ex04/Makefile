# **************************************************************************** #
# NAME
# **************************************************************************** #

NAME =	main_ex04

# **************************************************************************** #
# FILES
# **************************************************************************** #

SRC		= main.cpp

OBJ		= $(SRC:.cpp=.o)
DEP		= $(addsuffix .d, $(basename $(OBJ)))

# **************************************************************************** #
#COMPILATION
# **************************************************************************** #

COMPILE  = c++ -c
LINK	 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
DFLAGS	 = -g #-fsanitize=address
RM_FILE	 = rm -f
RM_DIR	 = rm -rf
MKDIR	 = mkdir -p

# **************************************************************************** #
#RULES
# **************************************************************************** #

%.o : %.cpp Makefile 
	@$(COMPILE) $(DFLAGS) $(CXXFLAGS) -o $@ $<
	@ECHO "Compiling... $<"

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@$(LINK) $(DFLAGS) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@ECHO "Created $(NAME)"

clean:
	@$(RM_FILE) $(OBJ) $(DEP) 

fclean: clean
	@$(RM_FILE) $(NAME)

re: fclean all

.PHONY:	all clean fclean re