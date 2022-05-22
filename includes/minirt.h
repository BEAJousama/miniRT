/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:31:28 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 11:44:16 by eabdelha         ###   ########.fr       */
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
}	t_elements;

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
void    display(t_elements *elem, t_mlx_ptr *gfx);
void	update_cogo_element(t_cogo *pos, t_cogo camera_pos);
void	move_origin_to_camera(t_elements *elem);
double	dot(t_cogo	v_one, t_cogo v_two);
void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe);
int		sphere_intersection(t_elements *elem, t_cogo ray, size_t index);

#endif
