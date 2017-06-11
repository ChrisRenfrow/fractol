/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 23:15:26 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/05 13:38:48 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = (void *)malloc(sizeof(content) * content_size);
		node->content = ft_memcpy((void *)node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
