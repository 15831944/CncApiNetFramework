#pragma once
#include "cncapi/cncapi.h"
#pragma warning( disable : 4091 )
namespace OosterhofDesign
{
	//#define VALUES
	typedef public enum class CncDef_AxesId
	{
		X_AXIS = CNC_X_AXIS,
		Y_AXIS = CNC_Y_AXIS,
		Z_AXIS = CNC_Z_AXIS,
		A_AXIS = CNC_A_AXIS,
		B_AXIS = CNC_B_AXIS,
		C_AXIS = CNC_C_AXIS,
		ALL_AXIS = CNC_ALL_AXES,
	};
	typedef public enum class CncDef_JointId
	{
		X_JOINT = CNC_X_JOINT,
		Y_JOINT = CNC_Y_JOINT,
		Z_JOINT = CNC_Z_JOINT,
		A_JOINT = CNC_A_JOINT,
		B_JOINT = CNC_B_JOINT,
		C_JOINT = CNC_C_JOINT,
		ALL_JOINT = CNC_ALL_JOINTS,
	};
	typedef public enum class CncDef_JogStepSize
	{
		STEP_SIZE_0_001 = CNC_JOG_STEP_SIZE_0_001,
		STEP_SIZE_0_01 = CNC_JOG_STEP_SIZE_0_01,
		STEP_SIZE_0_1 = CNC_JOG_STEP_SIZE_0_1,
		STEP_SIZE_0_5 = CNC_JOG_STEP_SIZE_0_5,
		STEP_SIZE_1 = CNC_JOG_STEP_SIZE_1,
	};
	typedef public enum class CncDef_HandWheelOn
	{
		ON_NONE = CNC_HANDWHEEL_ON_NONE,
		ON_X = CNC_HANDWHEEL_ON_X,
		ON_Y = CNC_HANDWHEEL_ON_Y,
		ON_Z = CNC_HANDWHEEL_ON_Z,
		ON_A = CNC_HANDWHEEL_ON_A,
		ON_B = CNC_HANDWHEEL_ON_B,
		ON_C = CNC_HANDWHEEL_ON_C,
		ON_ALL = CNC_HANDWHEEL_ON_ALL,
		ON_FEED = CNC_HANDWHEEL_ON_FEED,
		ON_SPEED = CNC_HANDWHEEL_ON_SPEED,

	};
	typedef public enum class CncDef_HandWheelMul
	{
		MUL_SEL_01 = CNC_HANDWHEEL_MUL_SEL_01 + 0,
		MUL_SEL_1 = CNC_HANDWHEEL_MUL_SEL_1,
		MUL_SEL_10 = CNC_HANDWHEEL_MUL_SEL_10,
		MUL_SEL_100 = CNC_HANDWHEEL_MUL_SEL_100,
	};
	typedef public enum class CncDef_HandWheelSel
	{
		SEL_000 = CNC_FEEDOV_SEL_000,
		SEL_001 = CNC_FEEDOV_SEL_001,
		SEL_002 = CNC_FEEDOV_SEL_002,
		SEL_005 = CNC_FEEDOV_SEL_005,
		SEL_010 = CNC_FEEDOV_SEL_010,
		SEL_030 = CNC_FEEDOV_SEL_030,
		SEL_060 = CNC_FEEDOV_SEL_060,
		SEL_100 = CNC_FEEDOV_SEL_100,
	};
	//
	//types

