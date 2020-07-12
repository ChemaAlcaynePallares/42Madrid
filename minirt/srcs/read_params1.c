/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 16:19:12 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 11:11:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int	resolution_error(t_resolution *resolution)
{
	if (resolution->x <= 0 || resolution->y <= 0)
	{
		ft_printf("Error en los parametros de la resolucion\n");
		return (0);
	}
	return (1);
}

int			ft_read_resolution(char *line, t_scene **scene)
{
	t_resolution	*resolution;

	resolution = (t_resolution *)malloc(sizeof(t_resolution));
	while (*line && (*line < '0' || *line > '9'))
		line++;
	resolution->x = ft_atoi(line);
	while (*line && *line != ' ')
		line++;
	while (*line && (*line < '0' || *line > '9'))
		line++;
	resolution->y = ft_atoi(line);
	if (resolution->x > 1920)
		resolution->x = 1920;
	if (resolution->y > 1080)
		resolution->y = 1080;
	if (resolution_error(resolution))
		(*scene)->resolution = resolution;
	return (1);
}

static int	camera_error(t_camera *camera)
{
	if ((camera->fieldofview < 0.0 || camera->fieldofview > 180.0)
	|| (camera->direction.x < -1.0 || camera->direction.x > 1)
	|| (camera->direction.y < -1.0 || camera->direction.y > 1)
	|| (camera->direction.z < -1.0 || camera->direction.z > 1))
	{
		printf("Error en los parametros de la camara\n");
		return (0);
	}
	return (1);
}

static void	add_camera(t_scene **scene, t_camera *camera)
{
	t_list		*cam;

	cam = ft_lstnew((camera));
	if ((*scene)->cameraread == NULL)
	{
		(*scene)->cameraread = cam;
	}
	else
	{
		ft_lstadd_back(&(*scene)->cameraread, cam);
	}
}

int			ft_read_camera(char *line, t_scene **scene)
{
	int			i;
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	camera->origin = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	camera->direction = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	camera->fieldofview = ft_atoi(&line[i]);
	if (camera_error(camera))
		add_camera(scene, camera);
	return (1);
}
