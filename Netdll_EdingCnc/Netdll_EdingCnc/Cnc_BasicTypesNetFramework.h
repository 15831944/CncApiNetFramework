#pragma once
#include <iostream>
#include "cncapi/cncapi.h"
#include "StringConversie.h"
#include "typedefEnumClass.h"
#include "Cnc_ManagedTemplate.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;



namespace OosterhofDesign
{
	
	public ref class CncKeepUiAliveFunction
	{
	private:
		Managedstruct<int>^ _Functionparameter = gcnew Managedstruct<int>(nullptr,1);
	internal:
		bool FunctionIsset = false;
		GCHandle FunctionGcHandle;
		IntPtr FunctionIntPtr;
		CNC_KEEP_UI_ALIVE_FUNCTION Functionpfunc = nullptr;

		int * ParsFuctionPointerParameter()
		{
			return _Functionparameter->ValuePointertype;
		}
	public:
		delegate int UiAliveFunction(int% PARAMETER);
		property int Functionparameter
		{
			int get()
			{
				return _Functionparameter->ValuePointertype[0];
			}
			void set(int Value)
			{
				_Functionparameter->ValuePointertype[0] = Value;
			}
		}
		

		CncKeepUiAliveFunction(Delegate^ DelegatefunctionCall, int parameter)
		{
			SetCncKeepUiAliveFunction(DelegatefunctionCall, parameter);
		}

		!CncKeepUiAliveFunction()
		{
			if (FunctionIsset == true)
			{
				FunctionGcHandle.Free();
				FunctionIsset = false;
				System::Diagnostics::Debug::WriteLine("gc:FunctionGcHandle.Free();");
			}
			_Functionparameter->DeletePointer(false);
		}
		~CncKeepUiAliveFunction() { this->!CncKeepUiAliveFunction(); }
		bool SetCncKeepUiAliveFunction(Delegate^ DelegatefunctionCall, int parameter)
		{
			if (DelegatefunctionCall != nullptr)
			{
				if (FunctionIsset == true)
				{
					FunctionGcHandle.Free();
					FunctionIsset = false;
					System::Diagnostics::Debug::WriteLine("FunctionGcHandle.Free();");
				}
				FunctionGcHandle = GCHandle::Alloc(DelegatefunctionCall);
				FunctionIntPtr = Marshal::GetFunctionPointerForDelegate(DelegatefunctionCall);
				Functionpfunc = static_cast<CNC_KEEP_UI_ALIVE_FUNCTION>(FunctionIntPtr.ToPointer());
				Functionparameter = parameter;
				FunctionIsset = true;
			}
			return FunctionIsset;
		}
		int testfunctionpointer()
		{
			int Return = 0;
			//Console::WriteLine("This function is only for testing a DelegatefunctionCall to managed code (functionpointer)");
			//typedef int(__stdcall *ANSWERCB)(void);
			//ANSWERCB cb = static_cast<ANSWERCB>(_IntPtr.ToPointer());
			//IntPtr ip2 = GCHandle::ToIntPtr(_GCHandle);
			//int obj = ip2.ToInt32();

			//int(*Csharp)(void) = (int)_GCHandle.Target;
			//https://beginnersbook.com/2014/01/c-function-pointers/
			//https://msdn.microsoft.com/nl-nl/library/windows/desktop/44ey4b32(v=vs.100).aspx
			//https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/delegates/using-delegates
			//Csharp();
			if (FunctionIsset == true)
			{
				Return = Functionpfunc(ParsFuctionPointerParameter());
			}
			else
			{
				Console::WriteLine("Cannot execute. No function is set with SetCncKeepUiAliveFunction");
			}
			return Return;
		}
	};


