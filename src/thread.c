/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 13:23:57 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/03 15:18:34 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		destroy_thread(t_thread *t)
{
	if (t)
		free(t);
	else
		ft_error("Freeing thread - Unable to free NULL");
}

pthread_t	new_thread(t_view *view, int i, void *func)
{
	pthread_t 	pt;
	t_thread 	*t;

	t = (t_thread*)malloc(sizeof(t_thread));
	t->id = i;
	t->view = view;
	pthread_create(&pt, NULL, func, t);
	return(pt);
}
