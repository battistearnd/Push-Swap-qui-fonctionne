CC = cc

CFLAGS =-Wall -Werror -Wextra

NAME = push_swap

SRC = main.c call_function.c\
	check_arg.c check_arg_utils.c split.c parsing_split.c\
	initialisation.c utils.c split_init.c leak.c\
	stack_utils.c \
	swap.c push.c rotate.c reverse_rotate.c \
	sort_three.c sort.c \
	position.c get_cost.c do.c \

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRCS:.c=.o)

INCLUDE = -I ./include/

all : $(NAME)



.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re