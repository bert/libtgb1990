/*!
 * \file NEN6772.c
 * 
 * \brief Implementation of formulas in NEN6772 (TGB 1990 - Steel structures - Connections).
 *
 * <b>Author:</b>\n
 * Copyright (C) 2011 ... 2012 by Bert Timmerman <bert.timmerman@xs4all.nl>
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
 * \brief NEN6772 9.2-1: Calculate the design value for the tensile
 * stress for rivets.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_9.2-1.gif
 *
 * \retval f_t_k_d The design value for the tensile stress for rivets.
 */
double
f_t_k_d
(
    double f_t_k_rep,
    /*!< The representative tensile stress for a S235 rivet. */
    double gamma_M
    /*!< Material factor, defaults to 1. */
)
{
        return (f_t_k_rep / gamma_M);
}


/*!
 * \brief NEN6772 9.2-2: Calculate the design value for friction.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_9.2-2.gif
 *
 * \retval mu_d The design value for friction.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_9.2-3.gif
 *
 * \retval f_b_d The design value for the stress for injection bolts.
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
 * \brief NEN6772 11.1-1: Calculate the Unity Check on swaging force
 * on a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-1.gif
 *
 * \retval UC_11_1_1 The Unity Check value.
 */
double
UC_11_1_1
(
    double F_c_s_d,
    /*!< Actual swaging force. */
    double F_c_u_d
    /*!< Maximum swaging capacity. */
)
{
        return (F_c_s_d / F_c_u_d);
}


/*!
 * \brief NEN6772 11.1-2: Calculate the Unity Check on shear force
 * on a rivet.
 *
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-2.gif
 *
 * \retval UC_11_1_2 The Unity Check value.
 */
double
UC_11_1_2
(
    double F_v_s_d,
    /*!< Actual shear force. */
    double F_v_u_d
    /*!< Maximum shear capacity. */
)
{
        return (F_v_s_d) / F_v_u_d);
}


/*!
 * \brief NEN6772 11.1-3: Calculate the Unity Check on tension force
 * on a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-3.gif
 *
 * \retval UC_11_1_3 The Unity Check value.
 */
double
UC_11_1_3
(
    double F_t_s_d,
    /*!< Actual tension force. */
    double F_t_u_d
    /*!< Maximum tension capacity. */
)
{
        return (F_t_s_d / F_t_u_d);
}


/*!
 * \brief NEN6772 11.1-4: Calculate the Unity Check on tension and shear
 * force on a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-4.gif
 *
 * \retval UC_11_1_4 The Unity Check value.
 */
double
UC_11_1_4
(
    double F_t_s_d,
    /*!< Actual tension force. */
    double F_v_s_d,
    /*!< Actual shear force. */
    double F_t_u_d,
    /*!< Maximum tension capacity. */
    double F_v_u_d
    /*!< Maximum shear capacity. */
)
{
        return ((F_v_s_d / F_v_u_d) + (F_t_s_d / (1.4 * F_t_u_d)));
}


/*!
 * \brief NEN6772 11.1-5: Calculation of the ultimate swaging capacity
 * for a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-5.gif
 *
 * \retval F_c_u_d The calculated value for the ultimate swaging
 * capacity of a rivet.
 */
double
F_c_u_d
(
    double alpha_c,
    /*!< The swaging factor. */
    double alpha_red_1,
    /*!< Geometry factor for edge distances and pitch between holes. */
    double f_t_d,
    /*!< Tensile strength of the considered plate material. */
    double d_k_nom,
    /*!< Nominal diameter of the rivet. */
    double t,
    /*!< The thickness of the considered plate material. */
    double gamma_M
    /*!< The model factor, defaults to 1.25. */
)
{
        return ((2.5 * alpha_c * alpha_red_1 * f_t_d * d_k_nom * t) / gamma_M);
}


/*!
 * \brief NEN6772 11.1-6: Calculation of the ultimate shear capacity
 * for a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-6.gif
 *
 * \retval F_v_u_d The calculated value for the ultimate shear
 * capacity of a rivet.
 */
double
F_v_u_d
(
    double f_t_k_d,
    /*!< Tensile strength of the considered rivet material. */
    double A_k,
    /*!< Nominal area of the rivet hole. */
    double gamma_M
    /*!< The model factor, defaults to 1.25. */
)
{
        return ((0.6 * f_t_k_d * A_k) / gamma_M);
}


/*!
 * \brief NEN6772 11.1-7: Calculation of the ultimate tension capacity
 * for a rivet.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-7.gif
 *
 * \retval F_t_u_d The calculated value for the ultimate tension
 * capacity of a rivet.
 */
double
F_t_u_d
(
    double f_t_k_d,
    /*!< Tensile strength of the considered rivet material. */
    double A_k,
    /*!< Nominal area of the rivet hole. */
    double gamma_M
    /*!< The model factor, defaults to 1.25. */
)
{
        return ((0.6 * f_t_k_d * A_k) / gamma_M);
}


/*!
 * \brief NEN6772 : Calculation of the swaging factor for a rivet
 * connection.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_alpha_c_swaging.gif
 *
 * \retval alpha_c_swaging The calculated swaging factor of a rivet
 * connection.
 */
