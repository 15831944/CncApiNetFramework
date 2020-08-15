from ctypes import c_void_p, c_char_p, c_int, c_short, c_char, c_long, c_uint, c_bool, c_double, c_ulong, c_float, Structure, c_wchar, c_wchar_p, POINTER, c_ubyte, Union, create_string_buffer, byref
from cncapi.cncdefines import *
from cncapi.cncenums import *

class KIN_CONTROLDATA(Union):
    _pack_ = 1
    _fields_ = [
        ( "dData", c_double * 12 ),
        ( "iData", c_int * 12 ),
        ( "cData", c_char * 64 ),
    ]

class CNC_CART_BOOL(Structure):
    _pack_ = 1
    _fields_ = [
        ( "x", c_int ),
        ( "y", c_int ),
        ( "z", c_int ),
        ( "a", c_int ),
        ( "b", c_int ),
        ( "c", c_int ),
    ]

class CNC_JOINT_BOOL(Structure):
    _pack_ = 1
    _fields_ = [
        ( "jx", c_int ),
        ( "jy", c_int ),
        ( "jz", c_int ),
        ( "ja", c_int ),
        ( "jb", c_int ),
        ( "jc", c_int ),
    ]

class CNC_CART_DOUBLE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "x", c_double ),
        ( "y", c_double ),
        ( "z", c_double ),
        ( "a", c_double ),
        ( "b", c_double ),
        ( "c", c_double ),
    ]

class CNC_VECTOR(Structure):
    _pack_ = 1
    _fields_ = [
        ( "x", c_double ),
        ( "y", c_double ),
        ( "z", c_double ),
    ]

class CNC_JOINT_DOUBLE(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class CNC_CIRCLE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "center", CNC_VECTOR ),
        ( "normal", CNC_VECTOR ),
        ( "rTan", CNC_VECTOR ),
        ( "rPerp", CNC_VECTOR ),
        ( "rHelix", CNC_VECTOR ),
        ( "radius", c_double ),
        ( "angle", c_double ),
        ( "spiral", c_double ),
    ]

class CNC_OFFSET_AND_PLANE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "g5xOffset", CNC_CART_DOUBLE ), #            /* G54 .. G59.3         */
        ( "currentG5X", c_int ), #           /* active coord. syst. index G54:0 .. G59.3:8 */
        ( "g92Offset", CNC_CART_DOUBLE ), #            /* G92                  */
        ( "spindleConfigOffset", CNC_CART_DOUBLE ), #  /* M90, M91, M92, M93   */
        ( "spOffsetIndex", c_int ), #        /* M90:0 .. M93:3       */
        ( "totalOffset", CNC_CART_DOUBLE ), #          /* Sum of the 3 above   */
        ( "toolOffset", CNC_VECTOR ), #           /* G43                  */
        ( "g43ToolNumber", c_int ), #        /* tool number for G43, can be different from actual tool ! */
        ( "XYRotationDegrees", c_double ), #    /* G68                  */
        ( "XYRotationActive", c_int ), #     /* G68                  */
        ( "XZRotationDegrees", c_double ), #    /* G68                  */
        ( "XZRotationActive", c_int ), #     /* G68                  */
        ( "YZRotationDegrees", c_double ), #    /* G68                  */
        ( "YZRotationActive", c_int ), #     /* G68                  */
        ( "RotationBasePoint", CNC_VECTOR ), #    /* G68                  */
        ( "XYScalingActive", c_int ), #      /* G51                  */
        ( "XYScalingFactor", CNC_VECTOR ), #      /* G51                  */
        ( "activePlane", c_int ), #          /* G17, G18, G19        */
    ]

class CALC_KIN_LIN_VA_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "start", CNC_CART_DOUBLE ), #	    //Start pos Cartesian
        ( "end", CNC_CART_DOUBLE ), #		//End pos Cartesian
        ( "vRequest", c_double ), #   //Feed from interpreter F value
        ( "type", c_int ), #     //Kin movement type
        ( "delta", CNC_CART_DOUBLE ), #    //delta absolute start - end
        ( "deltaXYZ", c_double ), # //Delta XYZ, Pythagoras
        ( "deltaABC", c_double ), # //Delta ABC, Pythagoras
        ( "offsetAndPlane", CNC_OFFSET_AND_PLANE ),
        ( "startJoint", CNC_JOINT_DOUBLE ), #//Start pos joint
        ( "endJoint", CNC_JOINT_DOUBLE ), #	//End pos joint
        ( "jointDelta", CNC_JOINT_DOUBLE ),
        ( "vMax", c_double ), #		//V max Cartesian possible
        ( "vel", c_double ), #      //Velocity Cartesian to be used for motion, limited from vRequest
        ( "aMax", c_double ), #		//Acceleration Cartesian
        ( "linearIsLeading", c_bool ), #	//True if linear is leading and speed is linear
    ]

class CNC_CMD_ARRAY_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "doArray", c_int ), #				//1 if nesting switched on
        ( "arrayStartOffsetX", c_double ), #     //All objects are offset by this
        ( "arrayStartOffsetY", c_double ), #     //All objects are offset by this
        ( "arrayDX", c_double ), #				//Shift (mm) for X
        ( "arrayDY", c_double ), #				//Shift (mm) for y
        ( "arrayNX", c_int ), #				//Number in x
        ( "arrayNY", c_int ), #				//Number in y
        ( "materialSizeX", c_double ), #         //Only used with GetJobArrayParameters
        ( "materialSizeY", c_double ), #         //Only used with GetJobArrayParameters
        ( "materialSizeZ", c_double ), #         //Only used with GetJobArrayParameters
    ]

class CNC_FIDUCIAL_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "fidn", c_int ), #   //%fidn=... number, -1 if not valid
        ( "fidt", c_int ), #	//%fidt=... type
        ( "fidcx", c_double ), #	//%fidcx=.. coordinate x
        ( "fidcy", c_double ), #	//%fidcy=.. coordinate y
        ( "fidox", c_double ), #  //%fidox=.. offset x
        ( "fidoy", c_double ), #  //%fidoy=.. offset y
        ( "fidor", c_double ), #	//%fidor=.. orientation
    ]

class CNC_CMD_JOB_PROLOG_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "prologEnable", c_int ), #				//0=no prolog, 1=prolog
        ( "prologChangeTool", c_int ), #			//Perform change tool with given tool before start of job
        ( "prologMoveToPlanePosition", CNC_CART_DOUBLE ), # //Perform XY positioning with Z at safe height (G17)
        ( "prologFlood", c_int ), #               //1=flood on, 0-flood off, -1 leave as is
        ( "prologMist", c_int ), #                //Idem for mist
        ( "prologSpindle", c_int ), #             //3 turn right, 4 turn left
        ( "prologSpeed", c_double ), #				//Spindle speed
        ( "prologPlungeFeed", c_int ), #          //Feed for Z down (G17)
        ( "prologPlungePos", c_double ), #           //Z down position
        ( "prologFeed", c_double ), #				//Feed after plunge.
    ]

