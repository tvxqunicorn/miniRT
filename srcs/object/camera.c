/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:43:12 by xli               #+#    #+#             */
/*   Updated: 2021/04/07 14:37:06 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;
	static int	num = 0;

	camera = ft_malloc(1, sizeof(t_camera));
	if (camera == NULL)
		error_exit("ERROR_IN_INIT_CAMERA\n");
	camera->fov = 0.0;
	camera->num = num++;
	camera->distance_to_screen = 0.0;
	camera->img_ptr = NULL;
	camera->bits_per_pixel = ft_malloc(1, sizeof(int));
	if (camera->bits_per_pixel == NULL)
		error_exit("ERROR_IN_INIT_CAMERA_BPP\n");
	camera->size_line = ft_malloc(1, sizeof(int));
	if (camera->size_line == NULL)
		error_exit("ERROR_IN_INIT_CAMERA_LINE\n");
	camera->endian = ft_malloc(1, sizeof(int));
	if (camera->endian == NULL)
		error_exit("ERROR_IN_INIT_ENDIAN\n");
	return (camera);
}
