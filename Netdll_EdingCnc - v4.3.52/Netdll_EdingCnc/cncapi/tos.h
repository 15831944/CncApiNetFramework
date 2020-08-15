//=================================================================
//    _____       _   _                    ____   _   _    ____
//   | ____|   __| | (_)  _ __     __ _   / ___| | \ | |  / ___|
//   |  _|    / _` | | | | '_ \   / _` | | |     |  \| | | |
//   | |___  | (_| | | | | | | | | (_| | | |___  | |\  | | |___
//   |_____|  \__,_| |_| |_| |_|  \__, |  \____| |_| \_|  \____|
//                                |___/
// ================================================================= 


#ifndef TOS_H
#define TOS_H

#ifdef __unix__                   
/**************************************/
/* Linux                              */
/**************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>


#define _snprintf snprintf
#define _vsnprintf vsnprintf
#define _localtime64 localtime
#define _itoa TosItoa
#define _hypot hypot
#define _getcwd getcwd
#define wcslen strlen
#define wcscpy strcpy
#define wcscmp strcmp
#define getchar getchar



#define TOS_MAX_PATH 260

typedef unsigned long  TOS_DWORD;
typedef unsigned long *TOS_DWORD_PTR;


/* use standard char for filenames etc on Linux for unicode */
typedef char TOS_WCHAR_T;
#define TosOpenFile TosOpenFileA
#define TosCreateProcess TosCreateProcessA
#define TosKillProcess TosKillProcessA
#define TosGetFileSize TosGetFileSizeA
#define TosSetConsoleTitle TosSetConsoleTitleA


#elif defined(_WIN32) || defined(WIN32) || defined(_WINDOWS)     
/**************************************/
/* Windows                            */
/**************************************/
#define OS_Windows 1
#include <tchar.h>
#include <stdint.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
#include <direct.h>
#include <locale.h>

#ifdef __GNUC__
#else
    #define getchar _getch
#endif


#ifdef __GNUC__

    #define _localtime64 localtime
    #pragma GCC diagnostic ignored "-Wwrite-strings"
    #pragma GCC diagnostic ignored "-Wliteral-suffix"
    #pragma GCC diagnostic ignored "-Wunused-function"
#endif

#define TOS_MAX_PATH 260

typedef unsigned long  TOS_DWORD;
typedef unsigned long *TOS_DWORD_PTR;

/* use wchar_t on windows for filenames etc */
#define TOS_WIDE_CHAR_FILES 1
typedef wchar_t TOS_WCHAR_T;

#define TosOpenFile TosOpenFileW
#define TosCreateProcess TosCreateProcessA
#define TosKillProcess TosKillProcessA
#define TosGetFileSize TosGetFileSizeW
#define TosSetConsoleTitle TosSetConsoleTitleW
#define TosIsProcessAlreadyStarted TosIsProcessAlreadyStartedA
#define TosFileExists TosFileExistsW

#endif //Windows



////////////////////
//WINDOWS or LINUX
////////////////////

#define TOS_STR_HELPER(x) #x
#define TOS_STR(x) TOS_STR_HELPER(x)
#ifdef __GNUC__
//#pragma message("content of EXP2DF:" TOS_STR(EXP2DF))
#endif

//Fool compiler to think a variable is used
#define TOS_UNUSED( ident )  (void) (ident = ident)

/* general calculation defines */
#ifndef TOS_PI
#define TOS_PI 3.1415926535897932384626433832795029
#endif

#ifndef TOS_PI2
#define TOS_PI2 (TOS_PI/2.0)
#endif

#ifndef TOS_TWO_PI
#define TOS_TWO_PI (TOS_PI * 2.0)
#endif

#ifndef TOS_MM_PER_INCH
#define TOS_MM_PER_INCH 25.4
#endif

#ifndef TOS_INCH_PER_MM
#define TOS_INCH_PER_MM 0.039370078740157477
#endif

#define TOS_MAX(x, y) ((x) > (y) ? (x) : (y))
#define TOS_MAX3(a,b,c) (TOS_MAX(TOS_MAX((a),(b)),(c)))
#define TOS_MAX4(a,b,c,d) (TOS_MAX(TOS_MAX((a),(b)),TOS_MAX((c),(d))))
#define TOS_MAX5(a,b,c,d,e) (TOS_MAX(TOS_MAX3((a),(b),(c)),TOS_MAX((d),(e))))
#define TOS_MAX6(a,b,c,d,e,f) (TOS_MAX(TOS_MAX3((a),(b),(c)),TOS_MAX3((d),(e),(f))))