class CNC_USER_BUTTON(Structure):
    _pack_ = 1
    _fields_ = [
        ( "enabled", c_int ),
        ( "iconFileName", c_char * CNC_MAX_PATH ),
    ]

class CNC_LOG_MESSAGE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "code", c_int ),
        ( "errorClass", c_int ),
        ( "subCode", c_int ),
        ( "text", c_char * CNC_MAX_LOGGING_TEXT ),
        ( "par1Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par2Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par3Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par4Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par5Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par6Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par7Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par8Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par9Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par10Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par11Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par12Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par13Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par14Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par15Name", c_char * CNC_MAX_NAME_LENGTH ),
        ( "par1Number", c_int ),
        ( "par2Number", c_int ),
        ( "par3Number", c_int ),
        ( "par4Number", c_int ),
        ( "par5Number", c_int ),
        ( "par6Number", c_int ),
        ( "par7Number", c_int ),
        ( "par8Number", c_int ),
        ( "par9Number", c_int ),
        ( "par10Number", c_int ),
        ( "par11Number", c_int ),
        ( "par12Number", c_int ),
        ( "par13Number", c_int ),
        ( "par14Number", c_int ),
        ( "par15Number", c_int ),
        ( "sourceInfo", c_char * CNC_MAX_SOURCE_INFO_TEXT ),
        ( "functionName", c_char * CNC_MAX_FUNCTION_NAME_TEXT ),
        ( "timeStamp", c_int ),
        ( "n", c_int ),
        ( "hint", c_int ),
    ]

class CNC_JOINT_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "name", c_char ),
        ( "isVisible", c_int ), #      //True if axis visible in GUI
        ( "cpuPortIndex", c_int ), #   //0-5 for 6 axes board, -1 if not used
        ( "resolution", c_double ),
        ( "positiveLimit", c_double ),
        ( "negativeLimit", c_double ),
        ( "maxVelocity", c_double ),
        ( "maxAcceleration", c_double ),
        ( "homeVelocity", c_double ), #     //Sign is direction
        ( "homeVelocitySlow", c_double ), # //Slow vel for 2nd move
        ( "homePosition", c_double ), #     //Position at home sensor
        ( "backLash", c_double ),
        ( "lowSpeedJogPercent", c_double ),
        ( "medSpeedJogPercent", c_double ),
        ( "highSpeedJogPercent", c_double ),
        ( "pitchCompensationFileName", c_char * CNC_MAX_PATH ),
        ( "pitchCompensationOn", c_int ),
        ( "crossCompensationFileName", c_char * CNC_MAX_PATH ),
        ( "crossCompensationFromAxis", c_int ), # /* 0 or 1 meaning X or Y, all other values invalid */
    ]

class CNC_KIN_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "axesInUse", CNC_CART_BOOL ), #	    //True if axis in use
        ( "axesVisible", CNC_CART_BOOL ), #	    //True if visible (implies inUse)
        ( "jointInUse", CNC_JOINT_BOOL ), #	//0-5 for 6 axes board. -1 if not connected
        ( "jointVisible", CNC_JOINT_BOOL ), #//True if visible
        ( "jointIsSlave", CNC_JOINT_BOOL ), #//True if a joint is slave
        ( "aAxisOption", c_int ),
        ( "bAxisOption", c_int ),
        ( "cAxisOption", c_int ),
        ( "kinematicsDLLName", c_char * CNC_MAX_PATH ),
        ( "maxCartesianVelocity", CNC_CART_DOUBLE ),
        ( "maxCartesianAcceleration", CNC_CART_DOUBLE ),
        ( "positiveCartesianLimit", CNC_CART_DOUBLE ),
        ( "negativeCartesianLimit", CNC_CART_DOUBLE ),
        ( "maxJointVelocity", CNC_JOINT_DOUBLE ),
        ( "maxJointAcceleration", CNC_JOINT_DOUBLE ),
        ( "positiveJointLimit", CNC_JOINT_DOUBLE ),
        ( "negativeJointLimit", CNC_JOINT_DOUBLE ),
        ( "zDownToolLength", c_double ),
        ( "positiveLimitTCA", CNC_CART_DOUBLE ),
        ( "negativeLimitTCA", CNC_CART_DOUBLE ),
        ( "disableZToolCollisionGuard", c_int ),
        ( "aAxisRotationPointIsCalibrated", c_int ),
        ( "aAxisCalibratedRotationPoint", CNC_VECTOR ),
        ( "aAxisCylinderRadiusIsCalibrated", c_int ),
        ( "aAxisCalibratedCilinderRadius", c_double ),
        ( "linDeltaArmLength", c_double ),
        ( "linDeltaRadius", c_double ),
        ( "linDeltaSafetyRadius", c_double ),
        ( "machineType", c_int ),
        ( "userOutputStartVariable", c_int ),
        ( "userOutputNumVariables", c_int ),
    ]

class CNC_TAN_KNIFE_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "tanKnifeIsOn", c_int ),
        ( "tanknifeBending", c_int ),
        ( "tanKnifeBCMapping", c_int ),
        ( "tanknifeZloMachine", c_double ),
        ( "tanknifeZhiMachine", c_double ),
    ]

class CNC_KIN_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "m_activeToolOffset", CNC_VECTOR ), # //Always active tool value, not related to G43/G49
        ( "m_kinType", c_int ),
        ( "m_version", c_char * CNC_MAX_NAME_LENGTH ), # //Read from DLL
        ( "m_kinActive", c_int ), #   //1 of active
        ( "m_offsetAndPlane", CNC_OFFSET_AND_PLANE ),
        ( "m_actConfig", CNC_KIN_CFG ),
        ( "m_tanknifeSts", CNC_TAN_KNIFE_STATUS ),
        ( "m_mcaActive", c_int ),
        ( "m_tcaActive", c_int ),
    ]

class CNC_VACUUMBED_SECTION_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "sectionOutputNumber", c_int ), #   //0=none, 1 = AUX1, 2=AUX2 ... 101 = GPIO 1 etc
        ( "sectionPumpOutputNumber", c_int ), #      //To which pump belongs this section, multiple section svan have the same pump.
        ( "sectionXPosition", c_double ),
        ( "sectionYPosition", c_double ),
        ( "sectionXWidth", c_double ),
        ( "sectionYWidth", c_double ),
    ]

class CNC_VACUUMBED_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "automaticMode", c_int ), #	     //0=off, 1=Determine sections while rendering.
        ( "numberOfSections", c_int ),
        ( "vacuumBedSectionData", CNC_VACUUMBED_SECTION_DATA * CNC_MAX_VACUUMBED_SECTIONS ),
    ]

class CNC_CAMERA_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "cameraOn", c_int ), #	     //o=off, 1=on
        ( "cameraIndex", c_int ), #      //0 is first, 1 is second etc.
        ( "cameraFlip", c_int ),
        ( "cameraMirror", c_int ),
        ( "cameraRotationAngle", c_int ),
    ]

