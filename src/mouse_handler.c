/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:00:00 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/04 11:38:52 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mbutton *init_mbutton(void)
{
	t_mbutton *mbuttons = (t_mbutton *) malloc(sizeof(t_mbutton));
	mbuttons->one = 0;
	mbuttons->two = 0;
	mbuttons->three = 0;
	mbuttons->scroll_up = 0;
	mbuttons->scroll_down = 0;
	return (mbuttons);
}

t_mouse *init_mouse(void)
{
	t_mouse *mouse;

	mouse = (t_mouse *) malloc(sizeof(t_mouse));
	mouse->x = 0;
	mouse->y = 0;
	mouse->button = init_mbutton();
	return (mouse);
}

void toggle_mouse(int mb_code, int toggle, t_view *view)
{
	if (mb_code == MOUSE_ONE)
		view->mouse->button->one = toggle;
	if (mb_code == MOUSE_TWO)
		view->mouse->button->two = toggle;
	if (mb_code == MOUSE_THREE)
		view->mouse->button->three = toggle;
	if (mb_code == MOUSE_SCROLL_UP)
		view->mouse->button->scroll_up = toggle;
	if (mb_code == MOUSE_SCROLL_DOWN)
		view->mouse->button->scroll_down = toggle;
}

int mouse_press_hook(int mb_code, int x, int y, t_view *view)
{
	(void) x;
	(void) y;
	// printf("Mouse %d pressed at %d, %d in %s instance - PID %d\n", mb_code,
	// x, y, view->title, getpid());
	toggle_mouse(mb_code, 0, view);
	view->update = 1;
	return (0);
}

int mouse_release_hook(int mb_code, int x, int y, t_view *view)
{
	(void) x;
	(void) y;
	// printf("Mouse %d released at %d, %d in %s instance - PID %d\n", mb_code,
	// x, y, view->title, getpid());
	toggle_mouse(mb_code, 0, view);
	return (0);
}

int motion_hook(int x, int y, t_view *view)
{
	if ((x >= 0 && x <= WIN_X) && (y >= 0 && y <= WIN_Y))
	{
		// printf("Mouse moved to %d, %d in %s instance - PID %d\n", x, y,
		// view->title, getpid());
		if (!view->freeze)
		{
			view->mouse->x = x;
			view->mouse->y = y;
			view->update = 1;
		}
	}
	return (0);
}
