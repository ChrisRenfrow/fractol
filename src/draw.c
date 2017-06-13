/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:42:07 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 15:44:09 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_point_view(t_view *view, float x, float y)
{
	if (x > 0 && y > 0 && x < WIN_X && y < WIN_Y)
	{
		mlx_pixel_put(view->mlx, view->window, x, y,
			rgb_to_hex(255, 255, 255));
	}
}
