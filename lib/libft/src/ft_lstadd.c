/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 23:28:41 by crenfrow          #+#    #+#             */
/*   Updated: 2017/07/01 18:34:55 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
