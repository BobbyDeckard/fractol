/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <imeulema@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:58:14 by imeulema          #+#    #+#             */
/*   Updated: 2025/02/26 15:59:05 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>

// KEY BIND MACROS
# ifdef __APPLE__
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define C_KEY 8
#  define D_KEY 2
#  define E_KEY 14
#  define H_KEY 4
#  define I_KEY 34
#  define M_KEY 43
#  define N_KEY 45
#  define R_KEY 15
#  define U_KEY 32
#  define X_KEY 7
#  define Z_KEY 16
# elif __linux__
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define C_KEY 99
#  define D_KEY 100
#  define E_KEY 101
#  define H_KEY 104
#  define I_KEY 105
#  define M_KEY 109
#  define N_KEY 110
#  define R_KEY 114
#  define U_KEY 117
#  define X_KEY 120
#  define Z_KEY 122
# endif

// VARIOUS MACROS
# define BLACK 0
# define WHITE 16777215
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define RESOLUTION 1080

// STRUCTS
typedef struct s_fract
{
	unsigned int	zoom;
	double			const_x;
	double			const_y;
	double			range;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	float			radius;
	float			radius2;
	int				**palettes;
	int				palette_id;
	int				fract_type;
	int				max_iter;
}	t_fract;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}	t_win;

typedef struct s_img
{
	t_fract	*fract;
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

// FRACTALS
t_fract	init_burning_ship(void);
t_fract	init_mandelbrot(void);
t_fract	init_julia(char **av);
double	scale_x(t_img *img, int x);
double	scale_y(t_img *img, int y);
void	burning_ship(t_img *img);
void	decrease_max_iter(t_img *img);
void	increase_max_iter(t_img *img);
void	julia(t_img *img);
void	mandelbrot(t_img *img);
void	move_down(t_img *img);
void	move_left(t_img *img);
void	move_right(t_img *img);
void	move_up(t_img *img);
void	select_fractal(t_img *img);
void	unzoom(t_img *img, int x, int y);
void	zoom(t_img *img, int x, int y);
int		check_params(char **av);

// COLORS
void	change_palette(t_img *img);
void	init_palettes(int **palettes);
void	init_wacced(int *wacced);
void	rev_palette(t_img *img);
int		extract_color(int **palettes, int palette_id,
			int iterations, int max_iter);
int		gen_trgb(int opacity, int red, int green, int blue);

// MLX UTILS
t_img	new_image(t_win *win, int height, int width);
t_win	new_window(int height, int width, char *str);
void	destroy_all(t_img *img);
void	exit_window(t_img *img);
void	hook_events(t_win *win, t_img *img);
void	put_pixel_img(t_img *img, int x, int y, int color);

// PRINTS
void	print_help(void);
void	print_options(void);
void	print_status(t_img *img);

#endif
