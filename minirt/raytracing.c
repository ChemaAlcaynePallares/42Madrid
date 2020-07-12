/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:57:38 by chema             #+#    #+#             */
/*   Updated: 2020/06/29 10:51:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracing.h"

static void		init_scene(t_scene **scene)
{
	(*scene)->resolution = NULL;
	(*scene)->ambient_light = NULL;
	(*scene)->light = NULL;
	(*scene)->lightread = NULL;
	(*scene)->camera = NULL;
	(*scene)->cameraread = NULL;
	(*scene)->camera_number = 0;
	(*scene)->triangle = NULL;
	(*scene)->triangleread = NULL;
	(*scene)->square = NULL;
	(*scene)->squareread = NULL;
	(*scene)->cylinder = NULL;
	(*scene)->cylinderread = NULL;
	(*scene)->sphere = NULL;
	(*scene)->sphereread = NULL;
	(*scene)->plane = NULL;
	(*scene)->planeread = NULL;
	(*scene)->save = 0;
	(*scene)->mlx_ptrs = (t_mlx_ptrs *)malloc(sizeof(t_mlx_ptrs));
}

int				ft_searcher(char *line, t_scene **scene)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			return (ft_read_resolution(&line[i++], scene));
		else if (line[i] == 'A')
			return (ft_read_ambient_light(&line[i++], scene));
		else if (line[i] == 'c' && line[i + 1] == ' ')
			return (ft_read_camera(&line[i++], scene));
		else if (line[i] == 'l')
			return (ft_read_light(&line[i++], scene));
		else if (line[i] == 's' && line[i + 1] == 'p')
			return (ft_read_sphere(&line[i++], scene));
		else if (line[i] == 'p' && line[i + 1] == 'l')
			return (ft_read_plane(&line[i++], scene));
		else if (line[i] == 's' && line[i + 1] == 'q')
			return (ft_read_square(&line[i++], scene));
		else if (line[i] == 'c' && line[i + 1] == 'y')
			return (ft_read_cylinder(&line[i++], scene));
		else if (line[i] == 't' && line[i + 1] == 'r')
			return (ft_read_triangle(&line[i++], scene));
	}
	return (0);
}

t_scene			*ft_scene_reader(char *scenetxt)
{
	int			fd;
	int			ret;
	char		*line;
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(&scene);
	fd = open(scenetxt, O_RDONLY);
	if (fd < 0)
	{
		printf("error al leer el archivo\n");
		exit(0);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_searcher(line, &scene);
		free(line);
	}
	if (ret == -1)
		printf("-----------\nError\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n");
	free(line);
	return (scene);
}

static	void	params_error(t_scene *scene)
{
	if (scene->resolution == NULL || scene->cameraread == NULL ||
		scene->lightread == NULL || scene->ambient_light == NULL)
	{
		ft_printf("Error en los parametros principales");
		destroy_n_exit(&scene);
	}
}

void			minirt(char *scenetxt, int save)
{
	t_scene		*scene;

	scene = ft_scene_reader(scenetxt);
	scene->save = save;
	scene->mlx_ptrs->mlx_ptr = mlx_init();
	params_error(scene);
	scene->mlx_ptrs->win_ptr = mlx_new_window(scene->mlx_ptrs->mlx_ptr,
	scene->resolution->x, scene->resolution->y, "MiniRT");
	scene->mlx_ptrs->img_ptr = mlx_new_image(scene->mlx_ptrs->mlx_ptr,
	scene->resolution->x, scene->resolution->y);
	scene->camera = scene->cameraread->content;
	mlx_key_hook(scene->mlx_ptrs->win_ptr, ft_manage_key, &scene);
	mlx_loop_hook(scene->mlx_ptrs->mlx_ptr, ft_scene_creator, scene);
	mlx_loop(scene->mlx_ptrs->mlx_ptr);
}
