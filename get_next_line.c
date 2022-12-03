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
	size_t	i;
	size_t	len_left;
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
	i = 0;
	while (i < len_left)
	{
		tmp[i] = line[i + len_ret];
		i++;
	}
	while (line[i + len_ret] == '\n')
	{
		tmp[i] = line[i + len_ret];
		i++;
	}
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

// char	*arn(int fd, char *line)
// {
// 	char	*buf;
// 	int		re_si;

// 	re_si = 1;
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // malloc check
// 	while (re_si > 0)
// 	{
// 		re_si = read(fd, buf, BUFFER_SIZE);
// 		// printf("%d\n", re_si);
// 		buf[re_si] = '\0';
// 		// printf("%s %d ", buf, re_si);
// 		if (re_si == -1)
// 		{
// 			free(buf);
// 			return (0);
// 		}
// 		// line = ft_strjoin(line, buf);
// 		if (ha_nee(line, '\n') || (ft_strlen(line) > 0 && !ha_nee(line, '\n')))
// 			break ;
// 		if (re_si == 0)
// 		{
// 			// line = ft_strjoin(line, buf)
// 			free (line);
// 			free(buf);
// 			printf("\nre_si = 0\n");
// 			return (NULL);
// 		}
// 	}
// 	free(buf);
// 	// printf("%s", line);
// 	return (line);
// }

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	int			khanhad;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!line)
	{
		line = malloc(1); //malloc check
		*line = '\0';
	}
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // malloc check
	// khanhad = 1;
	khanhad = read(fd, buff, BUFFER_SIZE);
	while (khanhad)
	{
		buff[khanhad] = '\0';
		line = ft_strjoin(line, buff);
		if ((khanhad < BUFFER_SIZE && khanhad > 0) || ha_nee(line, '\n'))
			break ;
		khanhad = read(fd, buff, BUFFER_SIZE);
	}
	if (buff)
		free (buff);
//	if (!line || khanhad == 0)
//		return (NULL);
	res = find_result(line);
	line = teelua(line);
	// if (!res)
	// 	free(line);
	return (res);
}
