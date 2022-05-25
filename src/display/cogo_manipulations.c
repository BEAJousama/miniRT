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

void	update_cogo_element(t_cogo *element, double t_pos[4][4])
{
    element->x = (t_pos[0][0] * element->x) + (t_pos[0][1] * element->y) + (t_pos[0][2] * element->z) - (t_pos[0][3]);
    element->y = (t_pos[1][0] * element->x) + (t_pos[1][1] * element->y) + (t_pos[1][2] * element->z) - (t_pos[1][3]);
    element->z = (t_pos[2][0] * element->x) + (t_pos[2][1] * element->y) + (t_pos[2][2] * element->z) - (t_pos[2][3]);
}	

void	update_cogo(t_elements *elem, double t_pos[4][4])
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
		update_cogo_element(&(elem->l[i].pos), t_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		update_cogo_element(&(elem->sp[i].pos), t_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		update_cogo_element(&(elem->pl[i].pos), t_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		update_cogo_element(&(elem->cy[i].pos), t_pos);
	elem->c->pos.x = 0;
	elem->c->pos.y = 0;
	elem->c->pos.z = 0;

}

void	move_origin_to_camera(t_elements *elem)
{
    double  t_pos_y[4][4];
	double  t_pos_x[4][4];
    double  t_pos[4][4];
    double  teta;
    double  beta;
    int     i;
    int     j;

    i = -1;
    while (++i < 4)
    {
        ft_memset(t_pos[i], 0, 4 * sizeof(double));
        ft_memset(t_pos_x[i], 0, 4 * sizeof(double));
        ft_memset(t_pos_y[i], 0, 4 * sizeof(double));
    }
    teta = (acos(elem->c->orient.z / sqrt(pow(elem->c->orient.z, 2) + pow(elem->c->orient.x, 2))));
    // printf("%.1f||\n", teta);
    t_pos_y[0][0] = cos(teta);
    t_pos_y[0][2] = sin(teta);
    t_pos_y[1][1] = 1;
    t_pos_y[2][0] = -sin(teta);
    t_pos_y[2][2] = cos(teta);
    t_pos_y[3][3] = 1;

    beta =(acos(sqrt(pow(mag_vector(elem->c->orient),2) - pow(elem->c->orient.y, 2)) / mag_vector(elem->c->orient)));
    t_pos_x[0][0] = 1;
    t_pos_x[1][1] = cos(beta);
    t_pos_x[1][2] = -sin(beta);
    t_pos_x[2][1] = sin(beta);
    t_pos_x[2][2] = cos(beta);
    t_pos_x[3][3] = 1;

    i = 0;
    j = 0;
    while (i < 4)
    {
        t_pos[i][j] = (t_pos_y[i][0] * t_pos_x[0][j]) + (t_pos_y[i][1] * t_pos_x[1][j]) + (t_pos_y[i][2] * t_pos_x[2][j]) + (t_pos_y[i][3] * t_pos_x[3][j]);
        if (++j == 4 && ++i)
            j = 0;
    }
    t_pos[0][3] = elem->c->pos.x;
    t_pos[1][3] = elem->c->pos.y;
    t_pos[2][3] = elem->c->pos.z; 
    i = 0;
    j = 0;
    while(i < 4)
    {
        printf("%.1f,", t_pos[i][j]);
        j++;
        if (j == 4)
        {
            j = 0;
            i++;
            printf("\n");
        }
    }
    update_cogo(elem, t_pos);
}

