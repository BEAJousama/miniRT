/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:07:23 by obeaj             #+#    #+#             */
/*   Updated: 2022/05/22 14:55:08 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	plane_intersection(t_elements *elem, t_cogo ray, size_t index)
{
	t_cogo	c_p;
	double	t;

	t = -1;
	add_sub_vectors(&c_p, elem->pl[index].pos, elem->origin, -1);
	if (dot(ray, elem->pl[index].orient))
		t = dot(c_p, elem->pl[index].orient) / dot(ray, elem->pl[index].orient);
	return (t);
}
