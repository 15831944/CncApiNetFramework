
//=================================================================
//    _____       _   _                    ____   _   _    ____
//   | ____|   __| | (_)  _ __     __ _   / ___| | \ | |  / ___|
//   |  _|    / _` | | | | '_ \   / _` | | |     |  \| | | |
//   | |___  | (_| | | | | | | | | (_| | | |___  | |\  | | |___
//   |_____|  \__,_| |_| |_| |_|  \__, |  \____| |_| \_|  \____|
//                                |___/
// ================================================================= 

#ifndef CNC_BASIC_TYPES_H_INCLUDED
#define CNC_BASIC_TYPES_H_INCLUDED
#include <stdlib.h>
#include <math.h>

//Use a packing/alignment of 1 byte
#pragma pack(1)

#ifndef EDINGCNC_VERSION
#define EDINGCNC_VERSION "CNC V4.03.36"
#define EDINGCNC_MAJOR_VERSION 4
//#define EDINGCNC_LIMITED_VERSION 1
#endif

#ifndef CNC_EPSILON
#define CNC_EPSILON (0.00001)
#endif

#ifndef CNC_EPSILON_EPSILON
#define CNC_EPSILON_EPSILON (1e-33)
#endif


#ifndef CNC_DOUBLES_ARE_EQUAL
#define CNC_DOUBLES_ARE_EQUAL(x,y)  (int)(fabs( (double)((x)-(y)) ) < CNC_EPSILON )
#endif

#ifndef CNC_DOUBLES_ARE_EQUAL_E
#define CNC_DOUBLES_ARE_EQUAL_E(x,y,e)  (int)(fabs( (double)((x)-(y)) ) < e )
#endif

#ifndef CNC_FLOATS_ARE_EQUAL
#define CNC_FLOATS_ARE_EQUAL(x,y)  (int)(fabs( (float)((x)-(y)) ) < CNC_EPSILON )
#endif

#ifndef CNC_FLOATS_ARE_EQUAL_E
#define CNC_FLOATS_ARE_EQUAL_E(x,y,e)  (int)(fabs( (float)((x)-(y)) ) < e )
#endif


#ifndef CNC_ROUND_TO_INT
#define CNC_ROUND_TO_INT(a) ((a) > 0) ? (int)((a) + 0.5) : (((a) < 0) ? (int) ((a) - 0.5) : (int)0)
#endif


#define CNC_MAGIC_NOTUSED_DOUBLE -1.0e10
#define CNC_MAGIC_ZERO 1.0e-33

#define CNC_IS_MAGIC_NOTUSED(x)  (int)(fabs( (double)((x)-(CNC_MAGIC_NOTUSED_DOUBLE)) ) < CNC_EPSILON )
#define CNC_DOUBLE_IS_ZERO(x)  (int)(fabs( (double)((x)-(CNC_MAGIC_ZERO)) ) < CNC_EPSILON_EPSILON )

#define CNC_DOUBLE_FUZZ 2.2204460492503131e-16
#define CNC_FULL_CIRCLE_FUZZ_STANDARD (0.000001) //Can be changed



inline double CNC_ROUND_TO_DECIMAL4 (double x)
{
    x = CNC_ROUND_TO_INT(x * 10000);
    x /= 10000;
    return x;
}


inline double CNC_ROUND_TO_DECIMAL3 (double x)
{
    x = CNC_ROUND_TO_INT(x * 1000);
    x /= 1000;
    return x;
}


inline double CNC_ROUND_TO_DECIMAL2 (double x)
{
    x = CNC_ROUND_TO_INT(x * 100);
    x /= 100;
    return x;
}

inline double CNC_ROUND_TO_DECIMAL1 (double x)
{
    x = CNC_ROUND_TO_INT(x * 10);
    x /= 10;
    return x;
}


inline int CNC_ROUND_UP(int numToRound, int multiple)
{
    if (multiple == 0)
        return numToRound;

    int remainder = abs(numToRound) % multiple;
    if (remainder == 0)
        return numToRound;

    if (numToRound < 0)
        return -(abs(numToRound) - remainder);
    else
        return numToRound + multiple - remainder;
}

/* general calculation defines */
#ifndef CNC_PI
#define CNC_PI 3.1415926535897932384626433832795029
#endif

#ifndef CNC_PI2
#define CNC_PI2 (CNC_PI/2.0)
#endif

#ifndef CNC_TWO_PI
#define CNC_TWO_PI (CNC_PI * 2.0)
#endif

#ifndef CNC_MM_PER_INCH
#define CNC_MM_PER_INCH 25.4
#endif

#ifndef CNC_INCH_PER_MM
#define CNC_INCH_PER_MM 0.039370078740157477
#endif

#define CNC_MAX(x, y) ((x) > (y) ? (x) : (y))
#define CNC_MAX3(a,b,c) (CNC_MAX(CNC_MAX((a),(b)),(c)))
#define CNC_MAX4(a,b,c,d) (CNC_MAX(CNC_MAX((a),(b)),CNC_MAX((c),(d))))
#define CNC_MAX5(a,b,c,d,e) (CNC_MAX(CNC_MAX3((a),(b),(c)),CNC_MAX((d),(e))))
#define CNC_MAX6(a,b,c,d,e,f) (CNC_MAX(CNC_MAX3((a),(b),(c)),CNC_MAX3((d),(e),(f))))

#define CNC_MIN(x, y) ((x) < (y) ? (x) : (y))
#define CNC_MIN3(a,b,c) (CNC_MIN(CNC_MIN((a),(b)),(c)))
#define CNC_MIN4(a,b,c,d) (CNC_MIN(CNC_MIN((a),(b)),CNC_MIN((c),(d))))
#define CNC_MIN5(a,b,c,d,e) (CNC_MIN(CNC_MIN3((a),(b),(c)),CNC_MIN((d),(e))))
#define CNC_MIN6(a,b,c,d,e,f) (CNC_MIN(CNC_MIN3((a),(b),(c)),CNC_MIN3((d),(e),(f))))


