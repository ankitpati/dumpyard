/* esfunc.h */
/* Essential Functions for C
 *
 * Copyright 2013 Ankit Pati <ankitpati@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the  terms of the GNU Lesser General Public License as published by the  Free
 * Software Foundation; either version 3 of the License, or (at your option) any
 * later version.
 *
 * This  library is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You  should  have received a copy of the GNU Lesser  General  Public  License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * The GPL v3 text can be found at <./gpl.txt>. The LGPL v3 text can be found at
 * <./lgpl.txt>.
 */

#ifndef apESFUNC_H
#define apESFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* all listed sorts ascend */

size_t lrand(size_t rand, size_t lower, size_t upper)
{
    return rand % (upper - lower + 1) + lower;
}

char *getstr()
{
    int c;
    size_t n;
    char *s, *t;
    if(!(s = t = malloc(1))) return NULL;
    for(n=0; (c=getchar())!=EOF && c-'\n' && (t=realloc(s, n+2)); s[n++]=c) s=t;
    if(!t){
        free(s);
        return NULL;
    }
    s[n] = '\0';
    return s;
}

char *b_search(char key, char *s)
{
    size_t high, low, mid;
    high = strlen(s) - 1;
    low = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (key == s[mid])
            return s + mid;
        else
            key < s[mid] ? (high = mid - 1) : (low = mid + 1);
    }
    return NULL;
}

char *bsort(char *s)
{
    size_t i, j, n;
    char temp;
    n = strlen(s);
    for (i = 1; i < n; ++i)
        for (j = n - 1; j >= i; --j)
            if (s[j - 1] > s[j]) {
                temp = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp;
            }
    return s;
}

char *inssort(char *s)
{
    size_t i, j, n;
    char temp;
    n = strlen(s);
    for (i = 1; i < n; ++i) {
        temp = s[i];
        for (j = i; j && temp < s[j - 1]; --j)
            s[j] = s[j - 1];
        s[j] = temp;
    }
    return s;
}

char *selsort(char *s)
{
    size_t i, j, n, small;
    char temp;

    n = strlen(s);
    for (i = 0; i < n; ++i) {
        for (small = j = i; j < n; ++j)
            if (s[j] < s[small])
                small = j;

        temp = s[small];
        s[small] = s[i];
        s[i] = temp;
    }

    return s;
}

char *mergsort(char *a, char *b, char *c)
{
    size_t i, j, k, m, n;
    m = strlen(a);
    n = strlen(b);
    i = j = k = 0;
    while (i < m && j < n)
        c[k++] = a[i] < b[j] ? a[i++] : b[j++];
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];
    c[m + n] = '\0';
    return c;
}

char *strrev(char *s)
{
    size_t i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

char *strinstr(char *hay, char *ned)
{
    size_t pos, nlen, i;

    for (nlen = 0; ned[nlen]; ++nlen);
    if (!nlen) return hay; /* emulate behaviour of strstr(3) */

    for (i = 0; hay[i] && i < nlen; ++i);
    if (i != nlen) return NULL;

    for (pos = 0; hay[pos + nlen - 1]; ++pos) {
        for (i = 0; i < nlen && (hay + pos)[i] == ned[i]; ++i);
        if (i == nlen) return hay + pos;
    }

    return NULL;
}

size_t str_len(char *s)
{
    size_t len = 0;
    while (*s++) ++len;
    return len;
}

int str_cmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) ++s1, ++s2;
    return *s1 - *s2;
}

char *str_cat(char *s1, char *s2)
{
    char *ret = s1;
    while (*s1) ++s1;
    while ((*s1++ = *s2++));
    return ret;
}

char *str_cpy(char *des, char *src)
{
    char *ret = des;
    while ((*des++ = *src++));
    return ret;
}

int ispalin(char *s)
{
    size_t i, j;
    for (i = 0, j = str_len(s) - 1; i < j && s[i] == s[j]; ++i, --j);
    return i == j;
}

size_t deldup(int *s, size_t n)
{
    size_t i, j, k;
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n; ++j)
            if (s[i] == s[j]) {
                for (k = j + 1; k < n; ++k)
                    s[k - 1] = s[k];
            }
    return n;
}

size_t uniq(int *a, size_t n)
{
    size_t i, r;
    for(i = r = 0; i < n; ++i)
        if(a[r] != a[i])
            a[++r] = a[i];
    return i ? r + 1 : 0;
}

int str_toi(char *s)
{
    size_t i;
    int sign, ret;
    for (i = 0; isspace(s[i]); ++i);
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        ++i;
    for (ret = 0; isdigit(s[i]) || isspace(s[i]) || s[i] == ','; ++i)
        if (isdigit(s[i]))
            ret = ret * 10 + (s[i] - '0');
    return sign * ret;
}

#endif
/* end of esfunc.h */
