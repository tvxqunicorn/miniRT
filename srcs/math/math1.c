/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:57:14 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 12:08:35 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	solve_quadratic_equation(int *is_amounts, double is_points[2],
		double *coef)
{
	if (coef[1] * coef[1] - 4.0 * coef[0] * coef[2] < 0.0)
		*is_amounts = 0;
	else if (coef[1] * coef[1] - 4.0 * coef[0] * coef[2] == 0.0)
	{
		*is_amounts = 1;
		is_points[0] = (-1.0 * coef[1]) / (2.0 * coef[0]);
	}
	else
	{
		*is_amounts = 2;
		is_points[0] = (-1.0 * coef[1] - sqrt(coef[1] * coef[1]
					- 4.0 * coef[0] * coef[2])) / (2.0 * coef[0]);
		is_points[1] = (-1.0 * coef[1] + sqrt(coef[1] * coef[1]
					- 4.0 * coef[0] * coef[2])) / (2.0 * coef[0]);
	}
}

void	linear_equations(double *u, double *v, double *w, double *ans)
{
	int	ct[3];

	ct[0] = -1;
	ct[2] = 1;
	while (ct[2] && ++ct[0] < 3)
	{
		ct[1] = -1;
		while (ct[2] && ++ct[1] < 3)
		{
			if (ct[0] == ct[1] || u[ct[0]] == 0.0
				|| v[ct[0]] * u[ct[1]] - u[ct[0]] * v[ct[1]] == 0.0)
				continue ;
			ct[2] = 0;
		}
	}
	if (ct[2])
		error_exit("linear_equations\n");
	ans[1] = (w[ct[0]] * u[ct[1]] - u[ct[0]] * w[ct[1]])
		/ (v[ct[0]] * u[ct[1]] - u[ct[0]] * v[ct[1]]);
	ans[0] = (w[ct[0]] - v[ct[0]] * ans[1]) / u[ct[0]];
}

double	dot(double *v1, double *v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

double	linear_equation(double *coef, t_line *line)
{
	return (-1 * (coef[0] * line->x[1] + coef[1] * line->y[1]
			+ coef[2] * line->z[1] + coef[3]) / (coef[0] * line->x[0]
			+ coef[1] * line->y[0] + coef[2] * line->z[0]));
}

double	cos_vector(double *v1, double *v2)
{
	return (dot(v1, v2) / len(v1) / len(v2));
}
