/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:52:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/15 21:28:50 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "keys.h"
# include "mouse.h"
# include "mlx.h"
# include <fcntl.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <math.h>

# define TITLE			"Fract'ol - "
# define WIN_RES		720.0
# define WIN_X			WIN_RES / (3.0 / 4.0)
# define WIN_Y			WIN_RES
# define X_CENTER		WIN_X / 2
# define Y_CENTER		WIN_Y / 2

# define RANGE_CHANGE(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)

# define AVAILABLE "Available options:\n- julia\n- mandelbrot\n- ..."

typedef unsigned int	t_ui;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct	s_cscheme
{
	char 		*title;
	int			color_ct;
	t_rgb		**colors;
}				t_cscheme;

typedef struct	s_pt2D
{
	float		x;
	float		y;
}				t_pt2D;

typedef struct		s_image
{
	void			*ptr;
	unsigned int	*pixels;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct	s_view
{
	void		*mlx;
	void		*window;
	void		*guiwin;
	t_image		*image;
	char		*title;
	t_list		*schemes;
	float		scale;
	float		x_shift;
	float		y_shift;
	int			update:1;
	int			help:1;
	int			stat:1;
	t_mouse		*mouse;
	t_keys		*pressed;
}				t_view;

void	usage(void);
void	ft_error(char *err);
void	ft_warning(char *warn);
int		check_ext(char *path, char *ext);

t_rgb	*init_rgb(t_ui r, t_ui g, t_ui b);
int		rgb_to_hex(int r, int g, int b);
t_rgb	*hex_to_rgb(t_ui hex);

void	get_schemes(t_view *view);

void	draw_point_view(t_view *view, float x, float y, int color);
t_view	*init_view(char *win_title);
void	init_image(t_view *view);

void	start_julia(void);
void	start_mandel(void);

void	redraw(t_view *view);
void	set_hooks(t_view *view);

int		expose_hook(t_view *view);
int		exit_hook(t_view *view);

int		mouse_press_hook(int mb_code, int x, int y, t_view *view);
int		mouse_release_hook(int mb_code, int x, int y, t_view *view);
int		motion_hook(int x, int y, t_view *view);

int		key_press_hook(int keycode, t_view *view);
int		key_release_hook(int keycode, t_view *view);

void	print_help(t_view *view);
void	print_coords_at_mouse(t_view *view);

#endif
