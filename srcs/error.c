/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:27:20 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 12:12:31 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_exit(const char *str)
{
	printf("ERROR\n%s", str);
	exit(EXIT_FAILURE);
}

void	arg_error(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		printf("ERROR\nWrong amounts of arguments.\n");
	else if (ft_strlen(av[1]) < 3
		|| ft_strncmp(".rt", ft_substr(av[1], ft_strlen(av[1]) - 3, 3), 3))
		printf("ERROR\nThe second argument should be in type *.rt\n");
	else if (ac == 3 && ft_strncmp(av[2], "--save", 7))
		printf("ERROR\nThe third argument should be --save or nothing\n");
	else
		return ;
	printf("Usage 1 : %s <scene.rt>\n", av[0]);
	printf("Usage 2 : %s <scene.rt> --save\n", av[0]);
	exit(EXIT_FAILURE);
}

int	file_error(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR\nCan't open file %s \n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
