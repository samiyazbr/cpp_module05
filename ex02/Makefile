NAME	= form

CPP		= c++

CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC		= main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRC:%.cpp=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re