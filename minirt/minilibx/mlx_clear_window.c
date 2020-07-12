/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:20:47 by user42            #+#    #+#             */
/*   Updated: 2020/06/29 14:21:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int		mlx_clear_window(t_xvar *xvar, t_win_list *win)
{
	XClearWindow(xvar->display, win->window);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
