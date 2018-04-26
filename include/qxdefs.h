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

#ifndef _QXDEFS_H
#define _QXDEFS_H

/* $Format: "#define HYDRA_VERSION \"$QueriXMajorVersion: 4$\"" $ */
#define HYDRA_VERSION "4"

#ifdef AIX
#define loc_t xxxx_t
#include <locale.h>
#include <sys/localedef.h>
#undef loc_t
#endif

#ifdef WINNT
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLIMPORT
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

#ifdef WINNT
#define SIGQUIT 3
#define SIGHUP 1
#endif

#define FGLCALL(x,y) x(y)

/*
 * QUERIX OBJECTS & UTILS
 */

typedef void WINDOW;

#define	CONTROL(x)	(((x) & 0x5f) - 0x40 )
#define uiInKey()       uiInKey()

#define REPORT          void *
#define PANEL           void *
#define MENU            void *
#define FORM            void *
#define VALUE           void
#define	GENERIC_CURSOR  void *
#define CURSOR          void *
#define IfxBLOB         void *

#define START           0
#define OUTPUT          1 
#define FINISH          2

#define	COUNT	        1
#define	PERCENT	        2
#define	SUM	        3
#define	AVG	        4
#define	MAX	        5
#define	MIN	        6

#ifndef NULL
#define NULL	        0
#endif
#define	EXIT	        -1
#ifndef TRUE
#define	TRUE	        1
#endif
#ifndef FALSE
#define	FALSE	        0
#endif
#define	DECNULL	        -1
#define	SQLNOTFOUND	100
#define SQLINVALCURSOR  -400


#ifndef NEED_INT64
typedef long long              type_int64;
typedef unsigned long long     type_uint64;
#else
typedef int                    type_int64;
typedef unsigned int           type_uint64;
#endif

typedef int                    type_int32;
typedef short                  type_int16;
typedef unsigned int           type_uint32;
typedef unsigned short         type_uint16;

#define _T_INT64               type_int64
#define _T_UINT64              type_uint64
#define _T_INT32               type_int32
#define _T_UINT32              type_uint32
#define _T_INT16               type_int16
#define _T_UINT16              type_uint16

#ifndef NEED_INT64
#define INT64NULL              ((_T_INT64)0x8000000000000000LL)
#define INT64INVAL             ((_T_INT64)0x8000000000000001LL)
#define MAXINT64               ((_T_INT64)0x7FFFFFFFFFFFFFFFLL)
#else
#define INT64NULL              ((_T_INT64)0x80000000L)
#define INT64INVAL             ((_T_INT64)0x80000001L)
#define MAXINT64               ((_T_INT64)0x7FFFFFFFL)
#endif

#define INT32NULL              ((_T_INT32)0x80000000L)
#define INT32INVAL             ((_T_INT32)0x80000001L)
#define MAXINT32               ((_T_INT32)0x7FFFFFFFL)

#define INT16NULL              ((_T_INT16)0x8000)
#define INT16INVAL             ((_T_INT16)0x8001)
#define MAXINT16               ((_T_INT16)0x7FFF)

#define SHORTNULL              ((_T_INT16)0x8000)
#define LONGNULL               ((_T_INT32)0x80000000L)
#define DATENULL               ((_T_INT32)0x80000000L)
#define SHORTINVAL             ((_T_INT16)0x8001)
#define LONGINVAL              ((_T_INT32)0x80000001L)
#define DATEINVAL              ((_T_INT32)0x80000001L)


#define SQLCHAR		0
#define SQLSMINT        1
#define SQLINT          2
#define SQLFLOAT        3
#define SQLSMFLOAT      4
#define SQLDECIMAL      5
#define SQLSERIAL       6
#define SQLDATE         7
#define SQLMONEY        8
#define SQLNULL         9
#define SQLDTIME        10
#define SQLBYTES        11
#define SQLTEXT         12
#define SQLVCHAR        13
#define SQLINTERVAL     14
#define SQLNCHAR	15
#define SQLNVCHAR	16
#define SQLINT8  	17
#define SQLSERIAL8	18
#define SQLSET          19
#define SQLMULTISET     20
#define SQLLIST         21
#define SQLROW          22
#define SQLCOLLECTION   23
#define SQLROWREF       24

