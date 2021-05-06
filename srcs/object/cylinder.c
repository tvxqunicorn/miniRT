/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:59:47 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 14:13:07 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*init_cylinder(void)
{
	int			ct;
	t_cylinder	*cylinder;

	cylinder = ft_malloc(1, sizeof(t_cylinder));
	if (cylinder == NULL)
		error_exit("ERROR_IN_INIT_CYLINDER\n");
	ct = -1;
	while (++ct < 3)
		cylinder->coordinate[ct] = 0.0;
	ct = -1;
	while (++ct < 3)
		cylinder->orientation[ct] = 0.0;
	cylinder->diameter = 0.0;
	cylinder->height = 0.0;
	ct = -1;
	while (++ct < 3)
		cylinder->color[ct] = 0;
	return (cylinder);
}

static void	cylinder_coef_sub(double *coef, double *alpha,
t_cylinder *cylinder)
{
	coef[0] = -1.0 * alpha[2] * alpha[2] / alpha[0] + alpha[1];
	coef[1] = 2.0 * alpha[2] * (alpha[3] - alpha[4]) / alpha[0]
		+ 2.0 * (alpha[6] - alpha[5]);
	coef[2] = -1.0 * (alpha[4] - alpha[3]) * (alpha[4] - alpha[3])
		/ alpha[0] + alpha[7] + alpha[8] - 2 * alpha[9] - cylinder->diameter
		* cylinder->diameter / 4.0;
}

void	cylinder_coef(double *coef, double *alpha, t_line *view_ray,
t_cylinder *cylinder)
{
	double	p[2][3];
	double	v[2][3];

	copy_vector(p[0], cylinder->end_point[0]);
	p[1][0] = view_ray->x[1];
	p[1][1] = view_ray->y[1];
	p[1][2] = view_ray->z[1];
	copy_vector(v[0], cylinder->orientation);
	v[1][0] = view_ray->x[0];
	v[1][1] = view_ray->y[0];
	v[1][2] = view_ray->z[0];
	alpha[0] = v[0][0] * v[0][0] + v[0][1] * v[0][1] + v[0][2] * v[0][2];
	alpha[1] = v[1][0] * v[1][0] + v[1][1] * v[1][1] + v[1][2] * v[1][2];
	alpha[2] = dot((double *)v[0], (double *)v[1]);
	alpha[3] = dot((double *)v[0], (double *)p[0]);
	alpha[4] = dot((double *)v[0], (double *)p[1]);
	alpha[5] = dot((double *)v[1], (double *)p[0]);
	alpha[6] = dot((double *)v[1], (double *)p[1]);
	alpha[7] = p[0][0] * p[0][0] + p[0][1] * p[0][1] + p[0][2] * p[0][2];
	alpha[8] = p[1][0] * p[1][0] + p[1][1] * p[1][1] + p[1][2] * p[1][2];
	alpha[9] = dot((double *)p[0], (double *)p[1]);
	cylinder_coef_sub(coef, alpha, cylinder);
}

void	get_cylinder_normal_vector(double normal_vector[3],
	t_cylinder *cylinder, double coordinate[3])
{
	int		ct;
	double	*vector[2];

	if (double_abs(dot(cylinder->orientation, coordinate)
			- dot(cylinder->orientation, cylinder->end_point[0])) < 1e-6
		|| double_abs(dot(cylinder->orientation, coordinate)
			- dot(cylinder->orientation, cylinder->end_point[1])) < 1e-6)
	{
		ct = -1;
		while (++ct < 3)
			normal_vector[ct] = cylinder->orientation[ct];
	}
	else
	{
		vector[0] = two_points_vector(cylinder->end_point[0], coordinate);
		vector[1] = cross(vector[0], cylinder->orientation);
		normal_vector = cross(cylinder->orientation, vector[1]);
	}
}
