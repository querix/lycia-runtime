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
#ifndef _FGIFUNC_H
#define _FGIFUNC_H

typedef struct {
  char *cf_name;              /* Name of function */
  int (*cf_ptr)();            /* Pointer to the function */
  short cf_nargs;             /* Ignored. RDS compatibility only */
} cfunc_t;

#endif
