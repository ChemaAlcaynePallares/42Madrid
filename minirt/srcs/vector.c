/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 11:03:41 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 11:45:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector	ft_vector_set(float x, float y, float z)
{
	t_vector new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_vector	ft_vector_sum(t_vector vec1, t_vector vec2)
{
	t_vector new_vec;

	new_vec.x = vec1.x + vec2.x;
	new_vec.y = vec1.y + vec2.y;
	new_vec.z = vec1.z + vec2.z;
	return (new_vec);
}

t_vector	ft_vector_min(t_vector vec1, t_vector vec2)
{
	t_vector new_vec;

	new_vec.x = vec1.x - vec2.x;
	new_vec.y = vec1.y - vec2.y;
	new_vec.z = vec1.z - vec2.z;
	return (new_vec);
}

t_vector	ft_vector_mul_vec(t_vector vec1, t_vector vec2)
{
	t_vector new_vec;

	new_vec.x = vec1.x * vec2.x;
	new_vec.y = vec1.y * vec2.y;
	new_vec.z = vec1.z * vec2.z;
	return (new_vec);
}

t_vector	ft_vector_div_vec(t_vector vec1, t_vector vec2)
{
	t_vector new_vec;

	new_vec.x = vec1.x / vec2.x;
	new_vec.y = vec1.y / vec2.y;
	new_vec.z = vec1.z / vec2.z;
	return (new_vec);
}
