CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line_utils.c get_next_line.c ft_printf.c ft_printf_handle_c.c ft_printf_handle_di.c \
 ft_printf_handle_u.c ft_printf_handle_p.c ft_printf_handle_percent.c ft_printf_handle_s.c \
 ft_printf_handle_x.c ft_printf_handle_xx.c ft_expo.c ft_strcmp.c ft_iswhitespace.c
BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(BONUS_SOURCES:.c=.o)

$(NAME): all

all: bonus
#$(OBJECTS)
#ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS) $(OBJECTS)
	ar rcs $(NAME) $< $^
