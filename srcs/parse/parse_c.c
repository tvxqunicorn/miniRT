/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:39:33 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 15:11:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_c_norm_0(t_camera *camera, char *str, int ct)
{
	double	sign;

	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("orientation for camera is invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		camera->orientation[ct] = sign * ft_atodouble(&str);
		if (camera->orientation[ct] < -1.0
			|| camera->orientation[ct] > 1.0)
			error_exit("orientation for camera out of range\n");
	}
	camera->fov = (int)ft_atodouble(&str);
	if (camera->fov < 0.0 || camera->fov > 180.0)
		error_exit("fov out of range\n");
}

void	parse_c(t_parse *parse, char *str)
{
	int			ct;
	t_camera	*camera;
	double		sign;

	camera = init_camera();
	ft_lstadd_back(&(parse->camera), ft_lstnew(camera));
	ct = -1;
	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("coordinate for camera invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		camera->coordinate[ct] = sign * ft_atodouble(&str);
	}
	parse_c_norm_0(camera, str, -1);
}
