/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 19:58:49 by chema             #+#    #+#             */
/*   Updated: 2020/06/29 10:55:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAYTRACING_H
# define FT_RAYTRACING_H
# include "minilibx/mlx.h"
# include "getnextline/get_next_line.h"
# include "libft/libft.h"
# include "srcs/vector.h"
# include "srcs/color.h"
# include "printf/libftprintf.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef MPI
#  define M_PI 3.14159265358979323846
# endif

typedef struct		s_resolution
{
	int				x;
	int				y;
}					t_resolution;

typedef struct		s_ambient_light
{
	float			ratio;
	t_color			color;
}					t_ambient_light;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		direction;
	int				fieldofview;
}					t_camera;

typedef struct		s_light
{
	t_vector		origin;
	float			brightness;
	t_color			color;
}					t_light;

typedef struct		s_sphere
{
	t_vector		origin;
	float			radius;
	t_color			color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		origin;
	t_vector		direction;
	t_color			color;
}					t_plane;

typedef struct		s_square
{
	t_vector		origin;
	t_vector		direction;
	float			side_size;
	t_color			color;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		origin;
	t_vector		direction;
	float			diameter;
	float			height;
	t_color			color;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		point_first;
	t_vector		point_second;
	t_vector		point_third;
	t_color			color;
}					t_triangle;

typedef struct		s_phong
{
	t_vector		am;
	t_vector		sp;
	t_vector		di;
}					t_phong;

typedef	struct		s_hit
{
	float			t;
	t_vector		normal;
	t_sphere		*sphere;
	t_plane			*plane;
	t_square		*square;
	t_cylinder		*cylinder;
	t_triangle		*triangle;
	t_vector		phit;
}					t_hit;

typedef struct		s_mlx_ptrs
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_mlx_ptrs;
typedef struct		s_scene
{
	t_resolution	*resolution;
	t_ambient_light	*ambient_light;
	t_list			*cameraread;
	t_camera		*camera;
	int				camera_number;
	t_list			*lightread;
	t_light			*light;
	t_list			*sphere;
	t_list			*sphereread;
	t_list			*plane;
	t_list			*planeread;
	t_list			*square;
	t_list			*squareread;
	t_list			*cylinder;
	t_list			*cylinderread;
	t_list			*triangle;
	t_list			*triangleread;
	int				save;
	t_mlx_ptrs		*mlx_ptrs;
}					t_scene;

void				minirt(char *scenetxt, int save);
float				ft_atof(const char *str);
char				*ft_strchrs(char *s, char *chars);
t_color				ft_read_color(char *line);
t_vector			ft_read_vector(char *line);
int					ft_read_resolution(char *line, t_scene **scene);
int					ft_read_ambient_light(char *line, t_scene **scene);
int					ft_read_camera(char *line, t_scene **scene);
int					ft_read_light(char *line, t_scene **scene);
int					ft_read_sphere(char *line, t_scene **scene);
int					ft_read_plane(char *line, t_scene **scene);
int					ft_read_square(char *line, t_scene **scene);
int					ft_read_cylinder(char *line, t_scene **scene);
int					ft_read_triangle(char *line, t_scene **scene);

int					ft_scene_creator(t_scene *scene);
t_hit				get_hit_sphere(t_scene *scene, t_ray ray, t_hit min_h);
t_hit				get_hit_plane(t_scene *scene, t_ray ray, t_hit min_h);
t_hit				get_hit_square(t_scene *scene, t_ray ray, t_hit min_h);
t_hit				get_hit_triangle(t_scene *scene, t_ray ray, t_hit min_h);
t_hit				get_hit_cylinder(t_scene *scene, t_ray ray, t_hit min_h);
int					ft_sphere_print(t_scene *scene, t_color **pixel_color);

t_vector			apply_rot(t_vector pos, t_vector dir, t_vector rot);
int					compute_ray(t_ray *ray, int x, int y, t_scene *scene);
void				init_hit(t_hit *hit);
t_hit				get_hit(t_scene *scene, t_ray ray);
t_vector			get_hit_color(t_hit hit);

t_color				get_color_w(t_scene *scene, t_ray ray);

void				destroy_n_exit(t_scene **scene);
int					ft_manage_key(int key, t_scene **scene);
void				ft_change_camera_adv(t_scene **scene);
void				ft_change_camera_rev(t_scene **scene);

t_vector			process_normal(t_ray ray, t_vector normal);
void				get_color_loop(t_scene *scene, t_hit hit,
					t_phong **ph, t_ray ray);
					
					t_vector    v_false(void);
					t_vector    v_true(void);
#endif
