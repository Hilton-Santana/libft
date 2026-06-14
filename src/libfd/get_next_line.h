/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:42:54 by hsouza-s          #+#    #+#             */
/*   Updated: 2026/06/14 15:09:14 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3000
# endif

int		get_next_line(int fd, char **line);
size_t	ft_join(char **source, char **target);
char	*ft_get_line(char	*buffer, char	**buffer_adr);
void	ft_read_buffer(int fd, char	**buffer_);
void	update_buffer(char	*buffer, char	**buffer_adr, int len);
#endif