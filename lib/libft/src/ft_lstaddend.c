/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 00:08:54 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 18:34:52 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstaddend(t_list **alst, t_list *new)
{
	if (!new)
		return;
	if (alst && (*alst)->next)
		ft_lstaddend(&(*alst)->next, new);
	else
		(*alst)->next = new;
}