#ifndef CNC_R2D
#define CNC_R2D(r) ((r)*180.0/CNC_PI)
#endif

#ifndef CNC_D2R
#define CNC_D2R(r) ((r)*CNC_PI/180.0)
#endif

#define CNC_X_AXIS 0
#define CNC_Y_AXIS 1
#define CNC_Z_AXIS 2
#define CNC_A_AXIS 3
#define CNC_B_AXIS 4
#define CNC_C_AXIS 5
#define CNC_ALL_AXES 6


#define CNC_X_JOINT 0
#define CNC_Y_JOINT 1
#define CNC_Z_JOINT 2
#define CNC_A_JOINT 3
#define CNC_B_JOINT 4
#define CNC_C_JOINT 5
#define CNC_ALL_JOINTS 6



#define CNC_JOG_STEP_SIZE_0_001     1
#define CNC_JOG_STEP_SIZE_0_01      2
#define CNC_JOG_STEP_SIZE_0_1       3
#define CNC_JOG_STEP_SIZE_0_5       4
#define CNC_JOG_STEP_SIZE_1         5

#define CNC_HANDWHEEL_ON_NONE       -1
#define CNC_HANDWHEEL_ON_X          0  //Equal to CNC_X_AXIS .. CNC_C_AXIS
#define CNC_HANDWHEEL_ON_Y          1
#define CNC_HANDWHEEL_ON_Z          2
#define CNC_HANDWHEEL_ON_A          3
#define CNC_HANDWHEEL_ON_B          4
#define CNC_HANDWHEEL_ON_C          5
#define CNC_HANDWHEEL_ON_ALL        6
#define CNC_HANDWHEEL_ON_FEED       10
#define CNC_HANDWHEEL_ON_SPEED      11

#define CNC_HANDWHEEL_MUL_SEL_01    1
#define CNC_HANDWHEEL_MUL_SEL_1     2
#define CNC_HANDWHEEL_MUL_SEL_10    3
#define CNC_HANDWHEEL_MUL_SEL_100   4

#define CNC_FEEDOV_SEL_000          1
#define CNC_FEEDOV_SEL_001          2
#define CNC_FEEDOV_SEL_002          3
#define CNC_FEEDOV_SEL_005          4
#define CNC_FEEDOV_SEL_010          5
#define CNC_FEEDOV_SEL_030          6
#define CNC_FEEDOV_SEL_060          7
#define CNC_FEEDOV_SEL_100          8


typedef enum CNC_CPU_TYPE
{
    CNC_CPU_TYPE_UNKNOWN = 0,
    CNC_CPU_TYPE_SIM     = 1,


    //PIC8 series
    CNC_CPU_TYPE_123     = 2,

    //ARM 7
    CNC_CPU_TYPE_4       = 3,

    //PIC32MX series
    CNC_CPU_TYPE_5A_USB  = 4,
    CNC_CPU_TYPE_5A_ETH  = 5,
    CNC_CPU_TYPE_5B_USB  = 6,
    CNC_CPU_TYPE_5B_ETH  = 7,
    CNC_CPU_TYPE_I600    = 8,
    CNC_CPU_TYPE_310_USB = 9,
    CNC_CPU_TYPE_310_ETH = 10,

    //PIC32MZ series
    CNC_CPU_TYPE_760     = 11,
    CNC_CPU_TYPE_720     = 12,

    //End indicator
    CNC_CPU_TYPE_LAST
} CNC_CPU_TYPE;

