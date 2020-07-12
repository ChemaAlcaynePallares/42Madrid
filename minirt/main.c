/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:05:58 by chema             #+#    #+#             */
/*   Updated: 2020/06/15 10:20:18 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

int		main(int argc, char **argv)
{
	if (argc <= 1 || argc > 3)
	{
		printf("Numero de argumentos invalidos\n");
		return (0);
	}
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", sizeof("--save")))
		{
			minirt(argv[1], 1);
		}
		else
		{
			minirt(argv[1], 0);
		}
	}
	else
		minirt(argv[1], 0);
	return (0);
}