#define SQLUDTVAR       40
#define SQLUDTFIXED     41
#define SQLREFSER8      42
#define SQLLVARCHAR     43
#define SQLSENDRECV     44
#define SQLBOOL         45
//#define SQLIMPEXP       46
//#define SQLIMPEXPBIN    47
// l_sergiy: begin few Informix specific types
#define IFX_SQLIMPEXP       46
#define IFX_SQLIMPEXPBIN    47
#define IFX_SQLINFXBIGINT   52
#define IFX_SQLBIGSERIAL    53
// l_sergiy: end few Informix specific types

#define SQLTYPE		0xff

#define SQLROWID        0xfe

#define CCHARTYPE	SQLCHAR
#define CSHORTTYPE	SQLSMINT
#define CINTTYPE	SQLINT
#define CLONGTYPE	SQLINT
#define CFLOATTYPE	SQLSMFLOAT
#define CDOUBLETYPE	SQLFLOAT
#define CDECIMALTYPE	SQLDECIMAL
#define CFIXCHARTYPE	SQLCHAR
#define CSTRINGTYPE	SQLVCHAR
#define CDATETYPE	SQLDATE
#define CMONEYTYPE 	SQLMONEY
#define CDTIMETYPE	SQLDTIME
#define CLOCATORTYPE	SQLTEXT
#define CVCHARTYPE	SQLVCHAR
#define CINVTYPE	SQLINTERVAL

/* Boolean */
#define	BOOL_EQ 1
#define	BOOL_NE 2
#define	BOOL_LT 3
#define	BOOL_LE 4
#define	BOOL_GT 5
#define	BOOL_GE 6
#define	BOOL_AND 7
#define	BOOL_OR 8
#define	BOOL_NOT 9
#define	BOOL_NUL 10
#define	BOOL_NNU 11

#define UNARY_SPC    1
#define UNARY_ASC    2
#define UNARY_COL    3
#define UNARY_NEG    4
#define	UNARY_CLP    5
#define UNARY_BITNOT 6

#define	DTF_DAY		1
#define	DTF_MONTH	2
#define	DTF_YEAR	3
#define	DTF_WEEKDAY	4
#define	DTF_MDY		5
#define	DTF_TODATE	6
#define	DTF_UNITS	7
#define	DTF_EXTEND	8
#define	DTF_CURRENT	9
#define DTF_DATE        10
#define DTF_TIME	11

#define	BIN_ADD	1
#define	BIN_SUB	2
#define	BIN_MUL	3
#define	BIN_DIV	4
#define	BIN_MOD	5
#define	BIN_EXP	6
#define BIN_BOOLCAT 7
#define BIN_BITAND 8
#define BIN_BITOR 9
#define BIN_BITXOR 10

#define	SCRNEXT		1
#define	SCRPRIOR	2
#define	SCRFIRST	3
#define	SCRLAST		4
#define	SCRCURR		5
#define	SCRABS		6
#define	SCRREL		7

#define DECSIZE 16

#ifndef NEWERA
#define LOCMEMORY	1		/* storage memory */
#define LOCFNAME	2		/* File name storage  */
#define LOCFILE		3		/* Files dscriptored storage  */
#define	LOCUSER		4		/* User define functions */

/* 'flags' definitions for BLOBS */
#define BLOBISNULL	(0x0001)	/* BLOB is NULL */
#define BLOBALIEN	(0x0002)	/* BLOB is ALIEN */
#define BL_BSBLOB       (0x0004)        /* blob is stored in blobspace */
#define BL_PNBLOB       (0x0008)        /* store in tablespace */
#define BL_DESCRIPTOR	(0x0010)	/* optical BLOB descriptor */

/*
 * this struture is used to pass "useful" information back to
 * the user.
 */

