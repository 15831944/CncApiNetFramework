

#include "stdafx.h"
#include <iostream>
#include "cncapi/cncapi.h"
#include "cncapi/cnclang.h"
#include "StringConversie.h"
#include "typedefEnumClass.h"
#include "Cnc_TypesNetFramework.h"

using namespace System;
using namespace  System::Diagnostics;

namespace OosterhofDesign
{
	//http://www.ishbir.com/post/2016-06-09-wrapping-a-c-library-in-c++/
	//http://www.dorodnic.com/blog/2014/12/10/calling-cpp-by-example/
	//using namespace std;
	
	//functions ingedeeld in groepen (groepen hebben dezelfde naam als omschrijving in cncapi.h)
	public ref class G_GetVersionsIons
	{
	private:
		static Managedstruct<char>^ Temp_APIVersion = gcnew Managedstruct<char>(nullptr, CNC_MAX_NAME_LENGTH);
		static Managedstruct<char>^ Temp_ServerVersion = gcnew Managedstruct<char>(nullptr, CNC_MAX_NAME_LENGTH);
		static Managedstruct<char>^ Temp_HeaderVersion = gcnew Managedstruct<char>(nullptr, CNC_MAX_NAME_LENGTH);
	public:
		static property String^ GetNetWrapperAPIVersion
		{
			String ^get()
			{
				return GetHeaderVersion;
			}

		}
		static property String^ GetAPIVersion {
			String^ get() {
				CncGetAPIVersion(Temp_APIVersion->ValuePointertype);
				return StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_APIVersion->ValuePointertype);
			}
	
		}
		static property String^ GetServerVersion {
			String^ get() {
				CncGetServerVersion(Temp_ServerVersion->ValuePointertype);
				return StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_ServerVersion->ValuePointertype);
			}



		}
		static property String^ GetHeaderVersion
		{
			String^ get()
			{
				CncGetHeaderVersion(Temp_HeaderVersion->ValuePointertype);
				return StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_HeaderVersion->ValuePointertype);
			}

		}
		static Cnc_Rc CheckVersionMatch()
		{//CNC_RC_ERR_VERSION_MISMATCH
			Cnc_Rc Return = (Cnc_Rc)CncCheckVersionMatch();
			
			if (GetHeaderVersion->ToUpper() != GetNetWrapperAPIVersion->ToUpper())
			{
				Return = Cnc_Rc::CNC_RC_ERR_VERSION_MISMATCH;
			}

			return Return;
		}
	};
	public ref class G_GetCncServer
	{
	private:
		static Process^ KillCNC_EXE = nullptr;
	public:
		static Cnc_Rc ConnectServer(String^ INI_FILENAME) 
		{
			
			_LastCNC_RC = (Cnc_Rc)CncConnectServer(StringConversie::SYSTEM_STRIN_toCharpoint(INI_FILENAME));
			if (_LastCNC_RC != Cnc_Rc::CNC_RC_ALREADY_CONNECTED && _LastCNC_RC != Cnc_Rc::CNC_RC_ALREADY_RUNS)
			{
				AppIsPlugin = false;
			}
			return _LastCNC_RC;

		}
		static Cnc_Rc DisConnectServer() {
			_LastCNC_RC = (Cnc_Rc)CncDisConnectServer();
			return _LastCNC_RC;
		}
		static bool KillCnc()
		{
			bool Return = false;
			DisConnectServer();
			if (KillCNC_EXE == nullptr)
			{
				KillCNC_EXE = gcnew Process();
				KillCNC_EXE->StartInfo->UseShellExecute = false;
				KillCNC_EXE->StartInfo->FileName = "KillCNC.exe";
				KillCNC_EXE->StartInfo->CreateNoWindow = true;
			}

			if (AppIsPlugin != true)
			{
				try
				{
					KillCNC_EXE->Start();
					Return = true;
				}
				catch (Exception^ e)
				{
					System::Diagnostics::Debug::WriteLine(e);
				}
			}
			else
			{
				PluginError();
			}


			return Return;
		}

		static property Cnc_Rc LastKnownState
		{
			Cnc_Rc get()
			{
				return _LastCNC_RC;
			}

		}
		static property bool IsPlugin
		{
			bool get()
			{
				return AppIsPlugin;
			}
			void set(bool Value)
			{
				AppIsPlugin = Value;
			}
		}
	};
	public ref class G_GetConfigItems
	{
	private:
		static Managedstruct<char>^ Temp_MacroFileName = gcnew Managedstruct<char>(nullptr, CNC_MAX_PATH);
		static Managedstruct<char>^ Temp_UserMacroFileName = gcnew Managedstruct<char>(nullptr, CNC_MAX_PATH);
		//char* Temp_Filename = new char[CNC_MAX_PATH];
		static CncSystemConfig^ Temp_CncSystemConfig;
		static CncInterprererConfig^ Temp_CncInterprererConfig;
		static CncSafetyConfig^ Return_CncSafetyConfig;
		static CncTrafficLightCfg^ Temp_CncTrafficLightCfg;
		static CncProbingCfg^ Temp_CncProbingCfg;
		static CncIoConfig^ Temp_CncIoConfig;
		static CncI2cgpioCardConfig^ Temp_CncI2cgpioCardConfig;
		//....
		static CncFeedSpeedCfg^ Temp_CncFeedSpeedCfg;
		static CncHandWheelCfg^ Temp_CncHandWheelCfg;
		static CncTrajectoryCfg^ Temp_CncTrajectoryCfg;
		static CncKinCfg^ Temp_CncKinCfg;
		static CncUiCfg^ Temp_CncUiCfg;
		static CncCameraConfig^ Temp_CncCameraConfig;
		static CncThcCfg^ Temp_CncThcCfg;
		static CncServiceCfg^ Temp_CncServiceCfg;
		static Cnc3DPrintingConfig^ Temp_Get3DPrintConfig;
		static CncUioConfig^ Temp_CncUioConfig;
		static CncVacuumBedConfig^Temp_CncVacuumBedConfig;
		static array<CncSpindleConfig^>^ Temp_GetSpindleConfig;
		static array<CncJointCfg^>^Temp_GetJointConfig;
		//array<CncIoPortSts^>^Temp_GetIOStatus;
	public:
		static property int MaxPassWordLength
		{
			int get()
			{
				return sizeof(CNC_UI_CFG::setupPassword);
			}
		}
		static property String^ SetupPassword {
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetSetupPassword());
			}
			void set(String^ Value)
			{
				int Temp_MaxSize = MaxPassWordLength;
				if (Value->Length < Temp_MaxSize)
				{
					char * CurrentPass = CncGetSetupPassword();
					StringConversie::SYSTEM_STRING_toMaxCharLength(Temp_MaxSize,Value,CurrentPass);
					_LastCNC_RC = (Cnc_Rc)CncSetSetupPassword(CurrentPass);
				}
				else
				{
					System::Diagnostics::Debug::WriteLine("Password not set: To many chars. Max:"+Temp_MaxSize);
				}
				
			}
		}
		
		static Cnc_Rc StoreIniFile(bool SAVE_FIXTURES)
		{
			_LastCNC_RC = (Cnc_Rc)CncStoreIniFile(Convert::ToInt32(SAVE_FIXTURES));
			CncReInitialize();
			return _LastCNC_RC;
		}
		static Cnc_Rc ReInitialize()
		{
			_LastCNC_RC = (Cnc_Rc)CncReInitialize();
			return _LastCNC_RC;
		}
		static property String^ MacroFileName {
			String^ get()
			{
				_LastCNC_RC = (Cnc_Rc)CncGetMacroFileName(Temp_MacroFileName->ValuePointertype);
				return StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_MacroFileName->ValuePointertype);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(Temp_MacroFileName->ArrayLength,Value, Temp_MacroFileName->ValuePointertype);
				_LastCNC_RC = (Cnc_Rc)CncSetMacroFileName(Temp_MacroFileName->ValuePointertype);
			}
		}
		static property String^ UserMacroFileName
		{
			String^ get()
			{
				_LastCNC_RC = (Cnc_Rc)CncGetUserMacroFileName(Temp_UserMacroFileName->ValuePointertype);
				return StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_UserMacroFileName->ValuePointertype);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(Temp_UserMacroFileName->ArrayLength, Value, Temp_UserMacroFileName->ValuePointertype);
				_LastCNC_RC = (Cnc_Rc)CncSetUserMacroFileName(Temp_UserMacroFileName->ValuePointertype);
				
			}
		}
		static CncSystemConfig^ GetSystemConfig()
		{
			if (Temp_CncSystemConfig == nullptr)
			{
				Temp_CncSystemConfig = gcnew CncSystemConfig(CncGetSystemConfig());
				 
			}
			else
			{
				Temp_CncSystemConfig->ValuePointertype = CncGetSystemConfig();//update only pointer optional
			}
			return Temp_CncSystemConfig;
		}
		static CncInterprererConfig^ GetInterpreterConfig()
		{
			if (Temp_CncInterprererConfig == nullptr)
			{
				Temp_CncInterprererConfig = gcnew CncInterprererConfig(CncGetInterpreterConfig());
			}
			else
			{
				Temp_CncInterprererConfig->ValuePointertype = CncGetInterpreterConfig();
			}
			return Temp_CncInterprererConfig;
		}
		static CncSafetyConfig^ GetSafetyConfig()
		{
			if (Return_CncSafetyConfig == nullptr)
			{
				Return_CncSafetyConfig = gcnew CncSafetyConfig(CncGetSafetyConfig());
			}
			else
			{
				Return_CncSafetyConfig->ValuePointertype = CncGetSafetyConfig();
			}
			return Return_CncSafetyConfig;
		}
		static CncTrafficLightCfg^ GetTrafficLightConfig()
		{
			if (Temp_CncTrafficLightCfg == nullptr)
			{
				Temp_CncTrafficLightCfg = gcnew CncTrafficLightCfg(CncGetTrafficLightConfig());
			}
			else
			{
				Temp_CncTrafficLightCfg->ValuePointertype = CncGetTrafficLightConfig();
			}
			return Temp_CncTrafficLightCfg;
		}
		static CncProbingCfg^ GetProbingConfig()
		{
			if (Temp_CncProbingCfg == nullptr)
			{
				Temp_CncProbingCfg = gcnew CncProbingCfg(CncGetProbingConfig());
			}
			else
			{
				Temp_CncProbingCfg->ValuePointertype = CncGetProbingConfig();
			}
			return Temp_CncProbingCfg;
		}
		static CncIoConfig^ GetIOConfig()
		{
			if (Temp_CncIoConfig== nullptr)
			{
				Temp_CncIoConfig = gcnew CncIoConfig(CncGetIOConfig());
			}
			else
			{
				Temp_CncIoConfig->ValuePointertype = CncGetIOConfig();
			}
			return Temp_CncIoConfig;
		}
		static CncI2cgpioCardConfig^ GetGPIOConfig()
		{
			if (Temp_CncI2cgpioCardConfig == nullptr)
			{
				Temp_CncI2cgpioCardConfig = gcnew CncI2cgpioCardConfig(CncGetGPIOConfig());
			}
			else
			{
				Temp_CncI2cgpioCardConfig->ValuePointertype = CncGetGPIOConfig();
			}
			return Temp_CncI2cgpioCardConfig;
		}
		static void GetIOStatus(CncIoId ioID, CncIoPortSts^IoPortSts)
		{
			IoPortSts->DeletePointer(false);
			IoPortSts->SetPointer(CncGetIOStatus((CNC_IO_ID)ioID),1);
		}
		static void GetGPIOStatus(int cardNr, CncGpioId ioID, CncGpioPortSts^GpioPortSts)
		{
			GpioPortSts->DeletePointer(false);
			GpioPortSts->SetPointer(CncGetGPIOStatus(cardNr, (CNC_GPIO_ID)ioID),1);
		}
		static CncJointCfg^ GetJointConfig(int joint)
		{
			CncJointCfg^ Temp_CncJointCfg = nullptr;
			if (Temp_GetJointConfig == nullptr)
			{
				Temp_GetJointConfig = gcnew array<CncJointCfg^>(CNC_MAX_JOINTS);
			}

			if (joint >=0 && joint < Temp_GetJointConfig->Length)
			{
				if (Temp_GetJointConfig[joint] == nullptr)
				{
					Temp_GetJointConfig[joint] = gcnew CncJointCfg(CncGetJointConfig(joint));
				}
				else
				{
					Temp_GetJointConfig[joint]->ValuePointertype = CncGetJointConfig(joint);
				}
				Temp_CncJointCfg = Temp_GetJointConfig[joint];
			}
			return Temp_CncJointCfg;
		}
		static array<CncJointCfg^>^ GetAllJointConfig()
		{
			if (Temp_GetJointConfig == nullptr)
			{
				Temp_GetJointConfig = gcnew array<CncJointCfg^>(CNC_MAX_JOINTS);
			}

			for (int i =0;i< Temp_GetJointConfig->Length;i++)
			{
				if (Temp_GetJointConfig[i] == nullptr)
				{
					Temp_GetJointConfig[i] = gcnew CncJointCfg(CncGetJointConfig(i));
				}
				else
				{
					Temp_GetJointConfig[i]->ValuePointertype = CncGetJointConfig(i);
				}
			}
			return Temp_GetJointConfig;
		}

		static CncSpindleConfig^ GetSpindleConfig(int spindle)
		{
			CncSpindleConfig^ Temp_CncSpindleConfig = nullptr;// gcnew CncSpindleConfig(CncGetSpindleConfig(spindle), spindle, false);
			if (Temp_GetSpindleConfig == nullptr)
			{
				Temp_GetSpindleConfig = gcnew array<CncSpindleConfig^>(CNC_MAX_SPINDLES);
			}

			if (spindle >= 0 && spindle <Temp_GetSpindleConfig->Length)
			{
				if (Temp_GetSpindleConfig[spindle] == nullptr)
				{
					Temp_GetSpindleConfig[spindle] = gcnew CncSpindleConfig(CncGetSpindleConfig(spindle));
				}
				else
				{
					Temp_GetSpindleConfig[spindle]->ValuePointertype = CncGetSpindleConfig(spindle);
				}
				Temp_CncSpindleConfig =Temp_GetSpindleConfig[spindle];
			}		
			return Temp_CncSpindleConfig;
		}
		static array<CncSpindleConfig^>^ GetAllSpindleConfig()
		{
			if (Temp_GetSpindleConfig == nullptr)
			{
				Temp_GetSpindleConfig = gcnew array<CncSpindleConfig^>(CNC_MAX_SPINDLES);
			}
			for (int i =0;i< Temp_GetSpindleConfig->Length;i++)
			{
				if (Temp_GetSpindleConfig[i] == nullptr)
				{
					Temp_GetSpindleConfig[i] = gcnew CncSpindleConfig(CncGetSpindleConfig(i));
				}
				else
				{
					Temp_GetSpindleConfig[i]->ValuePointertype = CncGetSpindleConfig(i);
				}
			}
			return Temp_GetSpindleConfig;
		}

		static CncFeedSpeedCfg^ GetFeedSpeedConfig()
		{
			if (Temp_CncFeedSpeedCfg == nullptr)
			{
				Temp_CncFeedSpeedCfg = gcnew CncFeedSpeedCfg(CncGetFeedSpeedConfig());
			}
			else
			{
				Temp_CncFeedSpeedCfg->ValuePointertype = CncGetFeedSpeedConfig();
			}
			return Temp_CncFeedSpeedCfg;
		}
		static CncHandWheelCfg^ GetHandwheelConfig()
		{
			if (Temp_CncHandWheelCfg == nullptr)
			{
				Temp_CncHandWheelCfg = gcnew CncHandWheelCfg(CncGetHandwheelConfig());
			}
			else
			{
				Temp_CncHandWheelCfg->ValuePointertype = CncGetHandwheelConfig();
			}
			return Temp_CncHandWheelCfg;
		}
		static CncTrajectoryCfg^ GetTrajectoryConfig()
		{
			if (Temp_CncTrajectoryCfg == nullptr)
			{
				Temp_CncTrajectoryCfg = gcnew CncTrajectoryCfg(CncGetTrajectoryConfig());
			}
			else
			{
				Temp_CncTrajectoryCfg->ValuePointertype = CncGetTrajectoryConfig();
			}
			return Temp_CncTrajectoryCfg;
		}
		static CncKinCfg^ GetKinConfig()
		{
			if (Temp_CncKinCfg == nullptr)
			{
				Temp_CncKinCfg = gcnew CncKinCfg(CncGetKinConfig());
			}
			else
			{
				Temp_CncKinCfg->ValuePointertype = CncGetKinConfig();
			}
			return Temp_CncKinCfg;
		}	
		static CncUiCfg^ GetUIConfig()
		{
			if (Temp_CncUiCfg == nullptr)
			{
				Temp_CncUiCfg = gcnew CncUiCfg(CncGetUIConfig());
			}
			else
			{
				Temp_CncUiCfg->ValuePointertype = CncGetUIConfig();
			}
			return Temp_CncUiCfg;
		}
		static CncCameraConfig^ GetCameraConfig()
		{
			if (Temp_CncCameraConfig == nullptr)
			{
				Temp_CncCameraConfig = gcnew CncCameraConfig(CncGetCameraConfig());
			}
			else
			{
				Temp_CncCameraConfig->ValuePointertype = CncGetCameraConfig();
			}
			return Temp_CncCameraConfig;
		}
		static CncThcCfg^ GetTHCConfig()
		{
			if (Temp_CncThcCfg == nullptr)
			{
				Temp_CncThcCfg = gcnew CncThcCfg(CncGetTHCConfig());
			}
			else
			{
				Temp_CncThcCfg->ValuePointertype = CncGetTHCConfig();
			}
			return Temp_CncThcCfg;
		}
		static CncServiceCfg^ GetServiceConfig()
		{
			if (Temp_CncServiceCfg == nullptr)
			{
				Temp_CncServiceCfg = gcnew CncServiceCfg(CncGetServiceConfig());
			}
			else
			{
				Temp_CncServiceCfg->ValuePointertype = CncGetServiceConfig();
			}
			return  Temp_CncServiceCfg;
		}
		static Cnc3DPrintingConfig^ Get3DPrintConfig()
		{
			if (Temp_Get3DPrintConfig == nullptr)
			{
				Temp_Get3DPrintConfig = gcnew Cnc3DPrintingConfig(CncGet3DPrintConfig());
			}
			else
			{
				Temp_Get3DPrintConfig->ValuePointertype = CncGet3DPrintConfig();
			}
			return Temp_Get3DPrintConfig;
		}
		static CncUioConfig^ GetUIOConfig()
		{
			if (Temp_CncUioConfig == nullptr)
			{
				Temp_CncUioConfig = gcnew CncUioConfig(CncGetUIOConfig());
			}
			else
			{
				Temp_CncUioConfig->ValuePointertype = CncGetUIOConfig();
			}
			return Temp_CncUioConfig;
		}
		static CncVacuumBedConfig^ GetVacuumConfig()
		{
			if (Temp_CncVacuumBedConfig == nullptr)
			{
				Temp_CncVacuumBedConfig = gcnew CncVacuumBedConfig(CncGetVacuumConfig());
			}
			else
			{
				Temp_CncVacuumBedConfig->ValuePointertype = CncGetVacuumConfig();
			}
			return Temp_CncVacuumBedConfig;
			
		}
	};
	public ref class G_GetConfigControllerCpu
	{
	private:
		static array<CncJointSts^>^ Temp_JointStatus = gcnew array<CncJointSts^>(CNC_MAX_JOINTS);
	public:
		static property String^ GetControllerFirmwareVersion
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetControllerFirmwareVersion());
			}
			
		}
		static property String^ GetControllerSerialNumber
		{	
			String^ get()
			{
				String^ Return = "";
				unsigned char Serial[6];
				_LastCNC_RC = (Cnc_Rc)CncGetControllerSerialNumber(Serial);
				for (int i = 0; i < 6; i++)
				{
					Return = Return + Serial[i];
				}
				return Return;
			}
			
		}
		static property int GetControllerNumberOfFrequencyItems
		{	
			int get()
			{
				return CncGetControllerNumberOfFrequencyItems();
			}
		}
		static double GetControllerFrequencyItem(int index)
		{
			return CncGetControllerFrequencyItem(index);
		}
		static property int GetControllerConnectionNumberOfItems
		{
			int get()
			{
				return CncGetControllerConnectionNumberOfItems();
			}
		}
		static String^  GetControllerConnectionItem(int itemNumber)
		{
			return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetControllerConnectionItem(itemNumber));
		}
		static void GetNrOfAxesOnController(int% maxNrOfAxes, int% availableNrOfAxes)
		{
			int Temp_maxNrOfAxes = -1;
			int Temp_availableNrOfAxes = -1;
			CncGetNrOfAxesOnController(&Temp_maxNrOfAxes, &Temp_availableNrOfAxes);
			maxNrOfAxes = Temp_maxNrOfAxes;
			availableNrOfAxes = Temp_availableNrOfAxes;
			
		}
		static bool GetAxisIsConfigured(int axis, bool includingSlaves)
		{
			bool Return = false;
			int Configured = CncGetAxisIsConfigured(axis, includingSlaves);
			if (Configured == 1)
			{
				Return = true;
			}
			return Return;
		}
		static property bool GetFirmwareHasOptions
		{
			bool get()
			{
				return CncGetFirmwareHasOptions();
			}
		}
		static Cnc_Rc GetActiveOptions(String^ %actCustomerName, int% actNumberOfAxes, int% actCPUEnabled, int% actGPIOAVXEnabled, int% actGPIOEDIEnabled, int% actPLASMAEnabled, int% actTURNMACRO, int% actXHCPendant, int% actReserved1Enabled)//snap ik niet<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		{
			char* Temp_actCustomerName =  new char[CNC_MAX_CUSTOMER_NAME];
			int Temp_actNumberOfAxes =  -1;
			unsigned int Temp_actCPUEnabled = -1;
			unsigned int Temp_actGPIOAVXEnabled = -1;
			unsigned int Temp_actGPIOEDIEnabled = -1;
			unsigned int Temp_actPLASMAEnabled = -1;
			unsigned int Temp_actTURNMACRO = -1;
			unsigned int Temp_actXHCPendant = -1;
			unsigned int Temp_actReserved1Enabled = -1;
			_LastCNC_RC = (Cnc_Rc)CncGetActiveOptions(Temp_actCustomerName, &Temp_actNumberOfAxes, &Temp_actCPUEnabled, &Temp_actGPIOAVXEnabled, &Temp_actGPIOEDIEnabled, &Temp_actPLASMAEnabled, &Temp_actTURNMACRO, &Temp_actXHCPendant, &Temp_actReserved1Enabled);


			actCustomerName = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_actCustomerName);
			delete[] Temp_actCustomerName;
			actNumberOfAxes = Temp_actNumberOfAxes;
			actCPUEnabled = Temp_actCPUEnabled;
			actGPIOAVXEnabled = Temp_actGPIOAVXEnabled;
			actGPIOEDIEnabled = Temp_actGPIOEDIEnabled;
			actPLASMAEnabled = Temp_actPLASMAEnabled;
			actTURNMACRO = Temp_actTURNMACRO;
			actXHCPendant = Temp_actXHCPendant;
			actReserved1Enabled = Temp_actReserved1Enabled;
			

			return _LastCNC_RC;
		}
		static Cnc_Rc GetOptionRequestCode(String^ newCustomerName, int newNumberOfAxes, int newGPIOAVXEnabled, int newGPIOEDIEnabled, int newPLASMAEnabled, int newTURMACROEnabled, int	newXHCPendant, int newReserved1Enabled, String^% requestCode)
		{
			char* Temp_requestCode = new char[RequestCodebytes];
			char* Temp_newCustomerName = StringConversie::SYSTEM_STRIN_toCharpoint(newCustomerName);
			int Temp_newNumberOfAxes = newNumberOfAxes;
			unsigned int	Temp_newGPIOAVXEnabled = newGPIOAVXEnabled;
			unsigned int	Temp_newGPIOEDIEnabled = newGPIOEDIEnabled;
			unsigned int	Temp_newPLASMAEnabled = newPLASMAEnabled;
			unsigned int	Temp_newTURMACROEnabled = newTURMACROEnabled;
			unsigned int	Temp_newXHCPendant = newXHCPendant;
			unsigned int	Temp_newReserved1Enabled = newReserved1Enabled;
			_LastCNC_RC = (Cnc_Rc)CncGetOptionRequestCode(Temp_newCustomerName, Temp_newNumberOfAxes, Temp_newGPIOAVXEnabled, Temp_newGPIOEDIEnabled, Temp_newPLASMAEnabled, Temp_newTURMACROEnabled, Temp_newXHCPendant, Temp_newReserved1Enabled, Temp_requestCode);
			requestCode = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_requestCode);
			delete[] Temp_requestCode;
			delete[]Temp_newCustomerName;

			return _LastCNC_RC;
		}
		static property String^ GetOptionRequestCodeCurrent
		{
			String^ get()
			{
				char* Temp_requestCode = new char[RequestCodebytes];
				_LastCNC_RC = (Cnc_Rc)CncGetOptionRequestCodeCurrent(Temp_requestCode);
				String^ requestCode = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_requestCode);
				delete[] Temp_requestCode;
				return requestCode;
			}
		}
		static Cnc_Rc ActivateOption(String^ activationKey)
		{
			_LastCNC_RC = (Cnc_Rc)CncActivateOption(StringConversie::SYSTEM_STRIN_toCharpoint(activationKey));
			
			return _LastCNC_RC;
		}
		static CncJointSts^ GetJointStatus(int joint)
		{
			CncJointSts ^ Temp_JointSts;
			
			if (joint >= 0 && joint < Temp_JointStatus->Length)
			{
				if (Temp_JointStatus[joint] == nullptr)
				{
					Temp_JointStatus[joint] = gcnew CncJointSts(CncGetJointStatus(joint));
				}
				else
				{
					Temp_JointStatus[joint]->ValuePointertype = CncGetJointStatus(joint);
				}
				Temp_JointSts = Temp_JointStatus[joint];
			}
			//CncJointSts ^ Temp_JointSts = gcnew CncJointSts(CncGetJointStatus(joint));
			return Temp_JointSts;
		}
		static array<CncJointSts^>^ GetAllJointStatus()
		{
			for (int i =0;i< Temp_JointStatus->Length;i++)
			{
				if (Temp_JointStatus[i] == nullptr)
				{
					Temp_JointStatus[i] = gcnew CncJointSts(CncGetJointStatus(i));
				}
				else
				{
					Temp_JointStatus[i]->ValuePointertype = CncGetJointStatus(i);
				}
			}
			return Temp_JointStatus;
		}
	};
	public ref class G_GetSetToolTableData
	{
	private:
		static array<CncToolData^>^ Temp_GetToolData = gcnew array<CncToolData^>(CNC_MAX_TOOLS + 1);
	public:
		static array<CncToolData^>^ GetAllTooldata()
		{
			

			for(int i =0;i< Temp_GetToolData->Length;i++)
			{ 
				GetToolData(i);
			}
			return Temp_GetToolData;
		}

		static CncToolData^ GetToolData(int index)
		{

			CncToolData^ Return = nullptr;

			
			if (index >= 0 && index <= CNC_MAX_TOOLS)
			{
				if (Temp_GetToolData[index] == nullptr)
				{
					Temp_GetToolData[index] = gcnew CncToolData();
					Temp_GetToolData[index]->ValuePointertype[0] = CncGetToolData(index);
				}
				else
				{
					Temp_GetToolData[index]->ValuePointertype[0] = CncGetToolData(index);
				}
				
				Return = Temp_GetToolData[index];
			}
			return Return;
		}
		static bool UpdateToolData(CncToolData^ ToolData, int id)
		{
			bool Return = false;
			if (id >= 0 && id <= CNC_MAX_TOOLS)
			{
				_LastCNC_RC = (Cnc_Rc)CncUpdateToolData(ToolData->ValuePointertype, id);
				Return = true;
			}
			else
			{
				Console::WriteLine("ERROR: Tool index out of range.");
			}
			return Return;
		}
		static Cnc_Rc  LoadToolTable()
		{
			_LastCNC_RC = (Cnc_Rc)CncLoadToolTable();
			return _LastCNC_RC;
		}

	};
	public ref class G_VariableAccess
	{
	public:
		static double GetVariable(int varIndex)
		{
			return CncGetVariable(varIndex);
		}
		static void SetVariable(int varIndex, double value)
		{
			CncSetVariable(varIndex, value);
		}

	};
	public ref class G_StatusItems
	{
	private:
		static CncRunningStatus^ Temp_CncRunningStatus;
		static CncMotionStatus^ Temp_CncMotionStatus;
		static CncControllerStatus^ Temp_CncControllerStatus;
		static CncControllerConfigStatus^ Temp_CncControllerConfigStatus;
		static CncTraffigLightStatus^ Temp_GetTrafficLightStatus;
		static CncJobStatus^ Temp_GetJobStatus;
		static CncTrackingStatus^ Temp_CncTrackingStatus;
		static CncThcStatus^ Temp_CncThcStatus;
		static CncNestingStatus^ Temp_CncNestingStatus;
		static CncKinStatus^ Temp_CncKinStatus;
		static CncSpindleSts^ Temp_CncSpindleSts;
		static CncPauseSts^ Temp_CncPauseSts;
		static CncSearchStatus^ Temp_CncSearchStatus;
		static Cnc3dPrintingSts^ Temp_Cnc3dPrintingSts;
		static CncCompensationStatus^ Temp_CncCompensationStatus;
		static CncVacuumStatus^ Temp_CncVacuumStatus;
	public:
		static CncRunningStatus^ GetRunningStatus()
		{
			if (Temp_CncRunningStatus == nullptr)
			{
				Temp_CncRunningStatus = gcnew CncRunningStatus(CncGetRunningStatus());
			}
			else
			{
				Temp_CncRunningStatus->ValuePointertype = CncGetRunningStatus();
			}
			return Temp_CncRunningStatus;
		}
		static CncMotionStatus^ GetMotionStatus()
		{	
			if (Temp_CncMotionStatus == nullptr)
			{
				Temp_CncMotionStatus = gcnew CncMotionStatus(CncGetMotionStatus());
			}
			else
			{
				Temp_CncMotionStatus->ValuePointertype = CncGetMotionStatus();
			}
			return Temp_CncMotionStatus;
		}
		static CncControllerStatus^ GetControllerStatus()
		{
			if (Temp_CncControllerStatus == nullptr)
			{
			   Temp_CncControllerStatus = gcnew CncControllerStatus(CncGetControllerStatus());
			}
			else
			{
				Temp_CncControllerStatus->ValuePointertype = CncGetControllerStatus();
			}
			return Temp_CncControllerStatus;
		}
		static CncControllerConfigStatus^ GetControllerConfigStatus()
		{
			if (Temp_CncControllerConfigStatus == nullptr)
			{
				Temp_CncControllerConfigStatus = gcnew CncControllerConfigStatus(CncGetControllerConfigStatus());
			}
			else
			{
				Temp_CncControllerConfigStatus->ValuePointertype = CncGetControllerConfigStatus();
			}
			return Temp_CncControllerConfigStatus;
		}
		static CncTraffigLightStatus^ GetTrafficLightStatus()
		{
			if (Temp_GetTrafficLightStatus == nullptr)
			{
				Temp_GetTrafficLightStatus = gcnew CncTraffigLightStatus(CncGetTrafficLightStatus());
			}
			else
			{
				Temp_GetTrafficLightStatus->ValuePointertype = CncGetTrafficLightStatus();
			}
			return Temp_GetTrafficLightStatus;
		}
		static CncJobStatus^ GetJobStatus()
		{
			if (Temp_GetJobStatus == nullptr)
			{
				Temp_GetJobStatus = gcnew CncJobStatus(CncGetJobStatus());
			}
			else
			{
				Temp_GetJobStatus->ValuePointertype = CncGetJobStatus();
			}
			return Temp_GetJobStatus;
		}
		static CncTrackingStatus^ GetTrackingStatus()
		{
			if (Temp_CncTrackingStatus == nullptr)
			{
				Temp_CncTrackingStatus = gcnew CncTrackingStatus(CncGetTrackingStatus());
			}
			else
			{
				Temp_CncTrackingStatus->ValuePointertype = CncGetTrackingStatus();
			}
			return Temp_CncTrackingStatus;
		}
		static CncThcStatus^ GetTHCStatus()
		{
			if (Temp_CncThcStatus == nullptr)
			{
				Temp_CncThcStatus = gcnew CncThcStatus(CncGetTHCStatus());
			}
			else
			{
				Temp_CncThcStatus->ValuePointertype = CncGetTHCStatus();
			}
			return Temp_CncThcStatus;
		}
		static CncNestingStatus^ GetNestingStatus()
		{
			if (Temp_CncNestingStatus == nullptr)
			{
				Temp_CncNestingStatus = gcnew CncNestingStatus(CncGetNestingStatus());
			}
			else
			{
				Temp_CncNestingStatus->ValuePointertype = CncGetNestingStatus();
			}
			return Temp_CncNestingStatus;
		}
		static CncKinStatus^ GetKinStatus()//check
		{
			if (Temp_CncKinStatus == nullptr)
			{
				Temp_CncKinStatus = gcnew CncKinStatus(CncGetKinStatus());
			}
			else
			{
				Temp_CncKinStatus->ValuePointertype = CncGetKinStatus();
			}
			return  Temp_CncKinStatus;
		}
		static CncSpindleSts^ GetSpindleStatus()
		{
			if (Temp_CncSpindleSts == nullptr)
			{
				Temp_CncSpindleSts = gcnew CncSpindleSts(CncGetSpindleStatus());
			}
			else
			{
				Temp_CncSpindleSts->ValuePointertype = CncGetSpindleStatus();
			}
			return  Temp_CncSpindleSts;
		}
		static CncPauseSts^ GetPauseStatus()
		{
			if (Temp_CncPauseSts == nullptr)
			{
				
				Temp_CncPauseSts = gcnew CncPauseSts(CncGetPauseStatus());
			}
			else
			{
				Temp_CncPauseSts->ValuePointertype = CncGetPauseStatus();
			}
			return Temp_CncPauseSts;
		}
		static CncSearchStatus^ GetSearchStatus()
		{
			if (Temp_CncSearchStatus == nullptr)
			{
				Temp_CncSearchStatus = gcnew CncSearchStatus(CncGetSearchStatus());
			}
			else
			{
				Temp_CncSearchStatus->ValuePointertype = CncGetSearchStatus();
			}
			return Temp_CncSearchStatus;
		}
		static Cnc3dPrintingSts^ Get3DPrintStatus()
		{
			if (Temp_Cnc3dPrintingSts == nullptr)
			{
				Temp_Cnc3dPrintingSts = gcnew Cnc3dPrintingSts(CncGet3DPrintStatus());
			}
			else
			{
				Temp_Cnc3dPrintingSts->ValuePointertype = CncGet3DPrintStatus();
			}
			return Temp_Cnc3dPrintingSts;
		}
		static CncCompensationStatus^  GetCompensationStatus()
		{
			if (Temp_CncCompensationStatus == nullptr)
			{
				Temp_CncCompensationStatus = gcnew CncCompensationStatus(CncGetCompensationStatus());
			}
			else
			{
				Temp_CncCompensationStatus->ValuePointertype = CncGetCompensationStatus();
			}
			return Temp_CncCompensationStatus;
		}
		static CncVacuumStatus^ GetVacuumStatus()
		{
			if (Temp_CncVacuumStatus == nullptr)
			{
				Temp_CncVacuumStatus = gcnew CncVacuumStatus(CncGetVacuumStatus());
			}
			else
			{
				Temp_CncVacuumStatus->ValuePointertype = CncGetVacuumStatus();
			}
			return Temp_CncVacuumStatus;
		}
		static int Get10msHeartBeat()
		{
			return CncGet10msHeartBeat();
		}
		static int IsServerConnected()
		{
			return CncIsServerConnected();
		}

	};
	public ref class G_StatusItemsposition
	{
	private:
		static CncCartDouble^ WorkPosition=gcnew CncCartDouble();
		static CncJointDouble^ MotorPosition = gcnew CncJointDouble();
		static CncCartDouble^ MachinePosition = gcnew CncCartDouble();
		static CncCartDouble^ ActualOriginOffset = gcnew CncCartDouble();
		//static Managedstruct<int>^ Temp_rotationActive = gcnew Managedstruct<int>(nullptr,1);
		static CncCartDouble^ Temp_MachineZeroWorkPoint = gcnew CncCartDouble();
	public:	
		static CncIeState GetState()
		{
			return (CncIeState)CncGetState();
		}
		static String^ GetStateText(CncIeState state)
		{
			return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetStateText((CNC_IE_STATE)state));
		}
		static int InMillimeterMode()
		{
			return CncInMillimeterMode();
		}
		static CncPlane GetActualPlane()
		{
			return (CncPlane)CncGetActualPlane();
		}
		static CncCartDouble^ GetWorkPosition()
		{
			

			WorkPosition->ValuePointertype[0] = CncGetWorkPosition();
			return WorkPosition;
		}
		static CncJointDouble^ GetMotorPosition()
		{
			
			MotorPosition->ValuePointertype[0] = CncGetMotorPosition();
			return MotorPosition;
			
		}
		static CncCartDouble^ GetMachinePosition()
		{	
			
			MachinePosition->ValuePointertype[0] = CncGetMachinePosition();
			return MachinePosition;
		}
		static CncCartDouble^ GetMachineZeroWorkPoint(int % rotationActive)
		{
			int Temp_rotationActive = -1;

			CncGetMachineZeroWorkPoint(Temp_MachineZeroWorkPoint->ValuePointertype, &Temp_rotationActive);
			rotationActive = Temp_rotationActive;
			return Temp_MachineZeroWorkPoint;
		}
		static CncCartDouble^ GetActualOriginOffset()
		{	
		
			ActualOriginOffset->ValuePointertype[0] = CncGetActualOriginOffset();
			return ActualOriginOffset;
		}
		static double GetActualToolZOffset()
		{
			return CncGetActualToolZOffset();
		}
		static double GetActualToolXOffset()
		{
			return CncGetActualToolXOffset();
		}
		static double GetActualG68Rotation()
		{
			return CncGetActualG68Rotation();
		}
		static CncPlane GetActualG68RotationPlane()
		{
			return (CncPlane)CncGetActualG68RotationPlane();
		}
	};
	public ref class G_StatusItemsInterpreter
	{
	private:
		static Managedstruct<char>^ Temp_GetCurrentGcodesText = gcnew Managedstruct<char>(nullptr, CharCharacterBuffer);
		static Managedstruct<char>^ Temp_GetCurrentMcodesText = gcnew Managedstruct<char>(nullptr, CharCharacterBuffer);
		static Managedstruct<char>^ Temp_GetCurrentGcodeSettingsText = gcnew Managedstruct<char>(nullptr, CharCharacterBuffer);
	public:
		static String^  GetCurrentGcodesText()
		{
			String^ Return = "";
			CncGetCurrentGcodesText(Temp_GetCurrentGcodesText->ValuePointertype);
			Return = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_GetCurrentGcodesText->ValuePointertype);
			return Return;
		}
		static String^ GetCurrentMcodesText()
		{
			String ^ Return = "";
			CncGetCurrentMcodesText(Temp_GetCurrentMcodesText->ValuePointertype);
			Return = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_GetCurrentMcodesText->ValuePointertype);
			return Return;
		}
		static String^ GetCurrentGcodeSettingsText()
		{
			String ^ Return = "";
			CncGetCurrentGcodeSettingsText(Temp_GetCurrentGcodeSettingsText->ValuePointertype);
			Return = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_GetCurrentGcodeSettingsText->ValuePointertype);
			return Return;
		}
		static double GetProgrammedSpeed()
		{
			return CncGetProgrammedSpeed();
		}
		static double GetProgrammedFeed()
		{
			return CncGetProgrammedFeed();
		}
		static int GetCurrentToolNumber()
		{
			return CncGetCurrentToolNumber();
		}
		static int G43Active()
		{
			return CncG43Active();
		}
		static int GetCurInterpreterLineNumber()
		{
			return CncGetCurInterpreterLineNumber();
		}
		static int GetCurInterpreterLineText(String^ text)
		{
			return CncGetCurInterpreterLineText(StringConversie::SYSTEM_STRIN_toCharpoint(text));
		}
		static int CurrentInterpreterLineContainsToolChange()
		{
			return CncCurrentInterpreterLineContainsToolChange();
		}
	};
	public ref class G_StatusErrorSafety
	{
	public:
		static int GetSwLimitError()
		{
			return CncGetSwLimitError();
		}
		static int GetFifoError()
		{
			return CncGetFifoError();
		}
		static int GetEMStopActive()
		{
			return CncGetEMStopActive();
		}
		static int GetAllAxesHomed()
		{
			return CncGetAllAxesHomed();
		}
		static int  GetSafetyMode()
		{
			return CncGetSafetyMode();
		}

	};
	public ref class G_Kinematics
	{
	private:
		//array<KinControlData^>^ KinControl_KinControlData;
		//CncVector^ KinGetARotationPoint_CncVector;
		static CncVector^ KinARotationPoint = gcnew CncVector();
	public:
		static CncKineMaticsType KinGetActiveType()
		{
			return (CncKineMaticsType)CncKinGetActiveType();
		}
		static int KinActivate(int active)
		{
			return CncKinActivate(active);
		}
		static int KinInit()
		{
			return  CncKinInit();
		}
		static int KinControl(KinControlId controlID, KinControlData^ KinControlData)
		{	
			int Return = 0;
			if ((int)controlID >= 1 && (int)controlID < (int)KinControlId::KIN_CONTROL_LAST)
			{
				Return = CncKinControl((KIN_CONTROL_ID)controlID, KinControlData->ValuePointertype);
			}
			return Return;
		}
		static CncVector^ KinGetARotationPoint()
		{
			KinARotationPoint->ValuePointertype[0] = CncKinGetARotationPoint();
			return KinARotationPoint;
		}
	};
	public ref class G_StatusItemsIO
	{
	private:
		//static Managedstruct<int>^ Temp_CheckStartConditionOK = gcnew Managedstruct<int>(nullptr,1);
	public:
		static String^ GetIOName(CncIoId id)
		{
			return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetIOName((CNC_IO_ID)id));
		}
		static int GetOutput(CncIoId id)
		{
			return  CncGetOutput((CNC_IO_ID) id);
		}
		static int GetOutputRaw(CncIoId id)
		{
			return  CncGetOutputRaw((CNC_IO_ID) id);
		}
		static int GetGPIOOutput(int gpioCardIndex, CncGpioId ioId)
		{
			return CncGetGPIOOutput(gpioCardIndex, (CNC_GPIO_ID) ioId);
		}
		static int GetInput(CncIoId id)
		{
			return CncGetInput((CNC_IO_ID) id);
		}
		static int GetInputRaw(CncIoId id)
		{
			return CncGetInputRaw((CNC_IO_ID)id);
		}
		static int GetGPIOInput(int gpioCardIndex, CncGpioId ioId)
		{
			return CncGetGPIOInput(gpioCardIndex, (CNC_GPIO_ID) ioId);
		}
		static Cnc_Rc SetOutput(CncIoId id, int value)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetOutput((CNC_IO_ID) id, value);

			return _LastCNC_RC;
		}
		static Cnc_Rc  SetOutputRaw(CncIoId id, int value)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetOutputRaw((CNC_IO_ID) id, value);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetGPIOOutput(int gpioCardIndex, CncGpioId ioId, int value)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetGPIOOutput(gpioCardIndex, (CNC_GPIO_ID) ioId,value);
			return _LastCNC_RC;
		}
		static Cnc_Rc CheckStartConditionOK(int generateMessage, int ignoreHoming, int %result)
		{
			int Temp_result = -1;
			_LastCNC_RC = (Cnc_Rc)CncCheckStartConditionOK(generateMessage,ignoreHoming, &Temp_result);
			result = Temp_result;
			return _LastCNC_RC;
		}
		static Cnc_Rc  SetSpindleOutput(int onOff, int direction, double absSpeed)
		{
			_LastCNC_RC = (Cnc_Rc) CncSetSpindleOutput(onOff,direction, absSpeed);
			return _LastCNC_RC;
		}
	};
	public ref class G_LogMessagesRealtime
	{
	private:
		//static CncLogMessage^ Temp_LastLogMessage = gcnew CncLogMessage();
		//static CncPosFifoData^ Temp_PosFifo = gcnew CncPosFifoData();
		//static Managedstruct<int>^ Temp_IsLast = gcnew Managedstruct<int>(nullptr,1);
		//static CncPosFifoData^ Temp_PosFifo2 = gcnew CncPosFifoData();
		//static CncGraphFifoData^  Temp_GraphFifo = gcnew CncGraphFifoData();
		
	public:
		static Cnc_Rc LogFifoGet(CncLogMessage^ data)
		{
			Cnc_Rc Return = Cnc_Rc::CNC_RC_BUF_EMPTY;

			if (AppIsPlugin == false)
			{
				Return = (Cnc_Rc)CncLogFifoGet(data->ValuePointertype);
				_LastCNC_RC = Return;
			}
			else
			{
				PluginError();
			}

			return Return;
		}
		
		static Cnc_Rc PosFifoGet(CncPosFifoData^ data)
		{
			Cnc_Rc Return = Cnc_Rc::CNC_RC_BUF_EMPTY;

			if (AppIsPlugin == false)
			{
				Return = (Cnc_Rc)CncPosFifoGet(data->ValuePointertype);
				_LastCNC_RC = Return;
			}
			else
			{
				PluginError();
			}
			
			return Return;
		}
		

		static Cnc_Rc PosFifoGet2(CncPosFifoData^ data,int % isLast)
		{ 
			Cnc_Rc Return = Cnc_Rc::CNC_RC_BUF_EMPTY;

			if (AppIsPlugin == false)
			{
				int Temp_isLast = -1;
				Return = (Cnc_Rc)CncPosFifoGet2(data->ValuePointertype, &Temp_isLast);
				_LastCNC_RC = Return;
				isLast = Temp_isLast;
			}
			else
			{
				PluginError();
			}
			return Return;
		}
		
		static Cnc_Rc GraphFifoGet(CncGraphFifoData^ data)
		{	
			Cnc_Rc Return = Cnc_Rc::CNC_RC_BUF_EMPTY;

			if (AppIsPlugin == false)
			{
				Return = (Cnc_Rc)CncGraphFifoGet(data->ValuePointertype);
				_LastCNC_RC = Return;
			}
			else
			{
				PluginError();
			}
			return Return;
		}
		
	};
	public ref class G_CommandsJobInterpreter
	{
	private:
		static CncVector^ JobMaterialSize = gcnew CncVector();
		//static CncCmdArrayData^ Temp_JobArrayParameters = gcnew CncCmdArrayData();

	public:
		
		static Cnc_Rc Reset()
		{
			_LastCNC_RC = (Cnc_Rc)CncReset();
			return _LastCNC_RC;
		}
		static Cnc_Rc Reset2(int resetFlags)
		{
			_LastCNC_RC = (Cnc_Rc)CncReset2(resetFlags);
			return _LastCNC_RC;
		}
		static Cnc_Rc RunSingleLine(String^ text)
		{
			char * Temp_Line = StringConversie::SYSTEM_STRIN_toCharpoint(text);
			_LastCNC_RC = (Cnc_Rc)CncRunSingleLine(Temp_Line);
			delete[] Temp_Line;
			return _LastCNC_RC;
		}
		
		static int WaitSingleLine(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)//CNC_KEEP_UI_ALIVE_FUNCTION
		{
			return  CncWaitSingleLine(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		
		static Cnc_Rc LoadJob(String^fileName)
		{
			const wchar_t * Temp_Job = StringConversie::SYSTEM_STRING_toWchar_tpoint(fileName);
			_LastCNC_RC = (Cnc_Rc)CncLoadJob(Temp_Job);
			delete[] Temp_Job;
			return _LastCNC_RC;
		}
		static Cnc_Rc RunOrResumeJob()
		{
			_LastCNC_RC = (Cnc_Rc)CncRunOrResumeJob();
			return _LastCNC_RC;
		}
		static Cnc_Rc StartRenderGraph(int outLines, int contour)
		{
			_LastCNC_RC = (Cnc_Rc)CncStartRenderGraph(outLines, contour);
			return _LastCNC_RC;
		}
		static Cnc_Rc StartRenderSearch(int outLines, int contour, int lineNr,int ToolNr, int arrayX, int arrayY)
		{
			_LastCNC_RC = (Cnc_Rc)CncStartRenderSearch(outLines, contour, lineNr,ToolNr, arrayX, arrayY);
			return _LastCNC_RC;
		}
		static Cnc_Rc RewindJob()
		{
			_LastCNC_RC = (Cnc_Rc)CncRewindJob();
			return _LastCNC_RC;
		}
		static Cnc_Rc AbortJob()
		{
			_LastCNC_RC = (Cnc_Rc)CncAbortJob();
			return _LastCNC_RC;
		}
		static Cnc_Rc GetJobArrayParameters(CncCmdArrayData^ runJobData)
		{
			Cnc_Rc Return = (Cnc_Rc)CncGetJobArrayParameters(runJobData->ValuePointertype);
			_LastCNC_RC = Return;
			return Return;
		}
		static Cnc_Rc SetJobArrayParameters(CncCmdArrayData^ runJobData)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetJobArrayParameters(runJobData->ValuePointertype);
			return _LastCNC_RC;
		}
		static CncVector^ GetJobMaterialSize()
		{

			JobMaterialSize->ValuePointertype[0] = CncGetJobMaterialSize();
			return JobMaterialSize;
		}
		static Cnc_Rc GetJobFiducual(int n, CncFiducialData^ JobFiducual)
		{
			_LastCNC_RC = (Cnc_Rc)CncGetJobFiducual(n, JobFiducual->ValuePointertype);
			return _LastCNC_RC;
		}
		static Cnc_Rc EnableBlockDelete(int enable)
		{
			_LastCNC_RC =(Cnc_Rc)CncEnableBlockDelete(enable);
			return _LastCNC_RC;
		}
		static int GetBlocDelete()
		{
			return CncGetBlocDelete();
		}
		static Cnc_Rc EnableOptionalStop(int enable)
		{
			_LastCNC_RC = (Cnc_Rc)CncEnableOptionalStop(enable);
			return _LastCNC_RC;
		}
		static int GetOptionalStop()
		{
			return CncGetOptionalStop();
		}
		static Cnc_Rc SingleStepMode(int enable)
		{
			_LastCNC_RC = (Cnc_Rc)CncSingleStepMode(enable);
			return _LastCNC_RC;
		}
		static int GetSingleStepMode()
		{
			return CncGetSingleStepMode();
		}
		static Cnc_Rc SetExtraJobOptions(String^ extraLine, int doRepeat, int numberOfRepeats)
		{
			_LastCNC_RC =(Cnc_Rc)CncSetExtraJobOptions(StringConversie::SYSTEM_STRIN_toCharpoint(extraLine), doRepeat, numberOfRepeats);
			return _LastCNC_RC;
		}
		static void GetExtraJobOptions(String^ % extraLine, int % doRepeat, int % numberOfRepeats)
		{
			char *Temp_extraLine = new char[CharCharacterBuffer];
			int Temp_doRepeat = -1;
			unsigned int Temp_numberOfRepeats = -1;
			CncGetExtraJobOptions(Temp_extraLine, &Temp_doRepeat, &Temp_numberOfRepeats);
			extraLine = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_extraLine);
			doRepeat = Temp_doRepeat;
			numberOfRepeats = Temp_numberOfRepeats;
			delete[] Temp_extraLine;
			
		}
		static Cnc_Rc SetSimulationMode(int enable)
		{
			_LastCNC_RC =(Cnc_Rc)CncSetSimulationMode(enable);
			return _LastCNC_RC;
		}
		static int GetSimulationMode()
		{
			return CncGetSimulationMode();
		}
		static Cnc_Rc SetFeedOverride(double factor)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetFeedOverride(factor);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetArcFeedOverride(double factor)
		{
			_LastCNC_RC =(Cnc_Rc)CncSetArcFeedOverride(factor);
			return _LastCNC_RC;
		}
		static double GetActualFeedOverride()
		{
			return CncGetActualFeedOverride();
		}
		static double GetActualArcFeedOverride()
		{
			return CncGetActualArcFeedOverride();
		}
		static double GetActualFeed()
		{
			return CncGetActualFeed();
		}
		static Cnc_Rc SetSpeedOverride(double factor)
		{
			_LastCNC_RC =(Cnc_Rc)CncSetSpeedOverride(factor);
			return _LastCNC_RC;
		}
		static double GetActualSpeedOverride()
		{
			return CncGetActualSpeedOverride();
		}
		static double GetActualSpeed()
		{
			return CncGetActualSpeed();
		}
		static Cnc_Rc FindFirstJobLine(String^ %text, int %endOfJob, int %totNumOfLines)
		{
			char *Temp_text = new char[CNC_MAX_INTERPRETER_LINE];
			int  Temp_endOfJob = -1;
			int  Temp_totNumOfLines = -1;

			_LastCNC_RC = (Cnc_Rc)CncFindFirstJobLine(Temp_text, &Temp_endOfJob, &Temp_totNumOfLines);
			text = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_text);
			endOfJob = Temp_endOfJob;
			totNumOfLines = Temp_totNumOfLines;
			delete[] Temp_text;
			return _LastCNC_RC;
		}
		static Cnc_Rc FindFirstJobLineF(String^ %text, int %endOfJob)
		{
			char *Temp_text = new char[CNC_MAX_INTERPRETER_LINE];
			int  Temp_endOfJob = -1;
			
			_LastCNC_RC =(Cnc_Rc)CncFindFirstJobLineF(Temp_text, &Temp_endOfJob);
			text = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_text);
			endOfJob = Temp_endOfJob;
			delete[] Temp_text;
			return _LastCNC_RC;
		}
		static Cnc_Rc  FindNextJobLine(String^ %text, int %endOfJob)
		{
			char *Temp_text = new char[CNC_MAX_INTERPRETER_LINE];
			int  Temp_endOfJob = -1;
			_LastCNC_RC =(Cnc_Rc)CncFindNextJobLine(Temp_text, &Temp_endOfJob);
			text = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_text);
			endOfJob = Temp_endOfJob;
			delete[] Temp_text;
			return _LastCNC_RC;
		}
		static Cnc_Rc FindNextJobLineF(String^ %text, int %endOfJob)
		{
			char *Temp_text = new char[CNC_MAX_INTERPRETER_LINE];
			int  Temp_endOfJob = -1;
			_LastCNC_RC = (Cnc_Rc)CncFindNextJobLineF(Temp_text, &Temp_endOfJob);
			text = StringConversie::SDT_STRING_toSYSTEM_STRING(Temp_text);
			endOfJob = Temp_endOfJob;
			
			delete[] Temp_text;
			return _LastCNC_RC;
		}

	};
	public ref class G_PauseFunctions
	{
	public:
		
		static Cnc_Rc SwitchOnSpindleAndWaitUntilOn(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			
			return (Cnc_Rc)CncSwitchOnSpindleAndWaitUntilOn(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		static Cnc_Rc PauseJob()
		{
			_LastCNC_RC = (Cnc_Rc)CncPauseJob();

			return _LastCNC_RC;
		}
		
		static Cnc_Rc PauseJob2(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{

			return (Cnc_Rc)CncPauseJob2(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
			
		}
		static int SyncPauseZSafe()
		{
			return CncSyncPauseZSafe();
		}
		static int SyncPauseXSafe()
		{
			return CncSyncPauseXSafe();
		}
		static int SyncPauseAxis(int axis, double feed)
		{
			return CncSyncPauseAxis(axis, feed);
		}
		
		static int SyncFromPauseAndStartAutomatic(double approachFeed, CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncFromPauseAndStartAutomatic(approachFeed, KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
	};
	
	public ref class G_SearchFunctions
	{
	public:
		
		static int SyncSearchZSafe(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncSearchZSafe(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());//(CNC_KEEP_UI_ALIVE_FUNCTION)ip2.ToInt32(), &pFuncParameter
		}
		
		static int SyncSearchXSafe(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncSearchXSafe(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		
		static int SyncSearchTool(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncSearchTool(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		
		static int SyncInchModeAndParametersAndOffset(CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncInchModeAndParametersAndOffset(KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		
		static int SyncSearchAxis(int axis, double feed, CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return CncSyncSearchAxis(axis, feed, KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
		
		static int SyncFromSearchAndStartAutomatic(double approachFeed, CncKeepUiAliveFunction^ KEEP_UI_ALIVE)
		{
			return  CncSyncFromSearchAndStartAutomatic(approachFeed, KEEP_UI_ALIVE->Functionpfunc, KEEP_UI_ALIVE->ParsFuctionPointerParameter());
		}
	};
	public ref class G_JoggingFunctions
	{
	private:
		//static Managedstruct<double>^ Axis = gcnew Managedstruct<double>(nullptr, CNC_MAX_AXES);
	public:
		static Cnc_Rc StartJogContinuous(CncCartDouble^ axes,double velocityFactor, int continuous)
		{
			/*
			int MaxAxes = axes->GetLength(0);

			for (int i = 0; i < CNC_MAX_AXES; i++)
			{
				if (i < MaxAxes)
				{
					Axis->ValuePointertype[i] = axes[i];
					Console::WriteLine("Axis:"+i+" ="+ Axis->ValuePointertype[i]+" Isset");
				}
				else
				{
					Axis->ValuePointertype[i] = 0;
					Console::WriteLine("Axis:" + i + " =" + Axis->ValuePointertype[i]);
				}
			}
			*/
			_LastCNC_RC = (Cnc_Rc)CncStartJog(axes->ValuePointertype[0],velocityFactor,continuous);
			return _LastCNC_RC;
		}
		static Cnc_Rc StartJog2_SingleAxis(int axis, double step, double velocityFactor, int continuous)
		{
			_LastCNC_RC =(Cnc_Rc)CncStartJog2(axis,step,velocityFactor,continuous);
			return _LastCNC_RC;
		}
		static Cnc_Rc StopJog(int axis)
		{
			_LastCNC_RC =(Cnc_Rc)CncStopJog(axis);
			return _LastCNC_RC;
		}
		static Cnc_Rc MoveTo(CncCartDouble^ pos, CncCartBool^ move, double velocityFactor)
		{
			_LastCNC_RC =(Cnc_Rc)CncMoveTo(pos->ValuePointertype[0], move->ValuePointertype[0], velocityFactor);
			return _LastCNC_RC;
		}
	};
	public ref class G_TrackingFunctions
	{
	private:
		static CncThcProcessParameters^ Temp_GetPlasmaParameters = nullptr;
	public:
		static Cnc_Rc StartPositionTracking()
		{
			_LastCNC_RC =(Cnc_Rc)CncStartPositionTracking();
			return _LastCNC_RC;
		}
		static Cnc_Rc StartVelocityTracking()
		{
			_LastCNC_RC =(Cnc_Rc)CncStartVelocityTracking();
			return _LastCNC_RC;
		}
		static Cnc_Rc StartHandweelTracking(int axis, double vLimit, int handwheelID, int velMode, double multiplicationFactor, int handwheelCountsPerRevolution)
		{
			_LastCNC_RC =(Cnc_Rc)CncStartHandweelTracking(axis, vLimit, handwheelID,velMode,multiplicationFactor,handwheelCountsPerRevolution);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetTrackingPosition(CncCartDouble^ pos,CncCartDouble^ vel,CncCartBool^   move)
		{
			_LastCNC_RC =(Cnc_Rc)CncSetTrackingPosition(pos->ValuePointertype[0],vel->ValuePointertype[0],move->ValuePointertype[0]);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetTrackingPosition2(CncCartDouble^ pos, CncCartDouble^ vel, CncCartDouble^ acc, CncCartBool^ move)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetTrackingPosition2(pos->ValuePointertype[0],vel->ValuePointertype[0],acc->ValuePointertype[0],move->ValuePointertype[0]);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetTrackingVelocity(CncCartDouble^ vel, CncCartBool^   move)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetTrackingVelocity(vel->ValuePointertype[0],move->ValuePointertype[0]);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetTrackingVelocity2(CncCartDouble^ vel, CncCartDouble^ acc, CncCartBool^ axes)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetTrackingVelocity2(vel->ValuePointertype[0],acc->ValuePointertype[0],axes->ValuePointertype[0]);
			return _LastCNC_RC;
		}
		static Cnc_Rc SetTrackingHandwheelCounter(int hw1Count, int hw2Count, int hw3Count)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetTrackingHandwheelCounter(hw1Count, hw2Count, hw3Count);
			return _LastCNC_RC;
		}
		static Cnc_Rc StartPlasmaTHCTracking(double pLimit, double nLimit)
		{
			_LastCNC_RC = (Cnc_Rc)CncStartPlasmaTHCTracking(pLimit,nLimit);
			return _LastCNC_RC;
		}
		
		static Cnc_Rc SetPlasmaParameters(CncThcProcessParameters^ PlasmaParameters)
		{
			_LastCNC_RC = (Cnc_Rc)CncSetPlasmaParameters(PlasmaParameters->ValuePointertype[0]);
			return _LastCNC_RC;
		}
		static CncThcProcessParameters^ GetPlasmaParameters()//link error
		{	
			if (Temp_GetPlasmaParameters == nullptr)
			{
				Temp_GetPlasmaParameters = gcnew CncThcProcessParameters(CncGetPlasmaParameters());
			}
			else
			{
				Temp_GetPlasmaParameters->ValuePointertype = CncGetPlasmaParameters();
			}
			return Temp_GetPlasmaParameters;
		}
		
		static Cnc_Rc StopTracking()
		{
			_LastCNC_RC = (Cnc_Rc)CncStopTracking();
			return _LastCNC_RC;
		}
	};
	public ref class G_3DPrinter
	{
	public:
		static Cnc_Rc _3DPrintCommand(Cnc3DprintingCommand^ pCmd)
		{
			_LastCNC_RC =  (Cnc_Rc)Cnc3DPrintCommand(pCmd->ValuePointertype);
			return _LastCNC_RC;
		}
		
	};
	public ref class G_UtilityItems
	{
	public:
		static String^ GetRCText(Cnc_Rc rc)
		{
			return StringConversie::SDT_STRING_toSYSTEM_STRING(CncGetRCText((CNC_RC)rc));
		}
		static void SendUserMessage(String^ functionName, String^fileName, int lineNumber, CncErrorClass ec, Cnc_Rc rc, String^msg)
		{
			CncSendUserMessage(StringConversie::SYSTEM_STRIN_toCharpoint(functionName), StringConversie::SYSTEM_STRIN_toCharpoint(fileName), lineNumber, (CNC_ERROR_CLASS)ec, (CNC_RC)rc, StringConversie::SYSTEM_STRIN_toCharpoint(msg));

		}
		static Cnc_Rc SendToGUI(CncUioActions action, int value1, int value2)
		{
			_LastCNC_RC = (Cnc_Rc)CncSendToGUI((CNC_UIO_ACTIONS)action, value1, value2);
			return _LastCNC_RC;
		}
		static Cnc_Rc GetGUICommand(CncUioActions % pAction ,int % pValue1, int % pValue2)
		{
			
			if (AppIsPlugin == false)
			{
				CNC_UIO_ACTIONS Temp_pAction = CNC_UIOACTION_NONE;
				int  Temp_pValue = -1;
				int  Temp_pValue2 = -1;
				_LastCNC_RC = (Cnc_Rc)CncGetGUICommand(&Temp_pAction, &Temp_pValue, &Temp_pValue2);
				pValue1 = Temp_pValue;
				pValue2 = Temp_pValue2;
				pAction = (CncUioActions)Temp_pAction;
			}
			else
			{
				PluginError();
			}
			return _LastCNC_RC;
		}
	};

	//link error
	/*
	public ref class G_CncLang
	{
	public:
		void LangSet(CncLangT language)
		{
			//CncLangSet((CNC_LANG_T)language);
		}
		static String^ LangGetText(String^ english)
		{
			String^ Return = "";
			char * TempEnglish = new char[(int)CncLangMax::TextLength];
			StringConversie::SYSTEM_STRING_toMaxCharLength((int)CncLangMax::TextLength, english, TempEnglish);
			char * TempTranslate = CncLangGetText(TempEnglish);
			Return = StringConversie::SDT_STRING_toSYSTEM_STRING(TempTranslate);
			delete[] TempEnglish;
			delete[] TempTranslate;
			return Return;
		}
		static String^ LangGetText2(String^ text, CncLangT fromLanguage)
		{
			String^Return = "";
			char * TempText = new char[(int)CncLangMax::TextLength];
			StringConversie::SYSTEM_STRING_toMaxCharLength((int)CncLangMax::TextLength, text, TempText);
			char * TempTranslate = CncLangGetText2(TempText,(CNC_LANG_T)fromLanguage);
			delete[] TempText;
			delete[] TempTranslate;
			return Return;
		}
		static int LangGetAllTexts(String^ english, CncLangAllText^ Languages)
		{
			StringConversie::SYSTEM_STRING_toMaxCharLength((int)CncLangMax::TextLength,english, Languages->BaseLanguage->ValuePointertype);
			for (int i =0;i<Languages->AllLanguages->Length;i++)//clear currenttext
			{
				for (int f =0;f< Languages->MaxTextLength;f++)
				{
					Languages->AllLanguages[i]->ValuePointertype[f] = '\0';
				}
			}
			return CncLangGetAllTexts(Languages->BaseLanguage->ValuePointertype,
				Languages->AllLanguages[0]->ValuePointertype,
				Languages->AllLanguages[1]->ValuePointertype,
				Languages->AllLanguages[2]->ValuePointertype,
				Languages->AllLanguages[3]->ValuePointertype,
				Languages->AllLanguages[4]->ValuePointertype,
				Languages->AllLanguages[5]->ValuePointertype,
				Languages->AllLanguages[6]->ValuePointertype,
				Languages->AllLanguages[7]->ValuePointertype,
				Languages->AllLanguages[8]->ValuePointertype,
				Languages->AllLanguages[9]->ValuePointertype,
				Languages->AllLanguages[10]->ValuePointertype,
				Languages->AllLanguages[11]->ValuePointertype,
				Languages->AllLanguages[12]->ValuePointertype,
				Languages->AllLanguages[13]->ValuePointertype);
		}
		static int LangAddText(CncLangAllText^ Languages)
		{
			return CncLangAddText(Languages->BaseLanguage->ValuePointertype,
				Languages->AllLanguages[0]->ValuePointertype[0],
				Languages->AllLanguages[1]->ValuePointertype[0],
				Languages->AllLanguages[2]->ValuePointertype[0],
				Languages->AllLanguages[3]->ValuePointertype[0],
				Languages->AllLanguages[4]->ValuePointertype[0],
				Languages->AllLanguages[5]->ValuePointertype[0],
				Languages->AllLanguages[6]->ValuePointertype[0],
				Languages->AllLanguages[7]->ValuePointertype[0],
				Languages->AllLanguages[8]->ValuePointertype[0],
				Languages->AllLanguages[9]->ValuePointertype[0],
				Languages->AllLanguages[10]->ValuePointertype[0],
				Languages->AllLanguages[11]->ValuePointertype[0],
				Languages->AllLanguages[12]->ValuePointertype[0],
				Languages->AllLanguages[13]->ValuePointertype[0]);
		}
		static int LangImport(String^ filename)
		{
			int Return = -2;
			char * TempFilename = new char[CNC_MAX_PATH];
			StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH,filename, TempFilename);
			Return = CncLangImport(TempFilename);
			delete[] TempFilename;
			return Return;
		}
		static int LangExport(String^ filename)
		{
			int Return = -2;
			char * TempFilename = new char[CNC_MAX_PATH];
			StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH, filename, TempFilename);
			Return = CncLangExport(TempFilename);
			delete[] TempFilename;
			return Return;
		}
	};
	*/
	
}
//file checked for usbcncversie 4.3

/*mogelijke bugs in:
Group_CommandsJobInterpreterRelated -> CncVector^ GetJobMaterialSize() = jobsize parameters altijd x250 y250 z10 ????? Komt dit door simulatie modus of doe ik wat verkeerd?

*/
