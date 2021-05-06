/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:58:33 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 12:04:18 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

typedef struct s_info
{
	t_parse		*parse;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_info;

typedef struct s_intersect
{
	int		intersect;
	int		obj_num;
	double	dist;
	double	coordinate[3];
	int		color[3];
}				t_intersect;

int				close_program(void *parameter);
t_info			*init_info(t_parse *parse, void	*mlx_ptr, void *win_ptr);
void			open_window(t_parse *parse, t_info *info);
void			change_camera(t_info *info);
int				deal_key(int key, void *pointer);
void			load_image(t_info *info);
void			clean_screen(t_info *info);
void			put_all(t_info *info);
void			put_screen(t_info *info);
void			get_u_v_vector(t_info *info, double **return_u,
					double **return_v);
void			get_eye_coordinate(t_camera *camera);
void			get_pixel(int *xy, t_info *info, double *u, double *v);
t_line			*two_points_line(double a[3], double b[3]);
void			get_is_points_with_sphere(t_line *line, t_sphere *sphere,
					int *is_amounts, double is_points[2]);
void			get_is_points_with_plane(t_line *view_ray, t_plane *plane,
					int *is_amounts, double is_points[2]);
void			get_is_points_with_square(t_line *view_ray, t_square *square,
					int *is_amounts, double is_points[2]);
void			get_is_points_with_triangle(t_line *view_ray,
					t_triangle *triangle, int *is_amounts, double is_points[2]);
void			get_is_points_with_cylinder(t_line *view_ray,
					t_cylinder *cylinder, int *is_amounts, double is_points[2]);
void			get_is_points_with_objects(t_line *view_ray, t_objects *obj,
					int *is_amounts, double is_points[2]);
void			intersect_with_objects(t_line *view_ray, t_objects *obj,
					t_intersect *intersect);
void			get_intersect(int *xy, t_line *view_ray, t_info *info);
int				color(t_info *info, t_line *view_ray, t_intersect *is);
void			get_obj_vector(double normal_vector[3], t_parse_type type,
					void *ptr, double coordinate[3]);
void			get_obj_color(int *is_color, t_parse_type type, void *ptr);
void			get_light(void *p[4], double normal_vector[3],
					int return_color[3]);
double			mix_cos(t_line *view_ray, t_line *l_line,
					double normal_vector[3]);
void			mix(int is_color[3], int light_color[3], int rt_color[3],
					double cos);
void			**p(void *p0, void *p1, void *p2, void *p3);

#endif
