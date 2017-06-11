/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:47:35 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/27 17:13:26 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	else
		return (NULL);
}
