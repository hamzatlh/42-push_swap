/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htalhaou <htalhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:13:52 by htalhaou          #+#    #+#             */
/*   Updated: 2023/03/14 15:45:21 by htalhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rff(int fd, char *reserve)
{
	char				*buf;
	int					r;

	r = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (r > 0)
	{	
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		reserve = ft_strjoin_gnl(reserve, buf);
		if (ft_strchr_gnl(reserve, '\n'))
			break ;
	}
	free (buf);
	return (reserve);
}

char	*g_line(char *reserve)
{
	int					i;
	char				*line;

	i = 0;
	while (reserve[i] != '\0' && reserve[i] != '\n')
		i++;
	if (*reserve == 0)
		return (NULL);
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
				line[i] = reserve[i];
				i++;
	}	
	if (reserve[i] && reserve[i] == '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*n_res(char *reserve)
{
	int		i;
	int		j;
	char	*new_rese;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (reserve[i] == '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	new_rese = malloc(ft_strlen_gnl(reserve) - i + 1);
	if (!new_rese)
		return (NULL);
	j = 0;
	while (reserve[i] != '\0')
		new_rese[j++] = reserve[i++];
	new_rese[j] = '\0';
	free (reserve);
	return (new_rese);
}

char	*get_next_line(int fd)
{
	static char			*reserve;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	reserve = rff(fd, reserve);
	if (!reserve)
		return (NULL);
	line = g_line(reserve);
	reserve = n_res(reserve);
	return (line);
}
