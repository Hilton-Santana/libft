/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsouza-s <hsouza-s@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:47:14 by hsouza-s          #+#    #+#             */
/*   Updated: 2026/06/14 15:13:52 by hsouza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdarg.h>
# include "libfd/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
char	*ft_strchr(const char *s, int c);
int		ft_isascii(int c);
char	*ft_strrchr(const char *s, int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
int		ft_atoi(const char *str_ptr);
void	*ft_calloc(size_t ncell, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_itoa(int value);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
float	ft_norm(const float a[3]);
void	ft_normalized(const float a[3], float b[3]);
void	ft_normalize(float a[3]);
void	ft_cross(const float a[3], const float b[3], float c[3]);
void	ft_mat4_mul(const float a[4][4], const float b[4][4], float c[4][4]);
void	ft_mat4_vec(const float mat[4][4], const float vec[4], float res[4]);
void	ft_transform_vec3(const float mat[3][3], float vec[3]);
void	ft_rot_axes(float mat[4][4], const float x[3],
			const float y[3], const float z[4]);
void	ft_translation4(float mat[4][4], const float t[4]);
void	ft_rot_ax_angle(const float e[3], float const angle, float mat[3][3]);
void	zero_matrix_4(float mat[4][4], int n_rows, int n_cols);
void	zero_matrix_3(float mat[3][3], int n_rows, int n_cols);
void	swap_int(int *a, int *b);
void	swap_float(float *a, float *b);
void	ft_rot_ax_angle_4(const float e[3], const float angle, float mat[4][4]);
void	ft_rotate_about_fixed_point(const float e[3],
			const float angle,
			const float point[3],
			float mat[4][4]);
void	ft_transform_vec4(const float mat[4][4], float vec[4]);
int		ft_long_to_hex(unsigned long ptr);
int		ft_putnbr_base(long long int n, int base, char format);
int		ft_printf(const char *str, ...);

#endif