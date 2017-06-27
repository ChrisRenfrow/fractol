/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:06:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/18 08:47:04 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	view->schemes = (t_cscheme*)malloc(sizeof(t_cscheme));
	get_schemes(view);
	view->scheme_id = 0;
	view->mouse = init_mouse();
	view->max_iter = 10;
	view->pressed = (t_keys *)ft_memalloc(sizeof(t_keys));
	return (view);
}
