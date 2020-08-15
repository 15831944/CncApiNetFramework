from ctypes import c_void_p, c_char_p, c_int, c_short, c_char, c_long, c_uint, c_bool, c_double, c_ulong, c_float, Structure, c_wchar, c_wchar_p, POINTER, c_ubyte, Union, create_string_buffer, byref
from cncapi.cncdefines import *
from cncapi.cncenums import *
from cncapi.cncstructs import *

import platform
if platform.architecture()[1] == 'ELF':
    from ctypes import PYFUNCTYPE, cdll

    _mydll = cdll.LoadLibrary("libcncapi.so")
else:
    from ctypes import WINFUNCTYPE, windll

    if platform.architecture()[0] == '64bit':
        _mydll = windll.LoadLibrary("cncapi64.dll")
    else:
        _mydll = windll.LoadLibrary("cncapi.dll")

try:
    CNC_KEEP_UI_ALIVE_FUNCTION = WINFUNCTYPE(c_void_p)
except:
    CNC_KEEP_UI_ALIVE_FUNCTION = PYFUNCTYPE(c_void_p)

_mydll.CncGetAPIVersion.argtypes = [ c_char_p ]
_mydll.CncGetAPIVersion.restype = None

_mydll.CncGetServerVersion.argtypes = [ c_char_p ]
_mydll.CncGetServerVersion.restype = c_int

_mydll.CncConnectServer.argtypes = [ c_char_p ]
_mydll.CncConnectServer.restype = c_int

_mydll.CncDisConnectServer.argtypes = [  ]
_mydll.CncDisConnectServer.restype = c_int

_mydll.CncGetSetupPassword.argtypes = [  ]
_mydll.CncGetSetupPassword.restype = c_char_p

_mydll.CncSetSetupPassword.argtypes = [ c_char_p ]
_mydll.CncSetSetupPassword.restype = c_int

_mydll.CncGetSystemConfig.argtypes = [  ]
_mydll.CncGetSystemConfig.restype = POINTER(CNC_SYSTEM_CONFIG)

_mydll.CncGetInterpreterConfig.argtypes = [  ]
_mydll.CncGetInterpreterConfig.restype = POINTER(CNC_INTERPRETER_CONFIG)

_mydll.CncGetSafetyConfig.argtypes = [  ]
_mydll.CncGetSafetyConfig.restype = POINTER(CNC_SAFETY_CONFIG)

_mydll.CncGetTrafficLightConfig.argtypes = [  ]
_mydll.CncGetTrafficLightConfig.restype = POINTER(CNC_TRAFFIC_LIGHT_CFG)

_mydll.CncGetProbingConfig.argtypes = [  ]
_mydll.CncGetProbingConfig.restype = POINTER(CNC_PROBING_CFG)

_mydll.CncGetIOConfig.argtypes = [  ]
_mydll.CncGetIOConfig.restype = POINTER(CNC_IO_CONFIG)

_mydll.CncGetGPIOConfig.argtypes = [  ]
_mydll.CncGetGPIOConfig.restype = POINTER(CNC_I2CGPIO_CARD_CONFIG)

_mydll.CncGetJointConfig.argtypes = [ c_int ]
_mydll.CncGetJointConfig.restype = POINTER(CNC_JOINT_CFG)

_mydll.CncGetSpindleConfig.argtypes = [ c_int ]
_mydll.CncGetSpindleConfig.restype = POINTER(CNC_SPINDLE_CONFIG)

_mydll.CncGetFeedSpeedConfig.argtypes = [  ]
_mydll.CncGetFeedSpeedConfig.restype = POINTER(CNC_FEEDSPEED_CFG)

_mydll.CncGetHandwheelConfig.argtypes = [  ]
_mydll.CncGetHandwheelConfig.restype = POINTER(CNC_HANDWHEEL_CFG)

_mydll.CncGetTrajectoryConfig.argtypes = [  ]
_mydll.CncGetTrajectoryConfig.restype = POINTER(CNC_TRAJECTORY_CFG)

_mydll.CncGetKinConfig.argtypes = [  ]
_mydll.CncGetKinConfig.restype = POINTER(CNC_KIN_CFG)

_mydll.CncGetUIConfig.argtypes = [  ]
_mydll.CncGetUIConfig.restype = POINTER(CNC_UI_CFG)

_mydll.CncGetCameraConfig.argtypes = [  ]
_mydll.CncGetCameraConfig.restype = POINTER(CNC_CAMERA_CONFIG)

_mydll.CncGetTHCConfig.argtypes = [  ]
_mydll.CncGetTHCConfig.restype = POINTER(CNC_THC_CFG)

_mydll.CncGetServiceConfig.argtypes = [  ]
_mydll.CncGetServiceConfig.restype = POINTER(CNC_SERVICE_CFG)

_mydll.CncGet3DPrintConfig.argtypes = [  ]
_mydll.CncGet3DPrintConfig.restype = POINTER(CNC_3DPRINTING_CONFIG)

_mydll.CncGetUIOConfig.argtypes = [  ]
_mydll.CncGetUIOConfig.restype = POINTER(CNC_UIO_CONFIG)

_mydll.CncGetVacuumConfig.argtypes = [  ]
_mydll.CncGetVacuumConfig.restype = POINTER(CNC_VACUUMBED_CONFIG)

_mydll.CncGetIOStatus.argtypes = [ c_int ]
_mydll.CncGetIOStatus.restype = POINTER(CNC_IO_PORT_STS)

_mydll.CncGetGPIOStatus.argtypes = [ c_int, c_int ]
_mydll.CncGetGPIOStatus.restype = POINTER(CNC_GPIO_PORT_STS)

_mydll.CncStoreIniFile.argtypes = [ c_int ]
_mydll.CncStoreIniFile.restype = c_int

_mydll.CncReInitialize.argtypes = [  ]
_mydll.CncReInitialize.restype = c_int

_mydll.CncGetMacroFileName.argtypes = [ c_char_p ]
_mydll.CncGetMacroFileName.restype = c_int

_mydll.CncGetUserMacroFileName.argtypes = [ c_char_p ]
_mydll.CncGetUserMacroFileName.restype = c_int

_mydll.CncSetMacroFileName.argtypes = [ c_char_p ]
_mydll.CncSetMacroFileName.restype = c_int

_mydll.CncSetUserMacroFileName.argtypes = [ c_char_p ]
_mydll.CncSetUserMacroFileName.restype = c_int

_mydll.CncGetControllerFirmwareVersion.argtypes = [  ]
_mydll.CncGetControllerFirmwareVersion.restype = c_char_p

_mydll.CncGetControllerSerialNumber.argtypes = [ POINTER(c_ubyte) ]
_mydll.CncGetControllerSerialNumber.restype = c_int

_mydll.CncGetControllerNumberOfFrequencyItems.argtypes = [  ]
_mydll.CncGetControllerNumberOfFrequencyItems.restype = c_int

_mydll.CncGetControllerFrequencyItem.argtypes = [ c_uint ]
_mydll.CncGetControllerFrequencyItem.restype = c_double

_mydll.CncGetControllerConnectionNumberOfItems.argtypes = [  ]
_mydll.CncGetControllerConnectionNumberOfItems.restype = c_int

_mydll.CncGetControllerConnectionItem.argtypes = [ c_int ]
_mydll.CncGetControllerConnectionItem.restype = c_char_p

_mydll.CncGetNrOfAxesOnController.argtypes = [ POINTER(c_int), POINTER(c_int) ]
_mydll.CncGetNrOfAxesOnController.restype = None

_mydll.CncGetAxisIsConfigured.argtypes = [ c_int, c_bool ]
_mydll.CncGetAxisIsConfigured.restype = c_int

_mydll.CncGetFirmwareHasOptions.argtypes = [  ]
_mydll.CncGetFirmwareHasOptions.restype = c_int

_mydll.CncGetActiveOptions.argtypes = [ POINTER(c_char), POINTER(c_int), POINTER(c_uint), POINTER(c_uint), POINTER(c_uint), POINTER(c_uint), POINTER(c_uint), POINTER(c_uint), POINTER(c_uint) ]
_mydll.CncGetActiveOptions.restype = c_int

