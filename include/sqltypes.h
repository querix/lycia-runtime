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

#ifndef SQLCHAR 

#define CCHARTYPE	100
#define CSHORTTYPE	101
#define CINTTYPE	102
#define CLONGTYPE	103
#define CFLOATTYPE	104
#define CDOUBLETYPE	105
#define CDECIMALTYPE	107
#define CFIXCHARTYPE	108
#define CSTRINGTYPE	109
#define CDATETYPE	110
#define CMONEYTYPE	111
#define CDTIMETYPE	112
#define CLOCATORTYPE    113
#define CVCHARTYPE	114
#define CINVTYPE	115
#define CFILETYPE	116

#define SQLCHAR		0
#define SQLSMINT	1
#define SQLINT		2
#define SQLFLOAT	3
#define SQLSMFLOAT	4
#define SQLDECIMAL	5
#define SQLSERIAL	6
#define SQLDATE		7
#define SQLMONEY	8
#define SQLNULL		9
#define SQLDTIME	10
#define SQLBYTES	11
#define SQLTEXT		12
#define SQLVCHAR	13
#define SQLINTERVAL	14
#define SQLNCHAR        15
#define SQLNVCHAR       16
#define SQLINT8		17
#define SQLSERIAL8	18
#define SQLUDTVAR	40
#define SQLLVARCHAR     43
#define SQLBOOL         45
// l_sergiy: begin few Informix specific types
#define IFX_SQLIMPEXP       46
#define IFX_SQLIMPEXPBIN    47
#define IFX_SQLINFXBIGINT   52
#define IFX_SQLBIGSERIAL    53
// l_sergiy: end few Informix specific types
#define SQLTYPE		0xff

#define SQLROWID        0xfe

#define SQLNONULL	0x100
#define SQLHOST		01000
#define SQLNETFLT	02000

#define SIZCHAR		1
#define SIZSMINT	2
#define SIZINT		4
#define SIZFLOAT	(sizeof(double))
#define SIZSMFLOAT	(sizeof(float))
#define SIZDECIMAL	17	/* decimal(32) */
#define SIZSERIAL	4
#define SIZDATE		4
#define SIZMONEY	17	/* decimal(32) */
#define SIZDTIME	7	/* decimal(12,0) */
#define SIZVCHAR	1

#define DEFDECIMAL	9	/* default decimal(16) size */
#define DEFMONEY	9	/* default decimal(16) size */
#define DATENULL	((int)0x80000000L)
#define DATEDOOM 	((int)0x80000001L)


#define ISDECTYPE(x)	(((x)&SQLTYPE)==SQLDECIMAL||((x)&SQLTYPE)==SQLMONEY)
#define ISDTTYPE(x)	(((x)&SQLTYPE)==SQLDTIME||((x)&SQLTYPE)==SQLINTERVAL)
#define ISFLTTYPE(x)	(((x)&SQLTYPE)==SQLFLOAT||((x)&SQLTYPE)==SQLSMFLOAT)
#define ISFLTNULL(x)	((*(int *)&(x)) == 0xffffffffL)

#define ISDBLNULL(x) \
	( ( ((int *)&x)[0] == (int)0xffffffffL) && \
	  ( ((int *)&x)[1] == (int)0xffffffffL) )
#define SETDBLNULL(x) \
	( ( ((int *)&x)[0] = (int)0xffffffffL), \
	  ( ((int *)&x)[1] = (int)0xffffffffL) )

#define SETFLTNULL(x)	((*(int *)&(x)) = ((int)0xffffffffL))


#endif
