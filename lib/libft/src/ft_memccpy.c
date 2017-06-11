/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:00:19 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 17:25:46 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	int				i;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i < (int)n)
	{
		dst_tmp[i] = src_tmp[i];
		if (src_tmp[i] == (unsigned char)c)
			return (&dst_tmp[i + 1]);
		i++;
	}
	return (NULL);
}
