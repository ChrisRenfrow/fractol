/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:06:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/09 21:47:09 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_view *init_view(char *win_title)
{
	t_view *view;

	view = (t_view *) malloc(sizeof(t_view));
	if (!(view->mlx = mlx_init()))
		ft_error("Initializing mlx - Not enough memory");
	view->title = ft_strjoin(TITLE, win_title);
	if (!(view->window = mlx_new_window(view->mlx, WIN_X, WIN_Y, view->title)))
		ft_error("Initializing window - Not enough memory");
	init_image(view);
	view->schemes = ft_lstnew(NULL, sizeof(t_cscheme));
	view->scheme_id = 0;
	view->scheme_ct = 0;
	get_schemes(view);
	view->help = 0;
	view->stat = 0;
	view->freeze = 0;
	view->x_offset = 0;
	view->y_offset = 0;
	view->apt = 2;
	view->mouse = init_mouse();
	view->iter = 25;
	view->max_iter = 250;
	view->pressed = (t_keys *) ft_memalloc(sizeof(t_keys));
	view->update = 1;
	return (view);
}
