/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:12:14 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 18:40:12 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_r(t_parse *parse, char *str)
{
	if (parse->rx || parse->ry)
		error_exit("define render size mutiple times\n");
	parse->rx = ft_atoi_max(&str);
	parse->ry = ft_atoi_max(&str);
	if (parse->rx <= 0 || parse->ry <= 0)
		error_exit("invalid render size\n");
}
