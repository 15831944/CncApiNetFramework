#pragma once

using namespace System;



namespace OosterhofDesign
{
	template<typename Pointer>
	public ref class Managedstruct
	{
	internal:
		Pointer * ValuePointertype;
		bool CreatedNewPointer = false;//pointer not created from usbcnc server. remove pointer
		int NumberOfArrays = 1;
		bool LockCopyOverrideData = true;
		bool CopyPointerDataToClass(Pointer * POINTER, int NUMBER_OF_ARRAYS)
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
		property int ArrayLength
		{
			int get()
			{
				return NumberOfArrays;
			}

		}
	public:
		Managedstruct(Pointer * POINTER)
		{
			SetPointer(POINTER, NumberOfArrays);

		}
		Managedstruct(Pointer * POINTER, int NUMBER_OF_ARRAYS)
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
				SetPointer(nullptr, 1);
				GetValuePointer();
				NewPointer();
				PointerArrayLength();
			}
			DeletePointer(false);
		}
		void DeletePointer(bool FORCE_FREE_POINTER)
		{
			if (FORCE_FREE_POINTER == true)
			{
				CreatedNewPointer = true;
				NumberOfCreatedPointers = NumberOfCreatedPointers + 1;
			}
			if (CreatedNewPointer == true)
			{
				if (ValuePointertype != nullptr)
				{
					delete[] ValuePointertype;
					ValuePointertype = nullptr;
					NumberOfDeletedPointers = NumberOfDeletedPointers + 1;
					System::Diagnostics::Debug::WriteLine(NumberOfCreatedPointers + "/" + NumberOfDeletedPointers + ": unmanaged pointers deleted.");
				}
			}
		}
		bool SetPointer(Pointer * POINTER, int NUMBER_OF_ARRAYS)
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

					ValuePointertype = new Pointer[NUMBER_OF_ARRAYS]();
					CreatedNewPointer = true;
					NumberOfCreatedPointers = NumberOfCreatedPointers + 1;
					LockCopyOverrideData = false;
				}
				NumberOfArrays = NUMBER_OF_ARRAYS;
				Return = true;

			}
			return Return;
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
		Pointer * GetValuePointer()
		{
			return ValuePointertype;
		}
		bool NewPointer()
		{
			return CreatedNewPointer;
		}
		int PointerArrayLength()
		{
			return NumberOfArrays;
		}
	};


}