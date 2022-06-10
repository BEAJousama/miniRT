/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:30:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 11:42:58 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "./minirt.h"

typedef struct s_cogo
{
	double	x;
	double	y;
	double	z;
}	t_cogo;

typedef struct s_elem_nbr
{
	size_t	a_nbr;
	size_t	c_nbr;
	size_t	l_nbr;
	size_t	sp_nbr;
	size_t	pl_nbr;
	size_t	cy_nbr;
}	t_elem_nbr;

typedef struct s_amb_light
{
	double	ratio;
	int		rgb;
}	t_amb_light;

typedef struct s_camera
{
	t_cogo	pos;
	t_cogo	orient;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_cogo	pos;
	double	bright;
	int		rgb;
}	t_light;

typedef struct s_sphere
{
	t_cogo	pos;
	double	diameter;
	int		rgb;
}	t_sphere;

typedef struct s_plane
{
	t_cogo	pos;
	t_cogo	orient;
	t_cogo	limits;
	int		rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_cogo	pos;
	t_cogo	orient;
	t_cogo	o_c;
	double	z_o;
	double	**m_pos;
	double	diameter;
	double	height;
	int		rgb;
}	t_cylinder;

typedef struct s_elements
{
	t_amb_light	*a;
	t_camera	*c;
	t_light		*l;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;
	double		**m_pos;
	t_elem_nbr	elem_nbr;
	t_cogo		origin;
}	t_elements;

#endif
