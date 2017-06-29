/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:24:52 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/29 13:44:22 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cscheme	*init_scheme(void)
{
	t_cscheme	*sch;

	sch = (t_cscheme *)malloc(sizeof(t_cscheme));
	sch->color_ct = 0;
	sch->colors = ft_lstnew(NULL, sizeof(t_rgb));
	return (sch);
}

t_rgb		color_for_escape(t_view *view, int vel)
{
	t_cscheme *sch = (t_cscheme *)ft_lstget(&view->schemes, vel)->content;
	t_rgb color = *(t_rgb *)ft_lstget(&sch->colors,
		(view->max_iter / vel) * sch->color_ct)->content;
	return (color);
}
