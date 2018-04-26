$ifndef _LOCATOR_H;
$define _LOCATOR_H;

EXEC SQL BEGIN DECLARE SECTION;
typedef struct tag_loc_t {
  short loc_loctype;            /* USER: type of locator - see below    */
  union {                       /* variant on 'loc'                     */
    struct {                    /* case LOCMEMORY                       */
      int  lc_bufsize;          /* USER: buffer size */
      char *lc_buffer;          /* USER: memory buffer to use           */
      char *lc_currdata_p;/* INTERNAL: current memory buffer    */
      unsigned int   lc_mflags; /* USER/INTERNAL: memory flags          */
                                /*                      (see below)     */
    } lc_mem;

    struct {                    /* cases L0CFNAME & LOCFILE             */
      char *lc_fname;           /* USER: file name                      */
      unsigned int lc_mode;     /* USER: perm. bits used if creating    */
      int lc_fd;                /* USER: os file descriptior            */
      int lc_position;          /* INTERNAL: seek position              */
    } lc_file;
  } lc_union;

  int  loc_indicator;           /* USER SYSTEM: indicator               */
  int  loc_type;                /* USER SYSTEM: type of blob            */
  int  loc_size;                /* USER SYSTEM: num bytes in blob or -1 */
  unsigned int  loc_status;     /* SYSTEM: status return of locator ops */
  char *loc_user_env;           /* USER: for the user's PRIVATE use     */
  int  loc_xfercount;           /* INTERNAL/SYSTEM: Transfer count      */

  unsigned int (*loc_open)();
  unsigned int (*loc_close)();
  unsigned int (*loc_read)();
  unsigned int (*loc_write)();

  unsigned int   loc_oflags;    /* USER/INTERNAL: see flag definitions below */

  /* NBNBNB These are Querix specific */
  void *loc_mmap;               /* mmap pointer */
  int loc_mmap_fd;              /* mmap file descriptior */

} loc_t,blob_t;

typedef struct {
  char *fd;
  void *map_loc;
  int map_len;
} UnixMmap;

EXEC SQL END DECLARE SECTION;

$internal loc_t SQLTEXT;

#define	loc_fname	lc_union.lc_file.lc_fname
#define loc_fd		lc_union.lc_file.lc_fd
#define loc_position	lc_union.lc_file.lc_position
#define	loc_mmap	lc_union.lc_mmap
#define	loc_mmap_fd	lc_union.loc_mmap_fd	
#define loc_bufsize	lc_union.lc_mem.lc_bufsize
#define loc_buffer	lc_union.lc_mem.lc_buffer
#define loc_currdata_p	lc_union.lc_mem.lc_currdata_p
#define loc_mflags	lc_union.lc_mem.lc_mflags

/* Blob functions  */
int Locate(loc_t *blob, int locator_type, char *loc, int sqltype);
				/* Set blob location type, and (if LOCFILE
				   filename) */
void Free(loc_t *blob);		/* Free all storage assocaited with blob */
int OpenBlob(loc_t *loc,int mode,int size);
				/* Open up blob for access */
int CloseBlob(loc_t *loc);	/* Close blob */
int ReadBlob(loc_t *loc,char *buffer,int size,int *nbytes);
				/* Read up to size byte from loc into buffer
				   number of bytes read== (*nbytes) */
int WriteBlob(loc_t *loc,char *buffer,int size);
				/* Write size bytes from buffer to open blob
				   blob */
int NullBlob(loc_t *blob, int type);	/* Check to see if blob is null */
void ClearBlob(loc_t *blob);	/* Clear blob structure */
void ResetBlob(loc_t *blob);	/* Free and clear */
void InitBlob(loc_t *blob, int type);	/* Clear blob structure */
int BlobSize(loc_t *blob);	/* Number of bytes used to store bytes */
void *MapBlob(loc_t *blob);
int UnmapBlob(loc_t *blob);


/* Locator tyne definitions  */

#define LOCMEMORY	1		/* storage memory */
#define LOCFNAME	2		/* File name storage  */
#define LOCFILE		3		/* Files dscriptored storage  */
#define	LOCUSER		4		/* User define functions */

/*  open_locator flags set for open_blob_flgs */

#define LOC_RONLY	0x1		/* read only */
#define LOC_WONLY	0x2		/* write only */
#define LOC_APPEND	0x4		/* write with append */
#define LOC_TEMPFILE	0x8		/* tempfile blob */
#define LOC_USEALL	0x10		/* ignore blob_size field */

/* open_locator set for loc_mflags */

#define LOC_ALLOC	0x1		/* alloc & free memory */




$endif;
