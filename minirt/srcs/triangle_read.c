/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:18:09 by user42            #+#    #+#             */
/*   Updated: 2020/06/20 10:32:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			triangle_error(t_triangle *triangle)
{
	if ((triangle->color.r < 0 || triangle->color.r > 255)
	|| (triangle->color.g < 0 || triangle->color.g > 255)
	|| (triangle->color.b < 0 || triangle->color.b > 255))
	{
		printf("Error en los parametros del plano\n");
		return (0);
	}
	return (1);
}

static void			add_triangle(t_scene **scene, t_triangle *triangle)
{
	t_list			*tri;

	tri = ft_lstnew(triangle);
	if ((*scene)->triangleread == NULL)
	{
		(*scene)->triangleread = tri;
	}
	else
	{
		ft_lstadd_back(&(*scene)->triangleread, tri);
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

int					ft_read_triangle(char *line, t_scene **scene)
{
	int				i;
	t_triangle		*triangle;

	triangle = (t_triangle *)malloc(sizeof(t_triangle));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
	{
		i++;
	}
	triangle->point_first = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	triangle->point_second = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	triangle->point_third = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	triangle->color = ft_read_color(&line[i]);
	if (triangle_error(triangle))
		add_triangle(scene, triangle);
	return (1);
}
