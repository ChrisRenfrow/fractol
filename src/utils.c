/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:40:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/15 21:19:58 by crenfrow         ###   ########.fr       */
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

int			check_ext(char *path, char *ext)
{
	int		len_a;
	int		len_b;

	len_a = ft_strlen(path);
	len_b = ft_strlen(ext);
	if (ft_strncmp(&path[len_a - len_b], ext, len_b))
		return (1);
	return (0);
}