typedef enum CNC_CONSTANTS
{
    CNC_MAX_CUSTOMER_NAME = 32,
    CNC_MAX_JOINTS =  6,
    CNC_MAX_AXES   =  6,
    CNC_MAX_SPINDLES = 6,
    CNC_MAX_NAME_LENGTH = 32,
    CNC_MAX_IO_ERROR_TEXT = 32,
    CNC_MAX_IO_NAME_LENGTH = 16,
    CNC_MAX_PATH = 260,
    CNC_MAX_FNAME_LENGTH = 32,
    CNC_MAX_LOGGING_TEXT = 120,
    CNC_MAX_SOURCE_INFO_TEXT = 30,
    CNC_MAX_FUNCTION_NAME_TEXT = 30,
    CNC_MAX_MESSAGE_TEXT = 150,
    CNC_MAX_VARS = 6000,
    CNC_MAX_TOOLS = 99,
    CNC_MAX_CURRENT_GCODE_TEXT = 60,
    CNC_MAX_CURRENT_MCODE_TEXT = 20,
    CNC_MAX_EXPRESSION_TEXT = 80,
    CNC_MAX_INTERPRETER_LINE = 1055,
    CNC_MAX_TOOL_CHANGES_IN_JOB = 50,
    CNC_POS_FIFO_SIZE = 1000,
    CNC_POS_FIFO_MARGIN = 2,
    CNC_GRAPH_FIFO_SIZE = 100,
    CNC_GRAPH_FIFO_MARGIN  = 2,
    CNC_LOG_FIFO_SIZE = 25,
    CNC_LOG_FIFO_MARGIN = 2,
    CNC_MAX_INTERPRETER_LOOKAHEAD = 500,
    CNC_MAX_VERSION_TEXT = 50,
    CNC_COMMPORT_NAME_LEN = 20,
    CNC_MAX_COMM_PORTS = 50,

    CNC_MAX_CPU_STD_CNC_OUTPUTS = 6,
    CNC_MAX_CPU_AUX_OUTPUTS = 9,

    CNC_MAX_CPU_STD_CNC_INPUTS = 21,
    CNC_MAX_CPU_AUX_INPUTS = 8,

    CNC_MAX_CPU_DIGITAL_OUTPUT_PORTS  = 16,
    CNC_MAX_CPU_ANALOG_OUTPUT_PORTS   = 8,
    CNC_MAX_CPU_DIGITAL_INPUT_PORTS   = 33,
    CNC_MAX_CPU_ANALOG_INPUT_PORTS    = 8,
    CNC_MAX_CPU_DRIVE_INPUT_PORTS     = 2,
    CNC_MAX_CPU_IO_PROBLEM_INPUT_PORTS= 2,
    CNC_MAX_CPU_IO_PORTS =  
        (CNC_MAX_CPU_DIGITAL_OUTPUT_PORTS + 
         CNC_MAX_CPU_ANALOG_OUTPUT_PORTS + 
         CNC_MAX_CPU_DIGITAL_INPUT_PORTS + 
         CNC_MAX_CPU_ANALOG_INPUT_PORTS +
         CNC_MAX_CPU_DRIVE_INPUT_PORTS +
         CNC_MAX_CPU_IO_PROBLEM_INPUT_PORTS
         ), 

    CNC_MAX_GPIOCARD_DIGITAL_OUTPUT_PORTS = 10,
    CNC_MAX_GPIOCARD_ANALOG_OUTPUT_PORTS = 4,
    CNC_MAX_GPIOCARD_DIGITAL_INPUT_PORTS = 10,
    CNC_MAX_GPIOCARD_ANALOG_INPUT_PORTS = 4,

    CNC_MAX_GPIOCARD_PORTS = 
        (CNC_MAX_GPIOCARD_DIGITAL_OUTPUT_PORTS + 
         CNC_MAX_GPIOCARD_ANALOG_OUTPUT_PORTS + 
         CNC_MAX_GPIOCARD_DIGITAL_INPUT_PORTS + 
         CNC_MAX_GPIOCARD_ANALOG_INPUT_PORTS),

    CNC_MAX_GPIOCARD_CARDS = 8,         /* test for pronum */
	CNC_MAX_GPIOCARD_RULES = 16, 

    CNC_MAX_PRECISION_TEXT = 32,
    CNC_TOOL_DIAMETER_INDEX = 5500,		/* First var index of tool diameter    */
    CNC_TOOL_ZOFFSET_INDEX = 5400,		/* First var index of tool z-offset    */
    CNC_TOOL_XOFFSET_INDEX = 5600,		/* First var index of tool x-offset    */
    CNC_TOOL_ORIENTATION_INDEX = 5700,  /* First var index of tool orientation */
    CNC_TOOL_XDELTA_INDEX = 5800,
    CNC_TOOL_ZDELTA_INDEX = 5900,
    CNC_MAX_FREQENCY_TABLE_LEN = 20,
	CNC_MAX_FIDUCIALS = 10,
    CNC_MAX_3D_TEMP_TABLE = 61,
    CNC_MAX_AUX_GUARD_INPUTS = 10,

    CNC_MAX_UIO_INPUTS = 32,           /* number of inputs on UIO board */
    CNC_MAX_UIO_SELECTOR_SWITCHES = 8, /* max number of selector switches */
    CNC_MAX_UIO_SELECTOR_BITS = 16,    /* each max 4 bit, 16 positions    */
    CNC_MAX_UIO_SELECTOR_ACTIONS = 16, /* 2 to the power of CNC_MAX_UIO_SELECTOR_BITS  */
    CNC_MAX_UIO_ANALOG_INPUTS = 4,     /* max number of analog inputs */
    CNC_MAX_UIO_HANDWHEEL_INPUTS = 3,  /* max handwheel inputs */
    CNC_MAX_VACUUMBED_SECTIONS = 64,   /* max sections of vacuum bed */
    CNC_MAX_USER_BUTTONS = 40,         /* maximum number of user buttons on extended dialog */
    CNC_MAX_USER_BUTTON_TEXT_LENGTH = 20 /* maximum length of text description for extended user buttons */
} CNC_CONSTANTS;


typedef enum CNC_RC
{
    CNC_RC_OK            =  0,          /* success */
    CNC_RC_BUF_EMPTY     =  1,          /* buffer empty */
    CNC_RC_TRACE         =  2,          /* trace info */
    CNC_RC_USER_INFO     =  3,          /* User message */
    CNC_RC_SHUTDOWN      =  4,          /* returned by process request after CMD_CLOSE */
    CNC_RC_EXISTING      =  5,          /* if shared memory already exists */
    CNC_RC_ALREADY_RUNS  =  6,          /* if server already running */
    CNC_RC_ALREADY_CONNECTED  =  7,     /* if CncConnectServer() call is already done */
    CNC_RC_ERR           = -1,          /* no data in fifo */
    CNC_RC_ERR_PAR       = -2,          /* wrong parameter or parameter value, see text */
    CNC_RC_ERR_STATE     = -3,          /* wrong state, not allowed, see text */
    CNC_RC_ERR_CONFIG    = -4,          /* wrong config, e.g. axis not present */
    CNC_RC_ERR_INT       = -5,          /* interpreter error, see interpreter error status */
    CNC_RC_ERR_CE        = -6,          /* command envelope error */
    CNC_RC_ERR_EXE       = -7,          /* execution error */
    CNC_RC_ERR_CPU       = -8,          /* CPU error, see sub code, text, restart required */
    CNC_RC_ERR_MOT       = -9,          /* trajectory generator error, see sub code, text */
    CNC_RC_ERR_SYS       = -10,         /* server system error, see text */
    CNC_RC_ERR_TIMEOUT   = -11,         /* general timeout error */
    CNC_RC_EXE_CE        = -12,         /* Error executing command envelope */
    CNC_RC_ERR_FILEOPEN  = -13,         /* file open error */
    CNC_RC_ERR_COLLISION = -14,	        /* collision */
    CNC_RC_ERR_SERVER_NOT_RUNNING = -15,/* trying to connect as monitor, but server not running */
    CNC_RC_ERR_VERSION_MISMATCH = -16,  /* Versions mismatch between SERVER and CNCAPI */
    CNC_RC_ERR_NOT_CONNECTED = -17,     /* CncConnectServer was not called by the CNCAPI */
    CNC_RC_ERR_BUF_FULL = -18,          /* fifo buffer full, message not stored */
    CNC_RC_ERR_2ND_QUEUE_ABORTED = -19  /* user pressed pause while running subroutine in QUEUE mode */
} CNC_RC;

