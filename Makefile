NAME	:= push_swap

# Compiler settings
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Libft settings
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

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

# Object files
OBJS	:= $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Linking step: create the executable from object files
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Remove object files + the executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
