/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:15:56 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 17:25:59 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	int				i;
	unsigned char	uc;

	s_tmp = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < (int)n)
	{
		if (s_tmp[i] == uc)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
