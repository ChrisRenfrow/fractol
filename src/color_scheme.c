/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:24:52 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/06 15:20:09 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void change_scheme(t_view *view, int id)
{
	if (id >= 0 && id < view->scheme_ct)
		view->scheme_id = id;
	else if (id < 0)
		view->scheme_id = view->scheme_ct - 1;
	else if (id >= view->scheme_ct)
		view->scheme_id = 0;
	t_list *l = ft_lstget(&view->schemes, view->scheme_id);

	if (l->content)
		printf("%d/%d\n", view->scheme_id, view->scheme_ct);
	else
		printf("bad - %d/%d\n", view->scheme_id, view->scheme_ct);
}

t_cscheme *init_scheme(void)
{
	t_cscheme *sch;

	sch = (t_cscheme *) malloc(sizeof(t_cscheme));
	sch->color_ct = 0;
	sch->colors = ft_lstnew(NULL, sizeof(t_rgb));
	return (sch);
}

t_rgb color_for_escape(t_view *view, int vel)
{
	t_cscheme *sch;
	t_rgb      color;

	color = *init_rgb(vel * 10, vel * 10, vel * 10);
	sch = (t_cscheme *)ft_lstget(&view->schemes, view->scheme_id)->content;
	if (sch)
	{
		color = *(t_rgb *) ft_lstget(&sch->colors, sch->color_ct)->content;
	}
	return (color);
}
