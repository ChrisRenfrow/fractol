/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/17 19:30:50 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_mandel(void)
{
	t_view *view;

	view = init_view("Mandelbrot");
	view->scheme_id = 0;
	// t_rgb *col = color_for_escape(view, 4);
	// printf("Selected color: %d\n", rgb_to_hex(col->r, col->g, col->b));
	set_hooks(view);
	mlx_loop(view->mlx);
}
