/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:18:42 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 11:00:26 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	load_image(t_info *info)
{
	t_camera	*camera;

	info->parse->cur_camera = info->parse->camera;
	while (info->parse->cur_camera)
	{
		camera = info->parse->cur_camera->content;
		camera->img_ptr = mlx_new_image(info->mlx_ptr, info->parse->rx,
				info->parse->ry);
		camera->pixel = (int *)mlx_get_data_addr(camera->img_ptr,
				camera->bits_per_pixel, camera->size_line, camera->endian);
		put_screen(info);
		info->parse->cur_camera = info->parse->cur_camera->next;
	}
}
