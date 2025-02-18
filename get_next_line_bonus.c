/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meaydino <meaydino@student.42kocaeli.com.t +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:29:18 by meaydino          #+#    #+#             */
/*   Updated: 2024/12/10 11:44:29 by meaydino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*temp[4096];
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	if (have_n(temp[fd]))
		return (print_line(&temp[fd]));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp[fd]), free(buffer), temp[fd] = NULL, NULL);
		buffer[bytes_read] = 0;
		temp[fd] = ft_strjoin(temp[fd], buffer);
		if (have_n(temp[fd]))
			break ;
	}
	if (buffer)
		free(buffer);
	return (buffer = NULL, print_line(&temp[fd]));
}
