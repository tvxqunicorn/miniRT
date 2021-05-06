/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:06:29 by xli               #+#    #+#             */
/*   Updated: 2021/04/08 09:11:54 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_program(void *parameter)
{
	(void)parameter;
	printf("finished\n");
	exit(EXIT_SUCCESS);
	return (1);
}

t_info	*init_info(t_parse *parse, void *mlx_ptr, void *win_ptr)
{
	t_info	*info;

	info = ft_malloc(1, sizeof(t_info));
	if (info == NULL)
		error_exit("ERROR_IN_INIT_INFO\n");
	info->parse = parse;
	info->mlx_ptr = mlx_ptr;
	info->win_ptr = win_ptr;
	return (info);
}

void	open_window(t_parse *parse, t_info *info)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(info->mlx_ptr, parse->rx, parse->ry, "miniRT");
	info->win_ptr = win_ptr;
	mlx_hook(win_ptr, 17, 131072, close_program, info);
	mlx_key_hook(win_ptr, deal_key, info);
	mlx_loop(info->mlx_ptr);
}
