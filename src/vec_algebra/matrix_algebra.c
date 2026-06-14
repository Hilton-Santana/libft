/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_algebra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 02:40:31 by hsouza-s          #+#    #+#             */
/*   Updated: 2023/05/27 19:14:22 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	zero_matrix_4(float mat[4][4], int n_rows, int n_cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_rows)
	{
		j = 0;
		while (j < n_cols)
		{
			mat[i][j] = 0.0f;
			j++;
		}
		i++;
	}
}

void	zero_matrix_3(float mat[3][3], int n_rows, int n_cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < n_rows)
	{
		j = 0;
		while (j < n_cols)
		{
			mat[i][j] = 0.0f;
			j++;
		}
		i++;
	}
}

void	ft_mat4_mul(const float a[4][4], float const b[4][4], float c[4][4])
{
	int		i;
	int		j;
	int		k;
	float	sum;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sum = 0.0f;
			k = 0;
			while (k < 4)
			{
				sum += a[i][k] * b[k][j];
				k++;
			}
			c[i][j] = sum;
			j++;
		}
		i++;
	}
}

void	ft_mat4_vec(const float mat[4][4], const float vec[4], float res[4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		res[i] = 0.0f;
		while (j < 4)
		{
			res[i] += mat[i][j] * vec[j];
			j++;
		}
		i++;
	}
}

void	ft_transform_vec3(const float mat[3][3], float vec[3])
{
	float	temp[3];
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		temp[i] = 0.0f;
		while (j < 3)
		{
			temp[i] += mat[i][j] * vec[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		vec[i] = temp[i];
		i++;
	}
}
