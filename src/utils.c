/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:40:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 15:41:00 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putendl("Error: Invalid input");
	ft_putendl("Usage - ./fractol [fractal name]");
	ft_putendl(AVAILABLE);
}

void	ft_error(char *err)
{
	ft_putendl(ft_strjoin("Error: ", err));
	exit (1);
}

void	ft_warning(char *warn)
{
	ft_putendl(ft_strjoin("Warning: ", warn));
}
