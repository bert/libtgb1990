/*!
 * \file test.c
 * \author Copyright (C) 2008 by Bert Timmerman <bert.timmerman@xs4all.nl>
 * \brief Test program.
 *
 * <hr>
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

int
main (int argc, char *argv[])
{
        FILE *F_IR3;
        char InputFileName[] = "../test/03093-01.IR3";
        int length = 1024;
        char *TempText;
        char *Token;
        char Delimiters[] = " ()<>*;:-";
        ssize_t ErrorCode;

        F_IR3 = fopen (InputFileName, "r");
        if (F_IR3 != NULL)
        {
                fprintf (stderr, "Input file %s is opened Read-Only.\n", InputFileName);
        }
        else
        {
                fprintf (stderr, "Error: input file %s not found or does not exist.\n", InputFileName);
                exit (EXIT_FAILURE);
        }
        while (!feof (F_IR3))
        {
                TempText = (char *) malloc (length + 1);
                ErrorCode = getline (&TempText, &length, F_IR3);
                if (ErrorCode != -1)
                {
                        fprintf (stderr, "%s", TempText);
                        fprintf (stderr, "Start splitting into tokens.\n");
                        Token = strtok(TempText, Delimiters);
                        while (Token != NULL)
                        {
                                fprintf (stderr, "%s\n", Token);
                                Token = strtok (NULL, " ");
                        }
                        fprintf (stderr, "Ready splitting into tokens.\n");
                }
                else
                {
                        if (ErrorCode == EOF)
                        {
                                fprintf (stderr, "End Of File encountered.\nDone.\n");
                                exit (EXIT_FAILURE);
                        }
                        else
                        {
                                fprintf (stderr, "Error while reading line from file %s.\n", InputFileName);
                                exit (EXIT_FAILURE);
                        }
                }
        }
        ErrorCode = fclose (F_IR3);
        if (!ErrorCode)
        {
                fprintf (stderr, "Input file %s is closed.\n", InputFileName);
        }
        else
        {
                fprintf (stderr, "Error: input file %s not closed or does not exist.\n", InputFileName);
                exit (EXIT_FAILURE);
        }
        return (EXIT_SUCCESS);
}

/* EOF */