	public ref class CncUserButton :public Managedstruct<CNC_USER_BUTTON>
	{
	public:
		CncUserButton(CNC_USER_BUTTON * _USER_BUTTON) :Managedstruct(_USER_BUTTON, 1) {}
		CncUserButton() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncUserButton^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int enabled
		{
			int get()
			{
				return ValuePointertype->enabled;
			}
			void set(int Value)
			{
				ValuePointertype->enabled = Value;
			}
		}
		property String^ buttonText
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->buttonText);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->buttonText), Value, ValuePointertype->buttonText);
			}
		}
		property String^ iconFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->iconFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->iconFileName), Value, ValuePointertype->iconFileName);
			}
		}
	};
	public ref class CncLogMessage : public Managedstruct<CNC_LOG_MESSAGE>
	{
	public:
		CncLogMessage(CNC_LOG_MESSAGE * _CNC_LOG_MESSAGE) :Managedstruct(_CNC_LOG_MESSAGE, 1) {}
		CncLogMessage() :Managedstruct(nullptr) {}
		/* code where the error or what kind of message did occur, see CNC_RC */
		bool CopyUnmanagedPointer(CncLogMessage^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property bool IsPlugin
		{
			bool get()
			{
				return AppIsPlugin;
			}
		}

		property Cnc_Rc code
		{
			Cnc_Rc get()
			{
				return(Cnc_Rc)ValuePointertype->code;
			}
		}

		/* the error class */
		property CncErrorClass errorClass
		{
			CncErrorClass get()
			{
				return (CncErrorClass)ValuePointertype->errorClass;
			}
		}

		/* subcode is only relevant when code specifies a subcode */
		property int subCode
		{
			int get()
			{
				return ValuePointertype->subCode;
			}
		}
		/* textual error or dialog description */
		property String^ text//[CNC_MAX_LOGGING_TEXT]
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->text);
			}
		}

		/* parameter names */
		property String^ par1Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{

				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par1Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par1Name), Value, ValuePointertype->par1Name);
			}
		}
		property String^ par2Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par2Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par2Name), Value, ValuePointertype->par2Name);
			}
		}
		property String^ par3Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par3Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par3Name), Value, ValuePointertype->par3Name);
			}
		}
		property String^ par4Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par4Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par4Name), Value, ValuePointertype->par4Name);
			}
		}
		property String^ par5Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par5Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par5Name), Value, ValuePointertype->par5Name);
			}
		}
		property String^ par6Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par6Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par6Name), Value, ValuePointertype->par6Name);
			}
		}
		property String^ par7Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par7Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par7Name), Value, ValuePointertype->par7Name);
			}
		}
		property String^ par8Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par8Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par8Name), Value, ValuePointertype->par8Name);
			}
		}

		property String^ par9Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par9Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par9Name), Value, ValuePointertype->par9Name);
			}
		}
		property String^ par10Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par10Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par10Name), Value, ValuePointertype->par10Name);
			}
		}
		property String^ par11Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par11Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par11Name), Value, ValuePointertype->par11Name);
			}
		}
		property String^ par12Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par12Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par12Name), Value, ValuePointertype->par12Name);
			}
		}
		property String^ par13Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par13Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par13Name), Value, ValuePointertype->par13Name);
			}
		}
		property String^ par14Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par14Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par14Name), Value, ValuePointertype->par14Name);
			}
		}
		property String^ par15Name//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->par15Name);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->par15Name), Value, ValuePointertype->par15Name);
			}
		}

		/* parameter numbers to set, 1..MAX_VARS -1 */
		property int par1Number
		{
			int get()
			{
				return ValuePointertype->par1Number;
			}
			void set(int Value)
			{
				ValuePointertype->par1Number = Value;
			}
		}
		property int par2Number
		{
			int get()
			{
				return ValuePointertype->par2Number;
			}
			void set(int Value)
			{
				ValuePointertype->par2Number = Value;
			}
		}
		property int par3Number
		{
			int get()
			{
				return ValuePointertype->par3Number;
			}
			void set(int Value)
			{
				ValuePointertype->par3Number = Value;
			}
		}
		property int par4Number
		{
			int get()
			{
				return ValuePointertype->par4Number;
			}
			void set(int Value)
			{
				ValuePointertype->par4Number = Value;
			}
		}
		property int par5Number
		{
			int get()
			{
				return ValuePointertype->par5Number;
			}
			void set(int Value)
			{
				ValuePointertype->par5Number = Value;
			}
		}
		property int par6Number
		{
			int get()
			{
				return ValuePointertype->par6Number;
			}
			void set(int Value)
			{
				ValuePointertype->par6Number = Value;
			}
		}
		property int par7Number
		{
			int get()
			{
				return ValuePointertype->par7Number;
			}
			void set(int Value)
			{
				ValuePointertype->par7Number = Value;
			}
		}
		property int par8Number
		{
			int get()
			{
				return ValuePointertype->par8Number;
			}
			void set(int Value)
			{
				ValuePointertype->par8Number = Value;
			}
		}
		property int par9Number
		{
			int get()
			{
				return ValuePointertype->par9Number;
			}
			void set(int Value)
			{
				ValuePointertype->par9Number = Value;
			}
		}
		property int par10Number
		{
			int get()
			{
				return ValuePointertype->par10Number;
			}
			void set(int Value)
			{
				ValuePointertype->par10Number = Value;
			}
		}
		property int par11Number
		{
			int get()
			{
				return ValuePointertype->par11Number;
			}
			void set(int Value)
			{
				ValuePointertype->par11Number = Value;
			}
		}
		property int par12Number
		{
			int get()
			{
				return ValuePointertype->par12Number;
			}
			void set(int Value)
			{
				ValuePointertype->par12Number = Value;
			}
		}
		property int par13Number
		{
			int get()
			{
				return ValuePointertype->par13Number;
			}
			void set(int Value)
			{
				ValuePointertype->par13Number = Value;
			}
		}
		property int par14Number
		{
			int get()
			{
				return ValuePointertype->par14Number;
			}
			void set(int Value)
			{
				ValuePointertype->par14Number = Value;
			}
		}
		property int par15Number
		{
			int get()
			{
				return ValuePointertype->par15Number;
			}
			void set(int Value)
			{
				ValuePointertype->par15Number = Value;
			}
		}


		/* textual description of c-source and line number,
		* this extra is debug information to see where the error
		* occurred in the server.
		*/
		property String^ sourceInfo//[CNC_MAX_SOURCE_INFO_TEXT];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->sourceInfo);
			}
		}
		property String^ functionName//[CNC_MAX_FUNCTION_NAME_TEXT];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->functionName);
			}
		}

		//time_t
		property TimeSpan	timeStamp_time_t//1970,1,1
		{
			TimeSpan get()
			{

				TimeSpan Temp_TimeSpan(0, 0, (int)ValuePointertype->timeStamp);
				return Temp_TimeSpan;
			}
		}


		/* number */
		property int n
		{
			int get()
			{
				return ValuePointertype->n;
			}
			void set(int Value)
			{
				ValuePointertype->n = Value;
			}
		}

		/* for internal use only */
		property int hint
		{
			int get()
			{
				return ValuePointertype->hint;
			}
			void set(int Value)
			{
				ValuePointertype->hint = Value;
			}
		}

	};
	public ref class Cnc3DPrintingVoltTempTuple :public Managedstruct<CNC_3DPRINTING_VOLT_TEMP_TUPLE>
	{
	public:
		Cnc3DPrintingVoltTempTuple(CNC_3DPRINTING_VOLT_TEMP_TUPLE  * _3DPRINTING_VOLT_TEMP_TUPLE) :Managedstruct(_3DPRINTING_VOLT_TEMP_TUPLE) {	}
		Cnc3DPrintingVoltTempTuple() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(Cnc3DPrintingVoltTempTuple^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int  volt
		{
			int get()
			{
				return ValuePointertype->volt;
			}
			void set(int Value)
			{
				ValuePointertype->volt = Value;
			}
		}
		property float temp
		{
			float get()
			{
				return ValuePointertype->temp;
			}
			void set(float Value)
			{
				ValuePointertype->temp = Value;
			}
		}
	};
	public ref class Cnc3DPrintingTempPidPars :public Managedstruct<CNC_3DPRINTING_TEMP_PID_PARS>
	{

	public:
		Cnc3DPrintingTempPidPars(CNC_3DPRINTING_TEMP_PID_PARS *_CNC_3DPRINTING_TEMP_PID_PARS) :Managedstruct(_CNC_3DPRINTING_TEMP_PID_PARS) {}
		Cnc3DPrintingTempPidPars() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(Cnc3DPrintingTempPidPars^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property float KP
		{
			float get()
			{
				return ValuePointertype->KP;
			}
			void set(float Value)
			{
				ValuePointertype->KP = Value;
			}
		}
		property float KD
		{
			float get()
			{
				return ValuePointertype->KD;
			}
			void set(float Value)
			{
				ValuePointertype->KD = Value;
			}
		}
		property float KI
		{
			float get()
			{
				return ValuePointertype->KI;
			}
			void set(float Value)
			{
				ValuePointertype->KI = Value;
			}
		}
		property float maxIntegratorTerm
		{
			float get()
			{
				return ValuePointertype->maxIntegratorTerm;
			}
			void set(float Value)
			{
				ValuePointertype->maxIntegratorTerm = Value;
			}
		}
		property float setPointReachedWindow
		{
			float get()
			{
				return ValuePointertype->setPointReachedWindow;
			}
			void set(float Value)
			{
				ValuePointertype->setPointReachedWindow = Value;
			}
		}
		property float maxPower {
			float get()
			{
				return ValuePointertype->maxPower;
			}
			void set(float Value)
			{
				ValuePointertype->maxPower = Value;
			}
		}
		property float maxTemp
		{
			float get()
			{
				return ValuePointertype->maxTemp;
			}
			void set(float Value)
			{
				ValuePointertype->maxTemp = Value;
			}
		}
		property float standByTemp
		{
			float get()
			{
				return ValuePointertype->standByTemp;
			}
			void set(float Value)
			{
				ValuePointertype->standByTemp = Value;
			}
		}
		property float sampleTime
		{
			float get()
			{
				return ValuePointertype->sampleTime;
			}
			void set(float Value)
			{
				ValuePointertype->sampleTime = Value;
			}
		}
		property float setpointTemp
		{
			float get()
			{
				return ValuePointertype->setpointTemp;
			}
			void set(float Value)
			{
				ValuePointertype->setpointTemp = Value;
			}
		}
		property int   ignoreTempError
		{
			int get()
			{
				return ValuePointertype->ignoreTempError;
			}
			void set(int Value)
			{
				ValuePointertype->ignoreTempError = Value;
			}
		}
	};
	public ref class CncThcProcessParameters :public Managedstruct<CNC_THC_PROCESS_PARAMETERS>
	{
	public:
		CncThcProcessParameters(CNC_THC_PROCESS_PARAMETERS * _CNC_THC_PROCESS_PARAMETERS) :Managedstruct(_CNC_THC_PROCESS_PARAMETERS) {}
		CncThcProcessParameters() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncThcProcessParameters^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		/* set point voltage */

		property double setPointVoltage
		{
			double get()
			{
				return ValuePointertype->setPointVoltage;
			}
			void set(double Value)
			{
				ValuePointertype->setPointVoltage = Value;
			}
		}

		/* control delay, delay after piercing and starting machine move till switch on THC */
		property double controlDelay
		{
			double get()
			{
				return ValuePointertype->controlDelay;
			}
			void set(double Value)
			{
				ValuePointertype->controlDelay = Value;
			}
		}

		/* proportional gain, typical 0.1 mm/volt */
		property double KPUp
		{
			double get()
			{
				return ValuePointertype->KPUp;
			}
			void set(double Value)
			{
				ValuePointertype->KPUp = Value;
			}
		}
		property double KPDown
		{
			double get()
			{
				return ValuePointertype->KPDown;
			}
			void set(double Value)
			{
				ValuePointertype->KPDown = Value;
			}
		}
		property double deadBand
		{
			double get()
			{
				return ValuePointertype->deadBand;
			}
			void set(double Value)
			{
				ValuePointertype->deadBand = Value;
			}
		}
		property double KD
		{
			double get()
			{
				return ValuePointertype->KD;
			}
			void set(double Value)
			{
				ValuePointertype->KD = Value;
			}
		}
		property double filterTime
		{
			double get()
			{
				return ValuePointertype->filterTime;
			}
			void set(double Value)
			{
				ValuePointertype->filterTime = Value;
			}
		}
		property double holeDetectVoltage
		{
			double get()
			{
				return ValuePointertype->holeDetectVoltage;
			}
			void set(double Value)
			{
				ValuePointertype->holeDetectVoltage = Value;
			}
		}
		property double holeDetectTime
		{
			double get()
			{
				return ValuePointertype->holeDetectTime;
			}
			void set(double Value)
			{
				ValuePointertype->holeDetectTime = Value;
			}
		}

		/* off when feed below this value */
		property double cornerFeedFactor
		{
			double get()
			{
				return ValuePointertype->cornerFeedFactor;
			}
			void set(double Value)
			{
				ValuePointertype->cornerFeedFactor = Value;
			}
		}


		/* THC will not raise/lower Z more than these limits */
		property double zMax
		{
			double get()
			{
				return ValuePointertype->zMax;
			}
			void set(double Value)
			{
				ValuePointertype->zMax = Value;
			}
		}
		property double zMin
		{
			double get()
			{
				return ValuePointertype->zMin;
			}
			void set(double Value)
			{
				ValuePointertype->zMin = Value;
			}
		}

		/* 1 to switch THC ON, 0 to switch OFF */
		property int thcON
		{
			int get()
			{
				return ValuePointertype->thcON;
			}
			void set(int Value)
			{
				ValuePointertype->thcON = Value;
			}
		}
		property int measuredIsSetpoint
		{
			int get()
			{
				return ValuePointertype->measuredIsSetpoint;
			}
			void set(int Value)
			{
				ValuePointertype->measuredIsSetpoint = Value;
			}
		}
		/* tuning, 1 is on, 2 = off */
		/* voltage 1 and 2 can be applied as if from external measurement */
		property int tuningMode
		{
			int get()
			{
				return ValuePointertype->tuningMode;
			}
			void set(int Value)
			{
				ValuePointertype->tuningMode = Value;
			}
		}

		property double    externalUpDownVelocity
		{
			double get()
			{
				return ValuePointertype->externalUpDownVelocity;
			}
			void set(double Value)
			{
				ValuePointertype->externalUpDownVelocity = Value;
			}
		}
	};
	public ref class CncJointDouble :public Managedstruct<CNC_JOINT_DOUBLE>
	{
	public:

		CncJointDouble(CNC_JOINT_DOUBLE *_CNC_JOINT_DOUBLE) :Managedstruct(_CNC_JOINT_DOUBLE) {}
		CncJointDouble() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncJointDouble^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property double jx
		{
			double get()
			{

				return ValuePointertype->jx;
			}
			void set(double Value)
			{
				ValuePointertype->jx = Value;
			}
		}
		property double jy
		{
			double get()
			{
				return ValuePointertype->jy;
			}
			void set(double Value)
			{
				ValuePointertype->jy = Value;
			}
		}
		property double jz
		{
			double get()
			{
				return ValuePointertype->jz;
			}
			void set(double Value)
			{
				ValuePointertype->jz = Value;
			}
		}
		property double ja
		{
			double get()
			{
				return ValuePointertype->ja;
			}
			void set(double Value)
			{
				ValuePointertype->ja = Value;
			}
		}
		property double jb
		{
			double get()
			{
				return ValuePointertype->jb;
			}
			void set(double Value)
			{
				ValuePointertype->jb = Value;
			}
		}
		property double jc
		{
			double get()
			{
				return ValuePointertype->jc;
			}
			void set(double Value)
			{
				ValuePointertype->jc = Value;
			}
		}
	};
	public ref class CncCartDouble :public Managedstruct<CNC_CART_DOUBLE>
	{
	public:
		CncCartDouble(CNC_CART_DOUBLE *_CNC_CART_DOUBLE) :Managedstruct(_CNC_CART_DOUBLE) {}
		CncCartDouble() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncCartDouble^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property double x//, y, z, a, b, c;
		{
			double get()
			{

				return ValuePointertype->x;
			}
			void set(double Value)
			{
				ValuePointertype->x = Value;
			}
		}
		property double y//, y, z, a, b, c;
		{
			double get()
			{
				return ValuePointertype->y;
			}
			void set(double Value)
			{
				ValuePointertype->y = Value;
			}
		}
		property double z//, y, z, a, b, c;
		{
			double get()
			{
				return ValuePointertype->z;
			}
			void set(double Value)
			{
				ValuePointertype->z = Value;
			}
		}
		property double a//, y, z, a, b, c;
		{
			double get()
			{
				return ValuePointertype->a;
			}
			void set(double Value)
			{
				ValuePointertype->a = Value;
			}
		}
		property double b//, y, z, a, b, c;
		{
			double get()
			{
				return ValuePointertype->b;
			}
			void set(double Value)
			{
				ValuePointertype->b = Value;
			}
		}
		property double c//, y, z, a, b, c;
		{
			double get()
			{
				return ValuePointertype->c;
			}
			void set(double Value)
			{
				ValuePointertype->c = Value;
			}
		}
	};
	public ref class CncJointBool :public Managedstruct<CNC_JOINT_BOOL>
	{
	public:
		CncJointBool(CNC_JOINT_BOOL *_CNC_JOINT_BOOL) :Managedstruct(_CNC_JOINT_BOOL) {}
		CncJointBool() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncJointBool^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property bool jx
		{
			bool get()
			{
				return ValuePointertype->jx;
			}
			void set(bool Value)
			{
				ValuePointertype->jx = Value;
			}
		}
		property bool jy
		{
			bool get()
			{
				return ValuePointertype->jy;
			}
			void set(bool Value)
			{
				ValuePointertype->jy = Value;
			}
		}
		property bool jz
		{
			bool get()
			{
				return ValuePointertype->jz;
			}
			void set(bool Value)
			{
				ValuePointertype->jz = Value;
			}
		}
		property bool ja
		{
			bool get()
			{
				return ValuePointertype->ja;
			}
			void set(bool Value)
			{
				ValuePointertype->ja = Value;
			}
		}
		property bool jb
		{
			bool get()
			{
				return ValuePointertype->jb;
			}
			void set(bool Value)
			{
				ValuePointertype->jb = Value;
			}
		}
		property bool jc
		{
			bool get()
			{
				return ValuePointertype->jc;
			}
			void set(bool Value)
			{
				ValuePointertype->jc = Value;
			}
		}
	};
	public ref class CncCartBool :public Managedstruct<CNC_CART_BOOL>
	{
	public:

		CncCartBool(CNC_CART_BOOL * _CNC_CART_BOOL) :Managedstruct(_CNC_CART_BOOL) {}
		CncCartBool() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncCartBool^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property bool x
		{
			bool get()
			{
				return ValuePointertype->x;
			}
			void set(bool Value)
			{
				ValuePointertype->x = Value;
			}
		}
		property bool y
		{
			bool get()
			{
				return ValuePointertype->y;
			}
			void set(bool Value)
			{
				ValuePointertype->y = Value;
			}
		}
		property bool z
		{
			bool get()
			{
				return ValuePointertype->z;
			}
			void set(bool Value)
			{
				ValuePointertype->z = Value;
			}
		}
		property bool a
		{
			bool get()
			{
				return ValuePointertype->a;
			}
			void set(bool Value)
			{
				ValuePointertype->a = Value;
			}
		}
		property bool b
		{
			bool get()
			{
				return ValuePointertype->b;
			}
			void set(bool Value)
			{
				ValuePointertype->b = Value;
			}
		}
		property bool c
		{
			bool get()
			{
				return ValuePointertype->c;
			}
			void set(bool Value)
			{
				ValuePointertype->c = Value;
			}
		}

	};
	public ref class CncVector :public Managedstruct<CNC_VECTOR>
	{
	public:
		CncVector(CNC_VECTOR *_CNC_VECTOR) :Managedstruct(_CNC_VECTOR) {}
		CncVector() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncVector^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property double x
		{
			double get()
			{
				return ValuePointertype->x;
			}
			void set(double Value)
			{
				ValuePointertype->x = Value;
			}
		}
		property double y
		{
			double get()
			{
				return ValuePointertype->y;
			}
			void set(double Value)
			{
				ValuePointertype->y = Value;
			}
		}
		property double z
		{
			double get()
			{
				return ValuePointertype->z;
			}
			void set(double Value)
			{
				ValuePointertype->z = Value;
			}
		}

	};
	public ref class CncI2cgpioRuleConfig :public Managedstruct<CNC_I2CGPIO_RULE_CONFIG>
	{
	public:
		CncI2cgpioRuleConfig(CNC_I2CGPIO_RULE_CONFIG * _CNC_I2CGPIO_RULE_CONFIG) :Managedstruct(_CNC_I2CGPIO_RULE_CONFIG) {}
		CncI2cgpioRuleConfig() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncI2cgpioRuleConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property unsigned char cardIndex /* card index 0-1 */
		{
			unsigned char get()
			{
				return ValuePointertype->cardIndex;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->cardIndex = Value;
			}

		}
		property unsigned char ruleIndex /* 0 - 15 */
		{
			unsigned char get()
			{
				return ValuePointertype->ruleIndex;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->ruleIndex = Value;
			}
		}
		property CncGpioActionType action
		{
			CncGpioActionType get()
			{
				return  (CncGpioActionType)ValuePointertype->action;
			}
			void set(CncGpioActionType Value)
			{
				ValuePointertype->action = (CNC_GPIO_ACTION_TYPE)Value;
			}

		}
		property unsigned short int inputParticipantBits
		{
			unsigned short int get()
			{
				return ValuePointertype->inputParticipantBits;
			}
			void set(unsigned short int Value)
			{
				ValuePointertype->inputParticipantBits = Value;
			}
		}
		property unsigned short int inputCompareBit
		{
			unsigned short int get()
			{
				return  ValuePointertype->inputCompareBits;
			}
			void set(unsigned short int Value)
			{
				ValuePointertype->inputCompareBits = Value;
			}
		}
		property String^ messageText
		{
			String^ get()
			{
				return  StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->messageText);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->messageText), Value, ValuePointertype->messageText);
			}
		}

	};
	public ref class CncToolDataInternal :public Managedstruct<CNC_TOOL_DATA_INTERNAL>
	{
	public:
		CncToolDataInternal(CNC_TOOL_DATA_INTERNAL * toolTable) :Managedstruct(toolTable) {}
		CncToolDataInternal() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncToolDataInternal^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int id
		{
			int get()
			{
				return ValuePointertype->id;
			}

		}
		property String^ description
		{
			String^ get()
			{

				return  StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->description);


			}

			/*
			void set(String^ Value)
			{
			StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(Temp_toolTable[Temp_SeletedToolId].description), Value, Temp_toolTable[Temp_SeletedToolId].description);
			}
			*/
		}
		property int diameterIndex
		{
			int get()
			{
				return  ValuePointertype->diameterIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].diameterIndex = value;
			}
			*/
		}
		property int zOffsetIndex
		{
			int get()
			{
				return ValuePointertype->zOffsetIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].zOffsetIndex = value;
			}
			*/
		}
		property int xOffsetIndex
		{
			int get()
			{
				return ValuePointertype->xOffsetIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].xOffsetIndex = value;
			}
			*/
		}
		property int orientationIndex
		{
			int get()
			{
				return ValuePointertype->orientationIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].orientationIndex = value;
			}
			*/
		}
		property int xDeltaIndex
		{
			int get()
			{
				return ValuePointertype->xDeltaIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].xDeltaIndex = value;
			}
			*/
		}
		property int zDeltaIndex
		{
			int get()
			{
				return ValuePointertype->zDeltaIndex;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].zDeltaIndex = value;
			}
			*/
		}
		property int locationCode
		{
			int get()
			{
				return ValuePointertype->locationCode;
			}

			/*
			void set(int value)
			{
			Temp_toolTable[Temp_SeletedToolId].locationCode = value;
			}
			*/
		}
	};
	public ref class CncToolData :public Managedstruct<CNC_TOOL_DATA>
	{
	public:
		CncToolData(CNC_TOOL_DATA *  _CNC_TOOL_DATA) :Managedstruct(_CNC_TOOL_DATA) {}
		CncToolData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncToolData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int id
		{
			int get()
			{
				return ValuePointertype->id;
			}
			void set(int Value)
			{
				ValuePointertype->id = Value;
			}
		}
		property int locationCode
		{
			int get()
			{
				return ValuePointertype->locationCode;
			}
			void set(int Value)
			{
				ValuePointertype->locationCode = Value;
			}
		}
		property String^ description
		{
			String^ get()
			{

				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->description);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->description), Value, ValuePointertype->description);
			}
		}
		property double  diameter	//Variable index 5400 .. 5499
		{
			double get()
			{
				return ValuePointertype->diameter;
			}
			void set(double Value)
			{
				ValuePointertype->diameter = Value;
			}
		}
		property double  zOffset    //Variable index 5500 .. 5599  (Length)
		{
			double get()
			{
				return ValuePointertype->zOffset;
			}
			void set(double Value)
			{
				ValuePointertype->zOffset = Value;
			}
		}
		property double  xOffset    //Variable index 5600 .. 5699  (width, for turning)
		{
			double get()
			{
				return ValuePointertype->xOffset;
			}
			void set(double Value)
			{
				ValuePointertype->xOffset = Value;
			}
		}
		property double  zDelta      //Variable index 5900 .. 5999
		{
			double get()
			{
				return ValuePointertype->zDelta;
			}
			void set(double Value)
			{
				ValuePointertype->zDelta = Value;
			}
		}
		property double  xDelta      //Variable index 5800 .. 5899
		{
			double get()
			{
				return ValuePointertype->xDelta;
			}
			void set(double Value)
			{
				ValuePointertype->xDelta = Value;
			}
		}
		property int orientation
		{
			int get()
			{
				return ValuePointertype->orientation;
			}
			void set(int Value)
			{
				ValuePointertype->orientation = Value;
			}
		}
	};
	public ref class CncJointSts :public Managedstruct<CNC_JOINT_STS>
	{
	public:
		CncJointSts(CNC_JOINT_STS * _CNC_JOINT_STS) :Managedstruct(_CNC_JOINT_STS) {}
		CncJointSts() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncJointSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property char jointIndex
		{
			char get()
			{
				return ValuePointertype->jointIndex;
			}
		private:
			void set(char Value)
			{

			}
		}
		property CncJointState state
		{
			CncJointState get()
			{
				return (CncJointState)ValuePointertype->state;
			}
		private:
			void set(CncJointState Value)
			{

			}
		
		}
		property int errorWord
		{
			int get()
			{
				return ValuePointertype->errorWord;
			}
		private:
			void set(int Value)
			{

			}
		
		}
		property double position
		{
			double get()
			{
				return ValuePointertype->position;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double positionRaw
		{
			double get()
			{
				return ValuePointertype->positionRaw;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double maxPositionError
		{
			double get()
			{
				return ValuePointertype->maxPositionError;
			}
		private:
			void set(double Value)
			{

			}
		}
		property int isHomed
		{
			int get()
			{
				return ValuePointertype->isHomed;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int homeSensorStatus
		{
			int get()
			{
				return ValuePointertype->homeSensorStatus;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int jointIsConfigured
		{
			int get()
			{
				return ValuePointertype->jointIsConfigured;
			}
		private:
			void set(int Value)
			{

			}
		}

	};
	public ref class CncTanKnifeStatus :public Managedstruct<CNC_TAN_KNIFE_STATUS>
	{
	public:
		CncTanKnifeStatus(CNC_TAN_KNIFE_STATUS *_TAN_KNIFE_STATUS) :Managedstruct(_TAN_KNIFE_STATUS) {}
		CncTanKnifeStatus() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncTanKnifeStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		/* 1 if tangential knife mode is active, C-Axis follows X,Y direction */
		property int tanKnifeIsOn
		{
			int get()
			{
				return ValuePointertype->tanKnifeIsOn;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* -1 for bend angle negative from rotation angle, +1 positive, 0 no bending so normal tan knife */
		property int tanknifeBending
		{
			int get()
			{
				return ValuePointertype->tanknifeBending;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* 0: no special mapping, 1: Mapped to B, 2: Mapped to BC, dual tan knife */
		property int tanKnifeBCMapping
		{
			int get()
			{
				return ValuePointertype->tanKnifeBCMapping;
			}
		private:
			void set(int Value)
			{

			}
		}
		property double tanknifeZloMachine
		{
			double get()
			{
				return ValuePointertype->tanknifeZloMachine;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double tanknifeZhiMachine
		{
			double get()
			{
				return ValuePointertype->tanknifeZhiMachine;
			}
		private:
			void set(double Value)
			{

			}
		}

	};
	public ref class KinControlData :public Managedstruct<KIN_CONTROLDATA>
	{
	private:
		array<double>^ Temp_dData = nullptr;
		array<int>^ Temp_iData = nullptr;
		array<char>^ Temp_cData = nullptr;
		void NewClass()
		{
			Temp_dData = gcnew array<double>(sizeof(ValuePointertype->dData) / SizeOfdoublex32);
			Temp_iData = gcnew array<int>(sizeof(ValuePointertype->iData) / SizeOfintx32);
			Temp_cData = gcnew array<char>(sizeof(ValuePointertype->cData));
		}
	public:
		KinControlData(KIN_CONTROLDATA *_KIN_CONTROLDATA) :Managedstruct(_KIN_CONTROLDATA) 
		{
			NewClass();
		}
		KinControlData() :Managedstruct(nullptr) 
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(KinControlData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property array<double>^ dData
		{
			array<double>^ get()
			{
				for (int i = 0; i < Temp_dData->Length; i++)
				{
					Temp_dData[i] = ValuePointertype->dData[i];
				}
				return Temp_dData;
			}
			void set(array<double>^ Value)
			{
				for (int i = 0; i < Temp_dData->Length; i++)
				{
					if (i < Value->Length)
					{
						Temp_dData[i] = Value[i];
					}
					else
					{
						Temp_dData[i] = 0;
					}

					ValuePointertype->dData[i] = Temp_dData[i];
				}

			}
		}
		property array<int>^ iData
		{
			array<int>^get()
			{
				for (int i = 0; i < Temp_iData->Length; i++)
				{
					Temp_iData[i] = ValuePointertype->iData[i];
				}

				return Temp_iData;
			}
			void set(array<int>^Value)
			{
				for (int i = 0; i < Temp_iData->Length; i++)
				{
					if (i < Value->Length)
					{
						Temp_iData[i] = Value[i];
					}
					else
					{
						Temp_iData[i] = 0;
					}

					ValuePointertype->iData[i] = Temp_iData[i];
				}
			}
		}
		property array<char>^ cData
		{
			array<char>^get()
			{
				for (int i = 0; i < Temp_cData->Length; i++)
				{
					Temp_cData[i] = ValuePointertype->cData[i];
				}

				return Temp_cData;
			}
			void set(array<char> ^Value)
			{
				for (int i = 0; i < Temp_cData->Length; i++)
				{
					if (i < Value->Length)
					{
						Temp_cData[i] = Value[i];
					}
					else
					{
						Temp_cData[i] = 0;
					}

					ValuePointertype->cData[i] = Temp_cData[i];
				}
			}
		}
	};
	public ref class Cnc3DpOnOffData :public Managedstruct<CNC_3DP_ONOFF_DATA>
	{
	public:
		Cnc3DpOnOffData(CNC_3DP_ONOFF_DATA * _CNC_3DP_ONOFF_DATA) :Managedstruct(_CNC_3DP_ONOFF_DATA) {}
		Cnc3DpOnOffData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(Cnc3DpOnOffData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncOnOff onOff
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->onOff;
			}
			void set(CncOnOff value)
			{
				ValuePointertype->onOff = (CNC_ONOFF)value;
			}
		}
	};
	public ref class Cnc3DpFloatValData :public Managedstruct<CNC_3DP_FLOATVAL_DATA>
	{
	public:
		Cnc3DpFloatValData(CNC_3DP_FLOATVAL_DATA * _CNC_3DP_FLOATVAL_DATA) :Managedstruct(_CNC_3DP_FLOATVAL_DATA) {}
		Cnc3DpFloatValData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(Cnc3DpFloatValData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property float value
		{
			float get()
			{
				return ValuePointertype->value;
			}
			void set(float _value)
			{
				ValuePointertype->value = _value;
			}
		}
	};
	public ref class CncVacuumBedSectionData :public Managedstruct<CNC_VACUUMBED_SECTION_DATA>
	{
	public:
		CncVacuumBedSectionData(CNC_VACUUMBED_SECTION_DATA * _CNC_VACUUMBED_SECTION_DATA) :Managedstruct(_CNC_VACUUMBED_SECTION_DATA) {}
		CncVacuumBedSectionData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncVacuumBedSectionData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property int sectionOutputNumber //;   //0=none, 1 = AUX1, 2=AUX2 ... 101 = GPIO 1 etc
		{
			int get()
			{
				return ValuePointertype->sectionOutputNumber;
			}
			void set(int Value)
			{
				ValuePointertype->sectionOutputNumber = Value;
			}
		}
		property int sectionPumpOutputNumber //;   //0=none, 1 = AUX1, 2=AUX2 ... 101 = GPIO 1 etc
		{
			int get()
			{
				return ValuePointertype->sectionPumpOutputNumber;
			}
			void set(int Value)
			{
				ValuePointertype->sectionPumpOutputNumber = Value;
			}
		}

		property double sectionXPosition
		{
			double get()
			{
				return ValuePointertype->sectionXPosition;
			}
			void set(double Value)
			{
				ValuePointertype->sectionXPosition = Value;
			}
		}
		property double sectionYPosition
		{
			double get()
			{
				return ValuePointertype->sectionYPosition;
			}
			void set(double Value)
			{
				ValuePointertype->sectionYPosition = Value;
			}
		}
		property double sectionXWidth
		{
			double get()
			{
				return ValuePointertype->sectionXWidth;
			}
			void set(double Value)
			{
				ValuePointertype->sectionXWidth = Value;
			}
		}
		property double sectionYWidth
		{
			double get()
			{
				return ValuePointertype->sectionYWidth;
			}
			void set(double Value)
			{
				ValuePointertype->sectionYWidth = Value;
			}
		}
	};
	public ref class CncUioSingleInputCfg :public Managedstruct<CNC_UIO_SINGLE_INPUT_CFG>
	{
	public:
		CncUioSingleInputCfg(CNC_UIO_SINGLE_INPUT_CFG * _Temp_CNC_UIO_SINGLE_INPUT_CFG) :Managedstruct(_Temp_CNC_UIO_SINGLE_INPUT_CFG) {}
		CncUioSingleInputCfg() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncUioSingleInputCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property char hardwareIONumber//;     //Inputs 1..32 to which the selector is connected
		{
			char get()
			{
				return ValuePointertype->hardwareIONumber;
			}

			/*
			void set(char Value)
			{
				ValuePointertype[Temp_SelectedUioInput].hardwareIONumber = Value;
			}
			*/
		}
		property char pressAction//;          //Action on press for each selection, CNC_IOACTION_NONE .. CNC_IOACTION_LAST
		{
			char get()
			{
				return ValuePointertype->pressAction;
			}
			void set(char Value)
			{
				ValuePointertype->pressAction = Value;
			}
		}
		property char releaseAction//;        //Action on release for each selection, CNC_IOACTION_NONE .. CNC_IOACTION_LAST
		{
			char get()
			{
				return ValuePointertype->releaseAction;
			}
			void set(char Value)
			{
				ValuePointertype->releaseAction = Value;
			}
		}
	};
	public ref class CncUioSelectorConfig :public Managedstruct<CNC_UIO_SELECTOR_CONFIG>
	{
	private:
		array<unsigned char>^ Temp_actions = nullptr;
		array<unsigned char>^ Temp_hardwareIONumber = nullptr;
		void NewClass()
		{
			Temp_actions = gcnew array<unsigned char>(sizeof(ValuePointertype->actions));
			Temp_hardwareIONumber = gcnew array<unsigned char>(sizeof(ValuePointertype->hardwareIONumber));
		}
	public:
		CncUioSelectorConfig(CNC_UIO_SELECTOR_CONFIG * _Temp_CNC_UIO_SELECTOR_CONFIG) :Managedstruct(_Temp_CNC_UIO_SELECTOR_CONFIG)
		{
			NewClass();
		}
		CncUioSelectorConfig() :Managedstruct(nullptr) 
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncUioSelectorConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property array<unsigned char>^ hardwareIONumber
		{
			array<unsigned char>^ get()
			{
				for (int i = 0; i < Temp_hardwareIONumber->Length; i++)
				{
					Temp_hardwareIONumber[i] = ValuePointertype->hardwareIONumber[i];
				}
				return Temp_hardwareIONumber;
			}
			void set(array<unsigned char>^ Value)
			{
				if (Value->Length == Temp_hardwareIONumber->Length)
				{
					for (int i = 0; i < Temp_hardwareIONumber->Length; i++)
					{
						ValuePointertype->hardwareIONumber[i] = Value[i];
					}
				}
			}
		}
		property array<unsigned char>^ actions
		{
			array<unsigned char>^ get()
			{
				for (int i = 0; i < Temp_actions->Length; i++)
				{
					Temp_actions[i] = ValuePointertype->actions[i];
				}
				return Temp_actions;
			}
			void set(array<unsigned char>^ Value)
			{
				if (Value->Length == Temp_actions->Length)
				{
					for (int i = 0; i < Temp_actions->Length; i++)
					{
						ValuePointertype->actions[i] = Value[i];
					}
				}
			}
		}
	};
	public ref class CncUioAnalogConfig :public Managedstruct<CNC_UIO_ANALOG_CONFIG>
	{
	public:
		CncUioAnalogConfig(CNC_UIO_ANALOG_CONFIG * _Temp_CNC_UIO_ANALOG_CONFIG) :Managedstruct(_Temp_CNC_UIO_ANALOG_CONFIG) {}
		CncUioAnalogConfig() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncUioAnalogConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property unsigned char hardwareIONumber//; //Inputs 1..32 to which the analog input is connected
		{
			unsigned char get()
			{
				return ValuePointertype->hardwareIONumber;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->hardwareIONumber = Value;
			}
		}
		property unsigned char action//;           //Related Action CNC_IOACTION_NONE .. CNC_IOACTION_LAST
		{
			unsigned char get()
			{
				return ValuePointertype->action;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->action = Value;
			}
		}
	};
	public ref class CncUioHandWheelConfig :public Managedstruct<CNC_UIO_HANDWHEEL_CONFIG>
	{
	public:
		CncUioHandWheelConfig(CNC_UIO_HANDWHEEL_CONFIG * _Temp_CNC_UIO_HANDWHEEL_CONFIG) :Managedstruct(_Temp_CNC_UIO_HANDWHEEL_CONFIG) {}
		CncUioHandWheelConfig() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncUioHandWheelConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property unsigned char hardwareIONumberA//;    //Inputs 1..32 for A and B signals to which the hand wheel is connected
		{
			unsigned char get()
			{
				return ValuePointertype->hardwareIONumberA;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->hardwareIONumberA = Value;
			}
		}
		property unsigned char hardwareIONumberB//;    //Inputs 1..32 for A and B signals to which the hand wheel is connected
		{
			unsigned char get()
			{
				return ValuePointertype->hardwareIONumberB;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->hardwareIONumberB = Value;
			}
		}
		property unsigned char action//;               //Action for the hand wheel is always to move selected axis 
		{
			unsigned char get()
			{
				return ValuePointertype->action;
			}
			void set(unsigned char Value)
			{
				ValuePointertype->action = Value;
			}
		}
	};
	public ref class CncSystemConfig :public Managedstruct<CNC_SYSTEM_CONFIG>
	{
	private:
		array<int>^ Temp_reserved = nullptr;
		void NewClass()
		{
			Temp_reserved = gcnew array<int>(sizeof(ValuePointertype->reserved) / SizeOfintx32);
		}
	public:
		CncSystemConfig(CNC_SYSTEM_CONFIG * CONFIG) :Managedstruct(CONFIG)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		CncSystemConfig() :Managedstruct(nullptr) 
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncSystemConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		/*
		void Reload_CncGetSystemConfig() {
		Config = CncGetSystemConfig();
		}
		*/
		property String^ serverPath {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->serverPath);
			}

		}
		property String^ serverVersion {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->serverVersion);
			}

		}
		property String^ lastKnownServerVersion {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->lastKnownServerVersion);
			}

		}
		property String^ lastKnownFirmwareVersion {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->lastKnownFirmwareVersion);
			}

		}
		property int64_t et {
			int64_t get()
			{
				return  ValuePointertype->et;
			}
			void set(int64_t Value)
			{
				ValuePointertype->et = Value;
			}
		}
		property int newIniFileWasCreated {
			int get()
			{
				return  ValuePointertype->newIniFileWasCreated;
			}
			void set(int Value)
			{
				ValuePointertype->newIniFileWasCreated = Value;
			}
		}
		property int iniFileWasRestored
		{
			int get()
			{
				return  ValuePointertype->iniFileWasRestored;
			}
			void set(int Value)
			{
				ValuePointertype->iniFileWasRestored = Value;
			}
		}
		property String^ comPortName {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->comPortName);
			}

		}
		property int scanEthernet {
			int get()
			{
				return  ValuePointertype->scanEthernet;
			}
			void set(int Value)
			{
				ValuePointertype->scanEthernet = Value;
			}
		}
		property int nrOfJoints {
			int get()
			{
				return  ValuePointertype->nrOfJoints;
			}

		}
		property int controllerTimerDividerIndex {
			int get()
			{
				return  ValuePointertype->controllerTimerDividerIndex;
			}
			void set(int Value)
			{
				ValuePointertype->controllerTimerDividerIndex = Value;
			}
		}
		property int stepPulsePolarity {
			int get()
			{
				return  ValuePointertype->stepPulsePolarity;
			}
			void set(int Value)
			{
				ValuePointertype->stepPulsePolarity = Value;
			}
		}
		property CncMachineType machineType {
			CncMachineType get()
			{
				return  (CncMachineType)ValuePointertype->machineType;
			}
			void set(CncMachineType Value)
			{
				ValuePointertype->machineType = (CNC_MACHINE_TYPE)Value;
			}
		}
		property int pwmFrequency {
			int get()
			{
				return  ValuePointertype->pwmFrequency;
			}
			void set(int Value)
			{
				ValuePointertype->pwmFrequency = Value;
			}
		}
		property CncIoId resetInput {
			CncIoId get()
			{
				return  (CncIoId)ValuePointertype->resetInput;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->resetInput = (CNC_IO_ID)Value;
			}
		}
		property array<int>^ reserved
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_reserved->Length; i++)
				{
					Temp_reserved[i] = ValuePointertype->reserved[i];
				}
				return Temp_reserved;
			}
			void set(array<int>^ Value)
			{
				if (Temp_reserved->Length == Value->Length)
				{
					for (int i = 0; i < Temp_reserved->Length; i++)
					{
						ValuePointertype->reserved[i] = Value[i];
					}
				}
			}
		}
	};
	public ref class CncSafetyConfig :public Managedstruct<CNC_SAFETY_CONFIG>
	{
	private:
		array<int>^ Temp_auxInputCheckSenseLevel = nullptr;
		void NewClass()
		{
			Temp_auxInputCheckSenseLevel = gcnew array<int>(sizeof(ValuePointertype->auxInputCheckSenseLevel) / SizeOfintx32);
		}
	public:
		CncSafetyConfig(CNC_SAFETY_CONFIG * _CNC_SAFETY_CONFIG) :Managedstruct(_CNC_SAFETY_CONFIG)
		{
			NewClass();
		}
		CncSafetyConfig() :Managedstruct(nullptr) 
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncSafetyConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int homeIsEstopAfterHomingAllAxes
		{/* switch on e stop function on home sensors if all axes are homed */
			int get()
			{
				return ValuePointertype->homeIsEstopAfterHomingAllAxes;
			}
			void set(int Value)
			{
				ValuePointertype->homeIsEstopAfterHomingAllAxes = Value;
			}
		}
		property int EStopInputSenseLevel1
		{/* emergency stop sense level */
			int get()
			{
				return  ValuePointertype->EStopInputSenseLevel1;
			}
			void set(int Value)
			{
				ValuePointertype->EStopInputSenseLevel1 = Value;
			}
		}
		property int EStopInputSenseLevel2
		{/* only cpu5b */
			int get()
			{
				return  ValuePointertype->EStopInputSenseLevel2;
			}
			void set(int Value)
			{
				ValuePointertype->EStopInputSenseLevel2 = Value;
			}
		}
		property int driveWarningInputSenseLevel
		{		/* drive warning input sense level for i600 */
			int get()
			{
				return  ValuePointertype->driveWarningInputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->driveWarningInputSenseLevel = Value;
			}
		}
		property int driveErrorInputSenseLevel
		{
			int get()
			{
				return  ValuePointertype->driveErrorInputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->driveErrorInputSenseLevel = Value;
			}
		}
		property int isoInputSenseLevel
		{
			int get()
			{
				return  ValuePointertype->isoInputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->isoInputSenseLevel = Value;
			}
		}
		property int isoOutputSenseLevel
		{
			int get()
			{
				return  ValuePointertype->isoOutputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->isoOutputSenseLevel = Value;
			}
		}
		property int extErrorInputSenseLevel
		{/* input sense level, 0=low-e-stop, 1=hi-e-stop, 2=none, 3=low-stop, 4=hi-stop, 5=low-warning, 6=hi-warning*/
			int get()
			{
				return  ValuePointertype->extErrorInputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->extErrorInputSenseLevel = Value;
			}
		}
		/* aux inputs guarding */
		/* input sense level, 0=low-e-stop, 1=hi-e-stop, 2=none, 3=low-stop, 4=hi-stop, 5=low-slowfeed, 6=hi-slowfeed, 7=low warning, 8 = hi-warning*/
		property array<int>^ auxInputCheckSenseLevel
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_auxInputCheckSenseLevel->Length; i++)
				{
					Temp_auxInputCheckSenseLevel[i] = ValuePointertype->auxInputCheckSenseLevel[i];
				}

				return Temp_auxInputCheckSenseLevel;
			}
			void set(array<int>^ Value)
			{
				if (Temp_auxInputCheckSenseLevel->Length == Value->Length)
				{
					for (int i = 0; i < Temp_auxInputCheckSenseLevel->Length; i++)
					{
						ValuePointertype->auxInputCheckSenseLevel[i] = Temp_auxInputCheckSenseLevel[i];
					}
				}
			}
		}

		/* switch on/off gpio warnings/sstop/estop */
		property int enableGPIOActions
		{
			int get()
			{
				return  ValuePointertype->enableGPIOActions;
			}
			void set(int Value)
			{
				ValuePointertype->enableGPIOActions = Value;
			}
		}

		/* if this one is 1, no GPIO actions are taken on ESTOP */
		property int atEStopLeaveGPIOAsIs
		{
			int get()
			{
				return  ValuePointertype->atEStopLeaveGPIOAsIs;
			}
			void set(int Value)
			{
				ValuePointertype->atEStopLeaveGPIOAsIs = Value;
			}
		}

		/* max feed in safety mode */
		property double safetyFeed
		{
			double get()
			{
				return  ValuePointertype->safetyFeed;
			}
			void set(double Value)
			{
				ValuePointertype->safetyFeed = Value;
			}
		}

		/* max speed in safety mode */
		property double safetySpeedPercent
		{
			double get()
			{
				return  ValuePointertype->safetySpeedPercent;
			}
			void set(double Value)
			{
				ValuePointertype->safetySpeedPercent = Value;
			}
		}

		/* FeedOverride in safety mode */
		property double safetyFeedOverridePercent
		{
			double get()
			{
				return  ValuePointertype->safetyFeedOverridePercent;
			}
			void set(double Value)
			{
				ValuePointertype->safetyFeedOverridePercent = Value;
			}
		}

		/* max distance between master-slave axis after both are homed */
		property double maxMasterSlaveDistance
		{
			double get()
			{
				return  ValuePointertype->maxMasterSlaveDistance;
			}
			void set(double Value)
			{
				ValuePointertype->maxMasterSlaveDistance = Value;
			}
		}

		/* use end of stroke switch as emergency stop after homing */
		property int useXHomeinputForAllAxes
		{
			int get()
			{
				return  ValuePointertype->useXHomeinputForAllAxes;
			}
			void set(int Value)
			{
				ValuePointertype->useXHomeinputForAllAxes = Value;
			}
		}

		/* end of stroke sense level, used for homing */
		property int endOfStrokeInputSenseLevel
		{
			int get()
			{
				return  ValuePointertype->endOfStrokeInputSenseLevel;
			}
			void set(int Value)
			{
				ValuePointertype->endOfStrokeInputSenseLevel = Value;
			}
		}


		/* Homing mandatory or not, 1=mandatory */
		property int mandatoryHoming
		{
			int get()
			{
				return  ValuePointertype->mandatoryHoming;
			}
			void set(int Value)
			{
				ValuePointertype->mandatoryHoming = Value;
			}
		}
		property int allowJoggingBeforeHoming
		{
			int get()
			{
				return  ValuePointertype->allowJoggingBeforeHoming;
			}
			void set(int Value)
			{
				ValuePointertype->allowJoggingBeforeHoming = Value;
			}
		}

		property int stopSpindleOnPause
		{
			int get()
			{
				return  ValuePointertype->stopSpindleOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->stopSpindleOnPause = Value;
			}
		}
		property int noStartSpindleIfPauseActive
		{
			int get()
			{
				return  ValuePointertype->noStartSpindleIfPauseActive;
			}
			void set(int Value)
			{
				ValuePointertype->noStartSpindleIfPauseActive = Value;
			}
		}
		property int noStartJogIfPauseActive
		{
			int get()
			{
				return  ValuePointertype->noStartJogIfPauseActive;
			}
			void set(int Value)
			{
				ValuePointertype->noStartJogIfPauseActive = Value;
			}
		}
		property int noStartMDIIfPauseActive
		{
			int get()
			{
				return  ValuePointertype->noStartMDIIfPauseActive;
			}
			void set(int Value)
			{
				ValuePointertype->noStartMDIIfPauseActive = Value;
			}
		}
		property int noStartUserButtonIfPauseActive
		{
			int get()
			{
				return  ValuePointertype->noStartUserButtonIfPauseActive;
			}
			void set(int Value)
			{
				ValuePointertype->noStartUserButtonIfPauseActive = Value;
			}
		}
		property int aux1_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux1_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux1_OffOnPause = Value;
			}
		}
		property int aux2_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux2_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux2_OffOnPause = Value;
			}
		}
		property int aux3_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux3_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux3_OffOnPause = Value;
			}
		}
		property int aux4_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux4_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux4_OffOnPause = Value;
			}
		}
		property int aux5_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux5_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux5_OffOnPause = Value;
			}
		}
		property int aux6_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux6_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux6_OffOnPause = Value;
			}
		}
		property int aux7_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux7_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux7_OffOnPause = Value;
			}
		}
		property int aux8_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux8_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux8_OffOnPause = Value;
			}
		}
		property int aux9_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux9_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux9_OffOnPause = Value;
			}
		}
		property int aux10_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->aux10_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->aux10_OffOnPause = Value;
			}
		}

		property int mist_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->mist_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->mist_OffOnPause = Value;
			}
		}
		property int flood_OffOnPause
		{
			int get()
			{
				return  ValuePointertype->flood_OffOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->flood_OffOnPause = Value;
			}
		}


		/* start spindle when resumed from pause */
		property int autoStartAfterPause
		{
			int get()
			{
				return  ValuePointertype->autoStartAfterPause;
			}
			void set(int Value)
			{
				ValuePointertype->autoStartAfterPause = Value;
			}
		}

		/* move Z up on pause */
		property int zUpOnPause
		{
			int get()
			{
				return  ValuePointertype->zUpOnPause;
			}
			void set(int Value)
			{
				ValuePointertype->zUpOnPause = Value;
			}
		}

		/* Z up distance */
		property double zUpMoveDistanceOnPause
		{
			double get()
			{
				return  ValuePointertype->zUpMoveDistanceOnPause;
			}
			void set(double Value)
			{
				ValuePointertype->zUpMoveDistanceOnPause = Value;
			}
		}

		/* feed during approach of Z at resume */
		property double approachFeed
		{
			double get()
			{
				return  ValuePointertype->approachFeed;
			}
			void set(double Value)
			{
				ValuePointertype->approachFeed = Value;
			}
		}

		/* safety relay present */
		property int safetyRelayPresent
		{
			int get()
			{
				return  ValuePointertype->safetyRelayPresent;
			}
			void set(int Value)
			{
				ValuePointertype->safetyRelayPresent = Value;
			}
		}
		property CncIoId systemReadyOutPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->systemReadyOutPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->systemReadyOutPortID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId safetyRelayResetOutPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->safetyRelayResetOutPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->safetyRelayResetOutPortID = (CNC_IO_ID)Value;
			}
		}

		/* pulse length of reset pulse for safety relay */
		property int safetyRelayResetDelayMs
		{
			int get()
			{
				return  ValuePointertype->safetyRelayResetDelayMs;
			}
			void set(int Value)
			{
				ValuePointertype->safetyRelayResetDelayMs = Value;
			}
		}
		property int safetyRelayPulseLengthMs
		{
			int get()
			{
				return  ValuePointertype->safetyRelayPulseLengthMs;
			}
			void set(int Value)
			{
				ValuePointertype->safetyRelayPulseLengthMs = Value;
			}
		}

		/* G28 Guard */
		property CncIoId g28GuardPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->g28GuardPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->g28GuardPortID = (CNC_IO_ID)Value;
			}
		}
	};
	public ref class CncTrafficLightCfg :public Managedstruct<CNC_TRAFFIC_LIGHT_CFG>
	{
	public:
		CncTrafficLightCfg(CNC_TRAFFIC_LIGHT_CFG * _CNC_TRAFFIC_LIGHT_CFG) :Managedstruct(_CNC_TRAFFIC_LIGHT_CFG) {}
		CncTrafficLightCfg() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncTrafficLightCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* output numbers for traffic light */
		property CncIoId trafficLightGreenIOID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->trafficLightGreenIOID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->trafficLightGreenIOID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId trafficLightYellowIOID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->trafficLightYellowIOID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->trafficLightYellowIOID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId trafficLightRedIOID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->trafficLightRedIOID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->trafficLightRedIOID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId trafficLightProgressPWMIOID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->trafficLightProgressPWMIOID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->trafficLightProgressPWMIOID = (CNC_IO_ID)Value;
			}
		}
		property int noFlashing
		{
			int get()
			{
				return ValuePointertype->noFlashing;
			}
			void set(int Value)
			{
				ValuePointertype->noFlashing = Value;
			}
		}

	};
	public ref class CncProbingCfg :public Managedstruct<CNC_PROBING_CFG>
	{
	public:
		CncProbingCfg(CNC_PROBING_CFG * _CNC_PROBING_CFG) :Managedstruct(_CNC_PROBING_CFG) {}
		CncProbingCfg() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncProbingCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		/* 1 if height probe is present, 0 if not */
		property int heightProbePresent
		{
			int get()
			{
				return ValuePointertype->heightProbePresent;
			}
			void set(int Value)
			{
				ValuePointertype->heightProbePresent = Value;
			}
		}
		/* if 1, probe touch points are stored in digitize file name */
		property int storeProbeTouchPoints
		{
			int get()
			{
				return ValuePointertype->storeProbeTouchPoints;
			}
			void set(int Value)
			{
				ValuePointertype->storeProbeTouchPoints = Value;
			}
		}
		/* file name to store probe touch points */
		property String^ probeTouchPointFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->probeTouchPointFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->probeTouchPointFileName), Value, ValuePointertype->probeTouchPointFileName);
			}
		}
		/* beep if probe triggers */
		property int probeBeep
		{
			int get()
			{
				return ValuePointertype->probeBeep;
			}
			void set(int Value)
			{
				ValuePointertype->probeBeep = Value;
			}
		}
		/* probe input */
		property int probeUseHomeInput4
		{
			int get()
			{
				return ValuePointertype->probeUseHomeInput4;
			}
			void set(int Value)
			{
				ValuePointertype->probeUseHomeInput4 = Value;
			}
		}
		/* analog probing using analog input 3 of CPU */
		property double probeVoltIncToMM
		{
			double get()
			{
				return ValuePointertype->probeVoltIncToMM;
			}
			void set(double Value)
			{
				ValuePointertype->probeVoltIncToMM = Value;
			}
		}
		/* protect touch probe, detect unexpected triggers */
		property int probeDetectUnexpectedTrigger
		{
			int get()
			{
				return ValuePointertype->probeDetectUnexpectedTrigger;
			}
			void set(int Value)
			{
				ValuePointertype->probeDetectUnexpectedTrigger = Value;
			}
		}
	};
	public ref class CncIoConfig :public Managedstruct<CNC_IO_CONFIG>
	{
	public:
		CncIoConfig(CNC_IO_CONFIG * _CNC_IO_CONFIG) :Managedstruct(_CNC_IO_CONFIG) {}
		CncIoConfig() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncIoConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int invertAmpEnableOut
		{
			int get()
			{
				return ValuePointertype->invertAmpEnableOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertAmpEnableOut = Value;
			}
		}
		property int invertAmpCurrentReduceOut
		{
			int get()
			{
				return ValuePointertype->invertAmpCurrentReduceOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertAmpCurrentReduceOut = Value;
			}
		}
		property int delayMSAfterAmpenable
		{
			int get()
			{
				return ValuePointertype->delayMSAfterAmpenable;
			}
			void set(int Value)
			{
				ValuePointertype->delayMSAfterAmpenable = Value;
			}
		}
		property int delayMSCurrentReduceOn
		{
			int get()
			{
				return ValuePointertype->delayMSCurrentReduceOn;
			}
			void set(int Value)
			{
				ValuePointertype->delayMSCurrentReduceOn = Value;
			}
		}
		property int delayMSCurrentReduceOff
		{
			int get()
			{
				return ValuePointertype->delayMSCurrentReduceOff;
			}
			void set(int Value)
			{
				ValuePointertype->delayMSCurrentReduceOff = Value;
			}
		}
		property int invertToolOut
		{
			int get()
			{
				return ValuePointertype->invertToolOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertToolOut = Value;
			}
		}
		property int invertToolDirOut
		{
			int get()
			{
				return ValuePointertype->invertToolDirOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertToolDirOut = Value;
			}
		}

		property int invertFloodOut
		{
			int get()
			{
				return ValuePointertype->invertFloodOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertFloodOut = Value;
			}
		}
		property int invertMistOut
		{
			int get()
			{
				return ValuePointertype->invertMistOut;
			}
			void set(int Value)
			{
				ValuePointertype->invertMistOut = Value;
			}
		}
		property int invertAux1Out
		{
			int get()
			{
				return ValuePointertype->invertAux1Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux1Out = Value;
			}
		}
		property int invertAux2Out
		{
			int get()
			{
				return ValuePointertype->invertAux2Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux2Out = Value;
			}
		}
		property int invertAux3Out
		{
			int get()
			{
				return ValuePointertype->invertAux3Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux3Out = Value;
			}
		}
		property int invertAux4Out
		{
			int get()
			{
				return ValuePointertype->invertAux4Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux4Out = Value;
			}
		}
		property int invertAux5Out
		{
			int get()
			{
				return ValuePointertype->invertAux5Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux5Out = Value;
			}
		}
		property int invertAux6Out
		{
			int get()
			{
				return ValuePointertype->invertAux6Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux6Out = Value;
			}
		}
		property int invertAux7Out
		{
			int get()
			{
				return ValuePointertype->invertAux7Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux7Out = Value;
			}
		}
		property int invertAux8Out
		{
			int get()
			{
				return ValuePointertype->invertAux8Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux8Out = Value;
			}
		}
		property int invertAux9Out
		{
			int get()
			{
				return ValuePointertype->invertAux9Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux9Out = Value;
			}
		}
		property int invertAux10Out
		{
			int get()
			{
				return ValuePointertype->invertAux10Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux10Out = Value;
			}
		}

		property int invertPwm1Out
		{
			int get()
			{
				return ValuePointertype->invertPwm1Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm1Out = Value;
			}
		}
		property int invertPwm2Out
		{
			int get()
			{
				return ValuePointertype->invertPwm2Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm2Out = Value;
			}
		}
		property int invertPwm3Out
		{
			int get()
			{
				return ValuePointertype->invertPwm3Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm3Out = Value;
			}
		}
		property int invertPwm4Out
		{
			int get()
			{
				return ValuePointertype->invertPwm4Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm4Out = Value;
			}
		}
		property int invertPwm5Out
		{
			int get()
			{
				return ValuePointertype->invertPwm5Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm5Out = Value;
			}
		}
		property int invertPwm6Out
		{
			int get()
			{
				return ValuePointertype->invertPwm6Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm6Out = Value;
			}
		}
		property int invertPwm7Out
		{
			int get()
			{
				return ValuePointertype->invertPwm7Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm7Out = Value;
			}
		}
		property int invertPwm8Out
		{
			int get()
			{
				return ValuePointertype->invertPwm8Out;
			}
			void set(int Value)
			{
				ValuePointertype->invertPwm8Out = Value;
			}
		}

		property int invertAux1In
		{
			int get()
			{
				return ValuePointertype->invertAux1In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux1In = Value;
			}
		}
		property int invertAux2In
		{
			int get()
			{
				return ValuePointertype->invertAux2In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux2In = Value;
			}
		}
		property int invertAux3In
		{
			int get()
			{
				return ValuePointertype->invertAux3In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux3In = Value;
			}
		}
		property int invertAux4In
		{
			int get()
			{
				return ValuePointertype->invertAux4In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux4In = Value;
			}
		}
		property int invertAux5In
		{
			int get()
			{
				return ValuePointertype->invertAux5In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux5In = Value;
			}
		}
		property int invertAux6In
		{
			int get()
			{
				return ValuePointertype->invertAux6In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux6In = Value;
			}
		}
		property int invertAux7In
		{
			int get()
			{
				return ValuePointertype->invertAux7In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux7In = Value;
			}
		}
		property int invertAux8In
		{
			int get()
			{
				return ValuePointertype->invertAux8In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux8In = Value;
			}
		}
		property int invertAux9In
		{
			int get()
			{
				return ValuePointertype->invertAux9In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux9In = Value;
			}
		}
		property int invertAux10In
		{
			int get()
			{
				return ValuePointertype->invertAux10In;
			}
			void set(int Value)
			{
				ValuePointertype->invertAux10In = Value;
			}
		}


		property int invertPauseIn
		{
			int get()
			{
				return ValuePointertype->invertPauseIn;
			}
			void set(int Value)
			{
				ValuePointertype->invertPauseIn = Value;
			}
		}
		property int invertDriveErrIn
		{
			int get()
			{
				return ValuePointertype->invertDriveErrIn;
			}
			void set(int Value)
			{
				ValuePointertype->invertDriveErrIn = Value;
			}
		}
		property int invertDriveWarnIn
		{
			int get()
			{
				return ValuePointertype->invertDriveWarnIn;
			}
			void set(int Value)
			{
				ValuePointertype->invertDriveWarnIn = Value;
			}
		}

		property int invertAnalog1
		{
			int get()
			{
				return ValuePointertype->invertAnalog1;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog1 = Value;
			}
		}
		property int invertAnalog2
		{
			int get()
			{
				return ValuePointertype->invertAnalog2;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog2 = Value;
			}
		}
		property int invertAnalog3
		{
			int get()
			{
				return ValuePointertype->invertAnalog3;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog3 = Value;
			}
		}
		property int invertAnalog4
		{
			int get()
			{
				return ValuePointertype->invertAnalog4;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog4 = Value;
			}
		}
		property int invertAnalog5
		{
			int get()
			{
				return ValuePointertype->invertAnalog5;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog5 = Value;
			}
		}
		property int invertAnalog6
		{
			int get()
			{
				return ValuePointertype->invertAnalog6;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog6 = Value;
			}
		}
		property int invertAnalog7
		{
			int get()
			{
				return ValuePointertype->invertAnalog7;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog7 = Value;
			}
		}
		property int invertAnalog8
		{
			int get()
			{
				return ValuePointertype->invertAnalog8;
			}
			void set(int Value)
			{
				ValuePointertype->invertAnalog8 = Value;
			}
		}

		property String^ nameExtErrIn
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameExtErrIn);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameExtErrIn), Value, ValuePointertype->nameExtErrIn);
			}
		}
		property String^ nameFloodOut
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameFloodOut);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameFloodOut), Value, ValuePointertype->nameFloodOut);
			}
		}
		property String^ nameMistOut
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameMistOut);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameMistOut), Value, ValuePointertype->nameMistOut);
			}
		}
		property String^ nameAux1Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux1Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux1Out), Value, ValuePointertype->nameAux1Out);
			}
		}
		property String^ nameAux2Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux2Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux2Out), Value, ValuePointertype->nameAux2Out);
			}
		}
		property String^ nameAux3Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux3Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux3Out), Value, ValuePointertype->nameAux3Out);
			}
		}
		property String^ nameAux4Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux4Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux4Out), Value, ValuePointertype->nameAux4Out);
			}
		}
		property String^ nameAux5Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux5Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux5Out), Value, ValuePointertype->nameAux5Out);
			}
		}
		property String^ nameAux6Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux6Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux6Out), Value, ValuePointertype->nameAux6Out);
			}
		}
		property String^ nameAux7Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux7Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux7Out), Value, ValuePointertype->nameAux7Out);
			}
		}
		property String^ nameAux8Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux8Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux8Out), Value, ValuePointertype->nameAux8Out);
			}
		}
		property String^ nameAux9Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux9Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux9Out), Value, ValuePointertype->nameAux9Out);
			}
		}
		property String^ nameAux10Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux10Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux10Out), Value, ValuePointertype->nameAux10Out);
			}
		}

		property String^ namePwm1Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm1Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm1Out), Value, ValuePointertype->namePwm1Out);
			}
		}
		property String^ namePwm2Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm2Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm2Out), Value, ValuePointertype->namePwm2Out);
			}
		}
		property String^ namePwm3Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm3Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm3Out), Value, ValuePointertype->namePwm3Out);
			}
		}
		property String^ namePwm4Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm4Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm4Out), Value, ValuePointertype->namePwm4Out);
			}
		}
		property String^ namePwm5Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm5Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm5Out), Value, ValuePointertype->namePwm5Out);
			}
		}
		property String^ namePwm6Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm6Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm6Out), Value, ValuePointertype->namePwm6Out);
			}
		}
		property String^ namePwm7Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm7Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm7Out), Value, ValuePointertype->namePwm7Out);
			}
		}
		property String^ namePwm8Out
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->namePwm8Out);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->namePwm8Out), Value, ValuePointertype->namePwm8Out);
			}
		}

		property String^ nameAux1In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux1In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux1In), Value, ValuePointertype->nameAux1In);
			}
		}
		property String^ nameAux2In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux2In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux2In), Value, ValuePointertype->nameAux2In);
			}
		}
		property String^ nameAux3In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux3In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux3In), Value, ValuePointertype->nameAux3In);
			}
		}
		property String^ nameAux4In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux4In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux4In), Value, ValuePointertype->nameAux4In);
			}
		}
		property String^ nameAux5In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux5In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux5In), Value, ValuePointertype->nameAux5In);
			}
		}
		property String^ nameAux6In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux6In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux6In), Value, ValuePointertype->nameAux6In);
			}
		}
		property String^ nameAux7In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux7In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux7In), Value, ValuePointertype->nameAux7In);
			}
		}
		property String^ nameAux8In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux8In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux8In), Value, ValuePointertype->nameAux8In);
			}
		}
		property String^ nameAux9In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux9In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux9In), Value, ValuePointertype->nameAux9In);
			}
		}
		property String^ nameAux10In
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->nameAux10In);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->nameAux10In), Value, ValuePointertype->nameAux10In);
			}
		}

	};
	public ref class CncIoPortSts :public Managedstruct<CNC_IO_PORT_STS>
	{
	public:
		CncIoPortSts(CNC_IO_PORT_STS * _CNC_IO_PORT_STS) :Managedstruct(_CNC_IO_PORT_STS) {}
		CncIoPortSts() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncIoPortSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* The ID */
		property CncIoId ioId//CNC_IO_ID      ioId;
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->ioId;
			}
		private:
			void set(CncIoId Value)
			{

			}
		}
		/* Actually configuration item, set by configuration while reading ini file */
		property int invert
		{
			int get()
			{
				return ValuePointertype->invert;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* the current logic value, active/on = 1, inactive/off = 0 */
		property int lvalue
		{
			int get()
			{
				return ValuePointertype->lvalue;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* the current raw value direct from CPU */
		property int rvalue
		{
			int get()
			{
				return ValuePointertype->rvalue;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* 1 if present on CPU */
		property int present
		{
			int get()
			{
				return ValuePointertype->present;
			}
		private:
			void set(int Value)
			{

			}
		}
	};
	public ref class CncGpioPortSts :public Managedstruct<CNC_GPIO_PORT_STS>
	{
	public:
		CncGpioPortSts(CNC_GPIO_PORT_STS * _CNC_GPIO_PORT_STS) :Managedstruct(_CNC_GPIO_PORT_STS) {}
		CncGpioPortSts() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncGpioPortSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/*
		bool SetSeleted_IoId(int cardNr, CncGpioId ioId)
		{
			bool Return = false;
			CNC_GPIO_PORT_STS * Buffer_CNC_GPIO_PORT_STS = CncGetGPIOStatus(cardNr, (CNC_GPIO_ID)ioId);
			if (Buffer_CNC_GPIO_PORT_STS != NULL)
			{
				ValuePointertype = Buffer_CNC_GPIO_PORT_STS;
				Temp_ioId = ioId;
				Return = true;
			}
			return Return;
		}
		property CncGpioId Seleted_IoId
		{
			CncGpioId get()
			{
				return Temp_ioId;
			}
		}
		*/
		/* The ID */
		property CncGpioId ioId
		{
			CncGpioId get()
			{
				return (CncGpioId)ValuePointertype->ioId;
			}
		private:
			void set(CncGpioId Value)
			{

			}
		}
		/* Actually configuration item, set by configuration while reading ini file */
		property int invert
		{
			int get()
			{
				return ValuePointertype->invert;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* the current logic value, active/on = 1, inactive/off = 0 */
		property int lvalue
		{
			int get()
			{
				return ValuePointertype->lvalue;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* the current raw value direct from CPU */
		property int rvalue
		{
			int get()
			{
				return ValuePointertype->rvalue;
			}
		private:
			void set(int Value)
			{

			}
		}
		/* 1 if present on CPU */
		property int present
		{
			int get()
			{
				return ValuePointertype->present;
			}
		private:
			void set(int Value)
			{

			}
		}
		/* IO name */
		property String^ name
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->name);
			}
		private:
			void set(String^ Value)
			{

			}
		}

	};
	public ref class CncJointCfg :public Managedstruct<CNC_JOINT_CFG>
	{
	public:
		CncJointCfg(CNC_JOINT_CFG * _CNC_JOINT_CFG) :Managedstruct(_CNC_JOINT_CFG) {}
		CncJointCfg() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncJointCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* logical name of the joint, used in GUI, one character */
		property Char name
		{
			Char get()
			{
				return ValuePointertype->name;
			}
			void set(Char Value)
			{
				ValuePointertype->name = (char)Value;
			}
		}
		property bool isVisible      //True if axis visible in GUI
		{
			bool get()
			{
				return ValuePointertype->isVisible;
			}
			void set(bool Value)
			{
				ValuePointertype->isVisible = Value;
			}
		}
		property int cpuPortIndex   //0-5 for 6 axes board, -1 if not used
		{
			int get()
			{
				return ValuePointertype->cpuPortIndex;
			}
			void set(int Value)
			{
				ValuePointertype->cpuPortIndex = Value;
			}
		}
		/* Axis resolution nuber of increments for one application unit */
		property double resolution
		{
			double get()
			{
				return ValuePointertype->resolution;
			}
			void set(double Value)
			{
				ValuePointertype->resolution = Value;
			}
		}
		property double positiveLimit
		{
			double get()
			{
				return ValuePointertype->positiveLimit;
			}
			void set(double Value)
			{
				ValuePointertype->positiveLimit = Value;
			}
		}
		property double negativeLimit
		{
			double get()
			{
				return ValuePointertype->negativeLimit;
			}
			void set(double Value)
			{
				ValuePointertype->negativeLimit = Value;
			}
		}
		/* max values for velocity, acceleration, AU  */
		property double maxVelocity
		{
			double get()
			{
				return ValuePointertype->maxVelocity;
			}
			void set(double Value)
			{
				ValuePointertype->maxVelocity = Value;
			}
		}
		property double maxAcceleration
		{
			double get()
			{
				return ValuePointertype->maxAcceleration;
			}
			void set(double Value)
			{
				ValuePointertype->maxAcceleration = Value;
			}
		}
		/* homing parameters, AU  */
		property double homeVelocity //Sign is direction
		{
			double get()
			{
				return ValuePointertype->homeVelocity;
			}
			void set(double Value)
			{
				ValuePointertype->homeVelocity = Value;
			}
		}
		property double homeVelocitySlow //Slow vel for 2nd move
		{
			double get()
			{
				return ValuePointertype->homeVelocitySlow;
			}
			void set(double Value)
			{
				ValuePointertype->homeVelocitySlow = Value;
			}
		}
		property double homePosition     //Position at home sensor
		{
			double get()
			{
				return ValuePointertype->homePosition;
			}
			void set(double Value)
			{
				ValuePointertype->homePosition = Value;
			}
		}
		/* backlash parameters */
		property double backLash
		{
			double get()
			{
				return ValuePointertype->backLash;
			}
			void set(double Value)
			{
				ValuePointertype->backLash = Value;
			}
		}
		/* jog speed percentages */
		property double lowSpeedJogPercent
		{
			double get()
			{
				return ValuePointertype->lowSpeedJogPercent;
			}
			void set(double Value)
			{
				ValuePointertype->lowSpeedJogPercent = Value;
			}
		}
		property double medSpeedJogPercent
		{
			double get()
			{
				return ValuePointertype->medSpeedJogPercent;
			}
			void set(double Value)
			{
				ValuePointertype->medSpeedJogPercent = Value;
			}
		}
		property double highSpeedJogPercen
		{
			double get()
			{
				return ValuePointertype->highSpeedJogPercent;
			}
			void set(double Value)
			{
				ValuePointertype->highSpeedJogPercent = Value;
			}
		}
		/* pitch compensation */
		property String^ pitchCompensationFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->pitchCompensationFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->pitchCompensationFileName), Value, ValuePointertype->pitchCompensationFileName);
			}
		}
		property int  pitchCompensationOn
		{
			int get()
			{
				return ValuePointertype->pitchCompensationOn;
			}
			void set(int Value)
			{
				ValuePointertype->pitchCompensationOn = Value;
			}
		}

		/* cross compensation, this axis is corrected by another */
		property String^ crossCompensationFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->crossCompensationFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->crossCompensationFileName), Value, ValuePointertype->crossCompensationFileName);
			}
		}
		property int crossCompensationFromAxis /* 0 or 1 meaning X or Y, all other values invalid */
		{
			int get()
			{
				return ValuePointertype->crossCompensationFromAxis;
			}
			void set(int Value)
			{
				ValuePointertype->crossCompensationFromAxis = Value;
			}
		}
	};
	public ref class CncFeedSpeedCfg :public Managedstruct<CNC_FEEDSPEED_CFG>
	{
	public:
		CncFeedSpeedCfg(CNC_FEEDSPEED_CFG * _CNC_FEEDSPEED_CFG) :Managedstruct(_CNC_FEEDSPEED_CFG) {}
		CncFeedSpeedCfg() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncFeedSpeedCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncFeedspeedOverrideSource feedOverrideSource
		{
			CncFeedspeedOverrideSource get()
			{
				return (CncFeedspeedOverrideSource)ValuePointertype->feedOverrideSource;
			}
			void set(CncFeedspeedOverrideSource Value)
			{
				ValuePointertype->feedOverrideSource = (CNC_FEEDSPEED_OVERRIDE_SOURCE)Value;
			}
		}
		property CncFeedspeedOverrideSource speedOverrideSource
		{
			CncFeedspeedOverrideSource get()
			{
				return (CncFeedspeedOverrideSource)ValuePointertype->speedOverrideSource;
			}
			void set(CncFeedspeedOverrideSource Value)
			{
				ValuePointertype->speedOverrideSource = (CNC_FEEDSPEED_OVERRIDE_SOURCE)Value;
			}
		}

		property int adaptiveSpindlePowerFeedOv//only when on and spindle running not ramping
		{
			int get()
			{
				return ValuePointertype->adaptiveSpindlePowerFeedOv;
			}
			void set(int Value)
			{
				ValuePointertype->adaptiveSpindlePowerFeedOv = Value;
			}
		}
		property double analogFeedOvAtMaxVoltage  //Allow to adjust feeoOv by analog in as user wants it
		{
			double get()
			{
				return ValuePointertype->analogFeedOvAtMaxVoltage;
			}
			void set(double Value)
			{
				ValuePointertype->analogFeedOvAtMaxVoltage = Value;
			}
		}
		property double analogFeedOvAtMinVoltage  //User only needs to supply to give the feeoOv at max analog input 
		{
			double get()
			{
				return ValuePointertype->analogFeedOvAtMinVoltage;
			}
			void set(double Value)
			{
				ValuePointertype->analogFeedOvAtMinVoltage = Value;
			}
		}								  //and at min analog input.

		property int analogStopOnHigherThreshold//Stop motion if analogue value goes above this value.
		{
			int get()
			{
				return ValuePointertype->analogStopOnHigherThreshold;
			}
			void set(int Value)
			{
				ValuePointertype->analogStopOnHigherThreshold = Value;
			}
		}
		property CncIoId feedHoldInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->feedHoldInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->feedHoldInputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId speedHoldInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->speedHoldInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->speedHoldInputPortID = (CNC_IO_ID)Value;
			}
		}

		property int useAnalogFilter
		{
			int get()
			{
				return ValuePointertype->useAnalogFilter;
			}
			void set(int Value)
			{
				ValuePointertype->useAnalogFilter = Value;
			}
		}
	};
	public ref class CncHandWheelCfg :public Managedstruct<CNC_HANDWHEEL_CFG>
	{
	public:
		CncHandWheelCfg(CNC_HANDWHEEL_CFG * _CNC_HANDWHEEL_CFG) :Managedstruct(_CNC_HANDWHEEL_CFG) {}
		CncHandWheelCfg() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncHandWheelCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* hand wheel encoder count for one revolution */
		property int handwheelCountPerRev
		{
			int get()
			{
				return ValuePointertype->handwheelCountPerRev;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelCountPerRev = Value;
			}
		}

		/* vel limit for hand wheel percentage of selected axis max vel */
		property int handweelVPercent
		{
			int get()
			{
				return ValuePointertype->handweelVPercent;
			}
			void set(int Value)
			{
				ValuePointertype->handweelVPercent = Value;
			}
		}

		/* acc limit for hand wheel percentage of selected axis max acc */
		property int handwheelAPercent
		{
			int get()
			{
				return ValuePointertype->handwheelAPercent;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelAPercent = Value;
			}
		}

		/* velocity mode for 1x scale */
		property int handwheelX1VelMode
		{
			int get()
			{
				return ValuePointertype->handwheelX1VelMode;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelX1VelMode = Value;
			}
		}

		/* velocity mode for 10x scale */
		property int handwheelX10VelMode
		{
			int get()
			{
				return ValuePointertype->handwheelX10VelMode;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelX10VelMode = Value;
			}
		}

		/* velocity mode for 100x scale */
		property int handwheelX100VelMode
		{
			int get()
			{
				return ValuePointertype->handwheelX100VelMode;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelX100VelMode = Value;
			}
		}

		/* use analog input to select hand wheel axis */
		property CncIoId axisSelectAnInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->axisSelectAnInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->axisSelectAnInputPortID = (CNC_IO_ID)Value;
			}
		}

		/* use analog input to select hand wheel multiplication factor */
		property  CncIoId mulfactorSelectAnInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->mulfactorSelectAnInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->mulfactorSelectAnInputPortID = (CNC_IO_ID)Value;
			}
		}

		/* used to differentiate various XHC pendants, needed because HB04 and HB04B have no ID */
	   /* 0 : HB04B EdingCNC */
	   /* 1 : HB04B other    */
	   /* start XHC connect automatically if option > 0      */

	   /* Note that:                                         */
	   /* 0 : No pendant                                     */
	   /* 1 : Old style pendant                              HB04B other    */
	   /* 2 : Pendant with FEEDOV on selector button.        HB04B EdingCNC */
	   /* 3 : Pendant with FEEDOV and SPEEDOV on MPG wheel.  HB04B EdingCNC */

		property int handwheelType
		{
			int get()
			{
				return ValuePointertype->handwheelType;
			}
			void set(int Value)
			{
				ValuePointertype->handwheelType = Value;
			}
		}
	};
	public ref class CncTrajectoryCfg :public Managedstruct<CNC_TRAJECTORY_CFG>
	{
	public:
		CncTrajectoryCfg(CNC_TRAJECTORY_CFG * _CNC_TRAJECTORY_CFG) :Managedstruct(_CNC_TRAJECTORY_CFG) {}
		CncTrajectoryCfg() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncTrajectoryCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* trajectory interpolation time in seconds e.g. 0.01 second */
		property double interpolationTime
		{
			double get()
			{
				return ValuePointertype->interpolationTime;
			}
			void set(double Value)
			{
				ValuePointertype->interpolationTime = Value;
			}
		}
		property double fifoTime
		{
			double get()
			{
				return ValuePointertype->fifoTime;
			}
			void set(double Value)
			{
				ValuePointertype->fifoTime = Value;
			}
		}

		property double minCircleSegmentSize
		{
			double get()
			{
				return ValuePointertype->minCircleSegmentSize;
			}
			void set(double Value)
			{
				ValuePointertype->minCircleSegmentSize = Value;
			}
		}

		/* Laf reports G1 is G0 when velocity higher than this */
		/* required for 3D printing because 3D printing CAM software always outputs G1 */
		property double g1ShowsAsG0VelLimit
		{
			double get()
			{
				return ValuePointertype->g1ShowsAsG0VelLimit;
			}
			void set(double Value)
			{
				ValuePointertype->g1ShowsAsG0VelLimit = Value;
			}
		}

		/* look ahead feed angle in degrees, connecting lines with
		angle between this value and 180 are considered straight */
		property double lafAngleFullSpeed
		{
			double get()
			{
				return ValuePointertype->lafAngleFullSpeed;
			}
			void set(double Value)
			{
				ValuePointertype->lafAngleFullSpeed = Value;
			}
		}
		property double lafAngleReducedSpeed
		{
			double get()
			{
				return ValuePointertype->lafAngleReducedSpeed;
			}
			void set(double Value)
			{
				ValuePointertype->lafAngleReducedSpeed = Value;
			}
		}
		property double lafDeltaReducedSpeed
		{
			double get()
			{
				return ValuePointertype->lafDeltaReducedSpeed;
			}
			void set(double Value)
			{
				ValuePointertype->lafDeltaReducedSpeed = Value;
			}
		}
		property double lafAccFilter
		{
			double get()
			{
				return ValuePointertype->lafAccFilter;
			}
			void set(double Value)
			{
				ValuePointertype->lafAccFilter = Value;
			}
		}

		property double lafArcfeedFactor //Default arc feed factor
		{
			double get()
			{
				return ValuePointertype->lafArcfeedFactor;
			}
			void set(double Value)
			{
				ValuePointertype->lafArcfeedFactor = Value;
			}
		}
		/* on some hi speed machines, the velocity and acceleration for milling (G1/G2/G3) can be different as for positioning (G0) */
		/* the values below are factors for the velocity and acceleration for positioning movements (G0) */
		property double g0VelocityFactor
		{
			double get()
			{
				return ValuePointertype->g0VelocityFactor;
			}
			void set(double Value)
			{
				ValuePointertype->g0VelocityFactor = Value;
			}
		}
		property double g0AccelelerationFactor
		{
			double get()
			{
				return ValuePointertype->g0AccelelerationFactor;
			}
			void set(double Value)
			{
				ValuePointertype->g0AccelelerationFactor = Value;
			}
		}
	};
	public ref class CncCameraConfig :public Managedstruct<CNC_CAMERA_CONFIG>
	{
	public:
		CncCameraConfig(CNC_CAMERA_CONFIG * _CNC_CAMERA_CONFIG) :Managedstruct(_CNC_CAMERA_CONFIG) {}
		CncCameraConfig() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncCameraConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int cameraOn	     //o=off, 1=on
		{
			int get()
			{
				return ValuePointertype->cameraOn;
			}
			void set(int Value)
			{
				ValuePointertype->cameraOn = Value;
			}
		}
		property int cameraIndex      //0 is first, 1 is second etc.
		{
			int get()
			{
				return ValuePointertype->cameraIndex;
			}
			void set(int Value)
			{
				ValuePointertype->cameraIndex = Value;
			}
		}
		property int cameraFlip
		{
			int get()
			{
				return ValuePointertype->cameraFlip;
			}
			void set(int Value)
			{
				ValuePointertype->cameraFlip = Value;
			}
		}
		property int cameraMirror
		{
			int get()
			{
				return ValuePointertype->cameraMirror;
			}
			void set(int Value)
			{
				ValuePointertype->cameraMirror = Value;
			}
		}
		property int cameraRotationAngle
		{
			int get()
			{
				return ValuePointertype->cameraRotationAngle;
			}
			void set(int Value)
			{
				ValuePointertype->cameraRotationAngle = Value;
			}
		}
	};
	public ref class CncServiceCfg :public Managedstruct<CNC_SERVICE_CFG>
	{
	private:
		array<double>^ Temp_reserved = nullptr;
		void NewClass()
		{
			Temp_reserved = gcnew array<double>(sizeof(ValuePointertype->reserved) / SizeOfdoublex32);
		}
	public:
		CncServiceCfg(CNC_SERVICE_CFG * _CNC_SERVICE_CFG) :Managedstruct(_CNC_SERVICE_CFG)
		{
			NewClass();
		}
		CncServiceCfg() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncServiceCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* total time that machine has performed a job */
		property double stsUsageTimeHoursTotal
		{
			double get()
			{
				return ValuePointertype->stsUsageTimeHoursTotal;
			}
			void set(double Value)
			{
				ValuePointertype->stsUsageTimeHoursTotal = Value;
			}
		}

		/* time since last service reset */
		property double stsUsageTimeHoursService
		{
			double get()
			{
				return ValuePointertype->stsUsageTimeHoursService;
			}
			void set(double Value)
			{
				ValuePointertype->stsUsageTimeHoursService = Value;
			}
		}

		/* total machine traveled distance in meters */
		property double stsTraveledDistMetersTotal
		{
			double get()
			{
				return ValuePointertype->stsTraveledDistMetersTotal;
			}
			void set(double Value)
			{
				ValuePointertype->stsTraveledDistMetersTotal = Value;
			}
		}

		/* traveled distance since last service */
		property double stsTraveledDistMetersService
		{
			double get()
			{
				return ValuePointertype->stsTraveledDistMetersService;
			}
			void set(double Value)
			{
				ValuePointertype->stsTraveledDistMetersService = Value;
			}
		}

		/* number of jobs that has been done */
		property int stsNumJobsDoneTotal
		{
			int get()
			{
				return ValuePointertype->stsNumJobsDoneTotal;
			}
			void set(int Value)
			{
				ValuePointertype->stsNumJobsDoneTotal = Value;
			}
		}

		/* number of jobs that has been done */
		property int stsNumJobsDoneService
		{
			int get()
			{
				return ValuePointertype->stsNumJobsDoneService;
			}
			void set(int Value)
			{
				ValuePointertype->stsNumJobsDoneService = Value;
			}
		}

		/* time of usage for next service */
		property double parServiceTimeIntervalHours
		{
			double get()
			{
				return ValuePointertype->parServiceTimeIntervalHours;
			}
			void set(double Value)
			{
				ValuePointertype->parServiceTimeIntervalHours = Value;
			}
		}

		/* travel distance for next service */
		property double parServiceTravelDistInterval
		{
			double get()
			{
				return ValuePointertype->parServiceTravelDistInterval;
			}
			void set(double Value)
			{
				ValuePointertype->parServiceTravelDistInterval = Value;
			}
		}
		/* pump function */
		property double pumpIntervalTimeSeconds
		{
			double get()
			{
				return ValuePointertype->pumpIntervalTimeSeconds;
			}
			void set(double Value)
			{
				ValuePointertype->pumpIntervalTimeSeconds = Value;
			}
		}
		property double pumpPulseTimeSeconds
		{
			double get()
			{
				return ValuePointertype->pumpPulseTimeSeconds;
			}
			void set(double Value)
			{
				ValuePointertype->pumpPulseTimeSeconds = Value;
			}
		}
		property double stsPumpTimeToGo
		{
			double get()
			{
				return ValuePointertype->stsPumpTimeToGo;
			}
			void set(double Value)
			{
				ValuePointertype->stsPumpTimeToGo = Value;
			}
		}
		property CncIoId pumpPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->pumpPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->pumpPortID = (CNC_IO_ID)Value;
			}
		}
		property array<double>^ reserved
		{
			array<double>^get()
			{
				for (int i = 0; i < Temp_reserved->Length; i++)
				{
					Temp_reserved[i] = ValuePointertype->reserved[i];
				}
				return Temp_reserved;
			}
			void set(array<double>^ value)
			{
				if (value->Length == Temp_reserved->Length)
				{
					for (int i = 0; i < Temp_reserved->Length; i++)
					{
						ValuePointertype->reserved[i] = value[i];
					}
				}
			}
		}
	};
	public ref class CncControllerConfigStatus : public Managedstruct<CNC_CONTROLLER_CONFIG_STATUS>
	{
	private://controllerFrequencyTimerValues
		array<int>^ Temp_controllerFrequencyTimerValues = nullptr;
		array<double>^ Temp_controllerFrequencies = nullptr;
		array<String^>^ Temp_comPortList = nullptr;
		void NewClass()
		{
			Temp_controllerFrequencyTimerValues = gcnew array<int>(sizeof(ValuePointertype->controllerFrequencyTimerValues) / SizeOfintx32);
			Temp_controllerFrequencies = gcnew array<double>(sizeof(ValuePointertype->controllerFrequencies) / SizeOfdoublex32);
			Temp_comPortList = gcnew array<String^>(CNC_MAX_COMM_PORTS);
		}
	public:
		CncControllerConfigStatus(CNC_CONTROLLER_CONFIG_STATUS * _CONTROLLER_CONFIG_STATUS) :Managedstruct(_CONTROLLER_CONFIG_STATUS)
		{
			NewClass();
		}
		CncControllerConfigStatus() :Managedstruct(nullptr) 
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncControllerConfigStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int  comPortListSize
		{
			int get()
			{
				return  ValuePointertype->comPortListSize;
			}
		private:
			void set(int Value)
			{

			}
		}
		property array<String^>^ comPortList
		{
			array<String^>^ get()
			{
				int Temp_ComportLength = comPortListSize;

				if (Temp_comPortList->Length < Temp_ComportLength)
				{
					Temp_ComportLength = Temp_comPortList->Length;
				}

				for (int i = 0; i < Temp_ComportLength; i++)
				{
					Temp_comPortList[i] = StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->comPortList[i]);
				}
				
				return Temp_comPortList;
			}
		private:
			void set(array<String^>^ Value)
			{

			}
		}

		property int  connectedViaEtherNet
		{
			int get()
			{
				return ValuePointertype->connectedViaEtherNet;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  connectedViaUSB
		{
			int get()
			{
				return ValuePointertype->connectedViaUSB;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  connectedViaSimulation
		{
			int get()
			{
				return ValuePointertype->connectedViaSimulation;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* if the USB/ETH plug is pulled out or power is switched OFF from CPU */
		property int  connectionError
		{
			int get()
			{
				return ValuePointertype->connectionError;
			}
		private:
			void set(int Value)
			{

			}
		}
		/* controller frequency table */
		property array<double>^ controllerFrequencies
		{
			array<double>^ get()
			{
				for (int i = 0; i < Temp_controllerFrequencies->Length; i++)
				{
					Temp_controllerFrequencies[i] = ValuePointertype->controllerFrequencies[i];
				}

				return Temp_controllerFrequencies;
			}
		private:
			void set(array<double>^ Value)
			{

			}
		}
		property array<int>^ controllerFrequencyTimerValues
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_controllerFrequencyTimerValues->Length; i++)
				{
					Temp_controllerFrequencyTimerValues[i] = ValuePointertype->controllerFrequencyTimerValues[i];
				}
				return Temp_controllerFrequencyTimerValues;
			}
		private:
			void set(array<int>^ Value)
			{

			}
		}

		property int controllerNumberOfFrequencies
		{
			int get()
			{
				return ValuePointertype->controllerNumberOfFrequencies;
			}
		private:
			void set(int Value)
			{

			}
		}


		/* Controller firmware version, max axes, lathe capability */
		property String^controllerFirmwareVersion//[CNC_MAX_NAME_LENGTH]
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->controllerFirmwareVersion);
			}
		private:
			void set(String^ Value)
			{

			}
		}
		property int  controllerMaxAxes
		{
			int get()
			{
				return ValuePointertype->controllerMaxAxes;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  controllerAvailableAxes
		{
			int get()
			{
				return ValuePointertype->controllerAvailableAxes;
			}
		private:
			void set(int Value)
			{

			}
		}


		/* 1 if firmware has SW options */
		property int  firmwareHasOptions
		{
			int get()
			{
				return ValuePointertype->firmwareHasOptions;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* if False, a g-code program cannot be run */
		property int  cpuIsEnabled
		{
			int get()
			{
				return ValuePointertype->cpuIsEnabled;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* if false function is not available */
		property int  avx1GPIOIsEnabled
		{
			int get()
			{
				return ValuePointertype->avx1GPIOIsEnabled;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  ediGPIOIsEnabled
		{
			int get()
			{
				return ValuePointertype->ediGPIOIsEnabled;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  plasmaIsEnabled
		{
			int get()
			{
				return ValuePointertype->plasmaIsEnabled;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* we have cpu's with 10 and 12 bit ADC, range 0-1023 abd range 0-4096 */
		property int  maxAnalogValue
		{
			int get()
			{
				return ValuePointertype->maxAnalogValue;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int  cpuType
		{
			int get()
			{
				return ValuePointertype->cpuType;
			}
		private:
			void set(int Value)
			{

			}
		}

		/* initialize counter, incremented at every init */
		property int initCount
		{
			int get()
			{
				return ValuePointertype->initCount;
			}
		private:
			void set(int Value)
			{

			}
		}
	};
	public ref class CncTraffigLightStatus :public Managedstruct<CNC_TRAFFIC_LIGHT_STATUS>
	{
	public:
		CncTraffigLightStatus(CNC_TRAFFIC_LIGHT_STATUS * _TRAFFIC_LIGHT_STATUS) :Managedstruct(_TRAFFIC_LIGHT_STATUS) {}
		CncTraffigLightStatus() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncTraffigLightStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncTrafficLightColor trafficLightColor
		{
			CncTrafficLightColor get()
			{
				return (CncTrafficLightColor)ValuePointertype->trafficLightColor;
			}

		}
		property int trafficLightBlink//True if blink
		{
			int get()
			{
				return ValuePointertype->trafficLightBlink;
			}

		}
		property String^ traficLightReason//[CNC_MAX_LOGGING_TEXT]
		{
			String^get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->traficLightReason);
			}

		}
	};
	public ref class CncNestingStatus :public Managedstruct<CNC_NESTING_STATUS>
	{
	public:
		CncNestingStatus(CNC_NESTING_STATUS * _CNC_NESTING_STATUS) :Managedstruct(_CNC_NESTING_STATUS) {}
		CncNestingStatus() :Managedstruct(nullptr) {}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncNestingStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* job array status */
		property int doArray
		{
			int get()
			{
				return ValuePointertype->doArray;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int arrayNX
		{
			int get()
			{
				return ValuePointertype->arrayNX;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int arrayNY
		{
			int get()
			{
				return ValuePointertype->arrayNY;
			}
		private:
			void set(int Value)
			{

			}
		}
		property double arrayDX
		{
			double get()
			{
				return ValuePointertype->arrayDX;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayDY
		{
			double get()
			{
				return ValuePointertype->arrayDY;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayStartOffsetX
		{
			double get()
			{
				return ValuePointertype->arrayStartOffsetX;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayStartOffsetY
		{
			double get()
			{
				return ValuePointertype->arrayStartOffsetY;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayMaterialSizeX
		{
			double get()
			{
				return ValuePointertype->arrayMaterialSizeX;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayMaterialSizeY
		{
			double get()
			{
				return ValuePointertype->arrayMaterialSizeY;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayMaterialSizeZ
		{
			double get()
			{
				return ValuePointertype->arrayMaterialSizeZ;
			}
		private:
			void set(double Value)
			{

			}
		}
		property int arrayCurXIndex
		{
			int get()
			{
				return ValuePointertype->arrayCurXIndex;
			}
		private:
			void set(int Value)
			{

			}
		}
		property int arrayCurYIndex
		{
			int get()
			{
				return ValuePointertype->arrayCurYIndex;
			}
		private:
			void set(int Value)
			{

			}
		}
		property double arrayCurXOffset
		{
			double get()
			{
				return ValuePointertype->arrayCurXOffset;
			}
		private:
			void set(double Value)
			{

			}
		}
		property double arrayCurYOffset
		{
			double get()
			{
				return ValuePointertype->arrayCurYOffset;
			}
		private:
			void set(double Value)
			{

			}
		}
	};
	public ref class CncCmdArrayData :public Managedstruct<CNC_CMD_ARRAY_DATA>
	{
	public:
		CncCmdArrayData(CNC_CMD_ARRAY_DATA * _CNC_CMD_ARRAY_DATA) :Managedstruct(_CNC_CMD_ARRAY_DATA) {}
		CncCmdArrayData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncCmdArrayData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int doArray
		{
			int get()
			{
				return ValuePointertype->doArray;
			}
			void set(int value)
			{
				ValuePointertype->doArray = value;
			}
		}
		property double arrayStartOffsetX
		{
			double get()
			{
				return ValuePointertype->arrayStartOffsetX;
			}
			void set(double value)
			{
				ValuePointertype->arrayStartOffsetX = value;
			}
		}
		property double arrayStartOffsetY
		{
			double get()
			{
				return ValuePointertype->arrayStartOffsetY;
			}
			void set(double value)
			{
				ValuePointertype->arrayStartOffsetY = value;
			}
		}
		property double arrayDX
		{
			double get()
			{
				return ValuePointertype->arrayDX;
			}
			void set(double value)
			{
				ValuePointertype->arrayDX = value;
			}
		}
		property double arrayDY
		{
			double get()
			{
				return ValuePointertype->arrayDY;
			}
			void set(double value)
			{
				ValuePointertype->arrayDY = value;
			}
		}
		property int arrayNX
		{
			int get()
			{
				return ValuePointertype->arrayNX;
			}
			void set(int value)
			{
				ValuePointertype->arrayNX = value;
			}
		}
		property int arrayNY
		{
			int get()
			{
				return ValuePointertype->arrayNY;
			}
			void set(int value)
			{
				ValuePointertype->arrayNY = value;
			}
		}
		property double materialSizeX
		{
			double get()
			{
				return ValuePointertype->materialSizeX;
			}
			void set(double value)
			{
				ValuePointertype->materialSizeX = value;
			}
		}
		property double materialSizeY
		{
			double get()
			{
				return ValuePointertype->materialSizeY;
			}
			void set(double value)
			{
				ValuePointertype->materialSizeY = value;
			}
		}
		property double materialSizeZ
		{
			double get()
			{
				return ValuePointertype->materialSizeZ;
			}
			void set(double value)
			{
				ValuePointertype->materialSizeZ = value;
			}
		}
	};
	public ref class CncFiducialData :public Managedstruct<CNC_FIDUCIAL_DATA>
	{
	public:
		CncFiducialData(CNC_FIDUCIAL_DATA * _CNC_FIDUCIAL_DATA) :Managedstruct(_CNC_FIDUCIAL_DATA) {}
		CncFiducialData() :Managedstruct(nullptr) {}
		bool CopyUnmanagedPointer(CncFiducialData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int fidn   //%fidn=... number, -1 if not valid
		{
			int get()
			{
				return ValuePointertype->fidn;
			}

		}
		property int fidt	//%fidt=... type
		{
			int get()
			{
				return ValuePointertype->fidt;
			}

		}
		property double	fidcx	//%fidcx=.. coordinate x
		{
			double get()
			{
				return ValuePointertype->fidcx;
			}

		}
		property double	fidcy	//%fidcy=.. coordinate y
		{
			double get()
			{
				return ValuePointertype->fidcy;
			}

		}
		property double	fidox  //%fidox=.. offset x
		{
			double get()
			{
				return ValuePointertype->fidox;
			}

		}
		property double	fidoy  //%fidoy=.. offset y
		{
			double get()
			{
				return ValuePointertype->fidoy;
			}

		}
		property double	fidor	//%fidor=.. orientation
		{
			double get()
			{
				return ValuePointertype->fidor;
			}

		}
	};
	public ref class CncVacuumStatus :public Managedstruct<CNC_VACUUM_STATUS>
	{
	private:
		array<int>^ Temp_vacuumSectionConfigured = nullptr;
		array<int>^ Temp_vacuumSectionCrossed = nullptr;

		void NewClass()
		{
			Temp_vacuumSectionConfigured = gcnew array<int>(sizeof( ValuePointertype->vacuumSectionConfigured)/ SizeOfintx32);
			Temp_vacuumSectionCrossed = gcnew array<int>(sizeof(ValuePointertype->vacuumSectionCrossed) / SizeOfintx32);
		}
	public:
		CncVacuumStatus(CNC_VACUUM_STATUS * _CNC_VACUUM_STATUS) :Managedstruct(_CNC_VACUUM_STATUS)
		{
			NewClass();
		}
		CncVacuumStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncVacuumStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}


		property int autoMode
		{
			int get()
			{
				return ValuePointertype->autoMode;
			}
			void set(int Value)
			{
				ValuePointertype->autoMode = Value;
			}
		}
		property array<int>^ vacuumSectionConfigured//[CNC_MAX_VACUUMBED_SECTIONS];
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_vacuumSectionConfigured->Length; i++)
				{
					Temp_vacuumSectionConfigured[i] = ValuePointertype->vacuumSectionConfigured[i];
				}

				return Temp_vacuumSectionConfigured;
			}
			void set(array<int>^ Value)
			{
				if (Value->Length == Temp_vacuumSectionConfigured->Length)
				{
					for (int i = 0; i < Temp_vacuumSectionConfigured->Length; i++)
					{
						ValuePointertype->vacuumSectionConfigured[i] = Value[i];
					}
					//_vacuumSectionConfigured = Value;
				}

			}
		}
		property array<int>^ vacuumSectionCrossed//[CNC_MAX_VACUUMBED_SECTIONS];
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_vacuumSectionCrossed->Length; i++)
				{
					Temp_vacuumSectionCrossed[i] = ValuePointertype->vacuumSectionCrossed[i];
				}
				return Temp_vacuumSectionCrossed;
			}
			void set(array<int>^ Value)
			{
				if (Value->Length == Temp_vacuumSectionCrossed->Length)
				{
					for (int i = 0; i < Temp_vacuumSectionCrossed->Length; i++)
					{
						ValuePointertype->vacuumSectionCrossed[i] = Value[i];
					}
					//_vacuumSectionCrossed = Value;
				}

			}
		}
	};
	

	//cnclang.h
	public ref class CncLangAllText
	{
	private:
		bool IsGarbageCollected = false;
	internal:
		array<Managedstruct<char*>^>^ AllLanguages = gcnew array<Managedstruct<char*>^>(14);
		Managedstruct<char>^ BaseLanguage = gcnew Managedstruct<char>(nullptr, MaxTextLength);
	public:
		property int MaxTextLength
		{
			int get()
			{
				return  (int)CncLangMax::TextLength;
			}
		} 

		CncLangAllText()
		{
			
			for (int i =0;i< AllLanguages->Length;i++)
			{
				AllLanguages[i]->ValuePointertype[0] = new char[MaxTextLength];
			}
		}
		~CncLangAllText() { this->!CncLangAllText(); }
		!CncLangAllText()
		{
			if (IsGarbageCollected == false)
			{
				for (int i = 0; i < AllLanguages->Length; i++)
				{
					
					if (AllLanguages[i]->ValuePointertype[0] != nullptr)
					{
						delete[] AllLanguages[i]->ValuePointertype[0];
						AllLanguages[i]->ValuePointertype[0] = nullptr;
					}
				}
				IsGarbageCollected = true;
			}
		}
		property String^ BaseLanguage_english
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(BaseLanguage->ValuePointertype);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(BaseLanguage->ArrayLength,Value, BaseLanguage->ValuePointertype);
			}
		}
		property String^ german
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[0]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength,Value, AllLanguages[0]->ValuePointertype[0]);
			}
		}
		property String^ dutch
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[1]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[1]->ValuePointertype[0]);
			}
		}
		property String^ italian
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[2]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[2]->ValuePointertype[0]);
			}
		}
		property String^ french
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[3]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[3]->ValuePointertype[0]);
			}
		}
		property String^ spanish
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[4]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[4]->ValuePointertype[0]);
			}
		}
		property String^ portugese
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[5]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[5]->ValuePointertype[0]);
			}
		}
		property String^ turkish
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[6]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[6]->ValuePointertype[0]);
			}
		}
		property String^ japanese
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[7]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[7]->ValuePointertype[0]);
			}
		}
		property String^ greek
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[8]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[8]->ValuePointertype[0]);
			}
		}
		property String^ hun
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[9]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[9]->ValuePointertype[0]);
			}
		}
		property String^ cze
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[10]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[10]->ValuePointertype[0]);
			}
		}
		property String^ hkr
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[11]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[11]->ValuePointertype[0]);
			}
		}
		property String^ cn
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[12]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[12]->ValuePointertype[0]);
			}
		}
		property String^ new1
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(AllLanguages[13]->ValuePointertype[0]);
			}
			void set(String^Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MaxTextLength, Value, AllLanguages[13]->ValuePointertype[0]);
			}
		}
	};

	//--
}
