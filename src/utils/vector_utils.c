/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:22:20 by obeaj             #+#    #+#             */
/*   Updated: 2022/05/20 14:41:23 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector	*vec_create(t_point a, t_point b)
{
	t_vector	*v;

	v->x = b.x - a.x;
	v->y = b.y - a.y;
	v->z = b.z - a.z;
	return (v);
}

double	dot_product(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	*elong(t_vector *v, double c)
{
	t_vector	*v1;

	v1->x = c * v->x;
	v1->y = c * v->y;
	v1->z = c * v->z;
	return (v1);
}

t_vector	*vec_copy(t_vector *v)
{
	return (elong(v, 1));
}

t_vector	*cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	*v;

	v->x = v1->y * v2->z - v1->z * v2->y;
	v->y = v2->x * v1->z - v1->x * v2->z;
	v->z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}
