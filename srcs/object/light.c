/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:33:29 by xli               #+#    #+#             */
/*   Updated: 2021/04/15 15:11:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*init_light(void)
{
	int		ct;
	t_light	*light;

	light = ft_malloc(1, sizeof(t_light));
	if (light == NULL)
		error_exit("ERROR_IN_INIT_light\n");
	ct = -1;
	while (++ct < 3)
		light->coordinate[ct] = 0.0;
	light->brightness = 0.0;
	ct = -1;
	while (++ct < 3)
		light->color[ct] = 0;
	return (light);
}