inline char * CNC_AX_ID_TO_NAME(int id)
{
    switch (id)
    {
    case -1: return (char *)"*"; //ALL
    case 0: return (char *)"X";
    case 1: return (char *)"Y";
    case 2: return (char *)"Z";
    case 3: return (char *)"A";
    case 4: return (char *)"B";
    case 5: return (char *)"C";
    case 6: return (char *)"*";  //ALL
    default: return (char *)"?"; //UNKNOWN
    }
}

inline char * CNC_GET_RC_TEXT(CNC_RC rc)
{
	switch (rc)
	{
    case CNC_RC_OK                      : return (char *)"CNC_RC_OK";					     
    case CNC_RC_BUF_EMPTY               : return (char *)"CNC_RC_BUF_EMPTY";			     
    case CNC_RC_TRACE                   : return (char *)"CNC_RC_TRACE";				     
    case CNC_RC_USER_INFO               : return (char *)"CNC_RC_USER_INFO";			     
    case CNC_RC_SHUTDOWN                : return (char *)"CNC_RC_SHUTDOWN";				     
    case CNC_RC_EXISTING                : return (char *)"CNC_RC_EXISTING";				     
    case CNC_RC_ALREADY_RUNS            : return (char *)"CNC_RC_ALREADY_RUNS";			     
    case CNC_RC_ALREADY_CONNECTED       : return (char *)"CNC_RC_ALREADY_CONNECTED";	   
    case CNC_RC_ERR                     : return (char *)"CNC_RC_ERR";					   
    case CNC_RC_ERR_PAR                 : return (char *)"CNC_RC_ERR_PAR";				   
    case CNC_RC_ERR_STATE               : return (char *)"CNC_RC_ERR_STATE";			   
    case CNC_RC_ERR_CONFIG              : return (char *)"CNC_RC_ERR_CONFIG";			   
    case CNC_RC_ERR_INT                 : return (char *)"CNC_RC_ERR_INT";				   
    case CNC_RC_ERR_CE                  : return (char *)"CNC_RC_ERR_CE";				   
    case CNC_RC_ERR_EXE                 : return (char *)"CNC_RC_ERR_EXE";				   
    case CNC_RC_ERR_CPU                 : return (char *)"CNC_RC_ERR_CPU";				   
    case CNC_RC_ERR_MOT                 : return (char *)"CNC_RC_ERR_MOT";				   
    case CNC_RC_ERR_SYS                 : return (char *)"CNC_RC_ERR_SYS";				   
    case CNC_RC_ERR_TIMEOUT             : return (char *)"CNC_RC_ERR_TIMEOUT";			   
    case CNC_RC_EXE_CE                  : return (char *)"CNC_RC_EXE_CE";				   
    case CNC_RC_ERR_FILEOPEN            : return (char *)"CNC_RC_ERR_FILEOPEN";			   
    case CNC_RC_ERR_COLLISION           : return (char *)"CNC_RC_ERR_COLLISION	";	    
    case CNC_RC_ERR_SERVER_NOT_RUNNING  : return (char *)"CNC_RC_ERR_SERVER_NOT_RUNNING";
    case CNC_RC_ERR_VERSION_MISMATCH    : return (char *)"CNC_RC_ERR_VERSION_MISMATCH";
    case CNC_RC_ERR_NOT_CONNECTED       : return (char *)"CNC_RC_ERR_NOT_CONNECTED";
    case CNC_RC_ERR_BUF_FULL            : return (char *)"CNC_RC_ERR_BUF_FULL";         
    case CNC_RC_ERR_2ND_QUEUE_ABORTED   : return (char *)"CNC_RC_ERR_2ND_QUEUE_ABORTED";         
	default:return ((char *) "UNKNOWNRC");
	}
}


typedef enum CNC_ERROR_CLASS
{
    CNC_EC_INFO = 0,   /* Info, no user action                    */
    CNC_EC_DIALOG,     /* For user interaction with part program  */
    CNC_EC_USERACTION, /*  user action required                   */
    CNC_EC_WARNING,    /* Warning eventual user action            */
    CNC_EC_STOP,       /* Stopped on path                         */
    CNC_EC_QSTOP,      /* Stop immediate, path not maintained     */
    CNC_EC_ABORT,      /* Emergency stop                          */
    CNC_EC_BUG,        /* SW bug report to supplier               */
    CNC_EC_FATAL       /* unrecoverable system failure            */

} CNC_ERROR_CLASS;


inline char * CNC_GET_EC_TEXT(CNC_ERROR_CLASS ec)
{
	switch (ec)
	{
	case CNC_EC_INFO       : return (char *)"CNC_EC_INFO";					     
	case CNC_EC_DIALOG     : return (char *)"CNC_EC_DIALOG";			     
	case CNC_EC_USERACTION : return (char *)"CNC_EC_USERACTION";				     
	case CNC_EC_WARNING    : return (char *)"CNC_EC_WARNING";			     
	case CNC_EC_STOP       : return (char *)"CNC_EC_STOP";				     
	case CNC_EC_QSTOP      : return (char *)"CNC_EC_QSTOP";				     
	case CNC_EC_ABORT      : return (char *)"CNC_EC_ABORT";			     
	case CNC_EC_BUG        : return (char *)"CNC_EC_BUG";	   
	case CNC_EC_FATAL      : return (char *)"CNC_EC_FATAL";					   
	default:return((char *)"UNKNOWNEC");
	}
}

typedef enum CNC_PLANE
{
    CNC_PLANE_NONE = 0,
    CNC_PLANE_XY   = 1,
    CNC_PLANE_YZ   = 2,
    CNC_PLANE_XZ   = 3
} CNC_PLANE;

