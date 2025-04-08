NAME = internform

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = $(wildcard *.cpp)
SHRUB = Shrubbery_shrubbery
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(OBJ): %.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(SHRUB)

re: fclean all