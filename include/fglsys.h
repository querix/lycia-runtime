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
#ifndef _FGLSYS_H
#define _FGLSYS_H

#include "qxdefs.h"
#include "locator.h"

/* TEMPORARY - need to figure out what to do with the int8 type */
typedef long long int8;

#ifdef WINNT
#define usrcfuncs __declspec(dllexport) usrcfuncs
#endif

/* ========================================================================= */
/* Stack functions                                                           */
/* ========================================================================= */

#define VarPop __qx_VarPop
#define VarPush __qx_VarPush

#define ibm_lib4gl_popMInt __qx_popint
#define ibm_lib4gl_popInt2 __qx_popshort
#define ibm_lib4gl_popInt4 __qx_poplong
#define ibm_lib4gl_popInt8 __qx_popint8
#define ibm_lib4gl_popFloat __qx_popflo
#define ibm_lib4gl_popDouble __qx_popdub
#define ibm_lib4gl_popDecimal __qx_popdec
#define ibm_lib4gl_popQuotedStr __qx_popquote
#define ibm_lib4gl_popString __qx_popstring
#define ibm_lib4gl_popVarChar __qx_popvchar
#define ibm_lib4gl_popDate __qx_popdate
#define ibm_lib4gl_popDateTime __qx_popdtime
#define ibm_lib4gl_popInterval __qx_popinv
#define ibm_lib4gl_popBlobLocator __qx_poplocator

#define ibm_lib4gl_returnMInt __qx_retint
#define ibm_lib4gl_returnInt2 __qx_retshort
#define ibm_lib4gl_returnInt4 __qx_retlong
#define ibm_lib4gl_returnInt8 __qx_retint8
#define ibm_lib4gl_returnFloat __qx_retflo
#define ibm_lib4gl_returnDouble __qx_retdub
#define ibm_lib4gl_returnDecimal __qx_retdec
#define ibm_lib4gl_returnQuotedStr __qx_retquote
#define ibm_lib4gl_returnString __qx_retstring
#define ibm_lib4gl_returnVarChar __qx_retvchar
#define ibm_lib4gl_returnDate __qx_retdate
#define ibm_lib4gl_returnDateTime __qx_retdtime
#define ibm_lib4gl_returnInterval __qx_retinv

#define ibm_lib4gl_pushMInt __qx_pushint
#define ibm_lib4gl_pushInt2 __qx_pushshort
#define ibm_lib4gl_pushInt4 __qx_pushlong
#define ibm_lib4gl_pushInt8 __qx_pushint8
#define ibm_lib4gl_pushFloat __qx_pushflo
#define ibm_lib4gl_pushDouble __qx_pushdub
#define ibm_lib4gl_pushDecimal __qx_pushdec
#define ibm_lib4gl_pushQuotedStr __qx_pushquote
#define ibm_lib4gl_pushVarChar __qx_pushvchar
#define ibm_lib4gl_pushDate __qx_pushdate
#define ibm_lib4gl_pushDateTime __qx_pushdtime
#define ibm_lib4gl_pushInterval __qx_pushinv
#define ibm_lib4gl_pushBlobLocator __qx_pushlocator

#define popint __qx_popint
#define popshort __qx_popshort
#define poplong __qx_poplong
#define popflo __qx_popflo
#define popdub __qx_popdub
#define popdec __qx_popdec
#define popint8 __qx_popint8
#define popquote __qx_popquote
#define popstring __qx_popstring
#define popvchar __qx_popvchar
#define popdate __qx_popdate
#define popdtime __qx_popdtime
#define popinv __qx_popinv
#define poplocator __qx_poplocator

#define retint __qx_retint
#define retshort __qx_retshort
#define retlong __qx_retlong
#define retflo __qx_retflo
#define retdub __qx_retdub
#define retdec __qx_retdec
#define retint8 __qx_retbignit
#define retquote __qx_retquote
#define retstring __qx_retstring
#define retvchar __qx_retvchar
#define retdate __qx_retdate
#define retdtime __qx_retdtime
#define retinv __qx_retinv

#define pushint __qx_pushint
#define pushshort __qx_pushshort
#define pushlong __qx_pushlong
#define pushflo __qx_pushflo
#define pushdub __qx_pushdub
#define pushdec __qx_pushdec
#define pushint8 __qx_pushint8
#define pushquote __qx_pushquote
#define pushstring __qx_pushstring
#define pushvchar __qx_pushvchar
#define pushdate __qx_pushdate
#define pushdtime __qx_pushdtime
#define pushinv __qx_pushinv
#define pushlocator __qx_pushlocator

