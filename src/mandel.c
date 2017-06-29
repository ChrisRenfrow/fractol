/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/29 13:47:08 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prt_rgb_lst(t_list *elem)
{
	if (elem)
	{
		t_rgb *col = (t_rgb*)elem->content;
		if (col)
			printf(" - %d, %d, %d\n", col->r, col->g, col->b);
	}
}

void	prt_scheme_lst(t_list *elem)
{
	if (elem)
	{
		t_cscheme *sch = (t_cscheme*)elem->content;
		if (sch)
		{
			printf("Color scheme \"%s\" - %dct\n", sch->title, sch->color_ct);
			ft_lstiter(((t_cscheme*)sch)->colors, &prt_rgb_lst);
		}
	}
}

void	start_mandel(void)
{
	t_view *view;

	view = init_view("Mandelbrot");

	ft_lstiter(view->schemes, &prt_scheme_lst);
	set_hooks(view);
	mlx_loop(view->mlx);
}
