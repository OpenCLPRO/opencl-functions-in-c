/*
Converting floats to int and double using various rounding modes,
like is done in OpenCL.
See also http://streamcomputing.eu/blog/2014-11-07/opencl-integer-rounding-c/

Copyright (C) 2014 Vincent Hindriksen of StreamComputing

All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that the above copyright notice and this paragraph are
duplicated in all such forms and that any documentation,
advertising materials, and other materials related to such
distribution and use acknowledge that the software was developed
by the StreamComputing.
The name of the StreamComputing may not be used to endorse or
promote products derived from this software without specific
prior written permission.

THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "limits.h"
#ifdef __cplusplus
#include <cmath>
#else
#include <math.h>
#endif

inline float saturate_int(float number) {
	if (isnan(number)) return (0.0f); // check if the number was already NaN
	return (number>INT_MAX ? (float)INT_MAX : number<INT_MIN ? (float)INT_MIN : number);
}
inline float saturate_long(float number) {
	if (isnan(number)) return (0.0f); // check if the number was already NaN
	return (number>LONG_MAX ? (float)LONG_MAX : number<LONG_MIN ? (float)LONG_MIN : number);
}
inline int convert_int_rte (float number) {
	int sign = (int)((number > 0) - (number < 0));
	int odd = ((int)number % 2); // odd -> 1, even -> 0
	return ((int)(number-sign*(0.5f-odd)));
}
inline int convert_int_rtp (float number) {
	return ((int)(number+0.5f));
}
inline int convert_int_rtn (float number) {
	return ((int)(number-0.5f));
}
inline int convert_int_rtz (float number) {
	return ((int)(number));
}
inline int convert_long_rte (float number) {
	int sign = (long)((number > 0) - (number < 0));
	int odd = ((long)number % 2); // odd -> 1, even -> 0
	return ((long)(number-sign*(0.5f-odd)));
}
inline int convert_long_rtp (float number) {
	return ((long)(number+0.5f));
}
inline int convert_long_rtn (float number) {
	return ((long)(number-0.5f));
}
inline int convert_long_rtz (float number) {
	return ((long)(number));
}
inline int convert_int_sat_rte (float number) {
	number = saturate_int(number);
	int sign = (int)((number > 0) - (number < 0));
	int odd = ((int)number % 2); // odd -> 1, even -> 0
	return ((int)(number-sign*(0.5f-odd)));
}
inline int convert_int_sat_rtp (float number) {
	return ((int)(saturate_int(number)+0.5f));
}
inline int convert_int_sat_rtn (float number) {
	return ((int)(saturate_int(number)-0.5f));
}
inline int convert_int_sat_rtz (float number) {
	return ((int)(saturate_int(number)));
}
inline int convert_long_sat_rte (float number) {
	number = saturate_long(number);
	int sign = (int)((number > 0) - (number < 0));
	int odd = ((int)number % 2); // odd -> 1, even -> 0
	return ((int)(number-sign*(0.5f-odd)));
}
inline int convert_long_sat_rtp (float number) {
	return ((long)(saturate_long(number)+0.5f));
}
inline int convert_long_sat_rtn (float number) {
	return ((long)(saturate_long(number)-0.5f));
}
inline int convert_long_sat_rtz (float number) {
	return ((long)(saturate_long(number)));
}
