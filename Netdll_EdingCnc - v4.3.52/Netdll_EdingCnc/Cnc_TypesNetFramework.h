#pragma once
#include <iostream>
#include "cncapi/cncapi.h"
#include "StringConversie.h"
#include "typedefEnumClass.h"
#include "Cnc_ManagedTemplate.h"
#include "Cnc_BasicTypesNetFramework.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

//using namespace std;

namespace OosterhofDesign
{
	public ref class Cnc3DPrintingTempCalibrationTable :public Managedstruct<CNC_3DPRINTING_TEMP_CALIBRATION_TABLE>
	{
	private:
		array<Cnc3DPrintingVoltTempTuple^>^ Temp_table = nullptr;
		void NewClass()
		{
			Temp_table = gcnew array<Cnc3DPrintingVoltTempTuple^>(CNC_MAX_3D_TEMP_TABLE);
		}
	public:
		Cnc3DPrintingTempCalibrationTable(CNC_3DPRINTING_TEMP_CALIBRATION_TABLE  *_CNC_3DPRINTING_TEMP_CALIBRATION_TABLE) :Managedstruct(_CNC_3DPRINTING_TEMP_CALIBRATION_TABLE)
		{
			NewClass();
		}
		Cnc3DPrintingTempCalibrationTable() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(Cnc3DPrintingTempCalibrationTable^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int actualTableSize
		{
			int get()
			{
				return ValuePointertype->actualTableSize;
			}
			void set(int Value)
			{
				ValuePointertype->actualTableSize = Value;
			}
		}

		property array<Cnc3DPrintingVoltTempTuple^>^ table
		{
			array<Cnc3DPrintingVoltTempTuple^>^ get()
			{

				for (int i = 0; i < Temp_table->Length; i++)
				{
					if (Temp_table[i] == nullptr)
					{
						Temp_table[i] = gcnew Cnc3DPrintingVoltTempTuple(&ValuePointertype->table[i]);
					}
					else
					{
						Temp_table[i]->ValuePointertype = &ValuePointertype->table[i];
					}
				}

				return Temp_table;
			}
			void set(array<Cnc3DPrintingVoltTempTuple^>^ Value)
			{
				if (Value->Length == CNC_MAX_3D_TEMP_TABLE)
				{
					//Temp_table = Value;
					for (int i = 0; i < Value->Length; i++)
					{
						ValuePointertype->table[i] = Value[i]->ValuePointertype[0];
					}
				}
			}
		}

	};
	public ref class CncOffsetAndPlane :public Managedstruct<CNC_OFFSET_AND_PLANE>//<<updatepointer
	{
	private:
		CncCartDouble^  Temp_g5xOffset = nullptr;
		CncCartDouble^   Temp_g92Offset = nullptr;
		CncCartDouble^   Temp_spindleConfigOffset = nullptr;
		CncCartDouble^   Temp_totalOffset = nullptr;
		CncVector^        Temp_toolOffset = nullptr;
		CncVector^        Temp_RotationBasePoint = nullptr;
		CncVector^        Temp_XYScalingFactor = nullptr;
		void NewClass()
		{
			Temp_g5xOffset = gcnew CncCartDouble(&ValuePointertype->g5xOffset);
			Temp_g92Offset = gcnew CncCartDouble(&ValuePointertype->g92Offset);
			Temp_spindleConfigOffset = gcnew CncCartDouble(&ValuePointertype->spindleConfigOffset);
			Temp_totalOffset = gcnew CncCartDouble(&ValuePointertype->totalOffset);
			Temp_toolOffset = gcnew CncVector(&ValuePointertype->toolOffset);
			Temp_RotationBasePoint = gcnew CncVector(&ValuePointertype->RotationBasePoint);
			Temp_XYScalingFactor = gcnew CncVector(&ValuePointertype->XYScalingFactor);
		}

	public:
		CncOffsetAndPlane(CNC_OFFSET_AND_PLANE *_OFFSET_AND_PLANE) :Managedstruct(_OFFSET_AND_PLANE)
		{
			NewClass();
		}
		CncOffsetAndPlane() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncOffsetAndPlane^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property CncCartDouble^  g5xOffset            /* G54 .. G59.3         */
		{
			CncCartDouble^ get()
			{
				Temp_g5xOffset->ValuePointertype = &ValuePointertype->g5xOffset;
				return Temp_g5xOffset;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->g5xOffset = Value->ValuePointertype[0];
				//Temp_g5xOffset = Value;
			}
		}
		property int currentG5X      /* active coord syst nr */
		{
			int get()
			{
				return ValuePointertype->currentG5X;
			}
			void set(int Value)
			{
				ValuePointertype->currentG5X = Value;
			}
		}
		property CncCartDouble^   g92Offset            /* G92                  */
		{
			CncCartDouble^ get()
			{
				Temp_g92Offset->ValuePointertype = &ValuePointertype->g92Offset;
				return Temp_g92Offset;
			}
			void set(CncCartDouble^ Value)
			{
				ValuePointertype->g92Offset = Value->ValuePointertype[0];
				//Temp_g92Offset = Value;
			}
		}
		property CncCartDouble^   spindleConfigOffset  /* M90, M91, M92        */
		{
			CncCartDouble^ get()
			{
				Temp_spindleConfigOffset->ValuePointertype = &ValuePointertype->spindleConfigOffset;
				return Temp_spindleConfigOffset;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->spindleConfigOffset = Value->ValuePointertype[0];
				//Temp_spindleConfigOffset = Value;
			}
		}
		property int spOffsetIndex        /* M90:0 .. M92:2       */
		{
			int get()
			{
				return ValuePointertype->spOffsetIndex;
			}
			void set(int Value)
			{
				ValuePointertype->spOffsetIndex = Value;
			}
		}
		property CncCartDouble^   totalOffset          /* Sum of the 3 above   */
		{
			CncCartDouble^ get()
			{
				Temp_totalOffset->ValuePointertype = &ValuePointertype->totalOffset;
				return Temp_totalOffset;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->totalOffset = Value->ValuePointertype[0];
				//Temp_totalOffset = Value;
			}
		}

		property CncVector^ toolOffset           /* G43                  */
		{
			CncVector^ get()
			{
				Temp_toolOffset->ValuePointertype = &ValuePointertype->toolOffset;
				return Temp_toolOffset;
			}
			void set(CncVector^ Value)
			{

				ValuePointertype->toolOffset = Value->ValuePointertype[0];
				//Temp_toolOffset = Value;
			}
		}
		property int g43ToolNumber        /* tool number for G43, can be different from actual tool ! */
		{
			int get()
			{
				return ValuePointertype->g43ToolNumber;
			}
			void set(int Value)
			{
				ValuePointertype->g43ToolNumber = Value;
			}
		}

		//Rotate around Z (C)
		property double XYRotationDegrees    /* G68                  */
		{
			double get()
			{
				return ValuePointertype->XYRotationDegrees;
			}
			void set(double Value)
			{
				ValuePointertype->XYRotationDegrees = Value;
			}
		}
		property int XYRotationActive     /* G68                  */
		{
			int get()
			{
				return ValuePointertype->XYRotationActive;
			}
			void set(int Value)
			{
				ValuePointertype->XYRotationActive = Value;
			}
		}
		//Rotate around Y (B)
		property double XZRotationDegrees    /* G68                  */
		{
			double get()
			{
				return ValuePointertype->XZRotationDegrees;
			}
			void set(double Value)
			{
				ValuePointertype->XZRotationDegrees = Value;
			}
		}
		property int XZRotationActive     /* G68                  */
		{
			int get()
			{
				return ValuePointertype->XZRotationActive;
			}
			void set(int Value)
			{
				ValuePointertype->XZRotationActive = Value;
			}
		}
		//Rotate around X (A)
		property double YZRotationDegrees    /* G68                  */
		{
			double get()
			{
				return ValuePointertype->YZRotationDegrees;
			}
			void set(double Value)
			{
				ValuePointertype->YZRotationDegrees = Value;
			}
		}
		property int YZRotationActive     /* G68                  */
		{
			int get()
			{
				return ValuePointertype->YZRotationActive;
			}
			void set(int Value)
			{
				ValuePointertype->YZRotationActive = Value;
			}
		}


		property CncVector^ RotationBasePoint     /* G68                  */
		{
			CncVector^ get()
			{
				Temp_RotationBasePoint->ValuePointertype = &ValuePointertype->RotationBasePoint;
				return Temp_RotationBasePoint;
			}
			void set(CncVector^ Value)
			{

				ValuePointertype->RotationBasePoint = Value->ValuePointertype[0];
				//Temp_RotationBasePoint = Value;
			}
		}
		property int XYScalingActive      /* G51                  */
		{
			int get()
			{
				return ValuePointertype->XYScalingActive;
			}
			void set(int Value)
			{
				ValuePointertype->XYScalingActive = Value;
			}
		}
		property CncVector^ XYScalingFactor      /* G51                  */
		{
			CncVector^ get()
			{
				Temp_XYScalingFactor->ValuePointertype = &ValuePointertype->XYScalingFactor;
				return Temp_XYScalingFactor;
			}
			void set(CncVector^ Value)
			{

				ValuePointertype->XYScalingFactor = Value->ValuePointertype[0];
				//Temp_XYScalingFactor = Value;
			}
		}

		property CncPlane activePlane          /* G17, G18, G19        */
		{
			CncPlane get()
			{
				return (CncPlane)ValuePointertype->activePlane;
			}
			void set(CncPlane Value)
			{
				ValuePointertype->activePlane = (CNC_PLANE)Value;

			}
		}
	};
	public ref class CncBasicInterpreterStatus : public Managedstruct<CNC_BASIC_INTERPRETER_STATUS>
	{
	private:
		array<double>^ Temp_parameters0to27 = nullptr;
		CncCartBool^ Temp_axesPresent = nullptr;
		CncCartDouble^ Temp_position = nullptr;
		CncOffsetAndPlane^ Temp_activeOffsetAndPlane = nullptr;
		void NewClass()
		{
			Temp_parameters0to27 = gcnew array<double>(sizeof(ValuePointertype->parameters0to27) / SizeOfdoublex32);
			Temp_axesPresent = gcnew CncCartBool(&ValuePointertype->axesPresent);
			Temp_position = gcnew CncCartDouble(&ValuePointertype->position);
			Temp_activeOffsetAndPlane = gcnew CncOffsetAndPlane(&ValuePointertype->activeOffsetAndPlane);
		}
	public:
		CncBasicInterpreterStatus(CNC_BASIC_INTERPRETER_STATUS  *_BASIC_INTERPRETER_STATUS) :Managedstruct(_BASIC_INTERPRETER_STATUS)
		{
			NewClass();
		}
		CncBasicInterpreterStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncBasicInterpreterStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncCartBool^ axesPresent
		{
			CncCartBool^get()
			{
				Temp_axesPresent->ValuePointertype = &ValuePointertype->axesPresent;
				return Temp_axesPresent;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->axesPresent, LockOverrideDataInPointer);
			}

		}
		property CncCartDouble^ position //mm
		{
			CncCartDouble^ get()
			{
				Temp_position->ValuePointertype = &ValuePointertype->position;
				return Temp_position;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->position, LockOverrideDataInPointer);
			}

		}
		property CncOffsetAndPlane^ activeOffsetAndPlane
		{
			CncOffsetAndPlane^ get()
			{
				Temp_activeOffsetAndPlane->ValuePointertype = &ValuePointertype->activeOffsetAndPlane;
				return Temp_activeOffsetAndPlane;
			}
		
			void set(CncOffsetAndPlane^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_OFFSET_AND_PLANE>(Value->ValuePointertype[0], &ValuePointertype->activeOffsetAndPlane, LockOverrideDataInPointer);
			}

		}
		property int spindleOn
		{
			int get()
			{
				return ValuePointertype->spindleOn;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleOn, LockOverrideDataInPointer);
			}

		}
		property int mist
		{
			int get()
			{
				return ValuePointertype->mist;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->mist, LockOverrideDataInPointer);
			}

		}
		property int flood
		{
			int get()
			{
				return ValuePointertype->flood;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->flood, LockOverrideDataInPointer);
			}

		}
		property double speed
		{
			double get()
			{
				return ValuePointertype->speed;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->speed, LockOverrideDataInPointer);
			}

		}
		property int toolInSpindle
		{
			int get()
			{
				return ValuePointertype->toolInSpindle;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->toolInSpindle, LockOverrideDataInPointer);
			}

		}
		property double feed
		{
			double get()
			{
				return ValuePointertype->feed;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->feed, LockOverrideDataInPointer);
			}

		}
		property int inchMode
		{
			int get()
			{
				return ValuePointertype->inchMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->inchMode, LockOverrideDataInPointer);
			}

		}
		property int motionToBe
		{
			int get()
			{
				return ValuePointertype->motionToBe;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->motionToBe, LockOverrideDataInPointer);
			}

		}
		property double lafBlendAccuracy
		{
			double get()
			{
				return ValuePointertype->lafBlendAccuracy;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lafBlendAccuracy, LockOverrideDataInPointer);
			}

		}
		property double lineTolerance
		{
			double get()
			{
				return ValuePointertype->lineTolerance;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lineTolerance, LockOverrideDataInPointer);
			}

		}
		


		property double lafAngleFullSpeed
		{
			double get()
			{
				return ValuePointertype->lafAngleFullSpeed;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lafAngleFullSpeed, LockOverrideDataInPointer);
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
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lafAngleReducedSpeed, LockOverrideDataInPointer);
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
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lafDeltaReducedSpeed, LockOverrideDataInPointer);
			}

		}
		property double lafFilter
		{
			double get()
			{
				return ValuePointertype->lafFilter;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->lafFilter, LockOverrideDataInPointer);
			}

		}

		property array<double>^ parameters0to27
		{
			array<double>^ get()
			{
				for (int i = 0; i < Temp_parameters0to27->Length; i++)
				{
					Temp_parameters0to27[i] = ValuePointertype->parameters0to27[i];
				}
				return Temp_parameters0to27;
			}
		
			void set(array<double>^ Value)
			{
				if (Value->Length == Temp_parameters0to27->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < Temp_parameters0to27->Length; i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<double>(Value[i], &ValuePointertype->parameters0to27[i], LockOverrideDataInPointer);
					}
				}
			}

		}
	};
	public ref class Cnc3DPCmdData :public Managedstruct<CNC_3DP_CMD_DATA>
	{
	private:
		Cnc3DPrintingTempPidPars^ Temp_Cnc3DprintingTempPidPars = nullptr;
		Cnc3DpOnOffData^ Temp_Cnc3DpOnOffData = nullptr;
		Cnc3DpFloatValData^ Temp_Cnc3DpFloatValData = nullptr;
		void NewClass()
		{
			Temp_Cnc3DprintingTempPidPars = gcnew Cnc3DPrintingTempPidPars(&ValuePointertype->pidPars);
			Temp_Cnc3DpOnOffData = gcnew Cnc3DpOnOffData(&ValuePointertype->onOffVal);
			Temp_Cnc3DpFloatValData = gcnew Cnc3DpFloatValData(&ValuePointertype->floatVal);
		}

	public:
		Cnc3DPCmdData(CNC_3DP_CMD_DATA * _CNC_3DP_CMD_DATA) :Managedstruct(_CNC_3DP_CMD_DATA)
		{
			NewClass();
		}
		Cnc3DPCmdData() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(Cnc3DPCmdData^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property Cnc3DPrintingTempPidPars^ pidPars
		{
			Cnc3DPrintingTempPidPars^ get()
			{
				Temp_Cnc3DprintingTempPidPars->ValuePointertype = &ValuePointertype->pidPars;
				return Temp_Cnc3DprintingTempPidPars;
			}
			void set(Cnc3DPrintingTempPidPars^ Value)
			{

				ValuePointertype->pidPars = Value->ValuePointertype[0];//unmanaged class pointer. this is for if the user creates a new class Cnc3DprintingTempPidPars. the pointer must also set in the current class pointer
				//Temp_Cnc3DprintingTempPidPars = Value;//managed class for netframework
			}
		}
		property Cnc3DpOnOffData^ onOffVal
		{
			Cnc3DpOnOffData^ get()
			{
				Temp_Cnc3DpOnOffData->ValuePointertype = &ValuePointertype->onOffVal;
				return Temp_Cnc3DpOnOffData;
			}
			void set(Cnc3DpOnOffData^ Value)
			{

				ValuePointertype->onOffVal = Value->ValuePointertype[0];
				//Temp_Cnc3DpOnOffData = Value;
			}
		}
		property Cnc3DpFloatValData^ floatVal
		{
			Cnc3DpFloatValData^ get()
			{
				Temp_Cnc3DpFloatValData->ValuePointertype = &ValuePointertype->floatVal;
				return Temp_Cnc3DpFloatValData;
			}
			void set(Cnc3DpFloatValData^ Value)
			{

				ValuePointertype->floatVal = Value->ValuePointertype[0];
				//Temp_Cnc3DpFloatValData = Value;
			}
		}
	};
	public ref class CncInterprererConfig :public Managedstruct<CNC_INTERPRETER_CONFIG>
	{
	private:
		array<CncToolDataInternal^>^ Temp_toolTable = nullptr;
		void NewClass()
		{
			Temp_toolTable = gcnew array<CncToolDataInternal^>(CNC_MAX_TOOLS + 1);
		}
	public:
		CncInterprererConfig(CNC_INTERPRETER_CONFIG * _CNC_INTERPRETER_CONFIG) :Managedstruct(_CNC_INTERPRETER_CONFIG)
		{
			NewClass();
		}
		CncInterprererConfig() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncInterprererConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);

		}
		property double g64pvalue
		{
			double get()
			{
				return ValuePointertype->g64pvalue;
			}
			void set(double Value)
			{
				ValuePointertype->g64pvalue = Value;
			}
		}
		property int g64Active
		{
			int get()
			{
				return ValuePointertype->g64Active;
			}
			void set(int Value)
			{
				ValuePointertype->g64Active = Value;
			}
		}

		property int longFileModeCriterion
		{
			int get()
			{
				return ValuePointertype->longFileModeCriterion;
			}
			void set(int Value)
			{
				ValuePointertype->longFileModeCriterion = Value;
			}
		}
		property int superLongFileModeCriterion
		{
			int get()
			{
				return ValuePointertype->superLongFileModeCriterion;
			}
			void set(int Value)
			{
				ValuePointertype->superLongFileModeCriterion = Value;
			}
		}
		property String^ macroFileName
		{
			String^ get()
			{
				return  StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->macroFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH, Value, ValuePointertype->macroFileName);
			}
		}
		property String^ userMacroFileName
		{
			String^ get()
			{
				return  StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->userMacroFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH, Value, ValuePointertype->userMacroFileName);
			}
		}
		property String^ initialString
		{
			String^ get()
			{
				return  StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->initialString);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_INTERPRETER_LINE, Value, ValuePointertype->initialString);
			}
		}
		property int g4InMilliseconds
		{
			int get()
			{
				return ValuePointertype->g4InMilliseconds;
			}
			void set(int Value)
			{
				ValuePointertype->g4InMilliseconds = Value;
			}
		}
		property int inchModeActive
		{
			int get()
			{
				return ValuePointertype->inchModeActive;
			}
			void set(int Value)
			{
				ValuePointertype->inchModeActive = Value;
			}
		}
		property int diameterProgramming
		{
			int get()
			{
				return ValuePointertype->diameterProgramming;
			}
			void set(int Value)
			{
				ValuePointertype->diameterProgramming = Value;
			}
		}
		property int reverseG2G3
		{
			int get()
			{
				return ValuePointertype->reverseG2G3;
			}
			void set(int Value)
			{
				ValuePointertype->reverseG2G3 = Value;
			}
		}

		property int absoluteCenterCoords
		{
			int get()
			{
				return ValuePointertype->absoluteCenterCoords;
			}
			void set(int Value)
			{
				ValuePointertype->absoluteCenterCoords = Value;
			}
		}
		property double fullCircleThetaEpsilon
		{
			double get()
			{
				return ValuePointertype->fullCircleThetaEpsilon;
			}
			void set(double Value)
			{
				ValuePointertype->fullCircleThetaEpsilon = Value;
			}
		}

		property array<CncToolDataInternal^>^toolTable //(int ID)
		{
			//CncToolDataInternal^ Temp_toolTable;

			array<CncToolDataInternal^>^ get()
			{

				for (int i = 0; i < Temp_toolTable->Length; i++)
				{
					if (Temp_toolTable[i] == nullptr)
					{
						Temp_toolTable[i] = gcnew CncToolDataInternal(&ValuePointertype->toolTable[i]);
					}
					else
					{
						Temp_toolTable[i]->ValuePointertype = &ValuePointertype->toolTable[i];
					}
				}

				return Temp_toolTable;
			}
			void set(array<CncToolDataInternal^>^ Value)
			{
				if (Value->Length == Temp_toolTable->Length)
				{
					//Temp_toolTable = Value;
					for (int i = 0; i < Value->Length; i++)
					{
						ValuePointertype->toolTable[i] = Value[i]->ValuePointertype[0];
					}
				}
			}
		}
		property int noHaltForToolChange
		{
			int get()
			{
				return ValuePointertype->noHaltForToolChange;
			}
			void set(int Value)
			{
				ValuePointertype->noHaltForToolChange = Value;
			}
		}
		property int noHaltOnErrMsgDuringRender
		{
			int get()
			{
				return ValuePointertype->noHaltOnErrMsgDuringRender;
			}
			void set(int Value)
			{
				ValuePointertype->noHaltOnErrMsgDuringRender = Value;
			}
		}
		property double tanKnifeAngleForLiftUp
		{
			double get()
			{
				return ValuePointertype->tanKnifeAngleForLiftUp;
			}
			void set(double Value)
			{
				ValuePointertype->tanKnifeAngleForLiftUp = Value;
			}
		}
		property double tanKnifeBlendAngle
		{
			double get()
			{
				return ValuePointertype->tanKnifeBlendAngle;
			}
			void set(double Value)
			{
				ValuePointertype->tanKnifeBlendAngle = Value;
			}
		}
		property double tanKnifeBlendDistance
		{
			double get()
			{
				return ValuePointertype->tanKnifeBlendDistance;
			}
			void set(double Value)
			{
				ValuePointertype->tanKnifeBlendDistance = Value;
			}
		}
		property double tanKnifeLiftUpDistance
		{
			double get()
			{
				return ValuePointertype->tanKnifeLiftUpDistance;
			}
			void set(double Value)
			{
				ValuePointertype->tanKnifeLiftUpDistance = Value;
			}
		}
		property int tanknifeBendingAngle
		{
			int get()
			{
				return ValuePointertype->tanknifeBendingAngle;
			}
			void set(int Value)
			{
				ValuePointertype->tanknifeBendingAngle = Value;
			}
		}
		property double tanknifeZhiWork
		{
			double get()
			{
				return ValuePointertype->tanknifeZhiWork;
			}
			void set(double Value)
			{
				ValuePointertype->tanknifeZhiWork = Value;
			}
		}
		property double tanknifeZloWork
		{
			double get()
			{
				return ValuePointertype->tanknifeZloWork;
			}
			void set(double Value)
			{
				ValuePointertype->tanknifeZloWork = Value;
			}
		}
		property int tanknifeRewindTurns
		{
			int get()
			{
				return ValuePointertype->tanknifeRewindTurns;
			}
			void set(int Value)
			{
				ValuePointertype->tanknifeRewindTurns = Value;
			}
		}
	};
	public ref class CncI2cgpioCardConfig :public Managedstruct<CNC_I2CGPIO_CARD_CONFIG>//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	{
	private:
		array<CncI2cgpioRuleConfig^, 2>^ Temp_CncI2cgpioRuleConfig = nullptr;
		void NewClass()
		{
			Temp_CncI2cgpioRuleConfig = gcnew array<CncI2cgpioRuleConfig^, 2>(CNC_MAX_GPIOCARD_CARDS, CNC_MAX_GPIOCARD_RULES);
		}
	public:
		CncI2cgpioCardConfig(CNC_I2CGPIO_CARD_CONFIG * _CNC_I2CGPIO_CARD_CONFIG) :Managedstruct(_CNC_I2CGPIO_CARD_CONFIG)
		{
			NewClass();
		}
		CncI2cgpioCardConfig() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncI2cgpioCardConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		property int _nrOfGpioCards
		{
			int get()
			{
				return ValuePointertype->_nrOfGpioCards;
			}
			void set(int Value)
			{
				ValuePointertype->_nrOfGpioCards = Value;
			}

		}
		property array<CncI2cgpioRuleConfig^, 2>^ ruleConfig
		{
			array<CncI2cgpioRuleConfig^, 2>^ get()
			{
				for (int Card = 0; Card < CNC_MAX_GPIOCARD_CARDS; Card++)
				{
					for (int Rule = 0; Rule < CNC_MAX_GPIOCARD_RULES; Rule++)
					{
						if (Temp_CncI2cgpioRuleConfig[Card, Rule] == nullptr)
						{
							Temp_CncI2cgpioRuleConfig[Card, Rule] = gcnew CncI2cgpioRuleConfig(&ValuePointertype->ruleConfig[Card][Rule]);
						}
						else
						{
							Temp_CncI2cgpioRuleConfig[Card, Rule]->ValuePointertype = &ValuePointertype->ruleConfig[Card][Rule];
						}
					}
				}
				return Temp_CncI2cgpioRuleConfig;
			}
			void set(array<CncI2cgpioRuleConfig^, 2>^ Value)
			{
				if (Value->GetLength(0) == CNC_MAX_GPIOCARD_CARDS && Value->GetLength(1) == CNC_MAX_GPIOCARD_RULES)
				{
					//Temp_CncI2cgpioRuleConfig = Value;
					for (int Card = 0; Card < CNC_MAX_GPIOCARD_CARDS; Card++)
					{
						for (int Rule = 0; Rule < CNC_MAX_GPIOCARD_RULES; Rule++)
						{
							ValuePointertype->ruleConfig[Card][Rule] = Temp_CncI2cgpioRuleConfig[Card, Rule]->ValuePointertype[0];
						}
					}
				}
				else
				{
					System::Diagnostics::Debug::WriteLine("Incorrect Lenght");
				}
			}
		}


	};
	public ref class CncSpindleConfig :public Managedstruct<CNC_SPINDLE_CONFIG>
	{
	private:
		CncVector^ Temp_CncVector_coordinateSystemOffset = nullptr;
		void NewClass()
		{
			Temp_CncVector_coordinateSystemOffset = gcnew CncVector(&ValuePointertype->coordinateSystemOffset);
		}
	public:
		CncSpindleConfig(CNC_SPINDLE_CONFIG * _CNC_SPINDLE_CONFIG) :Managedstruct(_CNC_SPINDLE_CONFIG)
		{
			NewClass();
		}
		CncSpindleConfig() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncSpindleConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property int spindleIndex
		{
			int get()
			{
				return ValuePointertype->spindleIndex;
			}
			void set(int Value)
			{
				ValuePointertype->spindleIndex = Value;
			}
		}

		/* time to wait after spindle on to wait at full speed, before moving */
		property double rampUpTime
		{
			double get()
			{
				return ValuePointertype->rampUpTime;
			}
			void set(double Value)
			{
				ValuePointertype->rampUpTime = Value;
			}
		}
		property double rampDownTime
		{
			double get()
			{
				return ValuePointertype->rampDownTime;
			}
			void set(double Value)
			{
				ValuePointertype->rampDownTime = Value;
			}
		}
		/* if 1 ramp uptime is proportional with speed */
		/* int proportionalRampUpTime; */

		/* max/min spindle revolutions/sec five 100% PWM output */
		property double NmaxRPM
		{
			double get()
			{
				return ValuePointertype->NmaxRPM;
			}
			void set(double Value)
			{
				ValuePointertype->NmaxRPM = Value;
			}
		}
		property double NminRPM
		{
			double get()
			{
				return ValuePointertype->NminRPM;
			}
			void set(double Value)
			{
				ValuePointertype->NminRPM = Value;
			}
		}

		/* for step/pulse spindle, 0 for normal PWM spindle */
		property int countPerRev
		{
			int get()
			{
				return ValuePointertype->countPerRev;
			}
			void set(int Value)
			{
				ValuePointertype->countPerRev = Value;
			}
		}


		property int stepperMotorMode
		{
			int get()
			{
				return ValuePointertype->stepperMotorMode;
			}
			void set(int Value)
			{
				ValuePointertype->stepperMotorMode = Value;
			}
		}

		/* smooth count mode uses 32 bit counter i.s.o 16 bit, this however makes PWM2/3 no longer as separate PWM usable on cpu5b */
		property int smoothCountMode
		{
			int get()
			{
				return ValuePointertype->smoothCountMode;
			}
			void set(int Value)
			{
				ValuePointertype->smoothCountMode = Value;
			}
		}

		/* if true, use sensor (if available) to measure spindle speed */
		property int useRPMSensor
		{
			int get()
			{
				return ValuePointertype->useRPMSensor;
			}
			void set(int Value)
			{
				ValuePointertype->useRPMSensor = Value;
			}
		}

		/* IO's to be used for spindle */
		property CncGpioId onOffOutputPortID
		{
			CncGpioId get()
			{
				return (CncGpioId)ValuePointertype->onOffOutputPortID;
			}
			void set(CncGpioId Value)
			{
				ValuePointertype->onOffOutputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncGpioId directionOutputPortID
		{
			CncGpioId get()
			{
				return (CncGpioId)ValuePointertype->directionOutputPortID;
			}
			void set(CncGpioId Value)
			{
				ValuePointertype->directionOutputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncGpioId pwmOutputPortID
		{
			CncGpioId get()
			{
				return (CncGpioId)ValuePointertype->pwmOutputPortID;
			}
			void set(CncGpioId Value)
			{
				ValuePointertype->pwmOutputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncGpioId spindleReadyPortID
		{
			CncGpioId get()
			{
				return (CncGpioId)ValuePointertype->spindleReadyPortID;
			}
			void set(CncGpioId Value)
			{
				ValuePointertype->spindleReadyPortID = (CNC_IO_ID)Value;
			}
		}

		/* 0 = spindle ready with M3 and M5, 1 = spindle ready with m3, 2 spindle not ready with m5 */
		property int spindleReadyPortMode
		{
			int get()
			{
				return ValuePointertype->spindleReadyPortMode;
			}
			void set(int Value)
			{
				ValuePointertype->spindleReadyPortMode = Value;
			}
		}

		/* id this is set our direction and onoff port change into rightOnOff and leftOnOff port */
		property int rightOnLeftOnMNode
		{
			int get()
			{
				return ValuePointertype->rightOnLeftOnMNode;
			}
			void set(int Value)
			{
				ValuePointertype->rightOnLeftOnMNode = Value;
			}
		}

		/* offset for this spindle */
		property CncVector^ coordinateSystemOffset
		{
			CncVector^ get()
			{
				Temp_CncVector_coordinateSystemOffset->ValuePointertype = &ValuePointertype->coordinateSystemOffset;
				return Temp_CncVector_coordinateSystemOffset;
			}
			void set(CncVector^ Value)
			{
				ValuePointertype->coordinateSystemOffset = Value->ValuePointertype[0];
				//Temp_CncVector_coordinateSystemOffset = Value;
			}
		}

		/* spindle PWM correction table */
		property String^ pwmCompensationFileName//[CNC_MAX_PATH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->pwmCompensationFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH, Value, ValuePointertype->pwmCompensationFileName);
			}
		}
		property int  pwmCompensationOn
		{
			int get()
			{
				return ValuePointertype->pwmCompensationOn;
			}
			void set(int Value)
			{
				ValuePointertype->pwmCompensationOn = Value;
			}
		}

		/* max time for averaging the spindles speed, is o.a. used for thread cutting */
		property int maxAvgSpeedFilterTimeMillisecs
		{
			int get()
			{
				return ValuePointertype->maxAvgSpeedFilterTimeMillisecs;
			}
			void set(int Value)
			{
				ValuePointertype->maxAvgSpeedFilterTimeMillisecs = Value;
			}
		}

		/* correction of speed measured by sensor, not used yet */
		property int sensorSpeedControlOn
		{
			int get()
			{
				return ValuePointertype->sensorSpeedControlOn;
			}
			void set(int Value)
			{
				ValuePointertype->sensorSpeedControlOn = Value;
			}
		}
		property double sensorSpeedControlCycleTime
		{
			double get()
			{
				return ValuePointertype->sensorSpeedControlCycleTime;
			}
			void set(double Value)
			{
				ValuePointertype->sensorSpeedControlCycleTime = Value;
			}
		}
	};
	public ref class CncKinCfg :public Managedstruct<CNC_KIN_CFG>
	{
	private:
		CncCartBool^ Temp_CncCartBool_axesInUse = nullptr;
		CncCartBool^ Temp_CncCartBool_axesVisible = nullptr;
		CncJointBool^ Temp_CncJointBool_jointInUse = nullptr;
		CncJointBool^ Temp_CncJointBool_jointVisible = nullptr;
		CncJointBool^ Temp_CncJointBool_jointIsSlave = nullptr;
		CncCartDouble^ Temp_CncCartDouble_maxCartesianVelocity = nullptr;

		CncCartDouble^ Temp_CncCartDouble_maxCartesianAcceleration = nullptr;
		CncCartDouble^ Temp_CncCartDouble_positiveCartesianLimit = nullptr;
		CncCartDouble^ Temp_CncCartDouble_negativeCartesianLimit = nullptr;

		CncJointDouble^ Temp_CncJointDouble_maxJointVelocity = nullptr;
		CncJointDouble^ Temp_CncJointDouble_maxJointAcceleration = nullptr;
		CncJointDouble^ Temp_CncJointDouble_positiveJointLimit = nullptr;
		CncJointDouble^ Temp_CncJointDouble_negativeJointLimit = nullptr;

		CncCartDouble^ Temp_CncCartDouble_positiveLimitTCA = nullptr;
		CncCartDouble^ Temp_CncCartDouble_negativeLimitTCA = nullptr;

		CncVector^ Temp_CncVector_aAxisCalibratedRotationPoint = nullptr;
		void NewClass()
		{
			Temp_CncCartBool_axesInUse = gcnew CncCartBool(&ValuePointertype->axesInUse);
			Temp_CncCartBool_axesVisible = gcnew CncCartBool(&ValuePointertype->axesVisible);
			Temp_CncJointBool_jointInUse = gcnew CncJointBool(&ValuePointertype->jointInUse);
			Temp_CncJointBool_jointVisible = gcnew CncJointBool(&ValuePointertype->jointVisible);
			Temp_CncJointBool_jointIsSlave = gcnew CncJointBool(&ValuePointertype->jointIsSlave);

			Temp_CncCartDouble_maxCartesianVelocity = gcnew CncCartDouble(&ValuePointertype->maxCartesianVelocity);
			Temp_CncCartDouble_maxCartesianAcceleration = gcnew CncCartDouble(&ValuePointertype->maxCartesianAcceleration);
			Temp_CncCartDouble_positiveCartesianLimit = gcnew CncCartDouble(&ValuePointertype->positiveCartesianLimit);
			Temp_CncCartDouble_negativeCartesianLimit = gcnew CncCartDouble(&ValuePointertype->negativeCartesianLimit);

			Temp_CncJointDouble_maxJointVelocity = gcnew CncJointDouble(&ValuePointertype->maxJointVelocity);
			Temp_CncJointDouble_maxJointAcceleration = gcnew CncJointDouble(&ValuePointertype->maxJointAcceleration);
			Temp_CncJointDouble_positiveJointLimit = gcnew CncJointDouble(&ValuePointertype->positiveJointLimit);
			Temp_CncJointDouble_negativeJointLimit = gcnew CncJointDouble(&ValuePointertype->negativeJointLimit);

			Temp_CncCartDouble_positiveLimitTCA = gcnew CncCartDouble(&ValuePointertype->positiveLimitTCA);
			Temp_CncCartDouble_negativeLimitTCA = gcnew CncCartDouble(&ValuePointertype->negativeLimitTCA);

			Temp_CncVector_aAxisCalibratedRotationPoint = gcnew CncVector(&ValuePointertype->aAxisCalibratedRotationPoint);
		}

	public:
		CncKinCfg(CNC_KIN_CFG * _CNC_KIN_CFG) :Managedstruct(_CNC_KIN_CFG)
		{
			NewClass();
		}
		CncKinCfg() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncKinCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncCartBool^ axesInUse   //True if axis in use
		{
			CncCartBool^ get()
			{
				Temp_CncCartBool_axesInUse->ValuePointertype = &ValuePointertype->axesInUse;
				return Temp_CncCartBool_axesInUse;
			}
			void set(CncCartBool^ Value)
			{

				ValuePointertype->axesInUse = Value->ValuePointertype[0];
				//Temp_CncCartBool_axesInUse = Value;
			}
		}
		property CncCartBool^ axesVisible    //True if visible (implies inUse)
		{
			CncCartBool^ get()
			{
				Temp_CncCartBool_axesVisible->ValuePointertype = &ValuePointertype->axesVisible;
				return Temp_CncCartBool_axesVisible;
			}
			void set(CncCartBool^ Value)
			{

				ValuePointertype->axesVisible = Value->ValuePointertype[0];
				//Temp_CncCartBool_axesVisible = Value;
			}
		}
		property CncJointBool^ jointInUse	//0-5 for 6 axes board. -1 if not connected
		{
			CncJointBool^ get()
			{
				Temp_CncJointBool_jointInUse->ValuePointertype = &ValuePointertype->jointInUse;
				return Temp_CncJointBool_jointInUse;
			}
			void set(CncJointBool^ Value)
			{

				ValuePointertype->jointInUse = Value->ValuePointertype[0];
				//Temp_CncJointBool_jointInUse = Value;
			}
		}
		property CncJointBool^ jointVisible//True if visible
		{
			CncJointBool^ get()
			{
				Temp_CncJointBool_jointVisible->ValuePointertype = &ValuePointertype->jointVisible;
				return Temp_CncJointBool_jointVisible;
			}
			void set(CncJointBool^ Value)
			{

				ValuePointertype->jointVisible = Value->ValuePointertype[0];
				//Temp_CncJointBool_jointVisible = Value;
			}
		}
		property CncJointBool^ jointIsSlave//True if a joint is slave
		{
			CncJointBool^ get()
			{
				Temp_CncJointBool_jointIsSlave->ValuePointertype = &ValuePointertype->jointIsSlave;
				return Temp_CncJointBool_jointIsSlave;
			}
			void set(CncJointBool^ Value)
			{

				ValuePointertype->jointIsSlave = Value->ValuePointertype[0];
				//Temp_CncJointBool_jointIsSlave = Value;
			}
		}
		property CncRotAxisOption aAxisOption
		{
			CncRotAxisOption get()
			{
				return (CncRotAxisOption)ValuePointertype->aAxisOption;
			}
			void set(CncRotAxisOption Value)
			{
				ValuePointertype->aAxisOption = (CNC_ROT_AXIS_OPTION)Value;
			}
		}
		property CncRotAxisOption bAxisOption
		{
			CncRotAxisOption get()
			{
				return (CncRotAxisOption)ValuePointertype->bAxisOption;
			}
			void set(CncRotAxisOption Value)
			{
				ValuePointertype->bAxisOption = (CNC_ROT_AXIS_OPTION)Value;
			}
		}
		property CncRotAxisOption cAxisOption
		{
			CncRotAxisOption get()
			{
				return (CncRotAxisOption)ValuePointertype->cAxisOption;
			}
			void set(CncRotAxisOption Value)
			{
				ValuePointertype->cAxisOption = (CNC_ROT_AXIS_OPTION)Value;
			}
		}
		/* for run time loading of user kins */
		property String^ kinematicsDLLName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->kinematicsDLLName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(CNC_MAX_PATH, Value, ValuePointertype->kinematicsDLLName);
			}
		}

		/* max values for Cartesian velocity, acceleration, AU  */
		property CncCartDouble^ maxCartesianVelocity
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_maxCartesianVelocity->ValuePointertype = &ValuePointertype->maxCartesianVelocity;
				return Temp_CncCartDouble_maxCartesianVelocity;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->maxCartesianVelocity = Value->ValuePointertype[0];
				//Temp_CncCartDouble_maxCartesianVelocity = Value;
			}
		}
		property CncCartDouble^ maxCartesianAcceleration
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_maxCartesianAcceleration->ValuePointertype = &ValuePointertype->maxCartesianAcceleration;
				return Temp_CncCartDouble_maxCartesianAcceleration;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->maxCartesianAcceleration = Value->ValuePointertype[0];
				//Temp_CncCartDouble_maxCartesianAcceleration = Value;
			}
		}
		property CncCartDouble^ positiveCartesianLimit
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_positiveCartesianLimit->ValuePointertype = &ValuePointertype->positiveCartesianLimit;
				return Temp_CncCartDouble_positiveCartesianLimit;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->positiveCartesianLimit = Value->ValuePointertype[0];
				//Temp_CncCartDouble_positiveCartesianLimit = Value;
			}
		}
		property CncCartDouble^ negativeCartesianLimit
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_negativeCartesianLimit->ValuePointertype = &ValuePointertype->negativeCartesianLimit;
				return Temp_CncCartDouble_negativeCartesianLimit;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->negativeCartesianLimit = Value->ValuePointertype[0];
				//Temp_CncCartDouble_negativeCartesianLimit = Value;
			}
		}

		/* max values for joint velocity, acceleration, AU  */
		property CncJointDouble^ maxJointVelocity
		{
			CncJointDouble^ get()
			{
				Temp_CncJointDouble_maxJointVelocity->ValuePointertype = &ValuePointertype->maxJointVelocity;
				return Temp_CncJointDouble_maxJointVelocity;
			}
			void set(CncJointDouble^ Value)
			{

				ValuePointertype->maxJointVelocity = Value->ValuePointertype[0];
				//Temp_CncJointDouble_maxJointVelocity = Value;
			}
		}
		property CncJointDouble^ maxJointAcceleration
		{
			CncJointDouble^ get()
			{
				Temp_CncJointDouble_maxJointAcceleration->ValuePointertype = &ValuePointertype->maxJointAcceleration;
				return Temp_CncJointDouble_maxJointAcceleration;
			}
			void set(CncJointDouble^ Value)
			{

				ValuePointertype->maxJointAcceleration = Value->ValuePointertype[0];
				//Temp_CncJointDouble_maxJointAcceleration = Value;
			}
		}
		property CncJointDouble^ positiveJointLimit
		{
			CncJointDouble^ get()
			{
				Temp_CncJointDouble_positiveJointLimit->ValuePointertype = &ValuePointertype->positiveJointLimit;
				return Temp_CncJointDouble_positiveJointLimit;
			}
			void set(CncJointDouble^ Value)
			{

				ValuePointertype->positiveJointLimit = Value->ValuePointertype[0];
				//Temp_CncJointDouble_positiveJointLimit = Value;
			}
		}
		property CncJointDouble^ negativeJointLimit
		{
			CncJointDouble^ get()
			{
				Temp_CncJointDouble_negativeJointLimit->ValuePointertype = &ValuePointertype->negativeJointLimit;
				return Temp_CncJointDouble_negativeJointLimit;
			}
			void set(CncJointDouble^ Value)
			{

				ValuePointertype->negativeJointLimit = Value->ValuePointertype[0];
				//Temp_CncJointDouble_negativeJointLimit = Value;
			}
		}

		/* allowed tool length with z completely down */
		property double zDownToolLength
		{
			double get()
			{
				return ValuePointertype->zDownToolLength;
			}
			void set(double Value)
			{
				ValuePointertype->zDownToolLength = Value;
			}
		}

		/* prohibited area for tool changer */
		property CncCartDouble^ positiveLimitTCA
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_positiveLimitTCA->ValuePointertype = &ValuePointertype->positiveLimitTCA;
				return Temp_CncCartDouble_positiveLimitTCA;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->positiveLimitTCA = Value->ValuePointertype[0];
				//Temp_CncCartDouble_positiveLimitTCA = Value;
			}
		}
		property CncCartDouble^ negativeLimitTCA
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble_negativeLimitTCA->ValuePointertype = &ValuePointertype->negativeLimitTCA;
				return Temp_CncCartDouble_negativeLimitTCA;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->negativeLimitTCA = Value->ValuePointertype[0];
				//Temp_CncCartDouble_negativeLimitTCA = Value;
			}
		}

		/* disable guard in Z if 1, enable if 0 */
		property int disableZToolCollisionGuard
		{
			int get()
			{
				return ValuePointertype->disableZToolCollisionGuard;
			}
			void set(int Value)
			{
				ValuePointertype->disableZToolCollisionGuard = Value;
			}
		}

		/* 4th axis milling parameters */
		/* 0 = not calibrated, work position 0 is used as rotation point */
		property int  aAxisRotationPointIsCalibrated
		{
			int get()
			{
				return ValuePointertype->aAxisRotationPointIsCalibrated;
			}
			void set(int Value)
			{
				ValuePointertype->aAxisRotationPointIsCalibrated = Value;
			}
		}
		property CncVector^ aAxisCalibratedRotationPoint
		{
			CncVector^ get()
			{
				Temp_CncVector_aAxisCalibratedRotationPoint->ValuePointertype = &ValuePointertype->aAxisCalibratedRotationPoint;
				return Temp_CncVector_aAxisCalibratedRotationPoint;
			}
			void set(CncVector^ Value)
			{

				ValuePointertype->aAxisCalibratedRotationPoint = Value->ValuePointertype[0];
				//Temp_CncVector_aAxisCalibratedRotationPoint = Value;
			}

		}

		/* the calibrated radius for milling  on the cylinder*/
		property int aAxisCylinderRadiusIsCalibrated
		{
			int get()
			{
				return ValuePointertype->aAxisCylinderRadiusIsCalibrated;
			}
			void set(int Value)
			{
				ValuePointertype->aAxisCylinderRadiusIsCalibrated = Value;
			}
		}
		property double  aAxisCalibratedCilinderRadius
		{
			double get()
			{
				return ValuePointertype->aAxisCalibratedCilinderRadius;
			}
			void set(double Value)
			{
				ValuePointertype->aAxisCalibratedCilinderRadius = Value;
			}
		}

		/* linear delta robot parameters */
		property double linDeltaArmLength
		{
			double get()
			{
				return ValuePointertype->linDeltaArmLength;
			}
			void set(double Value)
			{
				ValuePointertype->linDeltaArmLength = Value;
			}
		}
		property double linDeltaRadius
		{
			double get()
			{
				return ValuePointertype->linDeltaRadius;
			}
			void set(double Value)
			{
				ValuePointertype->linDeltaRadius = Value;
			}
		}
		property double linDeltaSafetyRadius
		{
			double get()
			{
				return ValuePointertype->linDeltaSafetyRadius;
			}
			void set(double Value)
			{
				ValuePointertype->linDeltaSafetyRadius = Value;
			}
		}

		/* machine type, copy from system config */
		property CncMachineType  machineType
		{
			CncMachineType get()
			{
				return (CncMachineType)ValuePointertype->machineType;
			}
			void set(CncMachineType Value)
			{
				ValuePointertype->machineType = (CNC_MACHINE_TYPE)Value;
			}
		}
		property int userOutputStartVariable
		{
			int get()
			{
				return ValuePointertype->userOutputStartVariable;
			}
			void set(int Value)
			{
				ValuePointertype->userOutputStartVariable = Value;
			}
		}
		property int userOutputNumVariables
		{
			int get()
			{
				return ValuePointertype->userOutputNumVariables;
			}
			void set(int Value)
			{
				ValuePointertype->userOutputNumVariables = Value;
			}
		}
	};
	public ref class CncKinStatus :public Managedstruct<CNC_KIN_STATUS>//pointer add
	{
	private:

		CncVector^ Temp_m_activeToolOffset = nullptr;
		CncOffsetAndPlane^ Temp_m_offsetAndPlane = nullptr;
		CncKinCfg^ Temp_m_actConfig = nullptr;
		CncTanKnifeStatus^ Temp_m_tanknifeSts = nullptr;
		void NewClass()
		{
			Temp_m_activeToolOffset = gcnew CncVector(&ValuePointertype->m_activeToolOffset);
			Temp_m_offsetAndPlane = gcnew CncOffsetAndPlane(&ValuePointertype->m_offsetAndPlane);
			Temp_m_actConfig = gcnew CncKinCfg(&ValuePointertype->m_actConfig);
			Temp_m_tanknifeSts = gcnew CncTanKnifeStatus(&ValuePointertype->m_tanknifeSts);
		}
	public:
		CncKinStatus(CNC_KIN_STATUS  *_KIN_STATUS) :Managedstruct(_KIN_STATUS)
		{
			NewClass();
		}
		CncKinStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncKinStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncVector^ m_activeToolOffset//; //Always active tool value, not related to G43/G49
		{
			CncVector^ get()
			{
				Temp_m_activeToolOffset->ValuePointertype = &ValuePointertype->m_activeToolOffset;
				return Temp_m_activeToolOffset;
			}
		
			void set(CncVector^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_VECTOR>(Value->ValuePointertype[0], &ValuePointertype->m_activeToolOffset, LockOverrideDataInPointer);
			}

		}
		property CncKineMaticsType  m_kinType
		{
			CncKineMaticsType get()
			{
				return (CncKineMaticsType)ValuePointertype->m_kinType;
			}
		
			void set(CncKineMaticsType Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_KINEMATICS_TYPE>((CNC_KINEMATICS_TYPE)Value, &ValuePointertype->m_kinType, LockOverrideDataInPointer);
			}

		}
		property String^ m_version//[CNC_MAX_NAME_LENGTH]; //Read from DLL
		{
			String^get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->m_version);
			}
		
			void set(String^ Value)
			{
				InternalCncMethods::SetStringPropertyIfUnlocked(Value,ValuePointertype->m_version, sizeof(ValuePointertype->m_version), LockOverrideDataInPointer);
			}

		}

		property int m_kinActive   //1 of active
		{
			int get()
			{
				return ValuePointertype->m_kinActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->m_kinActive, LockOverrideDataInPointer);
			}

		}
		property CncOffsetAndPlane^ m_offsetAndPlane
		{
			CncOffsetAndPlane^ get()
			{
				Temp_m_offsetAndPlane->ValuePointertype = &ValuePointertype->m_offsetAndPlane;
				return Temp_m_offsetAndPlane;
			}
		
			void set(CncOffsetAndPlane^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_OFFSET_AND_PLANE>(Value->ValuePointertype[0], &ValuePointertype->m_offsetAndPlane, LockOverrideDataInPointer);
			}

		}
		property CncKinCfg^ m_actConfig
		{
			CncKinCfg^ get()
			{
				Temp_m_actConfig->ValuePointertype = &ValuePointertype->m_actConfig;
				return Temp_m_actConfig;
			}
		
			void set(CncKinCfg^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_KIN_CFG>(Value->ValuePointertype[0], &ValuePointertype->m_actConfig, LockOverrideDataInPointer);
			}

		}
		property CncTanKnifeStatus^ m_tanknifeSts
		{
			CncTanKnifeStatus^get()
			{
				Temp_m_tanknifeSts->ValuePointertype = &ValuePointertype->m_tanknifeSts;
				return Temp_m_tanknifeSts;
			}
		
			void set(CncTanKnifeStatus^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_TAN_KNIFE_STATUS>(Value->ValuePointertype[0], &ValuePointertype->m_tanknifeSts, LockOverrideDataInPointer);
			}

		}
		property int m_mcaActive
		{
			int get()
			{
				return ValuePointertype->m_mcaActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->m_mcaActive, LockOverrideDataInPointer);
			}

		}
		property int m_tcaActive
		{
			int get()
			{
				return ValuePointertype->m_tcaActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->m_tcaActive, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncUiCfg :public Managedstruct<CNC_UI_CFG>
	{
	private:
		array<CncUserButton^>^ Temp_extendedUserButtons = nullptr;
		void NewClass()
		{
			Temp_extendedUserButtons = gcnew array<CncUserButton^>(CNC_MAX_USER_BUTTONS);
		}
	public:
		CncUiCfg(CNC_UI_CFG * _CNC_UI_CFG) :Managedstruct(_CNC_UI_CFG)
		{
			NewClass();
		}
		CncUiCfg() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncUiCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* The language -1=eng, 0=duits. 1=ned ... etc */
		property CncLangT language
		{
			CncLangT get()
			{
				return (CncLangT)ValuePointertype->language;
			}
			void set(CncLangT Value)
			{
				ValuePointertype->language = (CNC_LANG_T)Value;
			}
		}

		/* If 1 GUI uses OpenGL */
		property int useOpenGL
		{
			int get()
			{
				return ValuePointertype->useOpenGL;
			}
			void set(int Value)
			{
				ValuePointertype->useOpenGL = Value;
			}
		}

		/* Save memory on RT view */
		property int OpenGLRTMaxLines
		{
			int get()
			{
				return ValuePointertype->OpenGLRTMaxLines;
			}
			void set(int Value)
			{
				ValuePointertype->OpenGLRTMaxLines = Value;
			}
		}

		/* OpenGL Pen Size */
		property double openGlPenScaleFactor
		{
			double get()
			{
				return ValuePointertype->openGlPenScaleFactor;
			}
			void set(double Value)
			{
				ValuePointertype->openGlPenScaleFactor = Value;
			}
		}

		/* grid scale, standard grid size is 50mm, with scale 2 it becomes 100 etc*/
		property double gridScaleFactor
		{
			double get()
			{
				return ValuePointertype->gridScaleFactor;
			}
			void set(double Value)
			{
				ValuePointertype->gridScaleFactor = Value;
			}
		}

		/* OpenGL shows orthogonal, no perspective */
		property int orthogonalView
		{
			int get()
			{
				return ValuePointertype->orthogonalView;
			}
			void set(int Value)
			{
				ValuePointertype->orthogonalView = Value;
			}
		}

		/* OpenGL background grey scale color 0-255 */
		property int backGroundColor {
			int get()
			{
				return ValuePointertype->backGroundColor;
			}
			void set(int Value)
			{
				ValuePointertype->backGroundColor = Value;
			}
		}

		/* Show G0 movements or hide them */
		property int showG0MovesInGraphic
		{
			int get()
			{
				return ValuePointertype->showG0MovesInGraphic;
			}
			void set(int Value)
			{
				ValuePointertype->showG0MovesInGraphic = Value;
			}
		}

		/* -1 rotates inversed, 1 rotates normally */
		property int rotationDirectionAAxis {
			int get()
			{
				return ValuePointertype->rotationDirectionAAxis;
			}
			void set(int Value)
			{
				ValuePointertype->rotationDirectionAAxis = Value;
			}
		}

		/* show maximized */
		property int restoreWindowPosition
		{
			int get()
			{
				return ValuePointertype->restoreWindowPosition;
			}
			void set(int Value)
			{
				ValuePointertype->restoreWindowPosition = Value;
			}
		}

		/* Editor use for edit .cnc files files */
		property String^ favoriteEditor
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->favoriteEditor);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->favoriteEditor), Value, ValuePointertype->favoriteEditor); //ValuePointertype->restoreWindowPosition = Value;
			}
		}

		/* Directory where user GUI icons are loaded from */
		property String^ iconDirectory
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->iconDirectory);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->iconDirectory), Value, ValuePointertype->iconDirectory); //ValuePointertype->restoreWindowPosition = Value;
			}
		}

		/* User logo file name */
		property String^ logoFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->logoFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->logoFileName), Value, ValuePointertype->logoFileName); //ValuePointertype->restoreWindowPosition = Value;
			}
		}

		/* Password for entering setup page */
		property String^ setupPassword//[80]
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->setupPassword);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->setupPassword), Value, ValuePointertype->setupPassword); //ValuePointertype->restoreWindowPosition = Value;
			}
		}


		/* id 1, no pop up dialog while zeroing. */
		property int simpleZeroing
		{
			int get()
			{
				return ValuePointertype->simpleZeroing;
			}
			void set(int Value)
			{
				ValuePointertype->simpleZeroing = Value;
			}
		}
		property int useG10L20ForZeroing
		{
			int get()
			{
				return ValuePointertype->useG10L20ForZeroing;
			}
			void set(int Value)
			{
				ValuePointertype->useG10L20ForZeroing = Value;
			}
		}

		/* The GUI automatically loads and runs this job file */
		property String^  watchLoadFileName
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->watchLoadFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->watchLoadFileName), Value, ValuePointertype->watchLoadFileName); //ValuePointertype->restoreWindowPosition = Value;
			}
		}
		property int  watchFileChanged
		{
			int get()
			{
				return ValuePointertype->watchFileChanged;
			}
			void set(int Value)
			{
				ValuePointertype->watchFileChanged = Value;
			}
		}
		property int  watchAutoLoad
		{
			int get()
			{
				return ValuePointertype->watchAutoLoad;
			}
			void set(int Value)
			{
				ValuePointertype->watchAutoLoad = Value;
			}
		}
		property int  watchAutoRun
		{
			int get()
			{
				return ValuePointertype->watchAutoRun;
			}
			void set(int Value)
			{
				ValuePointertype->watchAutoRun = Value;
			}
		}
		property int  watchAutoInterval
		{
			int get()
			{
				return ValuePointertype->watchAutoInterval;
			}
			void set(int Value)
			{
				ValuePointertype->watchAutoInterval = Value;
			}
		}
		/* show terms if not already shown */
		property int showTerms
		{
			int get()
			{
				return ValuePointertype->showTerms;
			}
			void set(int Value)
			{
				ValuePointertype->showTerms = Value;
			}
		}

		/* show startup screen */
		property int showStartupScreen
		{
			int get()
			{
				return ValuePointertype->showStartupScreen;
			}
			void set(int Value)
			{
				ValuePointertype->showStartupScreen = Value;
			}
		}

		/*show graph buttons for zooming etc */
		property int showGraphZoomButtons
		{
			int get()
			{
				return ValuePointertype->showGraphZoomButtons;
			}
			void set(int Value)
			{
				ValuePointertype->showGraphZoomButtons = Value;
			}
		}

		/* for machines with moving bed */
		property int invertJogKeysX
		{
			int get()
			{
				return ValuePointertype->invertJogKeysX;
			}
			void set(int Value)
			{
				ValuePointertype->invertJogKeysX = Value;
			}
		}
		property int invertJogKeysY
		{
			int get()
			{
				return ValuePointertype->invertJogKeysY;
			}
			void set(int Value)
			{
				ValuePointertype->invertJogKeysY = Value;
			}
		}
		property int invertJogKeysZ
		{
			int get()
			{
				return ValuePointertype->invertJogKeysZ;
			}
			void set(int Value)
			{
				ValuePointertype->invertJogKeysZ = Value;
			}
		}

		/* +X is backward key and +Y is left, so this is a key/button rotation of 90 degree */
		property int rotateXYJogkeys90
		{
			int get()
			{
				return ValuePointertype->rotateXYJogkeys90;
			}
			void set(int Value)
			{
				ValuePointertype->rotateXYJogkeys90 = Value;
			}
		}

		/* Only jogging by the JogPad, no longer keyboard */
		property int disableKeyboardJogging
		{
			int get()
			{
				return ValuePointertype->disableKeyboardJogging;
			}
			void set(int Value)
			{
				ValuePointertype->disableKeyboardJogging = Value;
			}
		}

		/* use old in stead of new jog step sizes */
		property int useOldJogStepSize
		{
			int get()
			{
				return ValuePointertype->useOldJogStepSize;
			}
			void set(int Value)
			{
				ValuePointertype->useOldJogStepSize = Value;
			}
		}

		/* after keyboardTimeOut UI will stop jogging */
		property double keyBoardTimeOut
		{
			double get()
			{
				return ValuePointertype->keyBoardTimeOut;
			}
			void set(double Value)
			{
				ValuePointertype->keyBoardTimeOut = Value;
			}
		}

		/* correction factor for job time estimation */
		property double timeEstimateFactor
		{
			double get()
			{
				return ValuePointertype->timeEstimateFactor;
			}
			void set(double Value)
			{
				ValuePointertype->timeEstimateFactor = Value;
			}
		}

		/* adjust estimation runtime based on average speed and distToGo */
		property int adjustEstimation
		{
			int get()
			{
				return ValuePointertype->adjustEstimation;
			}
			void set(int Value)
			{
				ValuePointertype->adjustEstimation = Value;
			}
		}

		/* possibility to hide function key's */
		property int showM7key
		{
			int get()
			{
				return ValuePointertype->showM7key;
			}
			void set(int Value)
			{
				ValuePointertype->showM7key = Value;
			}
		}
		property int showM8key
		{
			int get()
			{
				return ValuePointertype->showM8key;
			}
			void set(int Value)
			{
				ValuePointertype->showM8key = Value;
			}
		}
		property int showAux1Key
		{
			int get()
			{
				return ValuePointertype->showAux1Key;
			}
			void set(int Value)
			{
				ValuePointertype->showAux1Key = Value;
			}
		}
		property int showHomeToZero
		{
			int get()
			{
				return ValuePointertype->showHomeToZero;
			}
			void set(int Value)
			{
				ValuePointertype->showHomeToZero = Value;
			}
		}
		property int showSpindleOnButton
		{
			int get()
			{
				return ValuePointertype->showSpindleOnButton;
			}
			void set(int Value)
			{
				ValuePointertype->showSpindleOnButton = Value;
			}
		}
		property int showTrafficButton
		{
			int get()
			{
				return ValuePointertype->showTrafficButton;
			}
			void set(int Value)
			{
				ValuePointertype->showTrafficButton = Value;
			}
		}
		property int showStartButton
		{
			int get()
			{
				return ValuePointertype->showStartButton;
			}
			void set(int Value)
			{
				ValuePointertype->showStartButton = Value;
			}
		}
		property int showZeroButtons
		{
			int get()
			{
				return ValuePointertype->showZeroButtons;
			}
			void set(int Value)
			{
				ValuePointertype->showZeroButtons = Value;
			}
		}
		property int showZeroButtonC
		{
			int get()
			{
				return ValuePointertype->showZeroButtonC;
			}
			void set(int Value)
			{
				ValuePointertype->showZeroButtonC = Value;
			}
		}
		property int showPlasmaMinButton
		{
			int get()
			{
				return ValuePointertype->showPlasmaMinButton;
			}
			void set(int Value)
			{
				ValuePointertype->showPlasmaMinButton = Value;
			}
		}

		property int showLeftUser11Button
		{
			int get()
			{
				return ValuePointertype->showLeftUser11Button;
			}
			void set(int Value)
			{
				ValuePointertype->showLeftUser11Button = Value;
			}
		}
		property int showLeftUser12Button
		{
			int get()
			{
				return ValuePointertype->showLeftUser12Button;
			}
			void set(int Value)
			{
				ValuePointertype->showLeftUser12Button = Value;
			}
		}
		property int showLeftUser13Button
		{
			int get()
			{
				return ValuePointertype->showLeftUser13Button;
			}
			void set(int Value)
			{
				ValuePointertype->showLeftUser13Button = Value;
			}
		}
		property int showLeftUser14Button
		{
			int get()
			{
				return ValuePointertype->showLeftUser14Button;
			}
			void set(int Value)
			{
				ValuePointertype->showLeftUser14Button = Value;
			}
		}
		property int showLeftUser15Button
		{
			int get()
			{
				return ValuePointertype->showLeftUser15Button;
			}
			void set(int Value)
			{
				ValuePointertype->showLeftUser15Button = Value;
			}
		}

		property int showCoordinatesTab
		{
			int get()
			{
				return ValuePointertype->showCoordinatesTab;
			}
			void set(int Value)
			{
				ValuePointertype->showCoordinatesTab = Value;
			}
		}
		property int showProgramTab
		{
			int get()
			{
				return ValuePointertype->showProgramTab;
			}
			void set(int Value)
			{
				ValuePointertype->showProgramTab = Value;
			}
		}
		property int showToolTab
		{
			int get()
			{
				return ValuePointertype->showToolTab;
			}
			void set(int Value)
			{
				ValuePointertype->showToolTab = Value;
			}
		}
		property int showVariablesTab
		{
			int get()
			{
				return ValuePointertype->showVariablesTab;
			}
			void set(int Value)
			{
				ValuePointertype->showVariablesTab = Value;
			}
		}
		property int showIOTab
		{
			int get()
			{
				return ValuePointertype->showIOTab;
			}
			void set(int Value)
			{
				ValuePointertype->showIOTab = Value;
			}
		}
		property int showFifoSize
		{
			int get()
			{
				return ValuePointertype->showFifoSize;
			}
			void set(int Value)
			{
				ValuePointertype->showFifoSize = Value;
			}
		}
		property int showServiceTab
		{
			int get()
			{
				return ValuePointertype->showServiceTab;
			}
			void set(int Value)
			{
				ValuePointertype->showServiceTab = Value;
			}
		}
		property int showUtilTab
		{
			int get()
			{
				return ValuePointertype->showUtilTab;
			}
			void set(int Value)
			{
				ValuePointertype->showUtilTab = Value;
			}
		}

		property int showEngrave
		{
			int get()
			{
				return ValuePointertype->showEngrave;
			}
			void set(int Value)
			{
				ValuePointertype->showEngrave = Value;
			}
		}
		property int showDrill
		{
			int get()
			{
				return ValuePointertype->showDrill;
			}
			void set(int Value)
			{
				ValuePointertype->showDrill = Value;
			}
		}
		property int showOffset
		{
			int get()
			{
				return ValuePointertype->showOffset;
			}
			void set(int Value)
			{
				ValuePointertype->showOffset = Value;
			}
		}
		property int showPocket
		{
			int get()
			{
				return ValuePointertype->showPocket;
			}
			void set(int Value)
			{
				ValuePointertype->showPocket = Value;
			}
		}
		property int showICP
		{
			int get()
			{
				return ValuePointertype->showICP;
			}
			void set(int Value)
			{
				ValuePointertype->showICP = Value;
			}
		}
		property int showWCCameraOption
		{
			int get()
			{
				return ValuePointertype->showWCCameraOption;
			}
			void set(int Value)
			{
				ValuePointertype->showWCCameraOption = Value;
			}
		}

		property int clickDROIsG0
		{
			int get()
			{
				return ValuePointertype->clickDROIsG0;
			}
			void set(int Value)
			{
				ValuePointertype->clickDROIsG0 = Value;
			}
		}

		property int windowRectLeft
		{
			int get()
			{
				return ValuePointertype->windowRectLeft;
			}
			void set(int Value)
			{
				ValuePointertype->windowRectLeft = Value;
			}
		}
		property int windowRectTop
		{
			int get()
			{
				return ValuePointertype->windowRectTop;
			}
			void set(int Value)
			{
				ValuePointertype->windowRectTop = Value;
			}
		}
		property int windowRectRight
		{
			int get()
			{
				return ValuePointertype->windowRectRight;
			}
			void set(int Value)
			{
				ValuePointertype->windowRectRight = Value;
			}
		}
		property int windowRectBottom
		{
			int get()
			{
				return ValuePointertype->windowRectBottom;
			}
			void set(int Value)
			{
				ValuePointertype->windowRectBottom = Value;
			}
		}
		property int windowRestoreFlags
		{
			int get()
			{
				return ValuePointertype->windowRestoreFlags;
			}
			void set(int Value)
			{
				ValuePointertype->windowRestoreFlags = Value;
			}
		}
		property int windowRestoreShowCmd
		{
			int get()
			{
				return ValuePointertype->windowRestoreShowCmd;
			}
			void set(int Value)
			{
				ValuePointertype->windowRestoreShowCmd = Value;
			}
		}

		/* for spindle visualisation */
		/* show analog input (power) or PWM value at programmed spindle speed */
		/* 0 =  prog speed, 1 = PWM value, 2 = analogIn1, 3 = analogin2, 4 is analog in 3 */
		property int showInProgSpeed
		{
			int get()
			{
				return ValuePointertype->showInProgSpeed;
			}
			void set(int Value)
			{
				ValuePointertype->showInProgSpeed = Value;
			}
		}
		property double showInProgSpeedAnaMulFactor
		{
			double get()
			{
				return ValuePointertype->showInProgSpeedAnaMulFactor;
			}
			void set(double Value)
			{
				ValuePointertype->showInProgSpeedAnaMulFactor = Value;
			}
		}

		/* show feed in mm/sec */
		property int feedUnitsMMPerSecond
		{
			int get()
			{
				return ValuePointertype->feedUnitsMMPerSecond;
			}
			void set(int Value)
			{
				ValuePointertype->feedUnitsMMPerSecond = Value;
			}
		}

		/* show position units in 0.0001 format for mm mode */
		property int mmMode4digits
		{
			int get()
			{
				return ValuePointertype->mmMode4digits;
			}
			void set(int Value)
			{
				ValuePointertype->mmMode4digits = Value;
			}
		}

		/* feed override step size when pressing +/- FeedOverride buttons */
		property double feedOVStepSize
		{
			double get()
			{
				return ValuePointertype->feedOVStepSize;
			}
			void set(double Value)
			{
				ValuePointertype->feedOVStepSize = Value;
			}
		}

		/* start XHC connect automatically if option enabled*/
		/* v4.3.25
		property int autoStartXHCPendant
		{
			int get()
			{
				return ValuePointertype->autoStartXHCPendant;
			}
			void set(int Value)
			{
				ValuePointertype->autoStartXHCPendant = Value;
			}
		}
		*/

		/* allow jogging with interpreter dialog */
		property int allowJoggingWithDlg
		{
			int get()
			{
				return ValuePointertype->allowJoggingWithDlg;
			}
			void set(int Value)
			{
				ValuePointertype->allowJoggingWithDlg = Value;
			}
		}
		/* Show something else in place of the software version in the GUI */
		property String^ overrideVersionText//[CNC_MAX_NAME_LENGTH];
		{
			String^ get()
			{

				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->overrideVersionText);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->overrideVersionText), Value, ValuePointertype->overrideVersionText);
			}
		}

		/* Qr scanner, set to 1..99 for COM1 .. COM99, 0 for no function */
		property int QrScannerComportNumber
		{
			int get()
			{
				return ValuePointertype->QrScannerComportNumber;
			}
			void set(int Value)
			{
				ValuePointertype->QrScannerComportNumber = Value;
			}
		}
		property String^ jobFolder//[CNC_MAX_PATH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->jobFolder);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->jobFolder), Value, ValuePointertype->jobFolder);
			}
		}
		/* switch off rendering is a debugging option */
		property int autoRenderAfterLoadingGCode
		{
			int get()
			{
				return ValuePointertype->autoRenderAfterLoadingGCode;
			}
			void set(int Value)
			{
				ValuePointertype->autoRenderAfterLoadingGCode = Value;
			}
		}
		property int useExtendedUserButtons
		{
			int get()
			{
				return ValuePointertype->useExtendedUserButtons;
			}
			void set(int Value)
			{
				ValuePointertype->useExtendedUserButtons = Value;
			}
		}
		property array<CncUserButton^>^ extendedUserButtons//nieuw(Testen)
		{
			array<CncUserButton^>^ get()
			{
				for (int i = 0; i < Temp_extendedUserButtons->Length; i++)
				{
					if (Temp_extendedUserButtons[i] == nullptr)
					{
						Temp_extendedUserButtons[i] = gcnew CncUserButton(&ValuePointertype->extendedUserButtons[i]);
					}
					else
					{
						Temp_extendedUserButtons[i]->ValuePointertype = &ValuePointertype->extendedUserButtons[i];
					}
				}

				return Temp_extendedUserButtons;
			}
			void set(array<CncUserButton^>^ Value)
			{
				if (Value->Length == Temp_extendedUserButtons->Length)
				{
					for (int i = 0; i < Value->Length; i++)
					{
						ValuePointertype->extendedUserButtons[i] = Value[i]->ValuePointertype[0];
					}
				}
				//ValuePointertype->extendedUserButtons = Value;
			}
		}

	};
	public ref class CncThcCfg :public Managedstruct<CNC_THC_CFG>
	{
	private:
		CncThcProcessParameters^ Temp_CncThcProcessParameters = nullptr;
		void NewClass()
		{
			Temp_CncThcProcessParameters = gcnew CncThcProcessParameters(&ValuePointertype->processPars);
		}
	public:
		CncThcCfg(CNC_THC_CFG * _CNC_THC_CFG) :Managedstruct(_CNC_THC_CFG)
		{
			NewClass();
		}
		CncThcCfg() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncThcCfg^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* default process parameters for THC */
		property CncThcProcessParameters^ processPars
		{
			CncThcProcessParameters^ get()
			{
				Temp_CncThcProcessParameters->ValuePointertype = &ValuePointertype->processPars;
				return Temp_CncThcProcessParameters;
			}
			void set(CncThcProcessParameters^ Value)
			{

				ValuePointertype->processPars = Value->ValuePointertype[0];
				//Temp_CncThcProcessParameters = Value;
			}
		}

		/* ADC 10 bit conversion to THC voltage		  */
		/* Volt = adcMulFactor * adcValue + adcOffset */
		property double adcMulFactor
		{
			double get()
			{
				return ValuePointertype->adcMulFactor;
			}
			void set(double Value)
			{
				ValuePointertype->adcMulFactor = Value;
			}
		}
		property double adcOffset
		{
			double get()
			{
				return ValuePointertype->adcOffset;
			}
			void set(double Value)
			{
				ValuePointertype->adcOffset = Value;
			}
		}
	
		property CncIoId plasmaAnalogInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->plasmaAnalogInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->plasmaAnalogInputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId plasmaExternalZUPInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->plasmaExternalZUPInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->plasmaExternalZUPInputPortID = (CNC_IO_ID)Value;
			}
		}
		property CncIoId plasmaExternalZDownInputPortID
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->plasmaExternalZDownInputPortID;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->plasmaExternalZDownInputPortID = (CNC_IO_ID)Value;
			}
		}
		property int useExternalUpDownControl
		{
			int get()
			{
				return ValuePointertype->useExternalUpDownControl;
			}
			void set(int Value)
			{
				ValuePointertype->useExternalUpDownControl = Value;
			}
		}

		/*not exist in version 4.3.22
		property int allowTHCWithoutM3M4
		{
			int get()
			{
				return ValuePointertype->allowTHCWithoutM3M4;
			}
			void set(int Value)
			{
				ValuePointertype->allowTHCWithoutM3M4 = Value;
			}
		}
		property int allowTHCWithoutPlasmaMachine
		{
			int get()
			{
				return ValuePointertype->allowTHCWithoutPlasmaMachine;
			}
			void set(int Value)
			{
				ValuePointertype->allowTHCWithoutPlasmaMachine = Value;
			}
		}
		*/


	};
	public ref class Cnc3DPrintingConfig :public Managedstruct<CNC_3DPRINTING_CONFIG>
	{
	private:
		Cnc3DPrintingTempPidPars^ Temp_extruderPIDPars = nullptr;
		Cnc3DPrintingTempCalibrationTable^ Temp_extruderVoltTempTable = nullptr;
		Cnc3DPrintingTempPidPars^ Temp_heatBedPIDPars = nullptr;
		Cnc3DPrintingTempCalibrationTable^ Temp_heatBedVoltTempTable = nullptr;
		void NewClass()
		{
			Temp_extruderPIDPars = gcnew Cnc3DPrintingTempPidPars(&ValuePointertype->extruderPIDPars);
			Temp_extruderVoltTempTable = gcnew Cnc3DPrintingTempCalibrationTable(&ValuePointertype->extruderVoltTempTable);
			Temp_heatBedPIDPars = gcnew Cnc3DPrintingTempPidPars(&ValuePointertype->heatBedPIDPars);
			Temp_heatBedVoltTempTable = gcnew Cnc3DPrintingTempCalibrationTable(&ValuePointertype->heatBedVoltTempTable);
		}
	public:
		Cnc3DPrintingConfig(CNC_3DPRINTING_CONFIG * _CNC_3DPRINTING_CONFIG) :Managedstruct(_CNC_3DPRINTING_CONFIG)
		{
			NewClass();
		}
		Cnc3DPrintingConfig() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(Cnc3DPrintingConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* main extruder parameters */

		property Cnc3DPrintingTempPidPars^ extruderPIDPars
		{
			Cnc3DPrintingTempPidPars^ get()
			{
				Temp_extruderPIDPars->ValuePointertype = &ValuePointertype->extruderPIDPars;
				return Temp_extruderPIDPars;
			}
			void set(Cnc3DPrintingTempPidPars^ Value)
			{

				ValuePointertype->extruderPIDPars = Value->ValuePointertype[0];
				//Temp_extruderPIDPars = Value;
			}
		}
		property Cnc3DPrintingTempCalibrationTable^ extruderVoltTempTable
		{
			Cnc3DPrintingTempCalibrationTable^ get()
			{
				Temp_extruderVoltTempTable->ValuePointertype = &ValuePointertype->extruderVoltTempTable;
				return Temp_extruderVoltTempTable;
			}
			void set(Cnc3DPrintingTempCalibrationTable^ Value)
			{

				ValuePointertype->extruderVoltTempTable = Value->ValuePointertype[0];
				//Temp_extruderVoltTempTable = Value;
			}
		}
		property String^ extruderVoltTempTableFileName// [CNC_MAX_PATH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->extruderVoltTempTableFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->extruderVoltTempTableFileName), Value, ValuePointertype->extruderVoltTempTableFileName);
			}
		}
		/* heat bed parameters */
		property Cnc3DPrintingTempPidPars^ heatBedPIDPars
		{
			Cnc3DPrintingTempPidPars^ get()
			{
				Temp_heatBedPIDPars->ValuePointertype = &ValuePointertype->heatBedPIDPars;
				return Temp_heatBedPIDPars;
			}
			void set(Cnc3DPrintingTempPidPars^ Value)
			{
				//Temp_heatBedPIDPars = Value;
				ValuePointertype->heatBedPIDPars = Value->ValuePointertype[0];
			}
		}

		property Cnc3DPrintingTempCalibrationTable^ heatBedVoltTempTable
		{
			Cnc3DPrintingTempCalibrationTable^ get()
			{
				Temp_heatBedVoltTempTable->ValuePointertype = &ValuePointertype->heatBedVoltTempTable;
				return Temp_heatBedVoltTempTable;
			}
			void set(Cnc3DPrintingTempCalibrationTable^ Value)
			{

				ValuePointertype->heatBedVoltTempTable = Value->ValuePointertype[0];
				//Temp_heatBedVoltTempTable = Value;
			}
		}
		property String^ heatBedVoltTempTableFileName// e[CNC_MAX_PATH];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->heatBedVoltTempTableFileName);
			}
			void set(String^ Value)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(sizeof(ValuePointertype->heatBedVoltTempTableFileName), Value, ValuePointertype->heatBedVoltTempTableFileName);
			}
		}
		property CncIoId extruderPWMPort
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->extruderPWMPort;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->extruderPWMPort = (CNC_IO_ID)Value;
			}
		}
		property CncIoId heatBedPWMPort
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->heatBedPWMPort;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->heatBedPWMPort = (CNC_IO_ID)Value;
			}
		}
		property CncIoId workpieceFanPWMPort
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->workpieceFanPWMPort;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->workpieceFanPWMPort = (CNC_IO_ID)Value;
			}
		}
		property CncIoId extruderTempInPort
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->extruderTempInPort;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->extruderTempInPort = (CNC_IO_ID)Value;
			}
		}
		property CncIoId heatBedTempInPort
		{
			CncIoId get()
			{
				return (CncIoId)ValuePointertype->heatBedTempInPort;
			}
			void set(CncIoId Value)
			{
				ValuePointertype->heatBedTempInPort = (CNC_IO_ID)Value;
			}
		}
		/* Workpiece cooling parameters */
		property float workPieceFanStandbyPower
		{
			float get()
			{
				return ValuePointertype->workPieceFanStandbyPower;
			}
			void set(float Value)
			{
				ValuePointertype->workPieceFanStandbyPower = Value;
			}
		}

		/* below this power the fan is switched off */
		property float workPieceFanPowerTreshold
		{
			float get()
			{
				return ValuePointertype->workPieceFanPowerTreshold;
			}
			void set(float Value)
			{
				ValuePointertype->workPieceFanPowerTreshold = Value;
			}
		}
		/* kik start time with 100% PWM when starting the FAN */
		property float workpieceFanStartTimeSeconds
		{
			float get()
			{
				return ValuePointertype->workpieceFanStartTimeSeconds;
			}
			void set(float Value)
			{
				ValuePointertype->workpieceFanStartTimeSeconds = Value;
			}
		}

		/* translate g0 to g1 if 1 */
		property int translateG0ToG1
		{
			int get()
			{
				return ValuePointertype->translateG0ToG1;
			}
			void set(int Value)
			{
				ValuePointertype->translateG0ToG1 = Value;
			}
		}
	};
	public ref class CncRunningStatus :public Managedstruct<CNC_RUNNING_STATUS>
	{

	private:
		array<int>^ _ActiveMCodes = nullptr;
		array<int>^ _ActiveGCodes = nullptr;
		array<double>^ _ActiveGSettings = nullptr;
		CncLogMessage^  Temp_lastIntError = nullptr;
		void NewClass()
		{
			Temp_lastIntError = gcnew CncLogMessage(&ValuePointertype->lastIntError);
			_ActiveMCodes = gcnew array<int>(sizeof(ValuePointertype->ActiveGCodes) / SizeOfintx32);
			_ActiveGCodes = gcnew array<int >(sizeof(ValuePointertype->ActiveGCodes) / SizeOfintx32);
			_ActiveGSettings = gcnew array<double>(sizeof(ValuePointertype->ActiveGSettings) / SizeOfdoublex32);
		}
	public:
		CncRunningStatus(CNC_RUNNING_STATUS * _CNC_RUNNING_STATUS) :Managedstruct(_CNC_RUNNING_STATUS)
		{
			NewClass();
		}
		CncRunningStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncRunningStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}


		/* state of the interpreter/execution task */
		property CncIeState state
		{
			CncIeState get()
			{
				return (CncIeState)ValuePointertype->state;
			}
		
			void set(CncIeState Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_IE_STATE>((CNC_IE_STATE)Value, &ValuePointertype->state, LockOverrideDataInPointer);
			}

		}

		/* active G-code for each of the G-code groups, the value contains the active g-code in the group multiplied by 10  */
		property array<int>^ ActiveGCodes
		{
			array<int>^get()
			{
				for (int i = 0; i < _ActiveGCodes->Length; i++)
				{
					_ActiveGCodes[i] = ValuePointertype->ActiveGCodes[i];
				}
				return _ActiveGCodes;
			}
		
			void set(array<int>^ Value)
			{
				if (Value->Length == _ActiveGCodes->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < _ActiveGCodes->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i], &ValuePointertype->ActiveGCodes[i], LockOverrideDataInPointer);
					}
				}
			}

		}
		/* idem for M-code for each of the M groups */
		property array<int>^ ActiveMCodes
		{
			array<int>^ get()
			{
				for (int i = 0; i < _ActiveMCodes->Length; i++)
				{
					_ActiveMCodes[i] = ValuePointertype->ActiveMCodes[i];
				}
				return _ActiveMCodes;
			}
		
			void set(array<int>^ Value)
			{
				if (Value->Length == _ActiveMCodes->Length && LockOverrideDataInPointer == false)
				{
					for (int i =0;i< _ActiveMCodes->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i], &ValuePointertype->ActiveMCodes[i], LockOverrideDataInPointer);
					}
				}
			}

		}

		/* settings lineNumber, current Feed, current Speed, current Tool (LFST)*/
		property array<double>^ ActiveGSettings
		{
			array<double>^ get()
			{
				for (int i = 0; i < _ActiveGSettings->Length; i++)
				{
					_ActiveGSettings[i] = ValuePointertype->ActiveGSettings[i];
				}
				return _ActiveGSettings;
			}
		
			void set(array<double>^ Value)
			{
				if (Value->Length == _ActiveGSettings->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < _ActiveGSettings->Length; i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<double>(Value[i], &ValuePointertype->ActiveGSettings[i], LockOverrideDataInPointer);
					}
				}
			}

		}
		/* last interpreter error info*/

		property CncLogMessage^  lastIntError
		{
			CncLogMessage^ get()
			{
				Temp_lastIntError->ValuePointertype = &ValuePointertype->lastIntError;
				//lastIntError->UpdateCncLogMessage(ValuePointertype->lastIntError);
				return Temp_lastIntError;
			}
		
			void set(CncLogMessage^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_LOG_MESSAGE>(Value->ValuePointertype[0], &ValuePointertype->lastIntError, LockOverrideDataInPointer);
			}

		}

		/* 0 block delete is off, 1 block delete is on */
		property int blockDelete
		{
			int get()
			{
				return ValuePointertype->blockDelete;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->blockDelete, LockOverrideDataInPointer);
			}

		}

		/* 1 when single stepping mode active */
		property int stepMode
		{
			int get()
			{
				return ValuePointertype->stepMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->stepMode, LockOverrideDataInPointer);
			}

		}

		/* optional stop M1 */
		property int optionalStopOn
		{
			int get()
			{
				return ValuePointertype->optionalStopOn;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->optionalStopOn, LockOverrideDataInPointer);
			}

		}
		property int subResetPresent
		{
			int get()
			{
				return ValuePointertype->subResetPresent;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->subResetPresent, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncMotionStatus :public Managedstruct<CNC_MOTION_STATUS>
	{
	private:
		CncCartDouble^ Temp_machineCartesianPosition = nullptr;
		CncJointDouble^ Temp_machineJointPosition = nullptr;
		CncOffsetAndPlane^ Temp_activeOffsetAndPlane = nullptr;
		void NewClass()
		{
			Temp_machineCartesianPosition = gcnew CncCartDouble(&ValuePointertype->machineCartesianPosition);
			Temp_machineJointPosition = gcnew CncJointDouble(&ValuePointertype->machineJointPosition);
			Temp_activeOffsetAndPlane = gcnew CncOffsetAndPlane(&ValuePointertype->activeOffsetAndPlane);
		}
	public:
		CncMotionStatus(CNC_MOTION_STATUS * _MOTION_STATUS) :Managedstruct(_MOTION_STATUS)
		{
			NewClass();
		}
		CncMotionStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncMotionStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* Cartesian position without offset from generator */
		property CncCartDouble^ machineCartesianPosition
		{
			CncCartDouble^ get()
			{
				Temp_machineCartesianPosition->ValuePointertype = &ValuePointertype->machineCartesianPosition;
				return Temp_machineCartesianPosition;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->machineCartesianPosition, LockOverrideDataInPointer);
			}

		}

		/* joint positions from generator */
		property CncJointDouble^ machineJointPosition
		{
			CncJointDouble^get()
			{
				Temp_machineJointPosition->ValuePointertype = &ValuePointertype->machineJointPosition;
				return Temp_machineJointPosition;
			}
		
			void set(CncJointDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->machineJointPosition, LockOverrideDataInPointer);
			}

		}

		/* active coordinate system offset, tool offset, rotation and plane */
		/* with this and above machine position, the program position is to be calculated */
		property CncOffsetAndPlane^ activeOffsetAndPlane
		{
			CncOffsetAndPlane^ get()
			{
				Temp_activeOffsetAndPlane->ValuePointertype = &ValuePointertype->activeOffsetAndPlane;
				return Temp_activeOffsetAndPlane;
			}
		
			void set(CncOffsetAndPlane^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_OFFSET_AND_PLANE>(Value->ValuePointertype[0], &ValuePointertype->activeOffsetAndPlane, LockOverrideDataInPointer);
			}

		}

		/* actual feed in X-Y plane, traveled distance / time * 60 [mm/minute]*/
		property double actualFeed
		{
			double get()
			{
				return ValuePointertype->actualFeed;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->actualFeed, LockOverrideDataInPointer);
			}

		}

		/* feed override set by GUI */
		property double userFeedOverride
		{
			double get()
			{
				return ValuePointertype->userFeedOverride;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->userFeedOverride, LockOverrideDataInPointer);
			}

		}
		/* arc feedOverride set by GUI */
		property double userArcFeedOverride
		{
			double get()
			{
				return ValuePointertype->userArcFeedOverride;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->userArcFeedOverride, LockOverrideDataInPointer);
			}


		}

		/* 1 if safe mode active */
		property int  safeMode
		{
			int get()
			{
				return ValuePointertype->safeMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->safeMode, LockOverrideDataInPointer);
			}

		}

		/* safety input value if present, 0 or 1, -1 if not present */
		property int safetyInputValue
		{
			int get()
			{
				return ValuePointertype->safetyInputValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->safetyInputValue, LockOverrideDataInPointer);
			}

		}

		/* 0 if real mode, 1 and 2 are simulation mode, 1 normal, 2 fast */
		property int simulationMode
		{
			int get()
			{
				return ValuePointertype->simulationMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->simulationMode, LockOverrideDataInPointer);
			}

		}

		/* incremented every motion update cycle */
		property int heartBeat
		{
			int get()
			{
				return ValuePointertype->heartBeat;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->heartBeat, LockOverrideDataInPointer);
			}

		}

		/* feed and speed override status */
		property int feedOvEnabled
		{
			int get()
			{
				return ValuePointertype->feedOvEnabled;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->feedOvEnabled, LockOverrideDataInPointer);
			}

		}
		property int speedOvEnabled
		{
			int get()
			{
				return ValuePointertype->speedOvEnabled;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->speedOvEnabled, LockOverrideDataInPointer);
			}

		}
		property int analogFeedOvEnabled
		{
			int get()
			{
				return ValuePointertype->analogFeedOvEnabled;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->analogFeedOvEnabled, LockOverrideDataInPointer);
			}

		}
		property int feedHoldActive
		{
			int get()
			{
				return ValuePointertype->feedHoldActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->feedHoldActive, LockOverrideDataInPointer);
			}

		}
		property int speedHoldHactive
		{
			int get()
			{
				return ValuePointertype->speedHoldHactive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->speedHoldHactive, LockOverrideDataInPointer);
			}

		}


	};
	public ref class CncControllerStatus :public Managedstruct<CNC_CONTROLLER_STATUS>//<<<<<<<<<<<<<<<
	{//gpioRLY8Present
	private:
		array<int>^ Temp_gpioRLY8Present = nullptr;
		array<int>^ Temp_gpioAvx2Present = nullptr;
		array<int>^ Temp_gpioRLY24Present = nullptr;

		array<CncJointSts^>^ Temp_CncJointSts = nullptr;//gcnew array<CncJointSts^>();
		array<CncIoPortSts^>^ Temp_cpuIoSts = nullptr;
		array<CncGpioPortSts^, 2>^ Temp_gpioSts = nullptr;
		void NewClass()
		{
			Temp_gpioRLY8Present = gcnew array<int>(sizeof(ValuePointertype->gpioRLY8Present) / SizeOfintx32);
			Temp_gpioAvx2Present = gcnew array<int>(sizeof(ValuePointertype->gpioAvx2Present) / SizeOfintx32);
			Temp_gpioRLY24Present = gcnew array<int>(sizeof(ValuePointertype->gpioRLY24Present) / SizeOfintx32);
			
			Temp_CncJointSts = gcnew array<CncJointSts^>(CNC_MAX_JOINTS);
			Temp_cpuIoSts = gcnew array<CncIoPortSts^>(CNC_IOID_LAST);
			Temp_gpioSts = gcnew array<CncGpioPortSts^, 2>(CNC_MAX_GPIOCARD_CARDS, CNC_GPIOID_LAST);
		}

	public:
		CncControllerStatus(CNC_CONTROLLER_STATUS * _CONTROLLER_STATUS) :Managedstruct(_CONTROLLER_STATUS)
		{
			NewClass();
		}
		CncControllerStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncControllerStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* physical status of joints and IO */
		property array<CncJointSts^>^ jointSts//(int JointNr)//[CNC_MAX_JOINTS];
		{
			array<CncJointSts^>^ get()
			{

				for (int i = 0; i < Temp_CncJointSts->Length; i++)
				{
					if (Temp_CncJointSts[i] == nullptr)
					{
						Temp_CncJointSts[i] = gcnew CncJointSts(&ValuePointertype->jointSts[i]);
					}
					else
					{
						Temp_CncJointSts[i]->ValuePointertype = &ValuePointertype->jointSts[i];
					}
				}

				return Temp_CncJointSts;
			}
		
			void set(array<CncJointSts^>^ Value)
			{
				if (Value->Length == Temp_CncJointSts->Length && LockOverrideDataInPointer == false)
				{
					for (int i =0;i< Temp_CncJointSts->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_STS>(Value[i]->ValuePointertype[0],&ValuePointertype->jointSts[i],LockOverrideDataInPointer);
					}
				}
			}

		}
		property array<CncIoPortSts^>^ cpuIoSts//(CncIoId IoIdNr)//[CNC_IOID_LAST];
		{
			array<CncIoPortSts^>^ get()
			{

				for (int i = 0; i < Temp_cpuIoSts->Length; i++)
				{
					if (Temp_cpuIoSts[i] == nullptr)
					{
						Temp_cpuIoSts[i] = gcnew CncIoPortSts(&ValuePointertype->cpuIoSts[i]);
					}
					else
					{
						Temp_cpuIoSts[i]->ValuePointertype = &ValuePointertype->cpuIoSts[i];
					}
				}

				return Temp_cpuIoSts;
			}
		
			void set(array<CncIoPortSts^>^ Value)
			{
				if (Value->Length == Temp_cpuIoSts->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < Temp_cpuIoSts->Length; i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<CNC_IO_PORT_STS>(Value[i]->ValuePointertype[0], &ValuePointertype->cpuIoSts[i], LockOverrideDataInPointer);
					}
				}
			}

			//CncIoPortSts^ Temp_cpuIoSts = gcnew CncIoPortSts(ValuePointertype->cpuIoSts, IoIdNr);
			//return Temp_cpuIoSts;
		}
		/* GP IO board */
		property array<int>^ gpioRLY8Present
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_gpioRLY8Present->Length; i++)
				{
					Temp_gpioRLY8Present[i] = ValuePointertype->gpioRLY8Present[i];
				}

				return Temp_gpioRLY8Present;
			}
		
			void set(array<int>^ Value)
			{
				if (Value->Length == Temp_gpioRLY8Present->Length && LockOverrideDataInPointer == false)
				{
					for (int i =0;i< Temp_gpioRLY8Present->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i], &ValuePointertype->gpioRLY8Present[i], LockOverrideDataInPointer);
					}
				}
			}

		}
		property array<int>^ gpioRLY24Present
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_gpioRLY24Present->Length; i++)
				{
					Temp_gpioRLY24Present[i] = ValuePointertype->gpioRLY24Present[i];
				}

				return Temp_gpioRLY24Present;
			}
		
			void set(array<int>^ Value)
			{
				if (Value->Length == Temp_gpioRLY24Present->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < Temp_gpioRLY24Present->Length; i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i], &ValuePointertype->gpioRLY24Present[i], LockOverrideDataInPointer);
					}
				}
			}

		}
		property array<int>^ gpioAvx2Present
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_gpioAvx2Present->Length; i++)
				{
					Temp_gpioAvx2Present[i] = ValuePointertype->gpioAvx2Present[i];
				}

				return Temp_gpioAvx2Present;
			}
		
			void set(array<int>^ Value)
			{
				if (Value->Length == Temp_gpioAvx2Present->Length && LockOverrideDataInPointer == false)
				{
					for (int i = 0; i < Temp_gpioAvx2Present->Length; i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i], &ValuePointertype->gpioAvx2Present[i], LockOverrideDataInPointer);
					}
				}
			}

		}

		property array<CncGpioPortSts^, 2>^ gpioSts
		{
			array<CncGpioPortSts^, 2>^ get()
			{
				for (int Card = 0; Card < CNC_MAX_GPIOCARD_CARDS; Card++)
				{
					for (int IOLast = 0; IOLast < CNC_GPIOID_LAST; IOLast++)
					{
						if (Temp_gpioSts[Card, IOLast] == nullptr)
						{
							Temp_gpioSts[Card, IOLast] = gcnew CncGpioPortSts(&ValuePointertype->gpioSts[Card][IOLast]);
						}
						else
						{
							Temp_gpioSts[Card, IOLast]->ValuePointertype = &ValuePointertype->gpioSts[Card][IOLast];
						}
					}
				}


				return Temp_gpioSts;
			}
		
			void set(array<CncGpioPortSts^, 2>^ Value)
			{
				if (Value->GetLength(0) == Temp_gpioSts->GetLength(0) && Value->GetLength(1) == Temp_gpioSts->GetLength(1) && LockOverrideDataInPointer == false)
				{
					for (int Card = 0; Card < CNC_MAX_GPIOCARD_CARDS; Card++)
					{
						for (int IOLast = 0; IOLast < CNC_GPIOID_LAST; IOLast++)
						{
							if (Temp_gpioSts[Card, IOLast] != nullptr)
							{
								InternalCncMethods::SetPropertyIfUnlocked<CNC_GPIO_PORT_STS>(Value[Card, IOLast]->ValuePointertype[0], &ValuePointertype->gpioSts[Card][IOLast],LockOverrideDataInPointer);
							}
						}
					}
				}
			}

		}


		/* free size in CPU motion fifo */
		property unsigned short cpuFifoFreeSize
		{
			unsigned short get()
			{
				return ValuePointertype->cpuFifoFreeSize;
			}
		
			void set(unsigned short Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<unsigned short>(Value, &ValuePointertype->cpuFifoFreeSize,LockOverrideDataInPointer);
			}

		}

		/* filled size in CPU motion fifo */
		property unsigned short cpuFifoFilledSize
		{
			unsigned short get()
			{
				return ValuePointertype->cpuFifoFilledSize;
			}
		
			void set(unsigned short Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<unsigned short>(Value, &ValuePointertype->cpuFifoFilledSize, LockOverrideDataInPointer);
			}

		}

		/* motion enabled status */
		property int motionEnabled
		{
			int get()
			{
				return  ValuePointertype->motionEnabled;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->motionEnabled, LockOverrideDataInPointer);
			}

		}

		/* homing or probing is active */
		property int capturing
		{
			int get()
			{
				return  ValuePointertype->capturing;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->capturing, LockOverrideDataInPointer);
			}

		}

		/* position captured */
		property int isCaptured
		{
			int get()
			{
				return ValuePointertype->isCaptured;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isCaptured, LockOverrideDataInPointer);
			}

		}

		/* motion error word */
		property int errorWord
		{
			int get()
			{
				return  ValuePointertype->isCaptured;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->errorWord, LockOverrideDataInPointer);
			}

		}

		/* hand wheel count */
		property int handWheelCount1
		{
			int get()
			{
				return  ValuePointertype->handWheelCount1;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->handWheelCount1, LockOverrideDataInPointer);
			}

		}
		property int handWheelCount2
		{
			int get()
			{
				return  ValuePointertype->handWheelCount2;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->handWheelCount2, LockOverrideDataInPointer);
			}

		}

		/* Aux axis */
		property int auxAxPos
		{
			int get()
			{
				return  ValuePointertype->auxAxPos;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->auxAxPos, LockOverrideDataInPointer);
			}

		}
		property int auxAxState
		{
			int get()
			{
				return  ValuePointertype->auxAxState;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->auxAxState, LockOverrideDataInPointer);
			}

		}
		property unsigned int auxAxCi
		{
			unsigned int get()
			{
				return  ValuePointertype->auxAxCi;
			}
		
			void set(unsigned int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<unsigned int>(Value, &ValuePointertype->auxAxCi, LockOverrideDataInPointer);
			}

		}
		property unsigned int auxAxCurN
		{
			unsigned int get()
			{
				return  ValuePointertype->auxAxCurN;
			}
		
			void set(unsigned int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<unsigned int>(Value, &ValuePointertype->auxAxCurN, LockOverrideDataInPointer);
			}

		}
		property int auxAxDirection
		{
			int get()
			{
				return  ValuePointertype->auxAxDirection;
			}
		
			void set( int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->auxAxDirection, LockOverrideDataInPointer);
			}

		}
		property int auxAxIsHomed
		{
			int get()
			{
				return  ValuePointertype->auxAxIsHomed;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->auxAxIsHomed, LockOverrideDataInPointer);
			}

		}
		property int auxAxisIs32bitMode
		{
			int get()
			{
				return  ValuePointertype->auxAxisIs32bitMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->auxAxisIs32bitMode, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncJobStatus :public Managedstruct<CNC_JOB_STATUS>
	{
	private:

		void NewClass()
		{
			
		}
	public:
		CncJobStatus(CNC_JOB_STATUS * _JOB_STATUS) :Managedstruct(_JOB_STATUS)
		{
			NewClass();
		}
		CncJobStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncJobStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* Job file name*/
		property String^ jobName//[CNC_MAX_PATH];//wchar_t 
		{
			String^get()
			{
				return StringConversie::Wchar_tPointer_to_SystemString(ValuePointertype->jobName);
			}
		
			void set(String^ Value)
			{
				if (LockOverrideDataInPointer == false)
				{
					StringConversie::SYSTEM_STRING_toMaxWCharLength(sizeof(ValuePointertype->jobName)/SizeOfWchar_t,Value, ValuePointertype->jobName);
				}
				else
				{
					StatusPropertyLockedDebug();
				}
			}

		}
		/* incremented every time a job is loaded */
		property int jobLoadCounter
		{
			int get()
			{
				return ValuePointertype->jobLoadCounter;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->jobLoadCounter, LockOverrideDataInPointer);
			}

		}
		property int numLinesInjob
		{
			int get()
			{
				return ValuePointertype->numLinesInjob;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->numLinesInjob, LockOverrideDataInPointer);
			}

		}
		property int numLinesInMacro
		{
			int get()
			{
				return ValuePointertype->numLinesInMacro;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->numLinesInMacro, LockOverrideDataInPointer);
			}
		}
		property int numLinesInUserMacro
		{
			int get()
			{
				return ValuePointertype->numLinesInUserMacro;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->numLinesInUserMacro, LockOverrideDataInPointer);
			}
		}
		property Int64 numBytesInJob
		{
			Int64 get()
			{
				return ValuePointertype->numBytesInJob;
			}
		
			void set(Int64 Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<Int64>(Value, &ValuePointertype->numBytesInJob, LockOverrideDataInPointer);
			}
		}
		property int isLongJob
		{
			int get()
			{
				return ValuePointertype->isLongJob;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isLongJob, LockOverrideDataInPointer);
			}
		}
		property int isSuperLongJob
		{
			int get()
			{
				return ValuePointertype->isSuperLongJob;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isSuperLongJob, LockOverrideDataInPointer);
			}
		}


		/* 0 if job needs rendering, 1 if rendered */
		property int jobIsRendered
		{
			int get()
			{
				return ValuePointertype->jobIsRendered;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->jobIsRendered, LockOverrideDataInPointer);
			}
		}

		/* total job length in mm */
		property double totalJobLength
		{
			double get()
			{
				return ValuePointertype->totalJobLength;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->totalJobLength, LockOverrideDataInPointer);
			}
		}

		/* length of job done */
		property double jobProgress
		{
			double get()
			{
				return ValuePointertype->jobProgress;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->jobProgress, LockOverrideDataInPointer);
			}
		}

		/* actual running time */
		property double jobActualRunningTime
		{
			double get()
			{
				return ValuePointertype->jobActualRunningTime;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->jobActualRunningTime, LockOverrideDataInPointer);
			}
		}

		/* Estimated remaining running time */
		property double jobRemainingRunningTime
		{
			double get()
			{
				return ValuePointertype->jobRemainingRunningTime;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->jobRemainingRunningTime, LockOverrideDataInPointer);
			}
		}

		/* Estimated total Time */
		property double jobEstimatedTime
		{
			double get()
			{
				return ValuePointertype->jobEstimatedTime;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->jobEstimatedTime, LockOverrideDataInPointer);
			}
		}

		/* job collision status */
		property int TCACollision
		{
			int get()
			{
				return ValuePointertype->TCACollision;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->TCACollision, LockOverrideDataInPointer);
			}
		}
		property int MCACollision
		{
			int get()
			{
				return ValuePointertype->MCACollision;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->MCACollision, LockOverrideDataInPointer);
			}
		}
		property int xCollision
		{
			int get()
			{
				return ValuePointertype->xCollision;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->xCollision, LockOverrideDataInPointer);
			}
		}
		property int yCollision
		{
			int get()
			{
				return ValuePointertype->yCollision;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->yCollision, LockOverrideDataInPointer);
			}
		}
		property int zCollision
		{
			int get()
			{
				return ValuePointertype->zCollision;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->zCollision, LockOverrideDataInPointer);
			}
		}

		/* render progress */
		property int jobRenderLine
		{
			int get()
			{
				return ValuePointertype->jobRenderLine;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->jobRenderLine, LockOverrideDataInPointer);
			}
		}
		property double jobRenderProgressPercentage
		{
			double get()
			{
				return ValuePointertype->jobRenderProgressPercentage;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->jobRenderProgressPercentage, LockOverrideDataInPointer);
			}
		}


		/* current interpreter line number starting from 1*/
		property int curIpLine
		{
			int get()
			{
				return ValuePointertype->curIpLine;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->curIpLine, LockOverrideDataInPointer);
			}
		}

		/* current interpreter text */
		property String^ curIpLineText//[CNC_MAX_INTERPRETER_LINE + 1];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->curIpLineText);
			}
		
			void set(String^ Value)
			{
				InternalCncMethods::SetStringPropertyIfUnlocked(Value,ValuePointertype->curIpLineText, sizeof(ValuePointertype->curIpLineText), LockOverrideDataInPointer);
			}
		}
		/* current execution line number starting from 1*/
		property int curExLine
		{
			int get()
			{
				return ValuePointertype->curExLine;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->curExLine, LockOverrideDataInPointer);
			}
		}

		/* last known executed interpreter line use for goto to resume where left after pause */
		property int lastKnownExcutedLineNumber
		{
			int get()
			{
				return ValuePointertype->lastKnownExcutedLineNumber;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->lastKnownExcutedLineNumber, LockOverrideDataInPointer);
			}
		}

		/* last known tool change line number */
		property int lastKnownToolChangeLineNumber
		{
			int get()
			{
				return ValuePointertype->lastKnownToolChangeLineNumber;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->lastKnownToolChangeLineNumber, LockOverrideDataInPointer);
			}
		}
		/* job repeat and extra options */
		property int doRepeatJob
		{
			int get()
			{
				return ValuePointertype->doRepeatJob;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->doRepeatJob, LockOverrideDataInPointer);
			}
		}
		property int nrOfJobRepeatsSet
		{
			int get()
			{
				return ValuePointertype->nrOfJobRepeatsSet;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->nrOfJobRepeatsSet, LockOverrideDataInPointer);
			}
		}
		property int nrOfRepeatsActual /* this one is decremented after each RUN */
		{
			int get()
			{
				return ValuePointertype->nrOfRepeatsActual;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->nrOfRepeatsActual, LockOverrideDataInPointer);
			}
		}
		/* 0=nothing 28=G28 home, 30=G30 home */
		property String^ extraLineWhenEndOfJob//[CNC_MAX_INTERPRETER_LINE];
		{
			String^ get()
			{
				return StringConversie::SDT_STRING_toSYSTEM_STRING(ValuePointertype->extraLineWhenEndOfJob);
			}
		
			void set(String^ Value)
			{
				InternalCncMethods::SetStringPropertyIfUnlocked(Value, ValuePointertype->extraLineWhenEndOfJob, sizeof(ValuePointertype->extraLineWhenEndOfJob), LockOverrideDataInPointer);
			}
		}
		property double stockDiameterTurning
		{
			double get()
			{
				return ValuePointertype->stockDiameterTurning;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->stockDiameterTurning, LockOverrideDataInPointer);
			}
		}
		property double stockLengthTurning
		{
			double get()
			{
				return ValuePointertype->stockLengthTurning;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->stockLengthTurning, LockOverrideDataInPointer);
			}
		}
		property int stockZAtworkOffset
		{
			int get()
			{
				return ValuePointertype->stockZAtworkOffset;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->stockZAtworkOffset, LockOverrideDataInPointer);
			}
		}
		
	};
	public ref class CncTrackingStatus :public Managedstruct<CNC_TRACKING_STATUS>
	{
	private:
		CncCartBool^ Temp_curTrackingPosReached = nullptr;
		CncCartBool^ Temp_curAxesIsTracking = nullptr;
		CncCartDouble^ Temp_trackingPosition = nullptr;
		CncCartDouble^ Temp_trackingVelocity = nullptr;
		array<int>^ Temp_trackingHandwheelCounter = nullptr;
		array<CncTrackSource>^ Temp_AllCurTrackSource = nullptr;
		void NewClass()
		{
			Temp_curTrackingPosReached = gcnew CncCartBool(&ValuePointertype->curTrackingPosReached);
			Temp_curAxesIsTracking = gcnew CncCartBool(&ValuePointertype->curAxesIsTracking);
			Temp_trackingPosition = gcnew CncCartDouble(&ValuePointertype->trackingPosition);
			Temp_trackingVelocity = gcnew CncCartDouble(&ValuePointertype->trackingVelocity);
			Temp_trackingHandwheelCounter = gcnew array<int>(sizeof(ValuePointertype->trackingHandwheelCounter) / SizeOfintx32);
			Temp_AllCurTrackSource = gcnew array<CncTrackSource>(CNC_MAX_AXES);
		}
	public:
		CncTrackingStatus(CNC_TRACKING_STATUS * _TRACKING_STATUS) :Managedstruct(_TRACKING_STATUS)
		{
			NewClass();
		}
		CncTrackingStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncTrackingStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}

		/* actual tracking status */
		property CncTrackingMode curTrackingMode
		{
			CncTrackingMode get()
			{
				return (CncTrackingMode)ValuePointertype->curTrackingMode;
			}
		
			void set(CncTrackingMode Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_TRACKING_MODE>((CNC_TRACKING_MODE)Value, &ValuePointertype->curTrackingMode, LockOverrideDataInPointer);
			}
		}
		property array<CncTrackSource>^ CurTrackSource
		{
			array<CncTrackSource>^ get()
			{
				for (int i = 0; i < Temp_AllCurTrackSource->Length; i++)
				{
					Temp_AllCurTrackSource[i] = (CncTrackSource)ValuePointertype->curTrackSource[i];
				}
				return Temp_AllCurTrackSource;
			}
		
			void set(array<CncTrackSource>^ Value)
			{
				if (Temp_AllCurTrackSource->Length == Value->Length &&LockOverrideDataInPointer == false)
				{
					for (int i =0;i<Temp_AllCurTrackSource->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<CNC_TRACK_SOURCE>((CNC_TRACK_SOURCE)Value[i], &ValuePointertype->curTrackSource[i], LockOverrideDataInPointer);
					}
				}
			}
		}
		property CncCartBool^ curTrackingPosReached
		{
			CncCartBool^get()
			{
				Temp_curTrackingPosReached->ValuePointertype = &ValuePointertype->curTrackingPosReached;
				return Temp_curTrackingPosReached;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->curTrackingPosReached, LockOverrideDataInPointer);
			}
		}
		property CncCartBool^ curAxesIsTracking
		{
			CncCartBool^ get()
			{
				Temp_curAxesIsTracking->ValuePointertype = &ValuePointertype->curAxesIsTracking;
				return Temp_curAxesIsTracking;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->curAxesIsTracking, LockOverrideDataInPointer);
			}
		}
		property double curHandwheelMultiplicationFactor
		{
			double get()
			{
				return ValuePointertype->curHandwheelMultiplicationFactor;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->curHandwheelMultiplicationFactor, LockOverrideDataInPointer);
			}
		}

		/* position which is currently tracked */
		property CncCartDouble^ trackingPosition
		{
			CncCartDouble^ get()
			{
				Temp_trackingPosition->ValuePointertype = &ValuePointertype->trackingPosition;
				return Temp_trackingPosition;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->trackingPosition, LockOverrideDataInPointer);
			}
		}
		property CncCartDouble^ trackingVelocity
		{
			CncCartDouble^ get()
			{
				Temp_trackingVelocity->ValuePointertype = &ValuePointertype->trackingVelocity;
				return Temp_trackingVelocity;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->trackingVelocity, LockOverrideDataInPointer);
			}
		}
		property CncCartDouble^ trackingAccel
		{
			CncCartDouble^ get()
			{
				Temp_trackingVelocity->ValuePointertype = &ValuePointertype->trackingAccel;
				return Temp_trackingVelocity;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->trackingAccel, LockOverrideDataInPointer);
			}
		}
		/* hand wheel counters */
		property array<int>^ trackingHandwheelCounter
		{
			array<int>^ get()
			{
				for (int i = 0; i < Temp_trackingHandwheelCounter->Length; i++)
				{
					Temp_trackingHandwheelCounter[i] = ValuePointertype->trackingHandwheelCounter[i];
				}

				return Temp_trackingHandwheelCounter;
			}
		
			void set(array<int>^ Value)
			{
				if (Temp_trackingHandwheelCounter->Length == Value->Length && LockOverrideDataInPointer == false)
				{
					for (int i =0;i< Temp_trackingHandwheelCounter->Length;i++)
					{
						InternalCncMethods::SetPropertyIfUnlocked<int>(Value[i],&ValuePointertype->trackingHandwheelCounter[i],LockOverrideDataInPointer);
					}
				}
			}
		}

		/* single flag protocol */
		property int newTrackingDataFlag
		{
			int get()
			{
				return ValuePointertype->newTrackingDataFlag;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->newTrackingDataFlag, LockOverrideDataInPointer);
			}
		}
	};
	public ref class CncThcStatus :public Managedstruct<CNC_THC_STATUS>
	{
	private:
		CncThcProcessParameters^ Temp_actualProcessPars = nullptr;
		void NewClass()
		{
			Temp_actualProcessPars = gcnew CncThcProcessParameters(&ValuePointertype->actualProcessPars);
		}
	public:
		CncThcStatus(CNC_THC_STATUS * _THC_STATUS) :Managedstruct(_THC_STATUS)
		{
			NewClass();
		}
		CncThcStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncThcStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* THC actual parameters */
		property CncThcProcessParameters^ actualProcessPars
		{
			CncThcProcessParameters^ get()
			{
				Temp_actualProcessPars->ValuePointertype = &ValuePointertype->actualProcessPars;
				return Temp_actualProcessPars;
			}
		
			void set(CncThcProcessParameters^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_THC_PROCESS_PARAMETERS>(Value->ValuePointertype[0], &ValuePointertype->actualProcessPars, LockOverrideDataInPointer);
			}
		}

		/* status vars */
		property double voltAct
		{
			double get()
			{
				return ValuePointertype->voltAct;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->voltAct, LockOverrideDataInPointer);
			}
		}
		property double controllerOut
		{
			double get()
			{
				return ValuePointertype->controllerOut;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->controllerOut, LockOverrideDataInPointer);
			}
		}

		property int isOn
		{
			int get()
			{
				return  ValuePointertype->isOn;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isOn, LockOverrideDataInPointer);
			}
		}
		property int isTracking
		{
			int get()
			{
				return  ValuePointertype->isTracking;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isTracking, LockOverrideDataInPointer);
			}
		}
		property int isActive
		{
			int get()
			{
				return  ValuePointertype->isActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isActive, LockOverrideDataInPointer);
			}
		}
		property int curveProtectActive
		{
			int get()
			{
				return  ValuePointertype->curveProtectActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->curveProtectActive, LockOverrideDataInPointer);
			}
		}
		property int holeDetectActive
		{
			int get()
			{
				return  ValuePointertype->holeDetectActive;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->holeDetectActive, LockOverrideDataInPointer);
			}
		}

		property int plasmaOnInput
		{
			int get()
			{
				return  ValuePointertype->plasmaOnInput;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->plasmaOnInput, LockOverrideDataInPointer);
			}
		}
		property int isCuttingMove
		{
			int get()
			{
				return  ValuePointertype->isCuttingMove;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isCuttingMove, LockOverrideDataInPointer);
			}
		}
		property int isTuningMode
		{
			int get()
			{
				return  ValuePointertype->isTuningMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isTuningMode, LockOverrideDataInPointer);
			}
		}

		property int externalUpDownMode
		{
			int get()
			{
				return  ValuePointertype->externalUpDownMode;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->externalUpDownMode, LockOverrideDataInPointer);
			}
		}
		property int goUpInput
		{
			int get()
			{
				return  ValuePointertype->goUpInput;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->goUpInput, LockOverrideDataInPointer);
			}
		}
		property int goDownInput
		{
			int get()
			{
				return  ValuePointertype->goDownInput;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->goDownInput, LockOverrideDataInPointer);
			}
		}

	};
	public ref class CncSpindleSts :public Managedstruct<CNC_SPINDLE_STS>
	{
	private:
		CncSpindleConfig^ Temp_spindleCfg = nullptr;
		void NewClass()
		{
			Temp_spindleCfg = gcnew CncSpindleConfig(&ValuePointertype->spindleCfg);
		}
	public:
		CncSpindleSts(CNC_SPINDLE_STS * _SPINDLE_STS) :Managedstruct(_SPINDLE_STS)
		{
			NewClass();
		}
		CncSpindleSts() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncSpindleSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* sync count, spindle pulse */
		property int syncCount
		{
			int get()
			{
				return ValuePointertype->syncCount;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->syncCount, LockOverrideDataInPointer);
			}
		}

		/* spindle rate, rev/sec RPS */
		property double actualSpindleSpeedSigned
		{
			double get()
			{
				return ValuePointertype->actualSpindleSpeedSigned;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->actualSpindleSpeedSigned, LockOverrideDataInPointer);
			}

		}

		/* programmed spindle speed RPS */
		property double programmedSpindleSpeed
		{
			double get()
			{
				return ValuePointertype->programmedSpindleSpeed;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->programmedSpindleSpeed, LockOverrideDataInPointer);
			}

		}

		/* Speed override Factor */
		property double speedOverrideFactor
		{
			double get()
			{
				return ValuePointertype->speedOverrideFactor;
			}
		
			void set(double Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<double>(Value, &ValuePointertype->speedOverrideFactor, LockOverrideDataInPointer);
			}

		}

		/* 1 of on */
		property int spindleIsOn
		{
			int get()
			{
				return ValuePointertype->spindleIsOn;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleIsOn, LockOverrideDataInPointer);
			}

		}

		/* 1 if ccw */
		property int spindleDirection
		{
			int get()
			{
				return ValuePointertype->spindleDirection;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleDirection, LockOverrideDataInPointer);
			}

		}

		/* value 0-1000%% */
		property int spindlePWMPrecentage
		{
			int get()
			{
				return ValuePointertype->spindlePWMPrecentage;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindlePWMPrecentage, LockOverrideDataInPointer);
			}

		}

		/* set if CPU supports spindle/feed synchronization */
		property int feedSpeedSyncAvailable
		{
			int get()
			{
				return ValuePointertype->feedSpeedSyncAvailable;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->feedSpeedSyncAvailable, LockOverrideDataInPointer);
			}

		}

		/* index 0-2, tells actual configuration */
		property int actualSpindleConfigurationIndex
		{
			int get()
			{
				return ValuePointertype->actualSpindleConfigurationIndex;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->actualSpindleConfigurationIndex, LockOverrideDataInPointer);
			}

		}

		/* spindle is ramping up */
		property int isRampingUp
		{
			int get()
			{
				return ValuePointertype->isRampingUp;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->isRampingUp, LockOverrideDataInPointer);
			}

		}

		/* Spindle ready IO input */
		property int spindleReady
		{
			int get()
			{
				return ValuePointertype->spindleReady;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleReady, LockOverrideDataInPointer);
			}

		}

		property CncSpindleConfig^ spindleCfg
		{
			CncSpindleConfig^ get()
			{
				Temp_spindleCfg->ValuePointertype = &ValuePointertype->spindleCfg;
				return Temp_spindleCfg;
			}
		
			void set(CncSpindleConfig^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_SPINDLE_CONFIG>(Value->ValuePointertype[0], &ValuePointertype->spindleCfg, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncPauseSts :public Managedstruct<CNC_PAUSE_STS>
	{
	private:
		CncCartDouble^ Temp_pausePosition = nullptr;
		CncCartBool^ Temp_curPosInSync = nullptr;
		
		void NewClass()
		{
			Temp_pausePosition = gcnew CncCartDouble(&ValuePointertype->pausePosition);
			Temp_curPosInSync = gcnew CncCartBool(&ValuePointertype->curPosInSync);
			
		}
	public:
		CncPauseSts(CNC_PAUSE_STS * _PAUSE_STS) :Managedstruct(_PAUSE_STS)
		{
			NewClass();
		}
		CncPauseSts() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncPauseSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* 1 if paused for manual action, like manual tool change */
		property int pauseManualActionRequired
		{
			int get()
			{
				return ValuePointertype->pauseManualActionRequired;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseManualActionRequired, LockOverrideDataInPointer);
			}

		}

		/* position which is stored after pause */
		property CncCartDouble^ pausePosition
		{
			CncCartDouble^ get()
			{
				Temp_pausePosition->ValuePointertype = &ValuePointertype->pausePosition;
				return Temp_pausePosition;
			}
		
			void set(CncCartDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->pausePosition, LockOverrideDataInPointer);
			}

		}
		
		property int pausePositionValid
		{
			int get()
			{
				return ValuePointertype->pausePositionValid;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pausePositionValid, LockOverrideDataInPointer);
			}

		}
		property int pausePositionLine
		{
			int get()
			{
				return ValuePointertype->pausePositionLine;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pausePositionLine, LockOverrideDataInPointer);
			}

		}
		property int pauseSpindleIOValue
		{
			int get()
			{
				return ValuePointertype->pauseSpindleIOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseSpindleIOValue, LockOverrideDataInPointer);
			}

		}
		
		property int pauseAux1IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux1IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux1IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux2IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux2IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux2IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux3IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux3IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux3IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux4IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux4IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux4IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux5IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux5IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux5IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux6IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux6IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux6IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux7IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux7IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux7IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux8IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux8IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux8IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux9IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux9IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux9IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseAux10IOValue
		{
			int get()
			{
				return ValuePointertype->pauseAux10IOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseAux10IOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseMistIOValue
		{
			int get()
			{
				return ValuePointertype->pauseMistIOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseMistIOValue, LockOverrideDataInPointer);
			}

		}
		property int pauseFloodIOValue
		{
			int get()
			{
				return ValuePointertype->pauseFloodIOValue;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseFloodIOValue, LockOverrideDataInPointer);
			}

		}

		/* So GUI knows Array indices where paused */
		property int pauseArrayIndexX
		{
			int get()
			{
				return ValuePointertype->pauseArrayIndexX;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseArrayIndexX, LockOverrideDataInPointer);
			}

		}
		property int pauseArrayIndexY
		{
			int get()
			{
				return ValuePointertype->pauseArrayIndexY;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseArrayIndexY, LockOverrideDataInPointer);
			}

		}
		property int pauseDoArray
		{
			int get()
			{
				return ValuePointertype->pauseDoArray;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->pauseDoArray, LockOverrideDataInPointer);
			}

		}

		//These are monitored and updated by the server
		//GUI can show axes/IO that are in sync (at correct value for resume)
		property CncCartBool^ curPosInSync
		{
			CncCartBool^ get()
			{
				Temp_curPosInSync->ValuePointertype = &ValuePointertype->curPosInSync;
				return Temp_curPosInSync;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->curPosInSync, LockOverrideDataInPointer);
			}

		}
		property int spindleInSync
		{
			int get()
			{
				return ValuePointertype->spindleInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleInSync, LockOverrideDataInPointer);
			}

		}
		property int floodInSync
		{
			int get()
			{
				return ValuePointertype->floodInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->floodInSync, LockOverrideDataInPointer);
			}

		}
		property int mistInSync
		{
			int get()
			{
				return ValuePointertype->mistInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->mistInSync, LockOverrideDataInPointer);
			}

		}
		property int allAxesInSync
		{
			int get()
			{
				return ValuePointertype->allAxesInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->allAxesInSync, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncSearchStatus :public Managedstruct<CNC_SEARCH_STATUS>
	{
	private:
		CncBasicInterpreterStatus^ Temp_basicIntStatusBeforeSearch = nullptr;
		CncBasicInterpreterStatus^ Temp_basicIntStatusAfterSearch = nullptr;
		CncCartBool^ Temp_curPosInSync = nullptr;
		void NewClass()
		{
			Temp_basicIntStatusBeforeSearch = gcnew CncBasicInterpreterStatus(&ValuePointertype->basicIntStatusBeforeSearch);
			Temp_basicIntStatusAfterSearch = gcnew CncBasicInterpreterStatus(&ValuePointertype->basicIntStatusAfterSearch);
			Temp_curPosInSync = gcnew CncCartBool(&ValuePointertype->curPosInSync);
		}
	public:
		CncSearchStatus(CNC_SEARCH_STATUS * _CNC_SEARCH_STATUS) :Managedstruct(_CNC_SEARCH_STATUS)
		{
			NewClass();
		}
		CncSearchStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncSearchStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property CncBasicInterpreterStatus^ basicIntStatusBeforeSearch
		{
			CncBasicInterpreterStatus^ get()
			{
				Temp_basicIntStatusBeforeSearch->ValuePointertype = &ValuePointertype->basicIntStatusBeforeSearch;
				return Temp_basicIntStatusBeforeSearch;
			}
		
			void set(CncBasicInterpreterStatus^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_BASIC_INTERPRETER_STATUS>(Value->ValuePointertype[0], &ValuePointertype->basicIntStatusBeforeSearch, LockOverrideDataInPointer);
			}

		}
		property CncBasicInterpreterStatus^ basicIntStatusAfterSearch
		{
			CncBasicInterpreterStatus^ get()
			{
				Temp_basicIntStatusAfterSearch->ValuePointertype = &ValuePointertype->basicIntStatusAfterSearch;
				return Temp_basicIntStatusAfterSearch;
			}
		
			void set(CncBasicInterpreterStatus^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_BASIC_INTERPRETER_STATUS>(Value->ValuePointertype[0], &ValuePointertype->basicIntStatusAfterSearch, LockOverrideDataInPointer);
			}

		}

		//These are monitored and updated by the server
		//GUI can show axes/IO that are in sync (at correct value for resume)
		property CncCartBool^ curPosInSync
		{
			CncCartBool^ get()
			{
				Temp_curPosInSync->ValuePointertype = &ValuePointertype->curPosInSync;
				return Temp_curPosInSync;
			}
		
			void set(CncCartBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_CART_BOOL>(Value->ValuePointertype[0], &ValuePointertype->curPosInSync, LockOverrideDataInPointer);
			}

		}
		property int spindleInSync
		{
			int get()
			{
				return ValuePointertype->spindleInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->spindleInSync, LockOverrideDataInPointer);
			}

		}
		property int floodInSync
		{
			int get()
			{
				return ValuePointertype->floodInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->floodInSync, LockOverrideDataInPointer);
			}

		}
		property int mistInSync
		{
			int get()
			{
				return ValuePointertype->mistInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->mistInSync, LockOverrideDataInPointer);
			}

		}
		property int toolInSync
		{
			int get()
			{
				return ValuePointertype->toolInSync;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->toolInSync, LockOverrideDataInPointer);
			}

		}
	};
	public ref class Cnc3dPrintingSts :public Managedstruct<CNC_3DPRINTING_STS>
	{
	private:
		Cnc3DPrintingTempPidPars^ Temp_extruderPIDPars = nullptr;
		Cnc3DPrintingTempPidPars^ Temp_heatBedPIDPars = nullptr;
		void NewClass()
		{
			Temp_extruderPIDPars = gcnew Cnc3DPrintingTempPidPars(&ValuePointertype->extruderPIDPars);
			Temp_heatBedPIDPars = gcnew Cnc3DPrintingTempPidPars(&ValuePointertype->heatBedPIDPars);
		}
	public:
		Cnc3dPrintingSts(CNC_3DPRINTING_STS * _3DPRINTING_STS) :Managedstruct(_3DPRINTING_STS)
		{
			NewClass();
		}
		Cnc3dPrintingSts() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(Cnc3dPrintingSts^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		//Actual PID parameters
		property Cnc3DPrintingTempPidPars^ extruderPIDPars
		{
			Cnc3DPrintingTempPidPars^ get()
			{
				Temp_extruderPIDPars->ValuePointertype = &ValuePointertype->extruderPIDPars;
				return Temp_extruderPIDPars;
			}
		
			void set(Cnc3DPrintingTempPidPars^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_3DPRINTING_TEMP_PID_PARS>(Value->ValuePointertype[0],&ValuePointertype->extruderPIDPars,LockOverrideDataInPointer);
			}

		}
		property Cnc3DPrintingTempPidPars^ heatBedPIDPars
		{
			Cnc3DPrintingTempPidPars^ get()
			{
				Temp_heatBedPIDPars->ValuePointertype = &ValuePointertype->heatBedPIDPars;
				return Temp_heatBedPIDPars;
			}
		
			void set(Cnc3DPrintingTempPidPars^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_3DPRINTING_TEMP_PID_PARS>(Value->ValuePointertype[0], &ValuePointertype->heatBedPIDPars, LockOverrideDataInPointer);
			}

		}

		//Extruder status visible in GUI
		property float extruderSetPointTemp
		{
			float get()
			{
				return ValuePointertype->extruderSetPointTemp;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->extruderSetPointTemp, LockOverrideDataInPointer);
			}

		}
		property float extruderActualTemp
		{
			float get()
			{
				return ValuePointertype->extruderActualTemp;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->extruderActualTemp, LockOverrideDataInPointer);
			}

		}
		property float extruderHeatingPower
		{
			float get()
			{
				return ValuePointertype->extruderHeatingPower;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->extruderHeatingPower, LockOverrideDataInPointer);
			}

		}
		property float extruderOverride
		{
			float get()
			{
				return ValuePointertype->extruderOverride;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->extruderOverride, LockOverrideDataInPointer);
			}

		}
		property CncOnOff extruderPIDIsON
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->extruderPIDIsON;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->extruderPIDIsON, LockOverrideDataInPointer);
			}

		}
		property CncOnOff extruderHeatingIsOn
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->extruderHeatingIsOn;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->extruderHeatingIsOn, LockOverrideDataInPointer);
			}

		}
		property CncOnOff extruderInStandByMode
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->extruderInStandByMode;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->extruderInStandByMode, LockOverrideDataInPointer);
			}

		}
		property CncOnOff extruderSetPointReached
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->extruderSetPointReached;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->extruderSetPointReached, LockOverrideDataInPointer);
			}

		}

		//HeatdBED status
		property float heatBedSetPointTemp
		{
			float get()
			{
				return ValuePointertype->heatBedSetPointTemp;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->heatBedSetPointTemp, LockOverrideDataInPointer);
			}

		}
		property float heatBedActualTemp
		{
			float get()
			{
				return ValuePointertype->heatBedActualTemp;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->heatBedActualTemp, LockOverrideDataInPointer);
			}

		}
		property float heatBedHeatingPower
		{
			float get()
			{
				return ValuePointertype->heatBedHeatingPower;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->heatBedHeatingPower, LockOverrideDataInPointer);
			}

		}
		property CncOnOff heatBedPIDIsON
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->heatBedPIDIsON;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->heatBedPIDIsON, LockOverrideDataInPointer);
			}

		}
		property CncOnOff heatBedHeatingIsOn
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->heatBedHeatingIsOn;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->heatBedHeatingIsOn, LockOverrideDataInPointer);
			}

		}
		property CncOnOff heatBedInStandByMode
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->heatBedInStandByMode;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->heatBedInStandByMode, LockOverrideDataInPointer);
			}

		}
		property CncOnOff heatBedSetPointReached
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->heatBedSetPointReached;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->heatBedSetPointReached, LockOverrideDataInPointer);
			}

		}

		//Workpiece FAN
		property float workPieceActualCoolFanPower
		{
			float get()
			{
				return ValuePointertype->workPieceActualCoolFanPower;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->workPieceActualCoolFanPower, LockOverrideDataInPointer);
			}

		}
		property float workPieceActualCoolFanPowerThreshold
		{
			float get()
			{
				return ValuePointertype->workPieceActualCoolFanPowerThreshold;
			}
		
			void set(float Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<float>(Value, &ValuePointertype->workPieceActualCoolFanPowerThreshold, LockOverrideDataInPointer);
			}

		}
		property CncOnOff workPieceCoolingFanIsOn
		{
			CncOnOff get()
			{
				return (CncOnOff)ValuePointertype->workPieceCoolingFanIsOn;
			}
		
			void set(CncOnOff Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_ONOFF>((CNC_ONOFF)Value, &ValuePointertype->workPieceCoolingFanIsOn, LockOverrideDataInPointer);
			}

		}
	};
	public ref class CncCompensationStatus :public Managedstruct<CNC_COMPENSATION_STATUS>
	{
	private:
		CncJointDouble^ Temp_curCompValue = nullptr;
		CncJointBool^ Temp_backlashCompIsOn = nullptr;
		CncJointBool^ Temp_linearJointCompIsOn = nullptr;
		CncJointBool^ Temp_crossCompIsOn = nullptr;
		void NewClass()
		{
			Temp_curCompValue = gcnew CncJointDouble(&ValuePointertype->curCompValue);
			Temp_backlashCompIsOn = gcnew CncJointBool(&ValuePointertype->backlashCompIsOn);
			Temp_linearJointCompIsOn = gcnew CncJointBool(&ValuePointertype->linearJointCompIsOn);
			Temp_crossCompIsOn = gcnew CncJointBool(&ValuePointertype->crossCompIsOn);
		}
	public:
		CncCompensationStatus(CNC_COMPENSATION_STATUS * _COMPENSATION_STATUS) :Managedstruct(_COMPENSATION_STATUS)
		{
			NewClass();
		}
		CncCompensationStatus() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncCompensationStatus^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		/* Z Height bilinear compensation */
		property int zHeightCompIsOn
		{
			int get()
			{
				return ValuePointertype->zHeightCompIsOn;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value,&ValuePointertype->zHeightCompIsOn,LockOverrideDataInPointer);
			}

		}
		property int outOfArea
		{
			int get()
			{
				return ValuePointertype->outOfArea;
			}
		
			void set(int Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<int>(Value, &ValuePointertype->outOfArea, LockOverrideDataInPointer);
			}

		}

		/* current comp value of all compensations */
		property CncJointDouble^ curCompValue
		{
			CncJointDouble^ get()
			{
				Temp_curCompValue->ValuePointertype = &ValuePointertype->curCompValue;
				return Temp_curCompValue;
			}
		
			void set(CncJointDouble^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_DOUBLE>(Value->ValuePointertype[0], &ValuePointertype->curCompValue, LockOverrideDataInPointer);
			}

		}

		/* joint backlash compensation */
		property CncJointBool^ backlashCompIsOn
		{
			CncJointBool^ get()
			{
				Temp_backlashCompIsOn->ValuePointertype = &ValuePointertype->backlashCompIsOn;
				return Temp_backlashCompIsOn;
			}
		
			void set(CncJointBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_BOOL>(Value->ValuePointertype[0], &ValuePointertype->backlashCompIsOn, LockOverrideDataInPointer);
			}

		}

		/* linear joint compensation */
		property CncJointBool^ linearJointCompIsOn
		{
			CncJointBool^ get()
			{
				Temp_linearJointCompIsOn->ValuePointertype = &ValuePointertype->linearJointCompIsOn;
				return Temp_linearJointCompIsOn;
			}
		
			void set(CncJointBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_BOOL>(Value->ValuePointertype[0], &ValuePointertype->linearJointCompIsOn, LockOverrideDataInPointer);
			}

		}

		/* cross compensation */
		property CncJointBool^ crossCompIsOn
		{
			CncJointBool^ get()
			{
				Temp_crossCompIsOn->ValuePointertype = &ValuePointertype->crossCompIsOn;
				return Temp_crossCompIsOn;
			}
		
			void set(CncJointBool^ Value)
			{
				InternalCncMethods::SetPropertyIfUnlocked<CNC_JOINT_BOOL>(Value->ValuePointertype[0], &ValuePointertype->crossCompIsOn, LockOverrideDataInPointer);
			}

		}


	};
	public ref class CncPosFifoData :public Managedstruct<CNC_POS_FIFO_DATA>
	{
	private:
		CncCartDouble^ Temp_CncCartDouble = nullptr;

		void NewClass()
		{
			Temp_CncCartDouble = gcnew CncCartDouble(&ValuePointertype->pos);
		}
	public:
		CncPosFifoData(CNC_POS_FIFO_DATA * _POS_FIFO_DATA) :Managedstruct(_POS_FIFO_DATA)
		{
			NewClass();
		}
		CncPosFifoData() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncPosFifoData^ SOURCE)
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
		property CncCartDouble^ pos
		{
			CncCartDouble^ get()
			{
				Temp_CncCartDouble->ValuePointertype = &ValuePointertype->pos;
				return Temp_CncCartDouble;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->pos = Value->ValuePointertype[0];
				//Temp_CncCartDouble = Value;
			}
		}
		property CncMoveType type
		{
			CncMoveType get()
			{
				return (CncMoveType)ValuePointertype->type;
			}
			void set(CncMoveType Value)
			{
				ValuePointertype->type = (CNC_MOVE_TYPE)Value;
			}
		}
	};
	public ref class CncGraphFifoData :public Managedstruct<CNC_GRAPH_FIFO_DATA>
	{
	private:
		CncCartDouble^ Temp_pos = nullptr;
		void NewClass()
		{
			Temp_pos = gcnew CncCartDouble(&ValuePointertype->pos);
		}
	public:
		CncGraphFifoData(CNC_GRAPH_FIFO_DATA * _CNC_GRAPH_FIFO_DATA) :Managedstruct(_CNC_GRAPH_FIFO_DATA)
		{
			NewClass();
		}
		CncGraphFifoData() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncGraphFifoData^ SOURCE)
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
		property int lineNumber
		{
			int get()
			{
				return ValuePointertype->lineNumber;
			}
			void set(int Value)
			{
				ValuePointertype->lineNumber = Value;
			}
		}
		property CncCartDouble^ pos
		{
			CncCartDouble^ get()
			{
				Temp_pos->ValuePointertype = &ValuePointertype->pos;

				return Temp_pos;
			}
			void set(CncCartDouble^ Value)
			{

				ValuePointertype->pos = Value->ValuePointertype[0];
				//Temp_pos = Value;
			}
		}
		property CncMoveType type
		{
			CncMoveType get()
			{
				return (CncMoveType)ValuePointertype->type;
			}
			void set(CncMoveType Value)
			{
				ValuePointertype->type = (CNC_MOVE_TYPE)Value;
			}
		}
		property int msgNumber
		{
			int get()
			{
				return ValuePointertype->msgNumber;
			}
			void set(int Value)
			{
				ValuePointertype->msgNumber = Value;
			}
		}
	};
	public ref class Cnc3DprintingCommand :public Managedstruct<CNC_3DPRINTING_COMMAND>
	{
	private:
		Cnc3DPCmdData^ Temp_Cnc3DPCmdData = nullptr;
		void NewClass()
		{
			Temp_Cnc3DPCmdData = gcnew Cnc3DPCmdData(&ValuePointertype->d);
		}
	public:
		Cnc3DprintingCommand(CNC_3DPRINTING_COMMAND * _CNC_3DPRINTING_COMMAND) :Managedstruct(_CNC_3DPRINTING_COMMAND)
		{
			NewClass();
		}
		Cnc3DprintingCommand() :Managedstruct(nullptr)
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(Cnc3DprintingCommand^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property Cnc3DPCommandId cmdID
		{
			Cnc3DPCommandId get()
			{
				return (Cnc3DPCommandId)ValuePointertype->cmdID;
			}
			void set(Cnc3DPCommandId value)
			{
				ValuePointertype->cmdID = (CNC_3DP_COMMAND_ID)value;
			}
		}
		property Cnc3DPCmdData^ d
		{
			Cnc3DPCmdData^ get()
			{
				Temp_Cnc3DPCmdData->ValuePointertype = &ValuePointertype->d;

				return Temp_Cnc3DPCmdData;
			}
			void set(Cnc3DPCmdData^ value)
			{

				ValuePointertype->d = value->ValuePointertype[0];
				//Temp_Cnc3DPCmdData = value;
			}
		}
	};
	public ref class CncUioConfig :public Managedstruct<CNC_UIO_CONFIG>
	{
	private:
		array<CncUioSingleInputCfg^>^ Temp_CncUioSingleInputCfg = nullptr;
		array<CncUioSelectorConfig^>^ Temp_CncUioSelectorConfig = nullptr;
		array<CncUioAnalogConfig^>^ Temp_CncUioAnalogConfig = nullptr;
		array<CncUioHandWheelConfig^>^ Temp_CncUioHandWheelConfig = nullptr;
		void NewClass()
		{
			Temp_CncUioSingleInputCfg = gcnew array<CncUioSingleInputCfg^>(CNC_MAX_UIO_INPUTS);
			Temp_CncUioSelectorConfig = gcnew array<CncUioSelectorConfig^>(CNC_MAX_UIO_SELECTOR_SWITCHES);
			Temp_CncUioAnalogConfig = gcnew array<CncUioAnalogConfig^>(CNC_MAX_UIO_ANALOG_INPUTS);
			Temp_CncUioHandWheelConfig = gcnew array<CncUioHandWheelConfig^>(CNC_MAX_UIO_HANDWHEEL_INPUTS);
		}
	public:
		CncUioConfig(CNC_UIO_CONFIG * _CNC_UIO_CONFIG) :Managedstruct(_CNC_UIO_CONFIG)
		{
			NewClass();
		}
		CncUioConfig() :Managedstruct(nullptr)
		{
			NewClass();
		}//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		bool CopyUnmanagedPointer(CncUioConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property array<CncUioSingleInputCfg^>^singleInput//(int SeletectUioInput)//[CNC_MAX_UIO_INPUTS];
		{
			array<CncUioSingleInputCfg^>^ get()
			{
				for (int i = 0; i < Temp_CncUioSingleInputCfg->Length; i++)
				{
					if (Temp_CncUioSingleInputCfg[i] == nullptr)
					{
						Temp_CncUioSingleInputCfg[i] = gcnew CncUioSingleInputCfg(&ValuePointertype->singleInput[i]);
					}
					else
					{
						Temp_CncUioSingleInputCfg[i]->ValuePointertype = &ValuePointertype->singleInput[i];
					}
				}
				return Temp_CncUioSingleInputCfg;
			}
			void set(array<CncUioSingleInputCfg^>^ Value)
			{
				if (Value->Length == CNC_MAX_UIO_INPUTS)
				{
					//Temp_CncUioSingleInputCfg = Value;
					for (int i = 0; i < Temp_CncUioSingleInputCfg->Length; i++)
					{
						ValuePointertype->singleInput[i] = Temp_CncUioSingleInputCfg[i]->ValuePointertype[0];
					}
				}
			}
		}
		property array<CncUioSelectorConfig^>^ selector//(int Seletecedselector)//[CNC_MAX_UIO_SELECTOR_SWITCHES];
		{
			array<CncUioSelectorConfig^>^ get()
			{
				for (int i = 0; i < Temp_CncUioSelectorConfig->Length; i++)
				{
					if (Temp_CncUioSelectorConfig[i] == nullptr)
					{
						Temp_CncUioSelectorConfig[i] = gcnew CncUioSelectorConfig(&ValuePointertype->selector[i]);
					}
					else
					{
						Temp_CncUioSelectorConfig[i]->ValuePointertype = &ValuePointertype->selector[i];
					}
				}
				return Temp_CncUioSelectorConfig;
			}
			void set(array<CncUioSelectorConfig^>^ Value)
			{
				if (Value->Length == CNC_MAX_UIO_SELECTOR_SWITCHES)
				{
					//Temp_CncUioSelectorConfig = Value;
					for (int i = 0; i < Temp_CncUioSelectorConfig->Length; i++)
					{
						ValuePointertype->selector[i] = Temp_CncUioSelectorConfig[i]->ValuePointertype[0];
					}
				}
			}
			//CncUioSelectorConfig^ Temp_CncUioSelectorConfig = nullptr;

			//return nullptr;
		}
		property array<CncUioAnalogConfig^>^analog//CNC_UIO_ANALOG_CONFIG analog[CNC_MAX_UIO_ANALOG_INPUTS];
		{
			array<CncUioAnalogConfig^>^ get()
			{
				for (int i = 0; i < Temp_CncUioAnalogConfig->Length; i++)
				{
					if (Temp_CncUioAnalogConfig[i] == nullptr)
					{
						Temp_CncUioAnalogConfig[i] = gcnew CncUioAnalogConfig(&ValuePointertype->analog[i]);
					}
					else
					{
						Temp_CncUioAnalogConfig[i]->ValuePointertype = &ValuePointertype->analog[i];
					}
				}

				return Temp_CncUioAnalogConfig;
			}
			void set(array<CncUioAnalogConfig^>^ Value)
			{
				if (Value->Length == CNC_MAX_UIO_ANALOG_INPUTS)
				{
					//Temp_CncUioAnalogConfig = Value;
					for (int i = 0; i < Temp_CncUioAnalogConfig->Length; i++)
					{
						ValuePointertype->analog[i] = Temp_CncUioAnalogConfig[i]->ValuePointertype[0];
					}
				}
			}
		}
		property array<CncUioHandWheelConfig^>^	handwheel//[CNC_MAX_UIO_HANDWHEEL_INPUTS];
		{
			array<CncUioHandWheelConfig^>^ get()
			{
				for (int i = 0; i < Temp_CncUioHandWheelConfig->Length; i++)
				{
					if (Temp_CncUioHandWheelConfig[i] == nullptr)
					{
						Temp_CncUioHandWheelConfig[i] = gcnew CncUioHandWheelConfig(&ValuePointertype->handwheel[i]);
					}
					else
					{
						Temp_CncUioHandWheelConfig[i]->ValuePointertype = &ValuePointertype->handwheel[i];
					}
				}

				return Temp_CncUioHandWheelConfig;
			}
			void set(array<CncUioHandWheelConfig^>^ Value)
			{
				if (Value->Length == CNC_MAX_UIO_HANDWHEEL_INPUTS)
				{
					//Temp_CncUioHandWheelConfig = Value;
					for (int i = 0; i < Temp_CncUioHandWheelConfig->Length; i++)
					{
						ValuePointertype->handwheel[i] = Temp_CncUioHandWheelConfig[i]->ValuePointertype[0];
						
					}
				}
			}
		}
	};
	public ref class CncVacuumBedConfig :public Managedstruct<CNC_VACUUMBED_CONFIG>
	{
	private:
		array<CncVacuumBedSectionData^>^ Temp_CncVacuumBedSectionData = nullptr;
		void NewClass()
		{
			Temp_CncVacuumBedSectionData = gcnew array<CncVacuumBedSectionData^>(CNC_MAX_VACUUMBED_SECTIONS);
		}
	public:
		CncVacuumBedConfig(CNC_VACUUMBED_CONFIG * _CNC_VACUUMBED_CONFIG) :Managedstruct(_CNC_VACUUMBED_CONFIG)
		{
			NewClass();
		}
		CncVacuumBedConfig() :Managedstruct(nullptr)//added 5-11-2018 i.v.b = CopyUnmanagedPointer
		{
			NewClass();
		}
		bool CopyUnmanagedPointer(CncVacuumBedConfig^ SOURCE)
		{
			return CopyPointerDataToClass(SOURCE->ValuePointertype, SOURCE->ArrayLength);
		}
		property bool automaticMode//;	     //0=off, 1=Determine sections while rendering.
		{
			bool get()
			{
				return ValuePointertype[0].automaticMode;
			}
			void set(bool Value)
			{
				ValuePointertype[0].automaticMode = Value;
			}
		}
		property int numberOfSections//;	     //0=off, 1=Determine sections while rendering.
		{
			int get()
			{
				return ValuePointertype[0].numberOfSections;
			}
			void set(int Value)
			{
				ValuePointertype[0].numberOfSections = Value;
			}
		}
		/* v4.3.25
		property int numberOfSectionsX
		{
			int get()
			{
				return ValuePointertype[0].numberOfSectionsX;
			}
			void set(int Value)
			{
				ValuePointertype[0].numberOfSectionsX = Value;
			}
		}
		property int numberOfSectionsY
		{
			int get()
			{
				return ValuePointertype[0].numberOfSectionsY;
			}
			void set(int Value)
			{
				ValuePointertype[0].numberOfSectionsY = Value;
			}
		}
		*/
		property array<CncVacuumBedSectionData^>^ vacuumBedSectionData//(int vacuumBedSection)//[CNC_MAX_VACUUMBED_SECTIONS];
		{
			array<CncVacuumBedSectionData^>^ get()
			{
				for (int i = 0; i < Temp_CncVacuumBedSectionData->Length; i++)
				{
					if (Temp_CncVacuumBedSectionData[i] == nullptr)
					{
						Temp_CncVacuumBedSectionData[i] = gcnew CncVacuumBedSectionData(&ValuePointertype->vacuumBedSectionData[i]);
					}
					else
					{
						Temp_CncVacuumBedSectionData[i]->ValuePointertype = &ValuePointertype->vacuumBedSectionData[i];
					}
				}

				return Temp_CncVacuumBedSectionData;
			}
			void set(array<CncVacuumBedSectionData^>^ Value)
			{
				if (Value->Length == CNC_MAX_VACUUMBED_SECTIONS)
				{
					//Temp_CncVacuumBedSectionData = Value;
					for (int i = 0; i < Temp_CncVacuumBedSectionData->Length; i++)
					{
						ValuePointertype->vacuumBedSectionData[i] = Temp_CncVacuumBedSectionData[i]->ValuePointertype[0];
					}
				}
			}
		}
	};
}