class CNC_TOOL_DATA_INTERNAL(Structure):
    _pack_ = 1
    _fields_ = [
        ( "id", c_int ),
        ( "description", c_char * 80 ),
        ( "diameterIndex", c_int ), #	    //Variable index 5400 .. 5499
        ( "zOffsetIndex", c_int ), #	    //Variable index 5500 .. 5599
        ( "xOffsetIndex", c_int ), #	    //Variable index 5600 .. 5699
        ( "orientationIndex", c_int ), #   //Variable index 5700 .. 5799
        ( "xDeltaIndex", c_int ), #         //Variable index 5800 .. 5899
        ( "zDeltaIndex", c_int ), #         //Variable index 5900 .. 5999
        ( "locationCode", c_int ),
    ]

class CNC_TOOL_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "id", c_int ),
        ( "locationCode", c_int ),
        ( "description", c_char * 80 ),
        ( "diameter", c_double ), #	//Variable index 5400 .. 5499
        ( "zOffset", c_double ), #    //Variable index 5500 .. 5599  (Length)
        ( "xOffset", c_double ), #    //Variable index 5600 .. 5699  (width, for turning)
        ( "zDelta", c_double ), #      //Variable index 5900 .. 5999
        ( "xDelta", c_double ), #      //Variable index 5800 .. 5899
        ( "orientation", c_int ),
    ]

class CNC_IO_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "invertAmpEnableOut", c_int ), #             // Amp enable inversion
        ( "invertAmpCurrentReduceOut", c_int ), #      // Current reduce inversion
        ( "delayMSAfterAmpenable", c_int ), #          // To be sure the amplifiers are really enabled before a movement can be started.
        ( "delayMSCurrentReduceOn", c_int ), #         // Delay between motion stop and current reduce on.
        ( "delayMSCurrentReduceOff", c_int ), #        // Delay between current reduce off and start motion.
        ( "invertToolOut", c_int ),
        ( "invertToolDirOut", c_int ),
        ( "invertFloodOut", c_int ),
        ( "invertMistOut", c_int ),
        ( "invertAux1Out", c_int ),
        ( "invertAux2Out", c_int ),
        ( "invertAux3Out", c_int ),
        ( "invertAux4Out", c_int ),
        ( "invertAux5Out", c_int ),
        ( "invertAux6Out", c_int ),
        ( "invertAux7Out", c_int ),
        ( "invertAux8Out", c_int ),
        ( "invertAux9Out", c_int ),
        ( "invertAux10Out", c_int ),
        ( "invertPwm1Out", c_int ),
        ( "invertPwm2Out", c_int ),
        ( "invertPwm3Out", c_int ),
        ( "invertPwm4Out", c_int ),
        ( "invertPwm5Out", c_int ),
        ( "invertPwm6Out", c_int ),
        ( "invertPwm7Out", c_int ),
        ( "invertPwm8Out", c_int ),
        ( "invertAux1In", c_int ),
        ( "invertAux2In", c_int ),
        ( "invertAux3In", c_int ),
        ( "invertAux4In", c_int ),
        ( "invertAux5In", c_int ),
        ( "invertAux6In", c_int ),
        ( "invertAux7In", c_int ),
        ( "invertAux8In", c_int ),
        ( "invertAux9In", c_int ),
        ( "invertAux10In", c_int ),
        ( "invertPauseIn", c_int ),
        ( "invertDriveErrIn", c_int ),
        ( "invertDriveWarnIn", c_int ),
        ( "invertAnalog1", c_int ),
        ( "invertAnalog2", c_int ),
        ( "invertAnalog3", c_int ),
        ( "invertAnalog4", c_int ),
        ( "invertAnalog5", c_int ),
        ( "invertAnalog6", c_int ),
        ( "invertAnalog7", c_int ),
        ( "invertAnalog8", c_int ),
        ( "nameExtErrIn", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameFloodOut", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameMistOut", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux1Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux2Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux3Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux4Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux5Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux6Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux7Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux8Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux9Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux10Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm1Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm2Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm3Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm4Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm5Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm6Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm7Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "namePwm8Out", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux1In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux2In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux3In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux4In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux5In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux6In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux7In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux8In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux9In", c_char * CNC_MAX_IO_NAME_LENGTH ),
        ( "nameAux10In", c_char * CNC_MAX_IO_NAME_LENGTH ),
    ]

class CNC_SPINDLE_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "spindleIndex", c_int ),
        ( "rampUpTime", c_double ),
        ( "rampDownTime", c_double ),
        ( "NmaxRPM", c_double ),
        ( "NminRPM", c_double ),
        ( "countPerRev", c_int ),
        ( "stepperMotorMode", c_int ),
        ( "smoothCountMode", c_int ),
        ( "useRPMSensor", c_int ),
        ( "onOffOutputPortID", c_int ),
        ( "directionOutputPortID", c_int ),
        ( "pwmOutputPortID", c_int ),
        ( "spindleReadyPortID", c_int ),
        ( "spindleReadyPortMode", c_int ),
        ( "rightOnLeftOnMNode", c_int ),
        ( "coordinateSystemOffset", CNC_VECTOR ),
        ( "pwmCompensationFileName", c_char * CNC_MAX_PATH ),
        ( "pwmCompensationOn", c_int ),
        ( "maxAvgSpeedFilterTimeMillisecs", c_int ),
        ( "sensorSpeedControlOn", c_int ),
        ( "sensorSpeedControlCycleTime", c_double ),
    ]

class CNC_FEEDSPEED_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "feedOverrideSource", c_int ),
        ( "speedOverrideSource", c_int ),
        ( "adaptiveSpindlePowerFeedOv", c_int ), #//only when on and spindle running not ramping
        ( "analogFeedOvAtMaxVoltage", c_double ), #  //Allow to adjust feeoOv by analog in as user wants it
        ( "analogFeedOvAtMinVoltage", c_double ), #  //User only needs to supply to give the feeoOv at max analog input
        ( "analogStopOnHigherThreshold", c_int ), # //Stop motion if analogue value goes above this value.
        ( "feedHoldInputPortID", c_int ),
        ( "speedHoldInputPortID", c_int ),
        ( "useAnalogFilter", c_int ),
    ]

class CNC_HANDWHEEL_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "handwheelCountPerRev", c_int ),
        ( "handweelVPercent", c_int ),
        ( "handwheelAPercent", c_int ),
        ( "handwheelX1VelMode", c_int ),
        ( "handwheelX10VelMode", c_int ),
        ( "handwheelX100VelMode", c_int ),
        ( "axisSelectAnInputPortID", c_int ),
        ( "mulfactorSelectAnInputPortID", c_int ),
        ( "handwheelType", c_int ),
    ]

class CNC_TRAFFIC_LIGHT_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "trafficLightGreenIOID", c_int ),
        ( "trafficLightYellowIOID", c_int ),
        ( "trafficLightRedIOID", c_int ),
        ( "trafficLightProgressPWMIOID", c_int ),
        ( "noFlashing", c_int ),
    ]