/* spindle control modes */
typedef enum CNC_SPINDLE_SPEED_MODE 
{ 
    CNC_SPINDLESPEEDMODE_CONSTANT_RPM_G97 = 0, 
    CNC_SPINDLESPEEDMODE_CONSTANT_SURFACE_G96 = 1 
} CNC_SPINDLE_SPEED_MODE;


typedef enum CNC_FEED_MODE 
{ 
    CNC_FEEDMODE_UNITS_PER_MINUTE_G94 = 0,
    CNC_FEEDMODE_INVERSE_TIME_G93 = 1,
    CNC_FEEDMODE_UNITS_PER_REVOLUTION_G95 = 2

} CNC_FEED_MODE;


typedef enum CNC_SPINDLE_SYNC_MODE
{
    CNC_SPINDLE_SYNCMODE_PULSE_FEED_RE_MEASURE_RPM = 0,
    CNC_SPINDLE_SYNCMODE_PULSE_FEED_USE_ACTUAL_RPM = 1,
    CNC_SPINDLE_SYNCMODE_USE_PREVIOUS_RPM = 2,
    CNC_SPINDLE_SYNCMODE_USE_SPEED_SETPOINT = 3,
    CNC_SPINDLE_SYNCMODE_FEED_RIDGID  //Not implemented
} CNC_SPINDLE_SYNC_MODE;


typedef struct _CNC_CART_BOOL
{
    int x;
    int y;
    int z;
    int a;
    int b;
    int c;
} CNC_CART_BOOL;

typedef struct _CNC_JOINT_BOOL
{
    int jx;
    int jy;
    int jz;
    int ja;
    int jb;
    int jc;
} CNC_JOINT_BOOL;

typedef struct _CNC_CART_DOUBLE
{
    double x;
    double y;
    double z;
    double a;
    double b;
    double c;
} CNC_CART_DOUBLE;

typedef struct _CNC_VECTOR
{
    double x;
    double y;
    double z;
} CNC_VECTOR;

inline CNC_VECTOR CNC_ZERO_VECTOR(void)
{
    CNC_VECTOR pos;
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = 0.0;
    return pos;
}

inline CNC_VECTOR CNC_VECTOR_INIT(double x, double y, double z)
{
    CNC_VECTOR pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;
    return pos;
}



inline CNC_VECTOR CNC_VECTOR_SUBTRACT(CNC_VECTOR v1, CNC_VECTOR v2)
{
    CNC_VECTOR r;
    r.x = v1.x - v2.x;
    r.y = v1.y - v2.y;
    r.z = v1.z - v2.z;
    return r;
}

inline CNC_VECTOR CNC_VECTOR_ADD(CNC_VECTOR v1, CNC_VECTOR v2)
{
    CNC_VECTOR r;
    r.x = v1.x + v2.x;
    r.y = v1.y + v2.y;
    r.z = v1.z + v2.z;
    return r;
}

inline CNC_VECTOR CNC_VECTOR_CROSS(CNC_VECTOR v1, CNC_VECTOR v2)
{
    CNC_VECTOR r;
    r.x = v1.y * v2.z - v1.z * v2.y;
    r.y = v1.z * v2.x - v1.x * v2.z;
    r.z = v1.x * v2.y - v1.y * v2.x;
    return r;
}

inline CNC_VECTOR CNC_VECTOR_SCALE(double s, CNC_VECTOR v)
{
    CNC_VECTOR r;
    r.x = v.x * s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}


inline int CNC_VECTOR_UNIT(CNC_VECTOR v, CNC_VECTOR * vout)
{
    double size = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));

    if (CNC_DOUBLE_IS_ZERO(size))
    {

        vout->x = 1e99;
        vout->y = 1e99;
        vout->z = 1e99;

        return -1;
    }

    vout->x = v.x / size;
    vout->y = v.y / size;
    vout->z = v.z / size;

    return 0;
}


#define CNC_VECTOR_DOT(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z) // dot product (3D) which allows vector operations in arguments
#define CNC_VECTOR_NORM(v)    sqrt(CNC_VECTOR_DOT(v,v))                       // norm = length of vector
#define CNC_VECTOR_DIST(u,v)  CNC_VECTOR_NORM(CNC_VECTOR_SUBTRACT(u,v))       // distance = norm of difference

#define CNC_VECTOR_MAG(v)   sqrt((v).x * (v).x + (v).y * (v).y + (v).z * (v).z) 




inline int CNC_VECTOR_VECTOR_PROJECT(CNC_VECTOR v1, CNC_VECTOR v2, CNC_VECTOR * vout)
{
    int r1;
    double d;

    r1 = CNC_VECTOR_UNIT(v2, &v2);

    if (r1 != 0) return -1;

    d  = CNC_VECTOR_DOT(v1, v2);
    *vout = CNC_VECTOR_SCALE(d, v2);
    
    return 0;
}


inline int CNC_VECTOR_PLANE_PROJECT(CNC_VECTOR v, CNC_VECTOR normal, CNC_VECTOR * vout)
{
    int r1;
    CNC_VECTOR par;

    r1 = CNC_VECTOR_VECTOR_PROJECT(v, normal, &par);
    *vout = CNC_VECTOR_SUBTRACT(v, par);


    return r1;
}



typedef struct _CNC_JOINT_DOUBLE
{
    double jx, jy, jz, ja, jb, jc;

} CNC_JOINT_DOUBLE;


typedef struct _CNC_ARC
{
    CNC_VECTOR center;
    CNC_VECTOR normal;
    CNC_VECTOR rTan;
    CNC_VECTOR rPerp;
    CNC_VECTOR rHelix;
    double radius;
    double angle;
    double spiral;
} CNC_CIRCLE;