#ifndef BLOBINFO_T
#define BLOBINFO_T
typedef struct blobinfo
    {
    int	bi_size;		/* Size of blob			*/
    int	bi_addr;		/* Starting Sector or BlobPage	*/
    int 	bi_family;		/* Family ID			*/
    int 	bi_volume;		/* Family Volume		*/
    short	bi_flags;		/* flags 			*/
    short	bi_medium;		/* Medium - odd if removable	*/
    } blobinfo_t;
#endif

typedef struct _Decimal {
  short _exponent;              /* exponent base 100            */
  short _position;              /* sign: 1=pos, 0=neg, -1=null  */
  short n_digits;               /* number of significant digits */
  char  dec_digits[DECSIZE];    /* actual digits base 100       */
} DECT;

#ifndef DEC_TYPE
#define DEC_TYPE
typedef struct _Decimal dec_t;
#endif
#ifndef DECIMAL_TYPE
#define DECIMAL_TYPE
typedef struct _Decimal decimal_type;
#endif

#ifdef _QX_ESQL
#define dec_dgts dec_digits
#define dec_pos _position
#define dec_ndgts n_digits
#define dec_exp _exponent
#define VCMAX(size)	((size) & 0x00ff)
#define VCMIN(size)	(((size) >> 8) & 0x00ff)
#define VCLENGTH(len)   (VCMAX(len)+1)
#define VCSIZ(max, min) ((((min) << 8) & 0xff00) + ((max) & 0x00ff))
#endif

#ifndef DTIME_T
#define DTIME_T
typedef struct _dtime_t {
  short dt_qual;
  decimal_type dt_dec;
} TIME;
#endif

#ifndef INTRVL_T
#define INTRVL_T
typedef struct _dtime_t dtime_t;

typedef struct _intrvl_t {
  short in_qual;
  decimal_type in_dec;
} intrvl_t;
#endif
#endif

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

typedef struct {
  short	keyval;
  char	*prompt;
  char	*text;
  short	helpno;
  short	option;
  short	mode;
} ITEM;

#ifndef NEWERA
#ifndef IFX_INT_TYPE
#define IFX_INT_TYPE
#ifndef INT4
typedef int		int4;
#else
typedef INT4		int4;
#endif
typedef short           int2;
typedef char            int1;
typedef int		mint;
typedef long		mlong;
#endif

#ifndef BIND_TYPE
#define BIND_TYPE
typedef struct sqlvar_struct {
  int2 sqltype;
  int4 sqllen;
  char *sqldata;
  int2 *sqlind;
  char *sqlname;
  char *sqlformat;
  int2 sqlitype;
  int2 sqlilen;            
  char *sqlidata; 
  int4 sqlxid;     
  char *sqltypename; 
  int2 sqltypelen;  
  int2 sqlownerlen;  
  int2 sqlsourcetype;
  char *sqlownername; 
  int4 sqlsourceid;  
  char *sqlilongdata; 
  int4 sqlflags;              
  void *sqlreserved;  
  } BIND;
#endif
#else
typedef struct sqlvar_struct BIND;
#endif

typedef struct {
  short attribute;
  short operator_offset;
  short next_condition;
} SCREENCOND;


typedef struct {
  short record_name;
  short record_start;
  short record_parts;
} SCREENRECORD;

typedef struct {
  short page_lines;
  short page_columns;
  short picture_offset;
} PAGE;

typedef struct _DISPLAY {
  short 	column;
  short 	size;
  char	line;
  char	page;
  struct _DISPLAY *next;
  short	name;
} DISPLAY;

typedef struct {
  char	*_pictstr;		
  char	*_strtab;	
  char	*_dbnmstr;
  char	*_others;
  int	*_longtab;
  short	*_shortab;
  struct	_FIELD	*_fldtab;
  DISPLAY		*_disptab;
  PAGE		*_pagetab;
  char	*_fpmim;	
  char	*_dectab;
  SCREENRECORD	*_rectab;	
  short	*_recpart;	
  SCREENCOND	*_condatt;	
  short	_pictsize;	
  short	_strtabsz;
  short	_dbnmsize;
  short	_othersz;
  short	_nlongs;	
  short	_nshorts;
  short	_nfields;
  short	_ndispds;
  short	_npages;
  short	_ndecims;	
  short	_nrecord;
  short	_nrparts;
  short	_ncondat;
  short	_ldelim;
  short	_rdelim;
  short	_color;	
} WINDOWFORM;

