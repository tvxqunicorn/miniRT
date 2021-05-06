/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:45:31 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 12:09:11 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	*two_points_vector(double *start_point, double *end_point)
{
	double	*ans;

	ans = ft_malloc(3, sizeof(double));
	if (ans == NULL)
		error_exit("two_points_vector\n");
	ans[0] = end_point[0] - start_point[0];
	ans[1] = end_point[1] - start_point[1];
	ans[2] = end_point[2] - start_point[2];
	return (ans);
}

void	copy_vector(double *target, double *srcs)
{
	target[0] = srcs[0];
	target[1] = srcs[1];
	target[2] = srcs[2];
}

double	two_points_distance(double *a, double *b)
{
	return (sqrt((a[0] - b[0]) * (a[0] - b[0])
			+ (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2])));
}

int	quadratic_equation(double *coef, double *answer)
{
	double	det;

	if (!coef || !answer)
		return (-1);
	det = coef[1] * coef[1] - 4 * coef[0] * coef[2];
	if (det < 0.0)
		return (0);
	answer[0] = (-1.0 * coef[1] + sqrt(det)) / (2.0 * coef[0]);
	answer[1] = (-1.0 * coef[1] - sqrt(det)) / (2.0 * coef[0]);
	return (1);
}
