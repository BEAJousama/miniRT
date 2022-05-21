/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:24:38 by obeaj             #+#    #+#             */
/*   Updated: 2022/05/20 16:48:14 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;
typedef t_vector	t_point;
typedef t_vector	t_color;
typedef struct s_ray
{
	t_point		*p;
	t_vector	*v;
}	t_ray;
double		dot_product(t_vector *v1, t_vector *v2);
t_vector	*cross_product(t_vector *v1, t_vector *v2);
t_vector	*elong(t_vector *v, double c);
t_vector	*vec_create(t_point a, t_point b);
t_vector	*vec_copy(t_vector *v);
t_vector	*normalize(t_vector *v);
double		magnitude(t_vector *v);

#endif