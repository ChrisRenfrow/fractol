/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:06:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/15 21:17:37 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mbutton *init_mbutton(void)
{
	t_mbutton *mbuttons = (t_mbutton*)malloc(sizeof(t_mbutton));
	mbuttons->one = 0;
	mbuttons->two = 0;
	mbuttons->three = 0;
	mbuttons->scroll_up = 0;
	mbuttons->scroll_down = 0;
	return (mbuttons);
}

t_mouse	*init_mouse(void)
{
	t_mouse *mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	mouse->x = 0;
	mouse->y = 0;
	mouse->button = init_mbutton();
	return(mouse);
}

t_view	*init_view(char *win_title)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	if (!(view->mlx = mlx_init()))
		ft_error("Initializing mlx - Not enough memory");
	view->title = ft_strjoin(TITLE, win_title);
	if (!(view->window = mlx_new_window(view->mlx, WIN_X, WIN_Y, view->title)))
		ft_error("Initializing window - Not enough memory");
	init_image(view);
	get_schemes(view);
	view->mouse = init_mouse();
	view->scale = 0.5;
	view->x_shift = 0;
	view->y_shift = 0;
	view->pressed = (t_keys *)ft_memalloc(sizeof(t_keys));
	return (view);
}
