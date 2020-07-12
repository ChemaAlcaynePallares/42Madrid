/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:43:49 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 11:44:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector	ft_vector_mul(t_vector vec1, float t)
{
	t_vector new_vec;

	new_vec.x = vec1.x * t;
	new_vec.y = vec1.y * t;
	new_vec.z = vec1.z * t;
	return (new_vec);
}

t_vector	ft_vector_div(t_vector vec1, float t)
{
	t_vector new_vec;

	new_vec.x = vec1.x / t;
	new_vec.y = vec1.y / t;
	new_vec.z = vec1.z / t;
	return (new_vec);
}

float		dot(t_vector v1, t_vector v2)
{
	float	x;

	x = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (x);
}

t_vector	cross(t_vector vec1, t_vector vec2)
{
	t_vector	cross;

	cross.x = vec1.y * vec2.z - vec1.z * vec2.y;
	cross.y = vec1.z * vec2.x - vec1.x * vec2.z;
	cross.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (cross);
}

t_vector	ft_vector_normalize(t_vector vec)
{
	t_vector		res;
	double			l;
	double			invl;

	l = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	invl = 1 / l;
	res = ft_vector_set(vec.x * invl, vec.y * invl, vec.z * invl);
	return (res);
}
