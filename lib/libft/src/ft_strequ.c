/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:15:56 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/27 20:28:51 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*s1_cmp;
	unsigned char	*s2_cmp;
	int				i;

	s1_cmp = (unsigned char *)s1;
	s2_cmp = (unsigned char *)s2;
	i = 0;
	while (s1_cmp[i] || s2_cmp[i])
	{
		if (s1_cmp[i] - s2_cmp[i])
			return (0);
		i++;
	}
	return (1);
}
