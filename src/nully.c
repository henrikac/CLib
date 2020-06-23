/*
 * Contains procedures to work with NULL pointers
 * Copyright (C) 2020 Henrik Abel Christensen
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *		
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *						
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "nully.h"

/**
 * Exits the program if the pointer is NULL
 * @param[in] ptr The pointer to check if is NULL
 * @param[in] err_msg Error message to print if ptr is NULL
*/
void exit_if_null(void *ptr, const char *err_msg)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "%s\n", err_msg);
		exit(EXIT_FAILURE);
	}
}

/**
 * Exits the program is the pointer is not NULL
 * @param[in] ptr The pointer to check if is not NULL
 * @param[in] err_msg Error message to print if ptr is not NULL
*/
void exit_if_not_null(void *ptr, const char *err_msg)
{
	if (ptr != NULL)
	{
		fprintf(stderr, "%s\n", err_msg);
		exit(EXIT_FAILURE);
	}
}
