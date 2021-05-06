/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_norm_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:39:47 by xli               #+#    #+#             */
/*   Updated: 2021/04/21 14:29:43 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_light_norm_0(t_list *obj_list, t_line *l_line, int have_is)
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
				have_is = 1;
				break ;
			}
		}
		if (have_is)
			break ;
		obj_list = obj_list->next;
	}
}

/*
** l_norm[0]: t_list	*light_list;
** l_norm[1]: t_light	*light;
** l_norm[2]: t_line	*l_line;
** i_norm[0 - 2]: int	result_color[3];
** i_norm[3]: int	have_is;
** i_norm[4]: int	ct;
*/

void	get_light(void *p[4], double normal_vector[3], int return_color[3])
{
	void	*l_norm[3];
	int		i_norm[5];
	double	cos;

	l_norm[0] = ((t_info *)p[0])->parse->light;
	while (l_norm[0])
	{
		l_norm[1] = ((t_list *)l_norm[0])->content;
		l_norm[2] = two_points_line(((t_light *)l_norm[1])->coordinate,
				((t_intersect *)p[1])->coordinate);
		i_norm[3] = 0;
		get_light_norm_0(p[2], l_norm[2], 0);
		if (i_norm[3] == 0)
		{
			cos = mix_cos(p[3], l_norm[2], normal_vector);
			mix(((t_intersect *)p[1])->color, ((t_light *)l_norm[1])->color,
				i_norm, cos);
			i_norm[4] = -1;
			while (++i_norm[4] < 3)
				return_color[i_norm[4]] += i_norm[i_norm[4]];
		}
		ft_free(l_norm[2]);
		l_norm[0] = ((t_list *)l_norm[0])->next;
	}
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
