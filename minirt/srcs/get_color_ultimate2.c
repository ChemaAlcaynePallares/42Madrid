/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_ultimate2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:18:56 by user42            #+#    #+#             */
/*   Updated: 2020/06/26 11:22:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			obj_cmp(t_hit obj, t_hit hit)
{
	if (hit.sphere == obj.sphere && hit.sphere != NULL)
		return (1);
	if (hit.cylinder == obj.cylinder && hit.cylinder != NULL)
		return (1);
	if (hit.square == obj.square && hit.square != NULL)
		return (1);
	if (hit.triangle == obj.triangle && hit.triangle != NULL)
		return (1);
	if (hit.plane == obj.plane && hit.plane != NULL)
		return (1);
	return (0);
}

static float		maxi(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float		calc_diff(t_light *light, t_hit hit, t_vector *l)
{
	t_vector		tm;

	tm = ft_vector_min(light->origin, hit.phit);
	*l = ft_vector_normalize(tm);
	return (maxi(0.0, dot(hit.normal, *l)) * 0.7);
}

static void			do_calc(t_light *light, t_hit hit,
					t_phong **ph, t_ray ray)
{
	t_vector		l;
	t_vector		p;
	float			diff;
	float			spec;
	t_vector		tmp;

	diff = calc_diff(light, hit, &l);
	tmp = ft_vector_mul(hit.normal, 2 * (dot(l, hit.normal)));
	l = ft_vector_min(tmp, l);
	p = ft_vector_normalize(l);
	l = ft_vector_invert(ray.direction);
	tmp = ft_vector_normalize(l);
	spec = 0.1 * pow(maxi(0.0, dot(p, tmp)), 32);
	tmp = c_to_vec(ft_color_to_vector(light->color));
	l = ft_vector_mul(tmp, light->brightness);
	tmp = ft_vector_mul(l, diff);
	l = ft_vector_mul(l, spec);
	(*ph)->di = ft_vector_sum((*ph)->di, tmp);
	(*ph)->sp = ft_vector_sum((*ph)->sp, l);
}

void				get_color_loop(t_scene *scene, t_hit hit,
					t_phong **ph, t_ray ray)
{
	t_ray			shadow;
	t_hit			hit_shad;
	t_vector		tmp;
	t_vector		tmp2;
	float			dst;

	shadow.origin = scene->light->origin;
	tmp = ft_vector_min(hit.phit, scene->light->origin);
	shadow.direction = ft_vector_normalize(tmp);
	hit_shad = get_hit(scene, shadow);
	tmp = ft_vector_mul(shadow.direction, hit_shad.t);
	tmp2 = ft_vector_sum(shadow.origin, tmp);
	dst = dist(tmp2, hit.phit);
	if (obj_cmp(hit, hit_shad) || dst >= dist(hit.phit, scene->light->origin))
		do_calc(scene->light, hit, ph, ray);
}
