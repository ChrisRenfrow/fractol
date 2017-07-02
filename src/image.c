/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:41:12 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 19:47:58 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_image(t_view *view)
{
	t_image *image;

	image = (t_image *) malloc(sizeof(t_image));
	if (!(image->ptr = mlx_new_image(view->mlx, WIN_X, WIN_Y)))
		ft_error("Initializing image - Not enough memory");
}
