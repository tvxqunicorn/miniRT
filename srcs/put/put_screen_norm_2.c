/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:19:31 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 13:12:42 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_obj_vector(double normal_vector[3], t_parse_type type,
		void *ptr, double coordinate[3])
{
	if (type == sp)
		get_sphere_normal_vector(normal_vector, ptr, coordinate);
	if (type == pl)
		get_plane_normal_vector(normal_vector, ptr, coordinate);
	if (type == sq)
		get_square_normal_vector(normal_vector, ptr, coordinate);
	if (type == tr)
		get_triangle_normal_vector(normal_vector, ptr, coordinate);
	if (type == cy)
		get_cylinder_normal_vector(normal_vector, ptr, coordinate);
}

void	get_obj_color(int *is_color, t_parse_type type, void *ptr)
{
	int	ct;

	ct = -1;
	if (type == sp)
		while (++ct < 3)
			is_color[ct] = ((t_sphere *)ptr)->color[ct];
	if (type == pl)
		while (++ct < 3)
			is_color[ct] = ((t_plane *)ptr)->color[ct];
	if (type == sq)
		while (++ct < 3)
			is_color[ct] = ((t_square *)ptr)->color[ct];
	if (type == tr)
		while (++ct < 3)
			is_color[ct] = ((t_triangle *)ptr)->color[ct];
	if (type == cy)
		while (++ct < 3)
			is_color[ct] = ((t_cylinder *)ptr)->color[ct];
}
