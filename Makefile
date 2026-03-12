NAME = klein_gordon

CC = g++
CPP_FLAGS = -Wall -Wextra -Werror

OBJ_DIR = ./obj/
SRC_DIR = ./src/
INC_DIR = ./include/

SRC = algo.cpp test_algo.cpp init.cpp utils.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPP_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPP_FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re