class CNC_PROBING_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "heightProbePresent", c_int ),
        ( "storeProbeTouchPoints", c_int ),
        ( "probeTouchPointFileName", c_char * CNC_MAX_PATH ),
        ( "probeBeep", c_int ),
        ( "probeUseHomeInput4", c_int ),
        ( "probeVoltIncToMM", c_double ),
        ( "probeDetectUnexpectedTrigger", c_int ),
    ]

class CNC_SAFETY_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "homeIsEstopAfterHomingAllAxes", c_int ),
        ( "EStopInputSenseLevel1", c_int ),
        ( "EStopInputSenseLevel2", c_int ),
        ( "driveWarningInputSenseLevel", c_int ),
        ( "driveErrorInputSenseLevel", c_int ),
        ( "isoInputSenseLevel", c_int ),
        ( "isoOutputSenseLevel", c_int ),
        ( "extErrorInputSenseLevel", c_int ),
        ( "auxInputCheckSenseLevel", c_int * CNC_MAX_AUX_GUARD_INPUTS ),
        ( "enableGPIOActions", c_int ),
        ( "atEStopLeaveGPIOAsIs", c_int ),
        ( "safetyFeed", c_double ),
        ( "safetySpeedPercent", c_double ),
        ( "safetyFeedOverridePercent", c_double ),
        ( "maxMasterSlaveDistance", c_double ),
        ( "useXHomeinputForAllAxes", c_int ),
        ( "endOfStrokeInputSenseLevel", c_int ),
        ( "mandatoryHoming", c_int ),
        ( "allowJoggingBeforeHoming", c_int ),
        ( "stopSpindleOnPause", c_int ),
        ( "noStartSpindleIfPauseActive", c_int ),
        ( "noStartJogIfPauseActive", c_int ),
        ( "noStartMDIIfPauseActive", c_int ),
        ( "noStartUserButtonIfPauseActive", c_int ),
        ( "aux1_OffOnPause", c_int ),
        ( "aux2_OffOnPause", c_int ),
        ( "aux3_OffOnPause", c_int ),
        ( "aux4_OffOnPause", c_int ),
        ( "aux5_OffOnPause", c_int ),
        ( "aux6_OffOnPause", c_int ),
        ( "aux7_OffOnPause", c_int ),
        ( "aux8_OffOnPause", c_int ),
        ( "aux9_OffOnPause", c_int ),
        ( "aux10_OffOnPause", c_int ),
        ( "mist_OffOnPause", c_int ),
        ( "flood_OffOnPause", c_int ),
        ( "autoStartAfterPause", c_int ),
        ( "zUpOnPause", c_int ),
        ( "zUpMoveDistanceOnPause", c_double ),
        ( "approachFeed", c_double ),
        ( "safetyRelayPresent", c_int ),
        ( "systemReadyOutPortID", c_int ),
        ( "safetyRelayResetOutPortID", c_int ),
        ( "safetyRelayResetDelayMs", c_int ),
        ( "safetyRelayPulseLengthMs", c_int ),
        ( "g28GuardPortID", c_int ),
    ]

class CNC_THC_PROCESS_PARAMETERS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "controlDelay", c_double ),
        ( "KPUp", c_double ),
        ( "KPDown", c_double ),
        ( "deadBand", c_double ),
        ( "KD", c_double ),
        ( "filterTime", c_double ),
        ( "holeDetectVoltage", c_double ),
        ( "holeDetectTime", c_double ),
        ( "cornerFeedFactor", c_double ),
        ( "zMax", c_double ),
        ( "zMin", c_double ),
        ( "thcON", c_int ),
        ( "measuredIsSetpoint", c_int ),
        ( "tuningMode", c_int ),
        ( "externalUpDownVelocity", c_double ),
    ]

class CNC_THC_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "processPars", CNC_THC_PROCESS_PARAMETERS ),
        ( "adcMulFactor", c_double ),
        ( "adcOffset", c_double ),
        ( "plasmaAnalogInputPortID", c_int ),
        ( "plasmaExternalZUPInputPortID", c_int ),
        ( "plasmaExternalZDownInputPortID", c_int ),
        ( "useExternalUpDownControl", c_int ),
    ]

class CNC_3DPRINTING_VOLT_TEMP_TUPLE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "volt", c_int ),
        ( "temp", c_float ),
    ]

class CNC_3DPRINTING_TEMP_CALIBRATION_TABLE(Structure):
    _pack_ = 1
    _fields_ = [
        ( "table", CNC_3DPRINTING_VOLT_TEMP_TUPLE * CNC_MAX_3D_TEMP_TABLE ),
        ( "actualTableSize", c_int ),
    ]

class CNC_3DPRINTING_TEMP_PID_PARS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "KP", c_float ),
        ( "KD", c_float ),
        ( "KI", c_float ),
        ( "maxIntegratorTerm", c_float ),
        ( "setPointReachedWindow", c_float ),
        ( "maxPower", c_float ),
        ( "maxTemp", c_float ),
        ( "standByTemp", c_float ),
        ( "sampleTime", c_float ),
        ( "setpointTemp", c_float ),
        ( "ignoreTempError", c_int ),
    ]

class CNC_3DPRINTING_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "extruderPIDPars", CNC_3DPRINTING_TEMP_PID_PARS ),
        ( "extruderVoltTempTable", CNC_3DPRINTING_TEMP_CALIBRATION_TABLE ),
        ( "extruderVoltTempTableFileName", c_char * CNC_MAX_PATH ),
        ( "heatBedPIDPars", CNC_3DPRINTING_TEMP_PID_PARS ),
        ( "heatBedVoltTempTable", CNC_3DPRINTING_TEMP_CALIBRATION_TABLE ),
        ( "heatBedVoltTempTableFileName", c_char * CNC_MAX_PATH ),
        ( "extruderPWMPort", c_int ), #          //PWM out 1-8
        ( "heatBedPWMPort", c_int ), #           //PWM out 1-8
        ( "workpieceFanPWMPort", c_int ), #      //PWM out 1-8
        ( "extruderTempInPort", c_int ), #       //Analog in 1-8
        ( "heatBedTempInPort", c_int ), #        //Analog in 1-8
        ( "workPieceFanStandbyPower", c_float ),
        ( "workPieceFanPowerTreshold", c_float ),
        ( "workpieceFanStartTimeSeconds", c_float ),
        ( "translateG0ToG1", c_int ),
    ]

class CNC_3DP_ONOFF_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "onOff", c_int ),
    ]

class CNC_3DP_FLOATVAL_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "value", c_float ),
    ]

class CNC_3DP_CMD_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "pidPars", CNC_3DPRINTING_TEMP_PID_PARS ),
        ( "onOffVal", CNC_3DP_ONOFF_DATA ),
        ( "floatVal", CNC_3DP_FLOATVAL_DATA ),
    ]

