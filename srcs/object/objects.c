/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:57:54 by xli               #+#    #+#             */
/*   Updated: 2021/04/07 14:23:23 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects	*init_objects(t_parse_type type, void *ptr)
{
	t_objects	*obj;
	static int	num = 0;

	obj = ft_malloc(1, sizeof(t_objects));
	if (obj == NULL)
		error_exit("ERROR_IN_INIT_OBJECTS\n");
	obj->type = type;
	obj->ptr = ptr;
	obj->num = num++;
	return (obj);
}
