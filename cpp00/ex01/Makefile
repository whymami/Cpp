NAME = phonebook

SRCS = phonebook.cpp phonebook_utils.cpp contact.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re