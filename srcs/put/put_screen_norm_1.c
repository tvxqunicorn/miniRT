/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:57:32 by xli               #+#    #+#             */
/*   Updated: 2021/05/12 15:37:20 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_is_points_with_objects(t_line *view_ray, t_objects *obj,
		int *is_amounts, double is_points[2])
{
	if (obj->type == sp)
		get_is_points_with_sphere(view_ray, obj->ptr, is_amounts, is_points);
	if (obj->type == pl)
		get_is_points_with_plane(view_ray, obj->ptr, is_amounts, is_points);
	if (obj->type == sq)
		get_is_points_with_square(view_ray, obj->ptr, is_amounts, is_points);
	if (obj->type == tr)
		get_is_points_with_triangle(view_ray, obj->ptr, is_amounts, is_points);
	if (obj->type == cy)
		get_is_points_with_cylinder(view_ray, obj->ptr, is_amounts, is_points);
}

void	intersect_with_objects(t_line *view_ray, t_objects *obj,
		t_intersect *intersect)
{
	int		is_amounts;
	double	is_points[2];
	int		ct;

	is_amounts = -1;
	get_is_points_with_objects(view_ray, obj, &is_amounts, is_points);
	ct = -1;
	while (++ct < is_amounts)
	{
		if (is_points[ct] <= 1.0)
			continue ;
		if (intersect->intersect == 0)
		{
			intersect->intersect = 1;
			intersect->dist = is_points[ct];
			intersect->obj_num = obj->num;
		}
		else if (is_points[ct] < intersect->dist - 1e-6)
		{
			intersect->intersect = 1;
			intersect->dist = is_points[ct];
			intersect->obj_num = obj->num;
		}
	}
}

void	get_intersect(int *xy, t_line *view_ray, t_info *info)
{
	t_intersect	*intersect;
	t_camera	*camera;
	t_list		*obj_list;

	intersect = ft_malloc(1, sizeof(t_intersect));
	if (intersect == NULL)
		error_exit("get_intersect\n");
	obj_list = info->parse->objects;
	intersect->intersect = 0;
	while (obj_list)
	{
		intersect_with_objects(view_ray, obj_list->content, intersect);
		obj_list = obj_list->next;
	}
	camera = info->parse->cur_camera->content;
	if (intersect->intersect)
		camera->pixel[xy[0] + info->parse->rx * xy[1]]
			= color(info, view_ray, intersect);
}
