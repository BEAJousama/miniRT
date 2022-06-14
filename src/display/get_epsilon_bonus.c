/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_epsilon_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:58:16 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 15:58:40 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


double	epsilon_cone(t_elements *elem, size_t index)
{
	t_cogo	o_c;
	t_cogo	o;

	o = elem->co[index].orient;
    add_sub_vectors(&o_c, elem->c->pos, elem->co[index].pos, -1);
    resize_vec(&o_c, o_c, 1);
    resize_vec(&o, o, 1);
	if (dot(o_c, o) < cos(atan((elem->co[index].base / 2) / elem->co[index].hgt)))
		return (0.00001);
	return (-0.00001);
}
double	epsilon_co_disk(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->origin, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->origin, -1);
	if ((dot(c_c, elem->co[index].orient) * \
				dot(l_c, elem->co[index].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}
