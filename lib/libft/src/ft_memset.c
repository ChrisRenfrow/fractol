/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:45:08 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 17:29:14 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*cast;
	int		i;

	cast = (char *)s;
	i = 0;
	while (i < (int)len)
	{
		cast[i] = (unsigned)c;
		i++;
	}
	return (s);
}
