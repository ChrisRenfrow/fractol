/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 10:06:11 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/30 21:40:59 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
