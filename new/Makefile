CC = cc
CFLAGS =
INCLUDE = -I.libft
NAME = push_swap
SOURCES = input_validation.c utils/op1.c utils/op2.c utils/op3.c utils/utils1.c utils/utils2.c \
 main.c new_ops/op1.c output1.c
DEBUG = debug/logging.c
OBJECTS = $(SOURCES:.c=.o) $(DEBUG:.c=.o)
LDFLAGS = -L./libft -libft
LIBFT_DIR = ./libft
LIBFT = libft.a
LIBFT_PATH = $(LIBFT_DIR)/$(LIBFT)


all: $(NAME)

$(NAME): full 
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean


full: $(LIBFT_PATH) $(OBJECTS)
	cp $(LIBFT_PATH) $(NAME)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)
	cp $(NAME) push_swap_visualizer/build/bin/push_swap
	chmod 777 push_swap_visualizer/build/bin/push_swap

$(LIBFT_PATH):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_PATH) $(LIBFT)

libft: $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

#libft_make: 
#	$(MAKE) -C $(LIBFT_DIR)