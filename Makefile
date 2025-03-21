NAME = push_swap
B_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_DIR = ./libft/
SETUP_DIR = ./setup/
OPER_DIR = ./operations/
SORT_DIR = ./mandatory/
BONUS_DIR = ./bonus/
LIB_FT = -L$(LIBFT_DIR) -lft

INCLUDES = -I$(LIBFT_DIR) -I$(SETUP_DIR) -I$(SORT_DIR) -I$(OPER_DIR)

SRCS = $(SETUP_DIR)/validation.c $(SETUP_DIR)/initialization.c \
       $(OPER_DIR)operations.c $(OPER_DIR)utils.c $(SORT_DIR)small_data.c \
       $(SORT_DIR)big_data.c $(SORT_DIR)push_swap.c
OBJS = $(SRCS:.c=.o)

B_SRCS = $(SETUP_DIR)validation.c $(SETUP_DIR)initialization.c \
	 $(OPER_DIR)operations.c $(OPER_DIR)utils.c \
	 $(BONUS_DIR)push_swap_bonus.c $(BONUS_DIR)utils.c \
	 $(BONUS_DIR)get_next_line_utils.c $(BONUS_DIR)get_next_line.c
B_OBJS = $(B_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT_DIR)libft.a $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIB_FT) -o $(NAME)

bonus:	 $(LIBFT_DIR)libft.a $(B_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(B_OBJS) $(LIB_FT) -o $(B_NAME)

$(LIBFT_DIR)libft.a:
	$(MAKE) -C $(LIBFT_DIR) bonus

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	

fclean: clean
	rm -f $(NAME) $(B_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

