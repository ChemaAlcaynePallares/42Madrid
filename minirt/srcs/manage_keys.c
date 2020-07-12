/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 10:26:35 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 10:55:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static void		destroy_minlibx(t_scene **scene)
{
	if ((*scene)->mlx_ptrs->img_ptr != NULL)
		mlx_destroy_image((*scene)->mlx_ptrs->mlx_ptr,
			(*scene)->mlx_ptrs->img_ptr);
	if ((*scene)->mlx_ptrs->win_ptr != NULL)
		mlx_destroy_window((*scene)->mlx_ptrs->mlx_ptr,
			(*scene)->mlx_ptrs->win_ptr);
	free((*scene)->mlx_ptrs->mlx_ptr);
	free((*scene)->mlx_ptrs);
}

void			destroy_n_exit(t_scene **scene)
{
	if ((*scene)->ambient_light != NULL)
		free((*scene)->ambient_light);
	if ((*scene)->resolution != NULL)
		free((*scene)->resolution);
	ft_lstfree_all(&(*scene)->cameraread);
	free((*scene)->camera);
	ft_lstfree_all(&(*scene)->lightread);
	if ((*scene)->light != NULL)
		free((*scene)->light);
	ft_lstfree_all(&(*scene)->sphere);
	ft_lstfree_all(&(*scene)->sphereread);
	ft_lstfree_all(&(*scene)->plane);
	ft_lstfree_all(&(*scene)->planeread);
	ft_lstfree_all(&(*scene)->square);
	ft_lstfree_all(&(*scene)->squareread);
	ft_lstfree_all(&(*scene)->cylinder);
	ft_lstfree_all(&(*scene)->cylinderread);
	ft_lstfree_all(&(*scene)->triangle);
	ft_lstfree_all(&(*scene)->triangleread);
	destroy_minlibx(scene);
	exit(0);
}

int				ft_manage_key(int key, t_scene **scene)
{
	printf("Key in Win : %d\n", key);
	if (key == 65307)
	{
		printf("End of mini_RT\n");
		destroy_n_exit(scene);
		free(scene);
	}
	if (key == 100)
	{
		printf("Camera advance\n");
		ft_change_camera_adv(scene);
	}
	if (key == 97)
	{
		printf("Camera reverse\n");
		ft_change_camera_rev(scene);
	}
	return (0);
}
