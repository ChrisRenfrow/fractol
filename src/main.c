/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:07:55 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/12 19:10:11 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_instance(char *str)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		if (!ft_strcmp(str, "julia"))
			start_julia();
		if (!ft_strcmp(str, "mandelbrot"))
			start_mandel();
		_exit(0);
	}
	else
	{
		printf("Starting new %s instance on PID %d\n", str, pid);
	}
}

int		main(int ac, char *av[])
{
	int i;

	i = 0;
	if (ac == 1)
		usage();
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "julia") ||
			!ft_strcmp(av[i], "mandelbrot"))
			new_instance(av[i]);
		else
			ft_warning(ft_strjoin("Bad option - Skipping ", av[i]));
	}
	return (0);
}
