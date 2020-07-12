/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:07:06 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 11:12:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			ambient_light_error(t_ambient_light *ambient_light)
{
	if ((ambient_light->ratio < 0.0 || ambient_light->ratio > 1.0)
	|| (ambient_light->color.r < 0 || ambient_light->color.r > 255)
	|| (ambient_light->color.g < 0 || ambient_light->color.g > 255)
	|| (ambient_light->color.b < 0 || ambient_light->color.b > 255))
	{
		printf("Error en los parametros de la luz ambiental\n");
		return (0);
	}
	return (1);
}

int					ft_read_ambient_light(char *line, t_scene **scene)
{
	int				i;
	t_ambient_light	*ambient_light;

	ambient_light = (t_ambient_light *)malloc(sizeof(t_ambient_light));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
		i++;
	ambient_light->ratio = ft_atof(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	ambient_light->color = ft_read_color(&line[i]);
	if (ambient_light_error(ambient_light))
		(*scene)->ambient_light = ambient_light;
	return (1);
}

static int			light_error(t_light *light)
{
	if ((light->brightness < 0.0 || light->brightness > 1.0)
	|| (light->color.r < 0 || light->color.r > 255)
	|| (light->color.g < 0 || light->color.g > 255)
	|| (light->color.b < 0 || light->color.b > 255))
	{
		printf("Error en los parametros del foco de luz\n");
		return (0);
	}
	return (1);
}

static void			add_light(t_scene **scene, t_light *light)
{
	t_list		*l_light;

	l_light = ft_lstnew(light);
	if ((*scene)->lightread == NULL)
	{
		(*scene)->lightread = l_light;
	}
	else
	{
		ft_lstadd_back(&(*scene)->lightread, l_light);
	}
}

int					ft_read_light(char *line, t_scene **scene)
{
	int		i;
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
	{
		i++;
	}
	light->origin = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	light->brightness = ft_atof(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	light->color = ft_read_color(&line[i]);
	if (light_error(light))
		add_light(scene, light);
	return (1);
}
