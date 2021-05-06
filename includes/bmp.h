/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:07:01 by xli               #+#    #+#             */
/*   Updated: 2021/05/05 12:03:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

typedef struct s_bmp
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
	unsigned int	headersize;
	unsigned int	width;
	unsigned int	height;
	unsigned short	planes;
	unsigned short	bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}				t_bmp;

void	create_file(char *file_name, t_camera *camera, t_info *info);
t_bmp	*set_bmp(t_info *info);
void	write_pixel(int fd, t_parse *parse, t_camera *camera);
void	do_bmp(t_info *info, char *av[2]);

#endif
