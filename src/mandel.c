/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:10:22 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/13 15:00:39 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	start_mandel(void)
{
	t_view *view;

	view = init_view("Mandelbrot");
	set_hooks(view);
	mlx_loop(view->mlx);
}
