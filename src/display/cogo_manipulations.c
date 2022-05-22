/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cogo_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:08:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/21 09:08:24 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	update_cogo_element(t_cogo *pos, t_cogo camera_pos)
{
	pos->x -= camera_pos.x;
	pos->y -= camera_pos.y;
	pos->z -= camera_pos.z;
}

void	move_origin_to_camera(t_elements *elem)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
		update_cogo_element(&(elem->l[i].pos), elem->c->pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		update_cogo_element(&(elem->sp[i].pos), elem->c->pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		update_cogo_element(&(elem->pl[i].pos), elem->c->pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		update_cogo_element(&(elem->cy[i].pos), elem->c->pos);
	elem->c->pos.x = 0;
	elem->c->pos.y = 0;
	elem->c->pos.z = 0;
}