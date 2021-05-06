/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:51:33 by xli               #+#    #+#             */
/*   Updated: 2021/04/29 09:32:29 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square	*init_square(void)
{
	int			ct;
	t_square	*square;

	square = ft_malloc(1, sizeof(t_square));
	if (square == NULL)
		error_exit("ERROR_IN_INIT_SQUARE\n");
	ct = -1;
	while (++ct < 3)
		square->coordinate[ct] = 0.0;
	ct = -1;
	while (++ct < 3)
		square->orientation[ct] = 0.0;
	square->side_size = 0.0;
	ct = -1;
	while (++ct < 3)
		square->color[ct] = 0;
	ct = -1;
	while (++ct < 3)
		square->start_point[ct] = 0.0;
	return (square);
}

static int	get_is_points_with_square_norm_0(t_line *view_ray, t_square *square,
	double t)
{
	double	point[3];
	double	*v;
	double	ans[2];

	point[0] = view_ray->x[0] * t + view_ray->x[1];
	point[1] = view_ray->y[0] * t + view_ray->y[1];
	point[2] = view_ray->z[0] * t + view_ray->z[1];
	v = two_points_vector(square->start_point, point);
	linear_equations(square->vector[0], square->vector[1], v, ans);
	ft_free(v);
	if (ans[0] < 1.0 - 1e-6 && ans[0] > 1e-6
		&& ans[1] < 1.0 - 1e-6 && ans[1] > 1e-6)
		return (1);
	return (0);
}

void	get_is_points_with_square(t_line *view_ray, t_square *square,
	int *is_amounts, double is_points[2])
{
	double	coef[4];
	double	vector[3];
	double	res;

	vector[0] = view_ray->x[0];
	vector[1] = view_ray->y[0];
	vector[2] = view_ray->z[0];
	res = cos_vector(square->orientation, vector);
	*is_amounts = 0;
	if (res < 1e-6 && res > -1e-6)
		return ;
	coef[0] = square->orientation[0];
	coef[1] = square->orientation[1];
	coef[2] = square->orientation[2];
	coef[3] = -1.0 * (square->coordinate[0] * coef[0]
			+ square->coordinate[1] * coef[1]
			+ square->coordinate[2] * coef[2]);
	res = linear_equation(coef, view_ray);
	if (get_is_points_with_square_norm_0(view_ray, square, res) == 0)
		return ;
	*is_amounts = 1;
	is_points[0] = res;
}

void	get_square_normal_vector(double normal_vector[3], t_square *square,
	double coordinate[3])
{
	int	ct;

	(void)coordinate;
	ct = -1;
	while (++ct < 3)
		normal_vector[ct] = square->orientation[ct];
}