class CNC_3DPRINTING_COMMAND(Structure):
    _pack_ = 1
    _fields_ = [
        ( "cmdID", c_int ),
        ( "d", CNC_3DP_CMD_DATA ),
    ]

class CNC_3DPRINTING_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "extruderPIDPars", CNC_3DPRINTING_TEMP_PID_PARS ),
        ( "heatBedPIDPars", CNC_3DPRINTING_TEMP_PID_PARS ),
        ( "extruderSetPointTemp", c_float ),
        ( "extruderActualTemp", c_float ),
        ( "extruderHeatingPower", c_float ),
        ( "extruderOverride", c_float ),
        ( "extruderPIDIsON", c_int ),
        ( "extruderHeatingIsOn", c_int ),
        ( "extruderInStandByMode", c_int ),
        ( "extruderSetPointReached", c_int ),
        ( "heatBedSetPointTemp", c_float ),
        ( "heatBedActualTemp", c_float ),
        ( "heatBedHeatingPower", c_float ),
        ( "heatBedPIDIsON", c_int ),
        ( "heatBedHeatingIsOn", c_int ),
        ( "heatBedInStandByMode", c_int ),
        ( "heatBedSetPointReached", c_int ),
        ( "workPieceActualCoolFanPower", c_float ),
        ( "workPieceActualCoolFanPowerThreshold", c_float ),
        ( "workPieceCoolingFanIsOn", c_int ),
    ]

class CNC_TRAJECTORY_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "interpolationTime", c_double ),
        ( "fifoTime", c_double ),
        ( "minCircleSegmentSize", c_double ),
        ( "g1ShowsAsG0VelLimit", c_double ),
        ( "lafAngleFullSpeed", c_double ),
        ( "lafAngleReducedSpeed", c_double ),
        ( "lafDeltaReducedSpeed", c_double ),
        ( "lafAccFilter", c_double ),
        ( "lafArcfeedFactor", c_double ), # //Default arc feed factor
        ( "g0VelocityFactor", c_double ),
        ( "g0AccelelerationFactor", c_double ),
    ]

class CNC_INTERPRETER_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "g64pvalue", c_double ),
        ( "g64Active", c_int ),
        ( "longFileModeCriterion", c_int ),
        ( "superLongFileModeCriterion", c_int ),
        ( "macroFileName", c_char * CNC_MAX_PATH ),
        ( "userMacroFileName", c_char * CNC_MAX_PATH ),
        ( "initialString", c_char * CNC_MAX_INTERPRETER_LINE ),
        ( "g4InMilliseconds", c_int ),
        ( "inchModeActive", c_int ),
        ( "diameterProgramming", c_int ), #  /* Special for turning */
        ( "reverseG2G3", c_int ), #          /* also for turning */
        ( "absoluteCenterCoords", c_int ), # /* if 1, circle center coordinates are absolute */
        ( "fullCircleThetaEpsilon", c_double ), # /* used to determine full circle or not from startAngle and endAngle */
        ( "noHaltForToolChange", c_int ),
        ( "noHaltOnErrMsgDuringRender", c_int ),
        ( "tanKnifeAngleForLiftUp", c_double ),
        ( "tanKnifeBlendAngle", c_double ),
        ( "tanKnifeBlendDistance", c_double ),
        ( "tanKnifeLiftUpDistance", c_double ),
        ( "tanknifeBendingAngle", c_int ),
        ( "tanknifeZhiWork", c_double ),
        ( "tanknifeZloWork", c_double ),
        ( "tanknifeRewindTurns", c_int ),
    ]

class CNC_UI_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "language", c_int ),
        ( "useOpenGL", c_int ),
        ( "OpenGLRTMaxLines", c_int ),
        ( "openGlPenScaleFactor", c_double ),
        ( "gridScaleFactor", c_double ),
        ( "orthogonalView", c_int ),
        ( "backGroundColor", c_int ),
        ( "showG0MovesInGraphic", c_int ),
        ( "rotationDirectionAAxis", c_int ),
        ( "restoreWindowPosition", c_int ),
        ( "favoriteEditor", c_char * CNC_MAX_PATH ),
        ( "iconDirectory", c_char * CNC_MAX_PATH ),
        ( "logoFileName", c_char * CNC_MAX_PATH ),
        ( "setupPassword", c_char * 80 ),
        ( "simpleZeroing", c_int ),
        ( "useG10L20ForZeroing", c_int ),
        ( "watchLoadFileName", c_char * CNC_MAX_PATH ),
        ( "watchFileChanged", c_int ),
        ( "watchAutoLoad", c_int ),
        ( "watchAutoRun", c_int ),
        ( "watchAutoInterval", c_int ),
        ( "showTerms", c_int ),
        ( "showStartupScreen", c_int ),
        ( "showGraphZoomButtons", c_int ),
        ( "invertJogKeysX", c_int ),
        ( "invertJogKeysY", c_int ),
        ( "invertJogKeysZ", c_int ),
        ( "rotateXYJogkeys90", c_int ),
        ( "disableKeyboardJogging", c_int ),
        ( "useOldJogStepSize", c_int ),
        ( "keyBoardTimeOut", c_double ),
        ( "timeEstimateFactor", c_double ),
        ( "adjustEstimation", c_int ),
        ( "showM7key", c_int ),
        ( "showM8key", c_int ),
        ( "showAux1Key", c_int ),
        ( "showHomeToZero", c_int ),
        ( "showSpindleOnButton", c_int ),
        ( "showTrafficButton", c_int ),
        ( "showStartButton", c_int ),
        ( "showZeroButtons", c_int ),
        ( "showZeroButtonC", c_int ),
        ( "showPlasmaMinButton", c_int ),
        ( "showLeftUser11Button", c_int ),
        ( "showLeftUser12Button", c_int ),
        ( "showLeftUser13Button", c_int ),
        ( "showLeftUser14Button", c_int ),
        ( "showLeftUser15Button", c_int ),
        ( "showCoordinatesTab", c_int ),
        ( "showProgramTab", c_int ),
        ( "showToolTab", c_int ),
        ( "showVariablesTab", c_int ),
        ( "showIOTab", c_int ),
        ( "showFifoSize", c_int ),
        ( "showServiceTab", c_int ),
        ( "showUtilTab", c_int ),
        ( "showEngrave", c_int ),
        ( "showDrill", c_int ),
        ( "showOffset", c_int ),
        ( "showPocket", c_int ),
        ( "showICP", c_int ),
        ( "showWCCameraOption", c_int ),
        ( "clickDROIsG0", c_int ),
        ( "windowRectLeft", c_int ),
        ( "windowRectTop", c_int ),
        ( "windowRectRight", c_int ),
        ( "windowRectBottom", c_int ),
        ( "windowRestoreFlags", c_int ),
        ( "windowRestoreShowCmd", c_int ),
        ( "showInProgSpeed", c_int ),
        ( "showInProgSpeedAnaMulFactor", c_double ),
        ( "feedUnitsMMPerSecond", c_int ),
        ( "mmMode4digits", c_int ),
        ( "feedOVStepSize", c_double ),
        ( "allowJoggingWithDlg", c_int ),
        ( "overrideVersionText", c_char * CNC_MAX_NAME_LENGTH ),
        ( "QrScannerComportNumber", c_int ),
        ( "jobFolder", c_char * CNC_MAX_PATH ),
        ( "autoRenderAfterLoadingGCode", c_int ),
        ( "useExtendedUserButtons", c_int ),
        ( "extendedUserButtons", CNC_USER_BUTTON * CNC_MAX_USER_BUTTONS ),
    ]

