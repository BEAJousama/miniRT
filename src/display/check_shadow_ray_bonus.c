/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:33:39 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/18 23:08:54 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_shadow_ray_2(t_elements *elem, t_cogo sh_r, t_cogo o, int index)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (index != i && !check_sh_r_cy_disk(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (index != i && !check_sh_r_co(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.co_nbr)
		if (index != i && !check_sh_r_co_disk(elem, sh_r, (size_t)i, o))
			return (0);
	return (1);
}

bool	check_shadow_ray(t_elements *elem, t_cogo sh_r, t_cogo o, int index)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (index != i && !check_sh_r_sp(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		if (index != i && !check_sh_r_pl(elem, sh_r, (size_t)i, o))
			return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		if (index != i && !check_sh_r_cy(elem, sh_r, (size_t)i, o))
			return (0);
	return (check_shadow_ray_2(elem, sh_r, o, index));
}
