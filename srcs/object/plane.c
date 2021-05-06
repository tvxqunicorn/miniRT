/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:47:36 by xli               #+#    #+#             */
/*   Updated: 2021/04/29 09:31:45 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*init_plane(void)
{
	int		count;
	t_plane	*plane;

	plane = ft_malloc(1, sizeof(t_plane));
	if (plane == NULL)
		error_exit("ERROR_IN_INIT_PLANE\n");
	count = -1;
	while (++count < 3)
		plane->coordinate[count] = 0.0;
	count = -1;
	while (++count < 3)
		plane->orientation[count] = 0.0;
	count = -1;
	while (++count < 3)
		plane->color[count] = 0;
	return (plane);
}

void	get_is_points_with_plane(t_line *view_ray, t_plane *plane,
	int *is_amounts, double is_points[2])
{
	double	coef[4];
	double	vector[3];
	double	res;

	vector[0] = view_ray->x[0];
	vector[1] = view_ray->y[0];
	vector[2] = view_ray->z[0];
	res = cos_vector(plane->orientation, vector);
	*is_amounts = 0;
	if (res < 1e-6 && res > -1e-6)
		return ;
	coef[0] = plane->orientation[0];
	coef[1] = plane->orientation[1];
	coef[2] = plane->orientation[2];
	coef[3] = -1.0 * (plane->coordinate[0] * coef[0]
			+ plane->coordinate[1] * coef[1] + plane->coordinate[2] * coef[2]);
	res = linear_equation(coef, view_ray);
	*is_amounts = 1;
	is_points[0] = res;
}

void	get_plane_normal_vector(double normal_vector[3], t_plane *plane,
	double coordinate[3])
{
	int	ct;

	(void)coordinate;
	ct = -1;
	while (++ct < 3)
		normal_vector[ct] = plane->orientation[ct];
}
