/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:40:45 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 18:31:56 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void usage(void)
{
	ft_putendl("Error: Invalid input");
	ft_putendl("Usage - ./fractol [fractal name]");
	ft_putendl(AVAILABLE);
}

void ft_error(char *err)
{
	ft_putendl(ft_strjoin("Error: ", err));
	exit(1);
}

void ft_warning(char *warn)
{
	ft_putendl(ft_strjoin("Warning: ", warn));
}

int check_ext(char *path, char *ext)
{
	int len_a;
	int len_b;

	len_a = ft_strlen(path);
	len_b = ft_strlen(ext);
	if (ft_strncmp(&path[len_a - len_b], ext, len_b))
		return (1);
	return (0);
}

void prt_rgb_lst(t_list *elem)
{
	if (elem)
	{
		t_rgb *col = (t_rgb *) elem->content;
		if (col)
			printf(" - %d, %d, %d\n", col->r, col->g, col->b);
	}
}

void prt_scheme_lst(t_list *elem)
{
	if (elem)
	{
		t_cscheme *sch = (t_cscheme *) elem->content;
		if (sch)
		{
			printf("Color scheme \"%s\" - %dct\n", sch->title, sch->color_ct);
			ft_lstiter(((t_cscheme *) sch)->colors, &prt_rgb_lst);
		}
	}
}
