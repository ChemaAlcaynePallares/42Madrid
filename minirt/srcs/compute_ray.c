/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:36:05 by chema             #+#    #+#             */
/*   Updated: 2020/06/19 10:59:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

int		compute_ray(t_ray *ray, int x, int y, t_scene *scene)
{
	float			w;
	float			h;
	float			fov;
	t_vector		pixel;
	t_camera		*camera;

	camera = scene->camera;
	fov = camera->fieldofview * -1;
	w = scene->resolution->x;
	h = scene->resolution->y;
	pixel.x = (2 * (((float)x + 0.5) / w) - 1) *
	(w / h) * tan((fov / 2) * (M_PI / 180));
	pixel.y = (1 - 2 * (((float)y + 0.5) / h)) *
	tan((fov / 2) * (M_PI / 180));
	pixel.z = 1;
	if (!(camera->direction.x == 0 && camera->direction.y > 0 &&
	camera->direction.z == 0))
		pixel = apply_rot(pixel, camera->direction, ft_vector_set(0, 1, 0));
	(*ray).direction = ft_vector_normalize(pixel);
	(*ray).origin = camera->origin;
	return (1);
}
