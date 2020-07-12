/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:14:08 by jalcayne          #+#    #+#             */
/*   Updated: 2020/06/26 10:49:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static float	dot_number(const char *str, int sign, float nbr)
{
	int		i;
	int		counter;
	float	nbr2;

	i = 0;
	counter = 0;
	nbr2 = 0.0;
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nbr2 = (nbr2 * 10) + (str[i++] - '0');
			counter++;
		}
	}
	return ((nbr + (nbr2 * powf(0.1, counter))) * sign);
}

float			ft_atof(const char *str)
{
	int		i;
	int		sign;
	float	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str == NULL)
		return (0);
	while (ft_isspace(str[i]))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	while (str[i] != '.' && str[i])
		i++;
	return (dot_number(&str[i], sign, nbr));
}
