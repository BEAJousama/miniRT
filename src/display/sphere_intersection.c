/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:09:19 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/21 09:09:20 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int sphere_intersection(t_elements *elem, t_cogo ray)
{
	double	delta;
	t_cogo	p_c;

	add_sub_vectors(&p_c, elem->c->pos, elem->sp->pos, -1);
	delta = pow(2 * dot(ray, p_c), 2) - (4 * dot(ray, ray) * (dot(p_c, p_c) - pow(elem->sp->diameter / 2, 2)));

	if (delta < 0)
		return (0);
	else
		return (1);
}