/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 13:43:33 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 17:27:01 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;
	int				i;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = n - 1;
	while (i >= 0)
	{
		dst_tmp[i] = src_tmp[i];
		i--;
	}
	return (dst);
}