#define TOS_MIN(x, y) ((x) < (y) ? (x) : (y))
#define TOS_MIN3(a,b,c) (TOS_MIN(TOS_MIN((a),(b)),(c)))
#define TOS_MIN4(a,b,c,d) (TOS_MIN(TOS_MIN((a),(b)),TOS_MIN((c),(d))))
#define TOS_MIN5(a,b,c,d,e) (TOS_MIN(TOS_MIN3((a),(b),(c)),TOS_MIN((d),(e))))
#define TOS_MIN6(a,b,c,d,e,f) (TOS_MIN(TOS_MIN3((a),(b),(c)),TOS_MIN3((d),(e),(f))))


#ifndef TOS_R2D
#define TOS_R2D(r) ((r)*180.0/TOS_PI)
#endif

#ifndef TOS_D2R
#define TOS_D2R(r) ((r)*TOS_PI/180.0)
#endif


#ifndef TOS_EPSILON
#define TOS_EPSILON (0.00001)
#endif

#ifndef TOS_DOUBLES_ARE_EQUAL
#define TOS_DOUBLES_ARE_EQUAL(x,y)  (int)(fabs( (double)((x)-(y)) ) < TOS_EPSILON )
#endif

#ifndef TOS_DOUBLES_ARE_EQUAL_E
#define TOS_DOUBLES_ARE_EQUAL_E(x,y,e)  (int)(fabs( (double)((x)-(y)) ) < e )
#endif

#ifndef TOS_FLOATS_ARE_EQUAL
#define TOS_FLOATS_ARE_EQUAL(x,y)  (int)(fabs( (float)((x)-(y)) ) < TOS_EPSILON )
#endif

#ifndef TOS_FLOATS_ARE_EQUAL_E
#define TOS_FLOATS_ARE_EQUAL_E(x,y,e)  (int)(fabs( (float)((x)-(y)) ) < e )
#endif


#define TOS_MAGIC_NOTUSED_DOUBLE -1.0e10
#define TOS_IS_MAGIC_NOTUSED(x)  (int)(fabs( (double)((x)-(TOS_MAGIC_NOTUSED_DOUBLE)) ) < TOS_EPSILON )

#define TOS_ROUND_TO_INT(a) ((a) > 0) ? (int)((a) + 0.5) : (((a) < 0) ? (int) ((a) - 0.5) : (int)0)


#ifdef __linux__
#pragma GCC diagnostic ignored "-Wunused-function"
#ifdef __cplusplus
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif
#endif


double TOS_ROUND_TO_DECIMAL4 (double x);
double TOS_ROUND_TO_DECIMAL3 (double x);
double TOS_ROUND_TO_DECIMAL2 (double x);
double TOS_ROUND_TO_DECIMAL1 (double x);

#define	TOS_MAX_COMMAND_LINE		260
#define TOS_MAX_ARGUMENTS           20

#define TOS_MAX_CRITICAL_SECTIONS   25
#define TOS_MAX_MUTEXES             100
#define TOS_MAX_EVENTS              100
#define TOS_MAX_THREADS             25
#define TOS_MAX_UDP_SOCKETS         10
#define TOS_IP_ADDRESS_STRING_LEN   25


#define TOS_MAX_SHARED_MEM          100
#define TOS_MAX_MAILBOXES			100
#define TOS_MAX_MAILBOX_MESSAGES	255
#define TOS_MAX_SERIAL_PORTS        20

/* Target os max name length */
#define TOS_MAX_NAME_LENGTH			260
#define TOS_INDEFINITE_WAIT			0xFFFFFFFF
#define TOS_IMMEDIATE_RETURN		0
#define MSEC_PER_TICK				15

 //OxFFFFFFFF is a valid pid in windows!
#define TOS_NO_MEMPTR               0
#define TOS_NO_PROCESSID            (0x0)
#define TOS_USED					1
#define TOS_FREE					0
#define TOS_NOID                    0x1FFFFFFF

#define TOS_MSGBOX_OK 0
#define TOS_MSGBOX_CANCEL 1


typedef signed int          TOS_INT;
typedef signed char         TOS_INT8;
typedef signed short int    TOS_INT16;
typedef signed long int     TOS_INT32;
typedef long long           TOS_INT64;
typedef unsigned int        TOS_UINT;
typedef unsigned char       TOS_UINT8;
typedef unsigned short int  TOS_UINT16;
typedef unsigned long long  TOS_UINT64;

