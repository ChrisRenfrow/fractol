/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:39:32 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 16:03:19 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	start_julia(void)
{
	t_view *view;

	view = init_view("Julia");
	set_hooks(view);
	mlx_loop(view->mlx);
}
