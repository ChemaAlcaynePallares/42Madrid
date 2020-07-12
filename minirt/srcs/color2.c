/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 10:45:15 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 11:16:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_color		ft_color_sum(t_color color1, t_color color2)
{
	t_color new_color;

	new_color.r = (color1.r + color2.r) / 2;
	new_color.g = (color1.g + color2.g) / 2;
	new_color.b = (color1.b + color2.b) / 2;
	return (new_color);
}
