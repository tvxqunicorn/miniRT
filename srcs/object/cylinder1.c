/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:39:10 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 14:15:59 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	assign_v(double v[3][3], t_line *view_ray)
{
	v[0][0] = view_ray->x[1];
	v[0][1] = view_ray->y[1];
	v[0][2] = view_ray->z[1];
	v[1][0] = view_ray->x[0];
	v[1][1] = view_ray->y[0];
	v[1][2] = view_ray->z[0];
}

static void	get_is_points_with_cylinder_norm_0(t_cylinder *cylinder,
	double v[3][3], int *is_amount, double is_points[2])
{
	double	s;
	int		ct;

	ct = 0;
	s = (dot(cylinder->orientation, cylinder->end_point[ct])
			- dot(cylinder->orientation, (double *)v[0]))
		/ dot(cylinder->orientation, (double *)v[1]);
	v[2][0] = v[0][0] + v[1][0] * s;
	v[2][1] = v[0][1] + v[1][1] * s;
	v[2][2] = v[0][2] + v[1][2] * s;
	if (two_points_distance((double *)v[2], (double *)(cylinder->end_point[ct]))
	<= cylinder->diameter / 2.0)
		is_points[(*is_amount)++] = s;
}

static void	get_is_points_with_cylinder_norm_1(t_cylinder *cylinder,
	double v[3][3], int *is_amount, double is_points[2])
{
	double	s;
	int		ct;

	ct = 1;
	s = (dot(cylinder->orientation, cylinder->end_point[ct])
			- dot(cylinder->orientation, (double *)v[0]))
		/ dot(cylinder->orientation, (double *)v[1]);
	v[2][0] = v[0][0] + v[1][0] * s;
	v[2][1] = v[0][1] + v[1][1] * s;
	v[2][2] = v[0][2] + v[1][2] * s;
	if (two_points_distance((double *)v[2], (double *)(cylinder->end_point[ct]))
	<= cylinder->diameter / 2.0)
		is_points[(*is_amount)++] = s;
}

void	get_is_points_with_cylinder(t_line *view_ray, t_cylinder *cylinder,
	int *is_amounts, double is_points[2])
{
	double	coef[4];
	double	alpha[10];
	double	v[3][3];
	double	res[3];
	int		ct;

	assign_v(v, view_ray);
	*is_amounts = 0;
	get_is_points_with_cylinder_norm_0(cylinder, v, is_amounts, is_points);
	get_is_points_with_cylinder_norm_1(cylinder, v, is_amounts, is_points);
	cylinder_coef(coef, alpha, view_ray, cylinder);
	if (quadratic_equation(coef, res) <= 0)
		return ;
	ct = -1;
	while (++ct < 2)
	{
		if (res[0] - res[1] < 1e-6 && res[0] - res[1] > -1e-6 && ct == 1)
			break ;
		res[2] = (alpha[2] * res[ct] + alpha[4] - alpha[3]) / alpha[0];
		if (res[2] > 1e-6 && res[2] < 1.0 - 1e-6)
			is_points[(*is_amounts)++] = res[ct];
	}
}
