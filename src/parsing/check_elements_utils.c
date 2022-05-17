/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:13:03 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 11:20:44 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_double_elements_a_c(t_elem_nbr elem_nbr, char *iden)
{
	if ((elem_nbr.a_nbr) > 1)
		return (*iden = 'N', 1);
	if ((elem_nbr.c_nbr) > 1)
		return (*iden = 'M', 1);
	return (0);
}

bool	check_limit(char *ratio, double min, double max)
{
	double	hol;

	parse_ratio(ratio, &hol);
	if (hol < min || hol > max)
		return (1);
	return (0);
}

bool	check_dot(char *ratio, bool signe, bool dot)
{
	char	n_dot;
	int		i;

	n_dot = 0;
	i = 0;
	if (signe)
		if (ratio[i] == '+' || ratio[i] == '-')
			i++;
	while (ratio[i])
	{
		if (!dot && ratio[i] == '.')
			return (1);
		if (ratio[i] == '.')
			n_dot++;
		if ((!ft_isdigit(ratio[i]) && ratio[i] != '.') || n_dot > 1)
			return (1);
		i++;
	}
	if (ratio[i - 1] == '.' || ratio[0] == '.')
		return (1);
	return (0);
}

bool	check_tuple(char *tuple, int type, bool signe, bool dot)
{
	char	**tuple_splited;
	int		i;

	tuple_splited = ft_split(tuple, ',');
	if (strlen_2d(tuple_splited) != 3)
		return (free(tuple_splited), 1);
	i = 0;
	while (tuple_splited[i])
	{
		if (check_dot(tuple_splited[i], signe, dot))
			return (free(tuple_splited), 1);
		if (type == 0)
			if (ft_atoi(tuple_splited[i]) > 255)
				return (free(tuple_splited), 1);
		if (type == 1)
			if (check_limit(tuple_splited[i], -1, 1))
				return (free(tuple_splited), 1);
		i++;
	}
	return (free(tuple_splited), 0);
}