typedef struct _SCREENFIELD {
  short	table;		
  short	tablebind;
  short	column_name;
  short	nmind;
  short	flags;	
  short	field_type;			
  short	column_offset;		
  short	field_size;	
  short	label;	
  struct _SCREENFIELD	*next;	
  DISPLAY	*displst;
  short	attribs;		
  short	_default;	
  short	field_comment;
  short	field_subscript;
  short	number_of_includ;
  short	include_lst;
  short	field_format;
  short	field_lookup;
  short	field_picture;		
  short	number_of_conditions;
  short	decimal_precision;
  short	text_editor;	
} SCREENFIELD;

typedef struct _FIELD {
  char	*_field;
  char	*_record;
  short	_index;
  short _byname;
} FIELD;

typedef struct {
  char	*_field;
  char	*_record;
  short	_indexb;
  short	_indexa;
} EVENT;

typedef struct { 
  char *_action;
  int event;
} ACTIONEVENT;

typedef struct {
  short row, column;
  short up, down, left, right;
  short ifld, ibind, irecix;
} FIELD_CONTROL;

typedef void *IOAREA;

IOAREA GetActiveICB();
IOAREA GetPossibleActiveICB();
IOAREA GetNthICB();


typedef struct _DUMMY_WINDOW
{
  struct _DUMMY_WINDOW *upper, *lower;	
  WINDOW *win, *swin;		
  char *formname;	
  WINDOWFORM *winfrm;	
  short rows, columns;
  short promptline;	
  short msgline;
  short formline;			
  short cmtline;		
  short menuline;	
  short flag;	
  short forecolor;
  unsigned int ucount;	
} DUMMY_WINDOW;

#ifndef NEWERA
extern DLLIMPORT struct {
  int   sqlcode;
  char  sqlerrm[ 72 ];
  char  sqlerrp[ 8 ];
  int   sqlerrd[ 6 ];
#ifndef _QX_ESQL
  char  sqlawarn[ 8 ];
#else
  struct sqlcaw_s {
    char sqlwarn0;
    char sqlwarn1;
    char sqlwarn2;
    char sqlwarn3;
    char sqlwarn4;
    char sqlwarn5;
    char sqlwarn6;
    char sqlwarn7;
  } sqlwarn;
#endif
} sqlca;

#ifndef SQLDA_TYPE
#define SQLDA_TYPE
typedef struct sqlda
{
  int2 sqld;
  BIND *sqlvar;
  char desc_name[19];
  int2 desc_occ;
  struct sqlda *desc_next;
  void *reserved;
} SqlDa;

#endif
#endif

extern DLLIMPORT int engine_sql_code;
extern DLLIMPORT int SQLCODE;
extern DLLIMPORT VALUE *Stackp;

#ifdef WINNT
#ifdef NEWERA
extern "C" {
int NEESQLAddPreparedSql(char *name,char **text);
void NESqlSetNonblock(int onoff);
void SqlInterrupt();
int SqlDBType();

#define SqlDeclare NESqlDeclare
#define SqlDynamic NESqlDynamic
#define SqlPrepare NESqlPrepare
#define SqlPrepareNative NESqlPrepareNative
#define SqlOpen NESqlOpen
#define SqlClose NESqlClose
#define SqlFree NESqlFree
#define SqlDescribe NESqlDescribe
#define SqlExecute NESqlExecute
#define SqlExecuteInto NESqlExecuteInto
#define SqlImmediate NESqlImmediate
#define SqlFetch NESqlFetch
#define SqlScroll NESqlScroll
#define SqlPut NESqlPut
#define SqlFlush NESqlFlush
#define SqlLogon NESqlLogon
#define SqlLogoff NESqlLogoff
#define SqlConnect NESqlConnect
#define SqlSetConnection NESqlSetConnection
#define SqlQuery NESqlQuery
#define SqlDdl NESqlDdl
#define SqlDml NESqlDml
#define SqlBegin NESqlBegin
#define SqlCommit NESqlCommit
#define SqlRollback NESqlRollback
#define SqlLoad NESqlLoad
#define SqlUnload2 NESqlUnload2
#define ESQLAddPreparedSql NEESQLAddPreparedSql

int SqlRegisterExit(void *ptr);

};

