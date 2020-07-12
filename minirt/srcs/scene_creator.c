/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 11:43:56 by chema             #+#    #+#             */
/*   Updated: 2020/06/28 11:22:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

static void	make_header(int fd, int w, int h)
{
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, \
		0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};
	unsigned int			*sizeoffileentry;
	unsigned int			*widthentry;
	unsigned int			*heightentry;

	sizeoffileentry = (unsigned int *)&header[2];
	*sizeoffileentry = 54 + (w * sizeof(char) + (4 - \
						((w * sizeof(char)) % 4)) % 4) * h;
	widthentry = (unsigned int *)&header[18];
	*widthentry = w;
	heightentry = (unsigned int *)&header[22];
	*heightentry = h;
	write(fd, header, 54);
}

static void	writedata(int w, int h, char **img_data, int fd)
{
	char					*ro;
	int						i;
	int						ln;
	static unsigned char	zeroes[3] = {0, 0, 0};

	ln = 0;
	i = 0;
	ro = (char *)malloc(sizeof(char) * (w * 4 * h + 1));
	while (ln++ < w)
	{
		(*img_data)--;
		*ro++ = *(*img_data)--;
		*ro++ = *(*img_data)--;
		*ro++ = *(*img_data)--;
	}
	ro--;
	while (i++ < w)
	{
		write(fd, ro--, sizeof(char));
		write(fd, ro--, sizeof(char));
		write(fd, ro--, sizeof(char));
	}
	write(fd, zeroes, (4 - ((w * sizeof(char)) % 4)) % 4);
	free(++ro);
}

static void	save_image(int w, int h, char *img_data)
{
	int	fd;
	int	row;

	img_data--;
	row = 0;
	fd = open("save_image.bmp", O_WRONLY);
	if (fd == -1)
		fd = open("save_image.bmp", O_WRONLY | O_CREAT);
	make_header(fd, w, h);
	while (row++ < h)
	{
		writedata(w, h, &img_data, fd);
	}
	close(fd);
}

static void	calc_scene(t_scene *scene, t_ray ray, char *img_data)
{
	int		x;
	int		y;
	t_color color;

	x = 0;
	y = 0;
	while (y < scene->resolution->y)
	{
		while (x < scene->resolution->x)
		{
			compute_ray(&ray, x, y, scene);
			color = get_color_w(scene, ray);
			*img_data++ = color.r;
			*img_data++ = color.g;
			*img_data++ = color.b;
			*img_data++ = 0;
			x++;
		}
		y++;
		x = 0;
	}
}

int			ft_scene_creator(t_scene *scene)
{
	char	*img_data;
	int		g_bpp;
	int		g_size_line;
	int		g_endian;
	t_ray	ray;

	ray.direction = ft_vector_set(0, 0, 0);
	img_data = mlx_get_data_addr(scene->mlx_ptrs->img_ptr,
		&g_bpp, &g_size_line, &g_endian);
	calc_scene(scene, ray, img_data);
	if (scene->save)
		save_image(scene->resolution->x, scene->resolution->y, img_data);
	scene->save = 0;
	mlx_put_image_to_window(scene->mlx_ptrs->mlx_ptr,
		scene->mlx_ptrs->win_ptr, scene->mlx_ptrs->img_ptr, 0, 0);
	return (1);
}
