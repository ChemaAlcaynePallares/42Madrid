/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:54:42 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 11:43:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static float		inter_plane(t_ray ray, t_square *square)
{
	float		a;
	float		b;
	float		t;
	t_vector	tmp;

	tmp = ft_vector_min(ray.origin, square->origin);
	a = dot(tmp, square->direction);
	b = dot(ray.direction, square->direction);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < 0)
		return (0);
	return (t);
}

static void			intersect_square(t_square *square, t_ray ray, t_hit *hit)
{
	float		t;
	float		a;
	t_vector	p;
	t_vector	data;

	if (!(t = inter_plane(ray, square)))
		return ;
	data = ft_vector_mul(ray.direction, t);
	p = ft_vector_sum(ray.direction, data);
	if (square->direction.x != 0 || square->direction.y == 0 ||
		square->direction.z != 0)
		p = apply_rot(p, square->direction, ft_vector_set(0, 1, 0));
	a = square->origin.x - square->side_size / 2;
	data.x = square->origin.x + square->side_size / 2;
	data.y = square->origin.z - square->side_size / 2;
	data.z = square->origin.z + square->side_size / 2;
	if (!((p.x >= a && p.x <= data.x) && (p.z <= data.z && p.z >= data.y)))
		return ;
	(*hit).t = t;
	(*hit).square = square;
	(*hit).normal = process_normal(ray, square->direction);
}

t_hit				get_hit_square(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_hit		hit;

	scene->square = scene->squareread;
	while (scene->square)
	{
		init_hit(&hit);
		intersect_square(scene->square->content, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		scene->square = scene->square->next;
	}
	return (min_h);
}
