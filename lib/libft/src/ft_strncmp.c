/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:05:01 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 12:34:35 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cmp;
	unsigned char	*s2_cmp;
	size_t			i;

	s1_cmp = (unsigned char *)s1;
	s2_cmp = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1_cmp[i] && s2_cmp[i]) && i < n)
	{
		if (s1_cmp[i] - s2_cmp[i])
			return (s1_cmp[i] - s2_cmp[i]);
		i++;
	}
	if (i == n && i > 0)
		return (s1_cmp[i - 1] - s2_cmp[i - 1]);
	else
		return (s1_cmp[i] - s2_cmp[i]);
}
