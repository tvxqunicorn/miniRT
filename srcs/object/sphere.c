/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:42:40 by xli               #+#    #+#             */
/*   Updated: 2021/04/22 11:24:38 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*init_sphere(void)
{
	int			count;
	t_sphere	*sphere;

	sphere = ft_malloc(1, sizeof(t_sphere));
	if (sphere == NULL)
		error_exit("ERROR_IN_INIT_SPHERE\n");
	count = -1;
	while (++count < 3)
		sphere->coordinate[count] = 0.0;
	sphere->diameter = 0.0;
	count = -1;
	while (++count < 3)
		sphere->color[count] = 0;
	return (sphere);
}

void	get_is_points_with_sphere(t_line *view_ray, t_sphere *sphere,
	int *is_amounts, double is_points[2])
{
	double	coef[3];

	coef[0] = view_ray->x[0] * view_ray->x[0] + view_ray->y[0] * view_ray->y[0]
		+ view_ray->z[0] * view_ray->z[0];
	coef[1] = 2.0 * (view_ray->x[0] * (view_ray->x[1] - sphere->coordinate[0])
			+ view_ray->y[0] * (view_ray->y[1] - sphere->coordinate[1])
			+ view_ray->z[0] * (view_ray->z[1] - sphere->coordinate[2]));
	coef[2] = (view_ray->x[1] - sphere->coordinate[0])
		* (view_ray->x[1] - sphere->coordinate[0])
		+ (view_ray->y[1] - sphere->coordinate[1])
		* (view_ray->y[1] - sphere->coordinate[1])
		+ (view_ray->z[1] - sphere->coordinate[2])
		* (view_ray->z[1] - sphere->coordinate[2])
		- sphere->diameter * sphere->diameter / 4.0;
	solve_quadratic_equation(is_amounts, is_points, coef);
}

void	get_sphere_normal_vector(double normal_vector[3], t_sphere *sphere,
	double coordinate[3])
{
	int	ct;

	ct = -1;
	while (++ct < 3)
		normal_vector[ct] = coordinate[ct] - sphere->coordinate[ct];
}