_mydll.CncGetOptionRequestCode.argtypes = [ c_char_p, c_int, c_uint, c_uint, c_uint, c_uint, c_uint, c_uint, c_char_p ]
_mydll.CncGetOptionRequestCode.restype = c_int

_mydll.CncGetOptionRequestCodeCurrent.argtypes = [ c_char_p ]
_mydll.CncGetOptionRequestCodeCurrent.restype = c_int

_mydll.CncActivateOption.argtypes = [ c_char_p ]
_mydll.CncActivateOption.restype = c_int

_mydll.CncGetJointStatus.argtypes = [ c_int ]
_mydll.CncGetJointStatus.restype = POINTER(CNC_JOINT_STS)

_mydll.CncGetToolData.argtypes = [ c_int ]
_mydll.CncGetToolData.restype = CNC_TOOL_DATA

_mydll.CncUpdateToolData.argtypes = [ POINTER(CNC_TOOL_DATA), c_int ]
_mydll.CncUpdateToolData.restype = c_int

_mydll.CncLoadToolTable.argtypes = [  ]
_mydll.CncLoadToolTable.restype = c_int

_mydll.CncGetVariable.argtypes = [ c_int ]
_mydll.CncGetVariable.restype = c_double

_mydll.CncSetVariable.argtypes = [ c_int, c_double ]
_mydll.CncSetVariable.restype = None

_mydll.CncGetRunningStatus.argtypes = [  ]
_mydll.CncGetRunningStatus.restype = POINTER(CNC_RUNNING_STATUS)

_mydll.CncGetMotionStatus.argtypes = [  ]
_mydll.CncGetMotionStatus.restype = POINTER(CNC_MOTION_STATUS)

_mydll.CncGetControllerStatus.argtypes = [  ]
_mydll.CncGetControllerStatus.restype = POINTER(CNC_CONTROLLER_STATUS)

_mydll.CncGetControllerConfigStatus.argtypes = [  ]
_mydll.CncGetControllerConfigStatus.restype = POINTER(CNC_CONTROLLER_CONFIG_STATUS)

_mydll.CncGetTrafficLightStatus.argtypes = [  ]
_mydll.CncGetTrafficLightStatus.restype = POINTER(CNC_TRAFFIC_LIGHT_STATUS)

_mydll.CncGetJobStatus.argtypes = [  ]
_mydll.CncGetJobStatus.restype = POINTER(CNC_JOB_STATUS)

_mydll.CncGetTrackingStatus.argtypes = [  ]
_mydll.CncGetTrackingStatus.restype = POINTER(CNC_TRACKING_STATUS)

_mydll.CncGetTHCStatus.argtypes = [  ]
_mydll.CncGetTHCStatus.restype = POINTER(CNC_THC_STATUS)

_mydll.CncGetNestingStatus.argtypes = [  ]
_mydll.CncGetNestingStatus.restype = POINTER(CNC_NESTING_STATUS)

_mydll.CncGetKinStatus.argtypes = [  ]
_mydll.CncGetKinStatus.restype = POINTER(CNC_KIN_STATUS)

_mydll.CncGetSpindleStatus.argtypes = [  ]
_mydll.CncGetSpindleStatus.restype = POINTER(CNC_SPINDLE_STS)

_mydll.CncGetPauseStatus.argtypes = [  ]
_mydll.CncGetPauseStatus.restype = POINTER(CNC_PAUSE_STS)

_mydll.CncGetSearchStatus.argtypes = [  ]
_mydll.CncGetSearchStatus.restype = POINTER(CNC_SEARCH_STATUS)

_mydll.CncGet3DPrintStatus.argtypes = [  ]
_mydll.CncGet3DPrintStatus.restype = POINTER(CNC_3DPRINTING_STS)

_mydll.CncGetCompensationStatus.argtypes = [  ]
_mydll.CncGetCompensationStatus.restype = POINTER(CNC_COMPENSATION_STATUS)

_mydll.CncGetVacuumStatus.argtypes = [  ]
_mydll.CncGetVacuumStatus.restype = POINTER(CNC_VACUUM_STATUS)

_mydll.CncGet10msHeartBeat.argtypes = [  ]
_mydll.CncGet10msHeartBeat.restype = c_int

_mydll.CncIsServerConnected.argtypes = [  ]
_mydll.CncIsServerConnected.restype = c_int

_mydll.CncGetState.argtypes = [  ]
_mydll.CncGetState.restype = c_int

_mydll.CncGetStateText.argtypes = [ c_int ]
_mydll.CncGetStateText.restype = c_char_p

_mydll.CncInMillimeterMode.argtypes = [  ]
_mydll.CncInMillimeterMode.restype = c_int

_mydll.CncGetActualPlane.argtypes = [  ]
_mydll.CncGetActualPlane.restype = c_int

_mydll.CncGetWorkPosition.argtypes = [  ]
_mydll.CncGetWorkPosition.restype = CNC_CART_DOUBLE

_mydll.CncGetMotorPosition.argtypes = [  ]
_mydll.CncGetMotorPosition.restype = CNC_JOINT_DOUBLE

_mydll.CncGetMachinePosition.argtypes = [  ]
_mydll.CncGetMachinePosition.restype = CNC_CART_DOUBLE

_mydll.CncGetMachineZeroWorkPoint.argtypes = [ POINTER(CNC_CART_DOUBLE), POINTER(c_int) ]
_mydll.CncGetMachineZeroWorkPoint.restype = None

_mydll.CncGetActualOriginOffset.argtypes = [  ]
_mydll.CncGetActualOriginOffset.restype = CNC_CART_DOUBLE

_mydll.CncGetActualToolZOffset.argtypes = [  ]
_mydll.CncGetActualToolZOffset.restype = c_double

_mydll.CncGetActualToolXOffset.argtypes = [  ]
_mydll.CncGetActualToolXOffset.restype = c_double

_mydll.CncGetActualG68Rotation.argtypes = [  ]
_mydll.CncGetActualG68Rotation.restype = c_double

_mydll.CncGetActualG68RotationPlane.argtypes = [  ]
_mydll.CncGetActualG68RotationPlane.restype = c_int

_mydll.CncGetCurrentGcodesText.argtypes = [ c_char_p ]
_mydll.CncGetCurrentGcodesText.restype = None

_mydll.CncGetCurrentMcodesText.argtypes = [ c_char_p ]
_mydll.CncGetCurrentMcodesText.restype = None

_mydll.CncGetCurrentGcodeSettingsText.argtypes = [ c_char_p ]
_mydll.CncGetCurrentGcodeSettingsText.restype = None

_mydll.CncGetProgrammedSpeed.argtypes = [  ]
_mydll.CncGetProgrammedSpeed.restype = c_double

_mydll.CncGetProgrammedFeed.argtypes = [  ]
_mydll.CncGetProgrammedFeed.restype = c_double

_mydll.CncGetCurrentToolNumber.argtypes = [  ]
_mydll.CncGetCurrentToolNumber.restype = c_int

_mydll.CncG43Active.argtypes = [  ]
_mydll.CncG43Active.restype = c_int

_mydll.CncG95Active.argtypes = [  ]
_mydll.CncG95Active.restype = c_int

_mydll.CncGetCurInterpreterLineNumber.argtypes = [  ]
_mydll.CncGetCurInterpreterLineNumber.restype = c_int

_mydll.CncGetCurInterpreterLineText.argtypes = [ c_char_p ]
_mydll.CncGetCurInterpreterLineText.restype = c_int

_mydll.CncCurrentInterpreterLineContainsToolChange.argtypes = [  ]
_mydll.CncCurrentInterpreterLineContainsToolChange.restype = c_int

_mydll.CncGetSwLimitError.argtypes = [  ]
_mydll.CncGetSwLimitError.restype = c_int

_mydll.CncGetFifoError.argtypes = [  ]
_mydll.CncGetFifoError.restype = c_int

_mydll.CncGetEMStopActive.argtypes = [  ]
_mydll.CncGetEMStopActive.restype = c_int

