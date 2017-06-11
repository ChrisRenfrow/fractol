/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:08:00 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/30 04:08:21 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates a new space of memory for ptr, and copies as much memory as
** possible from the original ptr to the new one.
*/

void	*ft_memrealloc(void *ptr, size_t new_size)
{
	void	*newbuf;

	if (!(newbuf = ft_memalloc(new_size)))
		return (NULL);
	if (!ptr)
		return (newbuf);
	ft_memmove(newbuf, ptr, new_size);
	ft_memdel(&ptr);
	return (newbuf);
}
