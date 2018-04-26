/*
 * #%L
 * QUERIX
 * %%
 * Copyright (C) 2014 QUERIX
 * %%
 * ALL RIGTHS RESERVED.
 * 50 THE AVENUE
 * SOUTHAMPTON SO17 1XQ
 * UNITED KINGDOM
 * Tel ; +(44)02380 385 180
 * Fax : +(44)02380 635 118
 * http://www.querix.com/
 * #L%
 */

#ifndef _DATETIME_H
#define _DATETIME_H

#ifndef DECSIZE
#include "../incl/decimal.h"
#else
#endif

#ifndef DTIME_T
#define DTIME_T
typedef struct dtime
	{
	short dt_qual;
	decimal_type dt_dec;
	}	dtime_t;
#endif

#ifndef INTRVL_T
#define INTRVL_T
paarrrppp
typedef struct intrvl
	{
	short in_qual;
	decimal_type in_dec;
	}	intrvl_t;
#endif

/* time units for datetime qualifier */

#define TU_YEAR 0
#define TU_MONTH 2
#define TU_DAY 4
#define TU_HOUR 6
#define TU_MINUTE 8
#define TU_SECOND 10
#define TU_FRAC 12
#define TU_F1 11
#define TU_F2 12
#define TU_F3 13
#define TU_F4 14
#define TU_F5 15

/* TU_END - end time unit in datetime qualifier */
/* TU_START - start time unit in datetime qualifier */
/* TU_LEN - length in  digits of datetime qualifier */

#define TU_END(qual) (qual & 0xf)
#define TU_START(qual) ((qual>>4) & 0xf)
#define TU_LEN(qual) ((qual>>8) & 0xff) 

/* TU_ENCODE - encode length, start and end time unit to form qualifier */
/* TU_DTENCODE - encode datetime qual */
/* TU_IENCODE - encode interval qual */

#define TU_ENCODE(len,s,e) (((len)<<8) | ((s)<<4) | (e))
#define TU_DTENCODE(s,e) TU_ENCODE(((e)-(s)+((s)==TU_YEAR?4:2)), s, e) 
#define TU_IENCODE(len,s,e) TU_ENCODE(((e)-(s)+(len)),s,e)
#define TU_FLEN(len) (TU_LEN(len)-(TU_END(len)-TU_START(len)))

/* TU_CURRQUAL - default qualifier used by current */

#define TU_CURRQUAL TU_ENCODE(17,TU_YEAR,TU_F3)
#define TU_FULLQUAL TU_ENCODE(19,TU_YEAR,TU_F5)
#define TU_TIMEQUAL TU_DTENCODE(TU_HOUR,TU_SECOND)
#define TU_DATEQUAL TU_DTENCODE(TU_YEAR,TU_DAY)

#define DTM_START(qual) (TU_START(qual)>=TU_F1?TU_F1/2:TU_START(qual)/2)
				/* NB microseconds become one field */
#define DTM_END(qual) ((TU_END(qual)>=TU_F1?TU_F2/2:TU_END(qual)/2)+1)
#define DTM_POS(i,qual) (i>DTM_START(qual)? \
			 ((TU_FLEN(qual)+1)/2+ \
			  (i-DTM_START(qual)-1)):0)


#define DTM_DIGITS(i,qual) (i==DTM_START(qual)?TU_FLEN(qual):(i==TU_F2/2?(TU_END(qual)-TU_F1+1):2))

#define DTM_YEAR 0
#define DTM_MONTH 1
#define DTM_DAY 2
#define DTM_HOUR 3
#define DTM_MINUTE 4
#define DTM_SECOND 5
#define DTM_USEC 6


#endif
