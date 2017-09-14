/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:52:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 18:21:14 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
# define THREAD_COUNT	15

# define RANGE_CHANGE(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)

# define AVAILABLE "Available options:\n- julia\n- mandelbrot\n- burning-ship\n"

typedef unsigned int	t_ui;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_pt2d
{
	float	x;
	float	y;
}				t_pt2d;

typedef struct	s_image
{
	void			*ptr;
	unsigned int	*pixels;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}				t_image;

typedef struct	s_view
{
	void	*mlx;
	void	*window;
	t_image	*image;
	char	*title;
	t_list	*schemes;
	int		scheme_id;
	int		scheme_ct;
	int		iter;
	int		max_iter;
	void	*draw_func;
	void	*reset_func;
	int		update:1;
	int		help:1;
	int		stat:1;
	int		freeze:1;
	double	x_offset;
	double	y_offset;
	double	apt;
	t_mouse	*mouse;
	t_keys	*pressed;
}				t_view;

typedef struct	s_thread
{
	t_view	*view;
	int		id;
}				t_thread;

void			usage(void);
void			ft_error(char *err);
void			ft_warning(char *warn);

void			*ft_arraddend(void *arr, void *elem, size_t size);

t_rgb			*init_rgb(t_ui r, t_ui g, t_ui b);
int				rgb_to_hex(int r, int g, int b);
t_rgb			*hex_to_rgb(t_ui hex);

t_rgb			color_for_escape(t_view *view, int vel);

void			draw_point_view(t_view *view, float x, float y, t_rgb color);
t_view			*init_view(char *win_title);

void			init_image(t_view *view);
void			draw_point_image(t_view *view, int x, int y, t_rgb color);
void			image_to_view(t_view *view, void *image);
void			reset_image(t_view *view);

pthread_t		new_thread(t_view *view, int i, void *func);
void			destroy_thread(t_thread *t);

void			start_julia(void);
void			start_mandel(void);
void			start_ship(void);

void			redraw(t_view *view);
void			set_hooks(t_view *view);

int				expose_hook(t_view *view);
int				exit_hook(t_view *view);

t_mouse			*init_mouse(void);
t_mbutton		*init_mbutton(void);
int				mouse_press_hook(int mb_code, int x, int y, t_view *view);
int				mouse_release_hook(int mb_code, int x, int y, t_view *view);
int				motion_hook(int x, int y, t_view *view);

int				key_press_hook(int keycode, t_view *view);
int				key_release_hook(int keycode, t_view *view);

void			print_help(t_view *view);
void			print_stats_at_mouse(t_view *view);

void			zoom(t_view *view, int x, int y, float factor);

#endif
