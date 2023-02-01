# **************************************************************************** #
# NAME
# **************************************************************************** #

NAME	=	testAccount

# **************************************************************************** #
# FILES
# **************************************************************************** #

SRC		=	tests.cpp Account.cpp
OBJ		=	$(SRC:.cpp=.o)

# **************************************************************************** #
#COMPILATION
# **************************************************************************** #

COMPILE  = c++ -c
LINK	 = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DFLAGS	 = #-g -fsanitize=address
RM_FILE	 = rm -f

# **************************************************************************** #
#RULES
# **************************************************************************** #

%.o : %.cpp Makefile Account.hpp
	@$(COMPILE) $(DFLAGS) $(CXXFLAGS) -o $@ $<
	@ECHO "Compiling... $<"

all: $(NAME)

$(NAME): $(OBJ)
	@$(LINK) $(DFLAGS) $(CXXFLAGS) -o $@ $^
	@ECHO "Created binary $(NAME) (mandatory)"

clean:
	@$(RM_FILE) $(OBJ)

fclean: clean
	@$(RM_FILE) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re