/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chema <chema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 15:00:29 by chema             #+#    #+#             */
/*   Updated: 2020/06/13 16:31:18 by chema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

t_color			ft_vector_to_color(t_vector vec);
int				color_to_int(t_color color);
t_color			ft_color_set(float r, float g, float b);
t_color			ft_color_mul(t_color color, float f);
t_color			ft_color_sum(t_color color1, t_color color2);
t_vector		ft_color_to_vector(t_color vec);
#endif