_mydll.CncGetAllAxesHomed.argtypes = [  ]
_mydll.CncGetAllAxesHomed.restype = c_int

_mydll.CncGetSafetyMode.argtypes = [  ]
_mydll.CncGetSafetyMode.restype = c_int

_mydll.CncKinGetActiveType.argtypes = [  ]
_mydll.CncKinGetActiveType.restype = c_int

_mydll.CncKinActivate.argtypes = [ c_int ]
_mydll.CncKinActivate.restype = c_int

_mydll.CncKinInit.argtypes = [  ]
_mydll.CncKinInit.restype = c_int

_mydll.CncKinControl.argtypes = [ c_int, POINTER(KIN_CONTROLDATA) ]
_mydll.CncKinControl.restype = c_int

_mydll.CncKinGetARotationPoint.argtypes = [  ]
_mydll.CncKinGetARotationPoint.restype = CNC_VECTOR

_mydll.CncGetIOName.argtypes = [ c_int ]
_mydll.CncGetIOName.restype = c_char_p

_mydll.CncGetOutput.argtypes = [ c_int ]
_mydll.CncGetOutput.restype = c_int

_mydll.CncGetOutputRaw.argtypes = [ c_int ]
_mydll.CncGetOutputRaw.restype = c_int

_mydll.CncGetGPIOOutput.argtypes = [ c_int, c_int ]
_mydll.CncGetGPIOOutput.restype = c_int

_mydll.CncGetInput.argtypes = [ c_int ]
_mydll.CncGetInput.restype = c_int

_mydll.CncGetInputRaw.argtypes = [ c_int ]
_mydll.CncGetInputRaw.restype = c_int

_mydll.CncGetGPIOInput.argtypes = [ c_int, c_int ]
_mydll.CncGetGPIOInput.restype = c_int

_mydll.CncSetOutput.argtypes = [ c_int, c_int ]
_mydll.CncSetOutput.restype = c_int

_mydll.CncSetOutputRaw.argtypes = [ c_int, c_int ]
_mydll.CncSetOutputRaw.restype = c_int

_mydll.CncSetGPIOOutput.argtypes = [ c_int, c_int, c_int ]
_mydll.CncSetGPIOOutput.restype = c_int

_mydll.CncCheckStartConditionOK.argtypes = [ c_int, c_int, POINTER(c_int) ]
_mydll.CncCheckStartConditionOK.restype = c_int

_mydll.CncSetSpindleOutput.argtypes = [ c_int, c_int, c_double ]
_mydll.CncSetSpindleOutput.restype = c_int

_mydll.CncLogFifoGet.argtypes = [ POINTER(CNC_LOG_MESSAGE) ]
_mydll.CncLogFifoGet.restype = c_int

_mydll.CncPosFifoGet.argtypes = [ POINTER(CNC_POS_FIFO_DATA) ]
_mydll.CncPosFifoGet.restype = c_int

_mydll.CncPosFifoGet2.argtypes = [ POINTER(CNC_POS_FIFO_DATA), POINTER(c_int) ]
_mydll.CncPosFifoGet2.restype = c_int

_mydll.CncGraphFifoGet.argtypes = [ POINTER(CNC_GRAPH_FIFO_DATA) ]
_mydll.CncGraphFifoGet.restype = c_int

_mydll.CncReset.argtypes = [  ]
_mydll.CncReset.restype = c_int

_mydll.CncReset2.argtypes = [ c_uint ]
_mydll.CncReset2.restype = c_int

_mydll.CncRunSingleLine.argtypes = [ c_char_p ]
_mydll.CncRunSingleLine.restype = c_int

_mydll.CncWaitSingleLine.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncWaitSingleLine.restype = c_int

_mydll.CncLoadJobW.argtypes = [ c_wchar_p ]
_mydll.CncLoadJobW.restype = c_int

_mydll.CncLoadJobA.argtypes = [ c_char_p ]
_mydll.CncLoadJobA.restype = c_int

_mydll.CncRunOrResumeJob.argtypes = [  ]
_mydll.CncRunOrResumeJob.restype = c_int

_mydll.CncStartRenderGraph.argtypes = [ c_int, c_int ]
_mydll.CncStartRenderGraph.restype = c_int

_mydll.CncStartRenderSearch.argtypes = [ c_int, c_int, c_int, c_int, c_int, c_int ]
_mydll.CncStartRenderSearch.restype = c_int

_mydll.CncRewindJob.argtypes = [  ]
_mydll.CncRewindJob.restype = c_int

_mydll.CncAbortJob.argtypes = [  ]
_mydll.CncAbortJob.restype = c_int

_mydll.CncSetJobArrayParameters.argtypes = [ POINTER(CNC_CMD_ARRAY_DATA) ]
_mydll.CncSetJobArrayParameters.restype = c_int

_mydll.CncGetJobArrayParameters.argtypes = [ POINTER(CNC_CMD_ARRAY_DATA) ]
_mydll.CncGetJobArrayParameters.restype = c_int

_mydll.CncGetJobMaterialSize.argtypes = [  ]
_mydll.CncGetJobMaterialSize.restype = CNC_VECTOR

_mydll.CncGetJobFiducual.argtypes = [ c_int, POINTER(CNC_FIDUCIAL_DATA) ]
_mydll.CncGetJobFiducual.restype = c_int

_mydll.CncEnableBlockDelete.argtypes = [ c_int ]
_mydll.CncEnableBlockDelete.restype = c_int

_mydll.CncGetBlocDelete.argtypes = [  ]
_mydll.CncGetBlocDelete.restype = c_int

_mydll.CncEnableOptionalStop.argtypes = [ c_int ]
_mydll.CncEnableOptionalStop.restype = c_int

_mydll.CncGetOptionalStop.argtypes = [  ]
_mydll.CncGetOptionalStop.restype = c_int

_mydll.CncSingleStepMode.argtypes = [ c_int ]
_mydll.CncSingleStepMode.restype = c_int

_mydll.CncGetSingleStepMode.argtypes = [  ]
_mydll.CncGetSingleStepMode.restype = c_int

_mydll.CncSetExtraJobOptions.argtypes = [ c_char_p, c_int, c_uint ]
_mydll.CncSetExtraJobOptions.restype = c_int

_mydll.CncGetExtraJobOptions.argtypes = [ c_char_p, POINTER(c_int), POINTER(c_uint) ]
_mydll.CncGetExtraJobOptions.restype = None

_mydll.CncSetSimulationMode.argtypes = [ c_int ]
_mydll.CncSetSimulationMode.restype = c_int

_mydll.CncGetSimulationMode.argtypes = [  ]
_mydll.CncGetSimulationMode.restype = c_int

_mydll.CncSetFeedOverride.argtypes = [ c_double ]
_mydll.CncSetFeedOverride.restype = c_int

_mydll.CncSetArcFeedOverride.argtypes = [ c_double ]
_mydll.CncSetArcFeedOverride.restype = c_int

_mydll.CncGetActualFeedOverride.argtypes = [  ]
_mydll.CncGetActualFeedOverride.restype = c_double

_mydll.CncGetActualArcFeedOverride.argtypes = [  ]
_mydll.CncGetActualArcFeedOverride.restype = c_double

_mydll.CncGetActualFeed.argtypes = [  ]
_mydll.CncGetActualFeed.restype = c_double

_mydll.CncSetSpeedOverride.argtypes = [ c_double ]
_mydll.CncSetSpeedOverride.restype = c_int

_mydll.CncGetActualSpeedOverride.argtypes = [  ]
_mydll.CncGetActualSpeedOverride.restype = c_double

_mydll.CncGetActualSpeed.argtypes = [  ]
_mydll.CncGetActualSpeed.restype = c_double

_mydll.CncFindFirstJobLine.argtypes = [ c_char_p, POINTER(c_int), POINTER(c_int) ]
_mydll.CncFindFirstJobLine.restype = c_int

_mydll.CncFindFirstJobLineF.argtypes = [ c_char_p, POINTER(c_int) ]
_mydll.CncFindFirstJobLineF.restype = c_int

_mydll.CncFindNextJobLine.argtypes = [ c_char_p, POINTER(c_int) ]
_mydll.CncFindNextJobLine.restype = c_int

