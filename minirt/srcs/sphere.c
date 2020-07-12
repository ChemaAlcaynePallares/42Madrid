/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 11:48:59 by chema             #+#    #+#             */
/*   Updated: 2020/06/14 12:42:30 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static void	intersect_sphere(t_sphere *sphere, t_ray ray, t_hit *hit)
{
	t_vector		oc;
	float			a;
	float			b;
	float			discr;

	oc = ft_vector_min(ray.origin, sphere->origin);
	a = dot(ray.direction, ray.direction);
	b = 2 * dot(oc, ray.direction);
	discr = pow(b, 2) - 4 * a * (dot(oc, oc) - pow(sphere->radius, 2));
	if (discr < 0)
		return ;
	(*hit).t = (-b - sqrt(discr)) / (2 * a);
	if ((*hit).t < 0)
		(*hit).t = (-b + sqrt(discr)) / (2 * a);
	oc = ft_vector_mul(ray.direction, (*hit).t);
	(*hit).normal = ft_vector_sum(ray.origin, oc);
	oc = ft_vector_min((*hit).normal, sphere->origin);
	(*hit).sphere = sphere;
	(*hit).normal = ft_vector_normalize(oc);
}

t_hit		get_hit_sphere(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_hit		hit;

	scene->sphere = scene->sphereread;
	while (scene->sphere)
	{
		init_hit(&hit);
		intersect_sphere(scene->sphere->content, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		scene->sphere = scene->sphere->next;
	}
	return (min_h);
}
