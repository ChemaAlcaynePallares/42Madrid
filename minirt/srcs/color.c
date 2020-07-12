/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:46:18 by chema             #+#    #+#             */
/*   Updated: 2020/06/26 10:45:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_color		ft_vector_to_color(t_vector vec)
{
	t_color new_color;

	new_color.r = vec.x;
	new_color.g = vec.y;
	new_color.b = vec.z;
	return (new_color);
}

t_vector	ft_color_to_vector(t_color vec)
{
	t_vector new_color;

	new_color.x = vec.r;
	new_color.y = vec.g;
	new_color.z = vec.b;
	return (new_color);
}

int			color_to_int(t_color color)
{
	int rgb;

	rgb = (int)color.r;
	rgb = (rgb << 8) + (int)color.g;
	rgb = (rgb << 8) + (int)color.b;
	return (rgb);
}

t_color		ft_color_set(float r, float g, float b)
{
	t_color new_color;

	new_color.r = r;
	new_color.g = g;
	new_color.b = b;
	return (new_color);
}

t_color		ft_color_mul(t_color color, float f)
{
	t_color new_color;

	new_color.r = color.r * f;
	new_color.g = color.g * f;
	new_color.b = color.b * f;
	return (new_color);
}
