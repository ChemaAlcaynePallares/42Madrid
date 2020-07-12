/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:38:41 by chema             #+#    #+#             */
/*   Updated: 2020/06/13 16:25:31 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static t_vector		calculate_rot(t_vector *c2, t_vector *c3,
t_vector rot, t_vector to)
{
	t_vector	c1;
	t_vector	v;
	float		c;
	float		s;
	float		r;

	v = cross(to, rot);
	c = dot(rot, to);
	s = pow(magnitude(v), 2);
	r = ((1 - c) / s);
	c1 = ft_vector_set(-r * (pow(v.y, 2) + pow(v.z, 2))
	+ 1, r * v.x * v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = ft_vector_set(r * v.x * v.y + v.z, -r * (pow(v.x, 2)
	+ pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	(*c3) = ft_vector_set(r * v.x * v.z - v.y, r * v.y
	* v.z - v.x, -r * (pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_vector			apply_rot(t_vector pos, t_vector dir, t_vector rot)
{
	t_vector	c1;
	t_vector	c2;
	t_vector	c3;
	t_vector	prev;

	if (dir.x == 0 && dir.y < 0 && dir.z == 0)
		pos = ft_vector_set(pos.x, pos.y, -pos.z);
	else if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
	{
		prev = pos;
		c1 = calculate_rot(&c2, &c3, rot, dir);
		pos = ft_vector_set(dot(c1, prev), dot(c2, prev), dot(c3, prev));
	}
	return (pos);
}
