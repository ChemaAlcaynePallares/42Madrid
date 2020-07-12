/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 10:07:54 by chema             #+#    #+#             */
/*   Updated: 2020/06/26 10:48:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector		g_normal;
float			g_t_min;
t_vector		g_t;
t_vector		g_b;

static float	intersect_caps(t_ray ray, t_cylinder *cy, t_vector pos)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		t0;

	t0 = 0;
	tmp = ft_vector_min(ray.origin, pos);
	a = dot(tmp, cy->direction);
	b = dot(ray.direction, cy->direction);
	if (!(b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0)))
		t0 = -a / b;
	return (t0);
}

static float	calc_abc(t_ray ray, t_cylinder *cy, float *a, float *b)
{
	*a = dot(cross(ray.direction, ft_vector_min(g_t, g_b)),
	cross(ray.direction, ft_vector_min(g_t, g_b)));
	*b = 2 * dot(cross(ray.direction, ft_vector_min(g_t, g_b)),
	cross(ft_vector_min(ray.origin, g_b), ft_vector_min(g_t, g_b)));
	return (dot(cross(ft_vector_min(ray.origin, g_b),
	ft_vector_min(g_t, g_b)), cross(ft_vector_min(ray.origin, g_b),
	ft_vector_min(g_t, g_b))) - ((cy->diameter / 2) * (cy->diameter / 2) *
	dot(ft_vector_min(g_t, g_b), ft_vector_min(g_t, g_b))));
}

static void		infinite_cy(t_ray ray, t_cylinder *cy)
{
	float		t0;
	t_vector	p;
	float		a;
	float		b;
	float		c;

	c = calc_abc(ray, cy, &a, &b);
	if (pow(b, 2) - 4 * a * c > 0)
	{
		t0 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		if (t0 < 0)
			t0 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
		p = ft_vector_sum(ray.origin, ft_vector_mul(ray.direction, t0));
		p = apply_rot(p, cy->direction, ft_vector_set(0, 1, 0));
		g_b = apply_rot(g_b, cy->direction, ft_vector_set(0, 1, 0));
		g_t = apply_rot(g_t, cy->direction, ft_vector_set(0, 1, 0));
		if (t0 < g_t_min && p.y >= g_b.y && p.y <= g_t.y && (g_t_min = t0))
		{
			p = apply_rot(p, ft_vector_set(0, 1, 0), cy->direction);
			g_normal = ft_vector_normalize(ft_vector_min(p, cy->origin));
		}
	}
}

static void		intersect_cylinder(t_cylinder *cy, t_ray ray, t_hit *hit)
{
	float		t0;
	t_vector	p;

	t0 = 0;
	g_t_min = INFINITY;
	g_b = ft_vector_min(cy->origin, ft_vector_mul(
		ft_vector_normalize(cy->direction), cy->height / 2));
	g_t = ft_vector_sum(cy->origin, ft_vector_mul(
		ft_vector_normalize(cy->direction), cy->height / 2));
	t0 = intersect_caps(ray, cy, g_t);
	p = ft_vector_sum(ray.origin, ft_vector_mul(ray.direction, t0));
	if (t0 > 0 && dist(p, g_t) <= cy->diameter / 2 && (g_t_min = t0))
		g_normal = process_normal(ray, cy->direction);
	t0 = intersect_caps(ray, cy, g_b);
	p = ft_vector_sum(ray.origin, ft_vector_mul(ray.direction, t0));
	if (t0 > 0 && dist(p, g_b) <= cy->diameter / 2 && (g_t_min = t0))
		g_normal = process_normal(ray, cy->direction);
	infinite_cy(ray, cy);
	if (!(g_t_min > 0 && g_t_min != INFINITY))
		return ;
	(*hit).t = g_t_min;
	(*hit).cylinder = cy;
	(*hit).normal = g_normal;
}

t_hit			get_hit_cylinder(t_scene *scene, t_ray ray, t_hit min_h)
{
	t_hit	hit;

	scene->cylinder = scene->cylinderread;
	while (scene->cylinder)
	{
		init_hit(&hit);
		intersect_cylinder(scene->cylinder->content, ray, &hit);
		if (hit.t < min_h.t && hit.t > 0)
			min_h = hit;
		scene->cylinder = scene->cylinder->next;
	}
	return (min_h);
}
