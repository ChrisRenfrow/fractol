/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:09:16 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/17 22:09:36 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*res;
	char	*base_index;
	int		len;
	int		is_neg;
	int		tmp;

	base_index 	= "0123456789ABCDEF";
	len			= 0;
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		is_neg = 1;
	tmp = value;
	while (tmp /= base)
		len++;
	len += (is_neg) ? 2 : 1;
	res = (char *)malloc(sizeof(char) * len + 1);
	res[len] = 0;
	if (is_neg)
	{
		res[0] = '-';
		len--;
	}
	while (len > 0)
	{
		res[len - 1] = base_index[ft_abs(value % base)];
		len--;
		value /= base;
	}
	return (res);
}
