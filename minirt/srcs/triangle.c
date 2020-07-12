/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:03:27 by chema             #+#    #+#             */
/*   Updated: 2020/06/26 10:47:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static void		intersect_triangle(t_triangle *triangle, t_ray ray, t_hit *hit)
{
	t_vector	e1;
	t_vector	e2;
	t_vector	tvec;
	t_vector	pvec;
	t_vector	qvec;

	e1 = ft_vector_min(triangle->point_second, triangle->point_first);
	e2 = ft_vector_min(triangle->point_third, triangle->point_first);
	if (dot(e1, (pvec = cross(ray.direction, e2))) >
		-1e-8 && dot(e1, pvec) < 1e-8)
		return ;
	if (dot((tvec = ft_vector_min(ray.origin, triangle->point_first)), pvec) *
		(1 / dot(e1, pvec)) < 0 || dot(tvec, pvec) * (1 / dot(e1, pvec)) > 1)
		return ;
	qvec = cross(tvec, e1);
	if (dot(ray.direction, qvec) * (1 / dot(e1, pvec)) < 0 || dot(tvec, pvec) *
	(1 / dot(e1, pvec)) + dot(ray.direction, qvec) * (1 / dot(e1, pvec)) > 1)
		return ;
	(*hit).t = dot(e2, qvec) * (1 / dot(e1, pvec));
	(*hit).triangle = triangle;
	qvec = cross(e1, e2);
	tvec = ft_vector_normalize(qvec);
	(*hit).normal = process_normal(ray, tvec);
}

t_hit			get_hit_triangle(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_hit		hit;

	scene->triangle = scene->triangleread;
	while (scene->triangle)
	{
		init_hit(&hit);
		intersect_triangle(scene->triangle->content, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		scene->triangle = scene->triangle->next;
	}
	return (min_h);
}