class CNC_SYSTEM_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "serverPath", c_char * CNC_MAX_PATH ),
        ( "serverVersion", c_char * CNC_MAX_NAME_LENGTH ),
        ( "lastKnownServerVersion", c_char * CNC_MAX_NAME_LENGTH ),
        ( "lastKnownFirmwareVersion", c_char * CNC_MAX_NAME_LENGTH ),
        ( "newIniFileWasCreated", c_int ),
        ( "iniFileWasRestored", c_int ),
        ( "comPortName", c_char * CNC_COMMPORT_NAME_LEN ),
        ( "scanEthernet", c_int ),
        ( "nrOfJoints", c_int ),
        ( "controllerTimerDividerIndex", c_int ),
        ( "stepPulsePolarity", c_int ),
        ( "machineType", c_int ),
        ( "pwmFrequency", c_int ),
        ( "resetInput", c_int ),
        ( "reserved", c_int * 3 ),
    ]

class CNC_SERVICE_CFG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "stsUsageTimeHoursTotal", c_double ),
        ( "stsUsageTimeHoursService", c_double ),
        ( "stsTraveledDistMetersTotal", c_double ),
        ( "stsTraveledDistMetersService", c_double ),
        ( "stsNumJobsDoneTotal", c_int ),
        ( "stsNumJobsDoneService", c_int ),
        ( "parServiceTimeIntervalHours", c_double ),
        ( "parServiceTravelDistInterval", c_double ),
        ( "pumpIntervalTimeSeconds", c_double ),
        ( "pumpPulseTimeSeconds", c_double ),
        ( "stsPumpTimeToGo", c_double ), # //Remaining time before pump will start.
        ( "pumpPortID", c_int ),
        ( "reserved", c_double * 5 ),
    ]

class CNC_I2CGPIO_RULE_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "action", c_int ),
        ( "messageText", c_char * CNC_MAX_MESSAGE_TEXT ),
    ]

class CNC_I2CGPIO_CARD_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "_nrOfGpioCards", c_int ),
    ]

class CNC_UIO_SINGLE_INPUT_CFG(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class CNC_UIO_SELECTOR_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class CNC_UIO_ANALOG_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class CNC_UIO_HANDWHEEL_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class CNC_UIO_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "singleInput", CNC_UIO_SINGLE_INPUT_CFG * CNC_MAX_UIO_INPUTS ),
        ( "selector", CNC_UIO_SELECTOR_CONFIG * CNC_MAX_UIO_SELECTOR_SWITCHES ),
        ( "analog", CNC_UIO_ANALOG_CONFIG * CNC_MAX_UIO_ANALOG_INPUTS ),
        ( "handwheel", CNC_UIO_HANDWHEEL_CONFIG * CNC_MAX_UIO_HANDWHEEL_INPUTS ),
    ]

class CNC_GUI_COMMAND_MSG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "action", c_int ),
        ( "value", c_int ),
        ( "value2", c_int ),
    ]

class CNC_MACHINE_CONFIG(Structure):
    _pack_ = 1
    _fields_ = [
        ( "systemCfg", CNC_SYSTEM_CONFIG ),
        ( "jointCfg", CNC_JOINT_CFG * CNC_MAX_JOINTS ),
        ( "spindleCfg", CNC_SPINDLE_CONFIG * CNC_MAX_SPINDLES ),
        ( "ioCfg", CNC_IO_CONFIG ),
        ( "kinCfg", CNC_KIN_CFG ),
        ( "interpreterCfg", CNC_INTERPRETER_CONFIG ),
        ( "trajCfg", CNC_TRAJECTORY_CFG ),
        ( "plasmaCfg", CNC_THC_CFG ),
        ( "safetyCfg", CNC_SAFETY_CONFIG ),
        ( "probingCfg", CNC_PROBING_CFG ),
        ( "trafficLightCfg", CNC_TRAFFIC_LIGHT_CFG ),
        ( "handwheelCfg", CNC_HANDWHEEL_CFG ),
        ( "feedSpeedOVCfg", CNC_FEEDSPEED_CFG ),
        ( "gpioCfg", CNC_I2CGPIO_CARD_CONFIG ),
        ( "cameraCfg", CNC_CAMERA_CONFIG ),
        ( "vacuumBedCfg", CNC_VACUUMBED_CONFIG ),
        ( "uiCfg", CNC_UI_CFG ),
        ( "serviceCfg", CNC_SERVICE_CFG ),
        ( "print3DCfg", CNC_3DPRINTING_CONFIG ),
        ( "uioCfg", CNC_UIO_CONFIG ),
    ]

class CNC_IO_PORT_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "ioId", c_int ),
        ( "invert", c_int ),
        ( "lvalue", c_int ),
        ( "rvalue", c_int ),
        ( "present", c_int ),
    ]

class CNC_GPIO_PORT_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "ioId", c_int ),
        ( "invert", c_int ),
        ( "lvalue", c_int ),
        ( "rvalue", c_int ),
        ( "present", c_int ),
        ( "name", c_char * CNC_MAX_IO_NAME_LENGTH ),
    ]

class CNC_JOINT_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "jointIndex", c_char ),
        ( "state", c_int ),
        ( "errorWord", c_int ),
        ( "position", c_double ),
        ( "positionRaw", c_double ),
        ( "maxPositionError", c_double ),
        ( "isHomed", c_int ),
        ( "homeSensorStatus", c_int ),
        ( "jointIsConfigured", c_int ),
    ]

