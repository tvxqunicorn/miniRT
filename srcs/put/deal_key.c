/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:40:44 by xli               #+#    #+#             */
/*   Updated: 2021/04/21 14:59:58 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	change_camera(t_info *info)
{
	t_parse		*parse;
	t_camera	*camera;
	int			x;
	int			y;

	parse = info->parse;
	if (info->parse->cur_camera == NULL
		|| info->parse->cur_camera->next == NULL)
		info->parse->cur_camera = info->parse->camera;
	else
		info->parse->cur_camera = info->parse->cur_camera->next;
	camera = info->parse->cur_camera->content;
	x = -1;
	while (++x < parse->rx)
	{
		y = -1;
		while (++y < parse->ry)
			mlx_pixel_put(info->mlx_ptr, info->win_ptr, x, y,
				camera->pixel[x + info->parse->rx * y]);
	}
}

int	deal_key(int key, void *pointer)
{
	t_info	*info;

	info = pointer;
	if (key == ESC)
		close_program(info);
	if (key == SPACE)
		change_camera(info);
	if (!(info->parse->cur_camera))
		return (0);
	return (0);
}
