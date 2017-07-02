/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:39:32 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/02 14:52:17 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void reset(t_view *view)
{
	view->mouse->x = 0;
	view->mouse->y = 0;
}

static int eval_pt(t_view *view, double x, double y)
{
	int    i;
	double re;
	double im;
	double tmp;

	i = 0;
	x = ((x / WIN_X) * 3) - 1.1 - (3 * 0.5);
	y = ((y / WIN_X) * 3) - 0.5 - (3 * 0.5);
	re = ((view->mouse->x - (WIN_X / 2)) / WIN_X);
	im = ((view->mouse->y - (WIN_Y / 2)) / WIN_Y);
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
				draw_point_view(view, x, y, color_for_escape(view, i));
		}
	}
}

void start_julia(void)
{
	t_view *view;

	view = init_view("Julia");
	view->draw_func = eval_rows;
	view->reset_func = reset;
	set_hooks(view);
	mlx_loop(view->mlx);
}