class CNC_JOB_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "jobName", c_char * CNC_MAX_PATH ),
        ( "jobName", c_wchar * CNC_MAX_PATH ),
        ( "jobLoadCounter", c_int ),
        ( "numLinesInjob", c_int ),
        ( "numLinesInMacro", c_int ),
        ( "numLinesInUserMacro", c_int ),
        ( "isLongJob", c_int ),
        ( "isSuperLongJob", c_int ),
        ( "jobIsRendered", c_int ),
        ( "totalJobLength", c_double ),
        ( "jobProgress", c_double ),
        ( "jobActualRunningTime", c_double ),
        ( "jobRemainingRunningTime", c_double ),
        ( "jobEstimatedTime", c_double ),
        ( "TCACollision", c_int ),
        ( "MCACollision", c_int ),
        ( "xCollision", c_int ),
        ( "yCollision", c_int ),
        ( "zCollision", c_int ),
        ( "jobRenderLine", c_int ),
        ( "jobRenderProgressPercentage", c_double ),
        ( "curIpLine", c_int ),
        ( "curExLine", c_int ),
        ( "lastKnownExcutedLineNumber", c_int ),
        ( "lastKnownToolChangeLineNumber", c_int ),
        ( "doRepeatJob", c_int ),
        ( "nrOfJobRepeatsSet", c_int ),
        ( "nrOfRepeatsActual", c_int ), # /* this one is decremented after each RUN */
        ( "extraLineWhenEndOfJob", c_char * CNC_MAX_INTERPRETER_LINE ),
        ( "stockDiameterTurning", c_double ),
        ( "stockLengthTurning", c_double ),
        ( "stockZAtworkOffset", c_int ),
    ]

class CNC_SPINDLE_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "syncCount", c_int ),
        ( "actualSpindleSpeedSigned", c_double ),
        ( "programmedSpindleSpeed", c_double ),
        ( "speedOverrideFactor", c_double ),
        ( "spindleIsOn", c_int ),
        ( "spindleDirection", c_int ),
        ( "spindlePWMPrecentage", c_int ),
        ( "feedSpeedSyncAvailable", c_int ),
        ( "actualSpindleConfigurationIndex", c_int ),
        ( "isRampingUp", c_int ),
        ( "spindleReady", c_int ),
        ( "spindleCfg", CNC_SPINDLE_CONFIG ),
    ]

class CNC_PAUSE_STS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "pauseManualActionRequired", c_int ),
        ( "pausePosition", CNC_CART_DOUBLE ),
        ( "pausePositionValid", c_int ),
        ( "pausePositionLine", c_int ),
        ( "pauseSpindleIOValue", c_int ),
        ( "pauseAux1IOValue", c_int ),
        ( "pauseAux2IOValue", c_int ),
        ( "pauseAux3IOValue", c_int ),
        ( "pauseAux4IOValue", c_int ),
        ( "pauseAux5IOValue", c_int ),
        ( "pauseAux6IOValue", c_int ),
        ( "pauseAux7IOValue", c_int ),
        ( "pauseAux8IOValue", c_int ),
        ( "pauseAux9IOValue", c_int ),
        ( "pauseAux10IOValue", c_int ),
        ( "pauseMistIOValue", c_int ),
        ( "pauseFloodIOValue", c_int ),
        ( "pauseArrayIndexX", c_int ),
        ( "pauseArrayIndexY", c_int ),
        ( "pauseDoArray", c_int ),
        ( "curPosInSync", CNC_CART_BOOL ),
        ( "spindleInSync", c_int ),
        ( "floodInSync", c_int ),
        ( "mistInSync", c_int ),
        ( "allAxesInSync", c_int ),
    ]

class CNC_BASIC_INTERPRETER_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "axesPresent", CNC_CART_BOOL ),
        ( "position", CNC_CART_DOUBLE ), # //mm
        ( "activeOffsetAndPlane", CNC_OFFSET_AND_PLANE ),
        ( "spindleOn", c_int ),
        ( "mist", c_int ),
        ( "flood", c_int ),
        ( "speed", c_double ),
        ( "toolInSpindle", c_int ),
        ( "feed", c_double ),
        ( "inchMode", c_int ),
        ( "motionToBe", c_int ),
        ( "lafBlendAccuracy", c_double ), #    //P..
        ( "lineTolerance", c_double ), #       //Q..
        ( "lafAngleFullSpeed", c_double ), #   //R..
        ( "lafAngleReducedSpeed", c_double ), #//S..
        ( "lafDeltaReducedSpeed", c_double ), #//D..
        ( "lafFilter", c_double ), #           //F..
    ]

class CNC_SEARCH_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "basicIntStatusBeforeSearch", CNC_BASIC_INTERPRETER_STATUS ),
        ( "basicIntStatusAfterSearch", CNC_BASIC_INTERPRETER_STATUS ),
        ( "curPosInSync", CNC_CART_BOOL ),
        ( "spindleInSync", c_int ),
        ( "floodInSync", c_int ),
        ( "mistInSync", c_int ),
        ( "toolInSync", c_int ),
    ]

class CNC_TRACKING_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "curTrackingMode", c_int ),
        ( "curTrackSource", c_int * CNC_MAX_AXES ),
        ( "curTrackingPosReached", CNC_CART_BOOL ),
        ( "curAxesIsTracking", CNC_CART_BOOL ),
        ( "curHandwheelMultiplicationFactor", c_double ),
        ( "trackingPosition", CNC_CART_DOUBLE ),
        ( "trackingVelocity", CNC_CART_DOUBLE ),
        ( "trackingAccel", CNC_CART_DOUBLE ),
        ( "trackingHandwheelCounter", c_int * 3 ),
        ( "newTrackingDataFlag", c_int ),
    ]

class CNC_COMPENSATION_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "zHeightCompIsOn", c_int ),
        ( "outOfArea", c_int ),
        ( "curCompValue", CNC_JOINT_DOUBLE ),
        ( "backlashCompIsOn", CNC_JOINT_BOOL ),
        ( "linearJointCompIsOn", CNC_JOINT_BOOL ),
        ( "crossCompIsOn", CNC_JOINT_BOOL ),
    ]

class CNC_THC_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "actualProcessPars", CNC_THC_PROCESS_PARAMETERS ),
        ( "voltAct", c_double ), #   // = Vactual
        ( "controllerOut", c_double ),
        ( "isOn", c_int ),
        ( "isTracking", c_int ),
        ( "isActive", c_int ),
        ( "curveProtectActive", c_int ),
        ( "holeDetectActive", c_int ),
        ( "plasmaOnInput", c_int ),
        ( "isCuttingMove", c_int ),
        ( "isTuningMode", c_int ),
        ( "externalUpDownMode", c_int ),
        ( "goUpInput", c_int ),
        ( "goDownInput", c_int ),
    ]

class CNC_NESTING_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "doArray", c_int ),
        ( "arrayNX", c_int ),
        ( "arrayNY", c_int ),
        ( "arrayDX", c_double ),
        ( "arrayDY", c_double ),
        ( "arrayStartOffsetX", c_double ),
        ( "arrayStartOffsetY", c_double ),
        ( "arrayMaterialSizeX", c_double ),
        ( "arrayMaterialSizeY", c_double ),
        ( "arrayMaterialSizeZ", c_double ),
        ( "arrayCurXIndex", c_int ),
        ( "arrayCurYIndex", c_int ),
        ( "arrayCurXOffset", c_double ),
        ( "arrayCurYOffset", c_double ),
    ]

