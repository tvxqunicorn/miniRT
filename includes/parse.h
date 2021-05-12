/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:39:40 by xli               #+#    #+#             */
/*   Updated: 2021/05/12 12:51:00 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# ifndef AMBIENT_LIGHT_INTENSITY
#  define AMBIENT_LIGHT_INTENSITY 0.1
# endif

typedef struct s_line
{
	double	x[2];
	double	y[2];
	double	z[2];
}				t_line;

typedef struct s_parse
{
	int			rx;
	int			ry;
	double		aratio;
	int			acolor[3];
	t_list		*camera;
	t_list		*cur_camera;
	t_list		*light;
	t_list		*objects;
}				t_parse;

typedef enum e_parse_type
{
	R = 0,
	A,
	c,
	l,
	sp,
	pl,
	sq,
	cy,
	tr
}				t_parse_type;

typedef struct s_camera
{
	double		coordinate[3];
	double		orientation[3];
	double		eye_coordinate[3];
	double		fov;
	double		distance_to_screen;
	void		*img_ptr;
	int			*pixel;
	int			*bits_per_pixel;
	int			*size_line;
	int			*endian;
	int			num;
}				t_camera;

typedef struct s_light
{
	double		coordinate[3];
	double		brightness;
	int			color[3];
}				t_light;

typedef struct s_objects
{
	t_parse_type	type;
	void			*ptr;
	int				num;
}				t_objects;

typedef struct s_sphere
{
	double		coordinate[3];
	double		diameter;
	int			color[3];
}				t_sphere;

typedef struct s_plane
{
	double		coordinate[3];
	double		orientation[3];
	int			color[3];
}				t_plane;

typedef struct s_square
{
	double		coordinate[3];
	double		orientation[3];
	double		start_point[3];
	double		*vector[2];
	double		side_size;
	int			color[3];
}				t_square;

typedef struct s_cylinder
{
	double		coordinate[3];
	double		orientation[3];
	double		diameter;
	double		height;
	int			color[3];
	t_line		*middle_line;
	double		*end_point[2];
}				t_cylinder;

typedef struct s_triangle
{
	double		point[3][3];
	double		*orientation;
	double		*vector[2];
	int			color[3];
}				t_triangle;

t_sphere		*init_sphere(void);
t_plane			*init_plane(void);
t_square		*init_square(void);
t_cylinder		*init_cylinder(void);
t_triangle		*init_triangle(void);
t_objects		*init_objects(t_parse_type type, void *addr);
t_camera		*init_camera(void);
t_light			*init_light(void);
t_parse			*init_parse(void);
void			parse_r(t_parse *parse, char *str);
void			parse_a(t_parse *parse, char *str);
void			parse_c(t_parse *parse, char *str);
void			parse_l(t_parse *parse, char *str);
void			parse_sp(t_parse *parse, char *str);
void			parse_pl(t_parse *parse, char *str);
void			parse_sq(t_parse *parse, char *str);
void			parse_cy(t_parse *parse, char *str);
void			parse_tr(t_parse *parse, char *str);
void			parse_scene(int fd, t_parse *parse);
void			get_sphere_normal_vector(double normal_vector[3],
					t_sphere *sphere, double coordinate[3]);
void			get_plane_normal_vector(double normal_vector[3],
					t_plane *plane, double coordinate[3]);
void			get_square_normal_vector(double normal_vector[3],
					t_square *square, double coordinate[3]);
void			get_triangle_normal_vector(double normal_vector[3],
					t_triangle *triangle, double coordinate[3]);
void			cylinder_coef(double *coef, double *alpha, t_line *view_ray,
					t_cylinder *cylinder);
void			get_cylinder_normal_vector(double normal_vector[3],
					t_cylinder *cylinder, double coordinate[3]);

#endif