	typedef public enum class Cnc_Rc
	{

		CNC_RC_OK = CNC_RC::CNC_RC_OK,       /* success */
		CNC_RC_BUF_EMPTY = CNC_RC::CNC_RC_BUF_EMPTY,       /* buffer empty */
		CNC_RC_TRACE = CNC_RC::CNC_RC_TRACE,       /* trace info */
		CNC_RC_USER_INFO = CNC_RC::CNC_RC_USER_INFO,       /* User message */
		CNC_RC_SHUTDOWN = CNC_RC::CNC_RC_SHUTDOWN,       /* returned by process request after CMD_CLOSE */
		CNC_RC_EXISTING = CNC_RC::CNC_RC_EXISTING,       /* if shared memory already exists */
		CNC_RC_ALREADY_RUNS = CNC_RC::CNC_RC_ALREADY_RUNS,       /* if server already running */
		CNC_RC_ALREADY_CONNECTED = CNC_RC::CNC_RC_ALREADY_CONNECTED,  /* if CncConnectServer() call is already done */
		CNC_RC_ERR = CNC_RC::CNC_RC_ERR,       /* no data in fifo */
		CNC_RC_ERR_PAR = CNC_RC::CNC_RC_ERR_PAR,       /* wrong parameter or parameter value, see text */
		CNC_RC_ERR_STATE = CNC_RC::CNC_RC_ERR_STATE,       /* wrong state, not allowed, see text */
		CNC_RC_ERR_CONFIG = CNC_RC::CNC_RC_ERR_CONFIG,       /* wrong config, e.g. axis not present */
		CNC_RC_ERR_INT = CNC_RC::CNC_RC_ERR_INT,       /* interpreter error, see interpreter error status */
		CNC_RC_ERR_CE = CNC_RC::CNC_RC_ERR_CE,       /* command envelope error */
		CNC_RC_ERR_EXE = CNC_RC::CNC_RC_ERR_EXE,       /* execution error */
		CNC_RC_ERR_CPU = CNC_RC::CNC_RC_ERR_CPU,       /* CPU error, see sub code, text, restart required */
		CNC_RC_ERR_MOT = CNC_RC::CNC_RC_ERR_MOT,       /* trajectory generator error, see sub code, text */
		CNC_RC_ERR_SYS = CNC_RC::CNC_RC_ERR_SYS,      /* server system error, see text */
		CNC_RC_ERR_TIMEOUT = CNC_RC::CNC_RC_ERR_TIMEOUT,      /* general timeout error */
		CNC_RC_EXE_CE = CNC_RC::CNC_RC_EXE_CE,      /* Error executing command envelope */
		CNC_RC_ERR_FILEOPEN = CNC_RC::CNC_RC_ERR_FILEOPEN,      /* file open error */
		CNC_RC_ERR_COLLISION = CNC_RC::CNC_RC_ERR_COLLISION,	     /* collision */
		CNC_RC_ERR_SERVER_NOT_RUNNING = CNC_RC::CNC_RC_ERR_SERVER_NOT_RUNNING,/* trying to connect as monitor, but server not running */
		CNC_RC_ERR_VERSION_MISMATCH = CNC_RC::CNC_RC_ERR_VERSION_MISMATCH,  /* Versions mismatch between SERVER and CNCAPI */
		CNC_RC_ERR_NOT_CONNECTED = CNC_RC::CNC_RC_ERR_NOT_CONNECTED,     /* CncConnectServer was not called by the CNCAPI */
		CNC_RC_ERR_BUF_FULL = CNC_RC::CNC_RC_ERR_BUF_FULL,


	}Cnc_Rc;
	typedef public enum class CncJointState
	{
		CNC_JOINT_POWER_UP = CNC_JOINT_STATE::CNC_JOINT_POWER_UP,
		CNC_JOINT_MOVING_STATE = CNC_JOINT_STATE::CNC_JOINT_MOVING_STATE,
		CNC_JOINT_READY_STATE = CNC_JOINT_STATE::CNC_JOINT_READY_STATE,
		CNC_JOINT_READY_STOPPED_STATE = CNC_JOINT_STATE::CNC_JOINT_READY_STOPPED_STATE,
		CNC_JOINT_FREE_STATE = CNC_JOINT_STATE::CNC_JOINT_FREE_STATE,
		CNC_JOINT_ERROR_STATE = CNC_JOINT_STATE::CNC_JOINT_ERROR_STATE,
		CNC_JOINT_LAST_STATE = CNC_JOINT_STATE::CNC_JOINT_LAST_STATE
	}CncJointState;
	typedef public enum class CncIoId
	{
		CNC_IOID_NONE = CNC_IO_ID::CNC_IOID_NONE,             //No IO defined
															  //1 dummy io

															  CNC_IOID_MACHINE_ON_OUT = CNC_IO_ID::CNC_IOID_MACHINE_ON_OUT,     //Machine ON output
															  CNC_IOID_DRIVE_ENABLE_OUT = CNC_IO_ID::CNC_IOID_DRIVE_ENABLE_OUT,   //Amplifier enable
															  CNC_IOID_DRIVE_CURRENT_REDUCE_OUT = CNC_IO_ID::CNC_IOID_DRIVE_CURRENT_REDUCE_OUT,
															  CNC_IOID_TOOL_OUT = CNC_IO_ID::CNC_IOID_TOOL_OUT,           //Tool on
															  CNC_IOID_COOLANT1_OUT = CNC_IO_ID::CNC_IOID_COOLANT1_OUT,       //Flood
															  CNC_IOID_COOLANT2_OUT = CNC_IO_ID::CNC_IOID_COOLANT2_OUT,       //Mist
															  CNC_IOID_TOOLDIR_OUT = CNC_IO_ID::CNC_IOID_TOOLDIR_OUT,        //Tool direction output
																															 //6 total standard CNC outputs

																															 CNC_IOID_AUX1_OUT = CNC_IO_ID::CNC_IOID_AUX1_OUT,           //Aux1 output
																															 CNC_IOID_AUX2_OUT = CNC_IO_ID::CNC_IOID_AUX2_OUT,           //Aux2 output
																															 CNC_IOID_AUX3_OUT = CNC_IO_ID::CNC_IOID_AUX3_OUT,           //Aux3 output
																															 CNC_IOID_AUX4_OUT = CNC_IO_ID::CNC_IOID_AUX4_OUT,          //Aux4 output
																															 CNC_IOID_AUX5_OUT = CNC_IO_ID::CNC_IOID_AUX5_OUT,          //Aux5 output
																															 CNC_IOID_AUX6_OUT = CNC_IO_ID::CNC_IOID_AUX6_OUT,          //Aux6 output
																															 CNC_IOID_AUX7_OUT = CNC_IO_ID::CNC_IOID_AUX7_OUT,          //Aux7 output
																															 CNC_IOID_AUX8_OUT = CNC_IO_ID::CNC_IOID_AUX8_OUT,          //Aux8 output
																															 CNC_IOID_AUX9_OUT = CNC_IO_ID::CNC_IOID_AUX9_OUT,          //Aux9 output
																															 CNC_IOID_AUX10_OUT = CNC_IO_ID::CNC_IOID_AUX10_OUT,
																															 CNC_IOID_AUX_OUT_MAX = CNC_IO_ID::CNC_IOID_AUX_OUT_MAX,
																															 //9 AUX outputs
																															 //15  total digital CPU outputs

																															 CNC_IOID_PWM_VAL1_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL1_OUT,      //PWM value output 0..1000%%
																															 CNC_IOID_PWM_VAL2_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL2_OUT,      //PWM value output 0..1000%%
																															 CNC_IOID_PWM_VAL3_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL3_OUT,      //PWM value output 0..1000%%
																															 CNC_IOID_PWM_VAL4_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL4_OUT,
																															 CNC_IOID_PWM_VAL5_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL5_OUT,
																															 CNC_IOID_PWM_VAL6_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL6_OUT,
																															 CNC_IOID_PWM_VAL7_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL7_OUT,
																															 CNC_IOID_PWM_VAL8_OUT = CNC_IO_ID::CNC_IOID_PWM_VAL8_OUT,

																															 //3 total analog CPU outputs

																															 CNC_IOID_EMSTOP1_IN = CNC_IO_ID::CNC_IOID_EMSTOP1_IN,         //Emergency stop input
																															 CNC_IOID_EMSTOP2_IN = CNC_IO_ID::CNC_IOID_EMSTOP2_IN,         //Emergency stop input
																															 CNC_IOID_EXTERR_IN = CNC_IO_ID::CNC_IOID_EXTERR_IN,          //Ext error input
																															 CNC_IOID_PROBE_IN = CNC_IO_ID::CNC_IOID_PROBE_IN,           //Probe
																															 CNC_IOID_SYNC_IN = CNC_IO_ID::CNC_IOID_SYNC_IN,            //Spindle Sync pulse
																															 CNC_IOID_RUN_IN = CNC_IO_ID::CNC_IOID_RUN_IN,             //Run Button
																															 CNC_IOID_PAUSE_IN = CNC_IO_ID::CNC_IOID_PAUSE_IN,           //Pause Button
																															 CNC_IOID_HOME_X_IN = CNC_IO_ID::CNC_IOID_HOME_X_IN,          //Home sensor
																															 CNC_IOID_HOME_Y_IN = CNC_IO_ID::CNC_IOID_HOME_Y_IN,          //idem
																															 CNC_IOID_HOME_Z_IN = CNC_IO_ID::CNC_IOID_HOME_Z_IN,          //idem
																															 CNC_IOID_HOME_A_IN = CNC_IO_ID::CNC_IOID_HOME_A_IN,          //idem
																															 CNC_IOID_HOME_B_IN = CNC_IO_ID::CNC_IOID_HOME_B_IN,          //idem
																															 CNC_IOID_HOME_C_IN = CNC_IO_ID::CNC_IOID_HOME_C_IN,          //idem
																															 CNC_IOID_HOME_1_IN = CNC_IO_ID::CNC_IOID_HOME_1_IN,          //Home sensor
																															 CNC_IOID_HOME_2_IN = CNC_IO_ID::CNC_IOID_HOME_2_IN,          //idem
																															 CNC_IOID_HOME_3_IN = CNC_IO_ID::CNC_IOID_HOME_3_IN,          //idem
																															 CNC_IOID_HOME_4_IN = CNC_IO_ID::CNC_IOID_HOME_4_IN,          //idem
																															 CNC_IOID_HOME_5_IN = CNC_IO_ID::CNC_IOID_HOME_5_IN,          //idem
																															 CNC_IOID_HOME_6_IN = CNC_IO_ID::CNC_IOID_HOME_6_IN,          //idem
																															 CNC_IOID_HW1A_IN = CNC_IO_ID::CNC_IOID_HW1A_IN,            //Hand wheel counter
																															 CNC_IOID_HW1B_IN = CNC_IO_ID::CNC_IOID_HW1B_IN,            //Hand wheel counter
																															 CNC_IOID_HW2A_IN = CNC_IO_ID::CNC_IOID_HW2A_IN,
																															 CNC_IOID_HW2B_IN = CNC_IO_ID::CNC_IOID_HW2B_IN,

																															 CNC_IOID_EMSTOP_FROM_GPIO = CNC_IO_ID::CNC_IOID_EMSTOP_FROM_GPIO,   //EStop from GPIO
																															 CNC_IOID_SSTOP_FROM_GPIO = CNC_IO_ID::CNC_IOID_SSTOP_FROM_GPIO,    //SmoothStop from GPIO
																															 CNC_IOID_WARNING_FROM_GPIO = CNC_IO_ID::CNC_IOID_WARNING_FROM_GPIO,  //Warning from GPIO

																																																  //21 total CPU digital CNC inputs

																																																  CNC_IOID_AUX1_IN = CNC_IO_ID::CNC_IOID_AUX1_IN,            //Aux1 input
																																																  CNC_IOID_AUX2_IN = CNC_IO_ID::CNC_IOID_AUX2_IN,            //Aux2 input
																																																  CNC_IOID_AUX3_IN = CNC_IO_ID::CNC_IOID_AUX3_IN,            //Aux3 input
																																																  CNC_IOID_AUX4_IN = CNC_IO_ID::CNC_IOID_AUX4_IN,            //Aux4 input
																																																  CNC_IOID_AUX5_IN = CNC_IO_ID::CNC_IOID_AUX5_IN,            //Aux5 input
																																																  CNC_IOID_AUX6_IN = CNC_IO_ID::CNC_IOID_AUX6_IN,            //Aux6 input
																																																  CNC_IOID_AUX7_IN = CNC_IO_ID::CNC_IOID_AUX7_IN,            //Aux6 input
																																																  CNC_IOID_AUX8_IN = CNC_IO_ID::CNC_IOID_AUX8_IN,            //Aux6 input
																																																  CNC_IOID_AUX9_IN = CNC_IO_ID::CNC_IOID_AUX9_IN,
																																																  CNC_IOID_AUX10_IN = CNC_IO_ID::CNC_IOID_AUX10_IN,
																																																  CNC_IOID_AUX_IN_MAX = CNC_IO_ID::CNC_IOID_AUX_IN_MAX,
																																																  //6 total CPU digital AUX inputs
																																																															 //27 total CPU digital inputs

																																																															 CNC_IOID_ANA1_IN = CNC_IO_ID::CNC_IOID_ANA1_IN,            //Analog1
																																																															 CNC_IOID_ANA2_IN = CNC_IO_ID::CNC_IOID_ANA2_IN,            //Analog2
																																																															 CNC_IOID_ANA3_IN = CNC_IO_ID::CNC_IOID_ANA3_IN,            //Analog3
																																																															 CNC_IOID_ANA4_IN = CNC_IO_ID::CNC_IOID_ANA4_IN,            //Analog3
																																																															 CNC_IOID_ANA5_IN = CNC_IO_ID::CNC_IOID_ANA5_IN,            //Analog3
																																																															 CNC_IOID_ANA6_IN = CNC_IO_ID::CNC_IOID_ANA6_IN,
																																																															 CNC_IOID_ANA7_IN = CNC_IO_ID::CNC_IOID_ANA7_IN,
																																																															 CNC_IOID_ANA8_IN = CNC_IO_ID::CNC_IOID_ANA8_IN,
																																																															 CNC_IOID_ANA_IN_MAX = CNC_IO_ID::CNC_IOID_ANA_IN_MAX,

																																																															 //3 total CPU analog inputs
																																																															 CNC_IOID_DRIVEALM_IN = CNC_IO_ID::CNC_IOID_DRIVEALM_IN,        //Drive alarm input
																																																															 CNC_IOID_DRIVEWARN_IN = CNC_IO_ID::CNC_IOID_DRIVEWARN_IN,       //Drive warning input
																																																															 CNC_IOID_OUTPUTPROBLEM_IN = CNC_IO_ID::CNC_IOID_OUTPUTPROBLEM_IN,      //Drive alarm input
																																																															 CNC_IOID_INPUTPROBLEM_IN = CNC_IO_ID::CNC_IOID_INPUTPROBLEM_IN,      //Drive warning input

																																																															 CNC_IOID_LAST = CNC_IO_ID::CNC_IOID_LAST               //Serves as last

	}CncIoId;
	typedef public enum class CncGpioActionType
	{
		CNC_GPIO_ACTION_TYPE_NONE = CNC_GPIO_ACTION_TYPE::CNC_GPIO_ACTION_TYPE_NONE,
		CNC_GPIO_ACTION_TYPE_WARNING = CNC_GPIO_ACTION_TYPE::CNC_GPIO_ACTION_TYPE_WARNING,
		CNC_GPIO_ACTION_TYPE_SSTOP = CNC_GPIO_ACTION_TYPE::CNC_GPIO_ACTION_TYPE_SSTOP,
		CNC_GPIO_ACTION_TYPE_ESTOP = CNC_GPIO_ACTION_TYPE::CNC_GPIO_ACTION_TYPE_ESTOP

	} CncGpioActionType;
	typedef public enum class CncConstants
	{
		CNC_MAX_CUSTOMER_NAME = CNC_CONSTANTS::CNC_MAX_CUSTOMER_NAME,
		CNC_MAX_JOINTS = CNC_CONSTANTS::CNC_MAX_JOINTS,
		CNC_MAX_AXES = CNC_CONSTANTS::CNC_MAX_AXES,
		CNC_MAX_SPINDLES = CNC_CONSTANTS::CNC_MAX_SPINDLES,
		CNC_MAX_NAME_LENGTH = CNC_CONSTANTS::CNC_MAX_NAME_LENGTH,
		CNC_MAX_IO_ERROR_TEXT = CNC_CONSTANTS::CNC_MAX_IO_ERROR_TEXT,
		CNC_MAX_IO_NAME_LENGTH = CNC_CONSTANTS::CNC_MAX_IO_NAME_LENGTH,
		CNC_MAX_PATH = CNC_CONSTANTS::CNC_MAX_PATH,
		CNC_MAX_FNAME_LENGTH = CNC_CONSTANTS::CNC_MAX_FNAME_LENGTH,
		CNC_MAX_LOGGING_TEXT = CNC_CONSTANTS::CNC_MAX_LOGGING_TEXT,
		CNC_MAX_SOURCE_INFO_TEXT = CNC_CONSTANTS::CNC_MAX_SOURCE_INFO_TEXT,
		CNC_MAX_FUNCTION_NAME_TEXT = CNC_CONSTANTS::CNC_MAX_FUNCTION_NAME_TEXT,
		CNC_MAX_MESSAGE_TEXT = CNC_CONSTANTS::CNC_MAX_MESSAGE_TEXT,
		CNC_MAX_VARS = CNC_CONSTANTS::CNC_MAX_VARS,
		CNC_MAX_TOOLS = CNC_CONSTANTS::CNC_MAX_TOOLS,
		CNC_MAX_CURRENT_GCODE_TEXT = CNC_CONSTANTS::CNC_MAX_CURRENT_GCODE_TEXT,
		CNC_MAX_CURRENT_MCODE_TEXT = CNC_CONSTANTS::CNC_MAX_CURRENT_MCODE_TEXT,
		CNC_MAX_EXPRESSION_TEXT = CNC_CONSTANTS::CNC_MAX_EXPRESSION_TEXT,
		CNC_MAX_INTERPRETER_LINE = CNC_CONSTANTS::CNC_MAX_INTERPRETER_LINE,
		CNC_MAX_TOOL_CHANGES_IN_JOB = CNC_CONSTANTS::CNC_MAX_TOOL_CHANGES_IN_JOB,
		CNC_POS_FIFO_SIZE = CNC_CONSTANTS::CNC_POS_FIFO_SIZE,
		CNC_POS_FIFO_MARGIN = CNC_CONSTANTS::CNC_POS_FIFO_MARGIN,
		CNC_GRAPH_FIFO_SIZE = CNC_CONSTANTS::CNC_GRAPH_FIFO_SIZE,
		CNC_GRAPH_FIFO_MARGIN = CNC_CONSTANTS::CNC_GRAPH_FIFO_MARGIN,
		CNC_LOG_FIFO_SIZE = CNC_CONSTANTS::CNC_LOG_FIFO_SIZE,
		CNC_LOG_FIFO_MARGIN = CNC_CONSTANTS::CNC_LOG_FIFO_MARGIN,
		CNC_MAX_INTERPRETER_LOOKAHEAD = CNC_CONSTANTS::CNC_MAX_INTERPRETER_LOOKAHEAD,
		CNC_MAX_VERSION_TEXT = CNC_CONSTANTS::CNC_MAX_VERSION_TEXT,
		CNC_COMMPORT_NAME_LEN = CNC_CONSTANTS::CNC_COMMPORT_NAME_LEN,
		CNC_MAX_COMM_PORTS = CNC_CONSTANTS::CNC_MAX_COMM_PORTS,
		CNC_MAX_CPU_STD_CNC_OUTPUTS = CNC_CONSTANTS::CNC_MAX_CPU_STD_CNC_OUTPUTS,
		CNC_MAX_CPU_AUX_OUTPUTS = CNC_CONSTANTS::CNC_MAX_CPU_AUX_OUTPUTS,
		CNC_MAX_CPU_STD_CNC_INPUTS = CNC_CONSTANTS::CNC_MAX_CPU_STD_CNC_INPUTS,
		CNC_MAX_CPU_AUX_INPUTS = CNC_CONSTANTS::CNC_MAX_CPU_AUX_INPUTS,
		CNC_MAX_CPU_DIGITAL_OUTPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_DIGITAL_OUTPUT_PORTS,
		CNC_MAX_CPU_ANALOG_OUTPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_ANALOG_OUTPUT_PORTS,
		CNC_MAX_CPU_DIGITAL_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_DIGITAL_INPUT_PORTS,
		CNC_MAX_CPU_ANALOG_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_ANALOG_INPUT_PORTS,
		CNC_MAX_CPU_DRIVE_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_DRIVE_INPUT_PORTS,
		CNC_MAX_CPU_IO_PROBLEM_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_IO_PROBLEM_INPUT_PORTS,
		CNC_MAX_CPU_IO_PORTS = CNC_CONSTANTS::CNC_MAX_CPU_IO_PORTS,
		CNC_MAX_GPIOCARD_DIGITAL_OUTPUT_PORTS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_DIGITAL_OUTPUT_PORTS,
		CNC_MAX_GPIOCARD_ANALOG_OUTPUT_PORTS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_ANALOG_OUTPUT_PORTS,
		CNC_MAX_GPIOCARD_DIGITAL_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_DIGITAL_INPUT_PORTS,
		CNC_MAX_GPIOCARD_ANALOG_INPUT_PORTS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_ANALOG_INPUT_PORTS,
		CNC_MAX_GPIOCARD_PORTS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_PORTS,
		CNC_MAX_GPIOCARD_CARDS = CNC_CONSTANTS::CNC_MAX_GPIOCARD_CARDS,
		CNC_MAX_GPIOCARD_RULES = CNC_CONSTANTS::CNC_MAX_GPIOCARD_RULES,
		CNC_MAX_PRECISION_TEXT = CNC_CONSTANTS::CNC_MAX_PRECISION_TEXT,
		CNC_TOOL_DIAMETER_INDEX = CNC_CONSTANTS::CNC_TOOL_DIAMETER_INDEX,		/* First var index of tool diameter    */
		CNC_TOOL_ZOFFSET_INDEX = CNC_CONSTANTS::CNC_TOOL_ZOFFSET_INDEX,		/* First var index of tool z-offset    */
		CNC_TOOL_XOFFSET_INDEX = CNC_CONSTANTS::CNC_TOOL_XOFFSET_INDEX,		/* First var index of tool x-offset    */
		CNC_TOOL_ORIENTATION_INDEX = CNC_CONSTANTS::CNC_TOOL_ORIENTATION_INDEX,  /* First var index of tool orientation */
		CNC_TOOL_XDELTA_INDEX = CNC_CONSTANTS::CNC_TOOL_XDELTA_INDEX,
		CNC_TOOL_ZDELTA_INDEX = CNC_CONSTANTS::CNC_TOOL_ZDELTA_INDEX,
		CNC_MAX_FREQENCY_TABLE_LEN = CNC_CONSTANTS::CNC_MAX_FREQENCY_TABLE_LEN,
		CNC_MAX_FIDUCIALS = CNC_CONSTANTS::CNC_MAX_FIDUCIALS,
		CNC_MAX_3D_TEMP_TABLE = CNC_CONSTANTS::CNC_MAX_3D_TEMP_TABLE,
		CNC_MAX_AUX_GUARD_INPUTS = CNC_CONSTANTS::CNC_MAX_AUX_GUARD_INPUTS,
		CNC_MAX_UIO_INPUTS = CNC_CONSTANTS::CNC_MAX_UIO_INPUTS,           /* number of inputs on UIO board */
		CNC_MAX_UIO_SELECTOR_SWITCHES = CNC_CONSTANTS::CNC_MAX_UIO_SELECTOR_SWITCHES, /* max number of selector switches */
		CNC_MAX_UIO_SELECTOR_BITS = CNC_CONSTANTS::CNC_MAX_UIO_SELECTOR_BITS,     /* each max 4 bit, 16 positions    */
		CNC_MAX_UIO_SELECTOR_ACTIONS = CNC_CONSTANTS::CNC_MAX_UIO_SELECTOR_ACTIONS, /* 2 to the power of CNC_MAX_UIO_SELECTOR_BITS  */
		CNC_MAX_UIO_ANALOG_INPUTS = CNC_CONSTANTS::CNC_MAX_UIO_ANALOG_INPUTS,     /* max number of analog inputs */
		CNC_MAX_UIO_HANDWHEEL_INPUTS = CNC_CONSTANTS::CNC_MAX_UIO_HANDWHEEL_INPUTS,   /* max handwheel inputs */
		CNC_MAX_VACUUMBED_SECTIONS = CNC_CONSTANTS::CNC_MAX_VACUUMBED_SECTIONS,   /* max sections of vacuum bed */
		CNC_MAX_USER_BUTTONS = CNC_CONSTANTS::CNC_MAX_USER_BUTTONS,
		CNC_MAX_USER_BUTTON_TEXT_LENGTH = CNC_CONSTANTS::CNC_MAX_USER_BUTTON_TEXT_LENGTH,

	}CncConstants;
	typedef public enum class CncCpuType
	{
		CNC_CPU_TYPE_UNKNOWN = CNC_CPU_TYPE::CNC_CPU_TYPE_UNKNOWN,
		CNC_CPU_TYPE_SIM = CNC_CPU_TYPE::CNC_CPU_TYPE_SIM,


		//PIC8 series
		CNC_CPU_TYPE_123 = CNC_CPU_TYPE::CNC_CPU_TYPE_123,

		//ARM 7
		CNC_CPU_TYPE_4 = CNC_CPU_TYPE::CNC_CPU_TYPE_4,

		//PIC32MX series
		CNC_CPU_TYPE_5A_USB = CNC_CPU_TYPE::CNC_CPU_TYPE_5A_USB,
		CNC_CPU_TYPE_5A_ETH = CNC_CPU_TYPE::CNC_CPU_TYPE_5A_ETH,
		CNC_CPU_TYPE_5B_USB = CNC_CPU_TYPE::CNC_CPU_TYPE_5B_USB,
		CNC_CPU_TYPE_5B_ETH = CNC_CPU_TYPE::CNC_CPU_TYPE_5B_ETH,
		CNC_CPU_TYPE_I600 = CNC_CPU_TYPE::CNC_CPU_TYPE_I600,
		CNC_CPU_TYPE_310_USB = CNC_CPU_TYPE::CNC_CPU_TYPE_310_USB,
		CNC_CPU_TYPE_310_ETH = CNC_CPU_TYPE::CNC_CPU_TYPE_310_ETH,

		//PIC32MZ series
		CNC_CPU_TYPE_760 = CNC_CPU_TYPE::CNC_CPU_TYPE_760,
		CNC_CPU_TYPE_720 = CNC_CPU_TYPE::CNC_CPU_TYPE_720,

		//End indicator
		CNC_CPU_TYPE_LAST = CNC_CPU_TYPE::CNC_CPU_TYPE_LAST
	};
	typedef public enum class CncGpioId
	{
		CNC_GPIOID_NONE = CNC_GPIO_ID::CNC_GPIOID_NONE,             //No IO defined
																	//1 dummy gpio

																	//General purpose IO
																	CNC_GPIOID_OUT_1 = CNC_GPIO_ID::CNC_GPIOID_OUT_1,          //Ext io card output
																	CNC_GPIOID_OUT_2 = CNC_GPIO_ID::CNC_GPIOID_OUT_2,          //Ext io card output
																	CNC_GPIOID_OUT_3 = CNC_GPIO_ID::CNC_GPIOID_OUT_3,          //Ext io card output
																	CNC_GPIOID_OUT_4 = CNC_GPIO_ID::CNC_GPIOID_OUT_4,          //Ext io card output
																	CNC_GPIOID_OUT_5 = CNC_GPIO_ID::CNC_GPIOID_OUT_5,          //Ext io card output
																	CNC_GPIOID_OUT_6 = CNC_GPIO_ID::CNC_GPIOID_OUT_6,          //Ext io card output
																	CNC_GPIOID_OUT_7 = CNC_GPIO_ID::CNC_GPIOID_OUT_7,          //Ext io card output
																	CNC_GPIOID_OUT_8 = CNC_GPIO_ID::CNC_GPIOID_OUT_8,          //Ext io card output
																	CNC_GPIOID_OUT_9 = CNC_GPIO_ID::CNC_GPIOID_OUT_9,          //Ext io card output
																	CNC_GPIOID_OUT_10 = CNC_GPIO_ID::CNC_GPIOID_OUT_10,         //Ext io card output
																	CNC_GPIOID_OUT_11 = CNC_GPIO_ID::CNC_GPIOID_OUT_11,
																	CNC_GPIOID_OUT_12 = CNC_GPIO_ID::CNC_GPIOID_OUT_12,
																	CNC_GPIOID_OUT_13 = CNC_GPIO_ID::CNC_GPIOID_OUT_13,
																	CNC_GPIOID_OUT_14 = CNC_GPIO_ID::CNC_GPIOID_OUT_14,
																	CNC_GPIOID_OUT_15 = CNC_GPIO_ID::CNC_GPIOID_OUT_15,
																	CNC_GPIOID_OUT_16 = CNC_GPIO_ID::CNC_GPIOID_OUT_16,
																	CNC_GPIOID_OUT_17 = CNC_GPIO_ID::CNC_GPIOID_OUT_17,
																	CNC_GPIOID_OUT_18 = CNC_GPIO_ID::CNC_GPIOID_OUT_18,
																	CNC_GPIOID_OUT_19 = CNC_GPIO_ID::CNC_GPIOID_OUT_19,
																	CNC_GPIOID_OUT_20 = CNC_GPIO_ID::CNC_GPIOID_OUT_20,
																	CNC_GPIOID_OUT_21 = CNC_GPIO_ID::CNC_GPIOID_OUT_21,
																	CNC_GPIOID_OUT_22 = CNC_GPIO_ID::CNC_GPIOID_OUT_22,
																	CNC_GPIOID_OUT_23 = CNC_GPIO_ID::CNC_GPIOID_OUT_23,
																	CNC_GPIOID_OUT_24 = CNC_GPIO_ID::CNC_GPIOID_OUT_24,


																	CNC_GPIOID_ANOUT_1 = CNC_GPIO_ID::CNC_GPIOID_ANOUT_1,       //Ext io card output
																	CNC_GPIOID_ANOUT_2 = CNC_GPIO_ID::CNC_GPIOID_ANOUT_2,       //Ext io card output
																	CNC_GPIOID_ANOUT_3 = CNC_GPIO_ID::CNC_GPIOID_ANOUT_3,       //Ext io card output
																	CNC_GPIOID_ANOUT_4 = CNC_GPIO_ID::CNC_GPIOID_ANOUT_4,       //Ext io card output


																	CNC_GPIOID_IN_1 = CNC_GPIO_ID::CNC_GPIOID_IN_1,           //Ext io card input
																	CNC_GPIOID_IN_2 = CNC_GPIO_ID::CNC_GPIOID_IN_2,           //Ext io card input
																	CNC_GPIOID_IN_3 = CNC_GPIO_ID::CNC_GPIOID_IN_3,           //Ext io card input
																	CNC_GPIOID_IN_4 = CNC_GPIO_ID::CNC_GPIOID_IN_4,           //Ext io card input
																	CNC_GPIOID_IN_5 = CNC_GPIO_ID::CNC_GPIOID_IN_5,           //Ext io card input
																	CNC_GPIOID_IN_6 = CNC_GPIO_ID::CNC_GPIOID_IN_6,           //Ext io card input
																	CNC_GPIOID_IN_7 = CNC_GPIO_ID::CNC_GPIOID_IN_6,           //Ext io card input
																	CNC_GPIOID_IN_8 = CNC_GPIO_ID::CNC_GPIOID_IN_8,           //Ext io card input
																	CNC_GPIOID_IN_9 = CNC_GPIO_ID::CNC_GPIOID_IN_9,           //Ext io card input
																	CNC_GPIOID_IN_10 = CNC_GPIO_ID::CNC_GPIOID_IN_10,          //Ext io card input


																	CNC_GPIOID_ANIN_1 = CNC_GPIO_ID::CNC_GPIOID_ANIN_1,         //Ext io card analogue input
																	CNC_GPIOID_ANIN_2 = CNC_GPIO_ID::CNC_GPIOID_ANIN_2,         //Ext io card analogue input
																	CNC_GPIOID_ANIN_3 = CNC_GPIO_ID::CNC_GPIOID_ANIN_3,         //Ext io card analogue input
																	CNC_GPIOID_ANIN_4 = CNC_GPIO_ID::CNC_GPIOID_ANIN_4,         //Ext io card analogue input

																	CNC_GPIOID_RULE_TRIGGER_STATUS = CNC_GPIO_ID::CNC_GPIOID_RULE_TRIGGER_STATUS, //Ext io card trigger status, bit 0 .. 15

																	CNC_GPIO_ID_WARNING_OUT = CNC_GPIO_ID::CNC_GPIO_ID_WARNING_OUT,     //These are outputs on the CPU5B OPT connector
																	CNC_GPIO_ID_ESTOP_OUT = CNC_GPIO_ID::CNC_GPIO_ID_ESTOP_OUT,     //Output for the GPIO
																	CNC_GPIO_ID_SSTOP_OUT = CNC_GPIO_ID::CNC_GPIO_ID_SSTOP_OUT,     //Inputs for the CPU

																	CNC_GPIOID_LAST = CNC_GPIO_ID::CNC_GPIOID_LAST           //Serves as last

	} CncGpioId;
	typedef public enum class CncFeedspeedOverrideSource
	{
		CNC_FSOV_SOURCE_UI = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_UI,
		CNC_FSOV_SOURCE_UI_HANDWHEEL = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_UI_HANDWHEEL,
		CNC_FSOV_SOURCE_ANALOGIN1 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN1,
		CNC_FSOV_SOURCE_ANALOGIN2 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN2,
		CNC_FSOV_SOURCE_ANALOGIN3 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN3,
		CNC_FSOV_SOURCE_ANALOGIN4 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN4,
		CNC_FSOV_SOURCE_ANALOGIN5 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN5,
		CNC_FSOV_SOURCE_ANALOGIN6 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN6,
		CNC_FSOV_SOURCE_ANALOGIN7 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN7,
		CNC_FSOV_SOURCE_ANALOGIN8 = CNC_FEEDSPEED_OVERRIDE_SOURCE::CNC_FSOV_SOURCE_ANALOGIN8,


	} CncFeedspeedOverrideSource;
	typedef public enum class CncRotAxisOption
	{
		CNC_ROT_OPT_ROT = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_ROT,
		CNC_ROT_OPT_SLAVE_TO_X = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_SLAVE_TO_X,
		CNC_ROT_OPT_SLAVE_TO_Y = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_SLAVE_TO_Y,
		CNC_ROT_OPT_SLAVE_TO_Z = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_SLAVE_TO_Z,
		CNC_ROT_OPT_FOAMCUT = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_FOAMCUT,
		CNC_ROT_OPT_4AX_MILLING = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_4AX_MILLING,
		CNC_ROT_OPT_2ND_Z = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_2ND_Z,
		CNC_ROT_OPT_TAN_KNIFE = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_TAN_KNIFE,
		CNC_ROT_OPT_LAST = CNC_ROT_AXIS_OPTION::CNC_ROT_OPT_LAST
	} CncRotAxisOption;
	typedef public enum class CncMachineType
	{
		CNC_MACHINE_TYPE_MILLING = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_MILLING,
		CNC_MACHINE_TYPE_TURNING = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_TURNING,
		CNC_MACHINE_TYPE_TURNING_BACK_X = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_TURNING_BACK_X,
		CNC_MACHINE_TYPE_4AXES_FOAMCUTTER = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_4AXES_FOAMCUTTER,
		CNC_MACHINE_TYPE_PLASMACUTTER = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_PLASMACUTTER,
		CNC_MACHINE_TYPE_3D_PRINTING = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_3D_PRINTING,
		CNC_MACHINE_TYPE_LASER = CNC_MACHINE_TYPE::CNC_MACHINE_TYPE_LASER
	}CncMachineType;
	typedef public enum class CncLangT
	{
		CNC_LANG_ENGLISH = CNC_LANG_T::CNC_LANG_ENGLISH,
		CNC_LANG_GERMAN = CNC_LANG_T::CNC_LANG_GERMAN,
		CNC_LANG_DUTCH = CNC_LANG_T::CNC_LANG_DUTCH,
		CNC_LANG_ITALIAN = CNC_LANG_T::CNC_LANG_ITALIAN,
		CNC_LANG_FRENCH = CNC_LANG_T::CNC_LANG_FRENCH,
		CNC_LANG_SPANISH = CNC_LANG_T::CNC_LANG_SPANISH,
		CNC_LANG_PORTUGESE = CNC_LANG_T::CNC_LANG_PORTUGESE,
		CNC_LANG_TURKISH = CNC_LANG_T::CNC_LANG_TURKISH,
		CNC_LANG_JAPANESE = CNC_LANG_T::CNC_LANG_JAPANESE,
		CNC_LANG_GRC = CNC_LANG_T::CNC_LANG_GRC,
		CNC_LANG_HUN = CNC_LANG_T::CNC_LANG_HUN,
		CNC_LANG_CZE = CNC_LANG_T::CNC_LANG_CZE,
		CNC_LANG_HKR = CNC_LANG_T::CNC_LANG_HKR,
		CNC_LANG_CN = CNC_LANG_T::CNC_LANG_CN,
		CNC_LANG_KOREA = CNC_LANG_T::CNC_LANG_KOREA,
		CNC_LANG_RUSSIA = CNC_LANG_T::CNC_LANG_RUSSIA,
		CNC_LANG_NEW2 = CNC_LANG_T::CNC_LANG_NEW2,
		CNC_LANG_NEW3 = CNC_LANG_T::CNC_LANG_NEW3,
		CNC_LANG_LAST = CNC_LANG_T::CNC_LANG_LAST,		//Keep last

	} CncLangT;
	typedef public enum class CncErrorClass
	{
		CNC_EC_INFO = CNC_ERROR_CLASS::CNC_EC_INFO,   /* Info, no user action                    */
		CNC_EC_DIALOG = CNC_ERROR_CLASS::CNC_EC_DIALOG,     /* For user interaction with part program  */
		CNC_EC_USERACTION = CNC_ERROR_CLASS::CNC_EC_USERACTION, /*  user action required                   */
		CNC_EC_WARNING = CNC_ERROR_CLASS::CNC_EC_WARNING,    /* Warning eventual user action            */
		CNC_EC_STOP = CNC_ERROR_CLASS::CNC_EC_STOP,       /* Stopped on path                         */
		CNC_EC_QSTOP = CNC_ERROR_CLASS::CNC_EC_QSTOP,      /* Stop immediate, path not maintained     */
		CNC_EC_ABORT = CNC_ERROR_CLASS::CNC_EC_ABORT,      /* Emergency stop                          */
		CNC_EC_BUG = CNC_ERROR_CLASS::CNC_EC_BUG,        /* SW bug report to supplier               */
		CNC_EC_FATAL = CNC_ERROR_CLASS::CNC_EC_FATAL      /* unrecoverable system failure            */

	} CncErrorClass;
	typedef public enum class CncIeState
	{
		CNC_IE_POWERUP_STATE = CNC_IE_STATE::CNC_IE_POWERUP_STATE, /* no interpreter threads running yet */
		CNC_IE_IDLE_STATE = CNC_IE_STATE::CNC_IE_IDLE_STATE,               /* thread is started but IE not initialized */
		CNC_IE_READY_STATE = CNC_IE_STATE::CNC_IE_READY_STATE,              /* ready to load/run */
		CNC_IE_EXEC_ERROR_STATE = CNC_IE_STATE::CNC_IE_EXEC_ERROR_STATE,         /* Execution error */
		CNC_IE_INT_ERROR_STATE = CNC_IE_STATE::CNC_IE_INT_ERROR_STATE,          /* interpreter error */
		CNC_IE_ABORTED_STATE = CNC_IE_STATE::CNC_IE_ABORTED_STATE,            /* job was aborted */

																			  /* Running states from which Pause is possible */
																			  CNC_IE_RUNNING_JOB_STATE = CNC_IE_STATE::CNC_IE_RUNNING_JOB_STATE,        /* Job running */
																			  CNC_IE_RUNNING_LINE_STATE = CNC_IE_STATE::CNC_IE_RUNNING_LINE_STATE,       /* single line running */
																			  CNC_IE_RUNNING_SUB_STATE = CNC_IE_STATE::CNC_IE_RUNNING_SUB_STATE,        /* single subroutine running */
																			  CNC_IE_RUNNING_SUB_SEARCH_STATE = CNC_IE_STATE::CNC_IE_RUNNING_SUB_SEARCH_STATE, /* single subroutine running from search */
																			  CNC_IE_RUNNING_LINE_SEARCH_STATE = CNC_IE_STATE::CNC_IE_RUNNING_LINE_SEARCH_STATE,/* single line running from search*/

																																								/* the belonging paused states */
																																								CNC_IE_PAUSED_LINE_STATE = CNC_IE_STATE::CNC_IE_PAUSED_LINE_STATE,        /* single line paused, by pause command */
																																								CNC_IE_PAUSED_JOB_STATE = CNC_IE_STATE::CNC_IE_PAUSED_JOB_STATE,         /* paused running job, by pause command */
																																								CNC_IE_PAUSED_SUB_STATE = CNC_IE_STATE::CNC_IE_PAUSED_SUB_STATE,         /* paused running sub , by pause command */
																																								CNC_IE_PAUSED_LINE_SEARCH_STATE = CNC_IE_STATE::CNC_IE_PAUSED_LINE_SEARCH_STATE, /* paused running line search line running from search*/
																																								CNC_IE_PAUSED_SUB_SEARCH_STATE = CNC_IE_STATE::CNC_IE_PAUSED_SUB_SEARCH_STATE,  /* paused running sub search subroutine running from search */

																																																												/* special Running states, no pause possible */
																																																												CNC_IE_RUNNING_HANDWHEEL_STATE = CNC_IE_STATE::CNC_IE_RUNNING_HANDWHEEL_STATE,  /* hand wheel operation */
																																																												CNC_IE_RUNNING_LINE_HANDWHEEL_STATE = CNC_IE_STATE::CNC_IE_RUNNING_LINE_HANDWHEEL_STATE,
																																																												CNC_IE_RUNNING_LINE_PAUSED_STATE = CNC_IE_STATE::CNC_IE_RUNNING_LINE_PAUSED_STATE,/* single line running from hand wheel mode, can only be G92... */
																																																												CNC_IE_RUNNING_AXISJOG_STATE = CNC_IE_STATE::CNC_IE_RUNNING_AXISJOG_STATE,    /* running joint jog */
																																																												CNC_IE_RUNNING_IPJOG_STATE = CNC_IE_STATE::CNC_IE_RUNNING_IPJOG_STATE,      /* running joint jog */

																																																																															/* Rendering and searching states */
																																																																															CNC_IE_RENDERING_GRAPH_STATE = CNC_IE_STATE::CNC_IE_RENDERING_GRAPH_STATE,    /* running interpreter for graph view only */
																																																																															CNC_IE_SEARCHING_STATE = CNC_IE_STATE::CNC_IE_SEARCHING_STATE,          /* searching line */
																																																																															CNC_IE_SEARCHED_DONE_STATE = CNC_IE_STATE::CNC_IE_SEARCHED_DONE_STATE,      /* searched line found */

																																																																															CNC_IE_LAST_STATE = CNC_IE_STATE::CNC_IE_LAST_STATE              /* keep last */
	} CncIeState;
	typedef public enum class CncPlane
	{
		CNC_PLANE_NONE = CNC_PLANE::CNC_PLANE_NONE,
		CNC_PLANE_XY = CNC_PLANE::CNC_PLANE_XY,
		CNC_PLANE_YZ = CNC_PLANE::CNC_PLANE_YZ,
		CNC_PLANE_XZ = CNC_PLANE::CNC_PLANE_XZ
	}CncPlane;
	typedef public enum class CncTrafficLightColor
	{
		CNC_TRAFFIC_LIGHT_COLOR_OFF = CNC_TRAFFIC_LIGHT_COLOR::CNC_TRAFFIC_LIGHT_COLOR_OFF,
		CNC_TRAFFIC_LIGHT_COLOR_GREEN = CNC_TRAFFIC_LIGHT_COLOR::CNC_TRAFFIC_LIGHT_COLOR_GREEN,
		CNC_TRAFFIC_LIGHT_COLOR_YELLOW = CNC_TRAFFIC_LIGHT_COLOR::CNC_TRAFFIC_LIGHT_COLOR_YELLOW,
		CNC_TRAFFIC_LIGHT_COLOR_RED = CNC_TRAFFIC_LIGHT_COLOR::CNC_TRAFFIC_LIGHT_COLOR_RED,
	} CncTrafficLightColor;
	typedef public enum class CncTrackingMode
	{
		CNC_TRACKMODE_OFF = CNC_TRACKING_MODE::CNC_TRACKMODE_OFF,
		CNC_TRACKMODE_HANDWHEEL_POS = CNC_TRACKING_MODE::CNC_TRACKMODE_HANDWHEEL_POS,
		CNC_TRACKMODE_HANDWHEEL_VEL = CNC_TRACKING_MODE::CNC_TRACKMODE_HANDWHEEL_VEL,
		CNC_TRACKMODE_POSITION = CNC_TRACKING_MODE::CNC_TRACKMODE_POSITION,
		CNC_TRACKMODE_VELOCITY = CNC_TRACKING_MODE::CNC_TRACKMODE_VELOCITY
	}  CncTrackingMode;
	typedef public enum class CncTrackSource
	{
		CNC_TRACKSOURCE_NONE = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_NONE,
		CNC_TRACKSOURCE_INTERNAL_HANDWHEEL1 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_HANDWHEEL1,
		CNC_TRACKSOURCE_INTERNAL_HANDWHEEL2 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_HANDWHEEL2,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN1 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN1,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN2 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN2,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN3 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN3,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN4 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN4,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN5 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN5,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN6 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN6,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN7 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN7,
		CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN8 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_INTERNAL_AUXANALOGIN8,
		CNC_TRACKSOURCE_THC_ANALOGIN = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_THC_ANALOGIN,
		CNC_TRACKSOURCE_TRACK_DATA_POSITION = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_TRACK_DATA_POSITION,
		CNC_TRACKSOURCE_TRACK_DATA_VELOCITY = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_TRACK_DATA_VELOCITY,
		CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL1 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL1,
		CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL2 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL2,
		CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL3 = CNC_TRACK_SOURCE::CNC_TRACKSOURCE_TRACK_DATA_HANDWHEEL3

	} CncTrackSource;
	typedef public enum class CncKineMaticsType
	{
		CNC_KINEMATICS_TYPE_UNDEFINED = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_UNDEFINED,
		CNC_KINEMATICS_TYPE_TRIVIAL = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_TRIVIAL,  /* 1:1 kins                                */
		CNC_KINEMATICS_TYPE_4AX_A_CILINDER = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_4AX_A_CILINDER,  /* Y mapped to rotate A                    */
		CNC_KINEMATICS_TYPE_VIRTUAL_C = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_VIRTUAL_C,  /* Virtual C axis rotates XY               */
		CNC_KINEMATICS_TYPE_LIN_DELTA = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_LIN_DELTA,  /* Linear delta robot                      */
		CNC_KINEMATICS_TYPE_COREXY = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_COREXY,
		//CNC_KINEMATICS_TYPE_RESERVED_13 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_13,  /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_12 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_12,  /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_11 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_11,  /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_10 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_10,  /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_9 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_9,  /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_8 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_8, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_7 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_7, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_6 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_6, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_5 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_5, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_4 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_4, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_3 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_3, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_2 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_2, /* Reserved for build in kins              */
		CNC_KINEMATICS_TYPE_RESERVED_1 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_RESERVED_1, /* Reserved for build in kins              */
		CNC_KINEMATICS_CUSTOM_1 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_1, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_2 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_2, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_3 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_3, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_4 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_4, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_5 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_5, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_6 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_6, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_7 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_7, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_8 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_8, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_9 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_9, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_10 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_10, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_11 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_11, /* reservation for custom kinematics types */
		CNC_KINEMATICS_CUSTOM_12 = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_CUSTOM_12,  /* reservation for custom kinematics types */
		CNC_KINEMATICS_TYPE_TRUNNION_AC = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_TRUNNION_AC,
		CNC_KINEMATICS_TYPE_TRUNNION_BC = CNC_KINEMATICS_TYPE::CNC_KINEMATICS_TYPE_TRUNNION_BC
	}CncKineMaticsType;
	typedef public enum class CncOnOff
	{
		CNC_OFF = CNC_ONOFF::CNC_OFF,
		CNC_ON = CNC_ONOFF::CNC_ON,
	}CncOnOff;
	typedef public enum class KinControlId
	{
		KIN_CONTROL_FIRST,
		CNC_KIN_CONTROL_ID_OPEN = KIN_CONTROL_ID::CNC_KIN_CONTROL_ID_OPEN,    /* Used during initialization of the CNC */
		CNC_KIN_CONTROL_ID_CLOSE = KIN_CONTROL_ID::CNC_KIN_CONTROL_ID_CLOSE,    /* Used during shutdown of the CNC       */
		CNC_KIN_CONTROL_ID_OFF = KIN_CONTROL_ID::CNC_KIN_CONTROL_ID_OFF,    /* Kinematics switched off			    */
		CNC_KIN_CONTROL_ID_ON = KIN_CONTROL_ID::CNC_KIN_CONTROL_ID_ON,    /* Kinematics switched on				*/
		KIN_CONTROL_ID_RES1 = KIN_CONTROL_ID::KIN_CONTROL_ID_RES1,        /* System reserved        				*/
		KIN_CONTROL_ID_RES2 = KIN_CONTROL_ID::KIN_CONTROL_ID_RES2,        /* System reserved        				*/
		KIN_CONTROL_ID_RES3 = KIN_CONTROL_ID::KIN_CONTROL_ID_RES3,        /* System reserved        				*/
		KIN_CONTROL_ID_RES4 = KIN_CONTROL_ID::KIN_CONTROL_ID_RES4,        /* System reserved        				*/
		KIN_CONTROL_ID_JOINT_LIMITS = KIN_CONTROL_ID::KIN_CONTROL_ID_JOINT_LIMITS,/* System reserved        				*/
		KIN_CONTROL_ID_KIN_LIMITS = KIN_CONTROL_ID::KIN_CONTROL_ID_KIN_LIMITS, /* System reserved        				*/
		KIN_CONTROL_ID_USER1 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER1,       /* Kinematics specific control ID		*/
		KIN_CONTROL_ID_USER2 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER2,       /* Kinematics specific control ID		*/
		KIN_CONTROL_ID_USER3 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER3,       /* Kinematics specific control ID		*/
		KIN_CONTROL_ID_USER4 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER4,       /* Kinematics specific control ID		*/
		KIN_CONTROL_ID_USER5 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER5,       /* Kinematics specific control ID		*/
		KIN_CONTROL_ID_USER6 = KIN_CONTROL_ID::KIN_CONTROL_ID_USER6,       /* Kinematics specific control ID		*/
		KIN_CONTROL_LAST,
	}KinControlId;
	typedef public enum class CncMoveType
	{
		CNC_MOVE_TYPE_UNKNOWN = CNC_MOVE_TYPE::CNC_MOVE_TYPE_UNKNOWN,
		CNC_MOVE_TYPE_G0 = CNC_MOVE_TYPE::CNC_MOVE_TYPE_G0,
		CNC_MOVE_TYPE_G1 = CNC_MOVE_TYPE::CNC_MOVE_TYPE_G1,
		CNC_MOVE_TYPE_ARC = CNC_MOVE_TYPE::CNC_MOVE_TYPE_ARC,
		CNC_MOVE_TYPE_PROBE = CNC_MOVE_TYPE::CNC_MOVE_TYPE_PROBE,
		CNC_MOVE_TYPE_JOG = CNC_MOVE_TYPE::CNC_MOVE_TYPE_JOG,
		CNC_MOVE_TYPE_HOME = CNC_MOVE_TYPE::CNC_MOVE_TYPE_HOME,
		CNC_MOVE_TYPE_ORIGIN_OFFSET = CNC_MOVE_TYPE::CNC_MOVE_TYPE_ORIGIN_OFFSET,
		CNC_MOVE_TYPE_START_POSITION = CNC_MOVE_TYPE::CNC_MOVE_TYPE_START_POSITION,
		CNC_MOVE_TYPE_SET_GRAPH_START_POINT = CNC_MOVE_TYPE::CNC_MOVE_TYPE_SET_GRAPH_START_POINT,
		CNC_MOVE_TYPE_OUT_LINE = CNC_MOVE_TYPE::CNC_MOVE_TYPE_OUT_LINE,
		CNC_MOVE_TYPE_END = CNC_MOVE_TYPE::CNC_MOVE_TYPE_END,
		CNC_MOVE_TYPE_END_COLLISION = CNC_MOVE_TYPE::CNC_MOVE_TYPE_END_COLLISION
	}CncMoveType;
	typedef public enum class Cnc3DPCommandId
	{
		CNC_3DP_SET_EXTRUDER_ONOFF = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_ONOFF,
		CNC_3DP_SET_EXTRUDER_STANDBY = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_STANDBY,
		CNC_3DP_SET_EXTRUDER_PIDONOFF = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_PIDONOFF,
		CNC_3DP_SET_EXTRUDER_TEMP_MAX = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_TEMP_MAX,
		CNC_3DP_SET_EXTRUDER_TEMP = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_TEMP,
		CNC_3DP_SET_EXTRUDER_TEMP_WAIT = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_TEMP_WAIT,
		CNC_3DP_SET_EXTRUDER_PARS = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_PARS,
		CNC_3DP_SET_EXTRUDER_POWER = CNC_3DP_COMMAND_ID::CNC_3DP_SET_EXTRUDER_POWER,
		CNC_3DP_SET_HEATBED_ONOFF = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_ONOFF,
		CNC_3DP_SET_HEATBED_STANDBY = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_STANDBY,
		CNC_3DP_SET_HEATBED_PIDONOFF = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_PIDONOFF,
		CNC_3DP_SET_HEATBED_TEMP_WAIT = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_TEMP_WAIT,
		CNC_3DP_SET_HEATBED_TEMP = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_TEMP,
		CNC_3DP_SET_HEATBED_PARS = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_PARS,
		CNC_3DP_SET_HEATBED_POWER = CNC_3DP_COMMAND_ID::CNC_3DP_SET_HEATBED_POWER,
		CNC_3DP_SET_WPFAN_ONOFF = CNC_3DP_COMMAND_ID::CNC_3DP_SET_WPFAN_ONOFF,
		CNC_3DP_SET_WPFAN_STANDBY = CNC_3DP_COMMAND_ID::CNC_3DP_SET_WPFAN_STANDBY,
		CNC_3DP_SET_WPFAN_POWER = CNC_3DP_COMMAND_ID::CNC_3DP_SET_WPFAN_POWER,
		CNC_3DP_SET_WPFAN_PARS = CNC_3DP_COMMAND_ID::CNC_3DP_SET_WPFAN_PARS,
		CNC_3DP_ALL_OFF = CNC_3DP_COMMAND_ID::CNC_3DP_ALL_OFF,
		CNC_3DP_DEFAULT_PARS = CNC_3DP_COMMAND_ID::CNC_3DP_DEFAULT_PARS,
		CNC_3DP_EXTRUDER_RES_OVERRIDE = CNC_3DP_COMMAND_ID::CNC_3DP_EXTRUDER_RES_OVERRIDE,
		CNC_3DP_UPDATE_SHOW_AS_GO_FEED = CNC_3DP_COMMAND_ID::CNC_3DP_UPDATE_SHOW_AS_GO_FEED
	} Cnc3DPCommandId;
	typedef public enum class CncUioActions
	{
		CNC_UIOACTION_NONE = CNC_UIO_ACTIONS::CNC_UIOACTION_NONE,
		CNC_UIOACTION_GENERAL_UI_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_GENERAL_UI_SEPARATOR,
		CNC_UIOACTION_MODE_OPERATE = CNC_UIO_ACTIONS::CNC_UIOACTION_MODE_OPERATE,
		CNC_UIOACTION_TAB_NEXT_MODE = CNC_UIO_ACTIONS::CNC_UIOACTION_TAB_NEXT_MODE,
		CNC_UIOACTION_TAB_PREVIOUS_MODE = CNC_UIO_ACTIONS::CNC_UIOACTION_TAB_PREVIOUS_MODE,
		CNC_UIOACTION_NEXT_STATUS = CNC_UIO_ACTIONS::CNC_UIOACTION_NEXT_STATUS,
		CNC_UIOACTION_PREVIOUS_STATUS = CNC_UIO_ACTIONS::CNC_UIOACTION_PREVIOUS_STATUS,
		CNC_UIOACTION_TOGGLE_WORKMACHINE = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_WORKMACHINE,
		CNC_UIOACTION_TOGGLE_MDI = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_MDI,
		CNC_UIOACTION_TO_MAIN_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_MAIN_MENU,
		CNC_UIOACTION_TO_HOME_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_HOME_MENU,
		CNC_UIOACTION_TO_ZERO_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_ZERO_MENU,
		CNC_UIOACTION_TO_AUTO_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_AUTO_MENU,
		CNC_UIOACTION_TO_MACHIO_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_MACHIO_MENU,
		CNC_UIOACTION_TO_GRAPH_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_GRAPH_MENU,
		CNC_UIOACTION_TO_JOG_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_JOG_MENU,
		CNC_UIOACTION_TO_JOGPAD = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_JOGPAD,
		CNC_UIOACTION_TO_USR1_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_USR1_MENU,
		CNC_UIOACTION_TO_USR2_MENU = CNC_UIO_ACTIONS::CNC_UIOACTION_TO_USR2_MENU,
		CNC_UIOACTION_USERBUTTONS_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_USERBUTTONS_SEPARATOR, //User buttons
		CNC_UIOACTION_SUB_USER1 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER1,
		CNC_UIOACTION_SUB_USER2 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER2,
		CNC_UIOACTION_SUB_USER3 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER3,
		CNC_UIOACTION_SUB_USER4 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER4,
		CNC_UIOACTION_SUB_USER5 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER5,
		CNC_UIOACTION_SUB_USER6 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER6,
		CNC_UIOACTION_SUB_USER7 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER7,
		CNC_UIOACTION_SUB_USER8 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER8,
		CNC_UIOACTION_SUB_USER9 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER9,
		CNC_UIOACTION_SUB_USER10 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER10,
		CNC_UIOACTION_SUB_USER11 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER11,
		CNC_UIOACTION_SUB_USER12 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER12,
		CNC_UIOACTION_SUB_USER13 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER13,
		CNC_UIOACTION_SUB_USER14 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER14,
		CNC_UIOACTION_SUB_USER15 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER15,
		CNC_UIOACTION_SUB_USER16 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER16,
		CNC_UIOACTION_SUB_USER17 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER17,
		CNC_UIOACTION_SUB_USER18 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER18,
		CNC_UIOACTION_SUB_USER19 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER19,
		CNC_UIOACTION_SUB_USER20 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_USER20,
		CNC_UIOACTION_MAIN_BUTTONS_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_MAIN_BUTTONS_SEPARATOR, //Main buttons
		CNC_UIOACTION_CLOSE_PROGRAM = CNC_UIO_ACTIONS::CNC_UIOACTION_CLOSE_PROGRAM,
		CNC_UIOACTION_MAIN_RESET = CNC_UIO_ACTIONS::CNC_UIOACTION_MAIN_RESET,
		CNC_UIOACTION_HOMESEQ = CNC_UIO_ACTIONS::CNC_UIOACTION_HOMESEQ,
		CNC_UIOACTION_ZERO_BUTTONS_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_ZERO_BUTTONS_SEPARATOR, //Zero buttons
		CNC_UIOACTION_SUB_ZERO_X = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_X,
		CNC_UIOACTION_SUB_ZERO_Y = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_Y,
		CNC_UIOACTION_SUB_ZERO_Z = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_Z,
		CNC_UIOACTION_SUB_ZERO_4 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_4,
		CNC_UIOACTION_SUB_ZERO_5 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_5,
		CNC_UIOACTION_SUB_ZERO_6 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_ZERO_6,
		CNC_UIOACTION_HANDWHEEL_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_HANDWHEEL_SEPARATOR, //Hand wheel
		CNC_UIOACTION_JOG_HANDWHEEL_ON_X = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_X,
		CNC_UIOACTION_JOG_HANDWHEEL_ON_Y = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_Y,
		CNC_UIOACTION_JOG_HANDWHEEL_ON_Z = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_Z,
		CNC_UIOACTION_JOG_HANDWHEEL_ON_A = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_A,
		CNC_UIOACTION_JOG_HANDWHEEL_ON_B = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_B,
		CNC_UIOACTION_JOG_HANDWHEEL_ON_C = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_ON_C,
		CNC_UIOACTION_JOG_ALL_HANDWHEELS_ON = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_ALL_HANDWHEELS_ON, //Dedicated hand wheels usable if there are more than one.
		CNC_UIOACTION_JOG_HANDWHEEL_OFF = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_HANDWHEEL_OFF,
		CNC_UIOACTION_SUB_JOG_HW01 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_JOG_HW01,
		CNC_UIOACTION_SUB_JOG_HW1 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_JOG_HW1,
		CNC_UIOACTION_SUB_JOG_HW10 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_JOG_HW10,
		CNC_UIOACTION_SUB_JOG_HW100 = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_JOG_HW100,
		CNC_UIOACTION_JOGMODES_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_JOGMODES_SEPARATOR, //Jog modes 
		CNC_UIOACTION_SUB_JOG_CONTINU = CNC_UIO_ACTIONS::CNC_UIOACTION_SUB_JOG_CONTINU,
		CNC_UIOACTION_SELECT_JOG_STEP_0001 = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_STEP_0001,
		CNC_UIOACTION_SELECT_JOG_STEP_001 = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_STEP_001,
		CNC_UIOACTION_SELECT_JOG_STEP_01 = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_STEP_01,
		CNC_UIOACTION_SELECT_JOG_STEP_1 = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_STEP_1,
		CNC_UIOACTION_JOG_MODE_PREVIOUS = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_MODE_PREVIOUS,
		CNC_UIOACTION_JOG_MODE_NEXT = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_MODE_NEXT,
		CNC_UIOACTION_JOGSPEED_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_JOGSPEED_SEPARATOR, //Jog Speed
		CNC_UIOACTION_SELECT_LOW_SPEED = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_LOW_SPEED,
		CNC_UIOACTION_SELECT_MED_SPEED = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_MED_SPEED,
		CNC_UIOACTION_SELECT_HI_SPEED = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_HI_SPEED,
		CNC_UIOACTION_JOGSEL_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_JOGSEL_SEPARATOR, //Jogging with selection
		CNC_UIOACTION_SELECT_JOG_X = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_X,
		CNC_UIOACTION_SELECT_JOG_Y = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_Y,
		CNC_UIOACTION_SELECT_JOG_Z = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_Z,
		CNC_UIOACTION_SELECT_JOG_A = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_A,
		CNC_UIOACTION_SELECT_JOG_B = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_B,
		CNC_UIOACTION_SELECT_JOG_C = CNC_UIO_ACTIONS::CNC_UIOACTION_SELECT_JOG_C,
		CNC_UIOACTION_START_JOG_MINUS = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS,
		CNC_UIOACTION_START_JOG_PLUS = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS,
		CNC_UIOACTION_JOG_START_STOP_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_JOG_START_STOP_SEPARATOR, //Jogging start and stop
		CNC_UIOACTION_STOP_JOG = CNC_UIO_ACTIONS::CNC_UIOACTION_STOP_JOG,
		CNC_UIOACTION_START_JOG_MINUS_X = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_X,
		CNC_UIOACTION_START_JOG_PLUS_X = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_X,
		CNC_UIOACTION_START_JOG_MINUS_Y = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_Y,
		CNC_UIOACTION_START_JOG_PLUS_Y = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_Y,
		CNC_UIOACTION_START_JOG_MINUS_Z = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_Z,
		CNC_UIOACTION_START_JOG_PLUS_Z = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_Z,
		CNC_UIOACTION_START_JOG_MINUS_A = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_A,
		CNC_UIOACTION_START_JOG_PLUS_A = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_A,
		CNC_UIOACTION_START_JOG_MINUS_B = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_B,
		CNC_UIOACTION_START_JOG_PLUS_B = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_B,
		CNC_UIOACTION_START_JOG_MINUS_C = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_MINUS_C,
		CNC_UIOACTION_START_JOG_PLUS_C = CNC_UIO_ACTIONS::CNC_UIOACTION_START_JOG_PLUS_C,
		CNC_UIOACTION_PROGRAM_RUN_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_PROGRAM_RUN_SEPARATOR, //Program running
		CNC_UIOACTION_LOADJOB = CNC_UIO_ACTIONS::CNC_UIOACTION_LOADJOB,
		CNC_UIOACTION_RUN = CNC_UIO_ACTIONS::CNC_UIOACTION_RUN,
		CNC_UIOACTION_PAUSE = CNC_UIO_ACTIONS::CNC_UIOACTION_PAUSE,
		CNC_UIOACTION_TOGGLE_SINGLE = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_SINGLE,
		CNC_UIOACTION_TOGGLE_BLOCKDELETE = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_BLOCKDELETE,
		CNC_UIOACTION_PLUS_FEED = CNC_UIO_ACTIONS::CNC_UIOACTION_PLUS_FEED,
		CNC_UIOACTION_MIN_FEED = CNC_UIO_ACTIONS::CNC_UIOACTION_MIN_FEED,
		CNC_UIOACTION_PLUS_SPEED = CNC_UIO_ACTIONS::CNC_UIOACTION_PLUS_SPEED,
		CNC_UIOACTION_MIN_SPEED = CNC_UIO_ACTIONS::CNC_UIOACTION_MIN_SPEED,
		CNC_UIOACTION_FEEDOV_100_PERCENT = CNC_UIO_ACTIONS::CNC_UIOACTION_FEEDOV_100_PERCENT,
		CNC_UIOACTION_SPEEDOV_100_PERCENT = CNC_UIO_ACTIONS::CNC_UIOACTION_SPEEDOV_100_PERCENT,
		CNC_UIOACTION_TEACH_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_TEACH_SEPARATOR, //Teach
		CNC_UIOACTION_OPEN_TEACH = CNC_UIO_ACTIONS::CNC_UIOACTION_OPEN_TEACH,
		CNC_UIOACTION_ADD_TEACH_POINT = CNC_UIO_ACTIONS::CNC_UIOACTION_ADD_TEACH_POINT,
		CNC_UIOACTION_EDIT_TEACH = CNC_UIO_ACTIONS::CNC_UIOACTION_EDIT_TEACH,
		CNC_UIOACTION_IO_ONOFF_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_IO_ONOFF_SEPARATOR, //IO on/off
		CNC_UIOACTION_SPINDLE_ON_R = CNC_UIO_ACTIONS::CNC_UIOACTION_SPINDLE_ON_R,
		CNC_UIOACTION_SPINDLE_ON_L = CNC_UIO_ACTIONS::CNC_UIOACTION_SPINDLE_ON_L,
		CNC_UIOACTION_SPINDLE_OFF = CNC_UIO_ACTIONS::CNC_UIOACTION_SPINDLE_OFF,
		CNC_UIOACTION_FLOODON = CNC_UIO_ACTIONS::CNC_UIOACTION_FLOODON,
		CNC_UIOACTION_MISTON = CNC_UIO_ACTIONS::CNC_UIOACTION_MISTON,
		CNC_UIOACTION_TOGGLE_AUX1 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX1,
		CNC_UIOACTION_TOGGLE_AUX2 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX2,
		CNC_UIOACTION_TOGGLE_AUX3 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX3,
		CNC_UIOACTION_TOGGLE_AUX4 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX4,
		CNC_UIOACTION_TOGGLE_AUX5 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX5,
		CNC_UIOACTION_TOGGLE_AUX6 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX6,
		CNC_UIOACTION_TOGGLE_AUX7 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX7,
		CNC_UIOACTION_TOGGLE_AUX8 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX8,
		CNC_UIOACTION_TOGGLE_AUX9 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX9,
		CNC_UIOACTION_TOGGLE_AUX10 = CNC_UIO_ACTIONS::CNC_UIOACTION_TOGGLE_AUX10,
		CNC_UIOACTION_ANALOGS_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_ANALOGS_SEPARATOR, //Analog
		CNC_UIOACTION_ANA_FEEDOV_FACTOR = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_FEEDOV_FACTOR,
		CNC_UIOACTION_ANA_SPEEDOV_FACTOR = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_SPEEDOV_FACTOR,
		CNC_UIOACTION_ANA_RESERVED1 = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_RESERVED1,
		CNC_UIOACTION_ANA_RESERVED2 = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_RESERVED2,
		CNC_UIOACTION_ANA_RESERVED3 = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_RESERVED3,
		CNC_UIOACTION_ANA_RESERVED4 = CNC_UIO_ACTIONS::CNC_UIOACTION_ANA_RESERVED4,
		CNC_UIOACTION_FKEYS_SEPARATOR = CNC_UIO_ACTIONS::CNC_UIOACTION_FKEYS_SEPARATOR, //Function keys
		CNC_UIOACTION_F1 = CNC_UIO_ACTIONS::CNC_UIOACTION_F1,
		CNC_UIOACTION_F2 = CNC_UIO_ACTIONS::CNC_UIOACTION_F2,
		CNC_UIOACTION_F3 = CNC_UIO_ACTIONS::CNC_UIOACTION_F3,
		CNC_UIOACTION_F4 = CNC_UIO_ACTIONS::CNC_UIOACTION_F4,
		CNC_UIOACTION_F5 = CNC_UIO_ACTIONS::CNC_UIOACTION_F5,
		CNC_UIOACTION_F6 = CNC_UIO_ACTIONS::CNC_UIOACTION_F6,
		CNC_UIOACTION_F7 = CNC_UIO_ACTIONS::CNC_UIOACTION_F7,
		CNC_UIOACTION_F8 = CNC_UIO_ACTIONS::CNC_UIOACTION_F8,
		CNC_UIOACTION_F9 = CNC_UIO_ACTIONS::CNC_UIOACTION_F9,
		CNC_UIOACTION_F10 = CNC_UIO_ACTIONS::CNC_UIOACTION_F10,
		CNC_UIOACTION_F11 = CNC_UIO_ACTIONS::CNC_UIOACTION_F11,
		CNC_UIOACTION_F12 = CNC_UIO_ACTIONS::CNC_UIOACTION_F12,
		CNC_UIOACTION_C_F1 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F1,
		CNC_UIOACTION_C_F2 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F2,
		CNC_UIOACTION_C_F3 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F3,
		CNC_UIOACTION_C_F4 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F4,
		CNC_UIOACTION_C_F5 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F5,
		CNC_UIOACTION_C_F7 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F7,
		CNC_UIOACTION_C_F9 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F9,
		CNC_UIOACTION_C_F10 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F10,
		CNC_UIOACTION_C_F11 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F11,
		CNC_UIOACTION_C_F12 = CNC_UIO_ACTIONS::CNC_UIOACTION_C_F12,
		CNC_UIOACTION_A_F5 = CNC_UIO_ACTIONS::CNC_UIOACTION_A_F5,
		CNC_UIOACTION_A_F6 = CNC_UIO_ACTIONS::CNC_UIOACTION_A_F6,
		CNC_UIOACTION_LAST = CNC_UIO_ACTIONS::CNC_UIOACTION_LAST
	}CncUioActions;

