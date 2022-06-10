/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:31:28 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 11:46:49 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "./elements.h"
# include "./defines.h"
# include <stdbool.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct s_buf_i
{
	char	i0;
	char	i1;
	char	i2;
}	t_buf_i;

typedef struct s_mlx_ptr
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*buf;
	int		p_bits;
	int		l_bytes;
	int		endn;
	t_buf_i	i;
}	t_mlx_ptr;

typedef struct s_close_inter
{
	int		i;
	double	t;
	double	t_hol;
	char	object;
}	t_close_inter;

void	free_elements(t_elements *elem);
char	*ft_strjoin2(char *s1, char *s2);
bool	alloc(void **ptr, size_t len);
size_t	strlen_2d(char **strs);
char	*get_next_line(int fd);
void	free_2d(char **strs);

void	read_map(t_elements *elem, char *f_map);
void	map_invalid(char iden);

bool	print_error_msg_map(char iden);
bool	print_error_msg_a_c(char iden);
bool	print_error_msg_l_pl(char iden);
bool	print_error_msg_sp_cy(char iden);
bool	print_error_orient_vec(char iden);

void	check_amb_light_element(t_elements *elem, char *iden, char **param);
void	check_camera_element(t_elements *elem, char *iden, char **param);
void	check_light_element(t_elements *elem, char *iden, char **param);
void	check_plane_element(t_elements *elem, char *iden, char **param);
void	check_sphere_element(t_elements *elem, char *iden, char **param);
void	check_cylinder_element(t_elements *elem, char *iden, char **param);

bool	check_double_elements_a_c_l(t_elem_nbr elem_nbr, char *iden);
bool	check_tuple(char *tuple, int type, bool signe, bool dot);
bool	check_limit(char *ratio, double min, double max);
bool	check_dot(char *ratio, bool signe, bool dot);
int		check_valid_orient_vec(t_elements *elem);

void	parse_tuple_cogo(char *tuple, t_cogo *var_ptr);
void	parse_tuple_rgb(char *tuple, t_rgb *rgb);
void	parse_ratio(char *ratio, double *var_ptr);

double	mag_vector(t_cogo vec);
double	mag_vector_2d(t_cogo vec);
double	dot(t_cogo	v_one, t_cogo v_two);
double	dot_2d(t_cogo	v_one, t_cogo v_two);
void	resize_vec(t_cogo *vec, t_cogo v, double len);
void	resize_vec_2d(t_cogo *vec, t_cogo v, double len);
void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe);
void	add_sub_vectors_2d(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int s);
void	scaler_multiplication(t_cogo *vec, t_cogo v, double scaler);

t_rgb	multi_rgb(t_rgb rgb1, t_rgb rgb2, double ratio);
t_rgb	add_rgb(t_rgb rgb1, t_rgb rgb2);
t_rgb	mean_rgb(t_rgb rgb1, t_rgb rgb2);

void	fill_position_matrix(t_elements *elem);
void	init_ray(t_elements *elem, t_cogo *ray);
void	fill_t_buf_i(t_buf_i *i, int endn);

void	display(t_elements *elem, t_mlx_ptr *gfx);
t_rgb	get_pixel_color(t_elements *elem, t_cogo ray, double p_stp, bool depth);

void	fill_sub_matrix(t_cogo v, double **t_y, double **t_x);
void	fill_main_matrix(double **t_pos, double **t_y, double **t_x);
double	**alloc_matrix(double **matrix, int size);
void	free_matrix(double **matrix, int size);
double	**select_matrix(double **r, int row, int col, int size);
double	det_matrix(double **mtx, int size);
void	trans_matrix(double **matrix, int size);
double	**get_transf_matrix(t_cogo v_orient, t_cogo v_pos);
void	inverse_matrix(double **adjoint, double **matrix, int size);

void	update_cogo(t_elements *elem, double **m_pos);
void	update_cogo_element(t_cogo *element, double **m_pos);
void	update_orient_element(t_cogo *element, double **m_pos);

t_rgb	check_intersection(t_elements *elem, t_cogo ray);
bool	check_shadow_ray(t_elements *elem, t_cogo sh_ray);

double	sphere_intersection(t_elements *elem, t_cogo ray, size_t index);
double	sphere_intersection_sh(t_elements *elem, t_cogo ray, size_t index);
t_rgb	sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);

double	plane_intersection(t_elements *elem, t_cogo ray, size_t index);
t_rgb	plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);

double	cylinder_intersection(t_elements *elem, t_cogo ray, size_t index);
double	cylinder_intersection_sh(t_elements *elem, t_cogo ray, size_t index);
t_rgb	cylinder_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);

double	disk_cy_inter(t_elements *elem, t_cogo ray, size_t index, int signe);
t_rgb	disk_cy_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);

double	epsilon_sphere(t_elements *elem, size_t index);
double	epsilon_plane(t_elements *elem, size_t index);
double	epsilon_cylinder(t_elements *elem, size_t index);
double	epsilon_cy_disk(t_elements *elem, size_t index);

#endif
