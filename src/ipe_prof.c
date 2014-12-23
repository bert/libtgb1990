/*!
 * \file ipe_prof.c
 *
 * \brief This unit generates the properties of (prismatic) I-shaped
 * profiles (IPE class).
 * 
 * \author Copyright 2014 Bert Timmerman <bert.timmerman@xs4all.nl>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.\n
 * \n
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.\n
 * \n
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.\n
 * 
 * This unit generates the properties of (prismatic) I-shaped profiles.\n
 * \n
 * All standard available profiles are included (whatever that means ;-)\n
 * \n
 * \warning ALL x-, y- and z-indices refer to the LOCAL coordinate
 * system of the profile.\n
 *
 * \warning All units in SI-metrics [m, kg, sec] or derivatives, and are
 * stated below between [].\n
 * \n
 */


/*!
 * Description of fields in the table (with units between []):\n
 * <ul>
 * <li> ProfileName [-]</li>
 * <li> h [mm]</li>
 * <li> b [mm]</li>
 * <li> s [mm]</li>
 * <li> t [mm]</li>
 * <li> r [mm]</li>
 * <li> r1 [mm]</li>
 * <li> A [cm2]</li>
 * <li> c [mm]</li>
 * <li> h1 [mm]</li>
 * <li> wmin [mm]</li>
 * <li> wmax [mm]</li>
 * <li> d [mm]</li>
 * <li> Ixx [cm4]</li>
 * <li> Iyy [cm4]</li>
 * <li> iy [mm]</li>
 * <li> Wyy [cm3]</li>
 * <li> Syy [cm3]</li>
 * <li> Izz [cm4]</li>
 * <li> iz [mm]</li>
 * <li> Wzz [cm3]</li>
 * <li> m [kg/m]</li>
 * <li> ct [-]</li>
 * <li> </ul>
 */
enum inp_table_headings
(
        I_h,
        I_b,
        I_s,
        I_t,
        I_r,
        I_r1,
        I_A,
        I_c,
        I_h1,
        I_wmin,
        I_max,
        I_d,
        I_Ixx,
        I_Iyy,
        I_iy,
        I_Wyy,
        I_Syy,
        I_Izz,
        I_iz,
        I_Wzz,
        I_m,
        I_ct,
        I_NUMCOLS
)

#define I_NUMROWS 1024

char ipe_prof[I_NUMROWS][I_NUMCOLS]=
{
#include "ipe_prof.csv"
}


/* EOF */
