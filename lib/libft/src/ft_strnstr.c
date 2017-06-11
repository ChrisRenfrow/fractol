/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:51:54 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/02 22:50:37 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[j])
	{
		while (big[i] && i < (int)len)
		{
			while (big[i] && big[i] == little[j] && i < (int)len)
			{
				if (!little[j + 1])
					return ((char *)&big[i - j]);
				i++;
				j++;
			}
			i -= j - 1;
			j = 0;
		}
		return (NULL);
	}
	return ((char *)big);
}
