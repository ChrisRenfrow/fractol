/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:23:19 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/06 11:26:10 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		ct;
	int		i;
	int		j;

	ct = ft_ctwrd(s, c);
	i = 0;
	j = 0;
	res = (char **)ft_memalloc(sizeof(char *) * (ct + 1));
	if (!res)
		return (NULL);
	while (j < ct && *s)
	{
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		res[j] = ft_strsub(s, 0, i);
		s += i;
		i = 0;
		j++;
	}
	return (res);
}
