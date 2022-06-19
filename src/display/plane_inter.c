/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:02:04 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/19 16:02:07 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	plane_inter(t_elements *elem, t_cogo ray, size_t index, t_cogo o)
{
	t_cogo	c_p;
	double	t;

	t = -1;
	add_sub_vectors(&c_p, elem->pl[index].pos, o, -1);
	if (dot(ray, elem->pl[index].orient))
		t = dot(c_p, elem->pl[index].orient) / dot(ray, elem->pl[index].orient);
	return (t);
}
