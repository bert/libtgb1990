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
enum ipe_table_headings
(
        I_name,
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
"IPE80","80","46","3.8","5.2","5","0","764","10","60","0","0","0","0.6727","80.1","32.4","20","11.6","8.49","10.5","3.69","6","#ct"
"IPE100","100","55","4.1","5.7","7","0","1030","12.5","75","0","0","0","1.153","171","40.7","34.2","19.7","15.9","12.4","5.79","8.1","#ct"
"IPE120","120","64","4.4","6.3","7","0","1320","13.5","93","0","0","0","1.689","318","49","53","30.4","27.7","14.5","8.65","10.4","#ct"
"IPE140","140","73","4.7","6.9","7","0","1640","14","112","38","38","10","2.401","541","57.4","77.3","44.2","44.9","16.5","12.3","12.9","#ct"
"IPE160","160","82","5","7.4","9","0","20.1","16.5","127","42","42","12","3.530","869","65.8","109","61.9","68.3","18.4","16.7","15.8","#ct"
"IPE180","180","91","5.3","8","9","0","23.9","17","146","48","48","12","4.723","1317","74.2","146","83.2","101","20.5","22.2","18.8","#ct"
"IPE200","200","100","5.6","8.5","12","0","28.5","20.5","159","54","54","12","6.846","1943","82.6","194","110","142","22.4","28.5","22.4","#ct"
"IPE220","220","110","5.9","9.2","12","0","33.4","21","178","58","58","16","8.982","2772","91.1","252","143","205","24.8","37.3","26.2","#ct"
"IPE240","240","120","6.2","9.8","15","0","39.1","25","190","64","64","16","12.74","3892","99.7","324","183","284","26.9","47.3","30.7","#ct"
"IPE270","270","135","6.6","10.2","15","0","45.9","25","220","72","72","16","15.71","5790","112","429","242","420","30.2","62.2","36.1","#ct"
"IPE300","300","150","7.1","10.7","15","0","53.8","25.5","249","80","80","20","19.75","8356","125","557","314","604","33.5","80.5","42.2","#ct"
"IPE330","330","160","7.5","11.5","18","0","62.6","29.5","271","86","86","20","27.59","11770","137","713","402","788","35.5","98.5","49.1","#ct"
"IPE360","360","170","8","12.7","18","0","72.7","30.5","299","92","92","22","37.08","16270","150","904","510","1043","37.9","123","57.1","#ct"
"IPE400","400","180","8.6","13.5","21","0","84.5","34.5","331","96","96","22","50.41","23130","165","1160","654","1318","39.5","146","66.3","#ct"
"IPE450","450","190","9.4","14.6","21","0","98.8","35.5","379","102","102","24","66.05","33740","185","1500","851","1676","41.2","176","77.6","#ct"
"IPE500","500","200","10.2","16","21","0","116","37","426","108","108","24","88.62","48200","204","1930","1100","2142","43.1","214","90.7","#ct"
"IPE550","550","210","11.1","17.2","24","0","134","41","468","116","116","24","121.7","67120","223","2440","1390","2668","44.5","254","106","#ct"
"IPE600","600","220","12","19","24","0","156","43","514","120","120","24","164.6","92080","243","3070","1760","3387","46.6","308","122","#ct"
}


/* EOF */