typedef struct _CNC_OFFSET_AND_PLANE
{
    CNC_CART_DOUBLE   g5xOffset;            /* G54 .. G59.3         */
    int               g5xOffsetIndex;       /* G54:0 .. G59.3:8     */
    CNC_CART_DOUBLE   g92Offset;            /* G92                  */
    CNC_CART_DOUBLE   spindleConfigOffset;  /* M90, M91, M92, M93   */
    int               spOffsetIndex;        /* M90:0 .. M93:3       */
    CNC_CART_DOUBLE   totalOffset;          /* Sum of the 3 above   */

    CNC_VECTOR        toolOffset;           /* G43                  */
    int               g43ToolNumber;        /* tool number for G43, can be different from actual tool ! */
    
    //Rotate around Z (C)
    double            XYRotationDegrees;    /* G68                  */
    int               XYRotationActive;     /* G68                  */

    //Rotate around Y (B)
    double            XZRotationDegrees;    /* G68                  */
    int               XZRotationActive;     /* G68                  */

    //Rotate around X (A)
    double            YZRotationDegrees;    /* G68                  */
    int               YZRotationActive;     /* G68                  */



    CNC_VECTOR        RotationBasePoint;    /* G68                  */
	int               XYScalingActive;      /* G51                  */
	CNC_VECTOR        XYScalingFactor;      /* G51                  */

    CNC_PLANE         activePlane;          /* G17, G18, G19        */
    int               currentG5X;           /* active coord syst nr */

} CNC_OFFSET_AND_PLANE;


/* =============================================================================================== */


inline int CNC_GET_CART_BOOL(int axis, CNC_CART_BOOL b)
{
    switch (axis)
    {
    case CNC_X_AXIS : return(b.x); 
    case CNC_Y_AXIS : return(b.y); 
    case CNC_Z_AXIS : return(b.z); 
    case CNC_A_AXIS : return(b.a); 
    case CNC_B_AXIS : return(b.b); 
    case CNC_C_AXIS : return(b.c); 
    default:return(0);
    }
}

inline void CNC_SET_CART_BOOL(int axis, CNC_CART_BOOL *b, int value)
{
    switch (axis)
    {
    case CNC_X_AXIS : b->x = value; break;
    case CNC_Y_AXIS : b->y = value; break;
    case CNC_Z_AXIS : b->z = value; break;
    case CNC_A_AXIS : b->a = value; break;
    case CNC_B_AXIS : b->b = value; break;
    case CNC_C_AXIS : b->c = value; break;
    default:break;
    }
}

inline int CNC_CART_BOOL_IS_EQUAL(CNC_CART_BOOL p1, CNC_CART_BOOL p2)
{
    return (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z && p1.a == p2.a && p1.b == p2.b && p1.c == p2.c);
}


inline CNC_CART_DOUBLE CNC_CART_MINIMUM(CNC_CART_DOUBLE a, CNC_CART_DOUBLE b)
{
    CNC_CART_DOUBLE minimum;

    minimum.x = CNC_MIN(a.x, b.x);
    minimum.y = CNC_MIN(a.y, b.y);
    minimum.z = CNC_MIN(a.z, b.z);
    minimum.a = CNC_MIN(a.a, b.a);
    minimum.b = CNC_MIN(a.b, b.b);
    minimum.c = CNC_MIN(a.c, b.c);

    return minimum;
}


/* =============================================================================================== */

inline int CNC_GET_JOINT_BOOL(int axis, CNC_JOINT_BOOL b)
{
    switch (axis)
    {
    case CNC_X_JOINT : return(b.jx); 
    case CNC_Y_JOINT : return(b.jy); 
    case CNC_Z_JOINT : return(b.jz); 
    case CNC_A_JOINT : return(b.ja); 
    case CNC_B_JOINT : return(b.jb); 
    case CNC_C_JOINT : return(b.jc); 
    default:return(0);
    }
}


inline void CNC_SET_JOINT_BOOL(int axis, CNC_JOINT_BOOL *b, int value)
{
    switch (axis)
    {
    case CNC_X_JOINT : b->jx = value; break;
    case CNC_Y_JOINT : b->jy = value; break;
    case CNC_Z_JOINT : b->jz = value; break;
    case CNC_A_JOINT : b->ja = value; break;
    case CNC_B_JOINT : b->jb = value; break;
    case CNC_C_JOINT : b->jc = value; break;
    default:break;
    }
}

inline int CNC_JOINT_BOOL_IS_EQUAL(CNC_JOINT_BOOL p1, CNC_JOINT_BOOL p2)
{
	return (p1.jx == p2.jx && p1.jy == p2.jy && p1.jz == p2.jz && p1.ja == p2.ja && p1.jb == p2.jb && p1.jc == p2.jc);
}

/* =============================================================================================== */

inline double CNC_GET_CART_DOUBLE(int axis, CNC_CART_DOUBLE pos)
{
    switch (axis)
    {
    case CNC_X_AXIS : return(pos.x); 
    case CNC_Y_AXIS : return(pos.y); 
    case CNC_Z_AXIS : return(pos.z); 
    case CNC_A_AXIS : return(pos.a); 
    case CNC_B_AXIS : return(pos.b); 
    case CNC_C_AXIS : return(pos.c); 
    default:return(0.0);
    }
}

inline void CNC_INIT_CART_DOUBLE(CNC_CART_DOUBLE *pos)
{
    pos->x = 0.0;
    pos->y = 0.0;
    pos->z = 0.0;
    pos->a = 0.0;
    pos->b = 0.0;
    pos->c = 0.0;
}

inline CNC_CART_DOUBLE CNC_ZERO_CART_DOUBLE(void)
{
    CNC_CART_DOUBLE pos;
    pos.x = 0.0;
    pos.y = 0.0;
    pos.z = 0.0;
    pos.a = 0.0;
    pos.b = 0.0;
    pos.c = 0.0;
    return pos;
}

