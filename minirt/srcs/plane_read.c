/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:14:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 10:56:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			plane_error(t_plane *plane)
{
	if ((plane->direction.x < -1 || plane->direction.x > 1)
	|| (plane->direction.y < -1 || plane->direction.y > 1)
	|| (plane->direction.z < -1 || plane->direction.z > 1)
	|| (plane->color.r < 0 || plane->color.r > 255)
	|| (plane->color.g < 0 || plane->color.g > 255)
	|| (plane->color.b < 0 || plane->color.b > 255))
	{
		printf("Error en los parametros del plano\n");
		return (0);
	}
	return (1);
}

static void			add_plane(t_scene **scene, t_plane *plane)
{
	t_list		*pl;

	pl = ft_lstnew(plane);
	if ((*scene)->planeread == NULL)
	{
		(*scene)->planeread = pl;
	}
	else
	{
		ft_lstadd_back(&(*scene)->planeread, pl);
	}
}

int					ft_read_plane(char *line, t_scene **scene)
{
	int			i;
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
		i++;
	plane->origin = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
		i++;
	plane->direction = ft_read_vector(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '-'))
		i++;
	plane->color = ft_read_color(&line[i]);
	if (plane_error(plane))
		add_plane(scene, plane);
	return (1);
}
