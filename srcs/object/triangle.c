/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:06:37 by xli               #+#    #+#             */
/*   Updated: 2021/04/29 09:32:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triangle	*init_triangle(void)
{
	int			ct[2];
	t_triangle	*triangle;

	triangle = ft_malloc(1, sizeof(t_triangle));
	if (triangle == NULL)
		error_exit("ERROR_IN_INIT_TRIANGLE\n");
	ct[0] = -1;
	while (++ct[0] < 3)
	{
		ct[1] = -1;
		while (++ct[1] < 3)
			triangle->point[ct[0]][ct[1]] = 0.0;
	}
	ct[0] = -1;
	while (++ct[0] < 3)
		triangle->color[ct[0]] = 0;
	return (triangle);
}

static int	get_is_points_with_triangle_norm_0(t_line *view_ray,
	t_triangle *triangle, double t)
{
	double	point[3];
	double	*v;
	double	ans[2];

	point[0] = view_ray->x[0] * t + view_ray->x[1];
	point[1] = view_ray->y[0] * t + view_ray->y[1];
	point[2] = view_ray->z[0] * t + view_ray->z[1];
	v = two_points_vector(triangle->point[0], point);
	linear_equations(triangle->vector[0], triangle->vector[1], v, ans);
	ft_free(v);
	if (ans[0] > 1e-6 && ans[1] > 1e-6 && ans[0] + ans[1] <= 1.0 - 1e-6)
		return (1);
	return (0);
}

void	get_is_points_with_triangle(t_line *view_ray, t_triangle *triangle,
	int *is_amounts, double is_points[2])
{
	double	coef[4];
	double	vector[3];
	double	res;

	vector[0] = view_ray->x[0];
	vector[1] = view_ray->y[0];
	vector[2] = view_ray->z[0];
	res = cos_vector(triangle->orientation, vector);
	*is_amounts = 0;
	if (res < 1e-6 && res > -1e-6)
		return ;
	coef[0] = triangle->orientation[0];
	coef[1] = triangle->orientation[1];
	coef[2] = triangle->orientation[2];
	coef[3] = -1.0 * (triangle->point[0][0] * coef[0]
			+ triangle->point[0][1] * coef[1]
			+ triangle->point[0][2] * coef[2]);
	res = linear_equation(coef, view_ray);
	if (get_is_points_with_triangle_norm_0(view_ray, triangle, res) == 0)
		return ;
	*is_amounts = 1;
	is_points[0] = res;
}

void	get_triangle_normal_vector(double normal_vector[3],
	t_triangle *triangle, double coordinate[3])
{
	int	ct;

	(void)coordinate;
	ct = -1;
	while (++ct < 3)
		normal_vector[ct] = triangle->orientation[ct];
}
