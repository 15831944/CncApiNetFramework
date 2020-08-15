#pragma once

using namespace System;
using namespace System::ComponentModel;

namespace OosterhofDesign
{
	
	template<typename Pointer>
	public ref class Managedstruct :INotifyPropertyChanged
	{
	private:
		bool CreatedNewPointer = false;//pointer not created from usbcnc server. remove pointer
		int NumberOfArrays = 1;
		bool LockCopyOverrideData = true;
		int _Id = 0;
	internal:
		Pointer* ValuePointertype;
		bool CopyPointerDataToClass(Pointer* POINTER, int NUMBER_OF_ARRAYS)
		{

			bool Return = false;
			if (POINTER != nullptr && NUMBER_OF_ARRAYS > 0 && LockCopyOverrideData == false)
			{
				if (NumberOfArrays != NUMBER_OF_ARRAYS)
				{
					DeletePointer(false);
					SetPointer(nullptr, NUMBER_OF_ARRAYS);

				}

				for (int i = 0; i < NUMBER_OF_ARRAYS; i++)
				{
					ValuePointertype[i] = POINTER[i];
				}

				Return = true;
			}
			return Return;
		}
		bool SetPointer(Pointer* POINTER, int NUMBER_OF_ARRAYS)
		{
			bool Return = false;


			if (NUMBER_OF_ARRAYS > 0)
			{
				if (POINTER != nullptr)
				{
					ValuePointertype = POINTER;
					CreatedNewPointer = false;
					LockCopyOverrideData = true;
				}
				else
				{

					ValuePointertype = new Pointer[NUMBER_OF_ARRAYS]{};
					CreatedNewPointer = true;
					//NumberOfCreatedPointers = NumberOfCreatedPointers + 1;
					LockCopyOverrideData = false;
				}
				NumberOfArrays = NUMBER_OF_ARRAYS;
				Return = true;

			}
			return Return;
		}
	public:
		Managedstruct(Pointer* POINTER)
		{
			SetPointer(POINTER, NumberOfArrays);
		}
		Managedstruct(Pointer* POINTER, int NUMBER_OF_ARRAYS)
		{
			SetPointer(POINTER, NUMBER_OF_ARRAYS);
		}
		virtual ~Managedstruct()
		{
			this->!Managedstruct();
		}
		!Managedstruct()
		{
			if (1 != 1)// functions that aren't used in the C++ code won't be in the generated DLL. this code will never run
			{
				//SetPointer(nullptr, 1);
				SetIntPtr(IntPtr(ValuePointertype), 1, false);
				OnPropertyChanged("");
				//GetValuePointer();
				//NewPointer();
				//PointerArrayLength();
			}
			DeletePointer(false);
		}
		virtual event PropertyChangedEventHandler^ PropertyChanged;
		virtual void OnPropertyChanged(String^ propertyName)
		{
			PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
		}
		void DeletePointer(bool FORCE_FREE_POINTER)
		{
			if (FORCE_FREE_POINTER == true)
			{
				CreatedNewPointer = true;
				//NumberOfCreatedPointers = NumberOfCreatedPointers + 1;
			}
			if (CreatedNewPointer == true)
			{
				if (ValuePointertype != nullptr)
				{
					delete[] ValuePointertype;
					ValuePointertype = nullptr;
					//NumberOfDeletedPointers = NumberOfDeletedPointers + 1;
					//System::Diagnostics::Debug::WriteLine(NumberOfDeletedPointers + "/" +  NumberOfCreatedPointers + ": unmanaged pointers deleted.");
				}
			}
		}

		bool SetIntPtr(IntPtr INT_PTR, int ARRAY_LENGTH, bool TRY_DELETE_EXISTING_PTR)
		{
			if (TRY_DELETE_EXISTING_PTR == true)
			{
				DeletePointer(false);
			}
			return SetPointer((Pointer*)INT_PTR.ToPointer(), ARRAY_LENGTH);//SetPointer();
		}
		property bool LockOverrideDataInPointer
		{
			bool get()
			{
				return LockCopyOverrideData;
			}
			void set(bool Value)
			{
				LockCopyOverrideData = Value;
			}
		}
		property IntPtr GetValuePointer
		{
			IntPtr get()
			{
				return IntPtr(ValuePointertype);// ValuePointertype;
			}
		}
		property int UnderlyingTypeSize
		{
			int get()
			{
				return sizeof(Pointer);
			}
		}
		property bool NewPointer
		{
			bool get()
			{
				return CreatedNewPointer;
			}
		}
		property int ArrayLength
		{
			int get()
			{
				return NumberOfArrays;
			}

		}
		property int Id
		{
			int get()
			{
				return _Id;
			}

			void set(int Value)
			{
				_Id = Value;
			}
		}

	

	};
	private class InternalCncMethods
	{
	public:
		template <typename PT_S>
		static void SetPropertyIfUnlocked(PT_S  SOURCE, PT_S* DESTINATION, bool IS_LOCEKD)
		{
			if (IS_LOCEKD == false)
			{
				DESTINATION[0] = SOURCE;
			}
			else
			{
				StatusPropertyLockedDebug();
			}
		}
		static void SetStringPropertyIfUnlocked(String^ SOURCE, char* DESTINATION, int MAX_CHAR_LENGTH, bool ISLOCKED)
		{
			if (ISLOCKED == false)
			{
				StringConversie::SYSTEM_STRING_toMaxCharLength(MAX_CHAR_LENGTH, SOURCE, DESTINATION);
			}
			else
			{
				StatusPropertyLockedDebug();
			}
		}
	};
	


}