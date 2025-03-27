NAME = fractol
CC = cc
CFLAGS = -Wextra -Wall -Werror
RM = rm
RMFLAGS = -f
MAKE = make

# SOURCES
SRCS = $(addprefix srcs/, $(SRCS_FILES))
SRCS_FILES = main.c \
			 print.c \
			 $(COLORS) \
			 $(FRACTALS) \
			 $(MY_MLX) \
			 $(MOTIONS)
OBJS = $(SRCS:.c=.o)

#  COLORS
COLORS = $(addprefix colors/, $(COL_FILES))
COL_FILES = palettes.c \
			trgb.c \
			utils.c \
			wacced.c

#  FRACTALS
FRACTALS = $(addprefix fractals/, $(FRACT_FILES))
FRACT_FILES = burning_ship.c \
			  julia.c \
			  julia_checks.c \
			  mandelbrot.c \
			  utils.c

#  MY_MLX
MY_MLX = $(addprefix mlx/, $(MY_MLX_FILES))
MY_MLX_FILES = event_handling.c \
	       mlx_utils.c

#  MOTIONS
MOTIONS = $(addprefix motions/, $(MOT_FILES))
MOT_FILES = move.c \
			zoom.c

# INCLUDES
HEADERS = incl/fractol.h
LIBFT = libft/libft.a

# MINILIBX
MLX_FLAGS = -L$(MLX) -lmlx
UNAME = $(shell uname)
ifeq ($(UNAME), Darwin)
	MLX = /Users/ivo/Library/MiniLibX
	MLX_FLAGS += -framework OpenGL -framework AppKit
	MLX_INCL = -I/Users/ivo/Library/MiniLibX
else
	MLX = /home/imeulema/libs/MiniLibX
	MLX_FLAGS += -lXext -lX11 -lm
	MLX_INCL = -I/home/imeulema/libs/MiniLibX -Imlx_linux
endif

# TERMINAL COLORS
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RESET = \033[0m

# RULES
all: $(LIBFT) $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	echo "$(GREEN)Fract-ol compiled!$(RESET)"

%.o: %.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_INCL) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft --no-print-directory

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(MAKE) clean -C libft --no-print-directory

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) fclean -C libft --no-print-directory
	echo "$(GREEN)Full clean done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
