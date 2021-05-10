/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:10:09 by xli               #+#    #+#             */
/*   Updated: 2021/05/10 13:00:54 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_a_norm_0(t_parse *parse, char *str, int ct)
{
	while (++ct < 3)
	{
		while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
			str++;
		if (*str == 0)
			error_exit("ambient light color not found\n");
		parse->acolor[ct] = ft_atoi_max(&str);
		if (parse->acolor[ct] < 0 || parse->acolor[ct] > 255)
			error_exit("ambient light color invalid\n");
	}
}

void	parse_a(t_parse *parse, char *str)
{
	double	sign;

	sign = 1.0;
	if (parse->aratio != -1.0 || parse->acolor[0] != -1
		|| parse->acolor[1] != -1 || parse->acolor[2] != -1)
		error_exit("define ambient light mutiple times\n");
	while (*str && ft_isdigit(*str) == 0 && *str != '.' && *str != '-')
		str++;
	if (*str == 0)
		error_exit("ambient light ratio not found\n");
	if (*str == '-')
		sign *= -1.0;
	parse->aratio = sign * ft_atodouble(&str);
	if (parse->aratio < 0.0 || parse->aratio > 1.0)
		error_exit("ambient light ratio invalid\n");
	parse_a_norm_0(parse, str, -1);
}
