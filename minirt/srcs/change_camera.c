/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:22:54 by chema             #+#    #+#             */
/*   Updated: 2020/06/19 10:59:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

void	ft_change_camera_adv(t_scene **scene)
{
	t_list	*cam;
	int		i;

	cam = (*scene)->cameraread;
	i = 0;
	if (cam)
	{
		if (cam->next)
		{
			while (cam->next && (i <= (*scene)->camera_number))
			{
				i++;
				cam = cam->next;
			}
			(*scene)->camera = cam->content;
			(*scene)->camera_number = i;
		}
	}
}

void	ft_change_camera_rev(t_scene **scene)
{
	t_list	*cam;
	int		i;

	cam = (*scene)->cameraread;
	i = 0;
	if (cam && (*scene)->camera_number > 0)
	{
		if (cam->next)
		{
			while (cam->next && (i != ((*scene)->camera_number - 1)))
			{
				i++;
				cam = cam->next;
			}
			(*scene)->camera = cam->content;
			(*scene)->camera_number = i;
		}
	}
}
