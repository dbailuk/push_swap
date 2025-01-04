NAME	:= push_swap

# Compiler settings
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Source files
SRCS	:=	src/main.c \
			src/parse_args.c \
			src/index.c \
			src/check_sort.c \
			src/sort_small.c \
			src/quick_sort.c \
			src/list_utils.c \
			src/sort_utils.c \
			src/ops/push_ops.c \
			src/ops/reverse_rotate_ops.c \
			src/ops/rotate_ops.c \
			src/ops/swap_ops.c

# Object files (same names but .o instead of .c)
OBJS	:= $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Linking step: create the executable from object files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files + the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
