NAME = account

CXX = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

SRC = 	tests.cpp\
			Account.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re