/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:43:40 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 11:44:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector	ft_vector_invert(t_vector vec)
{
	t_vector res;

	res.x = -1 * vec.x;
	res.y = -1 * vec.y;
	res.z = -1 * vec.z;
	return (res);
}

float		magnitude(t_vector a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

float		dist(t_vector a, t_vector b)
{
	float dist;

	dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	return (dist);
}

t_vector	c_to_vec(t_vector color)
{
	t_vector col;

	col.x = color.x / 255;
	col.y = color.y / 255;
	col.z = color.z / 255;
	return (col);
}

t_vector	clamp(t_vector vec)
{
	t_vector res;

	res.x = (vec.x > 1.0) ? 1.0 : vec.x;
	res.y = (vec.y > 1.0) ? 1.0 : vec.y;
	res.z = (vec.z > 1.0) ? 1.0 : vec.z;
	res.x = res.x * 255;
	res.y = res.y * 255;
	res.z = res.z * 255;
	return (res);
}
