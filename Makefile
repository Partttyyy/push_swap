CC = cc
CFLAGS =-Wall -Wextra -Werror
INCLUDE = -I.libft
NAME = push_swap
SOURCES = utils/input_validation.c utils/op1.c utils/op2.c utils/op3.c utils/utils1.c utils/utils2.c \
 main.c utils/new_op1.c output1.c small_sort.c output2.c utils/utils_exit.c merge_sort1.c merge_sort2.c \
 utils/utils_sorting.c utils/utils_init.c
NORMS = utils/input_validation.c utils/op1.c \
 main.c \
 merge_sort1.c merge_sort2.c utils/op2.c utils/op3.c utils/utils1.c utils/utils2.c utils/new_op1.c small_sort.c output1.c output2.c utils/utils_exit.c utils/utils_sorting.c utils/utils_init.c 

NAME_BONUS = checker
OBJECTS = $(SOURCES:.c=.o)
SOURCES_BONUS:= $(filter-out main.c, $(SOURCES)) bonus/op_bonus/op1.c bonus/op_bonus/op2.c\
 bonus/op_bonus/op3.c bonus/main.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
LDFLAGS = -L./libft -libft
LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)


all: $(NAME)

$(NAME): full 
	$(MAKE) -C $(LIBFT_DIR) clean

full: $(LIBFT_PATH) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)
	cp $(NAME) push_swap_visualizer/build/bin/push_swap
	chmod +x push_swap_visualizer/build/bin/push_swap

$(LIBFT_PATH):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_PATH) $(LIBFT)

libft: $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBFT) push_swap_visualizer/build/bin/push_swap $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(LIBFT_PATH) $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS_BONUS) -o $(NAME_BONUS)

norm:
	norminette $(NORMS)
	cp $(LIBFT_PATH) $(NAME)


#libft_make: 
#	$(MAKE) -C $(LIBFT_DIR)