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
#ifndef WSSERVER_H_
#define WSSERVER_H_

#ifdef WINNT
#define strcasecmp(x, y) stricmp(x, y)
#endif

#define INDENT_UNIT "  "

#define OPERATION_ELEMENT "Operation"
#define PRIMITIVE_ELEMENT "Primitive"
#define ARRAY_ELEMENT "Array"
#define RECORD_ELEMENT "Record"
#define BASETYPE_ATTR "baseType"
#define NAME_ATTR "name"
#define DIMENSION_ATTR "dimension"

#undef DLLEXPORT
#undef DLLIMPORT
#undef DLLDECL

#ifdef WINNT
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLEXPORT
#define DLLIMPORT
#endif

#ifdef DLL__WSSERVER
#define DLLDECL DLLEXPORT
#else
#define DLLDECL DLLIMPORT
#endif

/*map between fgl type and sql type*/
typedef struct sqltype_map_s {
  char *fgltype;
  int sqltype;
} sqltype_map_t;

/*structure to describe a fgl type info*/
typedef struct fgl_type_s {
  char *JavaType;
  char *FglType;
  unsigned int length;
  unsigned int qualifier;
  unsigned int precision;
  unsigned int scale;
} fgl_type_t;

/*get the sql type for the given fgl type*/
int SqlType(char *fgltype);


/*structure to describe a 4gl parameter*/
typedef struct fgl_parameter_s {
  fgl_type_t *type;
  char *name;
  int isRecord;
  struct fgl_parameter_s *parent;
  unsigned int nchildren;
  struct fgl_parameter_s **children;
  int isArray;
  int dimensions;
} fgl_parameter_t;


/*4GL function pointer */
typedef int (*fgl_func_t)(int);

/*strure to describe a 4GL web service function*/
typedef struct fgl_ws_function_s {
  /*the name of fgl web service function*/
  char *name;
  /*the address of fgl web service function*/
  fgl_func_t add;
  /*the number of input paramters and the input parameter array*/
  unsigned int nparameters;
  fgl_parameter_t **parameters;
  /*the number of return parameters and the return paramter array*/
  unsigned int nreturns;
  fgl_parameter_t **returns;
  
} fgl_ws_function_t;

/*list to the description for each 4GL web service function*/ 
/*in the given 4GL project*/
typedef struct fgl_ws_function_list_s {
  unsigned int nfunctions;
  fgl_ws_function_t **functions;
} fgl_ws_function_list;

#ifdef __cplusplus
extern "C" {
#endif

/*operations on fgl type info*/
extern DLLDECL fgl_type_t *create_fgl_type(void);
extern DLLDECL void free_fgl_type(fgl_type_t * type);
extern DLLDECL void fgl_type_set_javatype(fgl_type_t *type, 
                                          const char *JavaType);
extern DLLDECL void fgl_type_set_fgltype(fgl_type_t * type, 
                                         const char *FglType);
extern DLLDECL void fgl_type_set_length(fgl_type_t *type, unsigned int length);
extern DLLDECL void fgl_type_set_prec(fgl_type_t *type, unsigned int prec);
extern DLLDECL void fgl_type_set_scale(fgl_type_t *type, unsigned int scale);
extern DLLDECL void fgl_type_set_qual(fgl_type_t *type, unsigned int qual);
void dump_fgl_type(fgl_type_t *type, const char *indent);

/*operations on fgl parameter*/
extern DLLDECL fgl_parameter_t *create_fgl_parameter(void);
extern DLLDECL void free_fgl_parameter(fgl_parameter_t *parameter);
extern DLLDECL void fgl_parameter_set_type(fgl_parameter_t *parameter, 
                                           fgl_type_t *type);
extern DLLDECL void fgl_parameter_set_name(fgl_parameter_t *parameter, 
                                           const char *name);
extern DLLDECL void fgl_parameter_set_isRecord(fgl_parameter_t *parameter, 
                                               int isRecord);
extern DLLDECL void fgl_parameter_add_child(fgl_parameter_t *parent, 
                                            fgl_parameter_t *child);
extern DLLDECL void fgl_parameter_set_isArray(fgl_parameter_t *parameter,
                                              int isArray);
extern DLLDECL void fgl_parameter_set_dimensions(fgl_parameter_t *parameter,
                                                 int dimensions);
int fgl_parameter_nprimitives(fgl_parameter_t *parameter);
void dump_fgl_parameter(fgl_parameter_t *parameter, char *indent);

/*operations on fgl web service functions*/
extern DLLDECL fgl_ws_function_t *create_fgl_ws_function(void);
extern DLLDECL void free_fgl_ws_function(fgl_ws_function_t *function);
extern DLLDECL void fgl_ws_function_set_name(fgl_ws_function_t *function, 
                                             const char *name);
extern DLLDECL void fgl_ws_function_set_add(fgl_ws_function_t *function, 
                                             fgl_func_t add);
extern DLLDECL void fgl_ws_function_add_parameter(fgl_ws_function_t *function, 
                                                  fgl_parameter_t *parameter);
extern DLLDECL void fgl_ws_function_add_return(fgl_ws_function_t *function, 
                                               fgl_parameter_t *parameter);
extern DLLDECL int fgl_ws_function_get_input_primitives(fgl_ws_function_t *function);
int fgl_ws_function_get_return_primitives(fgl_ws_function_t *function);
void dump_fgl_ws_function(fgl_ws_function_t *function, char *indent);

/*operations on 4GL web service function list*/
extern DLLDECL fgl_ws_function_list *create_fgl_ws_function_list(void);
void free_fgl_ws_function_list(fgl_ws_function_list *func_list);
extern DLLDECL void fgl_ws_function_list_add_function(fgl_ws_function_list *func_list, 
                                                      fgl_ws_function_t *func);

extern DLLDECL fgl_ws_function_t *fgl_ws_function_list_find_function(
  fgl_ws_function_list *func_list, const char *func_name);
void dump_fgl_ws_function_list(fgl_ws_function_list *func_list, const char *indent);

/*interface to call fgl function*/
extern DLLDECL int callFGLFunction(fgl_ws_function_list *func_list,
                                   const char *pcode_module);

#ifdef __cplusplus
}
#endif

#endif /*WSSERVER_H_*/