typedef enum _TOS_BOOL { TOS_FALSE = 0, TOS_TRUE } TOS_BOOL;
typedef TOS_BOOL TOS_BOOLEAN;

typedef unsigned int TOS_CRITICAL_SECTION; 
typedef unsigned int TOS_MUTEX_HANDLE;
typedef unsigned int TOS_EVENT_HANDLE;
typedef unsigned int TOS_THREADID;
typedef unsigned int TOS_UDP_CHANNEL;



typedef unsigned long TOS_PROCESSID;


typedef int           TOS_MBXID;

typedef void *        TOS_VOID_PTR;

#ifdef OS_Windows

    typedef TOS_DWORD TOS_THREAD_RET;
    #define TOS_THREAD_CALL __stdcall
    typedef TOS_THREAD_RET (TOS_THREAD_CALL *TOS_TASK_ENTRY)(void * lpThreadParameter);
    typedef int (__stdcall *TOS_FARPROC)();

#else

    typedef void * TOS_THREAD_RET;
    #define TOS_THREAD_CALL
    typedef void * (TOS_THREAD_CALL *TOS_TASK_ENTRY)(void * lpThreadParameter);
    typedef int (*TOS_FARPROC)();

#endif


typedef enum
{
    TOS_THREAD_PRIORITY_BELOW_NORMAL	= 0,
    TOS_THREAD_PRIORITY_NORMAL			= 1,
    TOS_THREAD_PRIORITY_ABOVE_NORMAL	= 2,
    TOS_THREAD_PRIORITY_HIGH			= 3,
    TOS_THREAD_PRIORITY_TIME_CRITICAL   = 4
} TOS_THREAD_PRIORITY;


typedef enum
{
    TOS_NO_ERROR,
    TOS_ALREADY_EXISTING,
    TOS_NOT_EXISTING,
    TOS_NOT_PERMITTED,
    TOS_TIMEOUT,
    TOS_ERROR_INTERRUPT,
    TOS_ERROR,
    TOS_ABANDONED,
    TOS_WRONG_SIZE,
    TOS_NO_MEM,
    TOS_INVALID_NAME,
    TOS_RESOURCE_FINISHED,
    TOS_MBX_FULL,
	TOS_MBX_EMPTY,
	TOS_INVALID_ID,
	TOS_MESSAGE_TOO_LONG,
} TOS_RET;

typedef enum
{
    TOS_PP_IDLE,
    TOS_PP_NORMAL,
    TOS_PP_HIGH,
    TOS_PP_REALTIME
} TOS_PROCESS_PRIORITY;

typedef enum 
{
	TOS_PM_DETACHED,
    TOS_PM_NEW_CONSOLE,
	TOS_PM_NORMAL
} TOS_PROCESS_MODE;


typedef enum 
{
	TOS_LANG_any    		= 0,
	TOS_LANG_Arabic				= 1,/*					1025	Arabic			  */
	TOS_LANG_Basque				= 2,/*					1069	ANSI			  */
	TOS_LANG_Catalan			= 3,/*					1027	ANSI			  */
	TOS_LANG_Chinese_s			= 4,/*	(Simplified)	2052	GB2312			  */
	TOS_LANG_Chinese_t			= 5,/*	(Traditional)	1028	Chinese-Big 5	  */
	TOS_LANG_Czech				= 6,/*					1029	Eastern European  */
	TOS_LANG_Danish				= 7,/*					1030	ANSI			  */
	TOS_LANG_Dutch				= 8,/*					1043	ANSI			  */
	TOS_LANG_English_us			= 9,/*					1033	ANSI			  */
	TOS_LANG_Finnish			= 10,/*					1035	ANSI			  */
	TOS_LANG_French				= 11,/*					1036	ANSI			  */
	TOS_LANG_German				= 12,/*					1031	ANSI			  */
	TOS_LANG_Greek				= 13,/*					1032	Greek			  */
	TOS_LANG_Hebrew				= 14,/*					1037	Hebrew			  */
	TOS_LANG_Hungarian			= 15,/*					1038	Eastern European  */
	TOS_LANG_Italian			= 16,/*					1040	ANSI			  */
	TOS_LANG_Japanese			= 17,/*					1041	Shift-JIS		  */
	TOS_LANG_Korean				= 18,/*					1042	Johab			  */
	TOS_LANG_Norwegian			= 19,/*					1044	ANSI			  */
	TOS_LANG_Polish				= 20,/*					1045	Eastern European  */
	TOS_LANG_Portuguese			= 21,/*					2070	ANSI			  */
	TOS_LANG_Portuguese_Brazil  = 22,/*					1046	ANSI			  */
	TOS_LANG_Russian			= 23,/*					1049	Russian			  */
	TOS_LANG_Slovakian			= 24,/*					1051	Eastern European  */
	TOS_LANG_Slovenian			= 25,/*					1060	Eastern European  */
	TOS_LANG_Spanish			= 26,/*					3082	ANSI			  */
	TOS_LANG_Swedish			= 27,/*					1053	ANSI			  */
	TOS_LANG_Turkish			= 28,/*					1055	Turkish			  */
	TOS_LANG_LAST			    = 30

} TOS_LANG_ID;


