/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:33:17 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/03 21:03:15 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*teelua(char *line)
{
	char	*tmp;
	ssize_t	i;
	ssize_t	len_left;
	size_t	len_ret;

	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	len_ret = ft_piset_len(line);
	len_left = ft_strlen(line) - len_ret;
	tmp = (char *)malloc(sizeof(char) * (len_left + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < len_left + 1)
		tmp[i] = line[i + len_ret];
	i--;
	while (line[++i + len_ret] == '\n')
		tmp[i] = line[i + len_ret];
	tmp[i] = '\0';
	free(line);
	return (tmp);
}

char	*find_result(char *s)
{
	char	*result;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_piset_len(s) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*arn(int fd, char *buff, char *line)
{
	int			khanhad;

	khanhad = read(fd, buff, BUFFER_SIZE);
	while (khanhad)
	{
		buff[khanhad] = '\0';
		line = ft_strjoin(line, buff); //leak here
		if ((khanhad < BUFFER_SIZE && khanhad > 0) || ha_nee(line, '\n'))
			break ;
		khanhad = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		*line = '\0';
	}
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		free (line);
		return (NULL);
	}
	line = arn(fd, buff, line);
	if (buff)
		free (buff);
	res = find_result(line);
	line = teelua(line);
	return (res);
}
