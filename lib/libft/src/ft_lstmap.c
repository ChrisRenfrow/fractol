/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 23:29:52 by crenfrow          #+#    #+#             */
/*   Updated: 2016/10/05 13:28:49 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *frsh;

	frsh = f(lst);
	if (!frsh)
		return (NULL);
	if (lst->next)
		frsh->next = ft_lstmap(lst->next, f);
	return (frsh);
}