#endif /* NEWERA */
#endif


#ifdef __cplusplus
extern "C" {
#endif

int SqlDeclare(CURSOR *cursor,char *name,int type,char **cmdtxt,
	       int nibind,BIND *ibindlst,
	       int nobind,BIND *obindlst);
int SqlDynamic(CURSOR crs,int type,char *curid);
int SqlPrepare(CURSOR *crs,char *stmt);
int SqlPrepareNative(CURSOR *crs,char *stmt);
int SqlOpen(CURSOR crs,int nibind,BIND *ibindlst);
int SqlClose(CURSOR crs);
int SqlFree(CURSOR crs);
int SqlDescribe(CURSOR crs, struct sqlda **da);
int SqlExecute(CURSOR crs,int nbind,BIND *bindlst);
int SqlImmediate(char *stmt);
int SqlFetch(CURSOR crs,int nbind,BIND *bindlst);
int SqlScroll(CURSOR crs,int nobind,BIND *obindlst,
	      int nibind,BIND *ibindlst,
	      int mode,long loc);
int SqlPut(CURSOR crs,int nbind,BIND *bindlst);
int SqlFlush(CURSOR crs);
int SqlLogon(char *dbs,char *x,int nbind,BIND *bindlst);
int SqlLogoff();
int SqlConnect(char *db,char *cname,char *usrname,char *pwd);
int SqlSetConnection(char *cname);
int SqlQuery(CURSOR ignore,char **cmdtext,
	     int nibind,BIND *ibindlst,
	     int nobind,BIND *obindlst);
int SqlDdl(char **cmdtxt,int nbind,BIND *bindlst);
int SqlDml(void *sb,char **cmdtxt,int nbind,BIND *bindlst);
int SqlBegin();
int SqlCommit();
int SqlRollback();
int SqlLoad(char *fname,char *delim,char *query);
int SqlUnload2(char *fname,char *delim,char *query,int nbind,BIND *bindlst);
int SqlDBType();
int SqlNativeError();
int SqlExecuteInto(CURSOR crs,int nbind,BIND *bindlst,int nobind,BIND *obindlst);
int SqlLockMode(int mode, int wait);
void ESQLFreePreparedSql(char *name);
int SqlRegisterExit(void *);
void QxAddData(char *lic);
void QxInitDomain(char *lic);
int ESQLAddPreparedSql(char *name,char **text);
char **ESQLPreparedSql(char *name);
void ESQLFreeCursor(char *name);
void ESQLAddCursor(char *name,CURSOR c);
CURSOR ESQLCursor(char *name);
CURSOR ESQLGenericCursor();
void SetupProgram(void);
char *SqlInterpretSql(char *sql);
char *sql_translate_stmt(char *sql);
void QxInitDBDriver(char *driver);
void SqlInterruptCursor(CURSOR c);
void SqlInterruptRunning(void);

void catalog_clear_tables(void);
void catalog_use_table(char *name);
char *catalog_get_user_tables(void);
int catalog_use_restrict(void);


#ifdef __cplusplus
};
#endif

