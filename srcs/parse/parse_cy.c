/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:30:32 by xli               #+#    #+#             */
/*   Updated: 2021/05/10 10:30:30 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_cy_norm_0(t_cylinder *cylinder)
{
	modify_length(cylinder->orientation, cylinder->height / 2.0);
	cylinder->end_point[1]
		= two_points_vector(cylinder->orientation, cylinder->coordinate);
	modify_length(cylinder->orientation, -1.0 * cylinder->height);
	cylinder->end_point[0]
		= two_points_vector(cylinder->orientation, cylinder->end_point[1]);
	cylinder->middle_line
		= two_points_line(cylinder->end_point[0], cylinder->end_point[1]);
}

static void	parse_cy_norm_1(t_cylinder *cylinder, char *str, int ct)
{
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("color for cylinder invalid\n");
		cylinder->color[ct] = ft_atoi_max(&str);
		if (cylinder->color[ct] < 0 || cylinder->color[ct] > 255)
			error_exit("color for cylinder out of range\n");
	}
	parse_cy_norm_0(cylinder);
}

static void	parse_cy_norm_2(t_cylinder *cylinder, char *str, int ct)
{
	double	sign;

	while (++ct < 3)
	{
		sign = -1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("orientation for cylinder is invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		cylinder->orientation[ct] = sign * ft_atodouble(&str);
		if (cylinder->orientation[ct] < -1.0
			|| cylinder->orientation[ct] > 1.0)
			error_exit("orientation for cylinder out of range\n");
	}
	cylinder->diameter = ft_atodouble(&str);
	cylinder->height = ft_atodouble(&str);
	parse_cy_norm_1(cylinder, str, -1);
}

void	parse_cy(t_parse *parse, char *str)
{
	int			ct;
	t_cylinder	*cylinder;
	double		sign;

	cylinder = init_cylinder();
	ft_lstadd_back(&(parse->objects), ft_lstnew(init_objects(cy, cylinder)));
	ct = -1;
	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("coordinate for cylinder invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		cylinder->coordinate[ct] = sign * ft_atodouble(&str);
	}
	parse_cy_norm_2(cylinder, str, -1);
}