#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT int __qx_VarPop(int type, void *ivar, int prec, int scale);
DLLIMPORT void __qx_VarPush(int type, void *cvar, int prec, int scale);

DLLIMPORT void __qx_popint(int *val);
DLLIMPORT void __qx_popshort(short *val);
DLLIMPORT void __qx_poplong(long *val);
DLLIMPORT void __qx_popflo(float *val);
DLLIMPORT void __qx_popdub(double *val);
DLLIMPORT void __qx_popdec(dec_t *val,int qual);
DLLIMPORT void __qx_popint8(int8 *val);
DLLIMPORT void __qx_popquote(char *val, int len);
DLLIMPORT void __qx_popstring(char *val, int len);
DLLIMPORT void __qx_popvchar(char *val, int len);
DLLIMPORT void __qx_popdate(int *val);
DLLIMPORT void __qx_popdtime(dtime_t *val, int qual);
DLLIMPORT void __qx_popinv(intrvl_t *val, int qual);
DLLIMPORT void __qx_poplocator(blob_t **val);

DLLIMPORT void __qx_retint(int val);
DLLIMPORT void __qx_retshort(short int val);
DLLIMPORT void __qx_retlong(long val);
DLLIMPORT void __qx_retflo(float *val);
DLLIMPORT void __qx_retdub(double *val);
DLLIMPORT void __qx_retdec(dec_t *val);
DLLIMPORT void __qx_retbignit(int8 *val);
DLLIMPORT void __qx_retquote(char *val);
DLLIMPORT void __qx_retstring(char *val);
DLLIMPORT void __qx_retvchar(char *val);
DLLIMPORT void __qx_retdate(int val);
DLLIMPORT void __qx_retdtime(dtime_t *val, int qual);
DLLIMPORT void __qx_retinv(intrvl_t *val);

DLLIMPORT void __qx_pushint(int val);
DLLIMPORT void __qx_pushshort(short int val);
DLLIMPORT void __qx_pushlong(long val);
DLLIMPORT void __qx_pushflo(float *val);
DLLIMPORT void __qx_pushdub(double *val);
DLLIMPORT void __qx_pushdec(dec_t *val, unsigned int qual);
DLLIMPORT void __qx_pushint8(int8 *val);
DLLIMPORT void __qx_pushquote(char *val, int len);
DLLIMPORT void __qx_pushstring(char *val, int len);
DLLIMPORT void __qx_pushvchar(char *val, int len);
DLLIMPORT void __qx_pushdate(int val);
DLLIMPORT void __qx_pushdtime(dtime_t *val);
DLLIMPORT void __qx_pushinv(intrvl_t *val);
DLLIMPORT void __qx_pushlocator(blob_t *val);

#ifdef __cplusplus
}
#endif

/* ========================================================================= */
/* Decimal functions                                                         */
/* ========================================================================= */

#define deccvasc __qx_deccvasc
#define dectoasc __qx_dectoasc
#define deccvint __qx_deccvint
#define dectoint __qx_dectoint
#define deccvlong __qx_deccvlong
#define dectolong __qx_dectolong
#define deccvflt __qx_deccvflt
#define dectoflt __qx_dectoflt
#define deccvdbl __qx_deccvdbl
#define dectodbl __qx_dectodbl
#define decadd __qx_decadd
#define decsub __qx_decsub
#define decmul __qx_decmul
#define decdiv __qx_decdiv
#define deccmp __qx_deccmp
#define deccopy __qx_deccopy
#define dececvt __qx_dececvt
#define decfcvt __qx_decfcvt

