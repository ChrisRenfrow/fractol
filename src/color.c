/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:39:20 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/15 21:30:01 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		*init_rgb(t_ui r, t_ui g, t_ui b)
{
	t_rgb *rgb;

	rgb = (t_rgb *)ft_memalloc(sizeof(t_rgb));
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

int			rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

t_rgb		*hex_to_rgb(unsigned int hex)
{
	t_rgb *rgb;

	rgb = init_rgb(0, 0, 0);
	rgb->r = ((hex & 0xFF0000) >> 16);
	rgb->g = ((hex & 0xFF00) >> 8);
	rgb->b = (hex & 0xFF);
	return (rgb);
}

// t_cscheme	*parse_scheme(char *path)
// {
// 	int fd;
// 	int i;
// 	char *title;
// 	char *line;
// 	t_rgb **colors;
//
// 	fd = open(path, O_RDONLY, 0700);
// 	i = 0;
// 	while (get_next_line(fd, &line))
// 	{
// 		if (i == 0)
// 			title =
// 	}
//
// }

// t_cscheme	*init_scheme(char *title, int ct, t_rgb *colors)
// {
// 	t_cscheme	*sch;
//
// 	sch = (t_cscheme *)malloc(sizeof(t_cscheme));
// 	sch->title = title;
// 	sch->color_ct = ct;
// 	sch->colors = (t_rgb **)malloc(sizeof(t_rgb*) * ct);
// 	while (++i < ct)
// 	{
//
// 	}
// }

void		get_schemes(t_view *view)
{
	DIR	*dirp;
	struct dirent *ndirp;

	(void)view;

	if (!(dirp = opendir("color_schemes/")))
		ft_error("Unable to open 'color_schemes/' - File missing or access denied");
	while((ndirp = readdir(dirp)))
	{
		if (!check_ext(ndirp->d_name, ".csc"))
			printf("Found scheme: %s\n", ndirp->d_name);
		// t_list *new = ft_lstnew()
	}
}
