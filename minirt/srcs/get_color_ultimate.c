/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_ultimate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:40:48 by chema             #+#    #+#             */
/*   Updated: 2020/06/26 11:18:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static t_phong		calc_ph(t_scene *scene)
{
	t_phong	ph;

	ph.am = ft_vector_mul(c_to_vec(
				ft_color_to_vector(scene->ambient_light->color)),
					scene->ambient_light->ratio);
	ph.di = ft_vector_set(0, 0, 0);
	ph.sp = ft_vector_set(0, 0, 0);
	return (ph);
}

t_color				get_color_w(t_scene *scene, t_ray ray)
{
	t_hit			hit;
	t_vector		hc;
	t_vector		color;
	t_phong			*ph;
	t_list			*light;

	light = scene->lightread;
	hit = get_hit(scene, ray);
	if (hit.t == INFINITY)
		return (ft_color_set(10, 10, 10));
	hit.phit = ft_vector_sum(ray.origin, ft_vector_mul(ray.direction, hit.t));
	hc = get_hit_color(hit);
	ph = (t_phong *)malloc(sizeof(t_phong));
	*ph = calc_ph(scene);
	while (light)
	{
		scene->light = light->content;
		get_color_loop(scene, hit, &ph, ray);
		light = light->next;
	}
	color = ft_vector_sum(ft_vector_mul_vec(ft_vector_sum(ph->am, ph->di),
		c_to_vec(hc)), ph->sp);
	free(ph);
	return (ft_vector_to_color(clamp(color)));
}