inline void CNC_SET_CART_DOUBLE(int axis, CNC_CART_DOUBLE *pos, double value)
{
    switch (axis)
    {
    case CNC_X_AXIS : pos->x = value; break;
    case CNC_Y_AXIS : pos->y = value; break;
    case CNC_Z_AXIS : pos->z = value; break;
    case CNC_A_AXIS : pos->a = value; break;
    case CNC_B_AXIS : pos->b = value; break;
    case CNC_C_AXIS : pos->c = value; break;
    default:break;
    }
}

inline double CNC_GET_JOINT_DOUBLE(int axis, CNC_JOINT_DOUBLE pos)
{
    switch (axis)
    {
    case CNC_X_JOINT : return(pos.jx); 
    case CNC_Y_JOINT : return(pos.jy); 
    case CNC_Z_JOINT : return(pos.jz); 
    case CNC_A_JOINT : return(pos.ja); 
    case CNC_B_JOINT : return(pos.jb); 
    case CNC_C_JOINT : return(pos.jc); 
    default:return(0.0);
    }
}

inline void CNC_INIT_JOINT_DOUBLE(CNC_JOINT_DOUBLE *pos)
{
    pos->jx = 0.0;
    pos->jy = 0.0;
    pos->jz = 0.0;
    pos->ja = 0.0;
    pos->jb = 0.0;
    pos->jc = 0.0;
}

inline CNC_JOINT_DOUBLE CNC_ZERO_JOINT_DOUBLE(void)
{
    CNC_JOINT_DOUBLE pos;
    pos.jx = 0.0;
    pos.jy = 0.0;
    pos.jz = 0.0;
    pos.ja = 0.0;
    pos.jb = 0.0;
    pos.jc = 0.0;
    return pos;
}


inline void CNC_SET_JOINT_DOUBLE_UNDEFINED(CNC_JOINT_DOUBLE *pos)
{
    pos->jx = 1e99;
    pos->jy = 1e99;
    pos->jz = 1e99;
    pos->ja = 1e99;
    pos->jb = 1e99;
    pos->jc = 1e99;
}

inline void CNC_SET_JOINT_DOUBLE(int axis, CNC_JOINT_DOUBLE *pos, double value)
{
    switch (axis)
    {
    case CNC_X_JOINT : pos->jx = value; break;
    case CNC_Y_JOINT : pos->jy = value; break;
    case CNC_Z_JOINT : pos->jz = value; break;
    case CNC_A_JOINT : pos->ja = value; break;
    case CNC_B_JOINT : pos->jb = value; break;
    case CNC_C_JOINT : pos->jc = value; break;
    default:break;
    }
}


inline CNC_CART_DOUBLE CNC_CART_SUBTRACT(CNC_CART_DOUBLE p1, CNC_CART_DOUBLE p2)
{
    CNC_CART_DOUBLE r;
    r.x = p1.x - p2.x;
    r.y = p1.y - p2.y;
    r.z = p1.z - p2.z;
    r.a = p1.a - p2.a;
    r.b = p1.b - p2.b;
    r.c = p1.c - p2.c;
    return r;
}

inline CNC_CART_DOUBLE CNC_CART_SUBTRACT_VEC_RETURN_CART(CNC_VECTOR p1, CNC_VECTOR p2)
{
    CNC_CART_DOUBLE r;
    r.x = p1.x - p2.x;
    r.y = p1.y - p2.y;
    r.z = p1.z - p2.z;                                   
    r.a = 0.0;
    r.b = 0.0;
    r.c = 0.0;
    return r;
}


inline CNC_CART_DOUBLE CNC_CART_DIFF_ABS(CNC_CART_DOUBLE p1, CNC_CART_DOUBLE p2)
{
    CNC_CART_DOUBLE r;
    r.x = fabs(p1.x - p2.x);
    r.y = fabs(p1.y - p2.y);
    r.z = fabs(p1.z - p2.z);
    r.a = fabs(p1.a - p2.a);
    r.b = fabs(p1.b - p2.b);
    r.c = fabs(p1.c - p2.c);
    return r;
}

inline CNC_CART_DOUBLE CNC_CART_ADD(CNC_CART_DOUBLE p1, CNC_CART_DOUBLE p2)
{
    CNC_CART_DOUBLE r;
    r.x = p1.x + p2.x;
    r.y = p1.y + p2.y;
    r.z = p1.z + p2.z;
    r.a = p1.a + p2.a;
    r.b = p1.b + p2.b;
    r.c = p1.c + p2.c;
    return r;
}


inline CNC_CART_DOUBLE CNC_CART_SCALE(CNC_CART_DOUBLE p, double scale)
{
    CNC_CART_DOUBLE r;
    r.x = scale * p.x;
    r.y = scale * p.y;
    r.z = scale * p.z;
    r.a = scale * p.a;
    r.b = scale * p.b;
    r.c = scale * p.c;
    return r;
}

inline void CNC_CART_SEPARATE_VECTORS(CNC_CART_DOUBLE p, CNC_VECTOR *xyz, CNC_VECTOR *abc)
{
    xyz->x =  p.x;
    xyz->y =  p.y;
    xyz->z =  p.z;
    abc->x =  p.a;
    abc->y =  p.b;
    abc->z =  p.c;
}

inline void CNC_CART_JOIN_VECTORS(CNC_CART_DOUBLE *p, CNC_VECTOR xyz, CNC_VECTOR abc)
{
    p->x = xyz.x ;
    p->y = xyz.y ;
    p->z = xyz.z ;
    p->a = abc.x ;
    p->b = abc.y ;
    p->c = abc.z ;
}




