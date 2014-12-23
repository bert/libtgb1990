/*!
 * \file i_prof.c
 *
 * \brief This unit generates the properties of (prismatic) I-shaped profiles.
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
 *
 * Include the generation of properties of I-shaped profiles based
 * on input with parameters.\n
 * For instance parameter input in the form of the ProfileName = 
 * 'I500x300x14.5x28x27x0'.\n
 * Meaning:\n
 * I = I-shaped profile
 * 500 = height
 * x = delimiter (typical)
 * 300 = width
 * 14.5  = web thickness
 * 28 = flange thickness
 * 27 = radius between web and flanges
 * 0 = radius on outer edge of the flanges
 * Thus the properties of welded (double) symmetrical I-shaped profiles
 * can be generated.\n
 */


/* EOF */
