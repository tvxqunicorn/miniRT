/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:55:45 by xli               #+#    #+#             */
/*   Updated: 2021/05/04 09:13:59 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "parse.h"
# include "put.h"
# include "math_0.h"
# include "bmp.h"
# define ESC 53
# define SPACE 49

t_info	*get_image(t_parse *parse);
void	error_exit(const char *str);
void	arg_error(int ac, char **av);
int		file_error(char **argv);

#endif
