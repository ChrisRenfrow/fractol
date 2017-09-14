/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:00:00 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 11:21:24 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mbutton	*init_mbutton(void)
{
	t_mbutton	*mbuttons;

	mbuttons = (t_mbutton *)malloc(sizeof(t_mbutton));
	mbuttons->one = 0;
	mbuttons->two = 0;
	mbuttons->three = 0;
	mbuttons->scroll_up = 0;
	mbuttons->scroll_down = 0;
	return (mbuttons);
}

t_mouse		*init_mouse(void)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	mouse->x = 0;
	mouse->y = 0;
	mouse->button = init_mbutton();
	return (mouse);
}

int			mouse_press_hook(int mb_code, int x, int y, t_view *view)
{
	if (mb_code == MOUSE_ONE)
	{
		view->iter = (view->iter + 1 > view->max_iter) ?
			view->max_iter : view->iter + 1;
	}
	if (mb_code == MOUSE_TWO)
		view->iter = (view->iter - 1 < 0) ? view->max_iter : view->iter - 1;
	if (mb_code == MOUSE_THREE)
		;
	if (mb_code == MOUSE_SCROLL_UP)
		zoom(view, x, y, 0.9);
	if (mb_code == MOUSE_SCROLL_DOWN)
		zoom(view, x, y, 1.1);
	view->update = 1;
	return (0);
}

int			mouse_release_hook(int mb_code, int x, int y, t_view *view)
{
	(void)mb_code;
	(void)x;
	(void)y;
	(void)view;
	return (0);
}

int			motion_hook(int x, int y, t_view *view)
{
	if ((x >= 0 && x <= WIN_X) && (y >= 0 && y <= WIN_Y))
	{
		if (!view->freeze)
		{
			view->mouse->x = x;
			view->mouse->y = y;
			view->update = 1;
		}
	}
	return (0);
}
