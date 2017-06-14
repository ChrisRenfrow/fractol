/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 12:37:06 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/14 12:38:36 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_view *view)
{
	int row;
	char **strs = ft_strsplit("Key-commands:\n - h : brings up this window\n - 1 : displays statistics\n - mouse movement : modifies\n   fractal\n - escape : exit program\n(press h to dismiss)", '\n');

	row = -1;
	while(strs[++row])
	{
		mlx_string_put(view->mlx, view->window,
			WIN_X - 300,
			0 + row * 20,
			rgb_to_hex(255,255,255),
			strs[row]);
	}
}

void	print_coords_at_mouse(t_view *view)
{
	char *str = (char*)malloc(sizeof(char));

	sprintf(str, "%d, %d", view->mouse->x, view->mouse->y);
	mlx_string_put(view->mlx, view->window,
	 (view->mouse->x + 100 > WIN_X) ? view->mouse->x - 90 : view->mouse->x + 10,
	 (view->mouse->y + 100 > WIN_Y) ? view->mouse->y - 20 : view->mouse->y + 10,
	 rgb_to_hex(255, 255, 255),
	 str);
}
