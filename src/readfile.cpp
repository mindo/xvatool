/*
   Copyright (C) 2009 Erik Lax 

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <stdio.h>
#include "readfile.hpp"

bool XVA::ReadFile(const std::string& path, std::string& result)
{
	FILE* fp = fopen(path.c_str(), "r");
 
 	if (!fp)
		return false;

	char buf[1024];
	size_t r;
	while((r = fread(buf, 1, sizeof(buf), fp)) > 0)
	{
		result.append(buf, r);
	}
	fclose(fp);

	return true;
}
