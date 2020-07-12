/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 10:15:32 by user42            #+#    #+#             */
/*   Updated: 2020/06/20 10:32:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static int			square_error(t_square *square)
{
	if ((square->side_size <= 0)
	|| (square->direction.x < -1 || square->direction.x > 1)
	|| (square->direction.y < -1 || square->direction.y > 1)
	|| (square->direction.z < -1 || square->direction.z > 1)
	|| (square->color.r < 0 || square->color.r > 255)
	|| (square->color.g < 0 || square->color.g > 255)
	|| (square->color.b < 0 || square->color.b > 255))
	{
		printf("Error en los parametros del cuadrado\n");
		return (0);
	}
	return (1);
}

static void			add_square(t_scene **scene, t_square *square)
{
	t_list		*sq;

	sq = ft_lstnew(square);
	if ((*scene)->squareread == NULL)
	{
		(*scene)->squareread = sq;
	}
	else
	{
		ft_lstadd_back(&(*scene)->squareread, sq);
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

int					ft_read_square(char *line, t_scene **scene)
{
	int			i;
	t_square	*square;

	square = (t_square *)malloc(sizeof(t_square));
	i = 0;
	while (line[i] && ((line[i] < '0' || line[i] > '9') &&
	line[i] != '.' && line[i] != '-'))
		i++;
	square->origin = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	square->direction = ft_read_vector(&line[i]);
	advance_pointer(line, &i);
	square->side_size = ft_atof(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	square->color = ft_read_color(&line[i]);
	if (square_error(square))
		add_square(scene, square);
	return (1);
}
