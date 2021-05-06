/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 10:26:55 by xli               #+#    #+#             */
/*   Updated: 2021/03/16 15:31:33 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	*get_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	if (!save)
		return (NULL);
	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (NULL);
	str = ft_malloc(get_len(save) - i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i++;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	return (str);
}

char	*get_line(char *s)
{
	int		i;
	char	*d;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	d = ft_malloc(i + 1, sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!save)
	{
		save = ft_malloc(1, sizeof(char));
		if (save == NULL)
			return (-1);
		save[0] = '\0';
	}
	i = 1;
	while (!get_return(save) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (-1);
		buff[i] = '\0';
		save = get_join(save, buff);
	}
	*line = get_line(save);
	save = get_save(save);
	return (ft_min(i, 1));
}
