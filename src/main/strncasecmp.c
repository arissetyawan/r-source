/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 2002   The R Development Core Team.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

int strncasecmp(const char *s1, const char *s2, size_t n)
{
    char c1, c2;
    int i;

    for (i = 0; i < n; i++) {
	c1 = s1[i]; c2 = s2[i];
	if ((c1 >= 'a') && (c1 <= 'z')) c1 -= 0x20;
	if ((c2 >= 'a') && (c2 <= 'z')) c2 -= 0x20;
	if (c1 == '\0') return ((c2 == '\0') ? 0 : -1);
	if (c2 == '\0') return 1;
	if (c1 < c2) return -1;
	if (c1 > c2) return 1;
    }
    return 0;
}
