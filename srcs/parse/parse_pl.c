/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:28:58 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 15:11:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_pl_norm_0(t_plane *plane, char *str, int ct)
{
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) && *str != '.')
			str++;
		if (*str == 0)
			error_exit("color for plane invalid\n");
		plane->color[ct] = (int)ft_atodouble(&str);
		if (plane->color[ct] < 0 || plane->color[ct] > 255)
			error_exit("color for plane out of range\n");
	}
}

static void	parse_pl_norm_1(t_plane *plane, char *str, int ct)
{
	double	sign;

	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("orientation for plane invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		plane->orientation[ct] = sign * ft_atodouble(&str);
		if (plane->orientation[ct] < -1 || plane->orientation[ct] > 1)
			error_exit("orientation for plane out of range\n");
	}
	parse_pl_norm_0(plane, str, -1);
}

void	parse_pl(t_parse *parse, char *str)
{
	int		ct;
	t_plane	*plane;
	double	sign;

	plane = init_plane();
	ft_lstadd_back(&(parse->objects), ft_lstnew(init_objects(pl, plane)));
	ct = -1;
	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("coordinate for plane invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong fomat\n");
		}
		plane->coordinate[ct] = sign * ft_atodouble(&str);
	}
	parse_pl_norm_1(plane, str, -1);
}