//hi res timer
typedef struct _TOS_TIME_STAMP
{
#ifdef OS_Windows
    long long startTime; 
    long long timeStamp;
#else
    /* LINUX */

    //struct timeval startTime;
    //struct timeval timeStamp;

    struct timespec startTime;
    struct timespec timeStamp;
#endif

} TOS_TIME_STAMP;

#ifdef __cplusplus
extern "C" {
#endif

//Translate tos return codes to printable text

char * TosGetErrorText(TOS_RET rc);
char * TosGetLastErrorText(void);

/////////////////
//TosInit should be called before any other Tos functionality
//TosTerm when the process ends
//////////////////
TOS_RET		 TosInit(void);
TOS_RET		 TosTerm(void);
unsigned long TosGetSystemPID(void);

//////////////////
//Critical sections, fast mutex within 1 process
//////////////////
TOS_RET  TosOpenCriticalSection (TOS_CRITICAL_SECTION *handle);
TOS_RET  TosCloseCriticalSection (TOS_CRITICAL_SECTION *handle);
TOS_RET  TosEnterCriticalSection (TOS_CRITICAL_SECTION handle);
TOS_RET  TosLeaveCriticalSection (TOS_CRITICAL_SECTION handle);

/////////////////
//Mutex, use NULL for unnamed, interprocess capability for named MUTEX
/////////////////
TOS_RET		 TosOpenMutex (char *name, TOS_MUTEX_HANDLE *handle);
TOS_RET		 TosCloseMutex (TOS_MUTEX_HANDLE *handle);
TOS_RET      TosRequestMutex (TOS_MUTEX_HANDLE handle,unsigned int timeOut);
TOS_RET		 TosReleaseMutex (TOS_MUTEX_HANDLE handle);

/////////////////
//Events, default not set
/////////////////
TOS_RET		 TosOpenEvent (char *name, TOS_EVENT_HANDLE *handle);
TOS_RET		 TosCloseEvent (TOS_EVENT_HANDLE *handle);
TOS_RET      TosWaitEvent (TOS_EVENT_HANDLE handle, unsigned int timeOut);
TOS_RET		 TosSetEvent (TOS_EVENT_HANDLE handle);
TOS_RET		 TosResetEvent (TOS_EVENT_HANDLE handle);



//Named shared memory
TOS_RET      TosOpenSharedMemory (void **ppvoidSharedMemory, unsigned int size, char *name);
TOS_RET		 TosCloseSharedMemory (void *pvoidSharedMemory);

/////////////////////////////////////
//Mailboxes, inter process capability
//Uses tos shared memory, Tos Mutex and Tos Event
/////////////////////////////////////
TOS_RET      TosOpenMbx (char *pszMbxName, unsigned int ulSize, TOS_MBXID *pMbxId);
TOS_RET		 TosCloseMbx (TOS_MBXID mbxId);
TOS_RET      TosReadMbx (TOS_MBXID mbxId, unsigned int uMaxMsgSize, unsigned int iTimeOutPeriod, char *pszMessage, unsigned int *puActualMsgSize);
TOS_RET      TosWriteMbx (TOS_MBXID mbxId, char *pszMessage, unsigned int uMsgSize);
///////////////////////////
//Thread functionality
//////////////////////////
TOS_RET		         TosCreateThread(TOS_TASK_ENTRY taskEntry, void *taskParameter, TOS_THREADID *handle);
void			     TosSetThreadPriority(TOS_THREADID handle, TOS_THREAD_PRIORITY priority);
TOS_THREAD_PRIORITY	 TosGetThreadPriority(TOS_THREADID handle);
TOS_THREADID         TosGetCurrentThreadID(void);
//This one cleans up the thread ad min in Tos and should be called just before the thread function Ends
void                 TosThreadEnd(void);



////////////////////////
//Process functions
////////////////////////
TOS_PROCESSID TosGetCurrentProcessId (void);
TOS_PROCESSID TosGetProcessIDByName(const char *procName);
TOS_RET		  TosCreateProcessW (wchar_t * vosProcessEntry, wchar_t commandLine[], TOS_PROCESS_MODE mode, TOS_PROCESS_PRIORITY priority, TOS_PROCESSID *pProcessId);
TOS_RET		  TosCreateProcessA (char * vosProcessEntry, char commandLine[], TOS_PROCESS_MODE mode, TOS_PROCESS_PRIORITY priority, TOS_PROCESSID *pProcessId);
TOS_RET		  TosDeleteProcess (TOS_PROCESSID tosProcessId);
void          TosKillProcessW(wchar_t *executableName);
void          TosKillProcessA(char *executableName);
TOS_RET		  TosGetProcessId (TOS_PROCESSID *pProcessId);
TOS_RET       TosWaitProcess (TOS_PROCESSID tosProcessId, unsigned int uTimeOut, int *pExitCode);
TOS_RET		  TosSetProcessPriority (TOS_PROCESSID processId, TOS_PROCESS_PRIORITY priority);
TOS_RET		  TosGetProcessPriority (TOS_PROCESSID processId, TOS_PROCESS_PRIORITY *priority);
int			  TosIsElevatedAdministrator (void *hInputToken); 
TOS_RET       TosIsProcessAlreadyStartedW(wchar_t *executableName);
TOS_RET       TosIsProcessAlreadyStartedA(char *executableName);


//Sleep milliseconds
extern TOS_RET  TosSleep (unsigned int millisecs);

////////////////////////
//Hi res timer functions
////////////////////////
void    TosStartTimer(TOS_TIME_STAMP *pTimeStamp);
double  TosStopTimer(TOS_TIME_STAMP *timeStamp);
double  TosTimerElapse(TOS_TIME_STAMP *timeStamp);
int     TosIsTimerExpired(TOS_TIME_STAMP *timeStamp, double duration, double *pSecondsSinceStart);



////////////////////////////////////////////////
//General Serial port communication (RS232 or USB-CDC)
////////////////////////////////////////////////
//Open serial port
TOS_RET  TosSerialPortOpen( int portNumber, int baudRate, unsigned char dataBits, unsigned char stopBits, char parity );
void     TosSerialPortClose ( int portNumber );
void     TosSerialPortReset(int portNumber);
void     TosSerialPortSetReadTimeout( int portNumber, unsigned int ms );
int      TosSerialPortReadMsg(int portNumber, unsigned char *pData, unsigned int maxLen);
int      TosSerialPortWrite(int portNumber, const unsigned char *pData, unsigned int len); 



/////////////////////////////////////////////////////////////////
// Serial port enumeration, returns a list of available COM ports with EdingCNC ID
/////////////////////////////////////////////////////////////////
#define TOS_MAX_PORT_NAME_SIZE 10
#define TOS_MAX_SERIAL_NUMBER_SIZE 128

typedef struct 
{
    TOS_DWORD Index;
    char PortName[TOS_MAX_PORT_NAME_SIZE];
    char SerialNumber[TOS_MAX_SERIAL_NUMBER_SIZE];
} TOS_SERIAL_PORT_INFO;

//Initialize Serial port enumeration




////////////////////////////////////////////////
//USB-CDC COM port communication dedicated for the Eding CNC CPU
////////////////////////////////////////////////

//Enumeration of COM ports with EdingCNC ID
TOS_RET  TosInitPortEnumeration(void);
int      TosGetSerialPortCount(void);
TOS_RET  TosGetSerialPortInfo(int index,	TOS_SERIAL_PORT_INFO* PortInfo);
void     TosTermPortEnumeration(void);

//Communication with USB COM Port with Eding CNC ID
TOS_RET  TosOpenUSBComPort(char *portName);
void     TosCloseUSBComPort ( void );
TOS_RET  TosUSBCOMRead(char *pData, unsigned int maxBytes, unsigned int *pActualBytes);
TOS_RET  TosUSBCOMWrite(char *pData, unsigned int len); 

////////////////////////////////////////////////
//USB-HID port communication dedicated for the Eding CNC CPU, boot loader
////////////////////////////////////////////////
#define MAX_NUMBER_USB_DEVICES 5


typedef enum
{
    HID_OK = 1,
    HID_OPEN_ERROR_NO_DEVICE_PRESENT = -1,
    HID_OPEN_ERROR_REQUESTED_DEVICE_DOES_NOT_EXIST = -2,
    HID_OPEN_COULD_NOT_GET_HANDLE = -3,
    HID_WRITE_FAILED = -10,
    HID_READ_FAILED = -20,
    HID_CLOSE_FAILED = -30
} TOS_HID_ERROR;

typedef struct TOS_HID_DEVICE
{
    char                    *path;
    struct TOS_HID_DEVICE   *next;
} TOS_HID_DEVICE;

TOS_HID_DEVICE *TosHIDEnumerate(int VID, int PID);
void           TosHIDFreeEnumeration(TOS_HID_DEVICE *enumeration);
TOS_VOID_PTR   TosHIDOpen(char *path);
TOS_VOID_PTR   TosHIDOpen2(int VID, int PID);
TOS_HID_ERROR  TosHIDClose(TOS_VOID_PTR handle);
TOS_HID_ERROR  TosHIDWrite(TOS_VOID_PTR deviceHandle, const unsigned char *data,unsigned int nBytes);
TOS_HID_ERROR  TosHIDRead(TOS_VOID_PTR deviceHandle, unsigned char *data,unsigned int nBytes);
TOS_HID_ERROR  TosHIDXfer(TOS_VOID_PTR deviceHandle, unsigned char *data, unsigned int nBytes);



/////////////////////////////////////////////////////////////////
// UDP Sockets, we call it channel here, because we open a communication
// channel to a remote device. The actual implementation may contain 1 or 2 sockets.
/////////////////////////////////////////////////////////////////
TOS_RET TosOpenUDPChannel (TOS_UDP_CHANNEL *handle, char *ipAddress, unsigned short port, int recvTimeoutMillisec, int broadCast, int doBind);
TOS_RET  TosCloseUDPChannel (TOS_UDP_CHANNEL *handle);
TOS_RET  TosSendUDPMessage(TOS_UDP_CHANNEL handle, char *msg, int msgLen);
TOS_RET  TosReceiveUDPMessage(TOS_UDP_CHANNEL handle, char *msg, int msgMaxLen, int *msgLen);
TOS_RET  TosReceiveUDPMessageTimeout(TOS_UDP_CHANNEL handle, char *msg, int msgMaxLen, int *msgLen, char *ipAddressFrom, int timeOutMillisecs);



///////////////////////
//Get locale of system
///////////////////////
extern int 			 TosGetLocale(void);
extern TOS_LANG_ID   TosGetLanguageID(void);
extern char         *TosGetLanguageText(TOS_LANG_ID id);



///////////////////////
//System dependents, related to directory's and files
///////////////////////
int      TosFileExistsW(wchar_t *path);
int      TosFileExistsA(char *path);
//Get current working directory
void     TosGetWorkingDirectory(char *path, size_t maxLen );
TOS_RET  TosMakeDirectory(char *path);
TOS_RET  TosGetFileSizeW(wchar_t *fileName, long long *fileSize);
TOS_RET  TosGetFileSizeA(char *fileName, long long *fileSize);
void     TosSetConsoleTitleW(wchar_t *title);
void     TosSetConsoleTitleA(char *title);
int      TosMessageBox(char *message, char *tittle);
FILE *   TosOpenFileW(wchar_t *fileName, wchar_t *mode);
FILE *   TosOpenFileA(char *fileName, char *mode);
char *   TosFgets(char *line, size_t size, FILE *fp);
void     TosCloseFile(FILE *fp);

///////////////////////
//System dependents, related to dynamic loading of DLL functions
///////////////////////
TOS_RET      TosLoadLibrary(char *dllName, void **dllHandle);
TOS_FARPROC  TosGetProcAddress (void * hDLL, const char * lpProcName);
void         TosFreeLibrary(void * hDLL);


char* TosItoa(int value, char* str, int radix);
int TosKBHit (void); //Use getchar() to get it

//Clean ./logging and /.backup to max 50 files, delete oldest.
void TosCleanBackupFolders(void);




#ifdef __cplusplus
}
#endif

void TosCleanupResources();


#endif //defined TOS_H