inline double CNC_CART_LIN_LEN(CNC_CART_DOUBLE p)
{
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

inline double CNC_CART_ANG_LEN(CNC_CART_DOUBLE p)
{
    return sqrt(p.a * p.a + p.b * p.b + p.c * p.c);
}


inline int CNC_CART_IS_EQUAL(CNC_CART_DOUBLE *p1, CNC_CART_DOUBLE *p2)
{
	return (CNC_DOUBLES_ARE_EQUAL(p1->x, p2->x) &&
			CNC_DOUBLES_ARE_EQUAL(p1->y, p2->y) &&
			CNC_DOUBLES_ARE_EQUAL(p1->z, p2->z) &&
			CNC_DOUBLES_ARE_EQUAL(p1->a, p2->a) &&
			CNC_DOUBLES_ARE_EQUAL(p1->b, p2->b) &&
			CNC_DOUBLES_ARE_EQUAL(p1->c, p2->c));
}


inline int CNC_CART_XYZ_IS_EQUAL(CNC_CART_DOUBLE *p1, CNC_CART_DOUBLE *p2)
{
    return (CNC_DOUBLES_ARE_EQUAL(p1->x, p2->x) &&
        CNC_DOUBLES_ARE_EQUAL(p1->y, p2->y) &&
        CNC_DOUBLES_ARE_EQUAL(p1->z, p2->z));
}


/* =============================================================================================== */

inline CNC_JOINT_DOUBLE CNC_JOINT_SUBTRACT(CNC_JOINT_DOUBLE p1, CNC_JOINT_DOUBLE p2)
{
    CNC_JOINT_DOUBLE r;
    r.jx = p1.jx - p2.jx;
    r.jy = p1.jy - p2.jy;
    r.jz = p1.jz - p2.jz;
    r.ja = p1.ja - p2.ja;
    r.jb = p1.jb - p2.jb;
    r.jc = p1.jc - p2.jc;
    return r;
}

inline CNC_JOINT_DOUBLE CNC_JOINT_ADD(CNC_JOINT_DOUBLE p1, CNC_JOINT_DOUBLE p2)
{
    CNC_JOINT_DOUBLE r;
    r.jx = p1.jx + p2.jx;
    r.jy = p1.jy + p2.jy;
    r.jz = p1.jz + p2.jz;
    r.ja = p1.ja + p2.ja;
    r.jb = p1.jb + p2.jb;
    r.jc = p1.jc + p2.jc;
    return r;
}

inline CNC_JOINT_DOUBLE CNC_JOINT_SCALE(CNC_JOINT_DOUBLE p, double scale)
{
    CNC_JOINT_DOUBLE r;
    r.jx = scale * p.jx;
    r.jy = scale * p.jy;
    r.jz = scale * p.jz;
    r.ja = scale * p.ja;
    r.jb = scale * p.jb;
    r.jc = scale * p.jc;
    return r;
}

inline double CNC_JOINT_LIN_LEN(CNC_JOINT_DOUBLE p)
{
    return sqrt(p.jx * p.jx + p.jy * p.jy + p.jz * p.jz);
}

inline double CNC_CART_ANG_LEN(CNC_JOINT_DOUBLE p)
{
    return sqrt(p.ja * p.ja + p.jb * p.jb + p.jc * p.jc);
}


inline CNC_CART_DOUBLE CNC_JOINT_TO_CART(CNC_JOINT_DOUBLE pos)
{
    CNC_CART_DOUBLE p;
    p.x = pos.jx;
    p.y = pos.jy;
    p.z = pos.jz;
    p.a = pos.ja;
    p.b = pos.jb;
    p.c = pos.jc;
    return p;
}

inline CNC_JOINT_DOUBLE CNC_CART_TO_JOINT(CNC_CART_DOUBLE pos)
{
    CNC_JOINT_DOUBLE p;
    p.jx = pos.x;
    p.jy = pos.y;
    p.jz = pos.z;
    p.ja = pos.a;
    p.jb = pos.b;
    p.jc = pos.c;
    return p;
}

/* =============================================================================================== */
inline int CNC_VECTOR_IS_EQUAL(CNC_VECTOR *p1, CNC_VECTOR *p2)
{
	return (CNC_DOUBLES_ARE_EQUAL(p1->x, p2->x) &&
			CNC_DOUBLES_ARE_EQUAL(p1->y, p2->y) &&
			CNC_DOUBLES_ARE_EQUAL(p1->z, p2->z));
}

/* =============================================================================================== */
typedef enum CNC_KIN_MOVE_TYPE
{
    CNC_KIN_MOVE_TYPE_NONE = 0,
    CNC_KIN_MOVE_TYPE_PURE_LINEAR = 1,
    CNC_KIN_MOVE_TYPE_PURE_ANGULAR = 2,
    CNC_KIN_MOVE_TYPE_LIN_PLUS_ANG = 3,

} CNC_KIN_MOVE_TYPE;


typedef struct _CNC_KIN_CALC_LIN_VA_DATA
{
    //Input values
    CNC_CART_DOUBLE start;	    //Start pos Cartesian
    CNC_CART_DOUBLE end;		//End pos Cartesian
    double          vRequest;   //Feed from interpreter F value

    CNC_KIN_MOVE_TYPE type;     //Kin movement type
    CNC_CART_DOUBLE   delta;    //delta absolute start - end
    double            deltaXYZ; //Delta XYZ, Pythagoras 
    double            deltaABC; //Delta ABC, Pythagoras


    //For some type of kins, the interpreter offsets are required
    CNC_OFFSET_AND_PLANE offsetAndPlane;

    //Calculated values
    CNC_JOINT_DOUBLE startJoint;//Start pos joint
    CNC_JOINT_DOUBLE endJoint;	//End pos joint
    CNC_JOINT_DOUBLE  jointDelta; 
    

    double			  vMax;		//V max Cartesian possible
    double            vel;      //Velocity Cartesian to be used for motion, limited from vRequest
    double            aMax;		//Acceleration Cartesian
    bool              linearIsLeading;	//True if linear is leading and speed is linear

    //Max velocity time and acceleration times
    double            tvMax, taMax;

} CALC_KIN_LIN_VA_DATA;

/* =============================================================================================== */



//Fool compiler to think a variable is used
#define CNC_UNUSED( ident )  (void) (ident = ident)

//End of alignment definition    
#pragma pack()

#endif //already included
