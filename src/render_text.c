/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 12:37:06 by crenfrow          #+#    #+#             */
/*   Updated: 2017/09/13 19:28:14 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(t_view *view)
{
	int		row;
	char	**strs;

	strs = ft_strsplit("Key-commands:\n\
		- h : brings up this window\n\
		- 1 : displays statistics\n\
		- mouse movement : modifies\n\
			real and imaginary numbers\n\
		- mouse scroll : zoom in/out\n\
		- left/right click : increase\n\
			/decrease iterations (max\n\
			250 iterations)\n\
		- WASD : pans view\n\
		- space : toggles mouse\n\
			movement\n\
		- r : reset view\n\
		- escape : exit program\n\
		(press h to dismiss)",
		'\n');
	row = -1;
	while (strs[++row])
	{
		mlx_string_put(view->mlx, view->window, WIN_X - 300, row * 20,
			rgb_to_hex(255, 255, 255), strs[row]);
	}
}

void	print_stats_at_mouse(t_view *view)
{
	int		row;
	int		x;
	int		y;
	char	*str;
	char	**strs;

	str = (char *)malloc(sizeof(char) * 1000);
	sprintf(str, "pos: %d, %d\niter: %d/%d\nzoom: %f",
		view->mouse->x, view->mouse->y, view->iter, view->max_iter,
		view->apt / 2);
	strs = ft_strsplit(str, '\n');
	row = -1;
	x = (view->mouse->x + 150 > WIN_X) ?
		view->mouse->x - 135 : view->mouse->x + 10;
	y = (view->mouse->y + 100 > WIN_Y) ?
		view->mouse->y - 65 : view->mouse->y + 10;
	while (strs[++row])
	{
		mlx_string_put(view->mlx, view->window, x, y + (row * 20),
			rgb_to_hex(255, 255, 255), strs[row]);
	}
}
