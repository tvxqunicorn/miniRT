/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:29:46 by xli               #+#    #+#             */
/*   Updated: 2021/04/28 14:16:12 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_sq_norm_0(t_square *square)
{
	double	base_v[3];
	int		ct;

	base_v[0] = 0.0;
	if (square->orientation[1] == 0.0 && square->orientation[0] == 0.0)
		base_v[1] = 1.0;
	else
		base_v[1] = 0.0;
	base_v[2] = 1.0 - base_v[1];
	square->vector[0] = cross(base_v, square->orientation);
	square->vector[1] = cross(square->vector[0], square->orientation);
	modify_length(square->vector[0], square->side_size);
	modify_length(square->vector[1], square->side_size);
	ct = -1;
	while (++ct < 3)
		square->start_point[ct] = square->coordinate[ct]
			- square->vector[0][ct] / 2.0 - square->vector[1][ct] / 2.0;
}

static void	parse_sq_norm_1(t_square *square, char *str, int ct)
{
	if (*str == 0)
		error_exit("couldn't find valid side_size for square\n");
	square->side_size = ft_atodouble(&str);
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) == 0 && *str != '.')
			str++;
		if (*str == 0)
			error_exit("color for square is invalid\n");
		square->color[ct] = (int)ft_atodouble(&str);
		if (square->color[ct] < 0 || square->color[ct] > 255)
			error_exit("color for square is out of range\n");
	}
	parse_sq_norm_0(square);
}

static void	parse_sq_norm_2(t_square *square, char *str, int ct)
{
	double	sign;

	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("orientation for square is invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		square->orientation[ct] = sign * ft_atodouble(&str);
		if (square->orientation[ct] < -1.0
			|| square->orientation[ct] > 1.0)
			error_exit("orientation for square out of range\n");
	}
	if (square->orientation[0] == 0.0 && square->orientation[1] == 0.0)
		square->orientation[2] = 1.0;
	while (*str && ft_isdigit(*str) == 0 && *str != '.')
		str++;
	parse_sq_norm_1(square, str, -1);
}

void	parse_sq(t_parse *parse, char *str)
{
	int			ct;
	t_square	*square;
	double		sign;

	square = init_square();
	ft_lstadd_back(&(parse->objects), ft_lstnew(init_objects(sq, square)));
	ct = -1;
	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("coordinate for square invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong format\n");
		}
		square->coordinate[ct] = sign * ft_atodouble(&str);
	}
	parse_sq_norm_2(square, str, -1);
}
