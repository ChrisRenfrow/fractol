/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 03:44:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 18:34:49 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Accesses the list item at index and returns a reference to it.
*/

t_list *ft_lstget(t_list **alist, int i)
{
	if (*alist)
	{
		if ((*alist)->next && i != 0)
			ft_lstget(&(*alist)->next, i - 1);
		else
			return (*alist);
	}
	return (*alist);
}
