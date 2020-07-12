/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:03:50 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 10:56:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector		process_normal(t_ray ray, t_vector normal)
{
	float		res;
	t_vector	tmp;

	res = dot(ray.direction, normal);
	if (res < 0)
		return (normal);
	tmp = ft_vector_invert(normal);
	return (tmp);
}

static void		intersect_plane(t_plane *plane, t_ray ray, t_hit *hit)
{
	float		a;
	float		b;
	float		t;
	t_vector	tmp;

	tmp = ft_vector_min(ray.origin, plane->origin);
	a = dot(tmp, plane->direction);
	b = dot(ray.direction, plane->direction);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (init_hit(hit));
	t = -a / b;
	if (t < 0)
		return (init_hit(hit));
	(*hit).t = t;
	(*hit).plane = plane;
	(*hit).normal = process_normal(ray, plane->direction);
}

t_hit			get_hit_plane(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_hit		hit;

	scene->plane = scene->planeread;
	while (scene->plane)
	{
		init_hit(&hit);
		intersect_plane(scene->plane->content, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		scene->plane = scene->plane->next;
	}
	return (min_h);
}
