/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:40:26 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 16:46:59 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_hook(t_view *view)
{
	(void)view;
	exit(0);
}

int		key_press_hook(int keycode, t_view *view)
{
	if (keycode == 53)
		exit_hook(view);
	printf("Key %d pressed in %s instance - PID %d\n", keycode, view->title, getpid());
	return (0);
}

int		key_release_hook(int keycode, t_view *view)
{
	(void)keycode;
	printf("Key %d released in %s instance - PID %d\n", keycode, view->title, getpid());
	// toggle_pressed(keycode, view, 0);
	return (0);
}

void	set_hooks(t_view *v)
{
	mlx_do_key_autorepeatoff(v->mlx);
	// mlx_loop_hook(v->mlx, my_loop_hook, v);
	mlx_hook(v->window, 2, 0, key_press_hook, v);
	mlx_hook(v->window, 3, 0, key_release_hook, v);
	mlx_hook(v->window, 17, 0, exit_hook, v);
}
