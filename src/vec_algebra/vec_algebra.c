/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_algebra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:25:58 by hsouza-s          #+#    #+#             */
/*   Updated: 2023/05/27 19:16:24 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_norm(const float a[3])
{
	float	res;

	res = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
	return (res);
}

void	ft_normalized(const float a[3], float b[3])
{
	float	len;

	len = ft_norm(a);
	if (len == 0)
		len = 1e-5;
	b[0] = a[0] / len;
	b[1] = a[1] / len;
	b[2] = a[2] / len;
}

void	ft_normalize(float a[3])
{
	float	len;

	len = ft_norm(a);
	if (len == 0)
		len = 1e-5;
	a[0] /= len;
	a[1] /= len;
	a[2] /= len;
}

void	ft_cross(const float a[3], const float b[3], float c[3])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void	ft_transform_vec4(const float mat[4][4], float vec[4])
{
	float	temp[4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		temp[i] = 0.0f;
		while (j < 4)
		{
			temp[i] += mat[i][j] * vec[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		vec[i] = temp[i];
		i++;
	}
}
