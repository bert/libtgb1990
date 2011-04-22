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
 * \brief NEN6772 9.2-1: Calculate the design tensile stress for rivets.
 * 
 * \image html NEN6772_9.2-1.gif 
 */
double
f_t_k_d
(
    double f_t_k_rep,
    /*!< The repesentative tensile stress for a S235 rivet. */
    double gamma_M
    /*!< Material factor, defaults to 1. */
)
{
        return (f_t_k_rep / gamma_M);
}


/*!
 * \brief NEN6772 9.2-2: Calculate the design value for friction.
 * 
 * \image html NEN6772_9.2-2.gif 
 */
double
mu_d
(
    double mu_rep,
    /*!< The repesentative value for friction. */
    double gamma_M
    /*!< Material factor, defaults to 1. */
)
{
        return (mu_rep / gamma_M);
}


/*!
 * \brief NEN6772 9.2-3: Calculate the design stress for injection bolts.
 * 
 * \image html NEN6772_9.2-3.gif 
 */
double
f_b_d
(
    double f_b_rep,
    /*!< The repesentative stress for injection bolts. */
    double gamma_M
    /*!< Material factor, defaults to 1. */
)
{
        return (f_b_rep / gamma_M);
}


/*!
 * \brief NEN6772 11.5-1: Calculate the Unity Check on bending strength
 * in a beam-column connection (beam at the end of a column).
 * 
 * \image html NEN6772_11.5-1.gif 
 */
double
UC_11_5_1
(
    double M_v_s_d,
    /*!< Actual bending moment. */
    double M_v_asym_u_d
    /*!< Maximum bending capacity (asymmetrical). */
)
{
        return (abs (M_v_s_d) / M_v_asym_u_d);
}


/*!
 * \brief NEN6772 11.5-2: Calculate the Unity Check on bending strength
 * in a beam-column connection (single beam branching on a column).
 *
 * \image html NEN6772_11.5-2.gif 
 */
double
UC_11_5_2
(
    double M_v_s_d,
    /*!< Actual bending moment. */
    double M_v_sym_u_d
    /*!< Maximum bending capacity (symmetrical). */
)
{
        return (abs (M_v_s_d) / M_v_sym_u_d);
}


/*!
 * \brief NEN6772 11.5-3: Calculate the Unity Check on bending strength
 * in a beam-column connection (symmetrical beams branching on a
 * column).
 *
 * \image html NEN6772_11.5-3.gif 
 */
double
UC_11_5_3
(
    double M_v_s_d,
    /*!< Actual bending moment. */
    double V_1_k_s_d,
    /*!< Actual shear force (beam 1). */
    double V_2_k_s_d,
    /*!< Actual shear force (beam 2). */
    double F_v_d,
    /*!< Maximum shear capacity. */
    double h_v
    /*!< Moment arm. */
)
{
        return (abs (((M_v_s_d / h_v) + 0.5 * (V_1_k_s_d + V_2_k_s_d)) / F_v_d));
}


/*!
 * \brief NEN6772 11.5-4: Calculate the Unity Check on bending strength
 * in a beam-column connection (first of two beams branching on a
 * column).
 *
 * \image html NEN6772_11.5-4.gif 
 */
double
UC_11_5_4
(
    double M_1_v_s_d,
    /*!< Actual bending moment (beam 1). */
    double M_1_v_sym_u_d
    /*!< Maximum bending capacity (symmetrical connection, beam 1). */
)
{
        return (abs (M_1_v_s_d) / M_1_v_sym_u_d);
}


/*!
 * \brief NEN6772 11.5-5: Calculate the Unity Check on bending strength
 * in a beam-column connection (second of two beams branching on a
 * column).
 *
 * \image html NEN6772_11.5-5.gif 
 */
double
UC_11_5_5
(
    double M_2_v_s_d,
    /*!< Actual bending moment (beam 2). */
    double M_2_v_sym_u_d
    /*!< Maximum bending capacity (symmetrical connection, beam 2). */
)
{
        return (abs (M_2_v_s_d) / M_2_v_sym_u_d);
}


/*!
 * \brief NEN6772 11.5-6: Calculate the Unity Check on bending strength
 * in a beam-column connection (symmetrical beams branching on a
 * column).
 *
 * \image html NEN6772_11.5-6.gif 
 */
double
UC_11_5_6
(
    double M_1_v_s_d,
    /*!< Actual bending moment (beam 1). */
    double M_2_v_s_d,
    /*!< Actual bending moment (beam 2). */
    double V_1_k_s_d,
    /*!< Actual shear force (beam 1). */
    double V_2_k_s_d,
    /*!< Actual shear force (beam 2). */
    double F_v_d,
    /*!< Actual shear force. */
    double h_1_v,
    /*!< Moment arm (beam 2). */
    double h_2_v
    /*!< Moment arm (beam 2). */
)
{
        return (abs (((M_1_v_s_d / h_1_v) + (M_2_v_s_d / h_2_v) + 0.5 * (V_1_k_s_d + V_2_k_s_d)) / F_v_d));
}


/* EOF */
