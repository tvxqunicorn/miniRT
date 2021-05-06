/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:11:57 by xli               #+#    #+#             */
/*   Updated: 2021/04/23 09:47:13 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	len(double *v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

void	modify_length(double *vector, double length)
{
	double	multiply;
	int		ct;

	multiply = length / len(vector);
	ct = -1;
	while (++ct < 3)
		vector[ct] *= multiply;
}

double	*cross(double *v1, double *v2)
{
	double	*new;

	new = ft_malloc(3, sizeof(double));
	if (new == NULL)
		return (NULL);
	new[0] = v1[1] * v2[2] - v1[2] * v2[1];
	new[1] = v1[2] * v2[0] - v1[0] * v2[2];
	new[2] = v1[0] * v2[1] - v1[1] * v2[0];
	return (new);
}

t_line	*two_points_line(double a[3], double b[3])
{
	t_line	*line;

	line = ft_malloc(1, sizeof(t_line));
	if (line == NULL)
		return (NULL);
	line->x[0] = b[0] - a[0];
	line->x[1] = a[0];
	line->y[0] = b[1] - a[1];
	line->y[1] = a[1];
	line->z[0] = b[2] - a[2];
	line->z[1] = a[2];
	return (line);
}

double	double_abs(double a)
{
	if (a < 0.0)
		return (-1.0 * a);
	return (a);
}
