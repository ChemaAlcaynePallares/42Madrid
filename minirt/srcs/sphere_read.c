/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:14:07 by user42            #+#    #+#             */
/*   Updated: 2020/06/20 10:14:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			sphere_error(t_sphere *sphere)
{
	if ((sphere->radius < 0.0)
	|| (sphere->color.r < 0 || sphere->color.r > 255)
	|| (sphere->color.g < 0 || sphere->color.g > 255)
	|| (sphere->color.b < 0 || sphere->color.b > 255))
	{
		printf("Error en los parametros de las esfera\n");
		return (0);
	}
	return (1);
}

static void			add_sphere(t_scene **scene, t_sphere *sphere)
{
	t_list		*sph;

	sph = ft_lstnew(sphere);
	if ((*scene)->sphereread == NULL)
	{
		(*scene)->sphereread = sph;
	}
	else
	{
		ft_lstadd_back(&(*scene)->sphereread, sph);
	}
}

int					ft_read_sphere(char *line, t_scene **scene)
{
	int			i;
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
	{
		i++;
	}
	sphere->origin = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	sphere->radius = ft_atof(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	sphere->color = ft_read_color(&line[i]);
	sphere->radius = sphere->radius / 2;
	if (sphere_error(sphere))
		add_sphere(scene, sphere);
	return (1);
}