	//cnclang.h

	typedef public enum class CncLangMax
	{
		TextLength = CNC_LANG_MAX_TEXT_LEN,
		LineLength = CNC_LANG_MAX_LINE_LEN,
	};

	//--

	//
	//cncrc status voor alle functies die CNC_RC returnen
	static Cnc_Rc _LastCNC_RC = Cnc_Rc::CNC_RC_ERR_SERVER_NOT_RUNNING;// is op te vragen bij G_GetCncServer
	static const int SizeOfintx32 = 4;
	static const int SizeOfdoublex32 = 8;
	static const int CharCharacterBuffer = 80;
	static const int RequestCodebytes = 256;
	static const int SizeOfWchar_t = 2;
	//static int NumberOfCreatedPointers = 0;
	//static int NumberOfDeletedPointers = 0;
	static bool AppIsPlugin = true;//set by G_GetCncServer;

	static void PluginError()
	{
		System::Diagnostics::Debug::WriteLine("-------------------------------------------------------------------------------");
		System::Diagnostics::Debug::WriteLine("WARRING:Program runs at plugin. IT IS POSSIBLE THAT FIFO/SERVER IS CONSUMED BY ANOTHER APP");
		System::Diagnostics::Debug::WriteLine("	You can bypass this restriction to call first \"G_GetCncServer.ConnectServer(\"\")\" and then by setting: G_GetCncServer.IssPlugin to false");
		System::Diagnostics::Debug::WriteLine("	If you bypass this restriction it is possible that the main app can not work correctly anymore");
		System::Diagnostics::Debug::WriteLine("--------------------------------------------------------------------------------");
	}
	static void StatusPropertyLockedDebug()
	{
		System::Diagnostics::Debug::WriteLine("Warning: Property can not be changed because it is locked. Set property: LockOverrideDataInPointer to false");
	}

	
		//
		//struct (zoals in usb cnc api)
}
//file checked for usbcnc 4.3 but not for not for sure