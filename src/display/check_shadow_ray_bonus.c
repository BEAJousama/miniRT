/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:33:39 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 16:36:41 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_shadow_ray_2(t_elements *elem, t_cogo sh_ray)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (!check_sh_ray_cy_disk(elem, sh_ray, (size_t)i))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (!check_sh_ray_co(elem, sh_ray, (size_t)i))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (!check_sh_ray_co_disk(elem, sh_ray, (size_t)i))
			return (0);
	return (1);
}

bool	check_shadow_ray(t_elements *elem, t_cogo sh_ray)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (!check_sh_ray_sp(elem, sh_ray, (size_t)i))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (!check_sh_ray_pl(elem, sh_ray, (size_t)i))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (!check_sh_ray_cy(elem, sh_ray, (size_t)i))
			return (0);
	return (check_shadow_ray_2(elem, sh_ray));
}
