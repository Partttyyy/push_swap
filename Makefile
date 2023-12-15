CC = cc
CFLAGS =-Wall -Wextra -Werror
INCLUDE = -I.libft
NAME = push_swap
SOURCES = utils/input_validation.c utils/op1.c utils/op2.c utils/op3.c utils/utils1.c utils/utils2.c \
 main.c utils/new_op1.c output1.c small_sort.c output2.c utils/utils_exit.c merge_sort1.c merge_sort2.c \
 utils/utils_sorting.c utils/utils_init.c
NAME_CHECKER = checker
OBJECTS = $(SOURCES:.c=.o)
SOURCES_CHECKER:= $(filter-out main.c, $(SOURCES)) checker_dir/op_checker/op1.c checker_dir/op_checker/op2.c\
 checker_dir/op_checker/op3.c checker_dir/main.c
OBJECTS_CHECKER = $(SOURCES_CHECKER:.c=.o)
LDFLAGS = -L./libft -libft
LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)

all: $(NAME)

$(NAME): full 
	$(MAKE) -C $(LIBFT_DIR)

full: $(LIBFT_PATH) $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)

$(LIBFT_PATH):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_PATH) $(LIBFT)

libft: $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS) $(OBJECTS_CHECKER) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(LIBFT) push_swap_visualizer/build/bin/push_swap $(NAME_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

checker: $(LIBFT_PATH) $(OBJECTS_CHECKER)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS_CHECKER) -o $(NAME_CHECKER)

re_checker: fclean checker