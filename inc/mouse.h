/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:05:09 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/13 15:09:36 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# define MOUSE_ONE 1
# define MOUSE_TWO 2
# define MOUSE_THREE 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct		s_mbutton
{
	int				one:1;
	int				two:1;
	int				three:1;
	int				scroll_up:1;
	int				scroll_down:1;
}					t_mbutton;

typedef struct		s_mouse
{
	int				x;
	int				y;
	t_mbutton		*button;
}					t_mouse;

#endif
