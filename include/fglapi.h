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
#ifndef _FGLAPI_H
#define _FGLAPI_H

#include "qxdefs.h"

#define print_error_stderr __qx_print_error_stderr

#define fgl_start(modname) __qx_fgl_start(modname)
#define fgl_call(funcname,nargs) __qx_fgl_call(#funcname,nargs)
#define fgl_exitfm __qx_fgl_exitfm
#define fgl_end __qx_fgl_end

#ifdef __cplusplus
extern "C" {
#endif

DLLIMPORT int __qx_print_error_stderr;

DLLIMPORT int __qx_fgl_start(const char *modname);
DLLIMPORT int __qx_fgl_call(const char *funcname,int nargs);
DLLIMPORT int __qx_exitfm();
DLLIMPORT int __qx_fgl_end();

#ifdef __cplusplus
}
#endif

#endif
