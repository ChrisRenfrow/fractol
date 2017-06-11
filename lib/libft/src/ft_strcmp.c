/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:00:22 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/27 20:25:20 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
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
			return (s1_cmp[i] - s2_cmp[i]);
		i++;
	}
	return (0);
}
