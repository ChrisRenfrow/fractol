/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:17:24 by crenfrow          #+#    #+#             */
/*   Updated: 2016/09/30 21:52:02 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s1_cmp;
	unsigned char	*s2_cmp;
	int				i;

	s1_cmp = (unsigned char *)s1;
	s2_cmp = (unsigned char *)s2;
	i = 0;
	while ((s1_cmp[i] || s2_cmp[i]) && i < (char)n)
	{
		if (s1_cmp[i] - s2_cmp[i])
			return (0);
		i++;
	}
	return (1);
}
