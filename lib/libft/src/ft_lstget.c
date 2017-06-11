/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 03:44:46 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/30 23:54:31 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Accesses the list item at index and returns a reference to it.
*/

t_list	*ft_lstget(t_list **alist, int i)
{
	if (i <= 0 || !*alist)
		return (*alist);
	else
		return (ft_lstget(&(*alist)->next, i - 1));
}
