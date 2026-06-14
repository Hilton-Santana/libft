/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:17:32 by hsouza-s          #+#    #+#             */
/*   Updated: 2026/06/14 15:08:28 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_rot_axes(float mat[4][4], const float x[3],
	const float y[3], const float z[4])
{
	zero_matrix_4(mat, 4, 4);
	mat[0][0] = x[0];
	mat[0][1] = x[1];
	mat[0][2] = x[2];
	mat[1][0] = y[0];
	mat[1][1] = y[1];
	mat[1][2] = y[2];
	mat[2][0] = z[0];
	mat[2][1] = z[1];
	mat[2][2] = z[2];
	mat[3][3] = 1.0f;
}

void	ft_translation4(float mat[4][4], const float t[4])
{
	zero_matrix_4(mat, 4, 4);
	mat[0][0] = 1.0f;
	mat[1][1] = 1.0f;
	mat[2][2] = 1.0f;
	mat[0][3] = t[0];
	mat[1][3] = t[1];
	mat[2][3] = t[2];
	mat[3][3] = 1.0f;
}

void	ft_rot_ax_angle(const float e[3], const float angle, float mat[3][3])
{
	float	sin_a;
	float	cos_a;
	float	angle_rad;

	zero_matrix_3(mat, 3, 3);
	angle_rad = angle * M_PI / 180;
	sin_a = sin(angle_rad);
	cos_a = cos(angle_rad);
	mat[0][0] = cos_a +(1 - cos_a) * e[0] * e[0];
	mat[0][1] = e[0] * e[1] * (1 - cos_a) - e[2] * sin_a;
	mat[0][2] = e[2] * e[0] * (1 - cos_a) + e[1] * sin_a;
	mat[1][0] = e[0] * e[1] * (1 - cos_a) + e[2] * sin_a;
	mat[1][1] = cos_a + (1 - cos_a) * e[1] * e[1];
	mat[1][2] = e[1] * e[2] * (1 - cos_a) - e[0] * sin_a;
	mat[2][0] = e[0] * e[2] * (1 - cos_a) - e[1] * sin_a;
	mat[2][1] = e[1] * e[2] * (1 - cos_a) + e[0] * sin_a;
	mat[2][2] = cos_a + (1 - cos_a) * e[2] * e[2];
}

void	ft_rot_ax_angle_4(const float e[3], const float angle, float mat[4][4])
{
	float	sin_a;
	float	cos_a;
	float	angle_rad;

	zero_matrix_4(mat, 4, 4);
	angle_rad = angle * M_PI / 180;
	sin_a = sin(angle_rad);
	cos_a = cos(angle_rad);
	mat[0][0] = cos_a +(1 - cos_a) * e[0] * e[0];
	mat[0][1] = e[0] * e[1] * (1 - cos_a) - e[2] * sin_a;
	mat[0][2] = e[2] * e[0] * (1 - cos_a) + e[1] * sin_a;
	mat[1][0] = e[0] * e[1] * (1 - cos_a) + e[2] * sin_a;
	mat[1][1] = cos_a + (1 - cos_a) * e[1] * e[1];
	mat[1][2] = e[1] * e[2] * (1 - cos_a) - e[0] * sin_a;
	mat[2][0] = e[0] * e[2] * (1 - cos_a) - e[1] * sin_a;
	mat[2][1] = e[1] * e[2] * (1 - cos_a) + e[0] * sin_a;
	mat[2][2] = cos_a + (1 - cos_a) * e[2] * e[2];
	mat[3][3] = 1.0f;
}

void	ft_rotate_about_fixed_point(const float e[3],
								const float angle,
								const float point[3],
								float mat[4][4])
{
	float	neg_point[3];
	float	translation[4][4];
	float	rotation[4][4];
	float	temp[4][4];

	neg_point[0] = -point[0];
	neg_point[1] = -point[1];
	neg_point[2] = -point[2];
	ft_translation4(translation, neg_point);
	ft_rot_ax_angle_4(e, angle, rotation);
	ft_mat4_mul(rotation, translation, temp);
	ft_translation4(translation, point);
	ft_mat4_mul(translation, temp, mat);
}
