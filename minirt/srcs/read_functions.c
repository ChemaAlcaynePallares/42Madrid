/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 09:51:03 by user42            #+#    #+#             */
/*   Updated: 2020/06/28 11:09:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_color		ft_read_color(char *line)
{
	t_color	new_color;
	int		i;

	i = 0;
	new_color.r = ft_atoi(&line[i]);
	while (line[i] && line[i] != ',')
		i++;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	new_color.g = ft_atoi(&line[i]);
	while (line[i] && line[i] != ',')
		i++;
	while (line[i] && (line[i] < '0' || line[i] > '9'))
		i++;
	new_color.b = ft_atoi(&line[i]);
	return (new_color);
}

t_vector	ft_read_vector(char *line)
{
	t_vector	new_vec;
	int			i;

	i = 0;
	new_vec.x = ft_atof(&line[i]);
	while (line[i] && line[i] != ',')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	new_vec.y = ft_atof(&line[i]);
	while (line[i] && line[i] != ',')
		i++;
	while (line[i] && ((line[i] < '0' || line[i] > '9') && line[i] != '-'))
		i++;
	new_vec.z = ft_atof(&line[i]);
	return (new_vec);
}
