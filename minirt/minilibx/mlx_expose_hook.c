/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:27:02 by user42            #+#    #+#             */
/*   Updated: 2020/06/29 14:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

int		mlx_expose_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[Expose].hook = funct;
	win->hooks[Expose].param = param;
	win->hooks[Expose].mask = ExposureMask;
}
