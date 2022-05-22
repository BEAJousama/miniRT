/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:07:23 by obeaj             #+#    #+#             */
/*   Updated: 2022/05/22 10:30:04 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	plane_intersection(t_elements *elem, t_cogo ray)
{
	if (elem->pl->orient.x == 0 && elem->pl->orient.y == 0
		&& elem->pl->orient.z == 0)
		return (0);
	else
		return (dot(elem->pl->pos, elem->pl->orient) / dot(ray,
				elem->pl->orient));
}
