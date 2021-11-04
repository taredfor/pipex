/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taredfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:48:09 by taredfor          #+#    #+#             */
/*   Updated: 2021/08/30 18:48:10 by taredfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(int fd, char **line, char **buffer)
{
	if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	*buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	return (0);
}

static	char	*ft_new_reminder(char **reminder, char **buffer)
{
	char	*new_reminder;

	new_reminder = ft_strjoin(*reminder, *buffer);
	free(*reminder);
	*reminder = new_reminder;
	return (*reminder);
}

static	int	ft_reminder(char **reminder, char **line, int n)
{
	char	*new_str;
	char	*new_line;

	new_line = NULL;
	new_str = NULL;
	if (ft_strchr(*reminder, '\n'))
	{
		new_str = ft_strchr(*reminder, '\n');
		*line = ft_strndup(*reminder, (new_str - (*reminder)));
		new_line = ft_strndup((new_str + 1), ft_strlen(new_str + 1));
		free(*reminder);
		*reminder = new_line;
		return (1);
	}
	else
	{
		*line = ft_strndup(*reminder, ft_strlen(*reminder));
		free(*reminder);
		*reminder = NULL;
		return (0);
	}
	if (n == 0 && (*reminder == NULL || (**reminder == '\0')))
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*reminder;
	size_t		n;

	if (ft_check(fd, line, &buffer) < 0)
		return (-1);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = '\0';
		if (reminder == NULL)
		{
			reminder = ft_strdup(buffer);
			if (!reminder)
				return (-1);
		}
		else
			ft_new_reminder(&reminder, &buffer);
		if (ft_strchr(reminder, '\n'))
			break ;
	}
	free(buffer);
	return (ft_reminder(&reminder, line, n));
}
