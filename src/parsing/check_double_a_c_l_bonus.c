/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_a_c_l_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:51:58 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/11 10:01:01 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_double_elements_a_c_l(t_elem_nbr elem_nbr, char *iden)
{
	if ((elem_nbr.a_nbr) > 1)
		return (*iden = 'N', 1);
	if ((elem_nbr.c_nbr) > 1)
		return (*iden = 'M', 1);
	return (0);
}
