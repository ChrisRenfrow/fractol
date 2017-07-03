/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/03 11:31:31 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void reset(t_view *view)
{
	view->mouse->x = 0;
	view->mouse->y = 0;
}

static int eval_pt(t_view *view, double re, double im)
{
	int    i;
	double x;
	double y;
	double tmp;

	i = -1;
	x = (double)(view->mouse->x * -0.001);
	y = (double)(view->mouse->y * -0.001);
	re = ((re / WIN_X) * 2.8) + (-3 / 2) - (2.8 * 0.5);
	im = ((im / WIN_Y) * 2.8) + (0.0 / 2) - (2.8 * 0.5);
	while ((++i < view->max_iter) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x) - (y * y) + re;
		y = (2 * x * y) + im;
		x = tmp;
	}
	return (i);
}

static void eval_rows(t_view *view)
{
	int x;
	int y;
	int i;

	i = 0;
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			i = eval_pt(view, x, y);
			if (i < view->max_iter)
				draw_point_image(view, x, y, *init_rgb(i * 10, i * 10, i * 10));
		}
	}
	image_to_view(view, view->image->ptr);
}

void start_mandel(void)
{
	t_view *view;

	view = init_view("Mandelbrot");
	ft_lstiter(view->schemes, &prt_scheme_lst);
	view->draw_func = eval_rows;
	view->reset_func = reset;
	set_hooks(view);
	mlx_loop(view->mlx);
}
