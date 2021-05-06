/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:28:06 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 15:11:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_sp_norm(t_sphere *sphere, char *str)
{
	int	ct;

	while (*str && ft_isdigit(*str) == 0 && *str != '.')
		str++;
	if (*str == 0)
		error_exit("diameter for sphere invalid\n");
	sphere->diameter = ft_atodouble(&str);
	if (sphere->diameter < 0.0)
		error_exit("negative diameter for sphere\n");
	ct = -1;
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) && *str != '.')
			str++;
		if (*str == 0)
			error_exit("color for sphere invalid\n");
		sphere->color[ct] = (int)ft_atodouble(&str);
		if (sphere->color[ct] < 0 || sphere->color[ct] > 255)
			error_exit("color for sphere out of range\n");
	}
}

void	parse_sp(t_parse *parse, char *str)
{
	int			ct;
	t_sphere	*sphere;
	double		sign;

	sphere = init_sphere();
	ft_lstadd_back(&(parse->objects), ft_lstnew(init_objects(sp, sphere)));
	ct = -1;
	while (++ct < 3)
	{
		sign = 1.0;
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("coordinate for sphere invalid\n");
		if (*str == '-')
		{
			sign *= -1.0;
			if (!(ft_isdigit(*(++str))))
				error_exit("negative number in wrong fomat\n");
		}
		sphere->coordinate[ct] = sign * ft_atodouble(&str);
	}
	parse_sp_norm(sphere, str);
}
