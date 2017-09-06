/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 03:44:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/04 14:05:02 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Accesses the list item at index and returns a reference to it.
*/

t_list *ft_lstget(t_list **alist, int i)
{
	t_list *tmp;

	tmp = *alist;
	if (*alist && (*alist)->next)
	{
		if (i != 0)
			tmp = ft_lstget(&(*alist)->next, i - 1);
		else
			return (tmp);
	}
	return (tmp);
}
