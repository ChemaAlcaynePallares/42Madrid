/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:46:56 by chema             #+#    #+#             */
/*   Updated: 2020/06/29 10:56:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

void		init_hit(t_hit *hit)
{
	(*hit).normal = v_false();
	(*hit).t = INFINITY;
	(*hit).sphere = NULL;
	(*hit).triangle = NULL;
	(*hit).square = NULL;
	(*hit).plane = NULL;
	(*hit).cylinder = NULL;
}

t_hit		get_hit(t_scene *scene, t_ray ray)
{
	t_hit min_h;

	init_hit(&min_h);
	min_h = get_hit_sphere(scene, ray, min_h);
	min_h = get_hit_plane(scene, ray, min_h);
	min_h = get_hit_square(scene, ray, min_h);
	min_h = get_hit_triangle(scene, ray, min_h);
	min_h = get_hit_cylinder(scene, ray, min_h);
	return (min_h);
}

t_vector	get_hit_color(t_hit hit)
{
	t_vector		hit_color;

	if (hit.cylinder)
		hit_color = ft_color_to_vector(hit.cylinder->color);
	else if (hit.square)
		hit_color = ft_color_to_vector(hit.square->color);
	else if (hit.triangle)
		hit_color = ft_color_to_vector(hit.triangle->color);
	else if (hit.plane)
		hit_color = ft_color_to_vector(hit.plane->color);
	else if (hit.sphere)
		hit_color = ft_color_to_vector(hit.sphere->color);
	else
		hit_color = v_false();
	return (hit_color);
}
