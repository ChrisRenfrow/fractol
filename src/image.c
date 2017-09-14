/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:41:12 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 19:20:44 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_view *view)
{
	t_image *img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		ft_error("Initializing image - Not enough memory");
	view->image = img;
	reset_image(view);
}

void	reset_image(t_view *view)
{
	t_image *img;

	img = view->image;
	img->ptr = mlx_new_image(view->mlx, WIN_X, WIN_Y);
	img->pixels = (unsigned int *)mlx_get_data_addr(img->ptr,
		&(img->bits_per_pixel), &(img->size_line), &(img->endian));
}

void	image_to_view(t_view *view, void *image)
{
	mlx_put_image_to_window(view->mlx, view->window, image, 0, 0);
	mlx_destroy_image(view->mlx, image);
	reset_image(view);
}

void	draw_point_image(t_view *view, int x, int y, t_rgb color)
{
	int i;

	i = (x + ((y * view->image->size_line) / 4));
	if (i >= 0 && i < (WIN_X * WIN_Y))
		view->image->pixels[i] = rgb_to_hex(color.r, color.b, color.g);
}
