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
#ifndef _WSFUNCDECLS_H
#define _WSFUNCDECLS_H

#include "qxconfig.h"

#ifdef WSCLIENTLIB
#include "dllexportdefs.h"
#else
#include "dllimportdefs.h"
#endif

extern DLLDECL int fgl_wsdl_load(int argc);
extern DLLDECL int fgl_ws_call(int argc);
extern DLLDECL int fgl_ws_create(int argc);
extern DLLDECL int fgl_ws_close(int argc);
extern DLLDECL int fgl_ws_execute(int argc);
extern DLLDECL int fgl_ws_setparameters(int argc);
extern DLLDECL int fgl_ws_getdata(int argc);
extern DLLDECL int fgl_ws_error(int argc);
extern DLLDECL int fgl_ws_set_option(int argc);
extern DLLDECL int fgl_ws_data_using(int argc);
extern DLLDECL int fgl_ws_set_array_size(int argc);
extern DLLDECL int fgl_ws_get_array_size(int argc);
extern DLLDECL int fgl_ws_set_data(int argc);
extern DLLDECL int fgl_ws_get_data(int argc);
#endif
