/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:52:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 16:03:17 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
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
	t_image		*image;
	char		*title;
	float		scale;
	float		x_shift;
	float		y_shift;
	t_keys		*pressed;
}				t_view;

void			usage(void);
void			ft_error(char *err);
void			ft_warning(char *warn);

t_rgb			*init_rgb(t_ui r, t_ui g, t_ui b);
int				rgb_to_hex(int r, int g, int b);
t_rgb			*hex_to_rgb(t_ui hex);

void			draw_point_view(t_view *view, float x, float y);
t_view			*init_view(char *win_title);
void			init_image(t_view *view);

void			start_julia(void);

void			redraw(t_view *view);
void			set_hooks(t_view *view);

#endif
