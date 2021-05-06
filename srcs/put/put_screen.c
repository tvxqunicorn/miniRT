/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:51:28 by xli               #+#    #+#             */
/*   Updated: 2021/04/16 17:14:36 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_all(t_info *info)
{
	double	*u;
	double	*v;
	int		pixel[2];

	get_u_v_vector(info, &u, &v);
	get_eye_coordinate(info->parse->cur_camera->content);
	pixel[0] = -1;
	while (++pixel[0] < info->parse->rx)
	{
		pixel[1] = -1;
		while (++pixel[1] < info->parse->ry)
			get_pixel(pixel, info, u, v);
	}
}

void	put_screen(t_info *info)
{
	t_camera	*camera;

	if (info->parse->cur_camera == NULL)
		error_exit("camera not found, cannot put screen\n");
	camera = (t_camera *)info->parse->cur_camera->content;
	if (camera->fov > 170.0)
		camera->fov = 170.0;
	if (camera->fov < 1.0)
		camera->fov = 1.0;
	if (camera->distance_to_screen == 0.0)
		camera->distance_to_screen = ((double)info->parse->rx)
			/ 2.0 / tan(camera->fov / 2.0 * M_PI / 180.0);
	put_all(info);
}
