#ifndef UTL_H_INCLUDED
#define UTL_H_INCLUDED

#include "Tos.h"
#include "cnc_types.h"

/* This lib is linked in cncapi.dll together with Tos */

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

#ifdef __cplusplus
extern "C" {
#endif


void  UtlInit(void);
void  UtlTerm(void);

//Logging macro
#define UTL_LOG(functionName, errorClass, code) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0,  NULL) 

#define UTL_LOG_P0(functionName, errorClass, code, fmt) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt)

#define UTL_LOG_P1(functionName, errorClass, code, fmt, p1) \
    /*lint -e534*/UtlLog(false, functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1)

#define UTL_LOG_P2(functionName, errorClass, code, fmt, p1, p2) \
    /*lint -e534*/UtlLog(false, functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2)

#define UTL_LOG_P3(functionName, errorClass, code, fmt, p1, p2, p3) \
    /*lint -e534*/UtlLog(false, functionName,  __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3)

#define UTL_LOG_P4(functionName, errorClass, code, fmt, p1, p2, p3, p4) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4)

#define UTL_LOG_P5(functionName, errorClass, code, fmt, p1, p2, p3, p4, p5) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4, p5)

#define UTL_LOG_P6(functionName, errorClass, code, fmt, p1, p2, p3, p4, p5, p6) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, p1, p2, p3, p4, p5, p6)

#ifdef __GNUC__

#define UTL_LOG_VA(functionName, errorClass, code, fmt, args...) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, ## args)

#define UTL_LOG_VA_FO(functionName, errorClass, code, fmt, args...) \
    /*lint -e534*/UtlLog(true, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, ## args)

#else

#define UTL_LOG_VA(functionName, errorClass, code, fmt, ...) \
    /*lint -e534*/UtlLog(false, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, __VA_ARGS__)

#define UTL_LOG_VA_FO(functionName, errorClass, code, fmt, ...) \
    /*lint -e534*/UtlLog(true, functionName, __FILE__, __LINE__, errorClass, code, 0, fmt, __VA_ARGS__)


#endif

//Tracing macros, the higher the level, the more detail information
#ifndef TSL_SKIP_TRACING


#define UTL_TL_MAIN 0x1
#define UTL_TL_CMD  0x2
#define UTL_TL_INT  0x4
#define UTL_TL_EXE  0x8
#define UTL_TL_TRG  0x10
#define UTL_TL_TRG1 0x20
#define UTL_TL_TRG2 0x40
#define UTL_TL_TRG3 0x80


#define UTL_TRACE(functionName, l) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, NULL); }

#define UTL_TRACE0(functionName, l, fmt) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt); }

#define UTL_TRACE1(functionName, l, fmt, p1) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1); }

#define UTL_TRACE2(functionName, l, fmt, p1, p2) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2); }

#define UTL_TRACE3(functionName, l, fmt, p1, p2, p3) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3); }

#define UTL_TRACE4(functionName, l, fmt, p1, p2, p3, p4) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4); }

#define UTL_TRACE5(functionName, l, fmt, p1, p2, p3, p4, p5) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5); }

#define UTL_TRACE6(functionName, l, fmt, p1, p2, p3, p4, p5, p6) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6); }

#define UTL_TRACE7(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7); }

#define UTL_TRACE8(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8); }

#define UTL_TRACE9(functionName, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9) {\
    UtlTrace(functionName, __FILE__, __LINE__, l, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9); }

#define UTL_TRACE_VA(functionName, l, fmt, ...) \
    /*lint -e534*/UtlTrace(functionName, __FILE__, __LINE__, l, fmt, __VA_ARGS__)

#else

/* Set macros to empty if TSL_SKIP_TRACEGING is defined */

#define UTL_TRACE0(functionName, fmt)
#define UTL_TRACE1(functionName, fmt, p1)
#define UTL_TRACE2(functionName, fmt, p1, p2)
#define UTL_TRACE3(functionName, fmt, p1, p2, p3)
#define UTL_TRACE4(functionName, fmt, p1, p2, p3, p4)
#define UTL_TRACE5(functionName, fmt, p1, p2, p3, p4, p5)
#define UTL_TRACE6(functionName, fmt, p1, p2, p3, p4, p5, p6)
#define UTL_TRACE7(functionName, fmt, p1, p2, p3, p4, p5, p6, p7)
#define UTL_TRACE8(functionName, fmt, p1, p2, p3, p4, p5, p6, p7, p8)
#define UTL_TRACE9(functionName, fmt, p1, p2, p3, p4, p5, p6, p7, p8, p9)

#endif



/* Assert macro, remain looping until assert function returns 0 */
#define UTL_ASSERT(exp) {UtlAssert((exp), #exp, __FILE__, __LINE__)/*lint -i 722*/;}

/* Assert */
int UtlAssert(int expression, const char *expressionText, const char *file, unsigned line);

/* Log infos warnings errors for user */
/* actual loggin decoupled to a thread, so that this can be used in the real time motion part */
void UtlLog(bool            fileOnly,       /* log to file only and not to gui */
            char            *functionName,  /* name of the function that caused the error */
            char            *file,          /* the c-file name where the code resides     */
            int             line,           /* the offending line number                  */
            CNC_ERROR_CLASS  errorClass,    /* PS error class                            */
            CNC_RC           error,         /* PS error code                             */
            int             subCode,        /* error subcode                              */
            char            *fmt, ...);     /* optional text aruments                     */

/* same function, however not decoupled, write into file and use buffer happens in calling context */
void UtlLogDirect(bool  fileOnly,       /* log to file only and not to gui */
    char            *functionName,  /* name of the function that caused the error */
    char            *file,          /* the c-file name where the code resides     */
    int             line,           /* the offending line number                  */
    CNC_ERROR_CLASS  errorClass,    /* PS error class                            */
    CNC_RC           error,         /* PS error code                             */
    int             subCode,        /* error subcode                              */
    char            *fmt, ...);     /* optional text aruments                     */



/* wait until logging completed */
void UtilFlushLogging(void);

/* Trace functions */
void UtlTrace(char   *functionName, /* name of the function that caused the error */
              char   *file,         /* the c-file name where the code resides     */
              int    line,          /* the offending line number                  */
              int    level,
              char   *fmt, ...);    /* optional text aruments                     */

void  UtlOpenTraceFile(void);
void  UtlCloseTraceFile(void);
void  UtlTraceFile( bool includeTimeStamp, char *fmt, ...);
void  UtlFlushTraceFile(void);
void  UtlSetTraceLevel(int level);



/* Read parameter from INI file and log eventual errors */
FILE * UtlIniOpenFile(char *fileName, char *openAttributes);
int    UtlIniCloseFile(FILE *fp);
void   UtlIniSetLogging(int on);
int    UtlIniGetLogging(void);
CNC_RC UtlIniReadRealParameter(char * fileName, FILE *fp, char *parameter, char *section, double *parValue);
CNC_RC UtlIniReadStringParameter(char * fileName, FILE *fp, char *parameter, char *section, char *parValue, int maxLen);
CNC_RC UtlIniReadIntParameter(char * fileName, FILE *fp, char *parameter, char *section, int  *parValue);
CNC_RC UtlIniReadLongLongParameter(char * fileName, FILE *fp, char *parameter, char *section, long long  *parValue);
CNC_RC UtlIniReadBoolParameter(char * fileName, FILE *fp, char *parameter, char *section, int *parValue);

/* format e.g. 0x32 to 0011 0010 */
void  UtlFormatBinary8(unsigned char x, char *out_10_bytes);
void  UtlFormatBinary16(unsigned short x, char *out_20_bytes);
void  UtlFormatBinary32(unsigned int x, char *out_40_bytes);
void  UtlFormatBinary10(unsigned short x, char *out_13_bytes);



/* Remove path from filename */
char * UtlStripName( char *fileName );
TOS_WCHAR_T * UtlStripNameU( TOS_WCHAR_T *fileName );

/* Case insensitive string compare */
int UtlStriCmp(const char *anyCase, const char *lowerCase);

/* Case insensitive string compare */
int UtlStrniCmp(const char *anyCase, const char *lowerCase, size_t count);

char * UtlCreateDateTimeString( char createString[] /* take str length is 20 */);



/* rotate G68 with only XY rotation*/
void UtlRotateScale(int reverse, double rotationDegrees, CNC_VECTOR rotationPoint,  CNC_VECTOR scaleFactor, double *x, double *y);

/* rotate G68 with XY XZ or YZ rotation */
void UtlRotateScale2(int reverse, /*if true, an un-rotate is performed */ const CNC_OFFSET_AND_PLANE &op, /*Parameters for the rotation */ double &x, double &y, double &z); /*Rotated output values*/

void UtlRotateScaleBasic( int reverse, 
    double XYRotationDegrees, double XZRotationDegrees, double YZRotationDegrees, //rotation angle
    bool   XYRotationActive,  bool   XZRotationActive,  bool   YZRotationActive,  //which plane, only one of them
    double rotationPoint_x,   double rotationPoint_y,   double rotationPoint_z,   //rotation point
    bool   scalingActive,                                                         //true if scaling factors are used in rotation plane
    double scalingFactor_x,   double scalingFactor_y,   double scalingFactor_z,   //Scaling factors
    double  &x,               double &y,                double &z );      



/* Convert interpreter-work position to machine position */
CNC_CART_DOUBLE UtlMachinePositionFromWorkPosition(CNC_CART_DOUBLE  workPos, CNC_OFFSET_AND_PLANE op);

/* Convert machine position to interpreter-work position */
CNC_CART_DOUBLE UtlWorkPositionFromMachinePosition(CNC_CART_DOUBLE machinePos, CNC_OFFSET_AND_PLANE op);




#ifdef __cplusplus
}
#endif


#endif //UTL_H_INCLUDED