#ifndef NEWERA
extern DLLIMPORT char SQLSTATE[16];
extern DLLIMPORT int FullSchemaDownloadOnConnect;
extern DLLIMPORT int status, int_flag, quit_flag;
extern DLLIMPORT char *DEBUG_MODES;
extern DLLIMPORT char q4gl_client_type[16];
extern DLLIMPORT int build_type;
extern DLLIMPORT int no_abort_report;
extern DLLIMPORT char sqlerrd6[19];
extern DLLIMPORT float FloatNull;
extern DLLIMPORT double DoubleNull;
extern DLLIMPORT float FloatInval;
extern DLLIMPORT double DoubleInval;
extern DLLIMPORT short InsertKey;
extern DLLIMPORT short DeleteKey;
extern DLLIMPORT short NextKey; 
extern DLLIMPORT short PreviousKey;
extern DLLIMPORT short FirstKey;
extern DLLIMPORT short EndKey;
extern DLLIMPORT short AcceptKey; 
extern DLLIMPORT short HelpKey;
extern DLLIMPORT short WrapMode; 
extern DLLIMPORT short Constrained;
extern DLLIMPORT int DisplayColor, InputColor;
extern DLLIMPORT int db_type;
extern REPORT *CurrentReport();
extern DLLIMPORT int report_line_break;
extern DLLIMPORT int af_valid;
extern DLLIMPORT int ifx_num;
extern DLLIMPORT int fgl_use_forked_pipe;
extern DLLIMPORT int fgl_ifx_report_header;
extern DLLIMPORT int ifx_display;
extern DLLIMPORT int print_error_stderr;
extern DLLIMPORT int ifx_multi;
extern DLLIMPORT int gui_varlen;
extern DLLIMPORT int ForcedBottomLineCount;
extern DLLIMPORT int auto_adjust_formline;
extern DLLIMPORT int ifx_dontdelnewrow;
extern DLLIMPORT int ifx_ovrwrite_dtqual;
extern DLLIMPORT int log_sql_errors;
extern DLLIMPORT VALUE *Stackp;
extern DLLIMPORT int dont_bind_on_display;

#else
extern "C" DLLIMPORT char SQLSTATE[6];
extern "C" DLLIMPORT char *DEBUG_MODES;
extern "C" DLLIMPORT int FullSchemaDownloadOnConnect;
extern "C" DLLIMPORT char q4gl_client_type[16];
extern "C" DLLIMPORT int no_abort_report;
extern "C" DLLIMPORT char sqlerrd6[19];
extern "C" DLLIMPORT float FloatNull;
extern "C" DLLIMPORT double DoubleNull;
extern "C" DLLIMPORT float FloatInval;
extern "C" DLLIMPORT double DoubleInval;
extern "C" DLLIMPORT short InsertKey, DeleteKey;
extern "C" DLLIMPORT short NextKey, PreviousKey;
extern "C" DLLIMPORT short AcceptKey, HelpKey;
extern "C" DLLIMPORT short WrapMode, Constrained;
extern "C" DLLIMPORT int DisplayColor, InputColor;
extern "C" DLLIMPORT int db_type;
extern "C" DLLIMPORT REPORT *CurrentReport();
extern "C" DLLIMPORT int report_line_break;
extern "C" DLLIMPORT int af_valid;
extern "C" DLLIMPORT int ifx_num;
extern "C" DLLIMPORT int ifx_display;
extern "C" DLLIMPORT int print_error_stderr;
extern "C" DLLIMPORT int ifx_multi;
extern "C" DLLIMPORT int gui_varlen;
extern "C" DLLIMPORT int ForcedBottomLineCount;
extern "C" DLLIMPORT int ifx_dontdelnewrow;
extern "C" DLLIMPORT int ifx_ovrwrite_dtqual;
extern "C" DLLIMPORT int log_sql_errors;
extern "C" DLLIMPORT VALUE *Stackp;

#endif




#define RST_NONE		0
#define RST_PAGE_HEADER		1
#define RST_ON_EVERY_ROW	2
#define RST_FIRST_PAGE_HEADER	3
#define RST_ON_LAST_ROW		4
#define RST_PAGE_TRAILER	5
#define RST_BEFORE_GROUP	6
#define RST_AFTER_GROUP		7

#define CONNECTION_NAMED	0
#define CONNECTION_DEFAULT	1
#define CONNECTION_CURRENT	2
#define CONNECTION_ALL		3

#endif
