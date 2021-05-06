/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_0.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:13:58 by xli               #+#    #+#             */
/*   Updated: 2021/04/29 10:16:45 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_0_H
# define MATH_0_H

double	len(double *v);
void	modify_length(double *vector, double length);
double	*cross(double *v1, double *v2);
void	solve_quadratic_equation(int *is_amounts, double is_points[2],
			double *coef);
double	double_abs(double a);
double	dot(double *v1, double *v2);
double	linear_equation(double *coef, t_line *line);
void	linear_equations(double *u, double *v, double *w, double *ans);
double	cos_vector(double *v1, double *v2);
double	*two_points_vector(double *start_point, double *end_point);
void	copy_vector(double *target, double *srcs);
double	two_points_distance(double *a, double *b);
int		quadratic_equation(double *coef, double *answer);

#endif
