/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:00:09 by xli               #+#    #+#             */
/*   Updated: 2021/04/16 16:51:25 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_u_v_vector(t_info *info, double **return_u, double **return_v)
{
	t_camera	*camera;
	double		base_v[3];
	double		*v;
	double		*u;

	camera = info->parse->cur_camera->content;
	base_v[0] = 0.0;
	if (camera->orientation[0] == 0.0 && camera->orientation[1] == 0.0)
		base_v[1] = 1.0;
	else
		base_v[1] = 0.0;
	base_v[2] = 1.0 - base_v[1];
	u = cross(base_v, camera->orientation);
	v = cross(u, camera->orientation);
	modify_length(u, 1.0);
	modify_length(v, 1.0);
	*return_u = u;
	*return_v = v;
}

void	get_eye_coordinate(t_camera *camera)
{
	int			ct;

	ct = -1;
	while (++ct < 3)
		camera->eye_coordinate[ct] = camera->orientation[ct];
	modify_length(camera->eye_coordinate, -1 * camera->distance_to_screen);
	ct = -1;
	while (++ct < 3)
		camera->eye_coordinate[ct] += camera->coordinate[ct];
}

void	get_pixel(int *xy, t_info *info, double *u, double *v)
{
	double		pixel_coordinate[3];
	t_camera	*camera;
	double		pixel[2];
	int			ct;
	t_line		*view_ray;

	camera = info->parse->cur_camera->content;
	ct = -1;
	while (++ct < 3)
		pixel_coordinate[ct] = camera->coordinate[ct];
	pixel[0] = (double)info->parse->rx;
	pixel[1] = (double)info->parse->ry;
	ct = -1;
	while (++ct < 3)
		pixel_coordinate[ct] -= (pixel[0] / 2.0) * u[ct]
			+ (pixel[1] / 2.0) * v[ct];
	ct = -1;
	while (++ct < 3)
		pixel_coordinate[ct] += (double)xy[0] * u[ct] + (double)xy[1] * v[ct];
	view_ray = two_points_line(camera->eye_coordinate, pixel_coordinate);
	get_intersect(xy, view_ray, info);
}
