/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_schemes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 13:12:18 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 18:34:17 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int rgbchk(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

static void parse_scheme(t_view *view, char *path)
{
	int        fd;
	int        i;
	char *     line;
	char **    split;
	t_rgb *    col;
	t_cscheme *sch;

	fd = open(path, O_RDONLY, 0700);
	i = -1;
	sch = init_scheme();
	while (get_next_line(fd, &line))
	{
		if (++i == 0)
		{
			sch->title = ft_strdup(line);
			continue;
		}
		split = ft_strsplit(line, ' ');
		if (split[0] && split[1] && split[2])
		{
			col = init_rgb(rgbchk(ft_atoi(split[0])), rgbchk(ft_atoi(split[1])), rgbchk(ft_atoi(split[2])));
			if (sch->colors)
				ft_lstaddend(&sch->colors, ft_lstnew(col, sizeof(t_rgb)));
			else
				ft_lstadd(&sch->colors, ft_lstnew(col, sizeof(t_rgb)));
		}
		else
		{
			ft_warning(ft_strjoin("Bad color scheme - Skipping ", sch->title));
			close(fd);
			return;
		}
		free(line);
	}
	sch->color_ct = i;
	if (view->schemes)
		ft_lstaddend(&view->schemes, ft_lstnew(sch, sizeof(t_cscheme)));
	else
		ft_lstadd(&view->schemes, ft_lstnew(sch, sizeof(t_cscheme)));
	close(fd);
}

void get_schemes(t_view *view)
{
	DIR *          dirp;
	struct dirent *ndirp;

	(void) view;

	if (!(dirp = opendir(SCHEME_PATH)))
		ft_error("Unable to open 'color_schemes/' - File missing or access "
		         "denied");
	while ((ndirp = readdir(dirp)))
	{
		if (!check_ext(ndirp->d_name, ".csc"))
		{
			printf("Found scheme: %s\n", ndirp->d_name);
			view->scheme_ct += 1;
			parse_scheme(view, ft_strjoin(SCHEME_PATH, ndirp->d_name));
		}
	}
}
