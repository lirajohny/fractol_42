NAME = fractol
SRC = $(wildcard *.c)
OBJS = ${SRC:.c=.o}
CC = clang
CFLAG = -Wall -Wextra -Werror -g
MLX = minilibx-linux/libmlx.a  -l Xext -l X11 -l m -l bsd

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I . -I minilibx-linux -c $< -o $(<:.c=.o)

bonus: all

$(NAME): $(LIBRARY) $(OBJS)
	make -C minilibx-linux
	gcc -Wall -Werror -Wextra $(SRC) minilibx-linux/libmlx.a -lXext -lX11 -lm -o fractol

clean:
	make -C minilibx-linux clean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PYTHON: all clean fclean re 
