/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:07:23 by obeaj             #+#    #+#             */
/*   Updated: 2022/06/10 08:29:21 by eabdelha         ###   ########.fr       */
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