#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT int __qx_deccvasc(char *str,int len,dec_t *np);
DLLIMPORT int __qx_dectoasc(dec_t *np,char *str,int len,int scale);
DLLIMPORT int __qx_deccvint(int intval,dec_t *np);
DLLIMPORT int __qx_dectoint(dec_t *np,int *ip);
DLLIMPORT int __qx_deccvlong(long longval,dec_t *np);
DLLIMPORT int __qx_dectolong(dec_t *np,long *lngp);
DLLIMPORT int __qx_deccvflt(float fltval,dec_t *np);
DLLIMPORT int __qx_dectoflt(dec_t *np,float *fltp);
DLLIMPORT int __qx_deccvdbl(double dblval,dec_t *np);
DLLIMPORT int __qx_dectodbl(dec_t *np,double *dblp);
DLLIMPORT int __qx_decadd(dec_t *n1,dec_t *n2,dec_t *n3);
DLLIMPORT int __qx_decsub(dec_t *n1,dec_t *n2,dec_t *n3);
DLLIMPORT int __qx_decmul(dec_t *n1,dec_t *n2,dec_t *n3);
DLLIMPORT int __qx_decdiv(dec_t *n1,dec_t *n2,dec_t *n3);
DLLIMPORT int __qx_deccmp(dec_t *n1,dec_t *n2);
DLLIMPORT int __qx_deccopy(dec_t *n1,dec_t *n2);
DLLIMPORT char *__qx_dececvt(dec_t *np,int ndigit,int *decpt,int *sign);
DLLIMPORT char *__qx_decfcvt(dec_t *np,int scale,int *decpt,int *sign);

#ifdef __cplusplus
}
#endif

/* ========================================================================= */
/* BIGINT functions                                                          */
/* ========================================================================= */

#define ifx_int8add __qx_int8add
#define ifx_int8cmp __qx_int8cmp
#define ifx_int8copy __qx_int8copy
#define ifx_int8cvasc __qx_int8cvasc
#define ifx_int8cvdbl __qx_int8cvdbl
#define ifx_int8cvdec __qx_int8cvdec
#define ifx_int8cvflt __qx_int8cvflt
#define ifx_int8cvint __qx_int8cvint
#define ifx_int8cvlong __qx_int8cvlong
#define ifx_int8cvlong_long __qx_int8cvlonglong
#define ifx_int8div __qx_int8div
#define ifx_int8mul __qx_int8mul
#define ifx_int8sub __qx_int8dub
#define ifx_int8toasc __qx_int8toasc
#define ifx_int8todbl __qx_int8todbl
#define ifx_int8todec __qx_int8todec
#define ifx_int8toflt __qx_int8toflt
#define ifx_int8toint __qx_int8toint
#define ifx_int8tolong __qx_int8tolong
#define ifx_int8tolong_long __qx_int8tolonglong

#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT int __qx_int8add(int8 *n1,int8 *n2,int8 *n3);
DLLIMPORT int __qx_int8cmp(int8 *n1,int8 *n2);
DLLIMPORT int __qx_int8copy(int8 *n1,int8 *n2);
DLLIMPORT int __qx_int8cvasc(char *str,int len,int8 *n);
DLLIMPORT int __qx_int8cvdbl(double d,int8 *n);
DLLIMPORT int __qx_int8cvdec(dec_t *d,int8 *n);
DLLIMPORT int __qx_int8cvflt(float d,int8 *n);
DLLIMPORT int __qx_int8cvint(int n1,int8 *n2);
DLLIMPORT int __qx_int8cvlong(long n1,int8 *n2);
DLLIMPORT int __qx_int8cvlonglong(long long n1,int8 *n2);
DLLIMPORT int __qx_int8div(int8 *n1,int8 *n2,int8 *quotient);
DLLIMPORT int __qx_int8mul(int8 *n1,int8 *n2,int8 *product);
DLLIMPORT int __qx_int8sub(int8 *n1,int8 *n2,int8 *difference);
DLLIMPORT int __qx_int8toasc(int8 *n1,char *str,int len);
DLLIMPORT int __qx_int8todbl(int8 *n1,double *d);
DLLIMPORT int __qx_int8todec(int8 *n,dec_t *d);
DLLIMPORT int __qx_int8toflt(int8 *n,float *f);
DLLIMPORT int __qx_int8toint(int8 *n1,int *n2);
DLLIMPORT int __qx_int8tolong(int8 *n1,long *n2);
DLLIMPORT int __qx_int8tolonglong(int8 *n1,long long *n2);

#ifdef __cplusplus
}
#endif

/* ========================================================================= */
/* Miscellaneous functions                                                   */
/* ========================================================================= */

#define Free __qx_Free
#define ibm_lib4gl_fglFatalError fgl_fatal
#define ibm_lib4gl_fglNotFatalError fgl_nofatal
#define ibm_lib4gl_returnFglWarningNo fgl_warn


#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT int __qx_Free(blob_t **blob);
DLLIMPORT int fgl_fatal(char *program, int line_no, int err);

#ifdef __cplusplus
}
#endif

#endif
