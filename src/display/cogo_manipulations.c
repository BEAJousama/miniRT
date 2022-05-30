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

void	update_cogo_element(t_cogo *element, double **m_pos)
{
    t_cogo hol;

    hol = *element;
    element->x = (m_pos[0][0] * hol.x) + (m_pos[0][1] * hol.y)
        + (m_pos[0][2] * hol.z) + (m_pos[0][3]);
    element->y = (m_pos[1][0] * hol.x) + (m_pos[1][1] * hol.y)
        + (m_pos[1][2] * hol.z) + (m_pos[1][3]);
    element->z = (m_pos[2][0] * hol.x) + (m_pos[2][1] * hol.y)
        + (m_pos[2][2] * hol.z) + (m_pos[2][3]);
}	

void	update_cogo(t_elements *elem, double **m_pos)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.l_nbr)
		update_cogo_element(&(elem->l[i].pos), m_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		update_cogo_element(&(elem->sp[i].pos), m_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		update_cogo_element(&(elem->pl[i].pos), m_pos);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		update_cogo_element(&(elem->cy[i].pos), m_pos);
	elem->c->pos.x = 0;
	elem->c->pos.y = 0;
	elem->c->pos.z = 0;
    free(m_pos);

}

void    fill_sub_matrix(t_elements *elem, double **t_y, double **t_x)
{
    double  teta;
    double  beta;

    if (elem->c->orient.z && elem->c->orient.x)
        teta = (acos(elem->c->orient.z / sqrt(pow(elem->c->orient.z, 2)
            + pow(elem->c->orient.x, 2))));
    if (elem->c->orient.x < 0)
        teta = (2 * M_PI) - teta;
    t_y[0][0] = cos(teta);
    t_y[0][2] = sin(teta);
    t_y[1][1] = 1;
    t_y[2][0] = -sin(teta);
    t_y[2][2] = cos(teta);
    t_y[3][3] = 1;
    beta =  (acos(sqrt(pow(mag_vector(elem->c->orient),2)
        - pow(elem->c->orient.y, 2)) / mag_vector(elem->c->orient)));
    if (elem->c->orient.y < 0)
        beta =  (2 * M_PI) - beta;
    t_x[0][0] = 1;
    t_x[1][1] = cos(beta);
    t_x[1][2] = -sin(beta);
    t_x[2][1] = sin(beta);
    t_x[2][2] = cos(beta);
    t_x[3][3] = 1;
}

void    fill_main_matrix(double **t_pos, double **t_y, double **t_x)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        t_pos[i][j] = (t_y[i][0] * t_x[0][j]) + (t_y[i][1] * t_x[1][j])
            + (t_y[i][2] * t_x[2][j]) + (t_y[i][3] * t_x[3][j]);
        if (++j == 4 && ++i)
            j = 0;
    }
}

void	move_origin_to_camera(t_elements *elem)
{
    double  **t_pos_y;
	double  **t_pos_x;
    double  **t_pos;
    double  **m_pos;

    t_pos = NULL;
    m_pos = NULL;
    t_pos_y = NULL;
    t_pos_x = NULL;
    t_pos = alloc_matrix(t_pos, 4);
    m_pos = alloc_matrix(m_pos, 4);
    t_pos_y = alloc_matrix(t_pos_y, 4);
    t_pos_x = alloc_matrix(t_pos_x, 4);
    fill_sub_matrix(elem, t_pos_y, t_pos_x);
    fill_main_matrix(t_pos, t_pos_y, t_pos_x);
    t_pos[0][3] = elem->c->pos.x;
    t_pos[1][3] = elem->c->pos.y;
    t_pos[2][3] = elem->c->pos.z; 
    inverse_matrix(m_pos, t_pos, 4);
    update_cogo(elem, m_pos);
    free(t_pos_y);
    free(t_pos_x);
    free(t_pos);
}

