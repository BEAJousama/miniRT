/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:05:47 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 09:55:34 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	dot(t_cogo	v_one, t_cogo v_two)
{
	return ((v_one.x * v_two.x) + (v_one.y * v_two.y) +(v_one.z * v_two.z));
}

void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe)
{
	v_res->x = v_one.x + (signe * v_two.x);
	v_res->y = v_one.y + (signe * v_two.y);
	v_res->z = v_one.z + (signe * v_two.z);
}