_mydll.CncFindNextJobLineF.argtypes = [ c_char_p, POINTER(c_int) ]
_mydll.CncFindNextJobLineF.restype = c_int

_mydll.CncSwitchOnSpindleAndWaitUntilOn.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSwitchOnSpindleAndWaitUntilOn.restype = c_int

_mydll.CncPauseJob.argtypes = [  ]
_mydll.CncPauseJob.restype = c_int

_mydll.CncPauseJob2.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncPauseJob2.restype = c_int

_mydll.CncSyncPauseZSafe.argtypes = [  ]
_mydll.CncSyncPauseZSafe.restype = c_int

_mydll.CncSyncPauseXSafe.argtypes = [  ]
_mydll.CncSyncPauseXSafe.restype = c_int

_mydll.CncSyncPauseAxis.argtypes = [ c_int, c_double ]
_mydll.CncSyncPauseAxis.restype = c_int

_mydll.CncSyncFromPauseAndStartAutomatic.argtypes = [ c_double, CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncFromPauseAndStartAutomatic.restype = c_int

_mydll.CncSyncSearchZSafe.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncSearchZSafe.restype = c_int

_mydll.CncSyncSearchXSafe.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncSearchXSafe.restype = c_int

_mydll.CncSyncSearchTool.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncSearchTool.restype = c_int

_mydll.CncSyncInchModeAndParametersAndOffset.argtypes = [ CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncInchModeAndParametersAndOffset.restype = c_int

_mydll.CncSyncSearchAxis.argtypes = [ c_int, c_double, CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncSearchAxis.restype = c_int

_mydll.CncSyncFromSearchAndStartAutomatic.argtypes = [ c_double, CNC_KEEP_UI_ALIVE_FUNCTION, c_void_p ]
_mydll.CncSyncFromSearchAndStartAutomatic.restype = c_int

_mydll.CncStartJog.argtypes = [ POINTER(c_double), c_double, c_int ]
_mydll.CncStartJog.restype = c_int

_mydll.CncStartJog2.argtypes = [ c_int, c_double, c_double, c_int ]
_mydll.CncStartJog2.restype = c_int

_mydll.CncStopJog.argtypes = [ c_int ]
_mydll.CncStopJog.restype = c_int

_mydll.CncMoveTo.argtypes = [ CNC_CART_DOUBLE, CNC_CART_BOOL, c_double ]
_mydll.CncMoveTo.restype = c_int

_mydll.CncStartPositionTracking.argtypes = [  ]
_mydll.CncStartPositionTracking.restype = c_int

_mydll.CncStartVelocityTracking.argtypes = [  ]
_mydll.CncStartVelocityTracking.restype = c_int

_mydll.CncStartHandweelTracking.argtypes = [ c_int, c_double, c_int, c_int, c_double, c_int ]
_mydll.CncStartHandweelTracking.restype = c_int

_mydll.CncSetTrackingPosition.argtypes = [ CNC_CART_DOUBLE, CNC_CART_DOUBLE, CNC_CART_BOOL ]
_mydll.CncSetTrackingPosition.restype = c_int

_mydll.CncSetTrackingPosition2.argtypes = [ CNC_CART_DOUBLE, CNC_CART_DOUBLE, CNC_CART_DOUBLE, CNC_CART_BOOL ]
_mydll.CncSetTrackingPosition2.restype = c_int

_mydll.CncSetTrackingVelocity.argtypes = [ CNC_CART_DOUBLE, CNC_CART_BOOL ]
_mydll.CncSetTrackingVelocity.restype = c_int

_mydll.CncSetTrackingVelocity2.argtypes = [ CNC_CART_DOUBLE, CNC_CART_DOUBLE, CNC_CART_BOOL ]
_mydll.CncSetTrackingVelocity2.restype = c_int

_mydll.CncSetTrackingHandwheelCounter.argtypes = [ c_int, c_int, c_int ]
_mydll.CncSetTrackingHandwheelCounter.restype = c_int

_mydll.CncStartPlasmaTHCTracking.argtypes = [ c_double, c_double ]
_mydll.CncStartPlasmaTHCTracking.restype = c_int

_mydll.CncSetPlasmaParameters.argtypes = [ CNC_THC_PROCESS_PARAMETERS ]
_mydll.CncSetPlasmaParameters.restype = c_int

_mydll.CncGetPlasmaParameters.argtypes = [  ]
_mydll.CncGetPlasmaParameters.restype = POINTER(CNC_THC_PROCESS_PARAMETERS)

_mydll.CncStopTracking.argtypes = [  ]
_mydll.CncStopTracking.restype = c_int

_mydll.Cnc3DPrintCommand.argtypes = [ POINTER(CNC_3DPRINTING_COMMAND) ]
_mydll.Cnc3DPrintCommand.restype = c_int

_mydll.CncGetRCText.argtypes = [ c_int ]
_mydll.CncGetRCText.restype = c_char_p

_mydll.CncSendUserMessage.argtypes = [ c_char_p, c_char_p, c_int, c_int, c_int, c_char_p ]
_mydll.CncSendUserMessage.restype = None

_mydll.CncSendToGUI.argtypes = [ c_int, c_int, c_int ]
_mydll.CncSendToGUI.restype = c_int

_mydll.CncGetGUICommand.argtypes = [ POINTER(c_int), POINTER(c_int), POINTER(c_int) ]
_mydll.CncGetGUICommand.restype = c_int

def CncGetAPIVersion():
    c_version = create_string_buffer(CNC_MAX_NAME_LENGTH)
    _mydll.CncGetAPIVersion(c_version)
    return (CNC_RC_OK, c_version.value)

def CncGetServerVersion():
    c_version = create_string_buffer(CNC_MAX_NAME_LENGTH)
    retval = _mydll.CncGetServerVersion(c_version)
    return (retval, c_version.value)

def CncConnectServer(iniFileName):
    c_iniFileName = c_char_p()
    c_iniFileName.value = str.encode(iniFileName)
    retval = _mydll.CncConnectServer(c_iniFileName)
    return (retval)

def CncDisConnectServer():
    retval = _mydll.CncDisConnectServer()
    return (retval)

def CncGetSetupPassword():
    retval = _mydll.CncGetSetupPassword()
    return (retval)

def CncSetSetupPassword(newPassword):
    c_newPassword = c_char_p()
    c_newPassword.value = str.encode(newPassword)
    retval = _mydll.CncSetSetupPassword(c_newPassword)
    return (retval)

def CncGetSystemConfig():
    retval = _mydll.CncGetSystemConfig()
    return (retval.contents)

def CncGetInterpreterConfig():
    retval = _mydll.CncGetInterpreterConfig()
    return (retval.contents)

def CncGetSafetyConfig():
    retval = _mydll.CncGetSafetyConfig()
    return (retval.contents)

def CncGetTrafficLightConfig():
    retval = _mydll.CncGetTrafficLightConfig()
    return (retval.contents)

def CncGetProbingConfig():
    retval = _mydll.CncGetProbingConfig()
    return (retval.contents)

def CncGetIOConfig():
    retval = _mydll.CncGetIOConfig()
    return (retval.contents)

def CncGetGPIOConfig():
    retval = _mydll.CncGetGPIOConfig()
    return (retval.contents)

def CncGetJointConfig(joint):
    c_joint = c_int(joint)
    retval = _mydll.CncGetJointConfig(c_joint)
    return (retval.contents)

def CncGetSpindleConfig(spindle):
    c_spindle = c_int(spindle)
    retval = _mydll.CncGetSpindleConfig(c_spindle)
    return (retval.contents)

def CncGetFeedSpeedConfig():
    retval = _mydll.CncGetFeedSpeedConfig()
    return (retval.contents)

def CncGetHandwheelConfig():
    retval = _mydll.CncGetHandwheelConfig()
    return (retval.contents)

def CncGetTrajectoryConfig():
    retval = _mydll.CncGetTrajectoryConfig()
    return (retval.contents)

def CncGetKinConfig():
    retval = _mydll.CncGetKinConfig()
    return (retval.contents)

def CncGetUIConfig():
    retval = _mydll.CncGetUIConfig()
    return (retval.contents)

def CncGetCameraConfig():
    retval = _mydll.CncGetCameraConfig()
    return (retval.contents)

def CncGetTHCConfig():
    retval = _mydll.CncGetTHCConfig()
    return (retval.contents)

def CncGetServiceConfig():
    retval = _mydll.CncGetServiceConfig()
    return (retval.contents)

def CncGet3DPrintConfig():
    retval = _mydll.CncGet3DPrintConfig()
    return (retval.contents)

def CncGetUIOConfig():
    retval = _mydll.CncGetUIOConfig()
    return (retval.contents)

def CncGetVacuumConfig():
    retval = _mydll.CncGetVacuumConfig()
    return (retval.contents)

def CncGetIOStatus(ioID):
    c_ioID = c_int(ioID)
    retval = _mydll.CncGetIOStatus(c_ioID)
    return (retval.contents)

def CncGetGPIOStatus(cardNr, ioID):
    c_cardNr = c_int(cardNr)
    c_ioID = c_int(ioID)
    retval = _mydll.CncGetGPIOStatus(c_cardNr, c_ioID)
    return (retval.contents)

def CncStoreIniFile(saveFixtures):
    c_saveFixtures = c_int(saveFixtures)
    retval = _mydll.CncStoreIniFile(c_saveFixtures)
    return (retval)

def CncReInitialize():
    retval = _mydll.CncReInitialize()
    return (retval)

def CncGetMacroFileName():
    c_name = create_string_buffer(CNC_MAX_PATH)
    retval = _mydll.CncGetMacroFileName(c_name)
    return (retval, c_name.value)

def CncGetUserMacroFileName():
    c_name = create_string_buffer(CNC_MAX_PATH)
    retval = _mydll.CncGetUserMacroFileName(c_name)
    return (retval, c_name.value)

def CncSetMacroFileName(name):
    c_name = c_char_p()
    c_name.value = str.encode(name)
    retval = _mydll.CncSetMacroFileName(c_name)
    return (retval)

def CncSetUserMacroFileName(name):
    c_name = c_char_p()
    c_name.value = str.encode(name)
    retval = _mydll.CncSetUserMacroFileName(c_name)
    return (retval)

def CncGetControllerFirmwareVersion():
    retval = _mydll.CncGetControllerFirmwareVersion()
    return (retval)

def CncGetControllerSerialNumber():
    c_serial = (c_ubyte * 50)()
    retval = _mydll.CncGetControllerSerialNumber(byref(c_serial))
    return (retval, c_serial.value)

def CncGetControllerNumberOfFrequencyItems():
    retval = _mydll.CncGetControllerNumberOfFrequencyItems()
    return (retval)

def CncGetControllerFrequencyItem(index):
    c_index = c_uint(index)
    retval = _mydll.CncGetControllerFrequencyItem(c_index)
    return (retval)

def CncGetControllerConnectionNumberOfItems():
    retval = _mydll.CncGetControllerConnectionNumberOfItems()
    return (retval)

def CncGetControllerConnectionItem(itemNumber):
    c_itemNumber = c_int(itemNumber)
    retval = _mydll.CncGetControllerConnectionItem(c_itemNumber)
    return (retval)

def CncGetNrOfAxesOnController():
    c_maxNrOfAxes = c_int()
    c_availableNrOfAxes = c_int()
    _mydll.CncGetNrOfAxesOnController(byref(c_maxNrOfAxes), byref(c_availableNrOfAxes))
    return (CNC_RC_OK, c_maxNrOfAxes.value, c_availableNrOfAxes.value)

def CncGetAxisIsConfigured(axis, includingSlaves):
    c_axis = c_int(axis)
    c_includingSlaves = c_bool(includingSlaves)
    retval = _mydll.CncGetAxisIsConfigured(c_axis, c_includingSlaves)
    return (retval)

def CncGetFirmwareHasOptions():
    retval = _mydll.CncGetFirmwareHasOptions()
    return (retval)

def CncGetActiveOptions():
    c_actCustomerName = create_string_buffer(256)
    c_actNumberOfAxes = c_int()
    c_actCPUEnabled = c_uint()
    c_actGPIOAVXEnabled = c_uint()
    c_actGPIOEDIEnabled = c_uint()
    c_actWolfcutCameraEnabled = c_uint()
    c_actTURNMACRO = c_uint()
    c_actXHCPendant = c_uint()
    c_actLimitedSoftwareEnabled = c_uint()
    retval = _mydll.CncGetActiveOptions(byref(c_actCustomerName), byref(c_actNumberOfAxes), byref(c_actCPUEnabled), byref(c_actGPIOAVXEnabled), byref(c_actGPIOEDIEnabled), byref(c_actWolfcutCameraEnabled), byref(c_actTURNMACRO), byref(c_actXHCPendant), byref(c_actLimitedSoftwareEnabled))
    return (retval, c_actCustomerName.value, c_actNumberOfAxes.value, c_actGPIOAVXEnabled.value, c_actGPIOEDIEnabled.value, c_actXHCPendant.value, c_actLimitedSoftwareEnabled.value)

def CncGetOptionRequestCode(newCustomerName, newNumberOfAxes, newGPIOAVXEnabled, newGPIOEDIEnabled, newPLASMAEnabled, newTURMACROEnabled, newXHCPendant, newLimitedSoftwareEnabled):
    c_newCustomerName = c_char_p()
    c_newCustomerName.value = str.encode(newCustomerName)
    c_newNumberOfAxes = c_int(newNumberOfAxes)
    c_newGPIOAVXEnabled = c_uint(newGPIOAVXEnabled)
    c_newGPIOEDIEnabled = c_uint(newGPIOEDIEnabled)
    c_newPLASMAEnabled = c_uint(newPLASMAEnabled)
    c_newTURMACROEnabled = c_uint(newTURMACROEnabled)
    c_newXHCPendant = c_uint(newXHCPendant)
    c_newLimitedSoftwareEnabled = c_uint(newLimitedSoftwareEnabled)
    c_requestCode = create_string_buffer(256)
    retval = _mydll.CncGetOptionRequestCode(c_newCustomerName, c_newNumberOfAxes, c_newGPIOAVXEnabled, c_newGPIOEDIEnabled, c_newPLASMAEnabled, c_newTURMACROEnabled, c_newXHCPendant, c_newLimitedSoftwareEnabled, c_requestCode)
    return (retval, c_requestCode.value)

def CncGetOptionRequestCodeCurrent():
    c_requestCode = create_string_buffer(256)
    retval = _mydll.CncGetOptionRequestCodeCurrent(c_requestCode)
    return (retval, c_requestCode.value)

def CncActivateOption(activationKey):
    c_activationKey = c_char_p()
    c_activationKey.value = str.encode(activationKey)
    retval = _mydll.CncActivateOption(c_activationKey)
    return (retval)

def CncGetJointStatus(joint):
    c_joint = c_int(joint)
    retval = _mydll.CncGetJointStatus(c_joint)
    return (retval.contents)

def CncGetToolData(index):
    c_index = c_int(index)
    retval = _mydll.CncGetToolData(c_index)
    return (CNC_TOOL_DATA)

def CncUpdateToolData(pTool, index):
    c_pTool = CNC_TOOL_DATA(pTool)
    c_index = c_int(index)
    retval = _mydll.CncUpdateToolData(byref(c_pTool), c_index)
    return (retval)

def CncLoadToolTable():
    retval = _mydll.CncLoadToolTable()
    return (retval)

def CncGetVariable(varIndex):
    c_varIndex = c_int(varIndex)
    retval = _mydll.CncGetVariable(c_varIndex)
    return (retval)

def CncSetVariable(varIndex, value):
    c_varIndex = c_int(varIndex)
    c_value = c_double(value)
    _mydll.CncSetVariable(c_varIndex, c_value)
    return (CNC_RC_OK)

def CncGetRunningStatus():
    retval = _mydll.CncGetRunningStatus()
    return (retval.contents)

def CncGetMotionStatus():
    retval = _mydll.CncGetMotionStatus()
    return (retval.contents)

def CncGetControllerStatus():
    retval = _mydll.CncGetControllerStatus()
    return (retval.contents)

def CncGetControllerConfigStatus():
    retval = _mydll.CncGetControllerConfigStatus()
    return (retval.contents)

def CncGetTrafficLightStatus():
    retval = _mydll.CncGetTrafficLightStatus()
    return (retval.contents)

def CncGetJobStatus():
    retval = _mydll.CncGetJobStatus()
    return (retval.contents)

def CncGetTrackingStatus():
    retval = _mydll.CncGetTrackingStatus()
    return (retval.contents)

def CncGetTHCStatus():
    retval = _mydll.CncGetTHCStatus()
    return (retval.contents)

def CncGetNestingStatus():
    retval = _mydll.CncGetNestingStatus()
    return (retval.contents)

def CncGetKinStatus():
    retval = _mydll.CncGetKinStatus()
    return (retval.contents)

def CncGetSpindleStatus():
    retval = _mydll.CncGetSpindleStatus()
    return (retval.contents)

def CncGetPauseStatus():
    retval = _mydll.CncGetPauseStatus()
    return (retval.contents)

def CncGetSearchStatus():
    retval = _mydll.CncGetSearchStatus()
    return (retval.contents)

def CncGet3DPrintStatus():
    retval = _mydll.CncGet3DPrintStatus()
    return (retval.contents)

def CncGetCompensationStatus():
    retval = _mydll.CncGetCompensationStatus()
    return (retval.contents)

def CncGetVacuumStatus():
    retval = _mydll.CncGetVacuumStatus()
    return (retval.contents)

def CncGet10msHeartBeat():
    retval = _mydll.CncGet10msHeartBeat()
    return (retval)

def CncIsServerConnected():
    retval = _mydll.CncIsServerConnected()
    return (retval)

def CncGetState():
    retval = _mydll.CncGetState()
    return (retval)

def CncGetStateText(state):
    c_state = c_int(state)
    retval = _mydll.CncGetStateText(c_state)
    return (retval)

def CncInMillimeterMode():
    retval = _mydll.CncInMillimeterMode()
    return (retval)

def CncGetActualPlane():
    retval = _mydll.CncGetActualPlane()
    return (retval)

def CncGetWorkPosition():
    retval = _mydll.CncGetWorkPosition()
    return (CNC_CART_DOUBLE)

def CncGetMotorPosition():
    retval = _mydll.CncGetMotorPosition()
    return (CNC_JOINT_DOUBLE)

def CncGetMachinePosition():
    retval = _mydll.CncGetMachinePosition()
    return (CNC_CART_DOUBLE)

def CncGetMachineZeroWorkPoint():
    c_pos = CNC_CART_DOUBLE()
    c_rotationActive = c_int()
    _mydll.CncGetMachineZeroWorkPoint(byref(c_pos), byref(c_rotationActive))
    return (CNC_RC_OK, c_pos.value, c_rotationActive.value)

def CncGetActualOriginOffset():
    retval = _mydll.CncGetActualOriginOffset()
    return (CNC_CART_DOUBLE)

def CncGetActualToolZOffset():
    retval = _mydll.CncGetActualToolZOffset()
    return (retval)

def CncGetActualToolXOffset():
    retval = _mydll.CncGetActualToolXOffset()
    return (retval)

def CncGetActualG68Rotation():
    retval = _mydll.CncGetActualG68Rotation()
    return (retval)

def CncGetActualG68RotationPlane():
    retval = _mydll.CncGetActualG68RotationPlane()
    return (retval)

def CncGetCurrentGcodesText():
    c_activeGCodes = create_string_buffer(80)
    _mydll.CncGetCurrentGcodesText(c_activeGCodes)
    return (CNC_RC_OK, c_activeGCodes.value)

def CncGetCurrentMcodesText():
    c_activeMCodes = create_string_buffer(80)
    _mydll.CncGetCurrentMcodesText(c_activeMCodes)
    return (CNC_RC_OK, c_activeMCodes.value)

def CncGetCurrentGcodeSettingsText():
    c_actualGCodeSettings = create_string_buffer(80)
    _mydll.CncGetCurrentGcodeSettingsText(c_actualGCodeSettings)
    return (CNC_RC_OK, c_actualGCodeSettings.value)

def CncGetProgrammedSpeed():
    retval = _mydll.CncGetProgrammedSpeed()
    return (retval)

def CncGetProgrammedFeed():
    retval = _mydll.CncGetProgrammedFeed()
    return (retval)

def CncGetCurrentToolNumber():
    retval = _mydll.CncGetCurrentToolNumber()
    return (retval)

def CncG43Active():
    retval = _mydll.CncG43Active()
    return (retval)

def CncG95Active():
    retval = _mydll.CncG95Active()
    return (retval)

def CncGetCurInterpreterLineNumber():
    retval = _mydll.CncGetCurInterpreterLineNumber()
    return (retval)

def CncGetCurInterpreterLineText():
    c_text = create_string_buffer(CNC_MAX_INTERPRETER_LINE)
    retval = _mydll.CncGetCurInterpreterLineText(c_text)
    return (retval, c_text.value)

def CncCurrentInterpreterLineContainsToolChange():
    retval = _mydll.CncCurrentInterpreterLineContainsToolChange()
    return (retval)

def CncGetSwLimitError():
    retval = _mydll.CncGetSwLimitError()
    return (retval)

def CncGetFifoError():
    retval = _mydll.CncGetFifoError()
    return (retval)

def CncGetEMStopActive():
    retval = _mydll.CncGetEMStopActive()
    return (retval)

def CncGetAllAxesHomed():
    retval = _mydll.CncGetAllAxesHomed()
    return (retval)

def CncGetSafetyMode():
    retval = _mydll.CncGetSafetyMode()
    return (retval)

def CncKinGetActiveType():
    retval = _mydll.CncKinGetActiveType()
    return (retval)

def CncKinActivate(active):
    c_active = c_int(active)
    retval = _mydll.CncKinActivate(c_active)
    return (retval)

def CncKinInit():
    retval = _mydll.CncKinInit()
    return (retval)

def CncKinControl(controlID):
    c_controlID = c_int(controlID)
    c_pControlData = KIN_CONTROLDATA()
    retval = _mydll.CncKinControl(c_controlID, byref(c_pControlData))
    return (retval, c_pControlData.value)

def CncKinGetARotationPoint():
    retval = _mydll.CncKinGetARotationPoint()
    return (CNC_VECTOR)

def CncGetIOName(id):
    c_id = c_int(id)
    retval = _mydll.CncGetIOName(c_id)
    return (retval)

def CncGetOutput(id):
    c_id = c_int(id)
    retval = _mydll.CncGetOutput(c_id)
    return (retval)

def CncGetOutputRaw(id):
    c_id = c_int(id)
    retval = _mydll.CncGetOutputRaw(c_id)
    return (retval)

def CncGetGPIOOutput(gpioCardIndex, ioId):
    c_gpioCardIndex = c_int(gpioCardIndex)
    c_ioId = c_int(ioId)
    retval = _mydll.CncGetGPIOOutput(c_gpioCardIndex, c_ioId)
    return (retval)

def CncGetInput(id):
    c_id = c_int(id)
    retval = _mydll.CncGetInput(c_id)
    return (retval)

def CncGetInputRaw(id):
    c_id = c_int(id)
    retval = _mydll.CncGetInputRaw(c_id)
    return (retval)

def CncGetGPIOInput(gpioCardIndex, ioId):
    c_gpioCardIndex = c_int(gpioCardIndex)
    c_ioId = c_int(ioId)
    retval = _mydll.CncGetGPIOInput(c_gpioCardIndex, c_ioId)
    return (retval)

def CncSetOutput(id, value):
    c_id = c_int(id)
    c_value = c_int(value)
    retval = _mydll.CncSetOutput(c_id, c_value)
    return (retval)

def CncSetOutputRaw(id, value):
    c_id = c_int(id)
    c_value = c_int(value)
    retval = _mydll.CncSetOutputRaw(c_id, c_value)
    return (retval)

def CncSetGPIOOutput(gpioCardIndex, ioId, value):
    c_gpioCardIndex = c_int(gpioCardIndex)
    c_ioId = c_int(ioId)
    c_value = c_int(value)
    retval = _mydll.CncSetGPIOOutput(c_gpioCardIndex, c_ioId, c_value)
    return (retval)

def CncCheckStartConditionOK(generateMessage, ignoreHoming):
    c_generateMessage = c_int(generateMessage)
    c_ignoreHoming = c_int(ignoreHoming)
    c_result = c_int()
    retval = _mydll.CncCheckStartConditionOK(c_generateMessage, c_ignoreHoming, byref(c_result))
    return (retval, c_result.value)

def CncSetSpindleOutput(onOff, direction, absSpeed):
    c_onOff = c_int(onOff)
    c_direction = c_int(direction)
    c_absSpeed = c_double(absSpeed)
    retval = _mydll.CncSetSpindleOutput(c_onOff, c_direction, c_absSpeed)
    return (retval)

def CncLogFifoGet():
    c_data = CNC_LOG_MESSAGE()
    retval = _mydll.CncLogFifoGet(byref(c_data))
    return (retval, c_data.value)

def CncPosFifoGet():
    c_data = CNC_POS_FIFO_DATA()
    retval = _mydll.CncPosFifoGet(byref(c_data))
    return (retval, c_data.value)

def CncPosFifoGet2():
    c_data = CNC_POS_FIFO_DATA()
    c_isLast = c_int()
    retval = _mydll.CncPosFifoGet2(byref(c_data), byref(c_isLast))
    return (retval, c_data.value, c_isLast.value)

def CncGraphFifoGet():
    c_data = CNC_GRAPH_FIFO_DATA()
    retval = _mydll.CncGraphFifoGet(byref(c_data))
    return (retval, c_data.value)

def CncReset():
    retval = _mydll.CncReset()
    return (retval)

def CncReset2(resetFlags):
    c_resetFlags = c_uint(resetFlags)
    retval = _mydll.CncReset2(c_resetFlags)
    return (retval)

def CncRunSingleLine(text):
    c_text = c_char_p()
    c_text.value = str.encode(text)
    retval = _mydll.CncRunSingleLine(c_text)
    return (retval)

def CncWaitSingleLine(pKeepAlive, pKeepAliveParameter):
    c_pKeepAlive = CNC_KEEP_UI_ALIVE_FUNCTION(pKeepAlive)
    c_pKeepAliveParameter = c_void_p(pKeepAliveParameter)
    retval = _mydll.CncWaitSingleLine(c_pKeepAlive, byref(c_pKeepAliveParameter))
    return (retval)

def CncLoadJobW(fileName):
    c_fileName = c_wchar_p(fileName)
    retval = _mydll.CncLoadJobW(c_fileName)
    return (retval)

def CncLoadJobA(fileName):
    c_fileName = c_char_p()
    c_fileName.value = str.encode(fileName)
    retval = _mydll.CncLoadJobA(c_fileName)
    return (retval)

def CncRunOrResumeJob():
    retval = _mydll.CncRunOrResumeJob()
    return (retval)

def CncStartRenderGraph(outLines, contour):
    c_outLines = c_int(outLines)
    c_contour = c_int(contour)
    retval = _mydll.CncStartRenderGraph(c_outLines, c_contour)
    return (retval)

def CncStartRenderSearch(outLines, contour, lineNr, toolNr, arrayX, arrayY):
    c_outLines = c_int(outLines)
    c_contour = c_int(contour)
    c_lineNr = c_int(lineNr)
    c_toolNr = c_int(toolNr)
    c_arrayX = c_int(arrayX)
    c_arrayY = c_int(arrayY)
    retval = _mydll.CncStartRenderSearch(c_outLines, c_contour, c_lineNr, c_toolNr, c_arrayX, c_arrayY)
    return (retval)

def CncRewindJob():
    retval = _mydll.CncRewindJob()
    return (retval)

def CncAbortJob():
    retval = _mydll.CncAbortJob()
    return (retval)

def CncSetJobArrayParameters(runJobData):
    c_runJobData = CNC_CMD_ARRAY_DATA(runJobData)
    retval = _mydll.CncSetJobArrayParameters(byref(c_runJobData))
    return (retval)

def CncGetJobArrayParameters():
    c_runJobData = CNC_CMD_ARRAY_DATA()
    retval = _mydll.CncGetJobArrayParameters(byref(c_runJobData))
    return (retval, c_runJobData.value)

def CncGetJobMaterialSize():
    retval = _mydll.CncGetJobMaterialSize()
    return (CNC_VECTOR)

def CncGetJobFiducual(n):
    c_n = c_int(n)
    c_fiducial = CNC_FIDUCIAL_DATA()
    retval = _mydll.CncGetJobFiducual(c_n, byref(c_fiducial))
    return (retval, c_fiducial.value)

def CncEnableBlockDelete(enable):
    c_enable = c_int(enable)
    retval = _mydll.CncEnableBlockDelete(c_enable)
    return (retval)

def CncGetBlocDelete():
    retval = _mydll.CncGetBlocDelete()
    return (retval)

def CncEnableOptionalStop(enable):
    c_enable = c_int(enable)
    retval = _mydll.CncEnableOptionalStop(c_enable)
    return (retval)

def CncGetOptionalStop():
    retval = _mydll.CncGetOptionalStop()
    return (retval)

def CncSingleStepMode(enable):
    c_enable = c_int(enable)
    retval = _mydll.CncSingleStepMode(c_enable)
    return (retval)

def CncGetSingleStepMode():
    retval = _mydll.CncGetSingleStepMode()
    return (retval)

def CncSetExtraJobOptions(extraLine, doRepeat, numberOfRepeats):
    c_extraLine = c_char_p()
    c_extraLine.value = str.encode(extraLine)
    c_doRepeat = c_int(doRepeat)
    c_numberOfRepeats = c_uint(numberOfRepeats)
    retval = _mydll.CncSetExtraJobOptions(c_extraLine, c_doRepeat, c_numberOfRepeats)
    return (retval)

def CncGetExtraJobOptions(extraLine):
    c_extraLine = c_char_p()
    c_extraLine.value = str.encode(extraLine)
    c_doRepeat = c_int()
    c_numberOfRepeats = c_uint()
    _mydll.CncGetExtraJobOptions(c_extraLine, byref(c_doRepeat), byref(c_numberOfRepeats))
    return (CNC_RC_OK, c_doRepeat.value, c_numberOfRepeats.value)

def CncSetSimulationMode(enable):
    c_enable = c_int(enable)
    retval = _mydll.CncSetSimulationMode(c_enable)
    return (retval)

def CncGetSimulationMode():
    retval = _mydll.CncGetSimulationMode()
    return (retval)

def CncSetFeedOverride(factor):
    c_factor = c_double(factor)
    retval = _mydll.CncSetFeedOverride(c_factor)
    return (retval)

def CncSetArcFeedOverride(factor):
    c_factor = c_double(factor)
    retval = _mydll.CncSetArcFeedOverride(c_factor)
    return (retval)

def CncGetActualFeedOverride():
    retval = _mydll.CncGetActualFeedOverride()
    return (retval)

def CncGetActualArcFeedOverride():
    retval = _mydll.CncGetActualArcFeedOverride()
    return (retval)

def CncGetActualFeed():
    retval = _mydll.CncGetActualFeed()
    return (retval)

def CncSetSpeedOverride(factor):
    c_factor = c_double(factor)
    retval = _mydll.CncSetSpeedOverride(c_factor)
    return (retval)

def CncGetActualSpeedOverride():
    retval = _mydll.CncGetActualSpeedOverride()
    return (retval)

def CncGetActualSpeed():
    retval = _mydll.CncGetActualSpeed()
    return (retval)

def CncFindFirstJobLine():
    c_text = create_string_buffer(256)
    c_endOfJob = c_int()
    c_totNumOfLines = c_int()
    retval = _mydll.CncFindFirstJobLine(c_text, byref(c_endOfJob), byref(c_totNumOfLines))
    return (retval, c_text.value, c_endOfJob.value)

def CncFindFirstJobLineF():
    c_text = create_string_buffer(256)
    c_endOfJob = c_int()
    retval = _mydll.CncFindFirstJobLineF(c_text, byref(c_endOfJob))
    return (retval, c_text.value, c_endOfJob.value)

def CncFindNextJobLine():
    c_text = create_string_buffer(256)
    c_endOfJob = c_int()
    retval = _mydll.CncFindNextJobLine(c_text, byref(c_endOfJob))
    return (retval, c_text.value, c_endOfJob.value)

def CncFindNextJobLineF():
    c_text = create_string_buffer(256)
    c_endOfJob = c_int()
    retval = _mydll.CncFindNextJobLineF(c_text, byref(c_endOfJob))
    return (retval, c_text.value, c_endOfJob.value)

def CncSwitchOnSpindleAndWaitUntilOn(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSwitchOnSpindleAndWaitUntilOn(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncPauseJob():
    retval = _mydll.CncPauseJob()
    return (retval)

def CncPauseJob2(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncPauseJob2(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncPauseZSafe():
    retval = _mydll.CncSyncPauseZSafe()
    return (retval)

def CncSyncPauseXSafe():
    retval = _mydll.CncSyncPauseXSafe()
    return (retval)

def CncSyncPauseAxis(axis, feed):
    c_axis = c_int(axis)
    c_feed = c_double(feed)
    retval = _mydll.CncSyncPauseAxis(c_axis, c_feed)
    return (retval)

def CncSyncFromPauseAndStartAutomatic(approachFeed, pFunc, pFuncParameter):
    c_approachFeed = c_double(approachFeed)
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncFromPauseAndStartAutomatic(c_approachFeed, c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncSearchZSafe(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncSearchZSafe(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncSearchXSafe(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncSearchXSafe(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncSearchTool(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncSearchTool(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncInchModeAndParametersAndOffset(pFunc, pFuncParameter):
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncInchModeAndParametersAndOffset(c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncSearchAxis(axis, feed, pFunc, pFuncParameter):
    c_axis = c_int(axis)
    c_feed = c_double(feed)
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncSearchAxis(c_axis, c_feed, c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncSyncFromSearchAndStartAutomatic(approachFeed, pFunc, pFuncParameter):
    c_approachFeed = c_double(approachFeed)
    c_pFunc = CNC_KEEP_UI_ALIVE_FUNCTION(pFunc)
    c_pFuncParameter = c_void_p(pFuncParameter)
    retval = _mydll.CncSyncFromSearchAndStartAutomatic(c_approachFeed, c_pFunc, byref(c_pFuncParameter))
    return (retval)

def CncStartJog(axes, velocityFactor, continuous):
    c_axes = double(axes)
    c_velocityFactor = c_double(velocityFactor)
    c_continuous = c_int(continuous)
    retval = _mydll.CncStartJog(byref(c_axes), c_velocityFactor, c_continuous)
    return (retval)

def CncStartJog2(axis, step, velocityFactor, continuous):
    c_axis = c_int(axis)
    c_step = c_double(step)
    c_velocityFactor = c_double(velocityFactor)
    c_continuous = c_int(continuous)
    retval = _mydll.CncStartJog2(c_axis, c_step, c_velocityFactor, c_continuous)
    return (retval)

def CncStopJog(axis):
    c_axis = c_int(axis)
    retval = _mydll.CncStopJog(c_axis)
    return (retval)

def CncMoveTo(pos, move, velocityFactor):
    c_pos = pos
    c_move = move
    c_velocityFactor = c_double(velocityFactor)
    retval = _mydll.CncMoveTo(c_pos, c_move, c_velocityFactor)
    return (retval)

def CncStartPositionTracking():
    retval = _mydll.CncStartPositionTracking()
    return (retval)

def CncStartVelocityTracking():
    retval = _mydll.CncStartVelocityTracking()
    return (retval)

def CncStartHandweelTracking(axis, vLimit, handwheelID, velMode, multiplicationFactor, handwheelCountsPerRevolution):
    c_axis = c_int(axis)
    c_vLimit = c_double(vLimit)
    c_handwheelID = c_int(handwheelID)
    c_velMode = c_int(velMode)
    c_multiplicationFactor = c_double(multiplicationFactor)
    c_handwheelCountsPerRevolution = c_int(handwheelCountsPerRevolution)
    retval = _mydll.CncStartHandweelTracking(c_axis, c_vLimit, c_handwheelID, c_velMode, c_multiplicationFactor, c_handwheelCountsPerRevolution)
    return (retval)

def CncSetTrackingPosition(pos, vel, move):
    c_pos = pos
    c_vel = vel
    c_move = move
    retval = _mydll.CncSetTrackingPosition(c_pos, c_vel, c_move)
    return (retval)

def CncSetTrackingPosition2(pos, vel, acc, move):
    c_pos = pos
    c_vel = vel
    c_acc = acc
    c_move = move
    retval = _mydll.CncSetTrackingPosition2(c_pos, c_vel, c_acc, c_move)
    return (retval)

def CncSetTrackingVelocity(vel, move):
    c_vel = vel
    c_move = move
    retval = _mydll.CncSetTrackingVelocity(c_vel, c_move)
    return (retval)

def CncSetTrackingVelocity2(vel, acc, axes):
    c_vel = vel
    c_acc = acc
    c_axes = axes
    retval = _mydll.CncSetTrackingVelocity2(c_vel, c_acc, c_axes)
    return (retval)

def CncSetTrackingHandwheelCounter(hw1Count, hw2Count, hw3Count):
    c_hw1Count = c_int(hw1Count)
    c_hw2Count = c_int(hw2Count)
    c_hw3Count = c_int(hw3Count)
    retval = _mydll.CncSetTrackingHandwheelCounter(c_hw1Count, c_hw2Count, c_hw3Count)
    return (retval)

def CncStartPlasmaTHCTracking(pLimit, nLimit):
    c_pLimit = c_double(pLimit)
    c_nLimit = c_double(nLimit)
    retval = _mydll.CncStartPlasmaTHCTracking(c_pLimit, c_nLimit)
    return (retval)

def CncSetPlasmaParameters(thcCfg):
    c_thcCfg = thcCfg
    retval = _mydll.CncSetPlasmaParameters(c_thcCfg)
    return (retval)

def CncGetPlasmaParameters():
    retval = _mydll.CncGetPlasmaParameters()
    return (retval.contents)

def CncStopTracking():
    retval = _mydll.CncStopTracking()
    return (retval)

def Cnc3DPrintCommand(pCmd):
    c_pCmd = CNC_3DPRINTING_COMMAND(pCmd)
    retval = _mydll.Cnc3DPrintCommand(byref(c_pCmd))
    return (retval)

def CncGetRCText(rc):
    c_rc = c_int(rc)
    retval = _mydll.CncGetRCText(c_rc)
    return (retval)

def CncSendUserMessage(functionName, fileName, lineNumber, ec, rc, msg):
    c_functionName = c_char_p()
    c_functionName.value = str.encode(functionName)
    c_fileName = c_char_p()
    c_fileName.value = str.encode(fileName)
    c_lineNumber = c_int(lineNumber)
    c_ec = c_int(ec)
    c_rc = c_int(rc)
    c_msg = c_char_p()
    c_msg.value = str.encode(msg)
    _mydll.CncSendUserMessage(c_functionName, c_fileName, c_lineNumber, c_ec, c_rc, c_msg)
    return (CNC_RC_OK)

def CncSendToGUI(action, value1, value2):
    c_action = c_int(action)
    c_value1 = c_int(value1)
    c_value2 = c_int(value2)
    retval = _mydll.CncSendToGUI(c_action, c_value1, c_value2)
    return (retval)

def CncGetGUICommand():
    c_pAction = c_int()
    c_pValue1 = c_int()
    c_pValue2 = c_int()
    retval = _mydll.CncGetGUICommand(byref(c_pAction), byref(c_pValue1), byref(c_pValue2))
    return (retval, c_pAction.value, c_pValue1.value, c_pValue2.value)

