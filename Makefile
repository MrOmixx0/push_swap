CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = push_swap



LIB_PATH =	libft

SRC_PATH =	src

OBJ_PATH =	obj



LIB_NAME =	libft.a

SRC_NAME =	main.c stack_utils.c operations.c radix_sort.c utils.c utils2.c sort_utils.c ranking.c

OBJ_NAME = $(SRC_NAME:.c=.o)



INC =	libft/include/libft.h 			\
		libft/include/get_next_line.h	\
		libft/include/ft_printf.h

SRC =	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ =	$(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

LIB =	$(addprefix $(LIB_PATH)/, $(LIB_NAME))

INC_FLAGS =	-Iinclude -Ilibft/include/



all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_PATH)
	$(CC) $(OBJ) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@$(CC) $(FLAGS) -o $@ -c $< $(INC_FLAGS)
	@echo $<
	
clean:
	$(MAKE) -C $(LIB_PATH) fclean
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
