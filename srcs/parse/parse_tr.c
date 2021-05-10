/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:34:18 by xli               #+#    #+#             */
/*   Updated: 2021/05/10 10:29:02 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_tr_norm_0(t_triangle *triangle, char *str, int ct)
{
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("color for triangle is invalid\n");
		triangle->color[ct] = ft_atoi_max(&str);
		if (triangle->color[ct] < 0 || triangle->color[ct] > 255)
			error_exit("color for triangle is out of range\n");
	}
}

static void	parse_tr_norm_1(t_triangle *triangle, char **str)
{
	int		ct[2];
	double	sign;

	ct[0] = -1;
	while (++ct[0] < 3)
	{
		ct[1] = -1;
		while (++ct[1] < 3)
		{
			sign = 1.0;
			while (**str && ft_isdigit(**str) == 0 && **str != '.'
				&& **str != '-')
				(*str)++;
			if (**str == 0)
				error_exit("coordinate for triangle invalid\n");
			if (**str == '-')
			{
				sign *= -1.0;
				if (!(ft_isdigit(*(++(*str)))))
					error_exit("negative number in wrong format\n");
			}
			triangle->point[ct[0]][ct[1]] = sign * ft_atodouble(str);
		}
	}
}

void	parse_tr(t_parse *parse, char *str)
{
	t_triangle	*triangle;

	triangle = init_triangle();
	ft_lstadd_back(&(parse->objects), ft_lstnew(init_objects(tr, triangle)));
	parse_tr_norm_1(triangle, &str);
	parse_tr_norm_0(triangle, str, -1);
	triangle->vector[0]
		= two_points_vector(triangle->point[0], triangle->point[1]);
	triangle->vector[1]
		= two_points_vector(triangle->point[0], triangle->point[2]);
	triangle->orientation = cross(triangle->vector[0], triangle->vector[1]);
	if (triangle->orientation == NULL)
		error_exit("parse_triangle\n");
	if (triangle->orientation[0] == 0.0 && triangle->orientation[1] == 0.0
		&& triangle->orientation[2] == 0.0)
		error_exit("cannot form lines for triangle\n");
}
