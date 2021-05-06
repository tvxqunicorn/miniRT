/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:59:29 by xli               #+#    #+#             */
/*   Updated: 2021/05/04 09:21:46 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_info	*get_image(t_parse *parse)
{
	void	*mlx_ptr;
	t_info	*info;
	int		sizex;
	int		sizey;

	mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx_ptr, &sizex, &sizey);
	parse->rx = ft_min(parse->rx, sizex);
	parse->ry = ft_min(parse->ry, sizey);
	info = init_info(parse, mlx_ptr, (void *) NULL);
	load_image(info);
	return (info);
}

int	main(int ac, char **av)
{
	int		fd;
	t_parse	*parse;
	t_info	*info;

	arg_error(ac, av);
	fd = file_error(av);
	parse = init_parse();
	if (parse == NULL)
		error_exit("ERROR_IN_MAIN\n");
	parse_scene(fd, parse);
	info = get_image(parse);
	if (ac == 2)
		open_window(parse, info);
	else
		do_bmp(info, av);
	return (0);
}
