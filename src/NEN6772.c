/*!
 * \file NEN6772.c
 * 
 * \brief Implementation of formulas in NEN6772 (TGB 1990 - Steel structures - Connections).
 *
 * <b>Author:</b>\n
 * Copyright (C) 2011 by Bert Timmerman <bert.timmerman@xs4all.nl>
 * 
 * <b>License:</b>\n
 * This program is free software; you can redistribute it and/or modify\n
 * it under the terms of the GNU General Public License as published by\n
 * the Free Software Foundation; either version 2 of the License, or\n
 * (at your option) any later version.\n
 * \n
 * This program is distributed in the hope that it will be useful,\n
 * but WITHOUT ANY WARRANTY; without even the implied warranty of\n
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.\n
 * \n
 * You should have received a copy of the GNU General Public License\n
 * along with this program; if not, write to:\n
 * the Free Software Foundation, Inc.,\n
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.\n
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*!
 * \brief Unity Check on bending strength in a beam-column connection
 * (beam at the end of the column).
 * 
 * \image html NEN6772_11.5-1.gif 
 */
double
UC_11_5_1
(
    double M_v_s_d;
    /*!< . */
    double M_v_asym_u_d;
    /*!< . */
)
{
        return (abs (M_v_s_d) / M_v_asym_u_d);
}


/*!
 * \brief Unity Check on bending strength in a beam-column connection
 * (single beam branching on column).
 *
 * \image html NEN6772_11.5-2.gif 
 */
double
UC_11_5_2
(
    double M_v_s_d;
    /*!< . */
    double M_v_sym_u_d;
    /*!< . */
)
{
        return (abs (M_v_s_d) / M_v_sym_u_d);
}


/*!
 * \brief Unity Check on bending strength in a beam-column connection
 * (symmetrical beams branching on column).
 *
 * \image html NEN6772_11.5-3.gif 
 */
double
UC_11_5_3
(
    double M_v_s_d;
    /*!< . */
    double V_1_k_s_d;
    /*!< . */
    double V_2_k_s_d;
    /*!< . */
    double F_v_d;
    /*!< . */
    double h_v;
    /*!< . */
)
{
        return (abs (((M_v_s_d / h_v) + 0.5 * (V_1_k_s_d + V_2_k_s_d)) / F_v_d));
}


/* EOF */

