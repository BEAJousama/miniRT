/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:31:28 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 14:23:29 by obeaj            ###   ########.fr       */
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

typedef struct s_mlx_ptr
{
	void	*win;
	void	*mlx;
}	t_mlx_ptr;

typedef struct s_elements
{
	t_amb_light	*a;
	t_camera	*c;
	t_light		*l;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
	t_elem_nbr	elem_nbr;
	t_cogo		origin;
}	t_elements;

typedef	struct s_close_inter
{
	int		i;
	double	t;
	double	t_hol;
	char	object;
}	t_close_inter;


void	free_2d(char **strs);
void	free_elements(t_elements *elem);
size_t	strlen_2d(char **strs);
char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);
bool	alloc(void **ptr, size_t len);
void	read_map(t_elements *elem, char *f_map);
void	map_invalid(char iden);
bool	print_error_msg_map(char iden);
bool	print_error_msg_a_c(char iden);
bool	print_error_msg_l_pl(char iden);
bool	print_error_msg_sp_cy(char iden);
void	check_amb_light_element(t_elements *elem, char *iden, char **param);
void	check_camera_element(t_elements *elem, char *iden, char **param);
void	check_light_element(t_elements *elem, char *iden, char **param);
void	check_plane_element(t_elements *elem, char *iden, char **param);
void	check_sphere_element(t_elements *elem, char *iden, char **param);
void	check_cylinder_element(t_elements *elem, char *iden, char **param);
bool	check_double_elements_a_c(t_elem_nbr elem_nbr, char *iden);
bool	check_limit(char *ratio, double min, double max);
bool	check_dot(char *ratio, bool signe, bool dot);
bool	check_tuple(char *tuple, int type, bool signe, bool dot);
void	parse_ratio(char *ratio, double *var_ptr);
void	parse_tuple_rgb(char *tuple, int *var_ptr);
void	parse_tuple_cogo(char *tuple, t_cogo *var_ptr);
void	display(t_elements *elem, t_mlx_ptr *gfx);
void	move_origin_to_camera(t_elements *elem);
double	mag_vector(t_cogo vec);
double	dot(t_cogo	v_one, t_cogo v_two);
void	scaler_multiplication(t_cogo *vec, t_cogo v,double scaler);
void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe);
void	resize_vec(t_cogo *vec, t_cogo v, double len);
t_cogo	cross_product(t_cogo v1, t_cogo v2);
t_cogo	vec_create(t_cogo a, t_cogo b);

void    fill_sub_matrix(t_elements *elem, double **t_y, double **t_x);
void    fill_main_matrix(double **t_pos, double **t_y, double **t_x);
double  **alloc_matrix(double **matrix, int size);
double  **select_matrix(double **r, int row, int col, int size);
double	det_matrix(double **mtx, int size);
void	trans_matrix(double **matrix, int size);
void	inverse_matrix(double **adjoint, double **matrix, int size);

int		check_intersection(t_elements *elem ,t_cogo ray);
double	sphere_intersection(t_elements *elem, t_cogo ray, size_t index);
double	plane_intersection(t_elements *elem, t_cogo ray, size_t index);
double	cylinder_intersection(t_elements *elem, t_cogo ray, int index, int isshadow);
int		sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);
int		plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);
int		cylinder_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray);

int		multi_rgb(int rgb_o, int rgb_l, double ratio);
int		add_rgb(int rgb_o, int rgb_l);

double	sphere_inter(t_elements *elem, t_cogo ray, size_t index);

#endif
