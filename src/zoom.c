/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:07:56 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 12:01:19 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_view *view, int x, int y, float factor)
{
	float	zoom;
	float	diff;
	float	offset_x;
	float	offset_y;

	zoom = view->apt * factor;
	diff = zoom - view->apt;
	offset_x = (((float)((WIN_X / 2) - x) / WIN_X) * diff);
	offset_y = (((float)((WIN_Y / 2) - y) / WIN_Y) * diff);
	view->x_offset += offset_x;
	view->y_offset += offset_y;
	view->apt = zoom;
}
