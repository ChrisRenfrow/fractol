/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memreallocf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 04:02:11 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/30 04:05:30 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Shamelessly 'borrowed' implementation from Kyle Davisß
*/

#include <stdlib.h>
#include "libft.h"

void	*ft_memreallocf(void *ptr, size_t new_size)
{
	void	*newbuf;

	if (!(newbuf = ft_memalloc(new_size)))
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	if (!ptr)
		return (newbuf);
	ft_memmove(newbuf, ptr, new_size);
	ft_memdel(&ptr);
	return (newbuf);
}