double
alpha_c
(
    double e_1_min,
    /*!< Minimum distance between the rivets and the edge of the plate. */
    double s_1_min,
    /*!< Minimum distance between rows of rivets. */
    double d_k_nom,
    /*!< Nominal diameter of the rivet. */
    double f_t_k_rep,
    /*!< The representative tensile strength of the considered rivet
     * material. */
    double f_t_rep
    /*!< The representative tensile strength of the considered plate
     * material. */
)
{
    double _alpha_c;

    _alpha_c = 1.0;
    if (_alpha_c >= (e_1_min / (3 * d_k_nom)))
    {
        _alpha_c = e_1_min / (3 * d_k_nom);
    }
    if (_alpha_c >= (s_1_min / (3 * d_k_nom)) - 0.25)
    {
        _alpha_c = (s_1_min / (3 * d_k_nom)) - 0.25;
    }
    if (_alpha_c >= (f_t_k_rep / f_t_rep))
    {
        _alpha_c = f_t_k_rep / f_t_rep;
    }
    return (_alpha_c);
}


/*!
 * \brief NEN6772 : Calculation of the reduction factor for a rivet
 * connection.
 *
 * \version NEN 6772:2000.
 *
 * \retval alpha_red_1 The calculated reduction factor of a rivet
 * connection.
 */
double
alpha_red_1
(
    double d_k_nom,
    /*!< Nominal diameter of the rivet. */
    double e_2,
    /*!< Distance between the rivets and the edge of the plate. */
    double s_2
    /*!< Distance between rows of rivets. */
)
{
    double _alpha_red_1;

    if (e_2 >= (1.5 * d_k_nom) && s_2 >= (3.0 * d_k_nom))
    {
            _alpha_red_1 = 1.0;
    }
    if (e_2 <= (1.2 * d_k_nom) && s_2 <= (2.4 * d_k_nom))
    {
            _alpha_red_1 = 0.67;
    }
    return (_alpha_red_1);
}


/*!
 * \brief NEN6772 11.1-8: Calculate the Unity Check on tension force on
 * a countersunk rivet or bolt.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-8.gif
 *
 * \retval UC_11_1_8 The Unity Check value.
 */
double
UC_11_1_8
(
    double F_t_s_d,
    /*!< Actual tension force. */
    double F_t_u_d,
    /*!< Maximum tension capacity. */
)
{
        return (F_t_s_d / (0.7 * F_t_u_d));
}


/*!
 * \brief NEN6772 11.1-9: Calculate the effective thickness of a plate
 * with a countersunk hole.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-9.gif
 *
 * \retval t_ef The effective thickness value.
 */
double
t_ef
(
    double t_nom,
    /*!< Nominal plate thickness, in mm. */
    double d_vzk,
    /*!< Depth of the countersunk hole, in mm. */
)
{
        return (t_nom - 0.5 * d_vzk);
}


/*!
 * \brief NEN6772 11.1-10: Calculate the Unity Check on tension and
 * shear force on a countersunk rivet or bolt.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-10.gif
 *
 * \retval UC_11_1_10 The Unity Check value.
 */
double
UC_11_1_10
(
    double F_t_s_d,
    /*!< Actual tension force. */
    double F_v_s_d,
    /*!< Actual shear force. */
    double F_t_u_d,
    /*!< Maximum tension capacity. */
    double F_v_u_d
    /*!< Maximum shear capacity. */
)
{
        return ((F_v_s_d / F_v_u_d) + (F_t_s_d / (1.4 * 0.7 * F_t_u_d)));
}


/*!
 * \brief NEN6772 11.1-11: Calculate the Unity Check on the
 * representative shearing force on a pre-tensiond bolt with regard to
 * maximum gliding resistance capacity of the contact surfaces.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-11.gif
 *
 * \retval UC_11_1_11 The Unity Check value.
 */
double
UC_11_1_11
(
    double F_g_s_rep,
    /*!< Representative shearing force. */
    double F_g_u_d,
    /*!< Maximum resistance gliding capacity. */
)
{
        return (F_g_s_rep / F_g_u_d);
}


/*!
 * \brief NEN6772 11.1-12: Calculate the Unity Check on the actual
 * shearing force on a pre-tensiond bolt with regard to
 * maximum gliding resistance capacity of the contact surfaces.
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.1-12.gif
 *
 * \retval UC_11_1_12 The Unity Check value.
 */
double
UC_11_1_12
(
    double F_g_s_d,
    /*!< Actual shearing force. */
    double F_g_u_d,
    /*!< Maximum resistance gliding capacity. */
)
{
        return (F_g_s_d / F_g_u_d);
}


/*!
 * \brief NEN6772 11.5-1: Calculate the Unity Check on bending strength
 * in a beam-column connection (beam at the end of a column).
 *
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-1.gif
 * 
 * \retval UC_11_5_1 The Unity Check value.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-2.gif
 *
 * \retval UC_11_5_2 The Unity Check value.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-3.gif
 *
 * \retval UC_11_5_3 The Unity Check value.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-4.gif
 *
 * \retval UC_11_5_4 The Unity Check value.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-5.gif
 *
 * \retval UC_11_5_5 The Unity Check value.
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
 * \version NEN 6772:2000.
 *
 * \image html NEN6772_11.5-6.gif
 *
 * \retval UC_11_5_6 The Unity Check value.
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
