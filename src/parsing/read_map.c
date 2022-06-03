/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:14:59 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 11:27:57 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	map_invalid(char iden)
{
	ft_putendl_fd("Erorr", 2);
	if (print_error_orient_vec(iden))
		exit (1);
	if (print_error_msg_map(iden))
		exit (1);
	else if (print_error_msg_a_c(iden))
		exit (1);
	else if (print_error_msg_l_pl(iden))
		exit (1);
	else if (print_error_msg_sp_cy(iden))
		exit(1);
}

char	check_element(t_elements *elem, char *element, char iden)
{
	char	**param;

	param = ft_split(element, ' ');
	if (!ft_strncmp(param[0], "A\0", 2))
		check_amb_light_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "C\0", 2))
		check_camera_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "L\0", 2))
		check_light_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "pl\0", 3))
		check_plane_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "sp\0", 3))
		check_sphere_element(elem, &iden, param);
	else if (!ft_strncmp(param[0], "cy\0", 3))
		check_cylinder_element(elem, &iden, param);
	else if (param[0])
		return (free_2d(param), '4');
	free_2d(param);
	return (iden);
}

bool	allocate_elements(t_elements *elem)
{
	if (alloc((void **)&elem->a, sizeof(t_amb_light) * (elem->elem_nbr.a_nbr)))
		return (0);
	if (alloc((void **)&elem->c, sizeof(t_camera) * (elem->elem_nbr.c_nbr)))
		return (0);
	if (alloc((void **)&elem->l, sizeof(t_light) * (elem->elem_nbr.l_nbr)))
		return (0);
	if (alloc((void **)&elem->sp, sizeof(t_sphere) * (elem->elem_nbr.sp_nbr)))
		return (0);
	if (alloc((void **)&elem->pl, sizeof(t_plane) * (elem->elem_nbr.pl_nbr)))
		return (0);
	if (alloc((void **)&elem->cy, sizeof(t_cylinder) * (elem->elem_nbr.cy_nbr)))
		return (0);
	return (1);
}

void	check_map(t_elements *elem, char **map)
{
	int		i;
	char	iden;

	i = 0;
	while (map[i])
	{
		iden = check_element(elem, map[i], 'x');
		if (iden != 'x')
		{
			free_2d(map);
			map_invalid(iden);
		}
		i++;
	}
	if (check_double_elements_a_c_l(elem->elem_nbr, &iden)
		|| !allocate_elements(elem))
		return (free_2d(map), free_elements(elem), map_invalid(iden));
	i = -1;
	while (map[++i])
		check_element(elem, map[i], 'X');
	iden = check_valid_orient_vec(elem);
	if (!elem->elem_nbr.c_nbr)
		iden = 'U';
	if (iden)
		return (free_2d(map), free_elements(elem), map_invalid(iden));
}

void	read_map(t_elements *elem, char *f_map)
{
	char	**map;
	char	*hget;
	char	*hol;
	int		fd;

	if (ft_strncmp(".rt", &f_map[ft_strlen(f_map) - 3], 3))
		map_invalid(INVALID_EXTENSION);
	fd = open(f_map, O_RDONLY);
	hol = NULL;
	while (1)
	{
		hget = get_next_line(fd);
		if (!hget)
			break ;
		hol = ft_strjoin2(hol, hget);
	}
	close(fd);
	if (!hol)
		map_invalid(EMPTY_MAP);
	map = ft_split(hol, '\n');
	free(hol);
	check_map(elem, map);
}
