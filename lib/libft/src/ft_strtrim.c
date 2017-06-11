/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:21:12 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 18:43:47 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	is_trim(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (is_trim(*s))
		s++;
	while (s[i])
		i++;
	i--;
	while (is_trim(s[i]) && i >= 0)
		i--;
	res = ft_strsub(s, 0, i + 1);
	if (res)
		return (res);
	else
		return (NULL);
}
