/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:39:47 by xli               #+#    #+#             */
/*   Updated: 2021/05/12 14:33:00 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_light_norm_0(t_list *obj_list, t_line *l_line, int *have_is)
{
	t_objects	*obj;
	int			is_amounts;
	double		is_points[2];
	int			ct;

	while (obj_list)
	{
		obj = obj_list->content;
		is_amounts = -1;
		get_is_points_with_objects(l_line, obj, &is_amounts, is_points);
		ct = -1;
		while (++ct < is_amounts)
		{
			if (is_points[ct] > 0.0 + 1e-6 && is_points[ct] < 1.0 - 1e-6)
			{
				*have_is = 1;
				break ;
			}
		}
		if (*have_is)
			break ;
		obj_list = obj_list->next;
	}
}

static void	get_light_norm_1(t_info *info, int *return_color)
{
	int	ct;

	ct = -1;
	while (++ct < 3)
		return_color[ct] += (int)((double)info->parse->acolor[ct]
				* info->parse->aratio * AMBIENT_LIGHT_INTENSITY);
}

/*
** l[0]:		t_list	*light_list;
** l[1]:		t_light	*light;
** l[2]:		t_line	*l_line;
** i[0 - 2]:	int	result_color[3];
** i[3]:		int	have_is;
** i[4]:		int	ct;
** p[0]:		info;
** p[1]:		intersect;
** p[2]:		obj_list;
** p[3]:		view_ray;
*/

void	get_light(void *p[4], double normal_vector[3], int return_color[3])
{
	void	*l[3];
	int		i[5];
	double	cos;

	l[0] = ((t_info *)p[0])->parse->light;
	while (l[0])
	{
		l[1] = ((t_list *)l[0])->content;
		l[2] = two_points_line(((t_light *)l[1])->coordinate,
				((t_intersect *)p[1])->coordinate);
		i[3] = 0;
		get_light_norm_0(p[2], l[2], &i[3]);
		if (i[3] == 0)
		{
			cos = mix_cos(p[3], l[2], normal_vector);
			mix(((t_intersect *)p[1])->color, ((t_light *)l[1])->color, i, cos);
			i[4] = -1;
			while (++i[4] < 3)
				return_color[i[4]] += i[i[4]];
		}
		ft_free(l[2]);
		l[0] = ((t_list *)l[0])->next;
	}
	get_light_norm_1(p[0], return_color);
	ft_free(p);
}

double	mix_cos(t_line *view_ray, t_line *l_line, double normal_vector[3])
{
	double	v[3];
	double	u[3];
	double	cos;

	v[0] = view_ray->x[0];
	v[1] = view_ray->y[0];
	v[2] = view_ray->z[0];
	u[0] = l_line->x[0];
	u[1] = l_line->y[0];
	u[2] = l_line->z[0];
	cos = double_abs(dot(v, normal_vector) / len(v) / len(normal_vector)
			* dot(u, normal_vector) / len(u) / len(normal_vector));
	return (cos);
}

void	mix(int is_color[3], int light_color[3], int rt_color[3], double cos)
{
	int		ct;

	ct = -1;
	while (++ct < 3)
		rt_color[ct] = (int)(((double)(is_color[ct] * light_color[ct]))
				* cos / 255.0);
}
