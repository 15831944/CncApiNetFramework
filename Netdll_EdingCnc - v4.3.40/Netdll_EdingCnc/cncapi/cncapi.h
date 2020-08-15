
//=================================================================
//    _____       _   _                    ____   _   _    ____
//   | ____|   __| | (_)  _ __     __ _   / ___| | \ | |  / ___|
//   |  _|    / _` | | | | '_ \   / _` | | |     |  \| | | |
//   | |___  | (_| | | | | | | | | (_| | | |___  | |\  | | |___
//   |_____|  \__,_| |_| |_| |_|  \__, |  \____| |_| \_|  \____|
//                                |___/
// =================================================================


#ifndef __CNCAPI__H__
#define __CNCAPI__H__

#ifdef EXP2DF
#undef EXP2DF
#endif


#ifdef __unix__
#define EXP2DF
#else
#ifdef CNCAPI_EXPORTS
#define EXP2DF __declspec(dllexport)
#else
#define EXP2DF __declspec(dllimport)
#endif
#endif

#include "cnc_types.h"



#ifdef __cplusplus
extern "C" {
#endif


/*************************************************************************/
/* Get versions ions of CNCAPI.DLL, CNCSERVER.DLL, CncGetHeaderVersion   */
/*************************************************************************/

/*
* Name   : CncGetAPIVersion
* In     : *version, points to a char array of CNC_MAX_NAME_LENGTH long
* Out    : *version, fillesd with version string
* Return : -
* Descr  : Get version string of CNCAPI DLL
*/
void EXP2DF __stdcall CncGetAPIVersion(char *version);

/*
* Name   : CncGetServerVersion
* In     : *version, points to a char array of CNC_MAX_NAME_LENGTH long
* Out    : *version, fillesd with version string
* Return : CNC_RC_OK if server running, otherwise see CNC_RC.. values
* Descr  : Contact is made to the server which sends the version string, if the server is not running
*          this function returns after 1 second.
*/
CNC_RC EXP2DF __stdcall CncGetServerVersion(char *version);

/*
* Name   : CncGetHeaderVersion
* In     : *version, points to a char array of CNC_MAX_NAME_LENGTH long
* Out    : *version, fillesd with version string
* Return : -
* Descr  : Get version string of header, this is simply the contents of macro EDINGCNC_VERSION
*/
inline void CncGetHeaderVersion(char *version)
{
    strncpy(version, EDINGCNC_VERSION, sizeof(EDINGCNC_VERSION));
};

/*
* Name   : CncCheckVersionMatch
* In     : *version, points to a char array of CNC_MAX_NAME_LENGTH long
* Out    : *version, fillesd with version string
* Return : -
* Descr  : Get version string of header, this is simply the contents of macro EDINGCNC_VERSION
*/
inline int CncCheckVersionMatch(void)
{
    char api[CNC_MAX_NAME_LENGTH]    = "";
    char server[CNC_MAX_NAME_LENGTH] = "";
    char header[CNC_MAX_NAME_LENGTH] = "";
    int rc = CNC_RC_OK;

    CncGetHeaderVersion(header);
    CncGetAPIVersion(api);
    rc = CncGetServerVersion(server);

    if (rc == CNC_RC_OK)
    {
        if (strncmp(server, api, CNC_MAX_NAME_LENGTH) != 0 ||
                strncmp(server, header, CNC_MAX_NAME_LENGTH) != 0)
        {
            rc = CNC_RC_ERR_VERSION_MISMATCH;
        }
    }
    return(rc);
}

/*************************************************************************/
/*              Connect/Disconnect with CncServer.exe                    */
/*************************************************************************/

/*
* Name   : CncConnectServer
* In     : iniFileName, only file name
* Out    : -
* Return : See CNC_RC values
* Descr  : Starts CNC server and establish connection with it
*          This is the first command that the GUI should execute.
*/
CNC_RC EXP2DF __stdcall CncConnectServer(char *iniFileName);

/*
* Name   : CncDisConnectServer
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Stops CNC server, to be called when GUI terminates.
*/
CNC_RC EXP2DF __stdcall CncDisConnectServer(void);

/*************************************************************************/
/*                         Get Configuration items                       */
/*************************************************************************/

/*
* Name   : CncGetSetupPassword
* In     : -
* Out    : -
* Return : Setup password (decrypted).
*/
char EXP2DF * __stdcall CncGetSetupPassword(void);

/*
* Name   : CncSetSetupPassword
* In     : *newPassword
* Out    : -
* Return : See CNC_RC values
* Descr  : Set new setup password, store encrypted.
*/
CNC_RC EXP2DF __stdcall CncSetSetupPassword(char *newPassword);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_SYSTEM_CONFIG      EXP2DF * __stdcall CncGetSystemConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_INTERPRETER_CONFIG EXP2DF * __stdcall CncGetInterpreterConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_SAFETY_CONFIG      EXP2DF * __stdcall CncGetSafetyConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_TRAFFIC_LIGHT_CFG  EXP2DF * __stdcall CncGetTrafficLightConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_PROBING_CFG        EXP2DF * __stdcall CncGetProbingConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_IO_CONFIG          EXP2DF * __stdcall CncGetIOConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_I2CGPIO_CARD_CONFIG EXP2DF * __stdcall CncGetGPIOConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : joint
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_JOINT_CFG          EXP2DF * __stdcall CncGetJointConfig(int joint);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : spindle
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_SPINDLE_CONFIG     EXP2DF * __stdcall CncGetSpindleConfig(int spindle);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_FEEDSPEED_CFG      EXP2DF * __stdcall CncGetFeedSpeedConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_HANDWHEEL_CFG      EXP2DF * __stdcall CncGetHandwheelConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_TRAJECTORY_CFG     EXP2DF * __stdcall CncGetTrajectoryConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_KIN_CFG            EXP2DF * __stdcall CncGetKinConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_UI_CFG             EXP2DF * __stdcall CncGetUIConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_CAMERA_CONFIG      EXP2DF * __stdcall CncGetCameraConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_THC_CFG            EXP2DF * __stdcall CncGetTHCConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_SERVICE_CFG        EXP2DF * __stdcall CncGetServiceConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_3DPRINTING_CONFIG  EXP2DF * __stdcall CncGet3DPrintConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_UIO_CONFIG         EXP2DF * __stdcall CncGetUIOConfig(void);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : -
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_VACUUMBED_CONFIG   EXP2DF * __stdcall CncGetVacuumConfig(void);

/*
* Name   : CncGetIOStatus, get access to IO status
* In     : ioID
* Out    : -
* Return : Pointer to io data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_IO_PORT_STS        EXP2DF * __stdcall CncGetIOStatus(CNC_IO_ID ioID);

/*
* Name   : CncGetXxxConfig, get access to all configuration items.
* In     : cardNr
*          ioID
* Out    : -
* Return : Pointer to configuration data
* Descr  : See return type in cnctypes.h for explanation
*          CNC_IO_PORT_STS is configuration as well as status.
*          Data is valid only after CncConnectServer() is called
*/
CNC_GPIO_PORT_STS      EXP2DF * __stdcall CncGetGPIOStatus(int cardNr, CNC_GPIO_ID ioID);

/*
* Name   : CncStoreIniFile
* In     : saveFixtures
* Out    : -
* Return : -
* Descr  : Save all current configuration data to ini file
*          Use CncReInitialize to activate new configuration parameters
*          Save coordinate system info fixtures only when saveFixtures = 1
*
*          Use this function after updating the configuration, it saves
*          modified values in the cnc.ini file.
*/
CNC_RC EXP2DF __stdcall CncStoreIniFile(int saveFixtures);

/*
* Name   : CncReInitialize
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Reinitialize, CNCSERVER after modified ini file
*/
CNC_RC EXP2DF __stdcall CncReInitialize(void);


/*
 * Name   : GetMacroFileName
 * In     : -
 * Out    : *name macro file name including path
 *          the name without path in  inside the cnc.ini file
 * Return : See CNC_RC values
 * Descr  : Get path of macro file for GUI.
 */
CNC_RC EXP2DF __stdcall CncGetMacroFileName(char *name);

/*
 * Name   : GetMacroFileName
 * In     : -
 * Out    : *name macro file name including path
 *          the name without path in  inside the cnc.ini file
 * Return : See CNC_RC values
 * Descr  : Get path of macro file for GUI.
 */
CNC_RC EXP2DF __stdcall CncGetUserMacroFileName(char *name);

/*
 * Name   : CncSetMacroFileName
 * In     : *name macrofile name, full path.
 *
 * Out    : -
 *
 * Return : See CNC_RC values
 * Descr  : set macro file name in configuration.
 *          ini file must be saved to activate this.
 */
CNC_RC EXP2DF __stdcall CncSetMacroFileName(char *name);

/*
 * Name   : CncSetMacroFileName
 * In     : *name macrofile name, full path.
 *
 * Out    : -
 *
 * Return : See CNC_RC values
 * Descr  : set macro file name in configuration.
 *          ini file must be saved to activate this.
 */
CNC_RC EXP2DF __stdcall CncSetUserMacroFileName(char *name);

/*************************************************************************/
/*               Configuration/Status items often used.                  */
/*         derived from configuration/status structures above            */
/*                        controller-cpu related                         */
/*************************************************************************/

/*
 * Name   : CncGetControllerFirmwareVersion
 * In     : char pointer to array of CNC_MAX_NAME_LENGTH size
 * Out    : the PIC firmware version string
 * Return : -
 */
char EXP2DF * __stdcall CncGetControllerFirmwareVersion(void);

/*
 * Name   : CncGetSerialNumber
 * In     :
 * Out    : serial 6 Bytes, which are the serial number of the CPU5 series
 *          caller must allocate the 6 byte array.
 * Return : -
 */
CNC_RC EXP2DF __stdcall CncGetControllerSerialNumber(unsigned char *serial);

/*
 * Name   : CncGetControllerNumberOfFrequencyItems
 * In     : -
 * Out    : -
 * Return : Get number of possible frequencies
 * Descr  :
 */
int EXP2DF __stdcall CncGetControllerNumberOfFrequencyItems(void);

/*
* Name   : CncGetControllerFrequencyItem
* In     : index
* Out    : -
* Return : Get a frequency given index =
*          0 .. CncGetControllerNumberOfFrequencyItems() - 1
* Descr  :
*/
double EXP2DF __stdcall CncGetControllerFrequencyItem(unsigned int index);

/*
* Name   : CncGetControllerConnectionNumberOfItems
* In     : -
* Out    : the port connection string e.g. COM1
* Return : Number of controller connection items
*/
int EXP2DF __stdcall CncGetControllerConnectionNumberOfItems(void);

/*
* Name   : CncGetControllerConnectionItem
* In     : itemNumber
* Out    : -
* Return : the port connection string e.g. "COM1"
*/
char EXP2DF * __stdcall CncGetControllerConnectionItem(int itemNumber);

/*
* Name   : CncGetNrOfAxesOnController
* In     : -
* Out    : *maxNrOfAxes
           *availableNrOfAxes
* Return : Number of axes on CPU and number of available axes
*          number of available axes may be less due to option's
*/
void EXP2DF __stdcall CncGetNrOfAxesOnController(int *maxNrOfAxes, int *availableNrOfAxes);

/*
* Name   : CncGetAxisIsConfigured
* In     : axis CNC_X_AXIS .. CNC_C_AXIS,
*          includingSlaves if a axis is configured because of slave
* Out    : -
* Return : 1 if axis configured
*/
int EXP2DF __stdcall CncGetAxisIsConfigured(int axis, bool includingSlaves);

/*
 * Name   : CncGetFirmwareHasOptions
 * In     : -
 * Out    : -
 * Return : 0=no options, 1=options available
 * Descr  : Check to see if option dialog in GUI is needed.
*/
int EXP2DF __stdcall CncGetFirmwareHasOptions(void);

/*
* Name   : CncGetActiveOptions
* In     : -
* Out    : *actCustomerName,
*          *actNumberOfAxes,
*          *actGPIOAVXEnabled,
*          *actGPIOEDIEnabled,
*          *actPLASMAEnabled,
*          *actTURMACROEnabled,
*          *actXHCPendant,
*          *actLimitedSoftwareEnabled,
* Return : See CNC_RC values
* Descr  : Get active software options, currently only number of axes for CPU5B
*/
CNC_RC EXP2DF __stdcall CncGetActiveOptions(char			*actCustomerName,
        int			*actNumberOfAxes,
        unsigned int	*actCPUEnabled,
        unsigned int	*actGPIOAVXEnabled,
        unsigned int	*actGPIOEDIEnabled,
        unsigned int	*actWolfcutCameraEnabled,
        unsigned int	*actTURNMACRO,
        unsigned int	*actXHCPendant,
        unsigned int	*actLimitedSoftwareEnabled);

/*
* Name   : CncActivateOption
* In     : *newCustomerName,
*          newNumberOfAxes,
*          newGPIOAVXEnabled,
*          newGPIOEDIEnabled,
*          newPLASMAEnabled,
*          newTURMACROEnabled,
*          newXHCPendant,
*          newLimitedSoftwareEnabled,
*          requestCode
* Out    : requestCode, send this to supplier to get activation code. make the string 256 bytes long
* Return : See CNC_RC values
* Descr  : Get request code for new options.
*          Request code is send to Eding CNC.
*          Eding CNC will send back an Activation Code.
*/
CNC_RC EXP2DF __stdcall CncGetOptionRequestCode( char          *newCustomerName,
        int           newNumberOfAxes,
        unsigned int	newGPIOAVXEnabled,
        unsigned int	newGPIOEDIEnabled,
        unsigned int	newPLASMAEnabled,
        unsigned int	newTURMACROEnabled,
        unsigned int	newXHCPendant,
        unsigned int	newLimitedSoftwareEnabled,
        char          *requestCode );

/*
* Name   : CncGetOptionRequestCodeCurrent
* In     : -
* Out    : *requestCode
* Return : See CNC_RC values
* Descr  : This one gives the request code for no extra options, its for internal use only.
*           the returned string can be 256 bytes long max
*/
CNC_RC EXP2DF __stdcall CncGetOptionRequestCodeCurrent(char *requestCode);

/*
* Name   : CncActivateOption
* In     : *activationKey, retrieved from Eding CNC after payment
* Out    : -
* Return : See CNC_RC values
* Descr  : Get active software options, currently only number of axes for CPU5B
*/
CNC_RC EXP2DF __stdcall CncActivateOption(char *activationKey);

/*
 * Name   : CncGetJointStatus
 * In     : joint
 * Out    : -
 * Return : Actual joint status of given joint
 */
CNC_JOINT_STS EXP2DF * __stdcall CncGetJointStatus(int joint);

/*************************************************************************/
/*                         Get/Set Tool table data                       */
/*************************************************************************/
/*
* Name   : CncGetToolData
* In     : index
* Out    : -
* Return : Pointer to tool data
*/
CNC_TOOL_DATA EXP2DF __stdcall CncGetToolData(int index);

/*
* Name   : CncUpdateToolData
* In     : *pTool
*          index
* Out    : -
* Return : Modify tool data
*          Data is made persistent when ini file is saved
*/
CNC_RC EXP2DF __stdcall CncUpdateToolData(CNC_TOOL_DATA *pTool, int index);

/*
* Name   : CncLoadToolTable
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : After this call the new tool data is used by the interpreter
*/
CNC_RC EXP2DF __stdcall CncLoadToolTable(void);

/*************************************************************************/
/*                         Variable access                               */
/*************************************************************************/

/*
* Name   : CncGetVariable
* In     : varIndex
* Out    : -
* Return : Get # variables [1..5399]
*/
double EXP2DF __stdcall CncGetVariable(int varIndex);

/*
* Name   : CncSetVariable
* In     : varIndex
*        : value
* Out    : -
* Return : Get # variables [1..5399]
*/
void EXP2DF __stdcall CncSetVariable(int varIndex, double value);

/*************************************************************************/
/*                            Status items                               */
/*************************************************************************/

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_RUNNING_STATUS           EXP2DF * __stdcall CncGetRunningStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_MOTION_STATUS            EXP2DF * __stdcall CncGetMotionStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_CONTROLLER_STATUS        EXP2DF * __stdcall CncGetControllerStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_CONTROLLER_CONFIG_STATUS EXP2DF * __stdcall CncGetControllerConfigStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_TRAFFIC_LIGHT_STATUS     EXP2DF * __stdcall CncGetTrafficLightStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_JOB_STATUS               EXP2DF * __stdcall CncGetJobStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_TRACKING_STATUS          EXP2DF * __stdcall CncGetTrackingStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_THC_STATUS               EXP2DF * __stdcall CncGetTHCStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_NESTING_STATUS           EXP2DF * __stdcall CncGetNestingStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_KIN_STATUS               EXP2DF * __stdcall CncGetKinStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_SPINDLE_STS              EXP2DF * __stdcall CncGetSpindleStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_PAUSE_STS                EXP2DF * __stdcall CncGetPauseStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_SEARCH_STATUS            EXP2DF * __stdcall CncGetSearchStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_3DPRINTING_STS           EXP2DF * __stdcall CncGet3DPrintStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_COMPENSATION_STATUS      EXP2DF * __stdcall CncGetCompensationStatus(void);

/*
* Name   : CncGetXxxStatus, get access to all status items
* In     : -
* Out    : -
* Return : Pointer to status data
* Descr  : See return type in cnctypes.h for explanation
*          Data is valid only after CncConnectServer() is called
*/
CNC_VACUUM_STATUS            EXP2DF * __stdcall CncGetVacuumStatus(void);

/*
* Name   : CncGet10msHeartBeat
* In     : -
* Out    : -
* Return : Counter that is incremented every 10ms when server is initialized and running normally.
* Descr  : If this counter has stopped, the server is no longer running as it should.
*/
int EXP2DF __stdcall CncGet10msHeartBeat(void);

/*
 * Name   : CncIsServerConnected
 * In     : -
 * Out    : -
 * Return : 1 if connection with CNCSERVER established
 *          Only if this one is
 */
int EXP2DF __stdcall CncIsServerConnected(void);

/*************************************************************************/
/*    Status items often used derived from status structures above       */
/*                        position related                               */
/*************************************************************************/

/*
 * Name   : CncGetState
 * In     : -
 * Out    : -
 * Return : Get state of CncServer
 *          See CNC_IE_STATE for state descriptions
 */
CNC_IE_STATE EXP2DF __stdcall CncGetState(void);
/*
* Name   : CncGetState
* In     : state
* Out    : -
* Return : Get state of CncServer
*          See CNC_IE_STATE for state descriptions
*/
char EXP2DF * __stdcall CncGetStateText(CNC_IE_STATE state);


/*
* Name   : CncInMillimeterMode
* In     : -
* Out    : -
* Return : 1 if millimeter mode (G21), 0 if not (G20)
* Descr  : Work positions must be commanded in INCHES if active
*/
int EXP2DF __stdcall CncInMillimeterMode(void);

/*
* Name   : CncGetActualPlane
* In     : -
* Out    : -
* Return : Current plane selection
* Descr  :
*/
CNC_PLANE EXP2DF __stdcall CncGetActualPlane(void);

/*
* Name   : CncGetWorkPos
* In     : void or axis id (X=0, Y=1, .. C=5)
* Out    :
* Return : Actual Cartesian work/interpreter
*          This is the "WORK" position in millimeters/degrees
*/
CNC_CART_DOUBLE EXP2DF __stdcall CncGetWorkPosition(void);

/*
 * Name   : CncGetJointPosition
 * In     : joint index
 * Out    :
 * Return : Actual joint (motor) positions in millimeters/degrees
 */
CNC_JOINT_DOUBLE EXP2DF __stdcall CncGetMotorPosition(void);

/*
 * Name   : CncGetMachinePos
 * In     :
 * Out    :
 * Return : Actual Cartesian machine position in millimeters/degrees
 */
CNC_CART_DOUBLE EXP2DF __stdcall CncGetMachinePosition(void);

/*
* Name   : CncGetMachineZeroWorkPoint
* In     :
* Out    : *pos - Actual work zero point machine coordinates in millimeters/degrees
*          *rotationActive including tool X and tool Z offset.
* Return : -
*/
void EXP2DF __stdcall CncGetMachineZeroWorkPoint(CNC_CART_DOUBLE *pos, int *rotationActive);

/*
* Name   : CncGetActualOriginOffset
* In     : -
* Out    : -
*
* Return : Actual offset excluding ToolZ and ToolX offset in millimeters
*/
CNC_CART_DOUBLE EXP2DF __stdcall CncGetActualOriginOffset(void);

/*
* Name   : CncGetActualToolZOffset
* In     : -
* Out    : -
* Return : Actual tool Z offset
*/
double EXP2DF __stdcall CncGetActualToolZOffset(void);

/*
* Name   : CncGetActualToolXOffset
* In     : -
* Out    : -
* Return : Actual tool X offset
*/
double EXP2DF __stdcall CncGetActualToolXOffset(void);

/*
* Name   : CncGetActualG68Rotation
* In     : -
* Out    : -
* Return : Actual G68 rotation
*/
double EXP2DF __stdcall CncGetActualG68Rotation(void);

/*
* Name   : CncGetActualG68RotationPlane
* In     : -
* Out    : -
* Return : Actual G68 rotation plane
*/
CNC_PLANE EXP2DF __stdcall CncGetActualG68RotationPlane(void);

/*************************************************************************/
/*    Status items often used derived from status structures above       */
/*                        interpreter related                            */
/*************************************************************************/

/*
 * Name   : CncGetCurrentGcodesText
 * In     : User supplied character buffer of 80 char size
 * Out    : *activeGCodes Buffer filled with actual GCode set
 * Return : -
 */
void EXP2DF __stdcall CncGetCurrentGcodesText(char *activeGCodes);

/*
* Name   : CncGetCurrentMcodesText
* In     : User supplied character buffer of 80 char size
* Out    : *activeMCodes Buffer filled with actual GCode set in text format
* Return : -
*/
void EXP2DF __stdcall CncGetCurrentMcodesText(char *activeMCodes);

/*
 * Name   : CncGetCurrentGcodeSettings (Feed Speed Tool)
 * In     : User supplied char buffer of 80 chars size
 * Out    : *actualGCodeSettings Current setting in text format
 * Return : -
 */
void EXP2DF __stdcall CncGetCurrentGcodeSettingsText(char *actualGCodeSettings);

/*
 * Name   : CncGetProgrammedSpeed
 * In     : -
 * Out    : -
 * Return : Programmed S value
 */
double EXP2DF __stdcall CncGetProgrammedSpeed(void);

/*
 * Name   : CncGetProgrammedFeed
 * In     : -
 * Out    : -
 * Return : Programmed F value
 */
double EXP2DF __stdcall CncGetProgrammedFeed(void);

/*
* Name   : CncGetCurrentToolNumber
* In     : -
* Out    : -
* Return : Current Tool in spindle
*/
int EXP2DF __stdcall CncGetCurrentToolNumber(void);

/*
 * Name   : CncG43Active
 * In     : -
 * Out    : -
 * Return : 1 if toollength compensation is active, 0 if not
*/
int EXP2DF __stdcall CncG43Active(void);

/*
 * Name   : CncGetCurInterpreterLineNumber
 * In     : -
 * Out    : -
 * Return : Current interpreter line number
*/
int EXP2DF __stdcall  CncGetCurInterpreterLineNumber(void);

/*
* Name   : CncGetCurInterpreterLineText
* In     : *text Pointer to callers character array with length CNC_MAX_INTERPRETER_LINE
* Out    : *text
* Return : 0
*/
int EXP2DF __stdcall CncGetCurInterpreterLineText( char * text);

/*
* Name   : CncCurrentInterpreterLineContainsToolChange
* In     : -
* Out    : -
* Return : 1 if the line contains M6T.. , 0 Otherwise.
*/
int EXP2DF __stdcall CncCurrentInterpreterLineContainsToolChange(void);

/*************************************************************************/
/*    Status items often used derived from status structures above       */
/*                        error / safety related                         */
/*************************************************************************/

/*
 * Name   : CncGetSwLimitError
 * In     : -
 * Out    : -
 * Return : 1 if there is a software limit error
 */
int EXP2DF __stdcall CncGetSwLimitError(void);

/*
 * Name   : CncGetFifoError
 * In     : -
 * Out    : -
 * Return : 1 if there is a fifo underflow
 */
int EXP2DF __stdcall CncGetFifoError(void);

/*
* Name   : CncGetEMStopActive
* In     : -
* Out    : -
* Return : 1 if there is emergency stop was triggered
*/
int EXP2DF __stdcall CncGetEMStopActive(void);

/*
 * Name   : CncGetAllAxesHomed
 * In     : -
 * Out    : -
 * Return : 1 if all axes are homed, 0 if not
 * Descr  : Check if all axes are homed.
 */
int  EXP2DF __stdcall CncGetAllAxesHomed(void);

/*
 * Name   : CncGetSafetyMode
 * In     : -
 * Out    : -
 * Return : 1 if all not all axes homed or safety input = 1
 * Descr  : If this returns 1 GUI will decide to use slow speed.
 */
int  EXP2DF __stdcall CncGetSafetyMode(void);

/*************************************************************************/
/*                              Kinematics                               */
/*************************************************************************/

/*
* Name   : CncKinGetActiveType
* In     : -
* Out    : -
* Return : Kinematics type if kinematics is active, Trivial if not active.
* Descr  : -
*/
CNC_KINEMATICS_TYPE EXP2DF __stdcall CncKinGetActiveType(void);

/*
 * Name   : CncKinActivate
 * In     : active
 * Out    : -
 * Return : CNC_RC_OK | CNC_RC _ERR
 * Descr  :
 */
int EXP2DF __stdcall CncKinActivate(int active);

/*
* Name   : CncInitialiseKinematics
* In     : -
* Out    : -
* Return : Re initialize kinematics at run-time, needed when kinematics parameters have changed,
*          such as the Radius and Rotation Point of the A-Axis.
* Descr  : -
*/
int EXP2DF __stdcall CncKinInit(void);

/*
* Name   : CncKinControl
* In     : *controlID,
* Out    : *pControlData
* Return : CNC_RC_OK | CNC_RC_ERR
* Descr  : Send/receive control data to kinematics.
*/
int EXP2DF __stdcall CncKinControl(KIN_CONTROL_ID controlID, KIN_CONTROLDATA *pControlData);

/*
* Name   : CncKinGetARotationPoint
* In     : -
* Out    : -
* Return : Rotation point (Y,Z) for A axis
* Descr  : -
*/
CNC_VECTOR EXP2DF __stdcall CncKinGetARotationPoint(void);




/*************************************************************************/
/*    Status items often used derived from status structures above       */
/*                             IO related                                */
/*************************************************************************/

/*
* Name   : CncGetIOName
* In     : id
* Out    : -
* Return : The name of the IO, can be user text
* Descr  : e.g. CncHetIOName(CNC_IOID_TOOL_OUT) will return "TOOL OUT"
*               CncGetIOName(CNC_IOID_AUX1_OUT) will return the name defined by the user  in the cnc.ini file.
*/
char EXP2DF * __stdcall CncGetIOName(CNC_IO_ID id);

/*
 * Name   : CncGetOutput
 * In     : id
 * Out    : -
 * Return : The actual value of an output
 * Descr  :
 */
int EXP2DF __stdcall CncGetOutput(CNC_IO_ID id);
/*
 * Name   : CncGetOutputRaw
 * In     : id
 * Out    : -
 * Return : The actual value of an output
 * Descr  :
 */
int EXP2DF __stdcall CncGetOutputRaw(CNC_IO_ID id);
/*
 * Name   : CncGetGPIOOutput
 * In     : gpioCardIndex
 *          ioId
 * Out    : -
 * Return : The actual value of an output
 * Descr  :
 */
int EXP2DF __stdcall CncGetGPIOOutput(int gpioCardIndex, CNC_GPIO_ID ioId);

/*
* Name   : CncGetInput
* In     : id
* Out    : -
* Return : The actual value of an input logic or Raw
* Descr  : Logic takes inversion into account, Raw gives the value from the CPU directly.
*/
int EXP2DF __stdcall CncGetInput(CNC_IO_ID id);

/*
* Name   : CncGetInputRaw
* In     : id
* Out    : -
* Return : The actual value of an input logic or Raw
* Descr  : Logic takes inversion into account, Raw gives the value from the CPU directly.
*/
int EXP2DF __stdcall CncGetInputRaw(CNC_IO_ID id);

/*
* Name   : CncGetGPIOInput
* In     : gpioCardIndex
*          ioId
* Out    : -
* Return : The actual value of an input logic or Raw
* Descr  : Logic takes inversion into account, Raw gives the value from the CPU directly.
*/
int EXP2DF __stdcall CncGetGPIOInput(int gpioCardIndex, CNC_GPIO_ID ioId);

/*
 * Name   : CncSetOutput
 * In     : id
 *        : value
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Set an output to value
 */
CNC_RC EXP2DF __stdcall CncSetOutput(CNC_IO_ID id, int value);

/*
 * Name   : CncSetOutputRaw
 * In     : id
 *        : value
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Set an output to value
 */
CNC_RC EXP2DF __stdcall CncSetOutputRaw(CNC_IO_ID id, int value);

/*
* Name   : CncSetGPIOOutput
* In     : gpioCardIndex
*        : ioId
*        : value
* Out    : -
* Return : See CNC_RC values
* Descr  : Set an output to value
*/
CNC_RC EXP2DF __stdcall CncSetGPIOOutput(int gpioCardIndex, CNC_GPIO_ID ioId, int value);

/*
* Name   : CncCheckStartConditionOK
* In     : generateMessage, if 1 a message is generated by the server.
*          ignoreHoming = 1 if the command that you test for is homing, 0 otherwise.
* Out    : *result, if 1, start is allowed, if 0 start is not allowed.
* Return : See CNC_RC values
* Descr  : Set an output to value
*/
CNC_RC EXP2DF __stdcall CncCheckStartConditionOK(int generateMessage, int ignoreHoming, int *result);

/*
 * Name   : CncSetSpindleOutput
 * In     : onOff and direction Value,
 *          direction can be 0 or 1, of value -1 it is ignored.
 *          absSpeed
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Set SpindleSpeed
*/
CNC_RC EXP2DF __stdcall CncSetSpindleOutput(int onOff, int direction, double absSpeed);

/*************************************************************************/
/*    Log messages, Real-time graphics data and Render graphics data     */
/*    These use a fifo, that the UI must repetitively read until empty   */
/*                                                                       */
/*************************************************************************/

/*
 * Name   : CncLogFifoGet
 * In     : -
 * Out    : *data
 * Return : CNC_RC_OK or CNC_RC_BUF_EMPTY
 * Descr  : Get log message from fifo, be sure to check this continuously
 *          and display the message to the operator of the machine.
 */
CNC_RC EXP2DF __stdcall CncLogFifoGet(CNC_LOG_MESSAGE *data);

/*
 * Name   : CncPosFifoGet
 * In     : -
 * Out    : *data
 * Return : CNC_RC_OK or CNC_RC_BUF_EMPTY
 * Descr  : Get real-time position info for viewing the real-time graph.
 *          this consists of new values for x,y,z,a
 *          Graphics draws a line to the new point.
 *          If a is rotation axis, rotate y/z plane with angle a.
 *          x remains the same.
 *
 */
CNC_RC EXP2DF __stdcall CncPosFifoGet(CNC_POS_FIFO_DATA *data);

/*
 * Name   : CncPosFifoGet2
 * In     : -
 * Out    : *data
 *          *isLast
 * Return : CNC_RC_OK or CNC_RC_BUF_EMPTY
 * Descr  : Get real-time position info for viewing the real-time graph.
 *          this consists of new values for x,y,z,a
 *          Graphics draws a line to the new point.
 *          If a is rotation axis, rotate y/z plane with angle a.
 *          x remains the same.
 *
 */
CNC_RC EXP2DF __stdcall CncPosFifoGet2(CNC_POS_FIFO_DATA *data, int *isLast);

/*
 * Name   : CncGraphFifoGet
 * In     : -
 * Out    : *data
 * Return : CNC_RC_OK or CNC_RC_BUF_EMPTY
 * Descr  : Get graph data info from rendering current job
 *          trough interpreter without actually execution.
 *          For showing /checking current job file
 */
CNC_RC EXP2DF __stdcall CncGraphFifoGet(CNC_GRAPH_FIFO_DATA *data);

/*************************************************************************/
/*              Commands, Job and Interpreter Related                    */
/*                                                                       */
/*************************************************************************/

/*
* Name   : CncReset
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Recover from errors, use this when there is an error
*
*/
CNC_RC EXP2DF __stdcall CncReset(void);

/*
* Name   : CncReset2
* In     : resetFlags (0: normal reset, 0x1: Call "userreset" from macro.cnc after normal reset
* Out    : -
* Return : See CNC_RC values
* Descr  : Recover from errors, use this when there is an error
*
*/
CNC_RC EXP2DF __stdcall CncReset2(unsigned int resetFlags);

/*
 * Name   : CncRunSingleLine
 * In     : *text
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Start single line of interpreter text for MDI mode
 *
 *          See also wait function below.
 */
CNC_RC EXP2DF __stdcall CncRunSingleLine(const char *text);

/**************************************************************************/
/* Some functions here have while loops to wait e.g. for motion to be     */
/* completed. This may block you GUI.                                     */
/* To keep the GUI alive a function pointer of type below can be given    */
/* If not NULL, the user supplied function is called during the while loop*/
/* Use may call a UI functions such as QApplication::ProcessEvents() to   */
/* keep the UI alive                                                      */
/* if the function returns something else than zero, the while loop is    */
/* ended, so the UI application may control unwanted hangups here         */
/* an additional void parameter may be given                              */
/**************************************************************************/
typedef int (*CNC_KEEP_UI_ALIVE_FUNCTION)(void * pParameter);

/*
* Name   : CncWaitSingleLine
* In     : pKeepAlive
*          pKeepAliveParameter
* Out    : -
* Return : Return value of user call back function or -1 if internal error.
* Descr  : Wait until CncRunSingleLine is done using supplied callback function pointer
*/
int    EXP2DF __stdcall CncWaitSingleLine(CNC_KEEP_UI_ALIVE_FUNCTION pKeepAlive, void *pKeepAliveParameter);

/*
* Name   : CncLoadJobW
* In     : fileName
* Out    : -
* Return : See CNC_RC values
* Descr  : Load a job file
*/
CNC_RC EXP2DF __stdcall CncLoadJobW(const wchar_t *fileName); //Windows unicode
/*
* Name   : CncLoadJobA
* In     : fileName
* Out    : -
* Return : See CNC_RC values
* Descr  : Load a job file
*/
CNC_RC EXP2DF __stdcall CncLoadJobA(const char *fileName);    //Multi byte

/* make compatible with bot Linux and Windows, application can use CncLoadJob */
#ifdef __unix__
#define CncLoadJob CncLoadJobA
#elif defined(_WIN32) || defined(WIN32)
#define CncLoadJob CncLoadJobW
#endif

/*
* Name   : CncRunOrResumeJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Start job or resume paused job
*/
CNC_RC EXP2DF __stdcall CncRunOrResumeJob(void);

/*
 * Name   : CncStartRenderGraph/CncStartRenderSearch
 *
 * In     : outLines, if 1, the outlines are generated to the GraphFifo.
 *          contour, if 1 the full contour is generated through the GraphFifo.
 *
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Run job through interpreter and send output to graph fifo for viewing
 *          Interpreter context is saved before and restored after.
 *          If this succeeds, job syntax is OK and will run without errors.
 *
 *          You could/should use it before CncRunOrResumeJob() above.
 *          if graphics isn't implemented in the GUI, use outlines = 0 and contour = 0
 *          if graphics is implemented, it should use CncGraphFifoGet() to get the graphics data.
 *
 */
CNC_RC EXP2DF __stdcall CncStartRenderGraph(int outLines, int contour);

/*
 * Name   : CncStartRenderGraph/CncStartRenderSearch
 *
 * In     : outLines, if 1, the outlines are generated to the GraphFifo.
 *          contour, if 1 the full contour is generated through the GraphFifo.
 *          lineNr
 *          toolNr
 *          arrayX
 *          arrayY
 *
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Run job through interpreter and send output to graph fifo for viewing
 *          Interpreter context is saved before and restored after.
 *          If this succeeds, job syntax is OK and will run without errors.
 *
 *          You could/should use it before CncRunOrResumeJob() above.
 *          if graphics isn't implemented in the GUI, use outlines = 0 and contour = 0
 *          if graphics is implemented, it should use CncGraphFifoGet() to get the graphics data.
 *
 */
CNC_RC EXP2DF __stdcall CncStartRenderSearch(int outLines, int contour, int lineNr, int toolNr, int arrayX, int arrayY);

/*
* Name   : CncRewindJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Rewind the job to beginning
*/
CNC_RC EXP2DF __stdcall CncRewindJob(void);

/*
* Name   : CncAbortJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Stop motion (stepper motor will lose steps, re-homing required when moving),
*          make IO safe
*/
CNC_RC EXP2DF __stdcall CncAbortJob(void);

/* Name  : CncSetJobArrayParameters
* In     : *runJobData
* Out    : -
* Return : See CNC_RC values
* Descr  : get render parameters for array/nesting execution which are in the job file
*          %dx=.., %dy=.., %ox=.., %oy=.., %mx=.., %my=.. from g-code file
*/
CNC_RC EXP2DF __stdcall CncSetJobArrayParameters(CNC_CMD_ARRAY_DATA *runJobData);

/* Name  : CncSetJobArrayParameters
* In     : *runJobData
* Out    : *runJobData
* Return : See CNC_RC values
* Descr  : get render parameters for array/nesting execution which are in the job file
*          %dx=.., %dy=.., %ox=.., %oy=.., %mx=.., %my=.. from g-code file
*/
CNC_RC EXP2DF __stdcall CncGetJobArrayParameters(CNC_CMD_ARRAY_DATA *runJobData);

/* Name  : CncGetJobMaterialSize
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Material size specified by %mx=.., %my=.., %mz..  from job file
*/
CNC_VECTOR EXP2DF __stdcall CncGetJobMaterialSize(void);

/* Name  : CncGetJobFiducual
* In     : n
* Out    : *fiducial
* Return : See CNC_RC values
* Descr  : Get fiducial parameters from %.. syntax in job file
*          %fidn=.. %fidt=.. %fidcx=.. %fidcy=.. %fidox=.. %fidoy=.. %fidor=..
*          if fiducial->fidn == -1, then the fiducial was no read from job file.
*/
CNC_RC EXP2DF __stdcall CncGetJobFiducual(int n, CNC_FIDUCIAL_DATA *fiducial);

/*
* Name   : CncEnableBlockDelete
* In     : enable, if 1 block delete will be switched on
* Out    : -
* Return : See CNC_RC values
* Descr  : If block delete is on, all lines wit '/' in font are skipped.
*/
CNC_RC EXP2DF __stdcall CncEnableBlockDelete(int enable);

/*
* Name   : CncGetBlockDelete
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  :
*/
int EXP2DF __stdcall CncGetBlocDelete(void);

/*
* Name   : CncEnableOptionalStop
* In     : enable, if 1 optional stop is switched on
* Out    : -
* Return : See CNC_RC values
* Descr  : Program will stop on M1 if optional stop is on.
*/
CNC_RC EXP2DF __stdcall CncEnableOptionalStop(int enable);

/*
* Name   : CncGetOptionalStop
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Program will stop on M1 if optional stop is on.
*/
int EXP2DF __stdcall CncGetOptionalStop(void);

/*
 * Name   : CncSingleStepMode
 * In     : enable, if 1 single step mode will be switched on
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Switch single step mode on or of, when on, CncRunJob will execute only
 *          one line of the loaded job, for single stepping.
 */
CNC_RC EXP2DF __stdcall CncSingleStepMode(int enable);

/*
 * Name   : CncGetSingleStepMode
 * In     : -
 * Out    : -
 * Return : Current status of single step mode.
 * Descr  :
 */
int EXP2DF __stdcall CncGetSingleStepMode(void);

/*
 * Name   : CncSetExtraLineAfterEndOfJob
 * In     : *extraLine
 *          doRepeat
 *          numberOfRepeats
 * Out    :
 * Return : See CNC_RC values
 * Descr  : When Job Done (with M30), this extra line is executed
 *          extraline must point to a rray of char with length CNC_MAX_INTERPRETER_LINE+1
 *
 */
CNC_RC EXP2DF __stdcall CncSetExtraJobOptions(char *extraLine, int doRepeat, unsigned int numberOfRepeats);

/*
* Name   : CncGetExtraJobOptions
* In     : *extraLine
* Out    : *doRepeat
*          *numberOfRepeats
* Return : -
* Descr  : When Job Done (with M30), this extra line is executed
*          extraline must point to a rray of char with length CNC_MAX_INTERPRETER_LINE+1
*
*/
void EXP2DF   __stdcall CncGetExtraJobOptions(char *extraLine, int *doRepeat, unsigned int *numberOfRepeats);

/*
 * Name   : CncSetSimulationMode
 * In     : enable, if 1 simulation mode will be switched on
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : Switch single step mode on or of, when on, CncRunJob will execute only
 *          one line of the loaded job, for single stepping.
 */
CNC_RC EXP2DF __stdcall CncSetSimulationMode(int enable);

/*
 * Name   : CncGetSimulationMode
 * In     : -
 * Out    : -
 * Return : Current simulation mode.
 * Descr  :
 */
int EXP2DF __stdcall CncGetSimulationMode(void);

/*
* Name   : CncSetFeedOverride
* In     : factor
* Out    : -
* Return : See CNC_RC values
* Descr  : Change feed rate factor global and relative for arc's
*          for arc's the factor is less than 1.0
*/
CNC_RC EXP2DF __stdcall CncSetFeedOverride(double factor);

/*
* Name   : CncSetArcFeedOverride
* In     : factor
* Out    : -
* Return : See CNC_RC values
* Descr  : Change feed rate factor global and relative for arc's
*          for arc's the factor is less than 1.0
*/
CNC_RC EXP2DF __stdcall CncSetArcFeedOverride(double factor);

/*
* Name   : CncGetActualFeedOverride
* In     : -
* Out    : -
* Return : Actual value of feed overrides and feed value
* Descr  :
*/
double EXP2DF __stdcall CncGetActualFeedOverride(void);

/*
* Name   : CncGetActualArcFeedOverride
* In     : -
* Out    : -
* Return : Actual value of feed overrides and feed value
* Descr  :
*/
double EXP2DF __stdcall CncGetActualArcFeedOverride(void);

/*
* Name   : CncGetActualFeed
* In     : -
* Out    : -
* Return : Actual value of feed overrides and feed value
* Descr  :
*/
double EXP2DF __stdcall CncGetActualFeed(void);

/*
* Name   : CncSetSpeedOverride
* In     : factor
* Out    : -
* Return : See CNC_RC values
* Descr  : Change feed rate factor
*/
CNC_RC EXP2DF __stdcall CncSetSpeedOverride(double factor);

/*
 * Name   : CncGetActualSpeedOverride
 * In     : -
 * Out    : -
 * Return : Actual value of speed override and speed value
 * Descr  : Change feed rate factor
 */
double EXP2DF __stdcall CncGetActualSpeedOverride(void);

/*
 * Name   : CncGetActualSpeed
 * In     : -
 * Out    : -
 * Return : Actual value of speed override and speed value
 * Descr  : Change feed rate factor
 */
double EXP2DF __stdcall CncGetActualSpeed(void);

/*
* Name   : CncFindFirstJobLine
* In     : -
* Out    : *text, a line of text
*          *endOfJob, 1 when last line
*          *totNumLines, total number of job lines
* Return : See CNC_RC values
*          get handle, pass to CncFindNextJobLine
*
* Descr  : Get first line of loaded job file
*/
CNC_RC EXP2DF __stdcall CncFindFirstJobLine(char *text, int *endOfJob, int *totNumOfLines);

/*
* Name   : CncFindFirstJobLineF
* In     : -
* Out    : *text, a line of text
*          *endOfJob, 1 when last line
* Return : See CNC_RC values
*          get handle, pass to CncFindNextJobLine
*
* Descr  : Get first line of loaded job file
*/
CNC_RC EXP2DF __stdcall CncFindFirstJobLineF(char *text, int *endOfJob);

/*
* Name   : CncFindNextJobLine
* In     : -
* Out    : *text, a line of text
*          *endOfJob, 1 when last line
* Return : See CNC_RC values
*          get handle, pass to next call to CncFindNextJobLine
*
* Descr  : Get next line of loaded job file
*/
CNC_RC EXP2DF __stdcall CncFindNextJobLine(char *text, int *endOfJob);

/*
* Name   : CncFindNextJobLineF
* In     : -
* Out    : *text, a line of text
*          *endOfJob, 1 when last line
* Return : See CNC_RC values
*          get handle, pass to next call to CncFindNextJobLine
*
* Descr  : Get next line of loaded job file
*/
CNC_RC EXP2DF __stdcall CncFindNextJobLineF(char *text, int *endOfJob);

/*************************************************************************/
/*                      Pause related functions                          */
/*************************************************************************/

/*
* Name   : CncSwitchOnSpindleAndWaitUntilOn
* In     : pFunc
*          pFuncParameter
* Out    : -
* Return :
* Descr  :
*/
int EXP2DF __stdcall CncSwitchOnSpindleAndWaitUntilOn(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/*
* Name   : CncPauseJob
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : Smooth stop in the middle of a job
*/
CNC_RC EXP2DF __stdcall CncPauseJob(void);

/*
* Name   : CncPauseJob
* In     : pFunc
*          pFuncParameter
* Out    : -
* Return : See CNC_RC values
* Descr  : Smooth stop in the middle of a job
*/
CNC_RC EXP2DF __stdcall CncPauseJob2(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/*
* Name   : CncSyncPauseZSafe
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  : In paused state move Z away from material
*/
int EXP2DF __stdcall CncSyncPauseZSafe(void);

/*
 * Name   : CncSyncPauseXSafe
 * In     : -
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : In paused state move X away from material (Lathe/Turning)
 */
int EXP2DF __stdcall CncSyncPauseXSafe(void);

/*
 * Name   : CncSyncPauseAxis
 * In     : axis
 *          feed
 * Out    : -
 * Return : See CNC_RC values
 * Descr  : In paused state move axes back to Pause position
 *          Required before Resume when moved away while in PAUSED state
 */
int EXP2DF __stdcall CncSyncPauseAxis(int axis, double feed);

/*
 * Name   : CncSyncFromPauseAndStartAutomatic
 * In     : approachFeed
 *          pFunc
 *          pFuncParameter
 * Out    : -
 * Return : 0 if ok, -1 if failed otherwise return value of pFunc
 * Descr  : In paused state move axes back to Pause position
 *          Required before Resume when moved away while in PAUSED state
 */
int EXP2DF __stdcall CncSyncFromPauseAndStartAutomatic(double approachFeed, CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/***************************************************************************/
/*                      Search related functions                           */
/* Search means that the g-code file/program is searched first up to a     */
/* given line and then run from there.                                     */
/* function below allow to synchronize the axes, tools etc so that the     */
/* machine position etc matches the searched interpreter position and tool */
/***************************************************************************/

/*
 * Name   : CncSyncSearchZSafe
 * In     : pFunc, keep GUI alive Function pointer, NULL allowed
 *          pFuncParameter
 * Out    : -
 * Return : Return value of user call back function or -1 if internal error.
 * Descr  : In search state move Z away from material
 */
int EXP2DF __stdcall CncSyncSearchZSafe(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/*
* Name   : CncSyncSearchXSafe
* In     : pFunc, keep GUI alive Function pointer, NULL allowed
*          pFuncParameter
* Out    : -
* Return : Return value of user call back function or -1 if internal error.
* Descr  : In search state move X away from material (Lathe/Turning)
*/
int EXP2DF __stdcall CncSyncSearchXSafe(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/*
* Name   : CncSyncSearchTool
* In     : pFunc, keep GUI alive Function pointer, NULL allowed
*          pFuncParameter
* Out    : -
* Return : Return value of user call back function or -1 if internal error.
* Descr  : Synchronize tool if required for search (tool change)
*          May be required before start a searched program (start in middle of g-code)
*/
int EXP2DF __stdcall CncSyncSearchTool(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);


/*
* Name   : CncSyncInchModeAndParametersAndOffset
* In     : pFunc, keep GUI alive Function pointer, NULL allowed
*          pFuncParameter
* Out    : -
* Return : Return value of user call back function or -1 if internal error.
* Descr  : Synchronize tool if required for search (tool change)
*          May be required before start a searched program (start in middle of g-code)
*/
int EXP2DF __stdcall CncSyncInchModeAndParametersAndOffset(CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);


/*
* Name   : CncSyncSearchAxis
* In     : axis CNC_X_AXIS .. CNC_C_AXIS
*          feed feed in mm/min or inc/min depending on inc/mm mode
*          pFunc, keep GUI alive Function pointer, NULL allowed
*          pFuncParameter
* Out    : -
* Return : Return value of user call back function or -1 if internal error.
* Descr  : Required before start a searched program (start in middle og g-code)
*/
int EXP2DF __stdcall CncSyncSearchAxis(int axis, double feed, CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);


/*
 * Name   : CncSyncSearchAllExceptToolAxis
 * In     : approachFeed
 *          pFunc, keep GUI alive Function pointer, NULL allowed
 *          pFuncParameter
 * Out    : -
 * Return : Return value of user call back function or -1 if internal error.
 * Descr  : Automatically Synchronize machine with interpreter status after search.
 *
 */
int EXP2DF __stdcall CncSyncFromSearchAndStartAutomatic(double approachFeed, CNC_KEEP_UI_ALIVE_FUNCTION pFunc, void *pFuncParameter);

/*************************************************************************/
/*                      Jogging related functions                        */
/*************************************************************************/

/*
* Name   : CncStartJog
* In     : axes, if value is 0, axis will not move,
*          velocityFactor if axes[i] > 0 movement is positive, if < 0 movement is negative
*          continuous if continuous is 0 axis[i] determines stepSize.
* Out    : -
* Return : See CNC_RC values
* Descr  : Start jog, multiple axes
*          velocity factor [-1.0 .. 1.0], sign determines direction
*
* Remark: CNC_MAX_AXES is 6
*
* Example:
*
*		Start continuous jog for x axis in positive direction with 50% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {1.0,0,0,0,0,0}
*       CncStartJog(axes, 0.5, 1)
*
*		Start continuous jog for y axis in negative direction with 50% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {0,-1.0,0,0,0,0}
*       CncStartJog(axes, 0.5, 1)
*
*		Start step wise jog of 2 mm jog for y axis in negative direction with 100% of max velocity
*       ================================================================================
*		double axes[CNC_MAX_AXES] = {0,-2.0,0,0,0,0}
*       CncStartJog(axes, 0.5, 0)
*
*/
CNC_RC EXP2DF __stdcall CncStartJog(CNC_CART_DOUBLE axes,
                                    double velocityFactor,
                                    int continuous);

/*
* Name   : CncStartJog2
* In     : axis, if value is 0, axis will not move,
*          step
*          velocityFactor if axes[i] > 0 movement is positive, if < 0 movement is negative
*          continuous if continuous is 0 axis[i] determines stepSize.
* Out    : -
* Return : See CNC_RC values
* Descr  : Start jog, multiple axes
*          velocity factor [-1.0 .. 1.0], sign determines direction
*
* Remark: CNC_MAX_AXES is 6
*/
CNC_RC EXP2DF __stdcall CncStartJog2(int axis,
                                     double step,
                                     double velocityFactor,
                                     int continuous);

/*
* Name   : CncStopJog
* In     : axis
* Out    : -
* Return : See CNC_RC values
* Descr  : Stop jog
*/
CNC_RC EXP2DF __stdcall CncStopJog(int axis);

/*
* Name   : CncMoveTo
* In     : pos position to move to for axis i,
*          move, if 1 axis i will move, if false no move.
*          velocityFactor
* Out    : -
* Return : See CNC_RC values
* Descr  : Move joints/motors to given position
*/
CNC_RC EXP2DF __stdcall CncMoveTo(CNC_CART_DOUBLE pos, CNC_CART_BOOL move, double velocityFactor);


/**************************************************************************/
/*                      Tracking related functions                        */
/*   Tracking is a mode where a special trajectory generator runs         */
/*   the machine will track give positions or positions from a hand-wheel */
/*it is currently used in vision applications and for hand-wheel operation*/
/**************************************************************************/

/*
* Name   : CncStartPositionTracking
* In     : -
*
* Out    : -
* Return : See CNC_RC values
* Descr  : Use e.g. for vision to track position of image.
*          Use in combination with CncSetTrackingPosition()
*          When done stop tracking by CncStopTracking()
*/
CNC_RC EXP2DF __stdcall CncStartPositionTracking(void);

/*
* Name   : CncStartVelocityTracking
* In     :
*
* Out    : -
* Return : See CNC_RC values
*          Use in combination with CncSetTrackingVelocity()
*          When done stop tracking by CncStopTracking()
*/
CNC_RC EXP2DF __stdcall CncStartVelocityTracking(void);

/*
* Name   : CncStartHandweelTracking
*
* In     : axis
*          vLimit
*          handwheelID
*			velMode
*			multiplicationFactor hand-wheel factor for joint
*          handwheelCountsPerRevolution is the number of counts that the hand-wheel gives for 1 revolution,
*
* Out    : -
* Return : See CNC_RC values
* Descr  :
*			axis is the axis to move, 0=X ... 5=C, it is ignored for external dual and triple handwheel.
*          vLimit is the maximum velocity to use when tracking.
*
*          handwheelID defines the hand-wheel source to track for each axis.
*			0 = tracking off
*         -1 = internal hand-wheel 1 (CPU)
*          1 = external hand-wheel 1
*          2 = external hand-wheel 2
*          3 - external hand-wheel 3
*          22 - external dual hand-wheel
*          33 - external triple hand-wheel
*
*			velMode, if 1, axis will immediately stop when hand-wheel is stopped.
*                   if 0, position of hand-wheel is maintained,
*					 axis may continue to run until position reached when hand wheel stopped.
*                   This happens e.g. when the hand-wheel is turned faster than the machine can follow.
*
*          factor = 1.0 will move 1 millimeter for one hand-wheel revolution.
*          factor = 2.0 will move 2 millimeter for one hand-wheel revolution.
*/
CNC_RC EXP2DF __stdcall CncStartHandweelTracking(int axis, double vLimit, int handwheelID,
        int velMode,
        double multiplicationFactor,
        int handwheelCountsPerRevolution);

/*
* Name   : CncSetTrackingPosition
* In     : pos machine position to move to.
*          vel maximum velocity to use, always positive. A velocity of 0 will give max velocity for that axis.
*          move set true for the axes that should move.
* Out    : -
* Return : See CNC_RC values
* Descr  : Use only with CncStartTrackPosition, repeat call to continue
*          tracking to different positions.
*/
CNC_RC EXP2DF __stdcall CncSetTrackingPosition(CNC_CART_DOUBLE pos,
        CNC_CART_DOUBLE vel,
        CNC_CART_BOOL   move);

/*
* Name   : CncSetTrackingPosition2
* In     : pos machine position to move to.
*          vel maximum velocity to use, always positive. A velocity of 0 will give max velocity for that axis.
*          acc
*          move set true for the axes that should move.
* Out    : -
* Return : See CNC_RC values
* Descr  : Use only with CncStartTrackPosition, repeat call to continue
*          tracking to different positions.
*/
CNC_RC EXP2DF __stdcall CncSetTrackingPosition2(CNC_CART_DOUBLE pos,
        CNC_CART_DOUBLE vel,
        CNC_CART_DOUBLE acc,
        CNC_CART_BOOL move);

/*
* Name   : CncSetTrackingVelocity
* In     : vel velocity to use, velocity can be positive or negative depending on the required movement direction.
*          move set true for the axes that should move.
* Out    : -
* Return : See CNC_RC values
* Descr  : Use e.g. for joystick application.
*          Use only with CncStartTrackVelocity
*          Repeat calling to change velocity, e.g. when joystick position was changed.
*/
CNC_RC EXP2DF __stdcall CncSetTrackingVelocity(CNC_CART_DOUBLE vel,
        CNC_CART_BOOL   move);

/*
* Name   : CncSetTrackingVelocity2
* In     : vel velocity to use, velocity can be positive or negative depending on the required movement direction.
*          acc
*          axes set true for the axes that should move.
* Out    : -
* Return : See CNC_RC values
* Descr  : Use e.g. for joystick application.
*          Use only with CncStartTrackVelocity
*          Repeat calling to change velocity, e.g. when joystick position was changed.
*/
CNC_RC EXP2DF __stdcall CncSetTrackingVelocity2(CNC_CART_DOUBLE vel,
        CNC_CART_DOUBLE acc,
        CNC_CART_BOOL axes);

/*
* Name   : CncSetTrackingHandwheelCounter
* In     : hw1Count New values for external hand-wheel counter 1 .. 3
*          hw2Count
*          hw3Count
* Out    : -
* Return : See CNC_RC values
* Descr  : Use e.g. for external hand-wheel application.
*          Use with CncStartHandwheelTracking
*          Repeat calling when hand-wheel counter changes.
*/
CNC_RC EXP2DF __stdcall CncSetTrackingHandwheelCounter(int hw1Count, int hw2Count, int hw3Count);

/*
* Name   : CncStartPlasmaTHCTracking
* In     : pLimit Positive
*          nLimit Negative limit of the tracking value
* Out    : -
* Return : See CNC_RC values
* Descr  : Use for THC.
*          See also CncSetPlasmaParameters/CncGetPlasmaParameters
*/
CNC_RC EXP2DF __stdcall CncStartPlasmaTHCTracking(double pLimit,  double nLimit);

/*
* Name   : CncSetPlasmaParameters
* In     : thcCfg plasma parameters
* Out    : -
* Return : See CNC_RC values
* Descr  : Use for THC.
*          See also CncStartPlasmaTHCTracking
*/
CNC_RC EXP2DF __stdcall CncSetPlasmaParameters(CNC_THC_PROCESS_PARAMETERS thcCfg);

/*
 * Name   : CncGetPlasmaParameters
 * In     : -
 * Out    : -
 * Return :
 * Descr  : Use for THC.
 *          See also CncStartPlasmaTHCTracking
 */
CNC_THC_PROCESS_PARAMETERS EXP2DF * __stdcall CncGetPlasmaParameters(void);

/*
* Name   : CncStopTracking
* In     : -
* Out    : -
* Return : See CNC_RC values
* Descr  :
*/
CNC_RC EXP2DF __stdcall CncStopTracking(void);

/*************************************************************************/
/*                         3D Printer                                    */
/*************************************************************************/
/*
* Name   : Cnc3DPrintCommand
* In     : pCmd command/reply for 3D printer, see description of CNC_3DPRINTING_COMMAND
* Out    : -
* Return : See CNC_RC values
* Descr  :
*/
CNC_RC EXP2DF __stdcall Cnc3DPrintCommand(CNC_3DPRINTING_COMMAND *pCmd);

/*************************************************************************/
/*              Utility functions and GUI control                        */
/*************************************************************************/

/*
* Name   : CncGetRCText
* In     : rc
* Out    : -
* Return : Text representing return code
*/
char EXP2DF * __stdcall CncGetRCText(CNC_RC rc);

/*
* Name   : CncSendUserMessage
* In     : functionName: ASCII character string name of your function
*          fileName: name of your file
*          lineNumber: line number in your file
*          ec: see CNC_ERROR_CLASS definition
*          rc: see CNC_RC definition
*          msg: your message text
*
* Out    : -
* Return : see CNC RC values
* Descr  : Send a message to the GUI message window
* Example:
*/
void EXP2DF __stdcall CncSendUserMessage(char *functionName, char *fileName, int lineNumber, CNC_ERROR_CLASS ec, CNC_RC rc, char *msg);

/*
* Name   : CncSendToGUI
* In     : action
*          value1
*          value2
* Out    : -
* Descr  : Send an action to the GUI with, optionally with 1 or 2 value parameters.
* Return : CNC_RC_OK or CNC_RC_ERR_FILEOPEN if not connected or
*          CNC_RC_ERR or CNC_RC_ERR_STATE when the mailbox is full.
*
*          This function is typically used by to control the GUI from another application, e.g. a Pendant input handler.
*          EdingCNC uses this for the UIO device.
*/
CNC_RC EXP2DF __stdcall CncSendToGUI(CNC_UIO_ACTIONS action, int value1, int value2);

/*
* Name   : CncGetGUICommand, get a command from the command mailbox, using a timeOut of 100ms.
* In     : *pAction
*        : pValue1
*        : pValue2
* Out    : *pAction
*        : *pValue1
*        : *pValue2
* Descr  : The main GUI receives the commands send by the function above.
* Return : CNC_RC_OK or TOS_INVALID_ID or CNC_RC_ERR or
*          CNC_RC_ERR_STATE when the mailbox is empty.
*          CNC_RC_ERR_TIMEOUT when a timeOut has occurred.
*
* Remark:  This function is already in use for the standard EdingCNC GUI.
*          3rd part usage is possible if there is also a 3rd party GUI and
*          the EdingCNC GUI is not used.
*/
CNC_RC EXP2DF __stdcall CncGetGUICommand(CNC_UIO_ACTIONS *pAction, int *pValue1, int *pValue2);

#ifdef __cplusplus
}
#endif


#endif
