/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/09 21:50:29 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void reset(t_view *view)
{
	view->mouse->x = 0;
	view->mouse->y = 0;
	view->x_offset = -5;
	view->y_offset = 0;
	view->apt = 2;
}

static int eval_pt(t_view *view, double x, double y)
{
	int    i;
	double x0 = x;
	double y0 = y;

	double tmp;

	i = -1;
	x = (double)((view->mouse->x - (WIN_X / 2)) / WIN_X);
	y = (double)((view->mouse->y - (WIN_Y / 2)) / WIN_Y);

	x0 = ((x0 / WIN_X) * view->apt) + (view->x_offset / view->apt) - (view->apt * 0.5);
	y0 = ((y0 / WIN_Y) * view->apt) + (view->y_offset / view->apt) - (view->apt * 0.5);

	while ((++i < view->iter) && ((x * x) + (y * y) < 4))
	{
		tmp = (x * x) - (y * y) + x0;
		y = (2 * x * y) + y0;
		x = tmp;
	}
	return (i);
}

static void eval_rows(t_thread *t)
{
	int x;
	int y;
	int i;

	i = 0;
	y = ((WIN_Y / THREAD_COUNT) * t->id) - 2;
	while (++y < ((WIN_Y / THREAD_COUNT) * (t->id + 1)))
	{
		x = -1;
		while (++x < WIN_X)
		{
			i = eval_pt(t->view, x, y);
			if (i < t->view->iter)
				draw_point_image(t->view, x, y, color_for_escape(t->view, i));
		}
	}
}

static void draw(t_view *view)
{
	int			i;
	pthread_t	threads[THREAD_COUNT];

	i = -1;
	while (++i < THREAD_COUNT)
		threads[i] = new_thread(view, i, (void*)eval_rows);
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(threads[i], NULL);
	image_to_view(view, view->image->ptr);
}

void start_mandel(void)
{
	t_view *view;

	view = init_view("Mandelbrot");
	view->draw_func = draw;
	view->reset_func = reset;
	set_hooks(view);
	mlx_loop(view->mlx);
}
