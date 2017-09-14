/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:39:20 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 18:48:47 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	*init_rgb(t_ui r, t_ui g, t_ui b)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)malloc(sizeof(t_rgb));
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

int		rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

t_rgb	*hex_to_rgb(unsigned int hex)
{
	t_rgb	*rgb;

	rgb = init_rgb(0, 0, 0);
	rgb->r = ((hex & 0xFF0000) >> 16);
	rgb->g = ((hex & 0xFF00) >> 8);
	rgb->b = (hex & 0xFF);
	return (rgb);
}

t_rgb	*init_default_colors(void)
{
	t_rgb *colors;

	colors = (t_rgb*)malloc(sizeof(t_rgb) * 5);
	colors[0] = *init_rgb(68, 202, 255);
	colors[1] = *init_rgb(62, 232, 222);
	colors[2] = *init_rgb(81, 255, 181);
	colors[3] = *init_rgb(62, 232, 98);
	colors[4] = *init_rgb(113, 255, 81);
	return (colors);
}

t_rgb	color_for_escape(t_view *view, int vel)
{
	return (view->colors[vel % 5]);
}
