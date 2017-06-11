/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:24:29 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 18:47:01 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[j])
	{
		while (big[i])
		{
			while (big[i] == little[j])
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
