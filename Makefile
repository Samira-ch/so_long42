CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -g
MLX_FLAGS = -L./mlx -lmlx -lXext -lX11 -lm
SRC =   ft_split.c \
		ft_strjoin.c \
		get_next_line.c \
		main.c \
		keypress.c \
		check_map1.c \
		check_map2.c \
		create_map.c \
		errorhandling.c \
		valid_path.c \
		window.c \
		mainhelper.c \
		function.c\
		player_position.c\
		ft_printf/ft_printf.c \
		ft_printf/ft_putchar.c \
        ft_printf/ft_put_hexadecimal.c\
        ft_printf/ft_putnbr.c\
        ft_printf/ft_putnbr_unsignedint.c\
        ft_printf/ft_putstr.c\
        ft_printf/ft_hexadecimal_pointer.c\
        
OBJ = $(SRC:.c=.o)
EXEC = so_long

all: $(EXEC)

$(EXEC): $(OBJ)
		$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(EXEC) $(LIB)

re: fclean all
.PHONY: all bonus clean fclean re