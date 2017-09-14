/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:44:23 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 19:23:09 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		reset(t_view *view)
{
	view->mouse->x = 0;
	view->mouse->y = 0;
	view->x_offset = -1.2;
	view->y_offset = -0.6;
	view->iter = 50;
	view->apt = 2.5;
}

static int		eval_pt(t_view *view, double x0, double y0)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = -1;
	x = (double)(view->mouse->x * -0.001);
	y = (double)(view->mouse->y * -0.001);
	x0 = ((x0 / WIN_X) * view->apt) + (view->x_offset) - (view->apt * 0.5);
	y0 = ((y0 / WIN_Y) * view->apt) + (view->y_offset) - (view->apt * 0.5);
	while ((++i < view->iter) && ((x * x) + (y * y) < 4))
	{
		x = fabs(x);
		y = fabs(y);
		tmp = (x * x) - (y * y) + x0;
		y = (2 * x * y) + y0;
		x = tmp;
	}
	return (i);
}

static void		eval_rows(t_thread *t)
{
	int	x;
	int	y;
	int	i;

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

static void		draw(t_view *view)
{
	pthread_t	threads[THREAD_COUNT];
	int			i;

	i = -1;
	while (++i < THREAD_COUNT)
		threads[i] = new_thread(view, i, (void*)eval_rows);
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(threads[i], NULL);
	image_to_view(view, view->image->ptr);
}

void			start_ship(void)
{
	t_view	*view;

	view = init_view("Burning Ship");
	reset(view);
	view->draw_func = draw;
	view->reset_func = reset;
	set_hooks(view);
	mlx_loop(view->mlx);
}
