/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_linux.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouguet <lbouguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:27:32 by lbouguet          #+#    #+#             */
/*   Updated: 2024/03/28 17:55:47 by lbouguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_LINUX_H
# define FRACTOL_LINUX_H

# include "../minilibx-linux/mlx.h"
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "stdio.h"
# include "math.h"

# define ERROR_MSG1 "Error, try this: ./fractol <Fractalname> [juliaVar].\n"
# define ERROR_MSG2 "Fractals are \"Julia\" \"Mandelbrot\" \"BurningShip\".\n"
# define ERROR_MSG3 "Julia variants are \"neuron\" \"brain\" \"galaxy\".\n"
# define ERROR_MSG4 "No Mandelbrot nor Burninship variant exist.\n"

# define CORRECT 0
# define WRONG 1

# define JULIA 1
# define MANDELBROT 2
# define BURNINGSHIP 3

# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17
# define BUTTONPRESSMASK 04
# define KEYRELEASEMASK 02

# define WHEELDOWN 5
# define WHEELUP 4
# define WHEELCLICK 2
# define REALINCR 114
# define REALDECR 102
# define IMAINCR 105
# define IMADECR 107
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define SPACE 32
# define ESC 65307
# define ENTER 65293
# define TAB 65289

typedef struct s_arlequin
{
	int		hue;
	float	saturation;
	float	value;
	float	color;
	float	x;
	float	m;
	int		red255;
	int		green255;
	int		blue255;
}		t_arlequin;

typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	op;
	float			r;
	float			g;
	float			b;
	int				color_idx;
}					t_color;
typedef struct s_zoom
{
	double	prev_x1;
	double	prev_y1;
	double	prev_zoom;
	double	zoom_factor;
	double	zoom_offset_x;
	double	zoom_offset_y;
	double	new_zoom;
}			t_zoom;

typedef struct s_image
{	
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;

}			t_image;

typedef struct s_fractal
{
	double		x;
	double		y;
	double		x1;
	float		x2;
	double		y1;
	double		y2;
	int			win_width;
	int			win_height;
	int			x_im;
	int			y_im;
	double		tempr;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		zoom;
	int			iter_max;
	int			name;
	char		variant;
	int			color;
	int			flag;
	int			idx;
	void		*mlx;
	void		*win;
	t_image		im;
	t_color		c;
	t_zoom		zm;
	int			scale_im;
}				t_fractal;

void			burningship(t_fractal *f);
unsigned int	color(int iteration, t_fractal *f);
unsigned int	render_color3(int iteration, t_fractal *f);
unsigned int	render_color2(int iteration, t_fractal *f);
unsigned int	render_color(int iter, t_fractal *f);
int				shutwindow(t_fractal *t);
int				julia(t_fractal *f);
int				init_julia(t_fractal *f);
int				init_mandelbrot(t_fractal *f);
int				parsing(int ac, char **av, t_fractal *f);
int				init_burningship(t_fractal *f);
int				handle_mouse(int button, int x, int y, t_fractal *f);
int				handle_key(int button, t_fractal *f);
void			mandelbrot(t_fractal *f);
void			julia_var(t_fractal *f);
void			img_pix_put(t_image *img, int x, int y, int color);
void			user_input(t_fractal *f, char **av);
void			orange(t_fractal *f);
void			yellow(t_fractal *f);
void			violet(t_fractal *f);
void			thistle(t_fractal *f);

#endif
