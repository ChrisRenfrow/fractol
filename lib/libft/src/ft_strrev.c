/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:56:51 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/22 21:20:10 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	tmp = ft_strnew(len);
	i = 0;
	j = len - 1;
	while (i < len)
	{
		tmp[i] = str[j - i];
		i++;
	}
	return (tmp);
}
