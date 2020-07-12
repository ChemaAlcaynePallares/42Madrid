/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 14:59:06 by chema             #+#    #+#             */
/*   Updated: 2020/06/26 11:17:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

t_vector		ft_vector_set(float x, float y, float z);
t_vector		ft_vector_sum(t_vector vec1, t_vector vec2);
t_vector		ft_vector_min(t_vector vec1, t_vector vec2);
t_vector		ft_vector_mul_vec(t_vector vec1, t_vector vec2);
t_vector		ft_vector_div_vec(t_vector vec1, t_vector vec2);
t_vector		ft_vector_mul(t_vector vec1, float t);
t_vector		ft_vector_div(t_vector vec1, float t);
float			dot(t_vector vec1, t_vector vec2);
t_vector		cross(t_vector vec1, t_vector vec2);
t_vector		ft_vector_normalize(t_vector vec1);
t_vector		ft_vector_invert(t_vector vec);
float			magnitude(t_vector a);
float			dist(t_vector a, t_vector b);
t_vector		c_to_vec(t_vector color);
t_vector		clamp(t_vector vec);
#endif
