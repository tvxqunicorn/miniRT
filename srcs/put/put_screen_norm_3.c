/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:38:33 by xli               #+#    #+#             */
/*   Updated: 2021/04/21 14:58:03 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	color_norm_0(int return_color[3])
{
	int	max_color;
	int	ct;

	max_color = 255;
	ct = -1;
	while (++ct < 3)
		max_color = ft_max(max_color, return_color[ct]);
	ct = -1;
	while (++ct < 3)
	{
		return_color[ct] *= 255;
		return_color[ct] /= max_color;
	}
}

static void	color_norm_1(t_line *view_ray, t_intersect *is, int re_color[3])
{
	int	ct;

	ct = -1;
	while (++ct < 3)
		re_color[ct] = 0;
	is->coordinate[0] = view_ray->x[0] * is->dist + view_ray->x[1];
	is->coordinate[1] = view_ray->y[0] * is->dist + view_ray->y[1];
	is->coordinate[2] = view_ray->z[0] * is->dist + view_ray->z[1];
}

int	color(t_info *info, t_line *view_ray, t_intersect *is)
{
	int			re_color[3];
	double		normal_vector[3];
	t_list		*obj_list;
	t_objects	*obj;

	color_norm_1(view_ray, is, re_color);
	obj_list = info->parse->objects;
	while (obj_list)
	{
		obj = obj_list->content;
		if (obj->num == is->obj_num)
		{
			get_obj_vector(normal_vector, obj->type, obj->ptr, is->coordinate);
			get_obj_color(is->color, obj->type, obj->ptr);
			break ;
		}
		obj_list = obj_list->next;
	}
	get_light(p(info, is, obj_list, view_ray), normal_vector, re_color);
	color_norm_0(re_color);
	return ((re_color[0] << 16) | (re_color[1] << 8) | (re_color[2]));
}

void	**p(void *p0, void *p1, void *p2, void *p3)
{
	void	**p;

	p = ft_malloc(4, sizeof(void *));
	p[0] = p0;
	p[1] = p1;
	p[2] = p2;
	p[3] = p3;
	return (p);
}