class CNC_CONTROLLER_CONFIG_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "comPortListSize", c_int ),
        ( "connectedViaEtherNet", c_int ),
        ( "connectedViaUSB", c_int ),
        ( "connectedViaSimulation", c_int ),
        ( "connectionError", c_int ),
        ( "controllerFrequencies", c_double * CNC_MAX_FREQENCY_TABLE_LEN ),
        ( "controllerFrequencyTimerValues", c_int * CNC_MAX_FREQENCY_TABLE_LEN ),
        ( "controllerNumberOfFrequencies", c_int ),
        ( "controllerFirmwareVersion", c_char * CNC_MAX_NAME_LENGTH ),
        ( "controllerMaxAxes", c_int ),
        ( "controllerAvailableAxes", c_int ),
        ( "firmwareHasOptions", c_int ),
        ( "cpuIsEnabled", c_int ),
        ( "avx1GPIOIsEnabled", c_int ),
        ( "ediGPIOIsEnabled", c_int ),
        ( "plasmaIsEnabled", c_int ),
        ( "maxAnalogValue", c_int ),
        ( "cpuType", c_int ),
        ( "initCount", c_int ),
    ]

class CNC_CONTROLLER_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "jointSts", CNC_JOINT_STS * CNC_MAX_JOINTS ),
        ( "cpuIoSts", CNC_IO_PORT_STS * CNC_IOID_LAST ),
        ( "gpioAvx2Present", c_int * CNC_MAX_GPIOCARD_CARDS ),
        ( "gpioRLY8Present", c_int * CNC_MAX_GPIOCARD_CARDS ),
        ( "gpioRLY24Present", c_int * CNC_MAX_GPIOCARD_CARDS ),
        ( "motionEnabled", c_int ),
        ( "capturing", c_int ),
        ( "isCaptured", c_int ),
        ( "errorWord", c_int ),
        ( "handWheelCount1", c_int ),
        ( "handWheelCount2", c_int ),
        ( "auxAxPos", c_int ),
        ( "auxAxState", c_int ),
        ( "auxAxDirection", c_int ),
        ( "auxAxIsHomed", c_int ),
        ( "auxAxisIs32bitMode", c_int ),
    ]

class CNC_MOTION_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "machineCartesianPosition", CNC_CART_DOUBLE ),
        ( "machineJointPosition", CNC_JOINT_DOUBLE ),
        ( "activeOffsetAndPlane", CNC_OFFSET_AND_PLANE ),
        ( "actualFeed", c_double ),
        ( "userFeedOverride", c_double ),
        ( "userArcFeedOverride", c_double ),
        ( "safeMode", c_int ),
        ( "safetyInputValue", c_int ),
        ( "simulationMode", c_int ),
        ( "heartBeat", c_int ),
        ( "feedOvEnabled", c_int ),
        ( "speedOvEnabled", c_int ),
        ( "analogFeedOvEnabled", c_int ),
        ( "feedHoldActive", c_int ),
        ( "speedHoldHactive", c_int ),
    ]

class CNC_RUNNING_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "state", c_int ),
        ( "ActiveGCodes", c_int * 17 ),
        ( "ActiveMCodes", c_int * 11 ),
        ( "ActiveGSettings", c_double * 4 ),
        ( "lastIntError", CNC_LOG_MESSAGE ),
        ( "blockDelete", c_int ),
        ( "stepMode", c_int ),
        ( "optionalStopOn", c_int ),
        ( "subResetPresent", c_int ),
    ]

class CNC_TRAFFIC_LIGHT_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "trafficLightColor", c_int ),
        ( "trafficLightBlink", c_int ), #//True if blink
        ( "traficLightReason", c_char * CNC_MAX_LOGGING_TEXT ),
    ]

class CNC_VACUUM_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "autoMode", c_int ),
        ( "vacuumSectionConfigured", c_int * CNC_MAX_VACUUMBED_SECTIONS ),
        ( "vacuumSectionCrossed", c_int * CNC_MAX_VACUUMBED_SECTIONS ),
    ]

class CNC_STATUS(Structure):
    _pack_ = 1
    _fields_ = [
        ( "runningStatus", CNC_RUNNING_STATUS ),
        ( "motionStatus", CNC_MOTION_STATUS ),
        ( "controllerStatus", CNC_CONTROLLER_STATUS ),
        ( "controllerConfigStatus", CNC_CONTROLLER_CONFIG_STATUS ),
        ( "trafficLichtStatus", CNC_TRAFFIC_LIGHT_STATUS ),
        ( "jobStatus", CNC_JOB_STATUS ),
        ( "trackingStatus", CNC_TRACKING_STATUS ),
        ( "thcStatus", CNC_THC_STATUS ),
        ( "nestingStatus", CNC_NESTING_STATUS ),
        ( "kinStatus", CNC_KIN_STATUS ),
        ( "spindleSts", CNC_SPINDLE_STS ),
        ( "pauseSts", CNC_PAUSE_STS ),
        ( "searchSts", CNC_SEARCH_STATUS ),
        ( "print3DSts", CNC_3DPRINTING_STS ),
        ( "zHeightCompSts", CNC_COMPENSATION_STATUS ),
        ( "vacuumStatus", CNC_VACUUM_STATUS ),
    ]

class CNC_POS_FIFO_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "pos", CNC_CART_DOUBLE ), #     /* x,y,z position vector  */
        ( "type", c_int ), #    /* see GRAPH type         */
    ]

class CNC_GRAPH_FIFO_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "lineNumber", c_int ),
        ( "pos", CNC_CART_DOUBLE ), #     /* end position, origin offset, start pos, tool offset, depending on type */
        ( "type", c_int ), #    /* see GRAPH type         */
        ( "msgNumber", c_int ),
    ]

class CNC_RENDER_DATA(Structure):
    _pack_ = 1
    _fields_ = [
        ( "lineNr", c_int ), #   /* job line number */
        ( "type", c_int ), #     /* see GRAPH type         */
        ( "pos", CNC_CART_DOUBLE ), #      /* end position, origin offset, start pos, tool offset, depending on type */
        ( "center", CNC_VECTOR ), #   /* center for arc */
        ( "normal", CNC_VECTOR ), #   /* for arc */
        ( "turn", c_int ), #     /* for arc direction & n of turns */
        ( "offsetAndPlane", CNC_OFFSET_AND_PLANE ),
        ( "velocity", c_double ),
        ( "acceleration", c_double ),
        ( "linearIsLeading", c_bool ),
        ( "mFunc", c_int ), #    /* real time I/O executed at motion start */
        ( "mFuncPar", c_int ), # /* associated parameter for real time I/O */
    ]

class TOS_TIME_STAMP(Structure):
    _pack_ = 1
    _fields_ = [
    ]

class TOS_SERIAL_PORT_INFO(Structure):
    _pack_ = 1
    _fields_ = [
        ( "Index", c_ulong ),
        ( "PortName", c_char * TOS_MAX_PORT_NAME_SIZE ),
        ( "SerialNumber", c_char * TOS_MAX_SERIAL_NUMBER_SIZE ),
    ]

class TOS_HID_DEVICE(Structure):
    _pack_ = 1
    _fields_ = [
    ]

