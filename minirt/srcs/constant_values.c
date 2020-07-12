/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:52:33 by user42            #+#    #+#             */
/*   Updated: 2020/06/29 10:54:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raytracing.h"

t_vector    v_false(void)
{
    return (ft_vector_set(-INFINITY,-INFINITY,-INFINITY));
}

t_vector    v_true(void)
{
    return (ft_vector_set(INFINITY,INFINITY,INFINITY));
}