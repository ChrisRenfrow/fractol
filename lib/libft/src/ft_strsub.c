/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:18:51 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/27 21:20:55 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	sub = ft_strnew(len);
	i = start;
	if (!sub)
		return (NULL);
	while ((i - start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}
