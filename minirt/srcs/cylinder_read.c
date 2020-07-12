/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:17:24 by user42            #+#    #+#             */
/*   Updated: 2020/06/20 10:32:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			cylinder_error(t_cylinder *cylinder)
{
	if ((cylinder->diameter <= 0)
	|| (cylinder->height <= 0)
	|| (cylinder->direction.x < -1 || cylinder->direction.x > 1)
	|| (cylinder->direction.y < -1 || cylinder->direction.y > 1)
	|| (cylinder->direction.z < -1 || cylinder->direction.z > 1)
	|| (cylinder->color.r < 0 || cylinder->color.r > 255)
	|| (cylinder->color.g < 0 || cylinder->color.g > 255)
	|| (cylinder->color.b < 0 || cylinder->color.b > 255))
	{
		printf("Error en los parametros del cilindro\n");
		return (0);
	}
	return (1);
}

static void			add_cylinder(t_scene **scene, t_cylinder *cylinder)
{
	t_list			*cy;

	cy = ft_lstnew(cylinder);
	if ((*scene)->cylinderread == NULL)
	{
		(*scene)->cylinderread = cy;
	}
	else
	{
		ft_lstadd_back(&(*scene)->cylinderread, cy);
	}
}

static void			advance_pointer(char *line, int *i)
{
	while (line[*i] && line[*i] != ' ')
		*i = *i + 1;
	while (line[*i] && ((line[*i] < '0' || line[*i] > '9') &&
	line[*i] != '.' && line[*i] != '-'))
		*i = *i + 1;
}

int					ft_read_cylinder(char *line, t_scene **scene)
{
	int				i;
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
		i++;
	cylinder->origin = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	cylinder->direction = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	cylinder->diameter = ft_atof(&line[i]);
	advance_pointer(line, &i);
	cylinder->height = ft_atof(&line[i]);
	advance_pointer(line, &i);
	cylinder->color = ft_read_color(&line[i]);
	if (cylinder_error(cylinder))
		add_cylinder(scene, cylinder);
	return (1);
}
