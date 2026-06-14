/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:59:55 by hsouza-s          #+#    #+#             */
/*   Updated: 2023/05/27 19:17:32 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_join(char **buffer, char **new)
{
	char	*new_buffer;
	size_t	i;
	size_t	curr_size;
	size_t	new_size;

	curr_size = ft_strlen(*buffer);
	new_size = curr_size + ft_strlen(*new);
	new_buffer = (char *) ft_calloc(new_size + 1, sizeof(char));
	i = 0;
	while (i < curr_size)
	{
		new_buffer[i] = (*buffer)[i];
		i++;
	}
	while (i < new_size)
	{
		new_buffer[i] = (*new)[i - curr_size];
		i++;
	}
	free(*buffer);
	free(*new);
	*buffer = new_buffer;
	return (new_size);
}

void	ft_read_buffer(int fd, char	**buffer_)
{
	char	*temp;
	int		count;
	int		i;
	int		res;

	i = 0;
	res = 1;
	count = ft_strlen(*buffer_);
	while (res)
	{
		while (i < count)
		{
			if ((*buffer_)[i] == '\n')
				return ;
			i++;
		}
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		res = read(fd, temp, BUFFER_SIZE);
		count = ft_join(buffer_, &temp);
	}
	if (i == 0)
	{
		free(*buffer_);
		*buffer_ = NULL;
	}
}

char	*ft_get_line(char	*buffer, char	**buffer_adr)
{
	int		i;
	char	*line;
	int		len;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *) ft_calloc(i + 2, sizeof(char));
	line[i] = '\n';
	len = i;
	while (i > 0)
	{
		line[i] = buffer[i];
		i--;
	}	
	line[i] = buffer[i];
	update_buffer(buffer, buffer_adr, len);
	return (line);
}

void	update_buffer(char	*buffer, char	**buffer_adr, int len)
{
	int	i;
	int	n;
	int	new_len;

	n = ft_strlen(buffer);
	new_len = n - len - 1;
	i = 0;
	*buffer_adr = (char *) ft_calloc(new_len + 1, sizeof(char));
	while (i < new_len)
	{
		(*buffer_adr)[i] = buffer[n - new_len + i];
		i++;
	}		
	free(buffer);
}

int	get_next_line(int fd, char **line)
{
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	if (!buffer)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read(fd, buffer, BUFFER_SIZE);
	}
	ft_read_buffer(fd, &buffer);
	*line = ft_get_line(buffer, &buffer);
	if (!(*line))
		return (0);
	return (1);
}
