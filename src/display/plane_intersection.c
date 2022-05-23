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
	double	scaler;

	if (elem->pl[index].orient.x == 0 && elem->pl[index].orient.y == 0
		&& elem->pl[index].orient.z == 0)
		return (0);
	else
	{
		scaler = dot(elem->pl[index].pos, elem->pl[index].orient) / dot(ray,
				elem->pl[index].orient);
		scaler_multiplication(&ray, ray, scaler);
		if (scaler > 0)
			return (scaler);
	}
	return (0);
}
