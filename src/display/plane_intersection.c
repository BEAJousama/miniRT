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

int	plane_intersection(t_elements *elem, t_cogo ray)
{
	int		scaler;
	t_cogo	v;

	if (elem->pl->orient.x == 0 && elem->pl->orient.y == 0
		&& elem->pl->orient.z == 0)
		return (0);
	else
	{
		scaler = dot(elem->pl->pos, elem->pl->orient) / dot(ray,
				elem->pl->orient);
		v = scaler_multiplication(&ray, scaler);
		if (v.z >= 0 && scaler > 0)
			return (scaler);
		else
			return (0);
	}
}
