/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 04:41:23 by crenfrow          #+#    #+#             */
/*   Updated: 2016/12/07 04:42:05 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *orig, size_t new)
{
	char	*fresh;

	fresh = ft_strnew(new);
	fresh = ft_strcpy(fresh, orig);
	free(orig);
	return (fresh);
}
