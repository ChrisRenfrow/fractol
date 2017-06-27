/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:24:52 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/18 08:52:55 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cscheme	*init_scheme(void)
{
	t_cscheme	*sch;

	sch = (t_cscheme *)malloc(sizeof(t_cscheme));
	sch->color_ct = 0;
	sch->colors = (t_rgb*)malloc(sizeof(t_rgb));
	return (sch);
}

t_rgb		color_for_escape(t_view *view, int vel)
{
	t_cscheme sch = view->schemes[view->scheme_id];
	t_rgb color = sch.colors[(view->max_iter / vel) * sch.color_ct];
	return (color);
}
