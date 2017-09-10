/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:02:17 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/09 21:55:43 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void redraw(t_view *view)
{
	void (*f)(t_view *);

	if (view->update)
	{
		mlx_clear_window(view->mlx, view->window);
		f = (void (*)(t_view *))(view->draw_func);
		f(view);
		if (view->help)
			print_help(view);
		if (view->stat)
			print_stats_at_mouse(view);
		view->update = 0;
	}
}

void reset_view(t_view *view)
{
	void (*f)(t_view *);

	f = (void (*)(t_view *))(view->reset_func);
	f(view);
	view->update = 1;
}

int key_press_hook(int keycode, t_view *view)
{
	// printf("Key %d pressed in %s instance - PID %d\n", keycode, view->title,
	// getpid());
	if (keycode == 53)
		exit_hook(view);
	if (keycode == KEY_H)
		view->help = (view->help) ? 0 : 1;
	if (keycode == KEY_ONE)
		view->stat = (view->stat) ? 0 : 1;
	if (keycode == KEY_UP)
		change_scheme(view, view->scheme_id + 1);
	if (keycode == KEY_DOWN)
		change_scheme(view, view->scheme_id - 1);
	if (keycode == KEY_R)
		reset_view(view);
	if (keycode == KEY_SPACE)
		view->freeze = (view->freeze) ? 0 : 1;
	if (keycode == KEY_STDEQU)
		view->iter = (view->iter + 1 > view->max_iter) ? view->max_iter : view->iter + 1;
	if (keycode == KEY_STDMIN)
		view->iter = (view->iter - 1 < 0) ? view->max_iter : view->iter - 1;
	view->update = 1;
	return (0);
}

int key_release_hook(int keycode, t_view *view)
{
	(void) keycode;
	(void) view;
	// printf("Key %d released in %s instance - PID %d\n", keycode, view->title,
	// getpid()); toggle_pressed(keycode, view, 0);
	return (0);
}
