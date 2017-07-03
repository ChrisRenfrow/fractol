/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/03 16:15:26 by crenfrow         ###   ########.fr       */
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
			if (i < t->view->max_iter)
				draw_point_image(t->view, x, y, *init_rgb(i * 10, i * 10, i * 10));
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
	ft_lstiter(view->schemes, &prt_scheme_lst);
	view->draw_func = draw;
	view->reset_func = reset;
	set_hooks(view);
	mlx_loop(view->mlx);
}
